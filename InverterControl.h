/***********************************************************************/
/*                                                                     */
/*  FILE        :InverterControl.h                     		       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Inverter Control		                       */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "typedefine.h"

void InverterControl(UINT8 ucInverter, UINT8 ucMode);
void CoilRelayControl(UINT8 ucCoil, UINT8 ucCmd);
void ED_GateDriver_Control(UINT8 ucInverter, UINT8 ucCmd);