/***********************************************************************/
/*                                                                     */
/*  FILE        :Init.c                     			       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Initial Function	                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/
#include "platform.h"
#include "init.h"
#include "globalvalue.h"

void TMR0Init()
{
	////100us
   /* Disable TMR0 interrupts */
    IEN(TMR0, CMIA0) = 0U;

    /* Cancel TMR module stop state */
    MSTP(TMR0) = 0U;

    /* Set counter clear and interrupt */
    TMR0.TCR.BYTE = _40_TMR_CMIA_INT_ENABLE | _08_TMR_CNT_CLR_COMP_MATCH_A | _00_TMR_CMIB_INT_DISABLE | 
                    _00_TMR_OVI_INT_DISABLE;

    /* Set A/D trigger and output */
    TMR0.TCSR.BYTE = _10_TMR_AD_TRIGGER_ENABLE | _E0_TMR0246_TCSR_DEFAULT;

    /* Set compare match value */
    TMR0.TCORA = 0x3EU;
    TMR0.TCORB = 0x3EU;

    /* Configure TMR0 interrupts */
    IPR(TMR0, CMIA0) = _0F_TMR_PRIORITY_LEVEL15;
    
}

void TMR2Init()
{
	//10us
    /* Disable TMR2 interrupts */
    IEN(TMR2, CMIA2) = 0U;

    /* Cancel TMR module stop state */
    MSTP(TMR2) = 0U;

    /* Set counter clear and interrupt */
    TMR2.TCR.BYTE = _40_TMR_CMIA_INT_ENABLE | _00_TMR_CNT_CLR_DISABLE | _00_TMR_CMIB_INT_DISABLE | 
                    _00_TMR_OVI_INT_DISABLE;

    /* Set A/D trigger and output */
    TMR2.TCSR.BYTE = _10_TMR_AD_TRIGGER_ENABLE | _E0_TMR0246_TCSR_DEFAULT;

    /* Set compare match value */
    TMR2.TCORA = 0x31U;//_31_TMR2_COMP_MATCH_VALUE_A;
    TMR2.TCORB = 0x31U;//_31_TMR2_COMP_MATCH_VALUE_B;

    /* Configure TMR2 interrupts */
    IPR(TMR2, CMIA2) = _0F_TMR_PRIORITY_LEVEL15;
}
void TMRInit()
{
	TMR0Init();
	TMR2Init();
}
void CMT0Init()
{
	   /* Disable CMI0 interrupt */
    IEN(CMT0,CMI0) = 0U;

    /* Cancel CMT stop state in LPC */
    MSTP(CMT0) = 0U;

    /* Set control registers */
    CMT0.CMCR.WORD = _0002_CMT_CMCR_CLOCK_PCLK128 | _0040_CMT_CMCR_CMIE_ENABLE | _0080_CMT_CMCR_DEFAULT;

    /* Set compare match register */
    CMT0.CMCOR = _001E_CMT0_CMCOR_VALUE;

    /* Set CMI0 priority level */
    IPR(CMT0,CMI0) = _0F_CMT_PRIORITY_LEVEL15;
}
void CMT1Init()
{
    /* Disable CMI1 interrupt */
    IEN(CMT1,CMI1) = 0U;

    /* Cancel CMT stop state in LPC */
    MSTP(CMT1) = 0U;

    /* Set control registers */
    CMT1.CMCR.WORD = _0002_CMT_CMCR_CLOCK_PCLK128 | _0040_CMT_CMCR_CMIE_ENABLE | _0080_CMT_CMCR_DEFAULT;

    /* Set compare match register */
    CMT1.CMCOR = 0x7A11U;//_7A11_CMT1_CMCOR_VALUE;

    /* Set CMI1 priority level */
    IPR(CMT1,CMI1) = _0F_CMT_PRIORITY_LEVEL15;
}

void CMTInit()
{
	CMT0Init();
	CMT1Init();
}

void MTU3Init()
{
	//P71, P74 : MTIOC3B, MTIOC3D Setting
	//Complementary PWM Mode  for PWM

	
    /* Release MTU channel 3 from stop state */
    MSTP(MTU3) = 0U;

    /* Enable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 1U;

    /* Stop MTU channel 3 counter */
    MTU.TSTRA.BIT.CST3 = 0U;
    MTU.TSTRA.BIT.CST4 = 0U;

    /* Set external clock noise filter */
    MTU0.NFCRC.BIT.NFBEN = 0U;

    /* Set A/D conversion signal output for ADSM0, ADSM1 pins */
    MTU.TADSTRGR0.BYTE = _00_MTU_TADSTRS_NOSOURCE;
    MTU.TADSTRGR1.BYTE = _00_MTU_TADSTRS_NOSOURCE;

    /* Set TGIA4/TGIB4 interrupt priority level */
    IPR(MTU4, TGIA4) = _0F_MTU_PRIORITY_LEVEL15;

    /* MTU channel 3 is used as complementary PWM mode 3 */
    MTU3.TIER.BYTE = 0x00U;
    MTU4.TIER.BYTE = 0x00U;
    MTU.TITCR1A.BIT.T3AEN = 0U;
    MTU.TITCR1A.BIT.T4VEN = 0U;
    MTU3.TCR.BYTE = _00_MTU_PCLK_1 | _00_MTU_CKCL_DIS;
    MTU4.TCR.BYTE = _00_MTU_PCLK_1;
    MTU3.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU4.TCR2.BYTE = _00_MTU_PCLK_1;
    MTU.TGCRA.BYTE = _80_MTU_BDC_OUT;
    MTU3.TCNT = DEAD_TIME;
    MTU4.TCNT = 0x0000U;
    MTU.TSYRA.BIT.SYNC3 = 0U;
    MTU.TSYRA.BIT.SYNC4 = 0U;
    MTU3.TGRB = 0x0198;		//62.5kHz Setting
    MTU3.TGRD = 0x0198;
    MTU4.TGRA = 0x0000;
    MTU4.TGRC = 0x0000;
    MTU4.TGRB = 0x0000;
    MTU4.TGRD = 0x0000;
    MTU.TDERA.BIT.TDER = 1U;
    MTU.TDDRA = DEAD_TIME;
    MTU.TCDRA = 0x0280;
    MTU.TCBRA = 0x0280;
    MTU3.TGRA = 0x0330;
    MTU3.TGRC = 0x0330;		//62.5kHz Setting
    MTU.TOCR1A.BYTE = _00_MTU_PSYE_DISABLE | _08_MTU_TOCL_DISABLE | _04_MTU_TOCS_TOCR2;
    MTU.TOCR2A.BYTE = _00_MTU_TOLBR_DIS | _02_MTU_OLS1N_LH | _01_MTU_OLS1P_LH;
    MTU.TOLBRA.BYTE = MTU.TOCR2A.BYTE & 0x3FU;
    MTU3.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | 0x00;//_80_MTU_TTGE_ENABLE;
    MTU4.TIER.BYTE = _01_MTU_TGIEA_ENABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TCIEV_DISABLE | _00_MTU_TTGE2_DISABLE;
    MTU.TITMRA.BIT.TITM = 0U;
    MTU3.TMDR1.BYTE = _0D_MTU_CMT1/*_0F_MTU_CMT3*/ | _10_MTU_BFA_BUFFER | _20_MTU_BFB_BUFFER;
    MTU.TOERA.BYTE = _C0_MTU_OE4D_DISABLE | _C0_MTU_OE4C_DISABLE | _C8_MTU_OE3D_ENABLE | _C0_MTU_OE4B_DISABLE | 
                     _C0_MTU_OE4A_DISABLE | _C1_MTU_OE3B_ENABLE;

    /* Disable read/write to MTU3, MTU4 registers */
    MTU.TRWERA.BIT.RWE = 0U;

    /* Set MTIOC3B pin */
    MPC.P71PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x02U;

    /* Set MTIOC3D pin */
    MPC.P74PFS.BYTE = 0x01U;
    PORT7.PMR.BYTE |= 0x10U;
}

void MTU6Init()
{
	//P91, P94 : MTIOC7C, MTIOC7A Setting
	//Complementary PWM Mode for PWM
	
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
    MTU6.TSYCR.BYTE = 0x00;

    /* Set A/D conversion signal output for ADSM0, ADSM1 pins */
    MTU.TADSTRGR0.BYTE = _00_MTU_TADSTRS_NOSOURCE;
    MTU.TADSTRGR1.BYTE = _00_MTU_TADSTRS_NOSOURCE;

    /* Set TGIA7/TGIB7 interrupt priority level */
    IPR(MTU7, TGIA7) = _0F_MTU_PRIORITY_LEVEL15;

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
    MTU6.TCNT = DEAD_TIME;	//62.5kHz Setting
    MTU7.TCNT = 0x0000U;
    MTU.TSYRB.BIT.SYNC6 = 0U;
    MTU.TSYRB.BIT.SYNC7 = 0U;
    MTU6.TGRB = 0x0000;
    MTU6.TGRD = 0x0000;
    MTU7.TGRA = 0x0198;
    MTU7.TGRC = 0x0198;
    MTU7.TGRB = 0x0000;
    MTU7.TGRD = 0x0000;
    MTU.TDERB.BIT.TDER = 1U;
    MTU.TDDRB = DEAD_TIME;
    MTU.TCDRB = 0x0280;
    MTU.TCBRB = 0x0280;
    MTU6.TGRA = 0x0330;
    MTU6.TGRC = 0x0330;		//62.5kHz Setting
    MTU.TOCR1B.BYTE = _08_MTU_TOCL_DISABLE | _04_MTU_TOCS_TOCR2;
    MTU.TOCR2B.BYTE = _00_MTU_TOLBR_DIS | _08_MTU_OLS2N_LH | _04_MTU_OLS2P_LH;
    MTU.TOLBRB.BYTE = MTU.TOCR2B.BYTE & 0x3FU;
    MTU6.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TTGE_DISABLE;
    MTU7.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _02_MTU_TGIEB_ENABLE | _00_MTU_TCIEV_DISABLE | 0x00;//_40_MTU_TTGE2_ENABLE;
    MTU.TITMRB.BIT.TITM = 0U;
    MTU6.TMDR1.BYTE = _0D_MTU_CMT1 | _10_MTU_BFA_BUFFER | _20_MTU_BFB_BUFFER;
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
}

void ADC0Init()
{
	 /* Cancel S12AD0 module stop state */
    MSTP(S12AD) = 0U;

    /* Disable and clear interrupt flags of S12AD0 module */
    S12AD.ADCSR.BIT.ADIE = 0U;
    S12AD.ADCSR.BIT.GBADIE = 0U;
    S12AD.ADGCTRGR.BIT.GCADIE = 0U;
    IEN(S12AD, S12ADI) = 0U;
    IEN(S12AD, GBADI) = 0U;

    /* Set S12AD0 control registers */
    S12AD.ADDISCR.BYTE = _00_AD_DISCONECT_UNUSED;
    S12AD.ADCSR.WORD = _0040_AD_GBADI_ENABLE | _0000_AD_DBLTRIGGER_DISABLE | _0200_AD_SYNCASYNCTRG_ENABLE | 
                       _1000_AD_SCAN_END_INTERRUPT_ENABLE | _2000_AD_GROUP_SCAN_MODE;
    S12AD.ADGCTRGR.BYTE = _00_AD_GROUPC_DISABLE;
    S12AD.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_SELFTDIAGST_DISABLE | _0000_AD_RIGHT_ALIGNMENT;
    S12AD.ADADC.BYTE = _00_AD_1_TIME_CONVERSION | _00_AD_ADDITION_MODE;

    /* Set channels and sampling time */
    S12AD.ADANSA0.WORD = _0001_AD_ANx00_GROUPA_USED | _0002_AD_ANx01_GROUPA_USED;
    S12AD.ADANSB0.WORD = _0004_AD_ANx02_GROUPB_USED;
    S12AD.ADSSTR0 = _0D_AD0_SAMPLING_STATE_0;
    S12AD.ADSSTR1 = _0D_AD0_SAMPLING_STATE_1;
    S12AD.ADSSTR2 = _0D_AD0_SAMPLING_STATE_2;

    /* Set AD conversion start trigger sources */
    S12AD.ADSTRGR.WORD = _001E_AD_TRSB_TMTRG0AN_1 | _1D00_AD_TRSA_TMTRG0AN_0;
    S12AD.ADGSPCR.WORD = _0000_AD_GPAPRIORITY_DISABLE;

    /* Set interrupt and priority level */
    IPR(S12AD, S12ADI) = _0F_AD_PRIORITY_LEVEL15;
    IPR(S12AD, GBADI) = _0F_AD_PRIORITY_LEVEL15;
    IPR(S12AD, GCADI) = _0F_AD_PRIORITY_LEVEL15;

    /* Set AN000 pin */
    PORT4.PDR.BYTE &= 0xFEU;
    MPC.P40PFS.BYTE = 0x80U;

    /* Set AN001 pin */
    PORT4.PDR.BYTE &= 0xFDU;
    MPC.P41PFS.BYTE = 0x80U;

    /* Set AN002 pin */
    PORT4.PDR.BYTE &= 0xFBU;
    MPC.P42PFS.BYTE = 0x80U;
}

void ADC1Init()
{
	 /* Cancel S12AD1 module stop state */
    MSTP(S12AD1) = 0U;

    /* Disable and clear interrupt flags of S12AD1 module */
    S12AD1.ADCSR.BIT.ADIE = 0U;
    S12AD1.ADCSR.BIT.GBADIE = 0U;
    S12AD1.ADGCTRGR.BIT.GCADIE = 0U;
    IEN(S12AD1, S12ADI1) = 0U;
    IEN(S12AD1, GBADI1) = 0U;

    /* Set S12AD1 control registers */
    S12AD1.ADDISCR.BYTE = _00_AD_DISCONECT_UNUSED;
    S12AD1.ADCSR.WORD = _0040_AD_GBADI_ENABLE | _0000_AD_DBLTRIGGER_DISABLE | _0200_AD_SYNCASYNCTRG_ENABLE | 
                        _1000_AD_SCAN_END_INTERRUPT_ENABLE | _2000_AD_GROUP_SCAN_MODE;
    S12AD1.ADGCTRGR.BYTE = _00_AD_GROUPC_DISABLE;
    S12AD1.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_SELFTDIAGST_DISABLE | _0000_AD_RIGHT_ALIGNMENT;
    S12AD1.ADADC.BYTE = _00_AD_1_TIME_CONVERSION | _00_AD_ADDITION_MODE;

    /* Set channels and sampling time */
    S12AD1.ADANSA0.WORD = _0001_AD_ANx00_GROUPA_USED | _0002_AD_ANx01_GROUPA_USED;
    S12AD1.ADANSB0.WORD = _0004_AD_ANx02_GROUPB_USED;
    S12AD1.ADSSTR0 = _0D_AD1_SAMPLING_STATE_0;
    S12AD1.ADSSTR1 = _0D_AD1_SAMPLING_STATE_1;
    S12AD1.ADSSTR2 = _0D_AD1_SAMPLING_STATE_2;

    /* Set AD conversion start trigger sources */
    S12AD1.ADSTRGR.WORD = _001E_AD_TRSB_TMTRG0AN_1 | _1D00_AD_TRSA_TMTRG0AN_0;
    S12AD.ADGSPCR.WORD = _0000_AD_GPAPRIORITY_DISABLE;

    /* Set interrupt and priority level */
    IPR(S12AD1, S12ADI1) = _0F_AD_PRIORITY_LEVEL15;
    IPR(S12AD1, GBADI1) = _0F_AD_PRIORITY_LEVEL15;
    IPR(S12AD1, GCADI1) = _0F_AD_PRIORITY_LEVEL15;

    /* Set AN100 pin */
    PORT4.PDR.BYTE &= 0xEFU;
    MPC.P44PFS.BYTE = 0x80U;

    /* Set AN101 pin */
    PORT4.PDR.BYTE &= 0xDFU;
    MPC.P45PFS.BYTE = 0x80U;

    /* Set AN102 pin */
    PORT4.PDR.BYTE &= 0xBFU;
    MPC.P46PFS.BYTE = 0x80U;
}

void ADC2Init()
{
    /* Cancel S12AD2 module stop state */
    MSTP(S12AD2) = 0U;

    /* Disable and clear interrupt flags of S12AD2 module */
    S12AD2.ADCSR.BIT.ADIE = 0U;
    IEN(S12AD2, S12ADI2) = 0U;
    /* Set S12AD2 control registers */
    S12AD2.ADDISCR.BYTE = _00_AD_DISCONECT_UNUSED;
    S12AD2.ADCSR.WORD = _0000_AD_SYNC_TRIGGER | _0200_AD_SYNCASYNCTRG_ENABLE | _1000_AD_SCAN_END_INTERRUPT_ENABLE | 
                        _4000_AD_CONTINUOUS_SCAN_MODE;
    S12AD2.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_SELFTDIAGST_DISABLE | _0000_AD_RIGHT_ALIGNMENT;
    S12AD2.ADADC.BYTE = _00_AD_1_TIME_CONVERSION | _00_AD_ADDITION_MODE;

    /* Set channels and sampling time */
    S12AD2.ADANSA0.WORD = _0040_AD_ANx06_USED | _0080_AD_ANx07_USED | _0100_AD_ANx08_USED | _0200_AD_ANx09_USED | 
                          _0400_AD_ANx10_USED;
    S12AD2.ADSSTR6 = _0D_AD2_SAMPLING_STATE_6;
    S12AD2.ADSSTR7 = _0D_AD2_SAMPLING_STATE_7;
    S12AD2.ADSSTR8 = _0D_AD2_SAMPLING_STATE_8;
    S12AD2.ADSSTR9 = _0D_AD2_SAMPLING_STATE_9;
    S12AD2.ADSSTR10 = _0D_AD2_SAMPLING_STATE_10;

    /* Set AD conversion start trigger sources */
    S12AD2.ADSTRGR.WORD = _1D00_AD_TRSA_TMTRG0AN_0;

    /* Set interrupt and priority level */
    IPR(S12AD2, S12ADI2) = _0F_AD_PRIORITY_LEVEL15;

    /* Set AN206 pin */
    PORT5.PDR.BYTE &= 0xFEU;
    MPC.P50PFS.BYTE = 0x80U;

    /* Set AN207 pin */
    PORT5.PDR.BYTE &= 0xFDU;
    MPC.P51PFS.BYTE = 0x80U;

    /* Set AN208 pin */
    PORT5.PDR.BYTE &= 0xFBU;
    MPC.P52PFS.BYTE = 0x80U;

    /* Set AN209 pin */
    PORT5.PDR.BYTE &= 0xF7U;
    MPC.P53PFS.BYTE = 0x80U;

    /* Set AN210 pin */
    PORT5.PDR.BYTE &= 0xEFU;
    MPC.P54PFS.BYTE = 0x80U;
}

void MCUInit()
{
	TMRInit();
	CMTInit();
}

void PortInit()
{
    /* Set PORT2 registers */
    PORT2.PODR.BYTE = 0;//_02_Pm1_OUTPUT_1 | _04_Pm2_OUTPUT_1 | _08_Pm3_OUTPUT_1 | _10_Pm4_OUTPUT_1;
    PORT2.ODR0.BYTE = _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORT2.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT;
    PORT2.DSCR.BYTE = _00_Pm1_HIDRV_OFF | _00_Pm2_HIDRV_OFF | _00_Pm3_HIDRV_OFF | _00_Pm4_HIDRV_OFF;
    PORT2.PMR.BYTE = _00_Pm1_PIN_GPIO | _00_Pm2_PIN_GPIO | _00_Pm3_PIN_GPIO | _00_Pm4_PIN_GPIO;
    PORT2.PDR.BYTE = _02_Pm1_MODE_OUTPUT | _04_Pm2_MODE_OUTPUT | _08_Pm3_MODE_OUTPUT | _10_Pm4_MODE_OUTPUT | 
                     _01_PDR2_DEFAULT;
		     
		     
    /* Set PORT3 registers */
    PORT3.PODR.BYTE = 0;//_01_Pm0_OUTPUT_1 | _02_Pm1_OUTPUT_1;
    PORT3.ODR0.BYTE = _01_Pm0_NCH_OPEN_DRAIN | _04_Pm1_NCH_OPEN_DRAIN;//_00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT;
    PORT3.ODR1.BYTE = _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORT3.DSCR.BYTE = _00_Pm0_HIDRV_OFF | _00_Pm1_HIDRV_OFF;
    PORT3.PMR.BYTE = _00_Pm0_PIN_GPIO | _00_Pm1_PIN_GPIO;
    PORT3.PDR.BYTE = _01_Pm0_MODE_OUTPUT | _02_Pm1_MODE_OUTPUT | _0C_PDR3_DEFAULT;

    
    /* Set PORTB registers */
    PORTB.PODR.BYTE = 0;//_02_Pm1_OUTPUT_1;//_00_Pm1_OUTPUT_0;
    PORTB.ODR0.BYTE = _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORTB.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT | _00_Pm5_CMOS_OUTPUT | _00_Pm6_CMOS_OUTPUT;
    PORTB.PMR.BYTE = _00_Pm1_PIN_GPIO;
    PORTB.PDR.BYTE = _02_Pm1_MODE_OUTPUT | _81_PDRB_DEFAULT;
}

void MTUInit()
{
	MTU3Init();	//MTIOC3B, MTIOC3D Init
	MTU6Init();	//MTIOC7A, MTIOC7C Init
}

void IntInit()
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
   /* MPC.P31PFS.BYTE = 0x40U;
    PORT3.PDR.BYTE &= 0xFDU;
    PORT3.PMR.BYTE &= 0xFDU;*/

    /* Set IRQ7 pin */
   /* MPC.P30PFS.BYTE = 0x40U;
    PORT3.PDR.BYTE &= 0xFEU;
    PORT3.PMR.BYTE &= 0xFEU;*/

    /* Set IRQ detection type */
    ICU.IRQCR[1].BYTE = _04_ICU_IRQ_EDGE_FALLING;
    IR(ICU,IRQ1) = 0U;
    ICU.IRQCR[2].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;
    ICU.IRQCR[3].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;
 //   ICU.IRQCR[6].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;
 //   ICU.IRQCR[7].BYTE = _00_ICU_IRQ_EDGE_LOW_LEVEL;

    /* Set IRQ priority level */
    IPR(ICU,IRQ1) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ2) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ3) = _0F_ICU_PRIORITY_LEVEL15;
  //  IPR(ICU,IRQ6) = _0F_ICU_PRIORITY_LEVEL15;
  //  IPR(ICU,IRQ7) = _0F_ICU_PRIORITY_LEVEL15;
    
    
     /* Enable IRQ1 interrupt */
    IEN(ICU,IRQ1) = 1U;
}
void Sci1Init()
{
    /* Cancel SCI stop state */
    MSTP(SCI1) = 0U;

    /* Set interrupt priority */
    IPR(SCI1,TXI1) = _0F_SCI_PRIORITY_LEVEL15;

    /* Clear the control register */
    SCI1.SCR.BYTE = 0x00U;

    /* Set clock enable */
    SCI1.SCR.BYTE = _00_SCI_INTERNAL_SCK_UNUSED;

    /* Clear the SIMR1.IICM, SPMR.CKPH, and CKPOL bit, and set SPMR */
    SCI1.SIMR1.BIT.IICM = 0U;
    SCI1.SPMR.BYTE = _00_SCI_RTS | _00_SCI_CLOCK_NOT_INVERTED | _00_SCI_CLOCK_NOT_DELAYED;

    /* Set control registers */
    SCI1.SMR.BYTE = _01_SCI_CLOCK_PCLK_4 | _00_SCI_MULTI_PROCESSOR_DISABLE | _00_SCI_STOP_1 | _00_SCI_PARITY_DISABLE | 
                    _00_SCI_DATA_LENGTH_8 | _00_SCI_ASYNCHRONOUS_OR_I2C_MODE;
    SCI1.SCMR.BYTE = _00_SCI_SERIAL_MODE | _00_SCI_DATA_INVERT_NONE | _00_SCI_DATA_LSB_FIRST | 
                     _10_SCI_DATA_LENGTH_8_OR_7 | _62_SCI_SCMR_DEFAULT;
    SCI1.SEMR.BYTE = _00_SCI_BIT_MODULATION_DISABLE | _10_SCI_8_BASE_CLOCK | _00_SCI_NOISE_FILTER_DISABLE | 
                     _00_SCI_BAUDRATE_SINGLE | _00_SCI_LOW_LEVEL_START_BIT;

    /* Set bit rate */
    SCI1.BRR = 0x40U;

    /* Set RXD1 pin */
    MPC.PD5PFS.BYTE = 0x0AU;
    PORTD.PMR.BYTE |= 0x20U;

    /* Set TXD1 pin */
    MPC.PD3PFS.BYTE = 0x0AU;
    PORTD.PODR.BYTE |= 0x08U;
    PORTD.PDR.BYTE |= 0x08U;
}
void Sci5Init()	//UART to Controller
{
    /* Cancel SCI stop state */
    MSTP(SCI5) = 0U;

    /* Set interrupt priority */
    IPR(SCI5,TXI5) = _0F_SCI_PRIORITY_LEVEL15;

    /* Clear the control register */
    SCI5.SCR.BYTE = 0x00U;

    /* Set clock enable */
    SCI5.SCR.BYTE = _01_SCI_INTERNAL_SCK_OUTPUT;	//Unused

    /* Clear the SIMR1.IICM, SPMR.CKPH, and CKPOL bit, and set SPMR */
    SCI5.SIMR1.BIT.IICM = 0U;
    SCI5.SPMR.BYTE = _00_SCI_RTS | _00_SCI_CLOCK_NOT_INVERTED | _00_SCI_CLOCK_NOT_DELAYED;

    /* Set control registers */
    SCI5.SMR.BYTE = _01_SCI_CLOCK_PCLK_4 | _00_SCI_MULTI_PROCESSOR_DISABLE | _00_SCI_STOP_1 | _00_SCI_PARITY_DISABLE | 
                    _00_SCI_DATA_LENGTH_8 | _00_SCI_ASYNCHRONOUS_OR_I2C_MODE;
    SCI5.SCMR.BYTE = _00_SCI_SERIAL_MODE | _00_SCI_DATA_INVERT_NONE | _00_SCI_DATA_LSB_FIRST | 
                     _10_SCI_DATA_LENGTH_8_OR_7 | _62_SCI_SCMR_DEFAULT;
    SCI5.SEMR.BYTE = _00_SCI_BIT_MODULATION_DISABLE | _10_SCI_8_BASE_CLOCK | _00_SCI_NOISE_FILTER_DISABLE | 
                     _00_SCI_BAUDRATE_SINGLE | _80_SCI_FALLING_EDGE_START_BIT;		//0x00;

    /* Set bit rate */
    SCI5.BRR = 0x40U;

    /* Set RXD5 pin */
    MPC.PB6PFS.BYTE = 0x0AU;
    PORTB.PMR.BYTE |= 0x40U;

    /* Set TXD5 pin */
    MPC.PB5PFS.BYTE = 0x0AU;
    PORTB.PODR.BYTE |= 0x20U;
    PORTB.PDR.BYTE |= 0x20U;
}

void SciInit()
{
	//Sci1Init();
	Sci5Init();
}

void ADCInit()
{
	ADC0Init();
	ADC1Init();
	ADC2Init();
}

void Init()
{
 /* Enable writing to registers related to operating modes, LPC, CGC, software reset and LVD */
   	SYSTEM.PRCR.WORD = 0xA50FU;
 /* Enable writing to MPC pin function control registers */
  	 MPC.PWPR.BIT.B0WI = 0U;
   	 MPC.PWPR.BIT.PFSWE = 1U;

 /* Write 0 to the target bits in the POECR2 registers */
   	POE.POECR2.WORD = 0x0000U;
	
	MCUInit();
	PortInit();
	MTUInit();
	IntInit();
	SciInit();
	ADCInit();
	
 /* Disable writing to MPC pin function control registers */
   	MPC.PWPR.BIT.PFSWE = 0U;
   	MPC.PWPR.BIT.B0WI = 1U;

 /* Enable protection */
   	SYSTEM.PRCR.WORD = 0xA500U;
}