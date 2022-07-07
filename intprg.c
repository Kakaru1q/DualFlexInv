/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/************************************************************************
*
* Device     : RX/RX200/RX24T
*
* File Name  : intprg.c
*
* Abstract   : Interrupt Program.
*
* History    : 0.5  (2015-06-16)  [Hardware Manual Revision : 0.50]
*            : 1.0A (2016-08-03)  [Hardware Manual Revision : 1.00]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright(C) 2016 (2015) Renesas Electronics Corporation.
*
************************************************************************/
#include <machine.h>
#include "vect.h"

#pragma section IntPRG

// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(); */}

// Exception(Access Instruction)
void Excep_AccessInst(void){/* brk(); */}

// Exception(Undefined Instruction)
void Excep_UndefinedInst(void){/* brk(); */}

// Exception(Floating Point)
void Excep_FloatingPoint(void){/* brk(); */}

// NMI
void NonMaskableInterrupt(void){/* brk(); */}

// Dummy
void Dummy(void){/* brk(); */}

// BRK
void Excep_BRK(void){ wait(); }

// BSC BUSERR
void Excep_BSC_BUSERR(void){/* brk(); */}

// FCU FRDYI
void Excep_FCU_FRDYI(void){/* brk(); */}

// ICU SWINT
void Excep_ICU_SWINT(void){/* brk(); */}

// CMT0 CMI0
void Excep_CMT0_CMI0(void){/* brk(); */}

// CMT1 CMI1
void Excep_CMT1_CMI1(void){/* brk(); */}

// CMT2 CMI2
void Excep_CMT2_CMI2(void){/* brk(); */}

// CMT3 CMI3
void Excep_CMT3_CMI3(void){/* brk(); */}

// CAC FERRF
void Excep_CAC_FERRF(void){/* brk(); */}

// CAC MENDF
void Excep_CAC_MENDF(void){/* brk(); */}

// CAC OVFF
void Excep_CAC_OVFF(void){/* brk(); */}

// SECURITY RD
void Excep_SECURITY_RD(void){/* brk(); */}

// SECURITY WR
void Excep_SECURITY_WR(void){/* brk(); */}

// SECURITY ERROR
void Excep_SECURITY_ERROR(void){/* brk(); */}

// GPT ETGIN
void Excep_GPT_ETGIN(void){/* brk(); */}

// GPT ETGIP
void Excep_GPT_ETGIP(void){/* brk(); */}

// RSPI0 SPEI0
void Excep_RSPI0_SPEI0(void){/* brk(); */}

// RSPI0 SPRI0
void Excep_RSPI0_SPRI0(void){/* brk(); */}

// RSPI0 SPTI0
void Excep_RSPI0_SPTI0(void){/* brk(); */}

// RSPI0 SPII0
void Excep_RSPI0_SPII0(void){/* brk(); */}

// GPT0 GTCIA0
void Excep_GPT0_GTCIA0(void){/* brk(); */}

// GPT0 GTCIB0
void Excep_GPT0_GTCIB0(void){/* brk(); */}

// GPT0 GTCIC0
void Excep_GPT0_GTCIC0(void){/* brk(); */}

// GPT0 GTCID0
void Excep_GPT0_GTCID0(void){/* brk(); */}

// GPT0 GDTE0
void Excep_GPT0_GDTE0(void){/* brk(); */}

// GPT0 GTCIE0
void Excep_GPT0_GTCIE0(void){/* brk(); */}

// GPT0 GTCIF0
void Excep_GPT0_GTCIF0(void){/* brk(); */}

// GPT0 GTCIV0
void Excep_GPT0_GTCIV0(void){/* brk(); */}

// GPT0 GTCIU0
void Excep_GPT0_GTCIU0(void){/* brk(); */}

// DOC DOPCF
void Excep_DOC_DOPCF(void){/* brk(); */}

// RSCAN COMFRXINT
void Excep_RSCAN_COMFRXINT(void){/* brk(); */}

// RSCAN RXFINT
void Excep_RSCAN_RXFINT(void){/* brk(); */}

// RSCAN TXINT
void Excep_RSCAN_TXINT(void){/* brk(); */}

// RSCAN CHERRINT
void Excep_RSCAN_CHERRINT(void){/* brk(); */}

// RSCAN GLERRINT
void Excep_RSCAN_GLERRINT(void){/* brk(); */}

// ICU IRQ0
void Excep_ICU_IRQ0(void){/* brk(); */}

// ICU IRQ1
void Excep_ICU_IRQ1(void){/* brk(); */}

// ICU IRQ2
void Excep_ICU_IRQ2(void){/* brk(); */}

// ICU IRQ3
void Excep_ICU_IRQ3(void){/* brk(); */}

// ICU IRQ4
void Excep_ICU_IRQ4(void){/* brk(); */}

// ICU IRQ5
void Excep_ICU_IRQ5(void){/* brk(); */}

// ICU IRQ6
void Excep_ICU_IRQ6(void){/* brk(); */}

// ICU IRQ7
void Excep_ICU_IRQ7(void){/* brk(); */}

// LVD LVD1
void Excep_LVD_LVD1(void){/* brk(); */}

// LVD LVD2
void Excep_LVD_LVD2(void){/* brk(); */}

// GPT1 GTCIA1
void Excep_GPT1_GTCIA1(void){/* brk(); */}

// GPT1 GTCIB1
void Excep_GPT1_GTCIB1(void){/* brk(); */}

// GPT1 GTCIC1
void Excep_GPT1_GTCIC1(void){/* brk(); */}

// GPT1 GTCID1
void Excep_GPT1_GTCID1(void){/* brk(); */}

// S12AD S12ADI
void Excep_S12AD_S12ADI(void){/* brk(); */}

// S12AD GBADI
void Excep_S12AD_GBADI(void){/* brk(); */}

// S12AD GCADI
void Excep_S12AD_GCADI(void){/* brk(); */}

// S12AD1 S12ADI1
void Excep_S12AD1_S12ADI1(void){/* brk(); */}

// S12AD1 GBADI1
void Excep_S12AD1_GBADI1(void){/* brk(); */}

// S12AD1 GCADI1
void Excep_S12AD1_GCADI1(void){/* brk(); */}

// CMPC0 CMPC0
void Excep_CMPC0_CMPC0(void){/* brk(); */}

// CMPC1 CMPC1
void Excep_CMPC1_CMPC1(void){/* brk(); */}

// CMPC2 CMPC2
void Excep_CMPC2_CMPC2(void){/* brk(); */}

// S12AD2 S12ADI2
void Excep_S12AD2_S12ADI2(void){/* brk(); */}

// S12AD2 GBADI2
void Excep_S12AD2_GBADI2(void){/* brk(); */}

// S12AD2 GCADI2
void Excep_S12AD2_GCADI2(void){/* brk(); */}

// MTU0 TGIA0
void Excep_MTU0_TGIA0(void){/* brk(); */}

// MTU0 TGIB0
void Excep_MTU0_TGIB0(void){/* brk(); */}

// MTU0 TGIC0
void Excep_MTU0_TGIC0(void){/* brk(); */}

// MTU0 TGID0
void Excep_MTU0_TGID0(void){/* brk(); */}

// MTU0 TCIV0
void Excep_MTU0_TCIV0(void){/* brk(); */}

// MTU0 TGIE0
void Excep_MTU0_TGIE0(void){/* brk(); */}

// MTU0 TGIF0
void Excep_MTU0_TGIF0(void){/* brk(); */}

// MTU1 TGIA1
void Excep_MTU1_TGIA1(void){/* brk(); */}

// MTU1 TGIB1
void Excep_MTU1_TGIB1(void){/* brk(); */}

// MTU1 TCIV1
void Excep_MTU1_TCIV1(void){/* brk(); */}

// MTU1 TCIU1
void Excep_MTU1_TCIU1(void){/* brk(); */}

// MTU2 TGIA2
void Excep_MTU2_TGIA2(void){/* brk(); */}

// MTU2 TGIB2
void Excep_MTU2_TGIB2(void){/* brk(); */}

// MTU2 TCIV2
void Excep_MTU2_TCIV2(void){/* brk(); */}

// MTU2 TCIU2
void Excep_MTU2_TCIU2(void){/* brk(); */}

// MTU3 TGIA3
void Excep_MTU3_TGIA3(void){/* brk(); */}

// MTU3 TGIB3
void Excep_MTU3_TGIB3(void){/* brk(); */}

// MTU3 TGIC3
void Excep_MTU3_TGIC3(void){/* brk(); */}

// MTU3 TGID3
void Excep_MTU3_TGID3(void){/* brk(); */}

// MTU3 TCIV3
void Excep_MTU3_TCIV3(void){/* brk(); */}

// MTU4 TGIA4
void Excep_MTU4_TGIA4(void){/* brk(); */}

// MTU4 TGIB4
void Excep_MTU4_TGIB4(void){/* brk(); */}

// MTU4 TGIC4
void Excep_MTU4_TGIC4(void){/* brk(); */}

// MTU4 TGID4
void Excep_MTU4_TGID4(void){/* brk(); */}

// MTU4 TCIV4
void Excep_MTU4_TCIV4(void){/* brk(); */}

// MTU5 TGIU5
void Excep_MTU5_TGIU5(void){/* brk(); */}

// MTU5 TGIV5
void Excep_MTU5_TGIV5(void){/* brk(); */}

// MTU5 TGIW5
void Excep_MTU5_TGIW5(void){/* brk(); */}

// MTU6 TGIA6
void Excep_MTU6_TGIA6(void){/* brk(); */}

// MTU6 TGIB6
void Excep_MTU6_TGIB6(void){/* brk(); */}

// MTU6 TGIC6
void Excep_MTU6_TGIC6(void){/* brk(); */}

// MTU6 TGID6
void Excep_MTU6_TGID6(void){/* brk(); */}

// MTU6 TCIV6
void Excep_MTU6_TCIV6(void){/* brk(); */}

// MTU7 TGIA7
void Excep_MTU7_TGIA7(void){/* brk(); */}

// MTU7 TGIB7
void Excep_MTU7_TGIB7(void){/* brk(); */}

// MTU7 TGIC7
void Excep_MTU7_TGIC7(void){/* brk(); */}

// MTU7 TGID7
void Excep_MTU7_TGID7(void){/* brk(); */}

// MTU7 TCIV7
void Excep_MTU7_TCIV7(void){/* brk(); */}

// MTU9 TGIA9
void Excep_MTU9_TGIA9(void){/* brk(); */}

// MTU9 TGIB9
void Excep_MTU9_TGIB9(void){/* brk(); */}

// MTU9 TGIC9
void Excep_MTU9_TGIC9(void){/* brk(); */}

// MTU9 TGID9
void Excep_MTU9_TGID9(void){/* brk(); */}

// MTU9 TCIV9
void Excep_MTU9_TCIV9(void){/* brk(); */}

// MTU9 TGIE9
void Excep_MTU9_TGIE9(void){/* brk(); */}

// MTU9 TGIF9
void Excep_MTU9_TGIF9(void){/* brk(); */}

// POE OEI1
void Excep_POE_OEI1(void){/* brk(); */}

// POE OEI2
void Excep_POE_OEI2(void){/* brk(); */}

// POE OEI3
void Excep_POE_OEI3(void){/* brk(); */}

// POE OEI4
void Excep_POE_OEI4(void){/* brk(); */}

// POE OEI5
void Excep_POE_OEI5(void){/* brk(); */}

// CMPC3 CMPC3
void Excep_CMPC3_CMPC3(void){/* brk(); */}

// TMR0 CMIA0
void Excep_TMR0_CMIA0(void){/* brk(); */}

// TMR0 CMIB0
void Excep_TMR0_CMIB0(void){/* brk(); */}

// TMR0 OVI0
void Excep_TMR0_OVI0(void){/* brk(); */}

// TMR1 CMIA1
void Excep_TMR1_CMIA1(void){/* brk(); */}

// TMR1 CMIB1
void Excep_TMR1_CMIB1(void){/* brk(); */}

// TMR1 OVI1
void Excep_TMR1_OVI1(void){/* brk(); */}

// TMR2 CMIA2
void Excep_TMR2_CMIA2(void){/* brk(); */}

// TMR2 CMIB2
void Excep_TMR2_CMIB2(void){/* brk(); */}

// TMR2 OVI2
void Excep_TMR2_OVI2(void){/* brk(); */}

// TMR3 CMIA3
void Excep_TMR3_CMIA3(void){/* brk(); */}

// TMR3 CMIB3
void Excep_TMR3_CMIB3(void){/* brk(); */}

// TMR3 OVI3
void Excep_TMR3_OVI3(void){/* brk(); */}

// TMR4 CMIA4
void Excep_TMR4_CMIA4(void){/* brk(); */}

// TMR4 CMIB4
void Excep_TMR4_CMIB4(void){/* brk(); */}

// TMR4 OVI4
void Excep_TMR4_OVI4(void){/* brk(); */}

// TMR5 CMIA5
void Excep_TMR5_CMIA5(void){/* brk(); */}

// TMR5 CMIB5
void Excep_TMR5_CMIB5(void){/* brk(); */}

// TMR5 OVI5
void Excep_TMR5_OVI5(void){/* brk(); */}

// TMR6 CMIA6
void Excep_TMR6_CMIA6(void){/* brk(); */}

// TMR6 CMIB6
void Excep_TMR6_CMIB6(void){/* brk(); */}

// TMR6 OVI6
void Excep_TMR6_OVI6(void){/* brk(); */}

// TMR7 CMIA7
void Excep_TMR7_CMIA7(void){/* brk(); */}

// TMR7 CMIB7
void Excep_TMR7_CMIB7(void){/* brk(); */}

// TMR7 OVI7
void Excep_TMR7_OVI7(void){/* brk(); */}

// GPT1 GDTE1
void Excep_GPT1_GDTE1(void){/* brk(); */}

// GPT1 GTCIE1
void Excep_GPT1_GTCIE1(void){/* brk(); */}

// GPT1 GTCIF1
void Excep_GPT1_GTCIF1(void){/* brk(); */}

// GPT1 GTCIV1
void Excep_GPT1_GTCIV1(void){/* brk(); */}

// GPT1 GTCIU1
void Excep_GPT1_GTCIU1(void){/* brk(); */}

// GPT2 GTCIA2
void Excep_GPT2_GTCIA2(void){/* brk(); */}

// GPT2 GTCIB2
void Excep_GPT2_GTCIB2(void){/* brk(); */}

// GPT2 GTCIC2
void Excep_GPT2_GTCIC2(void){/* brk(); */}

// GPT2 GTCID2
void Excep_GPT2_GTCID2(void){/* brk(); */}

// GPT2 GDTE2
void Excep_GPT2_GDTE2(void){/* brk(); */}

// GPT2 GTCIE2
void Excep_GPT2_GTCIE2(void){/* brk(); */}

// GPT2 GTCIF2
void Excep_GPT2_GTCIF2(void){/* brk(); */}

// GPT2 GTCIV2
void Excep_GPT2_GTCIV2(void){/* brk(); */}

// GPT2 GTCIU2
void Excep_GPT2_GTCIU2(void){/* brk(); */}

// GPT3 GTCIA3
void Excep_GPT3_GTCIA3(void){/* brk(); */}

// GPT3 GTCIB3
void Excep_GPT3_GTCIB3(void){/* brk(); */}

// SCI1 ERI1
void Excep_SCI1_ERI1(void){/* brk(); */}

// SCI1 RXI1
void Excep_SCI1_RXI1(void){/* brk(); */}

// SCI1 TXI1
void Excep_SCI1_TXI1(void){/* brk(); */}

// SCI1 TEI1
void Excep_SCI1_TEI1(void){/* brk(); */}

// SCI5 ERI5
void Excep_SCI5_ERI5(void){/* brk(); */}

// SCI5 RXI5
void Excep_SCI5_RXI5(void){/* brk(); */}

// SCI5 TXI5
void Excep_SCI5_TXI5(void){/* brk(); */}

// SCI5 TEI5
void Excep_SCI5_TEI5(void){/* brk(); */}

// SCI6 ERI6
void Excep_SCI6_ERI6(void){/* brk(); */}

// SCI6 RXI6
void Excep_SCI6_RXI6(void){/* brk(); */}

// SCI6 TXI6
void Excep_SCI6_TXI6(void){/* brk(); */}

// SCI6 TEI6
void Excep_SCI6_TEI6(void){/* brk(); */}

// SCI8 ERI8
void Excep_SCI8_ERI8(void){/* brk(); */}

// SCI8 RXI8
void Excep_SCI8_RXI8(void){/* brk(); */}

// SCI8 TXI8
void Excep_SCI8_TXI8(void){/* brk(); */}

// SCI8 TEI8
void Excep_SCI8_TEI8(void){/* brk(); */}

// SCI9 ERI9
void Excep_SCI9_ERI9(void){/* brk(); */}

// SCI9 RXI9
void Excep_SCI9_RXI9(void){/* brk(); */}

// SCI9 TXI9
void Excep_SCI9_TXI9(void){/* brk(); */}

// SCI9 TEI9
void Excep_SCI9_TEI9(void){/* brk(); */}

// GPT3 GTCIC3
void Excep_GPT3_GTCIC3(void){/* brk(); */}

// GPT3 GTCID3
void Excep_GPT3_GTCID3(void){/* brk(); */}

// GPT3 GDTE3
void Excep_GPT3_GDTE3(void){/* brk(); */}

// GPT3 GTCIE3
void Excep_GPT3_GTCIE3(void){/* brk(); */}

// GPT3 GTCIF3
void Excep_GPT3_GTCIF3(void){/* brk(); */}

// GPT3 GTCIV3
void Excep_GPT3_GTCIV3(void){/* brk(); */}

// GPT3 GTCIU3
void Excep_GPT3_GTCIU3(void){/* brk(); */}

// RIIC0 EEI0
void Excep_RIIC0_EEI0(void){/* brk(); */}

// RIIC0 RXI0
void Excep_RIIC0_RXI0(void){/* brk(); */}

// RIIC0 TXI0
void Excep_RIIC0_TXI0(void){/* brk(); */}

// RIIC0 TEI0
void Excep_RIIC0_TEI0(void){/* brk(); */}

// SCI11 ERI11
void Excep_SCI11_ERI11(void){/* brk(); */}

// SCI11 RXI11
void Excep_SCI11_RXI11(void){/* brk(); */}

// SCI11 TXI11
void Excep_SCI11_TXI11(void){/* brk(); */}

// SCI11 TEI11
void Excep_SCI11_TEI11(void){/* brk(); */}

