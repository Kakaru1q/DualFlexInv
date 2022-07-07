/***********************************************************************/
/*                                                                     */
/*  FILE        :PWMControl.h                     		       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :PWM Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/

#include "typedefine.h"


/*
    Timer Start Registers (TSTR)
*/
/* Counter Start 0 (CST0) */
#define _00_MTU_CST0_OFF               (0x00U) /* MTU0.TCNT performs count stop */
#define _01_MTU_CST0_ON                (0x01U) /* MTU0.TCNT performs count operation */
/* Counter Start 1 (CST1) */       
#define _00_MTU_CST1_OFF               (0x00U) /* MTU1.TCNT performs count stop */
#define _02_MTU_CST1_ON                (0x02U) /* MTU1.TCNT performs count operation */
/* Counter Start 2 (CST2) */       
#define _00_MTU_CST2_OFF               (0x00U) /* MTU2.TCNT performs count stop */
#define _04_MTU_CST2_ON                (0x04U) /* MTU2.TCNT performs count operation */
/* Counter Start 9 (CST9) */       
#define _00_MTU_CST9_OFF               (0x00U) /* MTU9.TCNT performs count stop */
#define _10_MTU_CST9_ON                (0x10U) /* MTU9.TCNT performs count operation */
/* Counter Start 3 (CST3) */       
#define _00_MTU_CST3_OFF               (0x00U) /* MTU3.TCNT performs count stop */
#define _40_MTU_CST3_ON                (0x40U) /* MTU3.TCNT performs count operation */
/* Counter Start 4 (CST4) */       
#define _00_MTU_CST4_OFF               (0x00U) /* MTU4.TCNT performs count stop */
#define _80_MTU_CST4_ON                (0x80U) /* MTU4.TCNT performs count operation */
/* Counter Start 6 (CST6) */       
#define _00_MTU_CST6_OFF               (0x00U) /* MTU6.TCNT performs count stop */
#define _40_MTU_CST6_ON                (0x40U) /* MTU6.TCNT performs count operation */
/* Counter Start 7 (CST7) */       
#define _00_MTU_CST7_OFF               (0x00U) /* MTU7.TCNT performs count stop */
#define _80_MTU_CST7_ON                (0x80U) /* MTU7.TCNT performs count operation */
/* Counter Start W5 (CSTW5) */       
#define _00_MTU_CSTW5_OFF              (0x00U) /* MTU5.TCNTW count operation is stopped */
#define _01_MTU_CSTW5_ON               (0x01U) /* MTU5.TCNTW performs count operation */
/* Counter Start V5 (CSTV5) */       
#define _00_MTU_CSTV5_OFF              (0x00U) /* MTU5.TCNTV count operation is stopped */
#define _02_MTU_CSTV5_ON               (0x02U) /* MTU5.TCNTV performs count operation */
/* Counter Start U5 (CSTU5) */       
#define _00_MTU_CSTU5_OFF              (0x00U) /* MTU5.TCNTU count operation is stopped */
#define _04_MTU_CSTU5_ON               (0x04U) /* MTU5.TCNTU performs count operation */




void PWMStart(UINT8 ucInverter);
void PWMStop(UINT8 ucInverter);

void PWM_MTU3_Start(void);
void PWM_MTU6_Start(void);
void PWM_MTU3_Stop(void);
void PWM_MTU6_Stop(void);


