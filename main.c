/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                     			       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "typedefine.h"

#include "globalvalue.h"
#include "init.h"
#include "InverterControl.h"
#include "FanControl.h"
#include "Sensing.h"
#include "Uart.h"
#include "ErrorControl.h"
#include "Timer.h"
#include "PWMControl.h"

void ZeroCrossingJob(void);
void main(void);

UINT8 gucTestPWM = 0;
UINT8 gucTestFreq = 0;
UINT8 gucTestRelay = 0;
UINT16 gunTestCommandPower0 = 0;
UINT16 gunTestCommandPower1 = 0;
UINT16 gunTestCommandPower = 0;

void main(void)
{

	//init
	Init();
	TimerStart();
//	ADCStart();
	UARTStart();

	//main
	while(TRUE)
	{
		//UART
		RxDataGet();
		//Sensor Job
		SensingJob();
		ZeroCrossingJob(); //TrueZero
		//ErrorControl
		ErrorControl();
	}
}


void ZeroCrossingJob()
{
	/*if(gucTestRelay == 1)
	{
		ED_GateDriver_Control(INVERTER0, SET);
		CoilRelayControl(COIL0,ON);
		CoilRelayControl(COIL1,ON);
		CoilRelayControl(COIL2,OFF);
		CoilRelayControl(COIL3,OFF);
		gastInverterModule[INVERTER0].unMainCommandPower = gunTestCommandPower;
		if(gucTestPWM == 1)
		{
		//	PWMStart(INVERTER0);
		//	gastInverterModule[INVERTER0].unReg = OSC/gucTestFreq;
		}
		else
		{
		//	PWMStop(INVERTER0);
		//	PWMStop(INVERTER1);
		}
	}
	else
	{
		ED_GateDriver_Control(INVERTER0, CLR);
		CoilRelayControl(COIL0,OFF);
		CoilRelayControl(COIL1,OFF);
		CoilRelayControl(COIL2,OFF);
		CoilRelayControl(COIL3,OFF);
	}*/
	
	if(gucFlexFlag) 
	{
		gunTestCommandPower0 = gunTestCommandPower/2;
		gunTestCommandPower1 = gunTestCommandPower/2;
	}
	
	gastInverterModule[INVERTER0].unMainCommandPower = gunTestCommandPower0;
	gastInverterModule[INVERTER1].unMainCommandPower = gunTestCommandPower1;
	
	if(ZeroCrossingFlag == SET)//TrueZero
	{
		
		//CalcSensing
		CalcADCValue();
		//InverterControl
		InverterControl(INVERTER0, gastInverterModule[INVERTER0].ucProc);	//InvControl 1 ? InvControl 2 ??
		InverterControl(INVERTER1, gastInverterModule[INVERTER1].ucProc);
		gastInverterModule[INVERTER0].ucFreq = OSC/gastInverterModule[INVERTER0].unReg;
		gastInverterModule[INVERTER1].ucFreq = OSC/gastInverterModule[INVERTER1].unReg;
		//FanControl
		////FanControl();
		ZeroCrossingFlag = CLR;
	}
	else
	{
		;
	}
	
}

