#include "Timerset.h"

void NVIC_init_IRQs(void){
	NVIC_ICPR1 |= (1<<(48 % 32)) | (1<<(49 % 32)) | (1<<(50 % 32)) | (1<<(51 % 32));
	NVIC_ISER1 |= (1<<(48 % 32)) | (1<<(49 % 32)) | (1<<(50 % 32)) | (1<<(51 % 32));
	NVIC_IPR48 = 0x10;
	NVIC_IPR49 = 0x11;
	NVIC_IPR50 = 0x12;
	NVIC_IPR51 = 0x13;
}

void LPIT0_init(char CH0, char CH1, char CH2, char CH3){
	PCC_LPIT &= ~((0b111)<<PCS_BITS);
	PCC_LPIT |= ((0b110)<<PCS_BITS);
	PCC_LPIT |= (1<<CGC_BIT);

	LPIT_MCR |= (1<<M_CEN_BIT);

	if(CH0){	// LPIT Channel 0
		LPIT_MIER |= (1<<TIE0_BIT);
		LPIT_TVAL0 = 40000000;
		LPIT_TCTRL0 &= ~((0b11)<<MODE_BITS);
		LPIT_TCTRL0 |= (1<<T_EN_BIT);
	}

	if(CH1){	// LPIT Channel 1
		LPIT_MIER |= (1<<TIE1_BIT);
		LPIT_TVAL1 = 40000000;
		LPIT_TCTRL1 &= ~((0b11)<<MODE_BITS);
		LPIT_TCTRL1 |= (1<<T_EN_BIT);
	}

	if(CH2){	// LPIT Channel2
		LPIT_MIER |= (1<<TIE2_BIT);
		LPIT_TVAL2 = 40000000;
		LPIT_TCTRL2 &= ~((0b11)<<MODE_BITS);
		LPIT_TCTRL2 |= (1<<T_EN_BIT);
	}

	if(CH3){	// LPIT Channel 3
		LPIT_MIER |= (1<<TIE3_BIT);
		LPIT_TVAL3 = 40000000;
		LPIT_TCTRL3 &= ~((0b11)<<MODE_BITS);
		LPIT_TCTRL3 |= (1<<T_EN_BIT);
	}
}