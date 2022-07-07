/***********************************************************************/
/*                                                                     */
/*  FILE        :Timer.h                     		       	       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Fan Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/

/* 
    Timer Counter Control Register (TCCR)
*/

/* Clock Source Select (CSS[1:0]) */
#define _08_TMR_CLK_SRC_PCLK                        (0x08U) /* Use PCLK */

#define _00_TMR_PCLK_DIV_1                          (0x00U) /* Count at PCLK */
#define _01_TMR_PCLK_DIV_2                          (0x01U) /* Count at PCLK/2 */
#define _02_TMR_PCLK_DIV_8                          (0x02U) /* Count at PCLK/8 */
#define _03_TMR_PCLK_DIV_32                         (0x03U) /* Count at PCLK/32 */
#define _04_TMR_PCLK_DIV_64                         (0x04U) /* Count at PCLK/64 */
#define _05_TMR_PCLK_DIV_1024                       (0x05U) /* Count at PCLK/1024 */
#define _06_TMR_PCLK_DIV_8192                       (0x06U) /* Count at PCLK/8192 */



void TimerStart(void);