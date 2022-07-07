/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_s12ad.h
* Version      : 1.0.103
* Device(s)    : R5F524TAAxFM
* Description  : General header file for S12AD peripheral.
* Creation Date: 2021-08-19
***********************************************************************************************************************/

#ifndef S12AD_H
#define S12AD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    A/D control register (ADCSR)
*/
/* Double Trigger Channel Select ( DBLANS) */
#define _0000_AD_DBCHANNEL_ANx00             (0x0000U) /* ANx00 is used for double trigger mode */
#define _0001_AD_DBCHANNEL_ANx01             (0x0001U) /* ANx01 is used for double trigger mode */
#define _0002_AD_DBCHANNEL_ANx02             (0x0002U) /* ANx02 is used for double trigger mode */
#define _0003_AD_DBCHANNEL_ANx03             (0x0003U) /* ANx03 is used for double trigger mode */
#define _0004_AD_DBCHANNEL_ANx04             (0x0004U) /* ANx04 is used for double trigger mode */
#define _0005_AD_DBCHANNEL_ANx05             (0x0005U) /* ANx05 is used for double trigger mode */
#define _0006_AD_DBCHANNEL_ANx06             (0x0006U) /* ANx06 is used for double trigger mode */
#define _0007_AD_DBCHANNEL_ANx07             (0x0007U) /* ANx07 is used for double trigger mode */
#define _0008_AD_DBCHANNEL_ANx08             (0x0008U) /* ANx08 is used for double trigger mode */
#define _0009_AD_DBCHANNEL_ANx09             (0x0009U) /* ANx09 is used for double trigger mode */
#define _000A_AD_DBCHANNEL_ANx10             (0x000AU) /* ANx10 is used for double trigger mode */
#define _000B_AD_DBCHANNEL_ANx11             (0x000BU) /* ANx11 is used for double trigger mode */
#define _0010_AD_DBCHANNEL_ANx16             (0x0010U) /* ANx16 is used for double trigger mode */
/* Group B Scan End Interrupt Enable (GBADIE) */
#define _0000_AD_GBADI_DISABLE               (0x0000U) /* Disables GBADI interrupt generation upon group B scan
                                                          completion */
#define _0040_AD_GBADI_ENABLE                (0x0040U) /* Enables GBADI interrupt generation upon group B scan
                                                          completion */
/* Double Trigger Mode Select (DBLE) */
#define _0000_AD_DBLTRIGGER_DISABLE          (0x0000U) /* Disable double trigger mode */
#define _0080_AD_DBLTRIGGER_ENABLE           (0x0080U) /* Enable double trigger mode */
/* Trigger Select (EXTRG) */
#define _0000_AD_SYNC_TRIGGER                (0x0000U) /* A/D conversion started by synchronous trigger */
#define _0100_AD_ASYNC_TRIGGER               (0x0100U) /* A/D conversion started by asynchronous trigger */
/* Trigger Start Enable (TRGE) */
#define _0000_AD_SYNCASYNCTRG_DISABLE        (0x0000U) /* A/D conversion synchronous or asynchronous trigger disable */
#define _0200_AD_SYNCASYNCTRG_ENABLE         (0x0200U) /* A/D conversion synchronous or asynchronous trigger enable */
/* Scan End Interrupt Enable (ADIE) */
#define _0000_AD_SCAN_END_INTERRUPT_DISABLE  (0x0000U) /* Disable S12ADI interrupt generation upon scan completion */
#define _1000_AD_SCAN_END_INTERRUPT_ENABLE   (0x1000U) /* Enable S12ADI interrupt generation upon scan completion */
/* Scan Mode Select (ADCS) */
#define _0000_AD_SINGLE_SCAN_MODE            (0x0000U) /* Single scan mode */
#define _2000_AD_GROUP_SCAN_MODE             (0x2000U) /* Group scan mode */
#define _4000_AD_CONTINUOUS_SCAN_MODE        (0x4000U) /* Continuous scan mode */
/* A/D Conversion Start (ADST) */
#define _0000_AD_CONVERSION_STOP             (0x0000U) /* Stop A/D conversion */
#define _8000_AD_CONVERSION_START            (0x8000U) /* Start A/D conversion */

/*
    A/D Channel Select Register A0 (ADANSA0)
*/
#define _0001_AD_ANx00_USED                  (0x0001U) /* ANx00 is subjected to conversion */
#define _0001_AD_ANx00_GROUPA_USED           (0x0001U) /* ANx00 is subjected to group A conversion */
#define _0002_AD_ANx01_USED                  (0x0002U) /* ANx01 is subjected to conversion */
#define _0002_AD_ANx01_GROUPA_USED           (0x0002U) /* ANx01 is subjected to group A conversion */
#define _0004_AD_ANx02_USED                  (0x0004U) /* ANx02 is subjected to conversion */
#define _0004_AD_ANx02_GROUPA_USED           (0x0004U) /* ANx02 is subjected to group A conversion */
#define _0008_AD_ANx03_USED                  (0x0008U) /* ANx03 is subjected to conversion */
#define _0008_AD_ANx03_GROUPA_USED           (0x0008U) /* ANx03 is subjected to group A conversion */
#define _0010_AD_ANx04_USED                  (0x0010U) /* ANx04 is subjected to conversion */
#define _0010_AD_ANx04_GROUPA_USED           (0x0010U) /* ANx04 is subjected to group A conversion */
#define _0020_AD_ANx05_USED                  (0x0020U) /* ANx05 is subjected to conversion */
#define _0020_AD_ANx05_GROUPA_USED           (0x0020U) /* ANx05 is subjected to group A conversion */
#define _0040_AD_ANx06_USED                  (0x0040U) /* ANx06 is subjected to conversion */
#define _0040_AD_ANx06_GROUPA_USED           (0x0040U) /* ANx06 is subjected to group A conversion */
#define _0080_AD_ANx07_USED                  (0x0080U) /* ANx07 is subjected to conversion */
#define _0080_AD_ANx07_GROUPA_USED           (0x0080U) /* ANx07 is subjected to group A conversion */
#define _0100_AD_ANx08_USED                  (0x0100U) /* ANx08 is subjected to conversion */
#define _0100_AD_ANx08_GROUPA_USED           (0x0100U) /* ANx08 is subjected to group A conversion */
#define _0200_AD_ANx09_USED                  (0x0200U) /* ANx09 is subjected to conversion */
#define _0200_AD_ANx09_GROUPA_USED           (0x0200U) /* ANx09 is subjected to group A conversion */
#define _0400_AD_ANx10_USED                  (0x0400U) /* ANx10 is subjected to conversion */
#define _0400_AD_ANx10_GROUPA_USED           (0x0400U) /* ANx10 is subjected to group A conversion */
#define _0800_AD_ANx11_USED                  (0x0800U) /* ANx11 is subjected to conversion */
#define _0800_AD_ANx11_GROUPA_USED           (0x0800U) /* ANx11 is subjected to group A conversion */

/*
    A/D Channel Select Register A1 (ADANSA1)
*/
#define _0001_AD_ANx16_USED                  (0x0001U) /* ANx16 is subjected to conversion */
#define _0001_AD_ANx16_GROUPA_USED           (0x0001U) /* ANx16 is subjected to group A conversion */

/*
    A/D Channel Select Register B0 (ADANSB0)
*/
#define _0001_AD_ANx00_GROUPB_USED           (0x0001U) /* ANx00 is subjected to group B conversion */
#define _0002_AD_ANx01_GROUPB_USED           (0x0002U) /* ANx01 is subjected to group B conversion */
#define _0004_AD_ANx02_GROUPB_USED           (0x0004U) /* ANx02 is subjected to group B conversion */
#define _0008_AD_ANx03_GROUPB_USED           (0x0008U) /* ANx03 is subjected to group B conversion */
#define _0010_AD_ANx04_GROUPB_USED           (0x0010U) /* ANx04 is subjected to group B conversion */
#define _0020_AD_ANx05_GROUPB_USED           (0x0020U) /* ANx05 is subjected to group B conversion */
#define _0040_AD_ANx06_GROUPB_USED           (0x0040U) /* ANx06 is subjected to group B conversion */
#define _0080_AD_ANx07_GROUPB_USED           (0x0080U) /* ANx07 is subjected to group B conversion */
#define _0100_AD_ANx08_GROUPB_USED           (0x0100U) /* ANx08 is subjected to group B conversion */
#define _0200_AD_ANx09_GROUPB_USED           (0x0200U) /* ANx09 is subjected to group B conversion */
#define _0400_AD_ANx10_GROUPB_USED           (0x0400U) /* ANx10 is subjected to group B conversion */
#define _0800_AD_ANx11_GROUPB_USED           (0x0800U) /* ANx11 is subjected to group B conversion */

/*
    A/D Channel Select Register B1 (ADANSB1)
*/
#define _0001_AD_ANx16_GROUPB_USED           (0x0001U) /* ANx16 is subjected to group B conversion */

/*
    A/D Channel Select Register C0 (ADANSC0)
*/
#define _0001_AD_ANx00_GROUPC_USED           (0x0001U) /* ANx00 is subjected to group C conversion */
#define _0002_AD_ANx01_GROUPC_USED           (0x0002U) /* ANx01 is subjected to group C conversion */
#define _0004_AD_ANx02_GROUPC_USED           (0x0004U) /* ANx02 is subjected to group C conversion */
#define _0008_AD_ANx03_GROUPC_USED           (0x0008U) /* ANx03 is subjected to group C conversion */
#define _0010_AD_ANx04_GROUPC_USED           (0x0010U) /* ANx04 is subjected to group C conversion */
#define _0020_AD_ANx05_GROUPC_USED           (0x0020U) /* ANx05 is subjected to group C conversion */
#define _0040_AD_ANx06_GROUPC_USED           (0x0040U) /* ANx06 is subjected to group C conversion */
#define _0080_AD_ANx07_GROUPC_USED           (0x0080U) /* ANx07 is subjected to group C conversion */
#define _0100_AD_ANx08_GROUPC_USED           (0x0100U) /* ANx08 is subjected to group C conversion */
#define _0200_AD_ANx09_GROUPC_USED           (0x0200U) /* ANx09 is subjected to group C conversion */
#define _0400_AD_ANx10_GROUPC_USED           (0x0400U) /* ANx10 is subjected to group C conversion */
#define _0800_AD_ANx11_GROUPC_USED           (0x0800U) /* ANx11 is subjected to group C conversion */

/*
    A/D Channel Select Register C1 (ADANSC1)
*/
#define _0001_AD_ANx16_GROUPC_USED           (0x0001U) /* ANx16 is subjected to group C conversion */

/*
    A/D-Converted Value Addition/Average Mode Select Register 0 (ADADS0)
*/
#define _0001_AD_ANx00_ADD_USED              (0x0001U) /* ANx00 is selected to addition/average mode */
#define _0002_AD_ANx01_ADD_USED              (0x0002U) /* ANx01 is selected to addition/average mode */
#define _0004_AD_ANx02_ADD_USED              (0x0004U) /* ANx02 is selected to addition/average mode */
#define _0008_AD_ANx03_ADD_USED              (0x0008U) /* ANx03 is selected to addition/average mode */
#define _0010_AD_ANx04_ADD_USED              (0x0010U) /* ANx04 is selected to addition/average mode */
#define _0020_AD_ANx05_ADD_USED              (0x0020U) /* ANx05 is selected to addition/average mode */
#define _0040_AD_ANx06_ADD_USED              (0x0040U) /* ANx06 is selected to addition/average mode */
#define _0080_AD_ANx07_ADD_USED              (0x0080U) /* ANx07 is selected to addition/average mode */
#define _0100_AD_ANx08_ADD_USED              (0x0100U) /* ANx08 is selected to addition/average mode */
#define _0200_AD_ANx09_ADD_USED              (0x0200U) /* ANx09 is selected to addition/average mode */
#define _0400_AD_ANx10_ADD_USED              (0x0400U) /* ANx10 is selected to addition/average mode */
#define _0800_AD_ANx11_ADD_USED              (0x0800U) /* ANx11 is selected to addition/average mode */

/*
    A/D-Converted Value Addition/Average Mode Select Register 1 (ADADS1)
*/
#define _0001_AD_ANx16_ADD_USED              (0x0001U) /* ANx16 is selected to addition/average mode */

/*
    A/D-Converted Value Addition/Average Count Select Register (ADADC)
*/
/* Addition Count Select (ADC) */
#define _00_AD_1_TIME_CONVERSION             (0x00U) /* 1-time conversion */
#define _01_AD_2_TIME_CONVERSION             (0x01U) /* 2-time conversion */
#define _02_AD_3_TIME_CONVERSION             (0x02U) /* 3-time conversion */
#define _03_AD_4_TIME_CONVERSION             (0x03U) /* 4-time conversion */
#define _05_AD_16_TIME_CONVERSION            (0x05U) /* 16-time conversion */
/* Average Mode Enable (AVEE) */
#define _00_AD_ADDITION_MODE                 (0x00U) /* Addition mode */
#define _80_AD_AVERAGE_MODE                  (0x80U) /* Average mode */

/*
    A/D Control Extended Register (ADCER)
*/
/* A/D Data Register Automatic Clearing Enable (ACE) */
#define _0000_AD_AUTO_CLEARING_DISABLE       (0x0000U) /* Disable auto clearing */
#define _0020_AD_AUTO_CLEARING_ENABLE        (0x0020U) /* Enable auto clearing */
/* Self-Diagnosis Conversion Voltage Select (DIAGVAL) */
#define _0100_AD_SELFTDIAGST_0V              (0x0100U) /* Self-diagnosis using a voltage of 0V */
#define _0200_AD_SELFTDIAGST_VREF_HALF       (0x0200U) /* Self-diagnosis using a voltage of VREF_1/2 */
#define _0300_AD_SELFTDIAGST_VREF            (0x0300U) /* Self-diagnosis using a voltage of VREF_1 */
/* Self-Diagnosis Mode Select (DIAGLD) */
#define _0000_AD_SELFTDIAGST_ROTATION        (0x0000U) /* Rotation mode for self-diagnosis voltage */
#define _0400_AD_SELFTDIAGST_FIX             (0x0400U) /* Fixed mode for self-diagnosis voltage */
/* Self-Diagnosis Enable (DIAGM) */
#define _0000_AD_SELFTDIAGST_DISABLE         (0x0000U) /* 12-bit A/D converter self-diagnosis disable */
#define _0800_AD_SELFTDIAGST_ENABLE          (0x0800U) /* 12-bit A/D converter self-diagnosis enable */
/* A/D Data Register Format Select (ADRFMT) */
#define _0000_AD_RIGHT_ALIGNMENT             (0x0000U) /* Right-alignment for data register format */
#define _8000_AD_LEFT_ALIGNMENT              (0x8000U) /* Left-alignment for data register format */

/*
    A/D Conversion Start Trigger Select Register (ADSTRGR)
*/
/* A/D Conversion Start Trigger Select for Group B (TRSB) */
#define _0001_AD_TRSB_TRGA0N                 (0x0001U) /* Compare match with or input capture to MTU0.TGRA */
#define _0002_AD_TRSB_TRGA1N                 (0x0002U) /* Compare match with or input capture to MTU1.TGRA */
#define _0003_AD_TRSB_TRGA2N                 (0x0003U) /* Compare match with or input capture to MTU2.TGRA */
#define _0004_AD_TRSB_TRGA3N                 (0x0004U) /* Compare match with or input capture to MTU3.TGRA */
#define _0005_AD_TRSB_TRGA4N                 (0x0005U) /* Compare match with or input capture to MTU4.TGRA or,
                                                          an underflow of MTU4.TCNT (in the trough) */
#define _0006_AD_TRSB_TRGA6N                 (0x0006U) /* Compare match with or input capture to MTU6.TGRA */
#define _0007_AD_TRSB_TRGA7N                 (0x0007U) /* Compare match with or input capture to MTU7.TGRA or, 
                                                          an underflow of MTU7.TCNT (in the trough) */
#define _0008_AD_TRSB_TRG0N                  (0x0008U) /* Compare match with MTU0.TGRE */
#define _0009_AD_TRSB_TRG4AN                 (0x0009U) /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _000A_AD_TRSB_TRG4BN                 (0x000AU) /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _000B_AD_TRSB_TRG4AN_TRG4BN          (0x000BU) /* Compare match between TADCORA and TCNT,
                                                          or between TADCORB and TCNT in MTU4 */
#define _000C_AD_TRSB_TRG4ABN                (0x000CU) /* Compare match between TADCORA and TCNT, 
                                                          and between TADCORB and TCNT in MTU4 (interrupt skipping 2 used) */
#define _000D_AD_TRSB_TRG7AN                 (0x000DU) /* Compare match between MTU7.TADCORA and MTU7.TCNT */
#define _000E_AD_TRSB_TRG7BN                 (0x000EU) /* Compare match between MTU7.TADCORB and MTU7.TCNT */
#define _000F_AD_TRSB_TRG7AN_TRG7BN          (0x000FU) /* Compare match between TADCORA and TCNT, 
                                                          or between TADCORB and TCNT in MTU7 */
#define _0010_AD_TRSB_TRG7ABN                (0x0010U) /* Compare match between TADCORA and TCNT, 
                                                          and between TADCORB and TCNT in MTU7 (interrupt skipping 2 used) */
#define _0013_AD_TRSB_TRGA9N                 (0x0013U) /* Compare match with or input capture to MTU9.TGRA */
#define _0014_AD_TRSB_TRG9N                  (0x0014U) /* Compare match with MTU9.TGRE */
#define _0019_AD_TRSB_TRGA0N_TRG0N           (0x0019U) /* Compare match with or input capture to MTU0.TGRA,
                                                          or compare match with MTU0.TGRE */
#define _001A_AD_TRSB_TRGA9N_TRG9N           (0x001AU) /* Compare match with or input capture to MTU9.TGRA,
                                                          or compare match with MTU9.TGRE */
#define _001B_AD_TRSB_TRGA0N_TRGA9N          (0x001BU) /* Compare match with or input capture to MTU0.TGRA 
                                                          or MTU9.TGRA */
#define _001C_AD_TRSB_TRG0N_TRG9N            (0x001CU) /* Compare match with MTU0.TGRE or MTU9.TGRE */
#define _001D_AD_TRSB_TMTRG0AN_0             (0x001DU) /* Compare match between TMR0.TCORA and TMR0.TCNT */
#define _001E_AD_TRSB_TMTRG0AN_1             (0x001EU) /* Compare match between TMR2.TCORA and TMR2.TCNT */
#define _001F_AD_TRSB_TMTRG0AN_2             (0x001FU) /* Compare match between TMR4.TCORA and TMR4.TCNT */
#define _0020_AD_TRSB_TMTRG0AN_3             (0x0020U) /* Compare match between TMR6.TCORA and TMR6.TCNT */
#define _0021_AD_TRSB_TRG9AEN                (0x0021U) /* Compare match with or input capture to MTU9.TGRA, 
                                                          and compare match with MTU9.TGRE */
#define _0022_AD_TRSB_TRG0AEN                (0x0022U) /* Compare match with or input capture to MTU0.TGRA, 
                                                          and compare match with MTU0.TGRE */
#define _0023_AD_TRSB_TRGA09N                (0x0023U) /* Compare match with or input capture to MTU0.TGRA, 
                                                          and MTU9.TGRA */
#define _0024_AD_TRSB_TRG09N                 (0x0024U) /* Compare match with MTU0.TGRE, and MTU9.TRGE */
#define _0032_AD_TRSB_GTADTRA0N              (0x0032U) /* Compare match with GPT0.GTADTRA */
#define _0033_AD_TRSB_GTADTRB0N              (0x0033U) /* Compare match with GPT0.GTADTRB */
#define _0034_AD_TRSB_GTADTRA1N              (0x0034U) /* Compare match with GPT1.GTADTRA */
#define _0035_AD_TRSB_GTADTRB1N              (0x0035U) /* Compare match with GPT1.GTADTRB */
#define _0036_AD_TRSB_GTADTRA2N              (0x0036U) /* Compare match with GPT2.GTADTRA */
#define _0037_AD_TRSB_GTADTRB2N              (0x0037U) /* Compare match with GPT2.GTADTRB */
#define _0038_AD_TRSB_GTADTRA3N              (0x0038U) /* Compare match with GPT3.GTADTRA */
#define _0039_AD_TRSB_GTADTRB3N              (0x0039U) /* Compare match with GPT3.GTADTRB */
#define _003A_AD_TRSB_GTADTRA0N_GTADTRB0N    (0x003AU) /* Compare match with GPT0.GTADTRA or with GPT0.GTADTRB */
#define _003B_AD_TRSB_GTADTRA1N_GTADTRB1N    (0x003BU) /* Compare match with GPT1.GTADTRA or with GPT1.GTADTRB */
#define _003C_AD_TRSB_GTADTRA2N_GTADTRB2N    (0x003CU) /* Compare match with GPT2.GTADTRA or with GPT2.GTADTRB */
#define _003D_AD_TRSB_GTADTRA3N_GTADTRB3N    (0x003DU) /* Compare match with GPT3.GTADTRA or with GPT3.GTADTRB */
/* A/D Conversion Start Trigger Select (TRSA) */
#define _0000_AD_TRSA_ADTRG                  (0x0000U) /* Input pin for the trigger */
#define _0100_AD_TRSA_TRGA0N                 (0x0100U) /* Compare match with or input capture to MTU0.TGRA */
#define _0200_AD_TRSA_TRGA1N                 (0x0200U) /* Compare match with or input capture to MTU1.TGRA */
#define _0300_AD_TRSA_TRGA2N                 (0x0300U) /* Compare match with or input capture to MTU2.TGRA */
#define _0400_AD_TRSA_TRGA3N                 (0x0400U) /* Compare match with or input capture to MTU3.TGRA */
#define _0500_AD_TRSA_TRGA4N                 (0x0500U) /* Compare match with or input capture to MTU4.TGRA or,
                                                          an underflow of MTU4.TCNT (in the trough) */
#define _0600_AD_TRSA_TRGA6N                 (0x0600U) /* Compare match with or input capture to MTU6.TGRA */
#define _0700_AD_TRSA_TRGA7N                 (0x0700U) /* Compare match with or input capture to MTU7.TGRA or, 
                                                          an underflow of MTU7.TCNT (in the trough) */
#define _0800_AD_TRSA_TRG0N                  (0x0800U) /* Compare match with MTU0.TGRE */
#define _0900_AD_TRSA_TRG4AN                 (0x0900U) /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _0A00_AD_TRSA_TRG4BN                 (0x0A00U) /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _0B00_AD_TRSA_TRG4AN_TRG4BN          (0x0B00U) /* Compare match between TADCORA and TCNT, 
                                                          or between TADCORB and TCNT in MTU4 */
#define _0C00_AD_TRSA_TRG4ABN                (0x0C00U) /* Compare match between TADCORA and TCNT, 
                                                          and between TADCORB and TCNT in MTU4 (interrupt skipping 2 used) */
#define _0D00_AD_TRSA_TRG7AN                 (0x0D00U) /* Compare match between MTU7.TADCORA and MTU7.TCNT */
#define _0E00_AD_TRSA_TRG7BN                 (0x0E00U) /* Compare match between MTU7.TADCORB and MTU7.TCNT */
#define _0F00_AD_TRSA_TRG7AN_TRG7BN          (0x0F00U) /* Compare match between TADCORA and TCNT, 
                                                          or between TADCORB and TCNT in MTU7 */
#define _1000_AD_TRSA_TRG7ABN                (0x1000U) /* Compare match between TADCORA and TCNT, 
                                                          and between TADCORB and TCNT in MTU7 (interrupt skipping 2 used) */
#define _1300_AD_TRSA_TRGA9N                 (0x1300U) /* Compare match with or input capture to MTU9.TGRA */
#define _1400_AD_TRSA_TRG9N                  (0x1400U) /* Compare match with MTU9.TGRE */
#define _1900_AD_TRSA_TRGA0N_TRG0N           (0x1900U) /* Compare match with or input capture to MTU0.TGRA,
                                                          or compare match with MTU0.TGRE */
#define _1A00_AD_TRSA_TRGA9N_TRG9N           (0x1A00U) /* Compare match with or input capture to MTU9.TGRA,
                                                          or compare match with MTU9.TGRE */
#define _1B00_AD_TRSA_TRGA0N_TRGA9N          (0x1B00U) /* Compare match with or input capture to MTU0.TGRA 
                                                          or MTU9.TGRA */
#define _1C00_AD_TRSA_TRG0N_TRG9N            (0x1C00U) /* Compare match with MTU0.TGRE or MTU9.TGRE */
#define _1D00_AD_TRSA_TMTRG0AN_0             (0x1D00U) /* Compare match between TMR0.TCORA and TMR0.TCNT */
#define _1E00_AD_TRSA_TMTRG0AN_1             (0x1E00U) /* Compare match between TMR2.TCORA and TMR2.TCNT */
#define _1F00_AD_TRSA_TMTRG0AN_2             (0x1F00U) /* Compare match between TMR4.TCORA and TMR4.TCNT */
#define _2000_AD_TRSA_TMTRG0AN_3             (0x2000U) /* Compare match between TMR6.TCORA and TMR6.TCNT */
#define _2100_AD_TRSA_TRG9AEN                (0x2100U) /* Compare match with or input capture to MTU9.TGRA, 
                                                          and compare match with MTU9.TGRE */
#define _2200_AD_TRSA_TRG0AEN                (0x2200U) /* Compare match with or input capture to MTU0.TGRA, 
                                                          and compare match with MTU0.TGRE */
#define _2300_AD_TRSA_TRGA09N                (0x2300U) /* Compare match with or input capture to MTU0.TGRA, 
                                                          and MTU9.TGRA */
#define _2400_AD_TRSA_TRG09N                 (0x2400U) /* Compare match with MTU0.TGRE, and MTU9.TRGE */
#define _3200_AD_TRSA_GTADTRA0N              (0x3200U) /* Compare match with GPT0.GTADTRA */
#define _3300_AD_TRSA_GTADTRB0N              (0x3300U) /* Compare match with GPT0.GTADTRB */
#define _3400_AD_TRSA_GTADTRA1N              (0x3400U) /* Compare match with GPT1.GTADTRA */
#define _3500_AD_TRSA_GTADTRB1N              (0x3500U) /* Compare match with GPT1.GTADTRB */
#define _3600_AD_TRSA_GTADTRA2N              (0x3600U) /* Compare match with GPT2.GTADTRA */
#define _3700_AD_TRSA_GTADTRB2N              (0x3700U) /* Compare match with GPT2.GTADTRB */
#define _3800_AD_TRSA_GTADTRA3N              (0x3800U) /* Compare match with GPT3.GTADTRA */
#define _3900_AD_TRSA_GTADTRB3N              (0x3900U) /* Compare match with GPT3.GTADTRB */
#define _3A00_AD_TRSA_GTADTRA0N_GTADTRB0N    (0x3A00U) /* Compare match with GPT0.GTADTRA or with GPT0.GTADTRB */
#define _3B00_AD_TRSA_GTADTRA1N_GTADTRB1N    (0x3B00U) /* Compare match with GPT1.GTADTRA or with GPT1.GTADTRB */
#define _3C00_AD_TRSA_GTADTRA2N_GTADTRB2N    (0x3C00U) /* Compare match with GPT2.GTADTRA or with GPT2.GTADTRB */
#define _3D00_AD_TRSA_GTADTRA3N_GTADTRB3N    (0x3D00U) /* Compare match with GPT3.GTADTRA or with GPT3.GTADTRB */

/*
    A/D Conversion Extended Input Control Register (ADEXICR)
*/
/* Internal Reference Voltage A/D Converted Value Addition/Average Mode Select (OCSAD) */
#define _0000_AD_IREF_ADD_UNUSED             (0x0000U) /* Internal ref. voltage A/D converted value addition/average
                                                          mode disabled */
#define _0002_AD_IREF_ADD_USED               (0x0002U) /* Internal ref. voltage A/D converted value addition/average
                                                          mode enabled */
/* Internal Reference Voltage A/D Conversion Select (OCSA) */
#define _0000_AD_IREF_UNUSED                 (0x0000U) /* A/D conversion of internal reference voltage is disabled */
#define _0200_AD_IREF_USED                   (0x0200U) /* A/D conversion of internal reference voltage is enabled */
#define _0200_AD_IREF_GROUPA_USED            (0x0200U) /* A/D conversion of internal reference voltage is enabled in
                                                          group A  */

/*
    A/D Group C Trigger Select Register (ADGCTRGR)
*/
/* Group C A/D Conversion Start Trigger Select (TRSC) */
#define _01_AD_TRSC_TRGA0N                   (0x01U)   /* Compare match with or input capture to MTU0.TGRA */
#define _02_AD_TRSC_TRGA1N                   (0x02U)   /* Compare match with or input capture to MTU1.TGRA */
#define _03_AD_TRSC_TRGA2N                   (0x03U)   /* Compare match with or input capture to MTU2.TGRA */
#define _04_AD_TRSC_TRGA3N                   (0x04U)   /* Compare match with or input capture to MTU3.TGRA */
#define _05_AD_TRSC_TRGA4N                   (0x05U)   /* Compare match with or input capture to MTU4.TGRA or,
                                                          an underflow of MTU4.TCNT (in the trough) */
#define _06_AD_TRSC_TRGA6N                   (0x06U)   /* Compare match with or input capture to MTU6.TGRA */
#define _07_AD_TRSC_TRGA7N                   (0x07U)   /* Compare match with or input capture to MTU7.TGRA or, 
                                                          an underflow of MTU7.TCNT (in the trough) */
#define _08_AD_TRSC_TRG0N                    (0x08U)   /* Compare match with MTU0.TGRE */
#define _09_AD_TRSC_TRG4AN                   (0x09U)   /* Compare match between MTU4.TADCORA and MTU4.TCNT */
#define _0A_AD_TRSC_TRG4BN                   (0x0AU)   /* Compare match between MTU4.TADCORB and MTU4.TCNT */
#define _0B_AD_TRSC_TRG4AN_TRG4BN            (0x0BU)   /* Compare match between TADCORA and TCNT, 
                                                          or between TADCORB and TCNT in MTU4 */
#define _0C_AD_TRSC_TRG4ABN                  (0x0CU)   /* Compare match between TADCORA and TCNT, 
                                                          and between TADCORB and TCNT in MTU4 (interrupt skipping 2 used) */
#define _0D_AD_TRSC_TRG7AN                   (0x0DU)   /* Compare match between MTU7.TADCORA and MTU7.TCNT */
#define _0E_AD_TRSC_TRG7BN                   (0x0EU)   /* Compare match between MTU7.TADCORB and MTU7.TCNT */
#define _0F_AD_TRSC_TRG7AN_TRG7BN            (0x0FU)   /* Compare match between TADCORA and TCNT, 
                                                          or between TADCORB and TCNT in MTU7 */
#define _10_AD_TRSC_TRG7ABN                  (0x10U)   /* Compare match between TADCORA and TCNT, 
                                                          and between TADCORB and TCNT in MTU7 (interrupt skipping 2 used) */
#define _13_AD_TRSC_TRGA9N                   (0x13U)   /* Compare match with or input capture to MTU9.TGRA */
#define _14_AD_TRSC_TRG9N                    (0x14U)   /* Compare match with MTU9.TGRE */
#define _19_AD_TRSC_TRGA0N_TRG0N             (0x19U)   /* Compare match with or input capture to MTU0.TGRA,
                                                          or compare match with MTU0.TGRE */
#define _1A_AD_TRSC_TRGA9N_TRG9N             (0x1AU)   /* Compare match with or input capture to MTU9.TGRA,
                                                          or compare match with MTU9.TGRE */
#define _1B_AD_TRSC_TRGA0N_TRGA9N            (0x1BU)   /* Compare match with or input capture to MTU0.TGRA 
                                                          or MTU9.TGRA */
#define _1C_AD_TRSC_TRG0N_TRG9N              (0x1CU)   /* Compare match with MTU0.TGRE or MTU9.TGRE */
#define _1D_AD_TRSC_TMTRG0AN_0               (0x1DU)   /* Compare match between TMR0.TCORA and TMR0.TCNT */
#define _1E_AD_TRSC_TMTRG0AN_1               (0x1EU)   /* Compare match between TMR2.TCORA and TMR2.TCNT */
#define _1F_AD_TRSC_TMTRG0AN_2               (0x1FU)   /* Compare match between TMR4.TCORA and TMR4.TCNT */
#define _20_AD_TRSC_TMTRG0AN_3               (0x20U)   /* Compare match between TMR6.TCORA and TMR6.TCNT */
#define _21_AD_TRSC_TRG9AEN                  (0x21U)   /* Compare match with or input capture to MTU9.TGRA,
                                                          and compare match with MTU9.TGRE */
#define _22_AD_TRSC_TRG0AEN                  (0x22U)   /* Compare match with or input capture to MTU0.TGRA, 
                                                          and compare match with MTU0.TGRE */
#define _23_AD_TRSC_TRGA09N                  (0x23U)   /* Compare match with or input capture to MTU0.TGRA, 
                                                          and MTU9.TGRA */
#define _24_AD_TRSC_TRG09N                   (0x24U)   /* Compare match with MTU0.TGRE, and MTU9.TRGE */
#define _32_AD_TRSC_GTADTRA0N                (0x32U)   /* Compare match with GPT0.GTADTRA */
#define _33_AD_TRSC_GTADTRB0N                (0x33U)   /* Compare match with GPT0.GTADTRB */
#define _34_AD_TRSC_GTADTRA1N                (0x34U)   /* Compare match with GPT1.GTADTRA */
#define _35_AD_TRSC_GTADTRB1N                (0x35U)   /* Compare match with GPT1.GTADTRB */
#define _36_AD_TRSC_GTADTRA2N                (0x36U)   /* Compare match with GPT2.GTADTRA */
#define _37_AD_TRSC_GTADTRB2N                (0x37U)   /* Compare match with GPT2.GTADTRB */
#define _38_AD_TRSC_GTADTRA3N                (0x38U)   /* Compare match with GPT3.GTADTRA */
#define _39_AD_TRSC_GTADTRB3N                (0x39U)   /* Compare match with GPT3.GTADTRB */
#define _3A_AD_TRSC_GTADTRA0N_GTADTRB0N      (0x3AU)   /* Compare match with GPT0.GTADTRA or with GPT0.GTADTRB */
#define _3B_AD_TRSC_GTADTRA1N_GTADTRB1N      (0x3BU)   /* Compare match with GPT1.GTADTRA or with GPT1.GTADTRB */
#define _3C_AD_TRSC_GTADTRA2N_GTADTRB2N      (0x3CU)   /* Compare match with GPT2.GTADTRA or with GPT2.GTADTRB */
#define _3D_AD_TRSC_GTADTRA3N_GTADTRB3N      (0x3DU)   /* Compare match with GPT3.GTADTRA or with GPT3.GTADTRB */
/* Group C Scan End Interrupt Enable (GCADIE) */
#define _00_AD_GCADI_DISABLE                 (0x00U)   /* Group C scan end interrupt is disabled */
#define _40_AD_GCADI_ENABLE                  (0x40U)   /* Group C scan end interrupt is enabled */
/* Group C A/D Conversion Operation Enable (GRCE) */
#define _00_AD_GROUPC_DISABLE                (0x00U)   /* A/D conversion operation for group C is disabled */
#define _80_AD_GROUPC_ENABLE                 (0x80U)   /* A/D conversion operation for group C is enabled */

/*
    A/D Sample-and-Hold Circuit Control Register (ADSHCR)
*/
/*  Channel-Dedicated Sample-and-Hold Circuit Bypass Select (SHANS) */
#define _0100_AD_DSH_ANx00_SELECT            (0x0100U) /* ANx00 use the channel-dedicated sample-and-hold circuits */
#define _0200_AD_DSH_ANx01_SELECT            (0x0200U) /* ANx01 use the channel-dedicated sample-and-hold circuits */
#define _0400_AD_DSH_ANx02_SELECT            (0x0400U) /* ANx02 use the channel-dedicated sample-and-hold circuits */

/*
    A/D Disconnection Detection Control Register (ADDISCR)
*/
#define _00_AD_DISCONECT_UNUSED              (0x00U) /* Detection detection control unused */
#define _00_AD_DISCONECT_DISCHARGE           (0x00U) /* Detection detection control discharge */
#define _10_AD_DISCONECT_PRECHARGE           (0x10U) /* Detection detection control precharge */
#define _02_AD_DISCONECT_2ADCLK              (0x02U) /* 2 ADCLK of detection detection control precharge/discharge */
#define _03_AD_DISCONECT_3ADCLK              (0x03U) /* 3 ADCLK of detection detection control precharge/discharge */
#define _04_AD_DISCONECT_4ADCLK              (0x04U) /* 4 ADCLK of detection detection control precharge/discharge */
#define _05_AD_DISCONECT_5ADCLK              (0x05U) /* 5 ADCLK of detection detection control precharge/discharge */
#define _06_AD_DISCONECT_6ADCLK              (0x06U) /* 6 ADCLK of detection detection control precharge/discharge */
#define _07_AD_DISCONECT_7ADCLK              (0x07U) /* 7 ADCLK of detection detection control precharge/discharge */
#define _08_AD_DISCONECT_8ADCLK              (0x08U) /* 8 ADCLK of detection detection control precharge/discharge */
#define _09_AD_DISCONECT_9ADCLK              (0x09U) /* 9 ADCLK of detection detection control precharge/discharge */
#define _0A_AD_DISCONECT_10ADCLK             (0x0AU) /* 10 ADCLK of detection detection control precharge/discharge */
#define _0B_AD_DISCONECT_11ADCLK             (0x0BU) /* 11 ADCLK of detection detection control precharge/discharge */
#define _0C_AD_DISCONECT_12ADCLK             (0x0CU) /* 12 ADCLK of detection detection control precharge/discharge */
#define _0D_AD_DISCONECT_13ADCLK             (0x0DU) /* 13 ADCLK of detection detection control precharge/discharge */
#define _0E_AD_DISCONECT_14ADCLK             (0x0EU) /* 14 ADCLK of detection detection control precharge/discharge */
#define _0F_AD_DISCONECT_15ADCLK             (0x0FU) /* 15 ADCLK of detection detection control precharge/discharge */

/*
    A/D Group Scan Priority Control Register (ADGSPCR)
*/
/* Group Priority Control Setting (PGS) */
#define _0000_AD_GPAPRIORITY_DISABLE         (0x0000U) /* Operation is without group A priority control */
#define _0001_AD_GPAPRIORITY_ENABLE          (0x0001U) /* Operation is with group A priority control */
/* Low-Priority Group Restart Setting (GBRSCN) */
#define _0000_AD_GPBRESTART_DISABLE          (0x0000U) /* Group B not restart after discontinued due to Group A
                                                          priority */
#define _0002_AD_GPBRESTART_ENABLE           (0x0002U) /* Group B restart after discontinued due to Group A priority */
/* Restart Channel Select (LGRRS) */
#define _0000_AD_RESTART_START_CHAN          (0x0000U) /* Scanning is restarted from the scan start channel */
#define _4000_AD_RESTART_INCOMPLETE          (0x4000U) /* Scanning is restarted from the channel on which A/D
                                                          conversion is not completed */
/* Single Scan Continuous Start (GBRP) */
#define _0000_AD_GPBSCSCS_DISABLE            (0x0000U) /* Single cycle scan for group B not continuously activated */
#define _8000_AD_GPBSCSCS_ENABLE             (0x8000U) /* Single cycle scan for group B is continuously activated */

/*
    A/D Programmable Gain Amplifier Control Register (ADPGACR)
*/
/* PGA Px00 Amplifier Pass-Through Enable (Px00SEL1) */
#define _0000_AD_PASS_THROUGH_Px00_DISABLE   (0x0000U) /* Pass through the amplifier in Px00 disable */
#define _0002_AD_PASS_THROUGH_Px00_ENABLE    (0x0002U) /* Pass through the amplifier in Px00 enable */
/* PGA Px00 Amplifier Enable (Px00ENAMP) */
#define _0000_AD_AMPLI_Px00_DISABLE          (0x0000U) /* The Amplifier in Px00 disable */
#define _0004_AD_AMPLI_Px00_ENABLE           (0x0004U) /* The Amplifier in Px00 enable */
/* PGA Px01 Amplifier Pass-Through Enable (Px01SEL1) */
#define _0000_AD_PASS_THROUGH_Px01_DISABLE   (0x0000U) /* Pass through the amplifier in Px01 disable */
#define _0020_AD_PASS_THROUGH_Px01_ENABLE    (0x0020U) /* Pass through the amplifier in Px01 enable */
/* PGA Px01 Amplifier Enable (Px01ENAMP) */
#define _0000_AD_AMPLI_Px01_DISABLE          (0x0000U) /* The Amplifier in Px01 disable */
#define _0040_AD_AMPLI_Px01_ENABLE           (0x0040U) /* The Amplifier in Px01 enable */
/* PGA Px02 Amplifier Pass-Through Enable (Px02SEL1) */
#define _0000_AD_PASS_THROUGH_Px02_DISABLE   (0x0000U) /* Pass through the amplifier in Px02 disable */
#define _0200_AD_PASS_THROUGH_Px02_ENABLE    (0x0200U) /* Pass through the amplifier in Px02 enable */
/* PGA Px02 Amplifier Enable (Px02ENAMP) */
#define _0000_AD_AMPLI_Px02_DISABLE          (0x0000U) /* The Amplifier in Px02 disable */
#define _0400_AD_AMPLI_Px02_ENABLE           (0x0400U) /* The Amplifier in Px02 enable */
#define _9999_AD_ADPGACR_DEFAULT             (0x9999U) /* Write default value of ADPGACR */

/*
    A/D Programmable Gain Amplifier Gain Setting Register 0 (ADPGAGS0)
*/
/* PGA Px00/Px01/Px02 Gain Setting */
#define _0000_AD_GAIN_2_000                  (0x0000U) /* x 2.000 */
#define _0001_AD_GAIN_2_500                  (0x0001U) /* x 2.500 */
#define _0004_AD_GAIN_3_077                  (0x0004U) /* x 3.077 */
#define _0006_AD_GAIN_3_636                  (0x0006U) /* x 3.636 */
#define _0007_AD_GAIN_4_000                  (0x0007U) /* x 4.000 */
#define _0008_AD_GAIN_4_444                  (0x0008U) /* x 4.444 */

/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _00_AD_PRIORITY_LEVEL0               (0x00U) /* Level 0 (interrupt disabled) */
#define _01_AD_PRIORITY_LEVEL1               (0x01U) /* Level 1 */
#define _02_AD_PRIORITY_LEVEL2               (0x02U) /* Level 2 */
#define _03_AD_PRIORITY_LEVEL3               (0x03U) /* Level 3 */
#define _04_AD_PRIORITY_LEVEL4               (0x04U) /* Level 4 */
#define _05_AD_PRIORITY_LEVEL5               (0x05U) /* Level 5 */
#define _06_AD_PRIORITY_LEVEL6               (0x06U) /* Level 6 */
#define _07_AD_PRIORITY_LEVEL7               (0x07U) /* Level 7 */
#define _08_AD_PRIORITY_LEVEL8               (0x08U) /* Level 8 */
#define _09_AD_PRIORITY_LEVEL9               (0x09U) /* Level 9 */
#define _0A_AD_PRIORITY_LEVEL10              (0x0AU) /* Level 10 */
#define _0B_AD_PRIORITY_LEVEL11              (0x0BU) /* Level 11 */
#define _0C_AD_PRIORITY_LEVEL12              (0x0CU) /* Level 12 */
#define _0D_AD_PRIORITY_LEVEL13              (0x0DU) /* Level 13 */
#define _0E_AD_PRIORITY_LEVEL14              (0x0EU) /* Level 14 */
#define _0F_AD_PRIORITY_LEVEL15              (0x0FU) /* Level 15 (highest) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    ADCHANNEL0, ADCHANNEL1, ADCHANNEL2, ADCHANNEL3, ADCHANNEL4, ADCHANNEL5, ADCHANNEL6, ADCHANNEL7,
    ADCHANNEL8, ADCHANNEL9, ADCHANNEL10, ADCHANNEL11, ADCHANNEL16, ADSELFDIAGNOSIS, ADINTERREFVOLT, 
    ADDATADUPLICATION, ADDATADUPLICATIONA, ADDATADUPLICATIONB
} ad_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

