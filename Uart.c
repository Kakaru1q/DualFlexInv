/***********************************************************************/
/*                                                                     */
/*  FILE        :Uart.c                     			       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Uart Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "Uart.h"
#include "platform.h"

void Sci5Start()
{
    /* Clear interrupt flag */
    IR(SCI5,TXI5) = 0U;
    IR(SCI5,RXI5) = 0U;

    /* Enable SCI interrupt */
    IEN(SCI5,TXI5) = 1U;
    IEN(SCI5,TEI5) = 1U;
    IEN(SCI5,RXI5) = 1U;
    //IEN(SCI5,ERI5) = 1U;
    
    //RIE = 1
    //RE = 1
}
void UARTStart()
{	
	Sci5Start();
}

void RxDataGet()
{
	//if RX Complete, Data Get & TX Start 
}