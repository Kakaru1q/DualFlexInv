/***********************************************************************/
/*                                                                     */
/*  FILE        :Init.h                     			       */
/*  DATE        :Thur, Aug 19, 2021                                    */
/*  DESCRIPTION :Initial Function	                               */
/*  CPU TYPE    :RX24T                                                 */
/*  MADE BY	:P.W.K                                                 */
/*                                     				       */
/*                                                                     */
/***********************************************************************/



void MCUInit(void);
void PortInit(void);
void MTUInit(void);
void IntInit(void);
void SciInit(void);
void ADCInit(void);

void Init(void);


////////TMR Define
/*
    Timer Control Register (TCR)
*/
/* Counter Clear (CCLR[1:0]) */
#define _00_TMR_CNT_CLR_DISABLE                     (0x00U) /* Clearing is disabled */
#define _08_TMR_CNT_CLR_COMP_MATCH_A                (0x08U) /* Cleared by compare match A */
/* Timer Overflow Interrupt Enable (OVIE) */
#define _00_TMR_OVI_INT_DISABLE                     (0x00U) /* Overflow interrupt requests (OVIn) are disabled */
/* Compare Match Interrupt Enable A (CMIEA) */
#define _00_TMR_CMIA_INT_DISABLE                    (0x00U) /* Compare match A interrupt (CMIAn) are disabled */
#define _40_TMR_CMIA_INT_ENABLE                     (0x40U) /* Compare match A interrupt (CMIAn) are enabled */
/* Compare Match Interrupt Enable B (CMIEB) */
#define _00_TMR_CMIB_INT_DISABLE                    (0x00U) /* Compare match B interrupt (CMIBn) are disabled */
#define _80_TMR_CMIB_INT_ENABLE                     (0x80U) /* Compare match B interrupt (CMIBn) are enabled */
/*
    Timer Control/Status Register (TCSR)
*/
/* A/D Trigger Enable (ADTE) */
#define _00_TMR_AD_TRIGGER_DISABLE                  (0x00U) /* A/D start request at compare match A disabled */
#define _10_TMR_AD_TRIGGER_ENABLE                   (0x10U) /* A/D start request at compare match A enabled */
#define _E0_TMR0246_TCSR_DEFAULT                    (0xE0U) /* Default TCSR write value for TMR0/2/4/6 */
#define _F0_TMR1357_TCSR_DEFAULT                    (0xF0U) /* Default TCSR write value for TMR1/3/5/7 */

/* Interrupt Priority Level Select (IPR[3:0]) */
#define _0F_TMR_PRIORITY_LEVEL15                    (0x0FU) /* Level 15 (highest) */



////////CMT Define
/*
    Compare Match Timer Control Register (CMCR)
*/
/* Clock Select (CKS[1:0]) */
#define _0000_CMT_CMCR_CLOCK_PCLK8              (0x0000U) /* PCLK/8 */
#define _0001_CMT_CMCR_CLOCK_PCLK32             (0x0001U) /* PCLK/32 */
#define _0002_CMT_CMCR_CLOCK_PCLK128            (0x0002U) /* PCLK/128 */
#define _0003_CMT_CMCR_CLOCK_PCLK512            (0x0003U) /* PCLK/512 */
/* Compare Match Interrupt Enable (CMIE) */
#define _0000_CMT_CMCR_CMIE_DISABLE             (0x0000U) /* Compare match interrupt(CMIn) disabled */
#define _0040_CMT_CMCR_CMIE_ENABLE              (0x0040U) /* Compare match interrupt(CMIn) enabled */
#define _0080_CMT_CMCR_DEFAULT                  (0x0080U) /* Write default value of CMCR */
/* Compare Match Constant Register (CMCOR) */
#define _001E_CMT0_CMCOR_VALUE              (0x001EU)
/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _0F_CMT_PRIORITY_LEVEL15                 (0x0FU) /* Level 15 (highest) */


////////MTU Define

/* Time Pre-scaler Select (TPSC[2:0]) */
#define _00_MTU_PCLK_1                  (0x00U) /* Internal clock: counts on PCLK/1 (for all channels) */
#define _01_MTU_PCLK_4                  (0x01U) /* Internal clock: counts on PCLK/4 (for all channels) */
#define _02_MTU_PCLK_16                 (0x02U) /* Internal clock: counts on PCLK/16 (for all channels) */
#define _03_MTU_PCLK_64                 (0x03U) /* Internal clock: counts on PCLK/64 (for all channels) */
/* Time Pre-scaler Select (TPSC2[2:0]) */
#define _01_MTU_PCLK_2                  (0x01U) /* Internal clock: counts on PCLK/2 (for all channels) */
#define _02_MTU_PCLK_8                  (0x02U) /* Internal clock: counts on PCLK/8 (for all channels) */
#define _03_MTU_PCLK_32                 (0x03U) /* Internal clock: counts on PCLK/32 (for all channels) */

/* Clock Edge Select (CKEG[1:0]) */
#define _00_MTU_CKEG_RISE               (0x00U) /* Count at rising edge */
#define _08_MTU_CKEG_FALL               (0x08U) /* Count at falling edge */
#define _10_MTU_CKEG_BOTH               (0x10U) /* Count at both edges */
/* Counter Clear Select (CCLR[2:0]) */
#define _00_MTU_CKCL_DIS                (0x00U) /* TCNT clearing disabled */
#define _20_MTU_CKCL_A                  (0x20U) /* TCNT cleared by TGRA compare match/input capture */
#define _40_MTU_CKCL_B                  (0x40U) /* TCNT cleared by TGRB compare match/input capture */
#define _60_MTU_CKCL_SYN                (0x60U) /* TCNT cleared by counter clearing in another synchronous channel */
#define _A0_MTU_CKCL_C                  (0xA0U) /* TCNT cleared by TGRC compare match/input capture */
#define _C0_MTU_CKCL_D                  (0xC0U) /* TCNT cleared by TGRD compare match/input capture */

/*
    Timer Mode Register 1 (TMDR1)
*/
/* Mode Select (MD[3:0]) */
#define _00_MTU_NORMAL                  (0x00U) /* Normal mode */
#define _02_MTU_PWM1                    (0x02U) /* PWM mode 1 */
#define _03_MTU_PWM2                    (0x03U) /* PWM mode 2 */
#define _08_MTU_REST                    (0x08U) /* Reset-synchronized PWM mode */
#define _0D_MTU_CMT1                    (0x0DU) /* Complementary PWM mode 1 (transfer at crest) */
#define _0E_MTU_CMT2                    (0x0EU) /* Complementary PWM mode 2 (transfer at trough) */
#define _0F_MTU_CMT3                    (0x0FU) /* Complementary PWM mode 3 (transfer at crest and trough) */
/* Buffer Operation A (BFA) */
#define _00_MTU_BFA_NORMAL              (0x00U) /* TGRA and TGRC operate normally */
#define _10_MTU_BFA_BUFFER              (0x10U) /* TGRA and TGRC used together for buffer operation */
/* Buffer Operation B (BFB) */
#define _00_MTU_BFB_NORMAL              (0x00U) /* TGRB and TGRD operate normally */
#define _20_MTU_BFB_BUFFER              (0x20U) /* TGRB and TGRD used together for buffer operation */
/* Buffer Operation E (BFE) */
#define _00_MTU_BFE_NORMAL              (0x00U) /* TGRE and TGRF operate normally */
#define _40_MTU_BFE_BUFFER              (0x40U) /* TGRE and TGRF used together for buffer operation */

/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _0F_MTU_PRIORITY_LEVEL15        (0x0FU) /* Level 15 (highest) */


/* A/D Conversion Start Request Select for ADSMn Pin Output Frame Synchronization Signal Generation (TADSTRSn[4:0]) */
#define _00_MTU_TADSTRS_NOSOURCE        (0x00U) /* Source not selected */

/*
    Timer Output Master Enable Registers (TOERA)
*/
/* Master Enable MTIOC3B (OE3B) */
#define _C0_MTU_OE3B_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C1_MTU_OE3B_ENABLE             (0xC1U) /* MTU output is enabled */
/* Master Enable MTIOC4A (OE4A) */
#define _C0_MTU_OE4A_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C2_MTU_OE4A_ENABLE             (0xC2U) /* MTU output is enabled */
/* Master Enable MTIOC4B (OE4B) */
#define _C0_MTU_OE4B_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C4_MTU_OE4B_ENABLE             (0xC4U) /* MTU output is enabled */
/* Master Enable MTIOC3D (OE3D) */
#define _C0_MTU_OE3D_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C8_MTU_OE3D_ENABLE             (0xC8U) /* MTU output is enabled */
/* Master Enable MTIOC4C (OE4C) */
#define _C0_MTU_OE4C_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _D0_MTU_OE4C_ENABLE             (0xD0U) /* MTU output is enabled */
/* Master Enable MTIOC4D (OE4D) */
#define _C0_MTU_OE4D_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _E0_MTU_OE4D_ENABLE             (0xE0U) /* MTU output is enabled */
/*
    Timer Output Master Enable Registers (TOERB)
*/
/* Master Enable MTIOC6B (OE6B) */
#define _C0_MTU_OE6B_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C1_MTU_OE6B_ENABLE             (0xC1U) /* MTU output is enabled */
/* Master Enable MTIOC7A (OE7A) */
#define _C0_MTU_OE7A_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C2_MTU_OE7A_ENABLE             (0xC2U) /* MTU output is enabled */
/* Master Enable MTIOC7B (OE7B) */
#define _C0_MTU_OE7B_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C4_MTU_OE7B_ENABLE             (0xC4U) /* MTU output is enabled */
/* Master Enable MTIOC6D (OE6D) */
#define _C0_MTU_OE6D_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _C8_MTU_OE6D_ENABLE             (0xC8U) /* MTU output is enabled */
/* Master Enable MTIOC7C (OE7C) */
#define _C0_MTU_OE7C_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _D0_MTU_OE7C_ENABLE             (0xD0U) /* MTU output is enabled */
/* Master Enable MTIOC7D (OE7D) */
#define _C0_MTU_OE7D_DISABLE            (0xC0U) /* MTU output is disabled (inactive level) */
#define _E0_MTU_OE7D_ENABLE             (0xE0U) /* MTU output is enabled */


/* TGR Interrupt Enable A (TGIEA) */
#define _00_MTU_TGIEA_DISABLE           (0x00U) /* Interrupt requests TGIA disabled */
#define _01_MTU_TGIEA_ENABLE            (0x01U) /* Interrupt requests TGIA enabled */
/* TGR Interrupt Enable B (TGIEB) */
#define _00_MTU_TGIEB_DISABLE           (0x00U) /* Interrupt requests TGIB disabled */
#define _02_MTU_TGIEB_ENABLE            (0x02U) /* Interrupt requests TGIB enabled */
/* TGR Interrupt Enable C (TGIEC) */
#define _00_MTU_TGIEC_DISABLE           (0x00U) /* Interrupt requests TGIC disabled */
#define _04_MTU_TGIEC_ENABLE            (0x04U) /* Interrupt requests TGIC enabled */
/* TGR Interrupt Enable D (TGIED) */
#define _00_MTU_TGIED_DISABLE           (0x00U) /* Interrupt requests TGID disabled */
#define _08_MTU_TGIED_ENABLE            (0x08U) /* Interrupt requests TGID enabled */
/* Overflow Interrupt Enable (TCIEV) */
#define _00_MTU_TCIEV_DISABLE           (0x00U) /* Interrupt requests TCIV disabled */
#define _10_MTU_TCIEV_ENABLE            (0x10U) /* Interrupt requests TCIV enabled */
/* Underflow Interrupt Enable (TCIEU) */
#define _00_MTU_TCIEU_DISABLE           (0x00U) /* Interrupt requests TCIU disabled */
#define _20_MTU_TCIEU_ENABLE            (0x20U) /* Interrupt requests TCIU enabled */
/* A/D Converter Start Request Enable 2 (TTGE2) */
#define _00_MTU_TTGE2_DISABLE           (0x00U) /* A/D converter start request by MTU4,7.TCNT disabled */
#define _40_MTU_TTGE2_ENABLE            (0x40U) /* A/D converter start request by MTU4,7.TCNT enabled */
/* A/D Converter Start Request Enable (TTGE) */
#define _00_MTU_TTGE_DISABLE            (0x00U) /* A/D converter start request generation disabled */
#define _80_MTU_TTGE_ENABLE             (0x80U) /* A/D converter start request generation enabled */

/*
    Timer Output Control Registers 1 (TOCR1A, TOCR1B)
*/
/* Output Level Select P (OLSP) */
#define _00_MTU_OLSP_HL                 (0x00U) /* Initial output:H, Active level:L */
#define _01_MTU_OLSP_LH                 (0x01U) /* Initial output:L, Active level:H */
/* Output Level Select N (OLSN) */
#define _00_MTU_OLSN_HL                 (0x00U) /* Initial output:H, Active level:L */
#define _02_MTU_OLSN_LH                 (0x02U) /* Initial output:L, Active level:H */
/* TOC Select (TOCS) */
#define _00_MTU_TOCS_TOCR1              (0x00U) /* TOCR1 setting is selected */
#define _04_MTU_TOCS_TOCR2              (0x04U) /* TOCR2 setting is selected */
/* TOC Register Write Protection (TOCL) */
#define _00_MTU_TOCL_ENABLE             (0x00U) /* Write access to the TOCS, OLSN, and OLSP bits is enabled */
#define _08_MTU_TOCL_DISABLE            (0x08U) /* Write access to the TOCS, OLSN, and OLSP bits is disabled */
/* PWM Synchronous Output Enable (PSYE) */
#define _00_MTU_PSYE_DISABLE            (0x00U) /* Toggle output is disabled */
#define _40_MTU_PSYE_ENABLE             (0x40U) /* Toggle output is enabled */

/*
    Timer Output Control Registers 2 (TOCR2A, TOCR2B)
*/
/* Output Level Select 1P (OLS1P) */
#define _00_MTU_OLS1P_HL                (0x00U) /* Initial output:H, Active level:L */
#define _01_MTU_OLS1P_LH                (0x01U) /* Initial output:L, Active level:H */
/* Output Level Select 1N (OLS1N) */
#define _00_MTU_OLS1N_HL                (0x00U) /* Initial output:H, Active level:L */
#define _02_MTU_OLS1N_LH                (0x02U) /* Initial output:L, Active level:H */
/* Output Level Select 2P (OLS2P) */
#define _00_MTU_OLS2P_HL                (0x00U) /* Initial output:H, Active level:L */
#define _04_MTU_OLS2P_LH                (0x04U) /* Initial output:L, Active level:H */
/* Output Level Select 2N (OLS2N) */
#define _00_MTU_OLS2N_HL                (0x00U) /* Initial output:H, Active level:L */
#define _08_MTU_OLS2N_LH                (0x08U) /* Initial output:L, Active level:H */
/* Output Level Select 3P (OLS3P) */
#define _00_MTU_OLS3P_HL                (0x00U) /* Initial output:H, Active level:L */
#define _10_MTU_OLS3P_LH                (0x10U) /* Initial output:L, Active level:H */
/* Output Level Select 3N (OLS3N) */
#define _00_MTU_OLS3N_HL                (0x00U) /* Initial output:H, Active level:L */
#define _20_MTU_OLS3N_LH                (0x20U) /* Initial output:L, Active level:H */
/* TOLBR Buffer Transfer Timing Select (BF[1:0]) */
#define _00_MTU_TOLBR_DIS               (0x00U) /* Does not transfer data from the buffer register (TOLBR) to TOCR2 */
#define _40_MTU_TOLBR_C                 (0x40U) /* Transfers at the crest of the MTU4,7.TCNT count */
#define _80_MTU_TOLBR_T                 (0x80U) /* Transfers at the trough of the MTU4,7.TCNT count */
#define _C0_MTU_TOLBR_CT                (0xC0U) /* Transfers at crest and trough of the MTU4,7.TCNT count */

/*
    Timer I/O Control Register (TIOR)
*/
/* I/O Control A (IOA[3:0]) */
#define _00_MTU_IOA_DISABLE             (0x00U) /* Output prohibited */
#define _01_MTU_IOA_LL                  (0x01U) /* Initial output is low. Low output at compare match */
#define _02_MTU_IOA_LH                  (0x02U) /* Initial output is low. High output at compare match */
#define _03_MTU_IOA_LT                  (0x03U) /* Initial output is low. Toggle output at compare match */
#define _05_MTU_IOA_HL                  (0x05U) /* Initial output is high. Low output at compare match */
#define _06_MTU_IOA_HH                  (0x06U) /* Initial output is high. High output at compare match */
#define _07_MTU_IOA_HT                  (0x07U) /* Initial output is high. Toggle output at compare match */
#define _08_MTU_IOA_IR                  (0x08U) /* Input capture at rising edge */
#define _09_MTU_IOA_IF                  (0x09U) /* Input capture at falling edge */
#define _0A_MTU_IOA_IB                  (0x0AU) /* Input capture at both edges */
#define _0C_MTU_IOA_EX                  (0x0CU) /* Input capture at MTU1.TCNT or MTU2.TCNT up-count/down-count */
#define _0D_MTU_IOA_TGRA                (0x0DU) /* Input capture at MTU0.TGRA compare match/input capture */
/* I/O Control B (IOB[3:0]) */
#define _00_MTU_IOB_DISABLE             (0x00U) /* Output prohibited */
#define _10_MTU_IOB_LL                  (0x10U) /* Initial output is low. Low output at compare match */
#define _20_MTU_IOB_LH                  (0x20U) /* Initial output is low. High output at compare match */
#define _30_MTU_IOB_LT                  (0x30U) /* Initial output is low. Toggle output at compare match */
#define _50_MTU_IOB_HL                  (0x50U) /* Initial output is high. Low output at compare match */
#define _60_MTU_IOB_HH                  (0x60U) /* Initial output is high. High output at compare match */
#define _70_MTU_IOB_HT                  (0x70U) /* Initial output is high. Toggle output at compare match */
#define _80_MTU_IOB_IR                  (0x80U) /* Input capture at rising edge */
#define _90_MTU_IOB_IF                  (0x90U) /* Input capture at falling edge */
#define _A0_MTU_IOB_IB                  (0xA0U) /* Input capture at both edges */
#define _C0_MTU_IOB_EX                  (0xC0U) /* Input capture at MTU1.TCNT or MTU2.TCNT  up-count/down-count */
#define _C0_MTU_IOB_TGRC0               (0xC0U) /* Input capture at MTU0.TGRC compare match/input capture */
/* I/O Control C (IOC[3:0]) for MTUn.TIORL (n=0,3,4,6,7,9) */
#define _00_MTU_IOC_DISABLE             (0x00U) /* Output prohibited */
#define _01_MTU_IOC_LL                  (0x01U) /* Initial output is low. Low output at compare match */
#define _02_MTU_IOC_LH                  (0x02U) /* Initial output is low. High output at compare match */
#define _03_MTU_IOC_LT                  (0x03U) /* Initial output is low. Toggle output at compare match */
#define _05_MTU_IOC_HL                  (0x05U) /* Initial output is high. Low output at compare match */
#define _06_MTU_IOC_HH                  (0x06U) /* Initial output is high. High output at compare match */
#define _07_MTU_IOC_HT                  (0x07U) /* Initial output is high. Toggle output at compare match */
#define _08_MTU_IOC_IR                  (0x08U) /* Input capture at rising edge */
#define _09_MTU_IOC_IF                  (0x09U) /* Input capture at falling edge */
#define _0A_MTU_IOC_IB                  (0x0AU) /* Input capture at both edges */
#define _0C_MTU_IOC_EX                  (0x0CU) /* Input capture at MTU1.TCNT or MTU2.TCNT up-count/down-count */

/* I/O Control D (IOD[3:0]) */
#define _00_MTU_IOD_DISABLE             (0x00U) /* Output prohibited */
#define _10_MTU_IOD_LL                  (0x10U) /* Initial output is low. Low output at compare match */
#define _20_MTU_IOD_LH                  (0x20U) /* Initial output is low. High output at compare match */
#define _30_MTU_IOD_LT                  (0x30U) /* Initial output is low. Toggle output at compare match */
#define _50_MTU_IOD_HL                  (0x50U) /* Initial output is high. Low output at compare match */
#define _60_MTU_IOD_HH                  (0x60U) /* Initial output is high. High output at compare match */
#define _70_MTU_IOD_HT                  (0x70U) /* Initial output is high. Toggle output at compare match */
#define _80_MTU_IOD_IR                  (0x80U) /* Input capture at rising edge */
#define _90_MTU_IOD_IF                  (0x90U) /* Input capture at falling edge */
#define _A0_MTU_IOD_IB                  (0xA0U) /* Input capture at both edges */
#define _C0_MTU_IOD_EX                  (0xC0U) /* Input capture at MTU1.TCNT or MTU2.TCNT up-count/down-count */

/* Brushless DC Motor (BDC) */
#define _80_MTU_BDC_OUT                 (0x80U) /* Ordinary output */


////ISR Define
/* IRQi Digital Filter Enable (FLTENi) (i = 0 to 7) */
#define _00_ICU_IRQn_FILTER_DISABLE             (0x00U) /* IRQi digital filter is disabled */
#define _01_ICU_IRQ0_FILTER_ENABLE              (0x01U) /* IRQ0 digital filter is enabled */
#define _02_ICU_IRQ1_FILTER_ENABLE              (0x02U) /* IRQ1 digital filter is enabled */
#define _04_ICU_IRQ2_FILTER_ENABLE              (0x04U) /* IRQ2 digital filter is enabled */
#define _08_ICU_IRQ3_FILTER_ENABLE              (0x08U) /* IRQ3 digital filter is enabled */
#define _10_ICU_IRQ4_FILTER_ENABLE              (0x10U) /* IRQ4 digital filter is enabled */
#define _20_ICU_IRQ5_FILTER_ENABLE              (0x20U) /* IRQ5 digital filter is enabled */
#define _40_ICU_IRQ6_FILTER_ENABLE              (0x40U) /* IRQ6 digital filter is enabled */
#define _80_ICU_IRQ7_FILTER_ENABLE              (0x80U) /* IRQ7 digital filter is enabled */

/* IRQ Detection Sense Select (IRQMD[1:0]) */
#define _00_ICU_IRQ_EDGE_LOW_LEVEL              (0x00U) /* Low level */
#define _04_ICU_IRQ_EDGE_FALLING                (0x04U) /* Falling edge */
#define _08_ICU_IRQ_EDGE_RISING                 (0x08U) /* Rising edge */
#define _0C_ICU_IRQ_EDGE_BOTH                   (0x0CU) /* Rising and falling edges */

/* Interrupt Priority Level Select (IPR[3:0]) */
#define _0F_ICU_PRIORITY_LEVEL15                (0x0FU) /* Level 15 (highest) */

/* A/D Conversion Start Request Select for ADSMn Pin Output Frame Synchronization Signal Generation (TADSTRSn[4:0]) */
#define _00_MTU_TADSTRS_NOSOURCE        (0x00U) /* Source not selected */


////ADC Define

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
    A/D Disconnection Detection Control Register (ADDISCR)
*/
#define _00_AD_DISCONECT_UNUSED              (0x00U) /* Detection detection control unused */


/* Group C A/D Conversion Operation Enable (GRCE) */
#define _00_AD_GROUPC_DISABLE                (0x00U)   /* A/D conversion operation for group C is disabled */
#define _80_AD_GROUPC_ENABLE                 (0x80U)   /* A/D conversion operation for group C is enabled */


/*
    A/D Control Extended Register (ADCER)
*/
/* A/D Data Register Automatic Clearing Enable (ACE) */
#define _0000_AD_AUTO_CLEARING_DISABLE       (0x0000U) /* Disable auto clearing */
#define _0020_AD_AUTO_CLEARING_ENABLE        (0x0020U) /* Enable auto clearing */
/* Self-Diagnosis Enable (DIAGM) */
#define _0000_AD_SELFTDIAGST_DISABLE         (0x0000U) /* 12-bit A/D converter self-diagnosis disable */
#define _0800_AD_SELFTDIAGST_ENABLE          (0x0800U) /* 12-bit A/D converter self-diagnosis enable */
/* A/D Data Register Format Select (ADRFMT) */
#define _0000_AD_RIGHT_ALIGNMENT             (0x0000U) /* Right-alignment for data register format */
#define _8000_AD_LEFT_ALIGNMENT              (0x8000U) /* Left-alignment for data register format */
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
    A/D Channel Select Register A0 (ADANSA0)
*/
#define _0001_AD_ANx00_USED                  (0x0001U) /* ANx00 is subjected to conversion */
#define _0001_AD_ANx00_GROUPA_USED           (0x0001U) /* ANx00 is subjected to group A conversion */
#define _0002_AD_ANx01_USED                  (0x0002U) /* ANx01 is subjected to conversion */
#define _0002_AD_ANx01_GROUPA_USED           (0x0002U) /* ANx01 is subjected to group A conversion */
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
/*
    A/D Channel Select Register B0 (ADANSB0)
*/
#define _0001_AD_ANx00_GROUPB_USED           (0x0001U) /* ANx00 is subjected to group B conversion */
#define _0002_AD_ANx01_GROUPB_USED           (0x0002U) /* ANx01 is subjected to group B conversion */
#define _0004_AD_ANx02_GROUPB_USED           (0x0004U) /* ANx02 is subjected to group B conversion */
/*
    A/D Conversion Start Trigger Select Register (ADSTRGR)
*/
#define _0004_AD_TRSB_TRGA3N                 (0x0004U) /* Compare match with or input capture to MTU3.TGRA */
#define _0007_AD_TRSB_TRGA7N                 (0x0007U) /* Compare match with or input capture to MTU7.TGRA or, 
                                                          an underflow of MTU7.TCNT (in the trough) */ 
#define _1D00_AD_TRSA_TMTRG0AN_0             (0x1D00U) /* Compare match between TMR0.TCORA and TMR0.TCNT */
#define _001E_AD_TRSB_TMTRG0AN_1             (0x001EU) /* Compare match between TMR2.TCORA and TMR2.TCNT */

/*
    A/D Group Scan Priority Control Register (ADGSPCR)
*/
/* Group Priority Control Setting (PGS) */
#define _0000_AD_GPAPRIORITY_DISABLE         (0x0000U) /* Operation is without group A priority control */

/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _0F_AD_PRIORITY_LEVEL15              (0x0FU) /* Level 15 (highest) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _0D_AD0_SAMPLING_STATE_0           (0x0DU)   /* AN000/Self-diagnosis sampling time setting */
#define _0D_AD0_SAMPLING_STATE_1           (0x0DU)   /* AN001 sampling time setting */
#define _0D_AD0_SAMPLING_STATE_2           (0x0DU)   /* AN002 sampling time setting */
#define _0D_AD1_SAMPLING_STATE_0           (0x0DU)   /* AN100/Self-diagnosis sampling time setting */
#define _0D_AD1_SAMPLING_STATE_1           (0x0DU)   /* AN101 sampling time setting */
#define _0D_AD1_SAMPLING_STATE_2           (0x0DU)   /* AN102 sampling time setting */
#define _0D_AD2_SAMPLING_STATE_6           (0x0DU)   /* AN206 sampling time setting */
#define _0D_AD2_SAMPLING_STATE_7           (0x0DU)   /* AN207 sampling time setting */
#define _0D_AD2_SAMPLING_STATE_8           (0x0DU)   /* AN208 sampling time setting */
#define _0D_AD2_SAMPLING_STATE_9           (0x0DU)   /* AN209 sampling time setting */
#define _0D_AD2_SAMPLING_STATE_10          (0x0DU)   /* AN210 sampling time setting */


/////Port Define

/*
    Port Output Data Register (PODR)
*/
/* Pmn Output Data Store (B7 - B0) */
#define _00_Pm0_OUTPUT_0        (0x00U) /* output low at B0 */
#define _01_Pm0_OUTPUT_1        (0x01U) /* output high at B0 */
#define _00_Pm1_OUTPUT_0        (0x00U) /* output low at B1 */
#define _02_Pm1_OUTPUT_1        (0x02U) /* output high at B1 */
#define _00_Pm2_OUTPUT_0        (0x00U) /* output low at B2 */
#define _04_Pm2_OUTPUT_1        (0x04U) /* output high at B2 */
#define _00_Pm3_OUTPUT_0        (0x00U) /* output low at B3 */
#define _08_Pm3_OUTPUT_1        (0x08U) /* output high at B3 */
#define _00_Pm4_OUTPUT_0        (0x00U) /* output low at B4 */
#define _10_Pm4_OUTPUT_1        (0x10U) /* output high at B4 */
#define _00_Pm5_OUTPUT_0        (0x00U) /* output low at B5 */
#define _20_Pm5_OUTPUT_1        (0x20U) /* output high at B5 */
#define _00_Pm6_OUTPUT_0        (0x00U) /* output low at B6 */
#define _40_Pm6_OUTPUT_1        (0x40U) /* output high at B6 */
#define _00_Pm7_OUTPUT_0        (0x00U) /* output low at B7 */
#define _80_Pm7_OUTPUT_1        (0x80U) /* output high at B7 */
/*
    Open Drain Control Register 0 (ODR0)
*/
/* Pmn Output Type Select (Pm0 to Pm3) */
#define _00_Pm0_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _01_Pm0_NCH_OPEN_DRAIN  (0x01U) /* N-channel open-drain output */
#define _00_Pm1_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _04_Pm1_NCH_OPEN_DRAIN  (0x04U) /* N-channel open-drain output */
#define _00_Pm2_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _10_Pm2_NCH_OPEN_DRAIN  (0x10U) /* N-channel open-drain output */
#define _00_Pm3_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _40_Pm3_NCH_OPEN_DRAIN  (0x40U) /* N-channel open-drain output */
/*
    Open Drain Control Register 1 (ODR1)
*/
/* Pmn Output Type Select (Pm4 to Pm7) */
#define _00_Pm4_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _01_Pm4_NCH_OPEN_DRAIN  (0x01U) /* N-channel open-drain output */
#define _00_Pm5_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _04_Pm5_NCH_OPEN_DRAIN  (0x04U) /* N-channel open-drain output */
#define _00_Pm6_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _10_Pm6_NCH_OPEN_DRAIN  (0x10U) /* N-channel open-drain output */
#define _00_Pm7_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _40_Pm7_NCH_OPEN_DRAIN  (0x40U) /* N-channel open-drain output */
/*
    Drive Capacity Control Register (DSCR)
*/
/* Pmn Drive Capacity Control (B7 - B0) */
#define _00_Pm0_HIDRV_OFF       (0x00U) /* Pm0 Normal drive output */
#define _01_Pm0_HIDRV_ON        (0x01U) /* Pm0 High-drive output */
#define _00_Pm1_HIDRV_OFF       (0x00U) /* Pm1 Normal drive output */
#define _02_Pm1_HIDRV_ON        (0x02U) /* Pm1 High-drive output */
#define _00_Pm2_HIDRV_OFF       (0x00U) /* Pm2 Normal drive output */
#define _04_Pm2_HIDRV_ON        (0x04U) /* Pm2 High-drive output */
#define _00_Pm3_HIDRV_OFF       (0x00U) /* Pm3 Normal drive output */
#define _08_Pm3_HIDRV_ON        (0x08U) /* Pm3 High-drive output */
#define _00_Pm4_HIDRV_OFF       (0x00U) /* Pm4 Normal drive output */
#define _10_Pm4_HIDRV_ON        (0x10U) /* Pm4 High-drive output */
#define _00_Pm5_HIDRV_OFF       (0x00U) /* Pm5 Normal drive output */
#define _20_Pm5_HIDRV_ON        (0x20U) /* Pm5 High-drive output */
#define _00_Pm6_HIDRV_OFF       (0x00U) /* Pm6 Normal drive output */
#define _40_Pm6_HIDRV_ON        (0x40U) /* Pm6 High-drive output */
#define _00_Pm7_HIDRV_OFF       (0x00U) /* Pm7 Normal drive output */
#define _80_Pm7_HIDRV_ON        (0x80U) /* Pm7 High-drive output */
/*
    Port Mode Register (PMR)
*/
/* Pmn Pin Mode Control (B7 -B0) */
#define _00_Pm0_PIN_GPIO        (0x00U) /* Pm0 as general I/O pin */
#define _00_Pm1_PIN_GPIO        (0x00U) /* Pm1 as general I/O pin */
#define _00_Pm2_PIN_GPIO        (0x00U) /* Pm2 as general I/O pin */
#define _00_Pm3_PIN_GPIO        (0x00U) /* Pm3 as general I/O pin */
#define _00_Pm4_PIN_GPIO        (0x00U) /* Pm4 as general I/O pin */
#define _00_Pm5_PIN_GPIO        (0x00U) /* Pm5 as general I/O pin */
#define _00_Pm6_PIN_GPIO        (0x00U) /* Pm6 as general I/O pin */
#define _00_Pm7_PIN_GPIO        (0x00U) /* Pm7 as general I/O pin */
/*
    Port Direction Register (PDR)
*/
/* Pmn Direction Control (B7 - B0) */
#define _00_Pm0_MODE_INPUT      (0x00U) /* Pm0 as input */
#define _01_Pm0_MODE_OUTPUT     (0x01U) /* Pm0 as output */
#define _00_Pm1_MODE_INPUT      (0x00U) /* Pm1 as input */
#define _02_Pm1_MODE_OUTPUT     (0x02U) /* Pm1 as output */
#define _00_Pm2_MODE_INPUT      (0x00U) /* Pm2 as input */
#define _04_Pm2_MODE_OUTPUT     (0x04U) /* Pm2 as output */
#define _00_Pm3_MODE_INPUT      (0x00U) /* Pm3 as input */
#define _08_Pm3_MODE_OUTPUT     (0x08U) /* Pm3 as output */
#define _00_Pm4_MODE_INPUT      (0x00U) /* Pm4 as input */
#define _10_Pm4_MODE_OUTPUT     (0x10U) /* Pm4 as output */
#define _00_Pm5_MODE_INPUT      (0x00U) /* Pm5 as input */
#define _20_Pm5_MODE_OUTPUT     (0x20U) /* Pm5 as output */
#define _00_Pm6_MODE_INPUT      (0x00U) /* Pm6 as input */
#define _40_Pm6_MODE_OUTPUT     (0x40U) /* Pm6 as output */
#define _00_Pm7_MODE_INPUT      (0x00U) /* Pm7 as input */
#define _80_Pm7_MODE_OUTPUT     (0x80U) /* Pm7 as output */
#define _01_PDR1_DEFAULT        (0x01U) /* PDR1 default value */
#define _01_PDR2_DEFAULT        (0x01U) /* PDR2 default value */
#define _0C_PDR3_DEFAULT        (0x0CU) /* PDR3 default value */
#define _88_PDR4_DEFAULT        (0x88U) /* PDR4 default value */
#define _20_PDR5_DEFAULT        (0x20U) /* PDR5 default value */
#define _81_PDRB_DEFAULT        (0x81U) /* PDRB default value */
#define _07_PDRD_DEFAULT        (0x07U) /* PDRD default value */
#define _3B_PDRE_DEFAULT        (0x3BU) /* PDRE default value */


/////UART Define
/*
    Interrupt Source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _0F_SCI_PRIORITY_LEVEL15                  (0x0FU) /* Level 15 (highest) */
/*
    Serial control register (SCR)
*/
/* Clock enable (CKE) */
#define _00_SCI_INTERNAL_SCK_UNUSED               (0x00U) /* Internal clock selected, SCK pin unused */
#define _01_SCI_INTERNAL_SCK_OUTPUT               (0x01U) /* Internal clock selected, SCK pin as clock output */
/*
    SPI mode register (SPMR)
*/
/* CTS enable (CTSE) */
#define _00_SCI_RTS                               (0x00U) /* RTS function is enabled */
/* Clock polarity select (CKPOL) */
#define _00_SCI_CLOCK_NOT_INVERTED                (0x00U) /* Clock polarity is not inverted */
/* Clock phase select (CKPH) */
#define _00_SCI_CLOCK_NOT_DELAYED                 (0x00U) /* Clock is not delayed */
/*
    Serial mode register (SMR)
*/
/* Clock select (CKS) */
#define _00_SCI_CLOCK_PCLK                        (0x00U) /* PCLK */
#define _01_SCI_CLOCK_PCLK_4                      (0x01U) /* PCLK/4 */
/* Multi-processor Mode (MP) */
#define _00_SCI_MULTI_PROCESSOR_DISABLE           (0x00U) /* Disable multiprocessor mode */
/* Stop bit length (STOP) */
#define _00_SCI_STOP_1                            (0x00U) /* 1 stop bit length */
/* Parity enable (PE) */
#define _00_SCI_PARITY_DISABLE                    (0x00U) /* Parity disable */
/* Character length (CHR) */
#define _00_SCI_DATA_LENGTH_8                     (0x00U) /* Data length 8 bits */
/* Communications mode (CM) */
#define _00_SCI_ASYNCHRONOUS_OR_I2C_MODE          (0x00U) /* Asynchronous mode or simple I2C mode */
/*
    Smart card mode register (SCMR)
*/
/* Smart card interface mode select (SMIF) */
#define _00_SCI_SERIAL_MODE                       (0x00U) /* Serial communications interface mode */
/* Transmitted / received data invert (SINV) */
#define _00_SCI_DATA_INVERT_NONE                  (0x00U) /* Data is not inverted */
/* Transmitted / received data transfer direction (SDIR) */
#define _00_SCI_DATA_LSB_FIRST                    (0x00U) /* Transfer data LSB first */
/* Character length 1 (CHR1)*/
#define _00_SCI_DATA_LENGTH_9                     (0x00U) /* Transmit/receive in 9-bit data length */
#define _10_SCI_DATA_LENGTH_8_OR_7                (0x10U) /* Transmit/receive in 8-bit or 7-bit data length */
/* Base clock pulse 2 (BCP2) */
#define _62_SCI_SCMR_DEFAULT                      (0x62U) /* Write default value of SCMR */
/*
    Serial extended mode register (SEMR)
*/
/* Bit Modulation Enable (BRME) */
#define _00_SCI_BIT_MODULATION_DISABLE            (0x00U) /* Bit rate modulation function is disabled */
/* Asynchronous mode base clock select (ABCS) */
#define _00_SCI_16_BASE_CLOCK                     (0x00U) /* Selects 16 base clock cycles for 1 bit period */
#define _10_SCI_8_BASE_CLOCK                      (0x10U) /* Selects 8 base clock cycles for 1 bit period */
/* Digital noise filter function enable (NFEN) */
#define _00_SCI_NOISE_FILTER_DISABLE              (0x00U) /* Noise filter is disabled */
/* Baud Rate Generator Double-Speed Mode Select (BGDM) */
#define _00_SCI_BAUDRATE_SINGLE                   (0x00U) /* Baud rate generator outputs normal frequency */
/* Asynchronous start bit edge detections select (RXDESEL) */
#define _00_SCI_LOW_LEVEL_START_BIT               (0x00U) /* Low level on RXDn pin selected as start bit */
#define _80_SCI_FALLING_EDGE_START_BIT            (0x80U) /* Falling edge on RXDn pin selected as start bit */