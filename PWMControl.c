/***********************************************************************/
/*                                                                     */
/*  FILE        :PWMControl.c                     		       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :PWM Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "platform.h"
#include "PWMControl.h"
#include "globalvalue.h"

void PWMStart(UINT8 ucInverter)
{
	switch(ucInverter)
	{
		case INVERTER0 :
			PWM_MTU3_Start();
			gastInverterModule[INVERTER0].ucStopFlag = CLR;
			break;
		case INVERTER1 :
			PWM_MTU6_Start();
			gastInverterModule[INVERTER1].ucStopFlag = CLR;
			break;
		default :
			PWM_MTU3_Stop();
			PWM_MTU6_Stop();
			break;
	}
}

void PWMStop(UINT8 ucInverter)
{
	switch(ucInverter)
	{
		case INVERTER0 :
			gastInverterModule[INVERTER0].ucStopFlag = SET;
			//PWM_MTU3_Stop();
			break;
		case INVERTER1 :
			gastInverterModule[INVERTER1].ucStopFlag = SET;
			//PWM_MTU6_Stop();
			break;
		default :
			PWM_MTU3_Stop();
			PWM_MTU6_Stop();
			break;
	}
}

void PWM_MTU3_Start()
{
    /* Enable TGIA4 interrupt in ICU */
    IEN(MTU4,TGIA4) = 1U;

    /* Start count operation */
    MTU.TSTRA.BYTE |= _40_MTU_CST3_ON | _80_MTU_CST4_ON;
}

void PWM_MTU3_Stop()
{
    /* Disable TGIA4 interrupt in ICU */
    IEN(MTU4,TGIA4) = 0U;

    /* Stop counting */
    MTU.TSTRA.BIT.CST3 = 0U;
    MTU.TSTRA.BIT.CST4 = 0U;
}

void PWM_MTU6_Start()
{
    /* Enable TGIB7 interrupt in ICU */
    IEN(MTU7,TGIB7) = 1U;

    /* Start count operation */
    MTU.TSTRB.BYTE |= _40_MTU_CST6_ON | _80_MTU_CST7_ON; 
}

void PWM_MTU6_Stop()
{
    /* Disable TGIB7 interrupt in ICU */
    IEN(MTU7,TGIB7) = 0U;

    /* Stop counting */
    MTU.TSTRB.BIT.CST6 = 0U;
    MTU.TSTRB.BIT.CST7 = 0U;
}
