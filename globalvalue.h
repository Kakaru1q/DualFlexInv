/***********************************************************************/
/*                                                                     */
/*  FILE        :globalvalue.h                     		       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Global Value                                          */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                  				       */
/*                                                                     */
/***********************************************************************/
#include "typedefine.h"


#define TRUE	1
#define FALSE	0
#define SET	1
#define CLR	0
#define ON	1
#define OFF	0

#define STEP0		0
#define STEP1		1
#define STEP2		2
#define STEP3		3
#define STEP_BREAK	5

#define INPUTCURRENT 	1
#define INPUTVOLTAGE 	0
#define PAVOLTAGE 	2

#define OSC		(80000)
#define DEAD_TIME	(176)	//2.2us
#define PEAK2RMS	(707)	//0.707 = 1/root2
#define ISCALE		(82)	//81.92
#define VSCALE		(286)	//0.286
#define PASCALE		(167)	//0.167
#define RESSCALE	(25)//(33)	//32.768
#define PSCALE		(12)//(13)	//13.68

#define RESONANT_CURRENT_LIMIT		(38)	//40A	//(90)	//90A
#define INPUT_CURRENT_LIMIT		(16)	//16A
#define RESONANT_CURRENT_PROTECTION	(50)	//120A
#define	INPUT_CURRENT_PROTECTION	(20)	//20A

#define NUM_OF_INVERTER	(2)
#define INVERTER0	(0)
#define INVERTER1	(1)
#define INVERTER2	(2)

#define COIL_MAX	(4)
#define COIL0		(0)
#define COIL1		(1)
#define COIL2		(2)
#define COIL3		(3)
#define COIL4		(4)

#define MINPOWER	(30)
#define MAXPOWER	(3400)
#define DUTYCONTROL_POWER (600)

#define F70KHZ		(70)
#define F60KHZ		(60)
#define F20KHZ		(20)
#define F23KHZ		(23)

#define UART_STARTBIT	(0xAA)
#define UART_LENGTH_RX	(0x0A)
#define UART_LENGTH_TX	(0x08)

enum InverterMode{
	IDLE_MODE = 0,
	AUTO_DETECT_MODE,
	PANDETECT_MODE,
	SOFTSTART_MODE,
	NORMAL_MODE,
	DUTYCONTROL_MODE
};

struct InverterModule{
	UINT8 	ucProc;
	UINT16 	unMainCommandPower;
	UINT16	unCommandPower;
	
	UINT8 	ucFreq;
	UINT16	unReg;
	
	UINT8	ucSoftStartEndFreq;
	
	UINT8	ucInitOperatingFlag;
	
	UINT8	ucOnDuty;
	UINT8	ucStopFlag;
	
	UINT16	unCalcPower;
	UINT16	unResCur;
};

struct PanDetectValue{
	UINT16 unResCurrent;
	UINT16 unInputCurrent;
};

extern struct InverterModule gastInverterModule[NUM_OF_INVERTER];
extern struct PanDetectValue gastPanDetectValue[NUM_OF_INVERTER][2];

extern UINT8 gaucRX[UART_LENGTH_RX];
extern UINT8 gaucTX[UART_LENGTH_TX];
extern UINT8 gucRxCnt;
extern UINT8 gucTxCnt;
extern UINT8 guc100usSensingFlag;
extern UINT8 guc10usSensingFlag;
extern UINT8 guc100msControlFlag;
extern UINT8 guc100msPanOffFlag;

extern UINT8 ZeroCrossingFlag;

extern UINT8 gucFlexFlag;

extern UINT8 gucPandetectCntFlag;

extern UINT8 gaucCoil[NUM_OF_INVERTER][2];


extern UINT16 gunADCVoltagevalue;
extern UINT16 gunADCInputCurrentvalue;
extern UINT16 gunADCTopSensorvalue[4];
extern UINT16 gunADCIGBTSensorvalue[2];
extern UINT16 gunADCResCurvalue[2];
extern UINT16 gunADCPA0value;

extern UINT16 gunADCInputCurrentMovingAVGvalue;
extern UINT16 gunInputCurrentPeakADC;
extern UINT16 gunInputCurrentMinPeakADC;
extern UINT16 gunInputCurrentPeakvalue;
extern UINT16 gunInputCurrentPeak;
extern UINT16 gunInputCurrent;
extern UINT16 gunInputCurrentPeakTemp;
extern UINT16 gunInputCurrentPeakSum_PanDetect;

extern UINT16 gunADCVoltageMovingAVGvalue;
extern UINT16 gunVoltagePeak;
extern UINT16 gunVoltage;

extern UINT16 gunADCPAVoltageMovingAVGvalue;
extern UINT16 gunPAVoltagePeak;
extern UINT16 gunPAVoltage;

extern UINT16 gunResCurRef[2];
extern UINT16 gunResCurPeak[2];
extern UINT16 gunResCurrent[2];
extern UINT16 gunResCurPeakTemp[2];

extern UINT16 gunInverterPowerValue;
extern UINT16 gunInverterPower;

extern UINT16 gunPanOffCheckPower[2];