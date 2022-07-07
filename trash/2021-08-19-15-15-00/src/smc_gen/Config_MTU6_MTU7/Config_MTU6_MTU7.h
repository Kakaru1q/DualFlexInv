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
* File Name    : Config_MTU6_MTU7.h
* Version      : 1.9.0
* Device(s)    : R5F524TAAxFM
* Description  : This file implements device driver for Config_MTU6_MTU7.
* Creation Date: 2021-08-19
***********************************************************************************************************************/

#ifndef CFG_Config_MTU6_MTU7_H
#define CFG_Config_MTU6_MTU7_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_mtu3.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define MTU6_PCLK_COUNTER_DIVISION      (1)
#define _0320_6TCNT_VALUE               (0x0320U) /* MTU6.TCNT value */
#define _0320_TDDRB_VALUE               (0x0320U) /* MTU.TDDRB value */
#define _0FA0_TCDRB_VALUE               (0x0FA0U) /* MTU.TCDRB value */
#define _0064_6TGRB_VALUE               (0x0064U) /* MTU6.TGRB value */
#define _0064_7TGRA_VALUE               (0x0064U) /* MTU7.TGRA value */
#define _0064_7TGRB_VALUE               (0x0064U) /* MTU7.TGRB value */
#define _0064_6TGRE_VALUE               (0x0064U) /* MTU6.TGRE value */
#define _0064_7TGRE_VALUE               (0x0064U) /* MTU7.TGRE value */
#define _0064_7TGRF_VALUE               (0x0064U) /* MTU7.TGRF value */
#define _12C0_SUM_VALUE                 (0x12C0U) /* Timer General Register (TGR) value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_MTU6_MTU7_Create(void);
void R_Config_MTU6_MTU7_Create_UserInit(void);
void R_Config_MTU6_MTU7_Start(void);
void R_Config_MTU6_MTU7_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
