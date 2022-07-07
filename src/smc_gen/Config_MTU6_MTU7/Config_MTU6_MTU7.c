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
* File Name    : Config_MTU6_MTU7.c
* Version      : 1.9.0
* Device(s)    : R5F524TAAxFM
* Description  : This file implements device driver for Config_MTU6_MTU7.
* Creation Date: 2021-08-19
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_MTU6_MTU7.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU6_MTU7_Create
* Description  : This function initializes the MTU6 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU6_MTU7_Create(void)
{
    /* Release MTU channel 6 from stop state */
    MSTP(MTU6) = 0U;

    /* Enable read/write to MTU6, MTU7 registers */
    MTU.TRWERB.BIT.RWE = 1U;

    /* Stop MTU channel 6 counter */
    MTU.TSTRB.BIT.CST6 = 0U;
    MTU.TSTRB.BIT.CST7 = 0U;

    /* Set external clock noise filter */
    MTU0.NFCRC.BIT.NFBEN = 0U;

    /* Set timer synchronous clear */
    MTU6.TSYCR.BYTE = _00_MTU6_CL0A_OFF | _00_MTU6_CL0B_OFF | _00_MTU6_CL0C_OFF | _00_MTU6_CL0D_OFF | 
                      _00_MTU6_CL1A_OFF | _00_MTU6_CL1B_OFF | _00_MTU6_CL2A_OFF | _00_MTU6_CL2B_OFF;

    /* Set A/D conversion signal output for ADSM0, ADSM1 pins */
    MTU.TADSTRGR0.BYTE = _00_MTU_TADSTRS_NOSOURCE;
    MTU.TADSTRGR1.BYTE = _00_MTU_TADSTRS_NOSOURCE;

    /* Set TCIV7 interrupt priority level */
    IPR(MTU7, TCIV7) = _0F_MTU_PRIORITY_LEVEL15;

    /* MTU channel 6 is used as complementary PWM mode 3 */
    MTU6.TIER.BYTE = 0x00U;
    MTU7.TIER.BYTE = 0x00U;
    MTU.TITCR1B.BIT.T6AEN = 0U;
    MTU.TITCR1B.BIT.T7VEN = 0U;
    MTU6.TCR.BYTE = _00_MTU_PCLK_1 | _00_MTU_CKCL_DIS;
    MTU7.TCR.BYTE = _00_MTU_PCLK_1;
    MTU6.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU7.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU.TGCRB.BYTE = _80_MTU_BDC_OUT;
    MTU6.TCNT = _0320_6TCNT_VALUE;
    MTU7.TCNT = 0x0000U;
    MTU.TSYRB.BIT.SYNC6 = 0U;
    MTU.TSYRB.BIT.SYNC7 = 0U;
    MTU6.TGRB = _0064_6TGRB_VALUE;
    MTU6.TGRD = _0064_6TGRB_VALUE;
    MTU7.TGRA = _0064_7TGRA_VALUE;
    MTU7.TGRC = _0064_7TGRA_VALUE;
    MTU7.TGRB = _0064_7TGRB_VALUE;
    MTU7.TGRD = _0064_7TGRB_VALUE;
    MTU6.TGRE = _0064_6TGRE_VALUE;
    MTU7.TGRE = _0064_7TGRE_VALUE;
    MTU7.TGRF = _0064_7TGRF_VALUE;
    MTU.TDERB.BIT.TDER = 1U;
    MTU.TDDRB = _0320_TDDRB_VALUE;
    MTU.TCDRB = _0FA0_TCDRB_VALUE;
    MTU.TCBRB = _0FA0_TCDRB_VALUE;
    MTU6.TGRA = _12C0_SUM_VALUE;
    MTU6.TGRC = _12C0_SUM_VALUE;
    MTU.TOCR1B.BYTE = _08_MTU_TOCL_DISABLE | _04_MTU_TOCS_TOCR2;
    MTU.TOCR2B.BYTE = _00_MTU_TOLBR_DIS | _08_MTU_OLS2N_LH | _00_MTU_OLS2P_HL;
    MTU.TOLBRB.BYTE = MTU.TOCR2B.BYTE & 0x3FU;
    MTU6.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TTGE_DISABLE;
    MTU7.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _10_MTU_TCIEV_ENABLE | _00_MTU_TTGE2_DISABLE;
    MTU.TITMRB.BIT.TITM = 0U;
    MTU.TITCR1B.BYTE = _00_MTU_TVCOR_SKIP_COUNT_0;
    MTU.TBTERB.BYTE = _00_MTU_TF_NO_INT;
    MTU6.TMDR1.BYTE = _0F_MTU_CMT3 | _10_MTU_BFA_BUFFER | _20_MTU_BFB_BUFFER;
    MTU.TMDR2B.BIT.DRS = 1U;
    MTU.TOERB.BYTE = _C0_MTU_OE7D_DISABLE | _D0_MTU_OE7C_ENABLE | _C0_MTU_OE6D_DISABLE | _C0_MTU_OE7B_DISABLE | 
                     _C2_MTU_OE7A_ENABLE | _C0_MTU_OE6B_DISABLE;

    /* Disable read/write to MTU6, MTU7 registers */
    MTU.TRWERB.BIT.RWE = 0U;

    /* Set MTIOC7A pin */
    MPC.P94PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x10U;

    /* Set MTIOC7C pin */
    MPC.P91PFS.BYTE = 0x01U;
    PORT9.PMR.BYTE |= 0x02U;

    R_Config_MTU6_MTU7_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU6_MTU7_Start
* Description  : This function starts the MTU6 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU6_MTU7_Start(void)
{
    /* Enable TCIV7 interrupt in ICU */
    IEN(MTU7, TCIV7) = 1U;

    /* Start MTU6, MTU7 channel counter */
    MTU.TSTRB.BYTE |= (_40_MTU_CST6_ON | _80_MTU_CST7_ON);
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU6_MTU7_Stop
* Description  : This function stops the MTU6 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU6_MTU7_Stop(void)
{
    /* Disable TCIV7 interrupt in ICU */
    IEN(MTU7, TCIV7) = 0U;

    /* Stop MTU6, MTU7 channel counter */
    MTU.TSTRB.BIT.CST6 = 0U;
    MTU.TSTRB.BIT.CST7 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
