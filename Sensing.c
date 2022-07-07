/***********************************************************************/
/*                                                                     */
/*  FILE        :Sensing.c                     			       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Sensor Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "platform.h"
#include "Sensing.h"
#include "globalvalue.h"

void S12AD0_Get_ValueResult(ad_channel_t channel, UINT16 * const buffer);
void S12AD1_Get_ValueResult(ad_channel_t channel, UINT16 * const buffer);
void S12AD2_Get_ValueResult(ad_channel_t channel, UINT16 * const buffer);

UINT16 MovingAvg(UINT16 unAdcValue, UINT8 ucType)
{
	static UINT8 sucAdcIndex[3] = {0,};
	static UINT16 saunValue[3][10] = {0,};
	static UINT16 sunValueSum[3] = {0,};
	UINT8 ucI = 0;
	UINT16 sunValueMax = 0;
	UINT16 sunValueMin = 0xFFFF;
	UINT16 unMovingAvg = 0;


	sunValueSum[ucType] -= saunValue[ucType][sucAdcIndex[ucType]];
	saunValue[ucType][sucAdcIndex[ucType]] = unAdcValue;
	for(ucI = 0; ucI < 10; ucI++)
	{
		if(saunValue[ucType][ucI] > sunValueMax) sunValueMax = saunValue[ucType][ucI];
		if(saunValue[ucType][ucI] < sunValueMin) sunValueMin = saunValue[ucType][ucI];
	}
	
	sunValueSum[ucType] += saunValue[ucType][sucAdcIndex[ucType]++];
	if(sucAdcIndex[ucType] >= 10) sucAdcIndex[ucType] = 0;
	unMovingAvg = (sunValueSum[ucType] - sunValueMax - sunValueMin) >> 3;
	
	
	return unMovingAvg;
}
UINT16 gunTestPeak[83] = {0,};
UINT16 testi = 0;
UINT16 testtesti = 0;
void GetADCBuffer()
{
	
	S12AD2_Get_ValueResult(ADCHANNEL10, &gunADCVoltagevalue);
	S12AD1_Get_ValueResult(ADCHANNEL0, &gunADCInputCurrentvalue);
	S12AD2_Get_ValueResult(ADCHANNEL9, &gunADCTopSensorvalue[0]);
	S12AD2_Get_ValueResult(ADCHANNEL8, &gunADCTopSensorvalue[1]);
	S12AD2_Get_ValueResult(ADCHANNEL7, &gunADCTopSensorvalue[2]);
	S12AD2_Get_ValueResult(ADCHANNEL6, &gunADCTopSensorvalue[3]);
	S12AD1_Get_ValueResult(ADCHANNEL1, &gunADCIGBTSensorvalue[0]);
	S12AD0_Get_ValueResult(ADCHANNEL1, &gunADCIGBTSensorvalue[1]);
	S12AD0_Get_ValueResult(ADCHANNEL0, &gunADCPA0value);
	gunADCInputCurrentMovingAVGvalue = MovingAvg(gunADCInputCurrentvalue, INPUTCURRENT);
	gunADCVoltageMovingAVGvalue = MovingAvg(gunADCVoltagevalue, INPUTVOLTAGE);
	gunADCPAVoltageMovingAVGvalue = MovingAvg(gunADCPA0value, PAVOLTAGE);
	if(gunADCInputCurrentMovingAVGvalue >= gunInputCurrentPeakADC) gunInputCurrentPeakADC = gunADCInputCurrentMovingAVGvalue;
	if(gunADCInputCurrentMovingAVGvalue <= gunInputCurrentMinPeakADC) gunInputCurrentMinPeakADC = gunADCInputCurrentMovingAVGvalue;
	
	if(gunADCVoltageMovingAVGvalue >= gunVoltagePeak) gunVoltagePeak = gunADCVoltageMovingAVGvalue;
	if(gunADCPAVoltageMovingAVGvalue >= gunPAVoltagePeak) gunPAVoltagePeak = gunADCPAVoltageMovingAVGvalue;
	
	if(gastInverterModule[INVERTER0].unMainCommandPower > 0)
	{
		gunTestPeak[testi++] = gunInputCurrentPeakADC;
	}
	//if(testi >= 83) testi = 0;
	
}
UINT16 gunTestCurrpeak = 0;
void CalcADCValue()
{
	//8.3ms
	testtesti = testi;
	testi=0;
	
/*	if(gunInputCurrentPeakADC > 2048) gunInputCurrentPeakADC -= 2048;
	else gunInputCurrentPeakADC = 0;
	if(gunInputCurrentMinPeakADC < 2048) gunInputCurrentMinPeakADC = 2048 - gunInputCurrentMinPeakADC;
	else gunInputCurrentMinPeakADC = 0;
	if(gunInputCurrentPeakADC >= gunInputCurrentMinPeakADC)
	{
		gunInputCurrentPeakvalue = gunInputCurrentPeakADC;
	}
	else
	{
		gunInputCurrentPeakvalue = gunInputCurrentMinPeakADC;
	}*/

	
	gunInputCurrentPeak = (UINT16)(((UINT32)gunInputCurrentPeakvalue * ISCALE)/1000);
	gunInputCurrent = gunInputCurrentPeak * PEAK2RMS / 1000;
	////gunVoltage = (gunVoltagePeak * PEAK2RMS * VSCALE)/1000000;
	////gunPAVoltage = (UINT16)(((UINT32)gunADCPAVoltageMovingAVGvlaue * PASCALE)/1000);
	//gunVoltagePeakvalue = (UINT16)(((UINT32)gunVoltagePeak * VSCALE)/1000);
	gunPAVoltage = (UINT16)(((UINT32)gunPAVoltagePeak * PASCALE)/1000);
	gunVoltage = gunPAVoltage * PEAK2RMS / 1000;
	
	gunInverterPowerValue = (UINT16)(((UINT32)(gunPAVoltagePeak * gunInputCurrentPeakvalue) * PSCALE)/1000);
	gunInverterPower = gunInverterPowerValue * PEAK2RMS / 10000;
	
	gunResCurPeakTemp[INVERTER0] = gunResCurPeak[INVERTER0];
	gunResCurPeakTemp[INVERTER1] = gunResCurPeak[INVERTER1];
	gunInputCurrentPeakTemp = gunInputCurrentPeakvalue;
	
	gunInputCurrentPeakADC = 0;
	gunInputCurrentMinPeakADC = 0xFFFF;
	gunVoltagePeak = 0;
	gunPAVoltagePeak = 0;
	gunResCurPeak[INVERTER0] = 0;
	gunResCurPeak[INVERTER1] = 0;
	
	//if(MTU.TSTRA.BYTE == 1 && MTU.TSTRB.BYTE == 0) gastInverterModule[INVERTER0].unCalcPower = gunInverterPower;
	//else if(MTU.TSTRA.BYTE == 0 && MTU.TSTRB.BYTE == 1) gastInverterModule[INVERTER1].unCalcPower = gunInverterPower;
	if(gastInverterModule[INVERTER1].ucStopFlag == SET) gastInverterModule[INVERTER0].unCalcPower = gunInverterPower;
	else if(gastInverterModule[INVERTER0].ucStopFlag == SET) gastInverterModule[INVERTER1].unCalcPower = gunInverterPower;
	/*if(gucFlexFlag == SET)
	{
		gastInverterModule[INVERTER0].unCalcPower = gunInverterPower/2;
		gastInverterModule[INVERTER1].unCalcPower = gunInverterPower/2;
	}
	else
	{
		gastInverterModule[INVERTER0].unCalcPower = gunInverterPower;
		gastInverterModule[INVERTER1].unCalcPower = gunInverterPower;
	}*/
	//gastInverterModule[INVERTER0].unCalcPower = gunInverterPower;
	//gastInverterModule[INVERTER1].unCalcPower = gunInverterPower;
	
	////gunInverterPower = gunVoltage * gunInputCurrent;	//ReCalc use to PSCALE?
}

void GetResCurBuffer()
{
	S12AD1_Get_ValueResult(ADCHANNEL2, &gunADCResCurvalue[INVERTER0]);
	S12AD0_Get_ValueResult(ADCHANNEL2, &gunADCResCurvalue[INVERTER1]);
	if(gunADCResCurvalue[INVERTER0] >= gunResCurPeak[INVERTER0]) gunResCurPeak[INVERTER0] = gunADCResCurvalue[INVERTER0];
	if(gunADCResCurvalue[INVERTER1] >= gunResCurPeak[INVERTER1]) gunResCurPeak[INVERTER1] = gunADCResCurvalue[INVERTER1];
	if(MTU.TSTRA.BYTE == 0)
	{
		gunResCurRef[INVERTER0] = gunResCurPeak[INVERTER0]; //MaxRef? MinRef?
	}
	else
	{
		if(gunResCurPeak[INVERTER0] < gunResCurRef[INVERTER0]) gunResCurPeak[INVERTER0] = gunResCurRef[INVERTER0];
		gunResCurrent[INVERTER0] = (gunResCurPeak[INVERTER0] - gunResCurRef[INVERTER0])/RESSCALE;
	}
	
	if(MTU.TSTRB.BYTE == 0)
	{
		gunResCurRef[INVERTER1] = gunResCurPeak[INVERTER1]; //MaxRef? MinRef?
	}
	else
	{
		if(gunResCurPeak[INVERTER1] < gunResCurRef[INVERTER1]) gunResCurPeak[INVERTER1] = gunResCurRef[INVERTER1];
		gunResCurrent[INVERTER1] = (gunResCurPeak[INVERTER1] - gunResCurRef[INVERTER1])/RESSCALE;
	}

}

void SensingJob()
{
	if(guc100usSensingFlag == SET)//Conversion End Int ??
	{
		GetADCBuffer();
		guc100usSensingFlag = CLR;
	}
	else
	{
		;
	}
	if(guc10usSensingFlag == SET)
	{
		GetResCurBuffer();
		guc10usSensingFlag = CLR;
	}
	else
	{
		;
	}
}

void S12AD0_Get_ValueResult(ad_channel_t channel, UINT16 * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            *buffer = (UINT16)(S12AD.ADRD);
            break;
        }
        case ADCHANNEL0:
        {
            *buffer = (UINT16)(S12AD.ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            *buffer = (UINT16)(S12AD.ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            *buffer = (UINT16)(S12AD.ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            *buffer = (UINT16)(S12AD.ADDR3);
            break;
        }
        case ADCHANNEL16:
        {
            *buffer = (UINT16)(S12AD.ADDR16);
            break;
        }
        case ADDATADUPLICATION:
        {
            *buffer = (UINT16)(S12AD.ADDBLDR);
            break;
        }
        case ADDATADUPLICATIONA:
        {
            *buffer = (UINT16)(S12AD.ADDBLDRA);
            break;
        }
        case ADDATADUPLICATIONB:
        {
            *buffer = (UINT16)(S12AD.ADDBLDRB);
            break;
        }
        default:
        {
            break;
        }
    }
}

void S12AD1_Get_ValueResult(ad_channel_t channel, UINT16 * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            *buffer = (UINT16)(S12AD1.ADRD);
            break;
        }
        case ADCHANNEL0:
        {
            *buffer = (UINT16)(S12AD1.ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            *buffer = (UINT16)(S12AD1.ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            *buffer = (UINT16)(S12AD1.ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            *buffer = (UINT16)(S12AD1.ADDR3);
            break;
        }
        case ADCHANNEL16:
        {
            *buffer = (UINT16)(S12AD1.ADDR16);
            break;
        }
        case ADDATADUPLICATION:
        {
            *buffer = (UINT16)(S12AD1.ADDBLDR);
            break;
        }
        case ADDATADUPLICATIONA:
        {
            *buffer = (UINT16)(S12AD1.ADDBLDRA);
            break;
        }
        case ADDATADUPLICATIONB:
        {
            *buffer = (UINT16)(S12AD1.ADDBLDRB);
            break;
        }
        default:
        {
            break;
        }
    }
}

void S12AD2_Get_ValueResult(ad_channel_t channel, UINT16 * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            *buffer = (UINT16)(S12AD2.ADRD);
            break;
        }
        case ADCHANNEL0:
        {
            *buffer = (UINT16)(S12AD2.ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            *buffer = (UINT16)(S12AD2.ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            *buffer = (UINT16)(S12AD2.ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            *buffer = (UINT16)(S12AD2.ADDR3);
            break;
        }
        case ADCHANNEL4:
        {
            *buffer = (UINT16)(S12AD2.ADDR4);
            break;
        }
        case ADCHANNEL5:
        {
            *buffer = (UINT16)(S12AD2.ADDR5);
            break;
        }
        case ADCHANNEL6:
        {
            *buffer = (UINT16)(S12AD2.ADDR6);
            break;
        }
        case ADCHANNEL7:
        {
            *buffer = (UINT16)(S12AD2.ADDR7);
            break;
        }
        case ADCHANNEL8:
        {
            *buffer = (UINT16)(S12AD2.ADDR8);
            break;
        }
        case ADCHANNEL9:
        {
            *buffer = (UINT16)(S12AD2.ADDR9);
            break;
        }
        case ADCHANNEL10:
        {
            *buffer = (UINT16)(S12AD2.ADDR10);
            break;
        }
        case ADCHANNEL11:
        {
            *buffer = (UINT16)(S12AD2.ADDR11);
            break;
        }
        case ADINTERREFVOLT:
        {
            *buffer = (UINT16)(S12AD2.ADOCDR);
            break;
        }
        case ADDATADUPLICATION:
        {
            *buffer = (UINT16)(S12AD2.ADDBLDR);
            break;
        }
        case ADDATADUPLICATIONA:
        {
            *buffer = (UINT16)(S12AD2.ADDBLDRA);
            break;
        }
        case ADDATADUPLICATIONB:
        {
            *buffer = (UINT16)(S12AD2.ADDBLDRB);
            break;
        }
        default:
        {
            break;
        }
    }
}




void ADC0Start()
{
    IR(S12AD, S12ADI) = 0U;
    IEN(S12AD, S12ADI) = 1U;
    IR(S12AD, GBADI) = 0U;
    IEN(S12AD, GBADI) = 1U;
    S12AD.ADCSR.BIT.TRGE = 1U;
}

void ADC1Start()
{
    IR(S12AD1, S12ADI1) = 0U;
    IEN(S12AD1, S12ADI1) = 1U;
    IR(S12AD1, GBADI1) = 0U;
    IEN(S12AD1, GBADI1) = 1U;
    S12AD1.ADCSR.BIT.TRGE = 1U;
}

void ADC2Start()
{
    IR(S12AD2, S12ADI2) = 0U;
    IEN(S12AD2, S12ADI2) = 1U;
    S12AD2.ADCSR.BIT.ADST = 1U;
}

void ADCStart()
{
	ADC0Start();
	ADC1Start();
	ADC2Start();
}