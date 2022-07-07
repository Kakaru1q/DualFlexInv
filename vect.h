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
* File Name  : vect.h
*
* Abstract   : Definition of Vector.
*
* History    : 0.5  (2015-06-16)  [Hardware Manual Revision : 0.50]
*            : 1.0A (2016-08-03)  [Hardware Manual Revision : 1.00]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright(C) 2016 (2015) Renesas Electronics Corporation.
*
************************************************************************/

// Exception(Supervisor Instruction)
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst(void);

// Exception(Access Instruction)
#pragma interrupt (Excep_AccessInst)
void Excep_AccessInst(void);

// Exception(Undefined Instruction)
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst(void);

// Exception(Floating Point)
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint(void);

// NMI
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt(void);

// Dummy
#pragma interrupt (Dummy)
void Dummy(void);

// BRK
#pragma interrupt (Excep_BRK(vect=0))
void Excep_BRK(void);

// vector  1 reserved
// vector  2 reserved
// vector  3 reserved
// vector  4 reserved
// vector  5 reserved
// vector  6 reserved
// vector  7 reserved
// vector  8 reserved
// vector  9 reserved
// vector 10 reserved
// vector 11 reserved
// vector 12 reserved
// vector 13 reserved
// vector 14 reserved
// vector 15 reserved

// BSC BUSERR
#pragma interrupt (Excep_BSC_BUSERR(vect=16))
void Excep_BSC_BUSERR(void);

// vector 17 reserved
// vector 18 reserved
// vector 19 reserved
// vector 20 reserved
// vector 21 reserved
// vector 22 reserved

// FCU FRDYI
#pragma interrupt (Excep_FCU_FRDYI(vect=23))
void Excep_FCU_FRDYI(void);

// vector 24 reserved
// vector 25 reserved
// vector 26 reserved

// ICU SWINT
#pragma interrupt (Excep_ICU_SWINT(vect=27))
void Excep_ICU_SWINT(void);

// CMT0 CMI0
#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

// CMT1 CMI1
#pragma interrupt (Excep_CMT1_CMI1(vect=29))
void Excep_CMT1_CMI1(void);

// CMT2 CMI2
#pragma interrupt (Excep_CMT2_CMI2(vect=30))
void Excep_CMT2_CMI2(void);

// CMT3 CMI3
#pragma interrupt (Excep_CMT3_CMI3(vect=31))
void Excep_CMT3_CMI3(void);

// CAC FERRF
#pragma interrupt (Excep_CAC_FERRF(vect=32))
void Excep_CAC_FERRF(void);

// CAC MENDF
#pragma interrupt (Excep_CAC_MENDF(vect=33))
void Excep_CAC_MENDF(void);

// CAC OVFF
#pragma interrupt (Excep_CAC_OVFF(vect=34))
void Excep_CAC_OVFF(void);

// vector 35 reserved

// SECURITY RD
#pragma interrupt (Excep_SECURITY_RD(vect=36))
void Excep_SECURITY_RD(void);

// SECURITY WR
#pragma interrupt (Excep_SECURITY_WR(vect=37))
void Excep_SECURITY_WR(void);

// SECURITY ERROR
#pragma interrupt (Excep_SECURITY_ERROR(vect=38))
void Excep_SECURITY_ERROR(void);

// vector 39 reserved

// GPT ETGIN
#pragma interrupt (Excep_GPT_ETGIN(vect=40))
void Excep_GPT_ETGIN(void);

// GPT ETGIP
#pragma interrupt (Excep_GPT_ETGIP(vect=41))
void Excep_GPT_ETGIP(void);

// vector 42 reserved
// vector 43 reserved

// RSPI0 SPEI0
#pragma interrupt (Excep_RSPI0_SPEI0(vect=44))
void Excep_RSPI0_SPEI0(void);

// RSPI0 SPRI0
#pragma interrupt (Excep_RSPI0_SPRI0(vect=45))
void Excep_RSPI0_SPRI0(void);

// RSPI0 SPTI0
#pragma interrupt (Excep_RSPI0_SPTI0(vect=46))
void Excep_RSPI0_SPTI0(void);

// RSPI0 SPII0
#pragma interrupt (Excep_RSPI0_SPII0(vect=47))
void Excep_RSPI0_SPII0(void);

// GPT0 GTCIA0
#pragma interrupt (Excep_GPT0_GTCIA0(vect=48))
void Excep_GPT0_GTCIA0(void);

// GPT0 GTCIB0
#pragma interrupt (Excep_GPT0_GTCIB0(vect=49))
void Excep_GPT0_GTCIB0(void);

// GPT0 GTCIC0
#pragma interrupt (Excep_GPT0_GTCIC0(vect=50))
void Excep_GPT0_GTCIC0(void);

// GPT0 GTCID0
#pragma interrupt (Excep_GPT0_GTCID0(vect=51))
void Excep_GPT0_GTCID0(void);

// GPT0 GDTE0
#pragma interrupt (Excep_GPT0_GDTE0(vect=52))
void Excep_GPT0_GDTE0(void);

// GPT0 GTCIE0
#pragma interrupt (Excep_GPT0_GTCIE0(vect=53))
void Excep_GPT0_GTCIE0(void);

// GPT0 GTCIF0
#pragma interrupt (Excep_GPT0_GTCIF0(vect=54))
void Excep_GPT0_GTCIF0(void);

// GPT0 GTCIV0
#pragma interrupt (Excep_GPT0_GTCIV0(vect=55))
void Excep_GPT0_GTCIV0(void);

// GPT0 GTCIU0
#pragma interrupt (Excep_GPT0_GTCIU0(vect=56))
void Excep_GPT0_GTCIU0(void);

// DOC DOPCF
#pragma interrupt (Excep_DOC_DOPCF(vect=57))
void Excep_DOC_DOPCF(void);

// vector 58 reserved

// RSCAN COMFRXINT
#pragma interrupt (Excep_RSCAN_COMFRXINT(vect=59))
void Excep_RSCAN_COMFRXINT(void);

// RSCAN RXFINT
#pragma interrupt (Excep_RSCAN_RXFINT(vect=60))
void Excep_RSCAN_RXFINT(void);

// RSCAN TXINT
#pragma interrupt (Excep_RSCAN_TXINT(vect=61))
void Excep_RSCAN_TXINT(void);

// RSCAN CHERRINT
#pragma interrupt (Excep_RSCAN_CHERRINT(vect=62))
void Excep_RSCAN_CHERRINT(void);

// RSCAN GLERRINT
#pragma interrupt (Excep_RSCAN_GLERRINT(vect=63))
void Excep_RSCAN_GLERRINT(void);

// ICU IRQ0
#pragma interrupt (Excep_ICU_IRQ0(vect=64))
void Excep_ICU_IRQ0(void);

// ICU IRQ1
#pragma interrupt (Excep_ICU_IRQ1(vect=65))
void Excep_ICU_IRQ1(void);

// ICU IRQ2
#pragma interrupt (Excep_ICU_IRQ2(vect=66))
void Excep_ICU_IRQ2(void);

// ICU IRQ3
#pragma interrupt (Excep_ICU_IRQ3(vect=67))
void Excep_ICU_IRQ3(void);

// ICU IRQ4
#pragma interrupt (Excep_ICU_IRQ4(vect=68))
void Excep_ICU_IRQ4(void);

// ICU IRQ5
#pragma interrupt (Excep_ICU_IRQ5(vect=69))
void Excep_ICU_IRQ5(void);

// ICU IRQ6
#pragma interrupt (Excep_ICU_IRQ6(vect=70))
void Excep_ICU_IRQ6(void);

// ICU IRQ7
#pragma interrupt (Excep_ICU_IRQ7(vect=71))
void Excep_ICU_IRQ7(void);

// vector 72 reserved
// vector 73 reserved
// vector 74 reserved
// vector 75 reserved
// vector 76 reserved
// vector 77 reserved
// vector 78 reserved
// vector 79 reserved
// vector 80 reserved
// vector 81 reserved
// vector 82 reserved
// vector 83 reserved
// vector 84 reserved
// vector 85 reserved
// vector 86 reserved
// vector 87 reserved

// LVD LVD1
#pragma interrupt (Excep_LVD_LVD1(vect=88))
void Excep_LVD_LVD1(void);

// LVD LVD2
#pragma interrupt (Excep_LVD_LVD2(vect=89))
void Excep_LVD_LVD2(void);

// vector 90 reserved
// vector 91 reserved
// vector 92 reserved
// vector 93 reserved
// vector 94 reserved
// vector 95 reserved
// vector 96 reserved
// vector 97 reserved

// GPT1 GTCIA1
#pragma interrupt (Excep_GPT1_GTCIA1(vect=98))
void Excep_GPT1_GTCIA1(void);

// GPT1 GTCIB1
#pragma interrupt (Excep_GPT1_GTCIB1(vect=99))
void Excep_GPT1_GTCIB1(void);

// GPT1 GTCIC1
#pragma interrupt (Excep_GPT1_GTCIC1(vect=100))
void Excep_GPT1_GTCIC1(void);

// GPT1 GTCID1
#pragma interrupt (Excep_GPT1_GTCID1(vect=101))
void Excep_GPT1_GTCID1(void);

// S12AD S12ADI
#pragma interrupt (Excep_S12AD_S12ADI(vect=102))
void Excep_S12AD_S12ADI(void);

// S12AD GBADI
#pragma interrupt (Excep_S12AD_GBADI(vect=103))
void Excep_S12AD_GBADI(void);

// S12AD GCADI
#pragma interrupt (Excep_S12AD_GCADI(vect=104))
void Excep_S12AD_GCADI(void);

// S12AD1 S12ADI1
#pragma interrupt (Excep_S12AD1_S12ADI1(vect=105))
void Excep_S12AD1_S12ADI1(void);

// S12AD1 GBADI1
#pragma interrupt (Excep_S12AD1_GBADI1(vect=106))
void Excep_S12AD1_GBADI1(void);

// S12AD1 GCADI1
#pragma interrupt (Excep_S12AD1_GCADI1(vect=107))
void Excep_S12AD1_GCADI1(void);

// CMPC0 CMPC0
#pragma interrupt (Excep_CMPC0_CMPC0(vect=108))
void Excep_CMPC0_CMPC0(void);

// CMPC1 CMPC1
#pragma interrupt (Excep_CMPC1_CMPC1(vect=109))
void Excep_CMPC1_CMPC1(void);

// CMPC2 CMPC2
#pragma interrupt (Excep_CMPC2_CMPC2(vect=110))
void Excep_CMPC2_CMPC2(void);

// S12AD2 S12ADI2
#pragma interrupt (Excep_S12AD2_S12ADI2(vect=111))
void Excep_S12AD2_S12ADI2(void);

// S12AD2 GBADI2
#pragma interrupt (Excep_S12AD2_GBADI2(vect=112))
void Excep_S12AD2_GBADI2(void);

// S12AD2 GCADI2
#pragma interrupt (Excep_S12AD2_GCADI2(vect=113))
void Excep_S12AD2_GCADI2(void);

// MTU0 TGIA0
#pragma interrupt (Excep_MTU0_TGIA0(vect=114))
void Excep_MTU0_TGIA0(void);

// MTU0 TGIB0
#pragma interrupt (Excep_MTU0_TGIB0(vect=115))
void Excep_MTU0_TGIB0(void);

// MTU0 TGIC0
#pragma interrupt (Excep_MTU0_TGIC0(vect=116))
void Excep_MTU0_TGIC0(void);

// MTU0 TGID0
#pragma interrupt (Excep_MTU0_TGID0(vect=117))
void Excep_MTU0_TGID0(void);

// MTU0 TCIV0
#pragma interrupt (Excep_MTU0_TCIV0(vect=118))
void Excep_MTU0_TCIV0(void);

// MTU0 TGIE0
#pragma interrupt (Excep_MTU0_TGIE0(vect=119))
void Excep_MTU0_TGIE0(void);

// MTU0 TGIF0
#pragma interrupt (Excep_MTU0_TGIF0(vect=120))
void Excep_MTU0_TGIF0(void);

// MTU1 TGIA1
#pragma interrupt (Excep_MTU1_TGIA1(vect=121))
void Excep_MTU1_TGIA1(void);

// MTU1 TGIB1
#pragma interrupt (Excep_MTU1_TGIB1(vect=122))
void Excep_MTU1_TGIB1(void);

// MTU1 TCIV1
#pragma interrupt (Excep_MTU1_TCIV1(vect=123))
void Excep_MTU1_TCIV1(void);

// MTU1 TCIU1
#pragma interrupt (Excep_MTU1_TCIU1(vect=124))
void Excep_MTU1_TCIU1(void);

// MTU2 TGIA2
#pragma interrupt (Excep_MTU2_TGIA2(vect=125))
void Excep_MTU2_TGIA2(void);

// MTU2 TGIB2
#pragma interrupt (Excep_MTU2_TGIB2(vect=126))
void Excep_MTU2_TGIB2(void);

// MTU2 TCIV2
#pragma interrupt (Excep_MTU2_TCIV2(vect=127))
void Excep_MTU2_TCIV2(void);

// MTU2 TCIU2
#pragma interrupt (Excep_MTU2_TCIU2(vect=128))
void Excep_MTU2_TCIU2(void);

// MTU3 TGIA3
#pragma interrupt (Excep_MTU3_TGIA3(vect=129))
void Excep_MTU3_TGIA3(void);

// MTU3 TGIB3
#pragma interrupt (Excep_MTU3_TGIB3(vect=130))
void Excep_MTU3_TGIB3(void);

// MTU3 TGIC3
#pragma interrupt (Excep_MTU3_TGIC3(vect=131))
void Excep_MTU3_TGIC3(void);

// MTU3 TGID3
#pragma interrupt (Excep_MTU3_TGID3(vect=132))
void Excep_MTU3_TGID3(void);

// MTU3 TCIV3
#pragma interrupt (Excep_MTU3_TCIV3(vect=133))
void Excep_MTU3_TCIV3(void);

// MTU4 TGIA4
#pragma interrupt (Excep_MTU4_TGIA4(vect=134))
void Excep_MTU4_TGIA4(void);

// MTU4 TGIB4
#pragma interrupt (Excep_MTU4_TGIB4(vect=135))
void Excep_MTU4_TGIB4(void);

// MTU4 TGIC4
#pragma interrupt (Excep_MTU4_TGIC4(vect=136))
void Excep_MTU4_TGIC4(void);

// MTU4 TGID4
#pragma interrupt (Excep_MTU4_TGID4(vect=137))
void Excep_MTU4_TGID4(void);

// MTU4 TCIV4
#pragma interrupt (Excep_MTU4_TCIV4(vect=138))
void Excep_MTU4_TCIV4(void);

// MTU5 TGIU5
#pragma interrupt (Excep_MTU5_TGIU5(vect=139))
void Excep_MTU5_TGIU5(void);

// MTU5 TGIV5
#pragma interrupt (Excep_MTU5_TGIV5(vect=140))
void Excep_MTU5_TGIV5(void);

// MTU5 TGIW5
#pragma interrupt (Excep_MTU5_TGIW5(vect=141))
void Excep_MTU5_TGIW5(void);

// MTU6 TGIA6
#pragma interrupt (Excep_MTU6_TGIA6(vect=142))
void Excep_MTU6_TGIA6(void);

// MTU6 TGIB6
#pragma interrupt (Excep_MTU6_TGIB6(vect=143))
void Excep_MTU6_TGIB6(void);

// MTU6 TGIC6
#pragma interrupt (Excep_MTU6_TGIC6(vect=144))
void Excep_MTU6_TGIC6(void);

// MTU6 TGID6
#pragma interrupt (Excep_MTU6_TGID6(vect=145))
void Excep_MTU6_TGID6(void);

// MTU6 TCIV6
#pragma interrupt (Excep_MTU6_TCIV6(vect=146))
void Excep_MTU6_TCIV6(void);

// vector 147 reserved
// vector 148 reserved

// MTU7 TGIA7
#pragma interrupt (Excep_MTU7_TGIA7(vect=149))
void Excep_MTU7_TGIA7(void);

// MTU7 TGIB7
#pragma interrupt (Excep_MTU7_TGIB7(vect=150))
void Excep_MTU7_TGIB7(void);

// MTU7 TGIC7
#pragma interrupt (Excep_MTU7_TGIC7(vect=151))
void Excep_MTU7_TGIC7(void);

// MTU7 TGID7
#pragma interrupt (Excep_MTU7_TGID7(vect=152))
void Excep_MTU7_TGID7(void);

// MTU7 TCIV7
#pragma interrupt (Excep_MTU7_TCIV7(vect=153))
void Excep_MTU7_TCIV7(void);

// vector 154 reserved
// vector 155 reserved
// vector 156 reserved
// vector 157 reserved
// vector 158 reserved

// MTU9 TGIA9
#pragma interrupt (Excep_MTU9_TGIA9(vect=159))
void Excep_MTU9_TGIA9(void);

// MTU9 TGIB9
#pragma interrupt (Excep_MTU9_TGIB9(vect=160))
void Excep_MTU9_TGIB9(void);

// MTU9 TGIC9
#pragma interrupt (Excep_MTU9_TGIC9(vect=161))
void Excep_MTU9_TGIC9(void);

// MTU9 TGID9
#pragma interrupt (Excep_MTU9_TGID9(vect=162))
void Excep_MTU9_TGID9(void);

// MTU9 TCIV9
#pragma interrupt (Excep_MTU9_TCIV9(vect=163))
void Excep_MTU9_TCIV9(void);

// MTU9 TGIE9
#pragma interrupt (Excep_MTU9_TGIE9(vect=164))
void Excep_MTU9_TGIE9(void);

// MTU9 TGIF9
#pragma interrupt (Excep_MTU9_TGIF9(vect=165))
void Excep_MTU9_TGIF9(void);

// vector 166 reserved
// vector 167 reserved

// POE OEI1
#pragma interrupt (Excep_POE_OEI1(vect=168))
void Excep_POE_OEI1(void);

// POE OEI2
#pragma interrupt (Excep_POE_OEI2(vect=169))
void Excep_POE_OEI2(void);

// POE OEI3
#pragma interrupt (Excep_POE_OEI3(vect=170))
void Excep_POE_OEI3(void);

// POE OEI4
#pragma interrupt (Excep_POE_OEI4(vect=171))
void Excep_POE_OEI4(void);

// POE OEI5
#pragma interrupt (Excep_POE_OEI5(vect=172))
void Excep_POE_OEI5(void);

// CMPC3 CMPC3
#pragma interrupt (Excep_CMPC3_CMPC3(vect=173))
void Excep_CMPC3_CMPC3(void);

// TMR0 CMIA0
#pragma interrupt (Excep_TMR0_CMIA0(vect=174))
void Excep_TMR0_CMIA0(void);

// TMR0 CMIB0
#pragma interrupt (Excep_TMR0_CMIB0(vect=175))
void Excep_TMR0_CMIB0(void);

// TMR0 OVI0
#pragma interrupt (Excep_TMR0_OVI0(vect=176))
void Excep_TMR0_OVI0(void);

// TMR1 CMIA1
#pragma interrupt (Excep_TMR1_CMIA1(vect=177))
void Excep_TMR1_CMIA1(void);

// TMR1 CMIB1
#pragma interrupt (Excep_TMR1_CMIB1(vect=178))
void Excep_TMR1_CMIB1(void);

// TMR1 OVI1
#pragma interrupt (Excep_TMR1_OVI1(vect=179))
void Excep_TMR1_OVI1(void);

// TMR2 CMIA2
#pragma interrupt (Excep_TMR2_CMIA2(vect=180))
void Excep_TMR2_CMIA2(void);

// TMR2 CMIB2
#pragma interrupt (Excep_TMR2_CMIB2(vect=181))
void Excep_TMR2_CMIB2(void);

// TMR2 OVI2
#pragma interrupt (Excep_TMR2_OVI2(vect=182))
void Excep_TMR2_OVI2(void);

// TMR3 CMIA3
#pragma interrupt (Excep_TMR3_CMIA3(vect=183))
void Excep_TMR3_CMIA3(void);

// TMR3 CMIB3
#pragma interrupt (Excep_TMR3_CMIB3(vect=184))
void Excep_TMR3_CMIB3(void);

// TMR3 OVI3
#pragma interrupt (Excep_TMR3_OVI3(vect=185))
void Excep_TMR3_OVI3(void);

// TMR4 CMIA4
#pragma interrupt (Excep_TMR4_CMIA4(vect=186))
void Excep_TMR4_CMIA4(void);

// TMR4 CMIB4
#pragma interrupt (Excep_TMR4_CMIB4(vect=187))
void Excep_TMR4_CMIB4(void);

// TMR4 OVI4
#pragma interrupt (Excep_TMR4_OVI4(vect=188))
void Excep_TMR4_OVI4(void);

// TMR5 CMIA5
#pragma interrupt (Excep_TMR5_CMIA5(vect=189))
void Excep_TMR5_CMIA5(void);

// TMR5 CMIB5
#pragma interrupt (Excep_TMR5_CMIB5(vect=190))
void Excep_TMR5_CMIB5(void);

// TMR5 OVI5
#pragma interrupt (Excep_TMR5_OVI5(vect=191))
void Excep_TMR5_OVI5(void);

// TMR6 CMIA6
#pragma interrupt (Excep_TMR6_CMIA6(vect=192))
void Excep_TMR6_CMIA6(void);

// TMR6 CMIB6
#pragma interrupt (Excep_TMR6_CMIB6(vect=193))
void Excep_TMR6_CMIB6(void);

// TMR6 OVI6
#pragma interrupt (Excep_TMR6_OVI6(vect=194))
void Excep_TMR6_OVI6(void);

// TMR7 CMIA7
#pragma interrupt (Excep_TMR7_CMIA7(vect=195))
void Excep_TMR7_CMIA7(void);

// TMR7 CMIB7
#pragma interrupt (Excep_TMR7_CMIB7(vect=196))
void Excep_TMR7_CMIB7(void);

// TMR7 OVI7
#pragma interrupt (Excep_TMR7_OVI7(vect=197))
void Excep_TMR7_OVI7(void);

// vector 198 reserved
// vector 199 reserved
// vector 200 reserved
// vector 201 reserved

// GPT1 GDTE1
#pragma interrupt (Excep_GPT1_GDTE1(vect=202))
void Excep_GPT1_GDTE1(void);

// GPT1 GTCIE1
#pragma interrupt (Excep_GPT1_GTCIE1(vect=203))
void Excep_GPT1_GTCIE1(void);

// GPT1 GTCIF1
#pragma interrupt (Excep_GPT1_GTCIF1(vect=204))
void Excep_GPT1_GTCIF1(void);

// GPT1 GTCIV1
#pragma interrupt (Excep_GPT1_GTCIV1(vect=205))
void Excep_GPT1_GTCIV1(void);

// GPT1 GTCIU1
#pragma interrupt (Excep_GPT1_GTCIU1(vect=206))
void Excep_GPT1_GTCIU1(void);

// GPT2 GTCIA2
#pragma interrupt (Excep_GPT2_GTCIA2(vect=207))
void Excep_GPT2_GTCIA2(void);

// GPT2 GTCIB2
#pragma interrupt (Excep_GPT2_GTCIB2(vect=208))
void Excep_GPT2_GTCIB2(void);

// GPT2 GTCIC2
#pragma interrupt (Excep_GPT2_GTCIC2(vect=209))
void Excep_GPT2_GTCIC2(void);

// GPT2 GTCID2
#pragma interrupt (Excep_GPT2_GTCID2(vect=210))
void Excep_GPT2_GTCID2(void);

// GPT2 GDTE2
#pragma interrupt (Excep_GPT2_GDTE2(vect=211))
void Excep_GPT2_GDTE2(void);

// GPT2 GTCIE2
#pragma interrupt (Excep_GPT2_GTCIE2(vect=212))
void Excep_GPT2_GTCIE2(void);

// GPT2 GTCIF2
#pragma interrupt (Excep_GPT2_GTCIF2(vect=213))
void Excep_GPT2_GTCIF2(void);

// GPT2 GTCIV2
#pragma interrupt (Excep_GPT2_GTCIV2(vect=214))
void Excep_GPT2_GTCIV2(void);

// GPT2 GTCIU2
#pragma interrupt (Excep_GPT2_GTCIU2(vect=215))
void Excep_GPT2_GTCIU2(void);

// GPT3 GTCIA3
#pragma interrupt (Excep_GPT3_GTCIA3(vect=216))
void Excep_GPT3_GTCIA3(void);

// GPT3 GTCIB3
#pragma interrupt (Excep_GPT3_GTCIB3(vect=217))
void Excep_GPT3_GTCIB3(void);

// SCI1 ERI1
#pragma interrupt (Excep_SCI1_ERI1(vect=218))
void Excep_SCI1_ERI1(void);

// SCI1 RXI1
#pragma interrupt (Excep_SCI1_RXI1(vect=219))
void Excep_SCI1_RXI1(void);

// SCI1 TXI1
#pragma interrupt (Excep_SCI1_TXI1(vect=220))
void Excep_SCI1_TXI1(void);

// SCI1 TEI1
#pragma interrupt (Excep_SCI1_TEI1(vect=221))
void Excep_SCI1_TEI1(void);

// SCI5 ERI5
#pragma interrupt (Excep_SCI5_ERI5(vect=222))
void Excep_SCI5_ERI5(void);

// SCI5 RXI5
#pragma interrupt (Excep_SCI5_RXI5(vect=223))
void Excep_SCI5_RXI5(void);

// SCI5 TXI5
#pragma interrupt (Excep_SCI5_TXI5(vect=224))
void Excep_SCI5_TXI5(void);

// SCI5 TEI5
#pragma interrupt (Excep_SCI5_TEI5(vect=225))
void Excep_SCI5_TEI5(void);

// SCI6 ERI6
#pragma interrupt (Excep_SCI6_ERI6(vect=226))
void Excep_SCI6_ERI6(void);

// SCI6 RXI6
#pragma interrupt (Excep_SCI6_RXI6(vect=227))
void Excep_SCI6_RXI6(void);

// SCI6 TXI6
#pragma interrupt (Excep_SCI6_TXI6(vect=228))
void Excep_SCI6_TXI6(void);

// SCI6 TEI6
#pragma interrupt (Excep_SCI6_TEI6(vect=229))
void Excep_SCI6_TEI6(void);

// SCI8 ERI8
#pragma interrupt (Excep_SCI8_ERI8(vect=230))
void Excep_SCI8_ERI8(void);

// SCI8 RXI8
#pragma interrupt (Excep_SCI8_RXI8(vect=231))
void Excep_SCI8_RXI8(void);

// SCI8 TXI8
#pragma interrupt (Excep_SCI8_TXI8(vect=232))
void Excep_SCI8_TXI8(void);

// SCI8 TEI8
#pragma interrupt (Excep_SCI8_TEI8(vect=233))
void Excep_SCI8_TEI8(void);

// SCI9 ERI9
#pragma interrupt (Excep_SCI9_ERI9(vect=234))
void Excep_SCI9_ERI9(void);

// SCI9 RXI9
#pragma interrupt (Excep_SCI9_RXI9(vect=235))
void Excep_SCI9_RXI9(void);

// SCI9 TXI9
#pragma interrupt (Excep_SCI9_TXI9(vect=236))
void Excep_SCI9_TXI9(void);

// SCI9 TEI9
#pragma interrupt (Excep_SCI9_TEI9(vect=237))
void Excep_SCI9_TEI9(void);

// GPT3 GTCIC3
#pragma interrupt (Excep_GPT3_GTCIC3(vect=238))
void Excep_GPT3_GTCIC3(void);

// GPT3 GTCID3
#pragma interrupt (Excep_GPT3_GTCID3(vect=239))
void Excep_GPT3_GTCID3(void);

// GPT3 GDTE3
#pragma interrupt (Excep_GPT3_GDTE3(vect=240))
void Excep_GPT3_GDTE3(void);

// GPT3 GTCIE3
#pragma interrupt (Excep_GPT3_GTCIE3(vect=241))
void Excep_GPT3_GTCIE3(void);

// GPT3 GTCIF3
#pragma interrupt (Excep_GPT3_GTCIF3(vect=242))
void Excep_GPT3_GTCIF3(void);

// GPT3 GTCIV3
#pragma interrupt (Excep_GPT3_GTCIV3(vect=243))
void Excep_GPT3_GTCIV3(void);

// GPT3 GTCIU3
#pragma interrupt (Excep_GPT3_GTCIU3(vect=244))
void Excep_GPT3_GTCIU3(void);

// vector 245 reserved

// RIIC0 EEI0
#pragma interrupt (Excep_RIIC0_EEI0(vect=246))
void Excep_RIIC0_EEI0(void);

// RIIC0 RXI0
#pragma interrupt (Excep_RIIC0_RXI0(vect=247))
void Excep_RIIC0_RXI0(void);

// RIIC0 TXI0
#pragma interrupt (Excep_RIIC0_TXI0(vect=248))
void Excep_RIIC0_TXI0(void);

// RIIC0 TEI0
#pragma interrupt (Excep_RIIC0_TEI0(vect=249))
void Excep_RIIC0_TEI0(void);

// SCI11 ERI11
#pragma interrupt (Excep_SCI11_ERI11(vect=250))
void Excep_SCI11_ERI11(void);

// SCI11 RXI11
#pragma interrupt (Excep_SCI11_RXI11(vect=251))
void Excep_SCI11_RXI11(void);

// SCI11 TXI11
#pragma interrupt (Excep_SCI11_TXI11(vect=252))
void Excep_SCI11_TXI11(void);

// SCI11 TEI11
#pragma interrupt (Excep_SCI11_TEI11(vect=253))
void Excep_SCI11_TEI11(void);

// vector 254 reserved
// vector 255 reserved

//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
extern void PowerON_Reset_PC(void);
//;<<VECTOR DATA END (POWER ON RESET)>>
