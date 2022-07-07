/***********************************************************************/
/*                                                                     */
/*  FILE        :Timer.c                     		      	       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Fan Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "platform.h"
#include "Timer.h"


void CMT0Start()
{
	    /* Enable CMI0 interrupt in ICU */
    IEN(CMT0,CMI0) = 1U;

    /* Start CMT0 count */
    CMT.CMSTR0.BIT.STR0 = 1U;
}

void CMT1Start()
{
	    /* Enable CMI1 interrupt in ICU */
    IEN(CMT1,CMI1) = 1U;

    /* Start CMT1 count */
    CMT.CMSTR0.BIT.STR1 = 1U;
}

void TMR0Start()
{	    
    //Timer Start
    /* Enable TMR0 interrupt */
    IR(TMR0, CMIA0) = 0U;
    IEN(TMR0, CMIA0) = 1U;

    /* Start counting */
    TMR0.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _04_TMR_PCLK_DIV_64;
}

void TMR2Start()
{
    /* Enable TMR2 interrupt */
    IR(TMR2, CMIA2) = 0U;
    IEN(TMR2, CMIA2) = 1U;

    /* Start counting */
    TMR2.TCCR.BYTE = _08_TMR_CLK_SRC_PCLK | _02_TMR_PCLK_DIV_8;
}

void TimerStart()
{
	CMT0Start();
	CMT1Start();
	TMR0Start();
	TMR2Start();
}