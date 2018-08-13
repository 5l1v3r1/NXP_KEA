// Device specific configurations

/*
#define SKEAZ1284
//*/ #define SKEAZN642

#ifdef SKEAZ1284
	#include "SKEAZ1284.h"
	// PINSEL translation
	#define SIM_PINSEL	SIM_PINSEL_REG(SIM)

	// Translations
	#define FTMRH						FTMRE
	#define FTMRH_FSTAT 				FTMRE_FSTAT
	#define FTMRH_FSTAT_CCIF_MASK		FTMRE_FSTAT_CCIF_MASK
	#define FTMRH_FCLKDIV				FTMRE_FCLKDIV
	#define FTMRH_FCLKDIV_FDIVLCK_MASK	FTMRE_FCLKDIV_FDIVLCK_MASK
	#define FTMRH_FCLKDIV_FDIVLD_MASK	FTMRE_FCLKDIV_FDIVLD_MASK
	#define FTMRH_FCLKDIV_FDIV_MASK		FTMRE_FCLKDIV_FDIV_MASK
	#define FTMRH_FCLKDIV_FDIV			FTMRE_FCLKDIV_FDIV

#elif defined SKEAZN642
	#include "SKEAZN642.h"

	/* Translations */
	#define SIM_CLKDIV_REG(base)	SIM_BUSDIV_REG(base)
	#define SIM_SOPT0_REG(base)		SIM_SOPT_REG(base)
	#define SIM_CLKDIV				SIM_BUSDIV
	#define SIM_CLKDIV_OUTDIV2_MASK	SIM_BUSDIV_BUSDIV_MASK

#endif
