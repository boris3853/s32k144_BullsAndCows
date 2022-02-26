#include "Timerset.h"

void NVIC_init_IRQs(void){
	NVIC_ICPR1 |= (1<<(48 % 32)) | (1<<(49 % 32));
	NVIC_ISER1 |= (1<<(48 % 32)) | (1<<(49 % 32));
	NVIC_IPR48 = 0x10;
	NVIC_IPR49 = 0x20;
}

void LPIT0_init(void){
	PCC_LPIT &= ~((0b111)<<PCS_BITS);
	PCC_LPIT |= ((0b110)<<PCS_BITS);
	PCC_LPIT |= (1<<CGC_BIT);

	LPIT_MCR |= (1<<M_CEN_BIT);

	// LPIT Channel 0
	LPIT_MIER |= (1<<TIE0_BIT);
	LPIT_TVAL0 = 40000000;
	LPIT_TCTRL0 &= ~((0b11)<<MODE_BITS);
	LPIT_TCTRL0 |= (1<<T_EN_BIT);

	// LPIT Channel 1
	LPIT_MIER |= (1<<TIE1_BIT);
	LPIT_TVAL1 = 40000000;
	LPIT_TCTRL1 &= ~((0b11)<<MODE_BITS);
	LPIT_TCTRL1 |= (1<<T_EN_BIT);
}