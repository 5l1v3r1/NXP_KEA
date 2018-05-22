#include "IO_Map.h"
#include "PDD_Types.h"
#include "FTM_PDD.h"


void PWM_Driver_Init(FTM_Type *pFTM, uint8_t ftmChannel, int32_t periodUS)
{
	  /* SIM_SCGC: FTM2=1 */
	  SIM_SCGC |= ( (pFTM == FTM0)?SIM_SCGC_FTM0_MASK:( pFTM == FTM1?SIM_SCGC_FTM1_MASK:SIM_SCGC_FTM2_MASK )) ;

	  /* FTM2_MODE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FAULTIE=0,FAULTM=0,CAPTEST=0,PWMSYNC=0,WPDIS=1,INIT=0,FTMEN=0 */
	  pFTM->MODE = (FTM_MODE_FAULTM(0x00) | FTM_MODE_WPDIS_MASK); /* Set up mode register */

	  /* Clear status and control register */
	  /* FTM2_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=0,CPWMS=0,CLKS=0,PS=0 */
	  pFTM->SC = (FTM_SC_CLKS(0x00) | FTM_SC_PS(0x00));

	  /* Clear counter initial register */
	  /* FTM2_CNTIN: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,INIT=0 */
	  pFTM->CNTIN = FTM_CNTIN_INIT(0x00);

	  /* FTM2_CNT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNT=0 */
	  pFTM->CNT = FTM_CNT_COUNT(0x00);      /* Reset counter register */

	  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
	  FTM2_C0SC = 0x00U;                   /* Clear channel status and control register */
	  /* FTM2_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
	  FTM2_C1SC = 0x00U;                   /* Clear channel status and control register */
	  /* FTM2_C2SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
	  FTM2_C2SC = 0x00U;                   /* Clear channel status and control register */
	  /* FTM2_C3SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
	  FTM2_C3SC = 0x00U;                   /* Clear channel status and control register */
	  /* FTM2_C4SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
	  FTM2_C4SC = 0x00U;                   /* Clear channel status and control register */
	  /* FTM2_C5SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
	  FTM2_C5SC = 0x00U;                   /* Clear channel status and control register */
	  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=1,MSA=0,ELSB=1,ELSA=0,??=0,??=0 */
	  FTM2_C0SC = (FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK); /* Set up channel status and control register */
	  /* FTM2_C0V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0 */
	  FTM2_C0V = FTM_CnV_VAL(0x00);        /* Set up channel value register */

	  /* FTM2_MOD: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MOD=0x3E7F */
	  pFTM->MOD = FTM_MOD_MOD(0x3E7F);      /* Set up modulo register */

	  /* FTM2_OUTINIT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CH7OI=0,CH6OI=0,CH5OI=0,CH4OI=0,CH3OI=0,CH2OI=0,CH1OI=0,CH0OI=1 */
	  pFTM->OUTINIT = FTM_OUTINIT_CH0OI_MASK; /* Set up Initial State for Channel Output register */

	  /* FTM2_MODE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FAULTIE=0,FAULTM=0,CAPTEST=0,PWMSYNC=0,WPDIS=1,INIT=1,FTMEN=0 */
	  pFTM->MODE = (FTM_MODE_FAULTM(0x00) | FTM_MODE_WPDIS_MASK | FTM_MODE_INIT_MASK); /* Initialize the Output Channels */

	  /* SIM_PINSEL: FTM2PS0=0 */
	  SIM_PINSEL &= (uint32_t)~(uint32_t)(SIM_PINSEL_FTM2PS0_MASK);
}

void PWM_Enable(FTM_Type *pFTM)
{
	//FTM_PDD_SelectPrescalerSource(pFTM, 8); return;

	///!< Initializing manually
	pFTM->SC |= 1<<5;	// CPWMS (Center-Aligned PWM Select): 0 = counting up, 1 = counting down
	pFTM->SC |= 0<<6;	// TOIE (Timer Overflow Interrupt Enable): 0 = disabled, 1 = enabled
	pFTM->SC |= 0<<4;	// CLKS (Clock Source Selection) 4-3: 00 - No clock selected, 01 - System clock
	pFTM->SC |= 1<<3;	// CLKS (Clock Source Selection) 4-3: 10 - Fixed frequency clock, 11 - External clock
	pFTM->SC |= 0<<2;	// PS (Prescale Factor Selection):
	pFTM->SC |= 1<<1;	// PS (Prescale Factor Selection):
	pFTM->SC |= 1<<0;	// PS (Prescale Factor Selection):
//				321
//				000 Divide by 1
//				001 Divide by 2
//				010 Divide by 4
//				011 Divide by 8
//				100 Divide by 16
//				101 Divide by 32
//				110 Divide by 64
//				111 Divide by 128
}

void PWM_SetRatio16(FTM_Type *pFTM, uint8_t ftmChannel, uint16_t ratio)
{
	//PWM1_SetRatio16(ratio); return;

	uint16_t period;
	uint16_t duty;

	// Retrieve period from FTM module
	period = (uint16_t)(FTM_PDD_ReadModuloReg(pFTM)) + 1;

	if ( period == 0U )
	{
		duty = ratio;
	}
	else
	{
		duty = (uint16_t)((((uint32_t)(period) * ratio) + 0x8000) >> 0x10);
	}

	// Write new duty
	FTM_PDD_WriteChannelValueReg(pFTM, ftmChannel, duty);
}

int main()
{
	/* Init pwm driver */
	PWM_Driver_Init(FTM2, 0, 1000);

	/* Emable PWM */
	PWM_Enable(FTM2);

	int i, j;
	while(1)
	{
		for(i=0; i<=65535; i++)
		{
			PWM_SetRatio16(FTM2, 0, i);
			for(int j=0; j <= 10; j++);
		}

		for(i=65534; i>=1; i--)
		{
			PWM_SetRatio16(FTM2, 0, i);
			for(int j=0; j <= 10; j++);
		}
	}
}