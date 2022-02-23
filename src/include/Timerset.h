#ifndef _TIMERSET_H_
#define _TIMERSET_H_

#include "define.h"



void NVIC_init_IRQs(void){

	NVIC_ICPR1 |= (1<<(48 % 32)) | (1<<(61 % 32));
	NVIC_ISER1 |= (1<<(48 % 32)) | (1<<(61 % 32));
	NVIC_IPR48 = 10;
	NVIC_IPR61 = 10;

}

void LPIT0_init(void){

	PCC_LPIT &= ~((0b111)<<PCS_BITS);
	PCC_LPIT |= ((0b110)<<PCS_BITS);
	PCC_LPIT |= (1<<CGC_BIT);

	LPIT_MCR |= (1<<M_CEN_BIT);

	LPIT_MIER |= (1<<TIE0_BIT);

	LPIT_TVAL0 = 40000000;

	LPIT_TCTRL0 &= ~((0b11)<<MODE_BITS);
	LPIT_TCTRL0 |= (1<<T_EN_BIT);
}



#endif /* _USERTIME_H_ */
