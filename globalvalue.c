/***********************************************************************/
/*                                                                     */
/*  FILE        :globalvalue.c                     		       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Global Value                                          */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                  				       */
/*                                                                     */
/***********************************************************************/
#include "typedefine.h"
#include "globalvalue.h"

struct InverterModule gastInverterModule[NUM_OF_INVERTER] = {0,};
struct PanDetectValue gastPanDetectValue[NUM_OF_INVERTER][2] = {0,};

UINT8 gaucRX[UART_LENGTH_RX] = {0,};
UINT8 gaucTX[UART_LENGTH_TX] = {0,};
UINT8 gucRxCnt = 0;
UINT8 gucTxCnt = 0;

UINT8 guc100usSensingFlag = 0;
UINT8 guc10usSensingFlag = 0;
UINT8 guc100msControlFlag = 0;
UINT8 guc100msPanOffFlag = 0;

UINT8 ZeroCrossingFlag = CLR;

UINT8 gucFlexFlag = 0;

UINT8 gucPandetectCntFlag = 0;

UINT8 gaucTopSensor[COIL_MAX] = {0,};

UINT8 gaucCoil[NUM_OF_INVERTER][2] = {0,};



UINT16 gunADCVoltagevalue = 0;
UINT16 gunADCInputCurrentvalue = 0;
UINT16 gunADCTopSensorvalue[4] = {0,};
UINT16 gunADCIGBTSensorvalue[2] = {0,};
UINT16 gunADCResCurvalue[2] = {0,};
UINT16 gunADCPA0value = 0;

UINT16 gunADCInputCurrentMovingAVGvalue = 0;
UINT16 gunInputCurrentPeakADC = 0;
UINT16 gunInputCurrentMinPeakADC = 0;
UINT16 gunInputCurrentPeakvalue = 0;
UINT16 gunInputCurrentPeak = 0;
UINT16 gunInputCurrent = 0;
UINT16 gunInputCurrentPeakTemp = 0;
UINT16 gunInputCurrentPeakSum_PanDetect = 0;

UINT16 gunADCVoltageMovingAVGvalue = 0;
UINT16 gunVoltagePeak = 0;
UINT16 gunVoltage = 0;

UINT16 gunADCPAVoltageMovingAVGvalue = 0;
UINT16 gunPAVoltagePeak = 0;
UINT16 gunPAVoltage = 0;

UINT16 gunResCurRef[2] = {0,};
UINT16 gunResCurPeak[2] = {0,};
UINT16 gunResCurrent[2] = {0,};
UINT16 gunResCurPeakTemp[2] = {0,};

UINT16 gunInverterPowerValue = 0;
UINT16 gunInverterPower = 0;

UINT16 gunPanOffCheckPower[2] = {0,};