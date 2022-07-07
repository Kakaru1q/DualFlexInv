/***********************************************************************/
/*                                                                     */
/*  FILE        :InverterControl.c                     		       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Inverter Control		                       */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "platform.h"
#include "InverterControl.h"
#include "globalvalue.h"
#include "typedefine.h"
#include "PWMControl.h"


void ED_GateDriver_Control(UINT8 ucInverter, UINT8 ucCmd)
{
	if(ucInverter == INVERTER0)
	{
		PORT3.PODR.BIT.B0 = ucCmd;
	}
	else if(ucInverter == INVERTER1)
	{
		PORT3.PODR.BIT.B1 = ucCmd;
	}
	else
	{
		;
	}
}

UINT8 OppositeInverter(UINT8 ucInverter)
{
	UINT8 ucOpposite = 0;
	
	if(ucInverter ^ ucOpposite == INVERTER1) ucOpposite = INVERTER0;
	else ucOpposite = INVERTER1;
	
	return ucOpposite;
}

void CoilRelayControl(UINT8 ucCoil, UINT8 ucCmd)
{
	switch(ucCoil)
	{
		case COIL0 :
			PORT2.PODR.BIT.B4 = ucCmd;
			break;
		case COIL1 :
			PORT2.PODR.BIT.B3 = ucCmd;
			break;
		case COIL2 :
			PORT2.PODR.BIT.B2 = ucCmd;
			break;
		case COIL3 :
			PORT2.PODR.BIT.B1 = ucCmd;
			break;
		default :
			break;
	}
}

void InitializeInverter(UINT8 ucInverter)
{
	gastInverterModule[ucInverter].ucProc = IDLE_MODE;
	gastInverterModule[ucInverter].ucInitOperatingFlag = CLR;
	gastInverterModule[ucInverter].unReg = OSC/65;	
	gastInverterModule[ucInverter].unCalcPower = 0;
	gastInverterModule[ucInverter].ucSoftStartEndFreq = 0;
	
	gunPanOffCheckPower[ucInverter] = 0;
	gastPanDetectValue[ucInverter][0].unResCurrent = 0;
	gastPanDetectValue[ucInverter][0].unInputCurrent = 0;
	gastPanDetectValue[ucInverter][1].unResCurrent = 0;
	gastPanDetectValue[ucInverter][1].unInputCurrent = 0;
	
	
	CoilRelayControl(gaucCoil[ucInverter][0], OFF);
	CoilRelayControl(gaucCoil[ucInverter][1], OFF);
		
	//...PANDETECT FLAG, OPERATION FALG,...
	
	//if ModelOption
	if(ucInverter == INVERTER0) 
	{
		gaucCoil[ucInverter][0] = COIL0;
		gaucCoil[ucInverter][1] = COIL1;
	}
	else if(ucInverter == INVERTER1)
	{
		gaucCoil[ucInverter][0] = COIL2;
		gaucCoil[ucInverter][1] = COIL3;
	}
	else
	{
		gaucCoil[ucInverter][0] = COIL4;
		gaucCoil[ucInverter][1] = COIL4;
	}
	
}

void IdleMode(UINT8 ucInverter)
{
	static UINT8 saucIdleCnt[2] = {0,};
	
	PWMStop(ucInverter);
	InitializeInverter(ucInverter);
	if(gastInverterModule[ucInverter].unMainCommandPower > MINPOWER)
	{
		if(saucIdleCnt[ucInverter] >= 10)
		{
			gastInverterModule[ucInverter].ucProc = PANDETECT_MODE;
			saucIdleCnt[ucInverter] = 0;
		//gastInverterModule[ucInverter].ucInitOperatingFlag = SET;
		}
		else
		{
			saucIdleCnt[ucInverter]++;
		}
	}
	else
	{
		gastInverterModule[ucInverter].ucProc = IDLE_MODE;
		PWMStop(ucInverter);
		CoilRelayControl(gaucCoil[ucInverter][0], OFF);
		CoilRelayControl(gaucCoil[ucInverter][1], OFF);
		gastInverterModule[ucInverter].unReg = OSC/65;		
	}
	//gauInverterModule
}


UINT8 PanCheck(UINT8 ucInverter, UINT8 ucCoil)
{
	UINT8 ucResult = 0;
	
	//GetPanValue
	//Result = 00,01,10,11

	
	if(ucCoil == 0x11)
	{
		if(gastPanDetectValue[ucInverter][0].unResCurrent > 2050 && gastPanDetectValue[ucInverter][0].unInputCurrent > 150
		&& gastPanDetectValue[ucInverter][1].unResCurrent > 2070 && gastPanDetectValue[ucInverter][1].unInputCurrent > 150)
		{
			ucResult = 1;
		}
		else
		{
			ucResult = 0;
		}
	}
	else
	{
		if(gastPanDetectValue[ucInverter][0].unResCurrent > 2050 && gastPanDetectValue[ucInverter][0].unInputCurrent > 210
		&& gastPanDetectValue[ucInverter][1].unResCurrent > 2050 && gastPanDetectValue[ucInverter][1].unInputCurrent > 210)
		{
			ucResult = 1;
		}
		else
		{
			ucResult = 0;
		}
	}
	return ucResult;
}

void PanValueCheck(UINT8 ucInverter, UINT8 ucseq)
{
	gastPanDetectValue[ucInverter][ucseq].unResCurrent = gunResCurPeakTemp[ucInverter];//gunResCurPeak[ucInverter];//gunResCurrent[ucInverter];
	gastPanDetectValue[ucInverter][ucseq].unInputCurrent = gunInputCurrentPeakSum_PanDetect;//gunInputCurrentPeakTemp;//gunInputCurrentPeakvalue;//gunInputCurrent;
}

UINT8 PanDetect(UINT8 ucInverter, UINT8 ucCoil, UINT8 ucResult)
{
	static UINT8 ucPanDetectCnt = 0;
	//UINT8 ucResult = 0;
	
	if(ucPanDetectCnt == 0)
	{//Relay On
		//CoilRelayControl(ucCoil, ON);		
	}
	else if(ucPanDetectCnt == 1)
	{//FreqSetting
		gastInverterModule[ucInverter].unReg = OSC/F70KHZ;
	}
	else if(ucPanDetectCnt == 2)
	{//PWM ON
		PWMStart(ucInverter);
	}
	else if(ucPanDetectCnt == 5)
	{//CHECK
		PanValueCheck(ucInverter,0);
		PWMStop(ucInverter);
		gunInputCurrentPeakSum_PanDetect = 0;
	}
	else if(ucPanDetectCnt == 6)
	{//Freq Change
		gastInverterModule[ucInverter].unReg = OSC/F60KHZ;
	}
	else if(ucPanDetectCnt == 7)
	{
		PWMStart(ucInverter);
	}
	else if(ucPanDetectCnt == 10)
	{//Check & Stop
		PanValueCheck(ucInverter,1);
		PWMStop(ucInverter);
		gunInputCurrentPeakSum_PanDetect = 0;
		ucResult++;
	//	ucPanDetectCnt = 0;
	}
	else
	{
		gunInputCurrentPeakSum_PanDetect += gunInputCurrentPeakTemp;
	}
	ucPanDetectCnt++;
	if(ucPanDetectCnt > 10) ucPanDetectCnt = 0;
	
	
	return ucResult;
}

UINT8 gucTestPan[2] = {0,};
void PanDetectMode(UINT8 ucInverter)
{
	static UINT8 sucResult = 0;
	static UINT8 sucBreakCnt = 0;
	static UINT8 sucSeq = 0;
	static UINT8 sucPan = 0;
	static UINT8 sucReSearchCnt = 0;
	static UINT8 sucUDisplayCnt = 0;
	UINT8 ucCoil = 0;
	UINT8 ucOppositeInverter = OppositeInverter(ucInverter);
	
	//1.RELAY ON
	//2.FREQ SETTING & PWM ON
	//3.CHECK
	if(gastInverterModule[ucInverter].unMainCommandPower < MINPOWER)
	{
		gastInverterModule[ucInverter].ucProc = IDLE_MODE;
	}
	else
	{
		if(gastInverterModule[ucOppositeInverter].ucInitOperatingFlag == SET)
		{
			PWMStop(ucInverter);
		}
		else
		{
			gastInverterModule[ucInverter].ucInitOperatingFlag = SET;
			switch(sucSeq)
			{
				case STEP0 :	
					CoilRelayControl(gaucCoil[ucInverter][0], ON);
					CoilRelayControl(gaucCoil[ucInverter][1], ON);
					ucCoil = 0x11;
					sucResult = PanDetect(ucInverter, ucCoil, sucResult);
					if(sucResult != STEP0)//PanDetected 
					{
						if(PanCheck(ucInverter, ucCoil)) 
						{
							sucReSearchCnt = 0;
						}
						else
						{
							if(sucReSearchCnt > 3)
							{
								sucResult = STEP3;
								sucReSearchCnt = 0;
							}
							else
							{
								sucResult = 0;
								sucReSearchCnt++;
							}
						}
						sucSeq = STEP_BREAK;
					}
					else //PanDetecting
					{
						;
					}
					break;
				case STEP1 : 
					CoilRelayControl(gaucCoil[ucInverter][0], ON);
					CoilRelayControl(gaucCoil[ucInverter][1], OFF);
					ucCoil = 0x01;
					sucResult = PanDetect(ucInverter, ucCoil, sucResult);
					if(sucResult != STEP1)//PanDetected 
					{
						if(PanCheck(ucInverter, ucCoil)) sucPan |= 0x01 ;
						else ;
						sucSeq = STEP_BREAK;
					}
					else //PanDetecting
					{
						;
					}
					//ucSeq = STEP_BREAK;
					break;
				case STEP2 :
					CoilRelayControl(gaucCoil[ucInverter][1], ON);
					CoilRelayControl(gaucCoil[ucInverter][0], OFF);
					ucCoil = 0x10;
					sucResult = PanDetect(ucInverter, ucCoil, sucResult);
					if(sucResult != STEP2)//PanDetected 
					{
						if(PanCheck(ucInverter, ucCoil)) sucPan |= 0x10 ;
						else ;
						sucSeq = STEP_BREAK;
					}
					else //PanDetecting
					{
						;
					}
					//ucSeq = STEP_BREAK;
					break;
				case STEP3 : 	
					//CoilRelayControl(gaucCoil[ucInverter][0], OFF);
					//CoilRelayControl(gaucCoil[ucInverter][1], OFF);
					//if(PanCheck(ucInverter) == 0)
					gucTestPan[ucInverter] = sucPan;
					if(sucPan == 0)
					{
						//Check 30Sec (U Display)
						//if Check 30Sec CookClear
						CoilRelayControl(gaucCoil[ucInverter][0], ON);
						CoilRelayControl(gaucCoil[ucInverter][1], ON);
						gastInverterModule[ucInverter].ucProc = PANDETECT_MODE;
						sucUDisplayCnt++;
						if(sucUDisplayCnt > 3)
						{
							sucUDisplayCnt = 0;
							gastInverterModule[ucInverter].ucProc = IDLE_MODE;
						}
					}
					else if(sucPan > 0)
					{
						if(sucPan == 0x01) 
						{
							CoilRelayControl(gaucCoil[ucInverter][0], ON);
							CoilRelayControl(gaucCoil[ucInverter][1], OFF);
						}
						else if(sucPan == 0x10)
						{
							CoilRelayControl(gaucCoil[ucInverter][0], OFF);
							CoilRelayControl(gaucCoil[ucInverter][1], ON);
						}
						else
						{
							CoilRelayControl(gaucCoil[ucInverter][0], ON);
							CoilRelayControl(gaucCoil[ucInverter][1], ON);
						}
						gastInverterModule[ucInverter].ucProc = SOFTSTART_MODE;
						gastInverterModule[ucInverter].ucInitOperatingFlag = CLR;
					}
					else
					{
						;
					}
					sucSeq = STEP0;
					sucResult = 0;
					sucPan = 0;
					break;
				case STEP_BREAK : 
					sucBreakCnt++;
					if(sucBreakCnt > 36) 
					{
						sucSeq = sucResult;
						sucBreakCnt = 0;
					}
					
					break;
				
				default :
					break;
			}
		}
	}
	
}

void SoftStartMode(UINT8 ucInverter)
{
	UINT8 ucOppositeInverter = OppositeInverter(ucInverter);
	
	if(gastInverterModule[ucInverter].unMainCommandPower < MINPOWER)
	{
		gastInverterModule[ucInverter].ucProc = IDLE_MODE;
	}
	else
	{
		if(gastInverterModule[ucOppositeInverter].ucInitOperatingFlag == SET)
		{
			PWMStop(ucInverter);
		}
		else
		{
			PWMStart(ucInverter);
			gastInverterModule[ucInverter].ucInitOperatingFlag = SET;
			//Power vs Command
			if(gastInverterModule[ucInverter].unCalcPower >= gastInverterModule[ucInverter].unMainCommandPower)// || gastInverterModule[ucInverter].unResCur >= RESONANT_CURRENT_LIMIT)
			{
				if(gastInverterModule[ucInverter].unMainCommandPower >= DUTYCONTROL_POWER)
				{
					gastInverterModule[ucInverter].ucProc = NORMAL_MODE;
				}
				else
				{
					gastInverterModule[ucInverter].ucProc = DUTYCONTROL_MODE;
				}
				gastInverterModule[ucInverter].ucInitOperatingFlag = CLR;
				gastInverterModule[ucInverter].ucSoftStartEndFreq = OSC/gastInverterModule[ucInverter].unReg;
			//	if(gucFlexFlag == SET) PWMStop(ucInverter);
				if(gastInverterModule[ucInverter].ucProc >= NORMAL_MODE && gastInverterModule[ucOppositeInverter].ucProc >= NORMAL_MODE)
				{
					if(gastInverterModule[ucInverter].ucSoftStartEndFreq > gastInverterModule[ucOppositeInverter].ucSoftStartEndFreq)
					{
						gastInverterModule[ucOppositeInverter].unReg = gastInverterModule[ucInverter].unReg;
					}
					else
					{
						gastInverterModule[ucInverter].unReg = gastInverterModule[ucOppositeInverter].unReg;
					}
				}
				
			}
			else
			{
				if(gastInverterModule[ucInverter].unMainCommandPower - gastInverterModule[ucInverter].unCalcPower >= 200)
				{
					gastInverterModule[ucInverter].unReg += 5;
				}
				else if(gastInverterModule[ucInverter].unMainCommandPower - gastInverterModule[ucInverter].unCalcPower >= 100)
				{
					gastInverterModule[ucInverter].unReg += 2;
				}
				else
				{
					gastInverterModule[ucInverter].unReg += 1;
				}
			}
		}
	}
}
UINT8 PanOffPeriod(UINT8 ucPeriod)
{
	static UINT8 suc100msCnt = 0;
	UINT8 ucRetValue = 0;
	
	if(guc100msPanOffFlag == SET)
	{
		guc100msPanOffFlag = CLR;
		suc100msCnt++;
	}
	else
	{
		;
	}
	if(suc100msCnt >= ucPeriod) 
	{
		suc100msCnt = 0;
		ucRetValue = SET;
	}
	return ucRetValue;
}
UINT8 NormalControlPeriod(UINT8 ucInverter, UINT8 ucPeriod)
{
	static UINT8 suc100msCnt = 0;
	//UINT8 aucStopCnt[2] = 0;
	UINT8 ucRetValue = 0;
	
	if(guc100msControlFlag == SET)
	{
		guc100msControlFlag = CLR;
		suc100msCnt++;
	}
	else
	{
		;
	}
	

	if(suc100msCnt >= ucPeriod) 
	{
		suc100msCnt = 0;
		ucRetValue = SET;
	}
	else if(suc100msCnt == 1)
	{
		;
	}
	else if(suc100msCnt == 2)
	{
		;
	}
	else ucRetValue = 0;
	
	return ucRetValue;
}

void TotalPowerControl(UINT8 ucInverter)
{
	UINT8 ucOppositeInverter = OppositeInverter(ucInverter);
	
	if(gunInverterPower >= gastInverterModule[ucInverter].unMainCommandPower + gastInverterModule[ucOppositeInverter].unMainCommandPower)
	{
		gastInverterModule[ucInverter].unReg--;
	}
	else
	{
		gastInverterModule[ucInverter].unReg++;
	}
	gastInverterModule[ucOppositeInverter].unReg = gastInverterModule[ucInverter].unReg;
	
	if(gastInverterModule[ucInverter].unReg <= OSC/F23KHZ) gastInverterModule[ucInverter].unReg++;
}

void PowerControl(UINT8 ucInverter)
{
	if(gastInverterModule[ucInverter].unCalcPower >= gastInverterModule[ucInverter].unMainCommandPower)
	{
		gastInverterModule[ucInverter].unReg--;
	}
	else
	{
		gastInverterModule[ucInverter].unReg++;
	}
}
UINT16 gunTestAbPower = 0;
UINT16 gunTestTempPower[2][50] = {0,};
UINT16 gunTestCalcPower[2][50] = {0,};
UINT16 gunTestAbPowerTest[2][50] = {0,};
UINT8 gucTestIndex = 0;
void PanOff(UINT8 ucInverter)
{
	static UINT16 saunTempPower[2] = {0,};
	UINT16 unCalcPower = 0;
	UINT16 unAbPower = 0;
	UINT16 aunAbPower[2] = {0,};
	
	///gunTestCalcPower = gastInverterModule[ucInverter].unCalcPower;
	///gunTestTempPower = saunTempPower[0];
	
	if(gucFlexFlag == SET) //Check number of operate >= 2
	{
		//if(gastInverterModule[INVERTER0].ucProc >= NORMAL_MODE && gastInverterModule[INVERTER1].ucProc >= NORMAL_MODE)
		if(gastInverterModule[INVERTER0].ucStopFlag == 0 && gastInverterModule[INVERTER1].ucStopFlag == 0)
		{
			unCalcPower = gunInverterPower;
		}
		else
		{
			gunPanOffCheckPower[ucInverter] = 0;
			unCalcPower = 0;
		}
	}
	else unCalcPower = gastInverterModule[ucInverter].unCalcPower;
	
	if(gunPanOffCheckPower[ucInverter] == 0) gunPanOffCheckPower[ucInverter] = unCalcPower;
	else if(gunPanOffCheckPower[ucInverter] < unCalcPower)
	{
		////aunAbPower[ucInverter] = unCalcPower - gunPanOffCheckPower[ucInverter];
	}
	else
	{
		aunAbPower[ucInverter] = gunPanOffCheckPower[ucInverter] - unCalcPower;
	}
	/////
	gunTestTempPower[ucInverter][gucTestIndex] = gunPanOffCheckPower[ucInverter];
	gunTestCalcPower[ucInverter][gucTestIndex] = unCalcPower;
	////
	if(aunAbPower[ucInverter] >= 55)//60 or unCalcPower/10
	{
		gastInverterModule[INVERTER0].ucProc = IDLE_MODE;
		gastInverterModule[INVERTER1].ucProc = IDLE_MODE;	//For Refresh to Noise
	}
	
	gunPanOffCheckPower[ucInverter] = unCalcPower;
	
	/*if(saunTempPower[ucInverter] == 0) saunTempPower[ucInverter] = unCalcPower;//gastInverterModule[ucInverter].unCalcPower;
	if(saunTempPower[ucInverter] < unCalcPower)
	{
		aunAbPower[ucInverter] = unCalcPower - saunTempPower[ucInverter];
	}
	else
	{
		aunAbPower[ucInverter] = saunTempPower[ucInverter] - unCalcPower;
	}
	gunTestAbPower = aunAbPower[ucInverter];
	
	if(aunAbPower[ucInverter] >= 55) 
	{
		gastInverterModule[ucInverter].ucProc = IDLE_MODE;
		saunTempPower[ucInverter] = 0;
	}
	
	saunTempPower[ucInverter] = unCalcPower;
	*/
	//Test
	gunTestAbPowerTest[ucInverter][gucTestIndex++] = aunAbPower[ucInverter];
	if(gucTestIndex>=50) gucTestIndex = 0;
}

void NormalMode(UINT8 ucInverter)
{
	UINT8 ucOppositeInverter = OppositeInverter(ucInverter);
	
	if(gastInverterModule[ucInverter].unMainCommandPower < MINPOWER)
	{
		gastInverterModule[ucInverter].ucProc = IDLE_MODE;
	}
	else
	{
		if(gastInverterModule[ucOppositeInverter].ucInitOperatingFlag == SET)
		{
			PWMStop(ucInverter);
		}
		else
		{
			PWMStart(ucInverter);
			//ResCurLimit
			if(gastInverterModule[ucInverter].unResCur >= RESONANT_CURRENT_LIMIT)
			{
				gastInverterModule[ucInverter].unReg--;
			}
			else
			{
				//PowerControl
				if(gucFlexFlag == SET)
				{
					if(NormalControlPeriod(ucInverter, 3)) TotalPowerControl(ucInverter);
				}
				else
				{
					if(NormalControlPeriod(ucInverter, 1)) PowerControl(ucInverter);
				}
			}
			if(PanOffPeriod(1))PanOff(ucInverter);
			//PanOff(ucInverter);
		}
	}
}

void DutyControlMode(UINT8 ucInverter)
{
	UINT16 unPeriod = 0;
	static UINT16 sunOnTime = 0;
	static UINT16 sunCnt = 0;
	static UINT16 sunCalcPower = 0;
	
	unPeriod = 240;// 2sec/8.3ms
	if(gastInverterModule[ucInverter].unMainCommandPower < MINPOWER)
	{
		gastInverterModule[ucInverter].ucProc = IDLE_MODE;
	}
	else
	{
		//Duty Control
		sunCnt++;
		if(sunCnt >= unPeriod)
		{
			PWMStop(ucInverter);
			sunCnt = 0;
			if(gastInverterModule[ucInverter].unCalcPower != 0)
			{
				sunOnTime = (gastInverterModule[ucInverter].unMainCommandPower/sunCalcPower)*unPeriod;
			}
			else
			{
				;
			}
		}
		else
		{
			if(sunCnt >= sunOnTime)
			{
				PWMStop(ucInverter);
			}
			else
			{
				PWMStart(ucInverter);
				sunCalcPower = gastInverterModule[ucInverter].unCalcPower;
			}
		}
		
	}
}

void InverterControl(UINT8 ucInverter, UINT8 ucMode)
{
	switch(ucMode)
	{
		case IDLE_MODE: 
		{
			IdleMode(ucInverter);
			break;
		}
		case PANDETECT_MODE:
		{
			PanDetectMode(ucInverter);
			break;
		}
		case SOFTSTART_MODE:
		{
			SoftStartMode(ucInverter);
			break;
		}
		case NORMAL_MODE:
		{
			NormalMode(ucInverter);
			break;
		}
		case DUTYCONTROL_MODE:
		{
			DutyControlMode(ucInverter);
			break;
		}
		default :
			IdleMode(ucInverter);
			break;
	}
}