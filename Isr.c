/***********************************************************************/
/*                                                                     */
/*  FILE        :isr.c                     			       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Interrupt Service Routine                             */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/


/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "platform.h"
#include "globalvalue.h"
#include "PWMControl.h"

/***********************************************************************************************************************
* Function Name: r_Config_TMR0_cmia0_interrupt
* Description  : This function is CMIA0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_TMR0_CMIA0
#pragma interrupt r_Config_TMR0_cmia0_interrupt(vect=VECT(TMR0,CMIA0),fint)
#else
#pragma interrupt r_Config_TMR0_cmia0_interrupt(vect=VECT(TMR0,CMIA0))
#endif
static void r_Config_TMR0_cmia0_interrupt(void)
{
    
    //100us
//    PORT2.PODR.BIT.B1 ^= SET;

}

/***********************************************************************************************************************
* Function Name: r_Config_TMR2_cmia2_interrupt
* Description  : This function is CMIA2 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_TMR2_CMIA2
#pragma interrupt r_Config_TMR2_cmia2_interrupt(vect=VECT(TMR2,CMIA2),fint)
#else
#pragma interrupt r_Config_TMR2_cmia2_interrupt(vect=VECT(TMR2,CMIA2))
#endif
static void r_Config_TMR2_cmia2_interrupt(void)
{
	//10us
	guc10usSensingFlag = SET;
}

/***********************************************************************************************************************
* Function Name: r_Config_CMT0_cmi0_interrupt
* Description  : This function is CMI0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_CMT0_CMI0
#pragma interrupt r_Config_CMT0_cmi0_interrupt(vect=VECT(CMT0,CMI0),fint)
#else
#pragma interrupt r_Config_CMT0_cmi0_interrupt(vect=VECT(CMT0,CMI0))
#endif
static void r_Config_CMT0_cmi0_interrupt(void)
{
	//100us
    guc100usSensingFlag = SET;
    
}

/***********************************************************************************************************************
* Function Name: r_Config_CMT1_cmi1_interrupt
* Description  : This function is CMI1 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_CMT1_CMI1
#pragma interrupt r_Config_CMT1_cmi1_interrupt(vect=VECT(CMT1,CMI1),fint)
#else
#pragma interrupt r_Config_CMT1_cmi1_interrupt(vect=VECT(CMT1,CMI1))
#endif
static void r_Config_CMT1_cmi1_interrupt(void)
{
    //100ms
//    PORT2.PODR.BIT.B4 ^= SET;
	///gucPandetectCntFlag = SET;
	//guc100msControlCnt = 0;
	guc100msControlFlag = SET;
	guc100msPanOffFlag = SET;
}

/***********************************************************************************************************************
* Function Name: r_Config_ICU_irq1_interrupt
* Description  : This function is IRQ1 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_ICU_IRQ1
#pragma interrupt r_Config_ICU_irq1_interrupt(vect=VECT(ICU,IRQ1),fint)
#else
#pragma interrupt r_Config_ICU_irq1_interrupt(vect=VECT(ICU,IRQ1))
#endif
static void r_Config_ICU_irq1_interrupt(void)
{
    /* Start user code for r_Config_ICU_irq1_interrupt. Do not edit comment generated here */
    
    //ZeroCrossing
    //Falling Edge
//    if(PORT1.PODR.BIT.B1 == CLR)
    nop();
    
    ZeroCrossingFlag = SET;
    
    /* End user code. Do not edit comment generated here */
}


/***********************************************************************************************************************
* Function Name: r_Config_MTU3_tgia4_interrupt
* Description  : This function is TGIA4 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
UINT16 gunTestTCDRA = 0;
#if FAST_INTERRUPT_VECTOR == VECT_MTU4_TGIA4
#pragma interrupt r_Config_MTU3_MTU4_c4_tgia4_interrupt(vect=VECT(MTU4,TGIA4),fint)
#else
#pragma interrupt r_Config_MTU3_MTU4_c4_tgia4_interrupt(vect=VECT(MTU4,TGIA4))
#endif
static void r_Config_MTU3_MTU4_c4_tgia4_interrupt(void)
{
	// PWM MTU3 : MTIOC3B, MTIOC3D : Compare Match TGIA4 ISR	
  
  	MTU.TRWERA.BIT.RWE = 1U;	//Protect
	
    	MTU.TDDRA = DEAD_TIME;		//176	DeadTime(2.2us)
	MTU.TCDRA = gastInverterModule[INVERTER0].unReg >> 1;	//640	1/2Period
	MTU.TCBRA = gastInverterModule[INVERTER0].unReg >> 1;
	gunTestTCDRA = gastInverterModule[INVERTER0].unReg >> 1;
	MTU3.TGRA = DEAD_TIME + MTU.TCDRA;		//TDDRA(deadtime) + TCDRA(1/2 period)
	MTU3.TGRC = DEAD_TIME + MTU.TCDRA;
	MTU3.TGRB = MTU.TCDRA - DEAD_TIME; 
	MTU3.TGRD = MTU.TCDRA - DEAD_TIME;
	
	
	if(gastInverterModule[INVERTER0].ucStopFlag == SET)
	{
		PWM_MTU3_Stop();
	}
	else
	{
		;
	}
	
	MTU.TRWERA.BIT.RWE = 0U;	//Protect

}



/***********************************************************************************************************************
* Function Name: r_Config_MTU6_tgia7_interrupt
* Description  : This function is TGIA7 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_MTU7_TGIB7
#pragma interrupt r_Config_MTU6_MTU7_c7_tgib7_interrupt(vect=VECT(MTU7,TGIB7),fint)
#else
#pragma interrupt r_Config_MTU6_MTU7_c7_tgib7_interrupt(vect=VECT(MTU7,TGIB7))
#endif
static void r_Config_MTU6_MTU7_c7_tgib7_interrupt(void)
{
 
   	MTU.TRWERB.BIT.RWE = 1U;	//Protect
	
        MTU.TDDRB = DEAD_TIME;			//176	DeadTime(2.2us)
	MTU.TCDRB = gastInverterModule[INVERTER1].unReg >> 1;	//640	1/2Period
	MTU.TCBRB = gastInverterModule[INVERTER1].unReg >> 1;
	MTU6.TGRA = DEAD_TIME + MTU.TCDRB;		
	MTU6.TGRC = DEAD_TIME + MTU.TCDRB;
	MTU7.TGRA = MTU.TCDRB - DEAD_TIME;
	MTU7.TGRC = MTU.TCDRB - DEAD_TIME;
	
    	if(gastInverterModule[INVERTER1].ucStopFlag == SET)
	{
		PWM_MTU6_Stop();
	}
	else
	{
		;
	}
	
	MTU.TRWERB.BIT.RWE = 0U;	//Protect
    
}




/***********************************************************************************************************************
* Function Name: r_Config_SCI5_receive_interrupt
* Description  : This function is RXI5 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_SCI5_RXI5
#pragma interrupt r_Config_SCI5_receive_interrupt(vect=VECT(SCI5,RXI5),fint)
#else
#pragma interrupt r_Config_SCI5_receive_interrupt(vect=VECT(SCI5,RXI5))
#endif
static void r_Config_SCI5_receive_interrupt(void)
{
    if (UART_LENGTH_RX > gucRxCnt)
    {
        gaucRX[gucRxCnt] = SCI5.RDR;
        gucRxCnt++;
    }
    if (UART_LENGTH_RX <= gucRxCnt)
    {
	gucRxCnt = 0;
	//SCI5.SCR.BIT.RIE = 0U;
        //SCI5.SCR.BIT.RE = 0U; 
    }

}

/***********************************************************************************************************************
* Function Name: r_Config_SCI5_transmit_interrupt
* Description  : This function is TXI5 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_SCI5_TXI5
#pragma interrupt r_Config_SCI5_transmit_interrupt(vect=VECT(SCI5,TXI5),fint)
#else
#pragma interrupt r_Config_SCI5_transmit_interrupt(vect=VECT(SCI5,TXI5))
#endif
static void r_Config_SCI5_transmit_interrupt(void)
{
    //if (0U < gucTxCnt)
    if (UART_LENGTH_TX > gucTxCnt)
    {
        SCI5.TDR = gaucTX[gucTxCnt];
     //   gp_sci5_tx_address++;
     //   g_sci5_tx_count--;
	gucTxCnt++;
    }
    else
    {
	gucTxCnt = 0;
        SCI5.SCR.BIT.TIE = 0U;
        SCI5.SCR.BIT.TEIE = 1U;
    }
}


/***********************************************************************************************************************
* Function Name: r_Config_SCI5_transmitend_interrupt
* Description  : This function is TEI5 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_SCI5_TEI5
#pragma interrupt r_Config_SCI5_transmitend_interrupt(vect=VECT(SCI5,TEI5),fint)
#else
#pragma interrupt r_Config_SCI5_transmitend_interrupt(vect=VECT(SCI5,TEI5))
#endif
static void r_Config_SCI5_transmitend_interrupt(void)
{
    /* Set TXD5 pin */
    PORTB.PMR.BYTE &= 0xDFU;

    SCI5.SCR.BIT.TIE = 0U;
    SCI5.SCR.BIT.TE = 0U;
    SCI5.SCR.BIT.TEIE = 0U;

 //   r_Config_SCI5_callback_transmitend();
}


/***********************************************************************************************************************
* Function Name: r_Config_SCI5_receiveerror_interrupt
* Description  : This function is ERI5 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_SCI5_ERI5
#pragma interrupt r_Config_SCI5_receiveerror_interrupt(vect=VECT(SCI5,ERI5),fint)
#else
#pragma interrupt r_Config_SCI5_receiveerror_interrupt(vect=VECT(SCI5,ERI5))
#endif
static void r_Config_SCI5_receiveerror_interrupt(void)
{
    uint8_t err_type;

 //   r_Config_SCI5_callback_receiveerror();

    /* Clear overrun, framing and parity error flags */
    err_type = SCI5.SSR.BYTE;
    err_type &= 0xC7U;
    err_type |= 0xC0U;
    SCI5.SSR.BYTE = err_type;
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI5_callback_transmitend
* Description  : This function is a callback function when SCI5 finishes transmission
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI5_callback_transmitend(void)
{
    /* Start user code for r_Config_SCI5_callback_transmitend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI5_callback_receiveend
* Description  : This function is a callback function when SCI5 finishes reception
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI5_callback_receiveend(void)
{
    /* Start user code for r_Config_SCI5_callback_receiveend. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI5_callback_receiveerror
* Description  : This function is a callback function when SCI5 reception encounters error
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI5_callback_receiveerror(void)
{
    /* Start user code for r_Config_SCI5_callback_receiveerror. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}