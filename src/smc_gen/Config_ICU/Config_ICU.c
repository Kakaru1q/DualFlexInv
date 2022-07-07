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
* File Name    : Config_ICU.c
* Version      : 2.1.0
* Device(s)    : R5F524TAAxFM
* Description  : This file implements device driver for Config_ICU.
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
#include "Config_ICU.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ICU_Create
* Description  : This function initializes the ICU module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_Create(void)
{
    /* Disable IRQ interrupts */
    ICU.IER[0x08].BYTE = 0x00U;

    /* Disable software interrupt */
    IEN(ICU,SWINT) = 0U;

    /* Disable IRQ digital filter */
    ICU.IRQFLTE0.BYTE &= ~(_02_ICU_IRQ1_FILTER_ENABLE | _04_ICU_IRQ2_FILTER_ENABLE | _08_ICU_IRQ3_FILTER_ENABLE | 
                         _40_ICU_IRQ6_FILTER_ENABLE | _80_ICU_IRQ7_FILTER_ENABLE);

    /* Set IRQ1 pin */
    MPC.P11PFS.BYTE = 0x40U;
    PORT1.PDR.BYTE &= 0xFDU;
    PORT1.PMR.BYTE &= 0xFDU;

    /* Set IRQ2 pin */
    MPC.P00PFS.BYTE = 0x40U;
    PORT0.PDR.BYTE &= 0xFEU;
    PORT0.PMR.BYTE &= 0xFEU;

    /* Set IRQ3 pin */
    MPC.PB4PFS.BYTE = 0x40U;
    PORTB.PDR.BYTE &= 0xEFU;
    PORTB.PMR.BYTE &= 0xEFU;

    /* Set IRQ6 pin */
    MPC.P31PFS.BYTE = 0x40U;
    PORT3.PDR.BYTE &= 0xFDU;
    PORT3.PMR.BYTE &= 0xFDU;

    /* Set IRQ7 pin */
    MPC.P30PFS.BYTE = 0x40U;
    PORT3.PDR.BYTE &= 0xFEU;
    PORT3.PMR.BYTE &= 0xFEU;

    /* Set IRQ detection type */
    ICU.IRQCR[1].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;
    ICU.IRQCR[2].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;
    ICU.IRQCR[3].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;
    ICU.IRQCR[6].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;
    ICU.IRQCR[7].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;

    /* Set IRQ priority level */
    IPR(ICU,IRQ1) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ2) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ3) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ6) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ7) = _0F_ICU_PRIORITY_LEVEL15;

    R_Config_ICU_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ1_Start
* Description  : This function enables IRQ1 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ1_Start(void)
{
    /* Enable IRQ1 interrupt */
    IEN(ICU,IRQ1) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ1_Stop
* Description  : This function disables IRQ1 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ1_Stop(void)
{
    /* Disable IRQ1 interrupt */
    IEN(ICU,IRQ1) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ2_Start
* Description  : This function enables IRQ2 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ2_Start(void)
{
    /* Enable IRQ2 interrupt */
    IEN(ICU,IRQ2) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ2_Stop
* Description  : This function disables IRQ2 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ2_Stop(void)
{
    /* Disable IRQ2 interrupt */
    IEN(ICU,IRQ2) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ3_Start
* Description  : This function enables IRQ3 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ3_Start(void)
{
    /* Enable IRQ3 interrupt */
    IEN(ICU,IRQ3) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ3_Stop
* Description  : This function disables IRQ3 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ3_Stop(void)
{
    /* Disable IRQ3 interrupt */
    IEN(ICU,IRQ3) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ6_Start
* Description  : This function enables IRQ6 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ6_Start(void)
{
    /* Enable IRQ6 interrupt */
    IEN(ICU,IRQ6) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ6_Stop
* Description  : This function disables IRQ6 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ6_Stop(void)
{
    /* Disable IRQ6 interrupt */
    IEN(ICU,IRQ6) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ7_Start
* Description  : This function enables IRQ7 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ7_Start(void)
{
    /* Enable IRQ7 interrupt */
    IEN(ICU,IRQ7) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ7_Stop
* Description  : This function disables IRQ7 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ7_Stop(void)
{
    /* Disable IRQ7 interrupt */
    IEN(ICU,IRQ7) = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
