/***********************************************************************/
/*                                                                     */
/*  FILE        :Sensing.h                     			       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Sensor Control		                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/




typedef enum
{
    ADCHANNEL0, ADCHANNEL1, ADCHANNEL2, ADCHANNEL3, ADCHANNEL4, ADCHANNEL5, ADCHANNEL6, ADCHANNEL7,
    ADCHANNEL8, ADCHANNEL9, ADCHANNEL10, ADCHANNEL11, ADCHANNEL16, ADSELFDIAGNOSIS, ADINTERREFVOLT, 
    ADDATADUPLICATION, ADDATADUPLICATIONA, ADDATADUPLICATIONB
} ad_channel_t;



void SensingJob(void);
void ADCStart(void);
void CalcADCValue(void);