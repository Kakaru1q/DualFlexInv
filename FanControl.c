/***********************************************************************/
/*                                                                     */
/*  FILE        :FanControl.c                     		       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Fan Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "platform.h"
#include "globalvalue.h"
#include "typedefine.h"
#include "FanControl.h"


void Fan(UINT8 ucCmd)
{
	PORTB.PODR.BIT.B1 = ucCmd;
}

void FanControl()
{
	//if Inverter On : ON
	if(gastInverterModule[INVERTER0].unMainCommandPower >= MINPOWER || gastInverterModule[INVERTER1].unMainCommandPower >= MINPOWER)
	{
		Fan(ON);
	}
	else
	{
		//elif Temp Normal : OFF
		Fan(OFF);
	}
}