#include "_1ND_7seg.h"

void _1ND_7SEG_init(void){

	PCC_PORTE |= (1 << CGC_BIT);
	PORTE_PCR0 &= ~((0b111) << MUX_BITS);
	PORTE_PCR0 |= (1 << MUX_BITS);
	PORTE_PCR1 &= ~((0b111) << MUX_BITS);
	PORTE_PCR1 |= (1 << MUX_BITS);
	PORTE_PCR6 &= ~((0b111) << MUX_BITS);
	PORTE_PCR6 |= (1 << MUX_BITS);
	PORTE_PCR9 &= ~((0b111) << MUX_BITS);
	PORTE_PCR9 |= (1 << MUX_BITS);
	PORTE_PCR13 &= ~((0b111) << MUX_BITS);
	PORTE_PCR13 |= (1 << MUX_BITS);
	PORTE_PCR14 &= ~((0b111) << MUX_BITS);
	PORTE_PCR14 |= (1 << MUX_BITS);
	PORTE_PCR15 &= ~((0b111) << MUX_BITS);
	PORTE_PCR15 |= (1 << MUX_BITS);
	PORTE_PCR16 &= ~((0b111) << MUX_BITS);
	PORTE_PCR16 |= (1 << MUX_BITS);

	GPIOE_PDDR |= (1<<PTE13)|(1<<PTE14)|(1<<PTE15)|(1<<PTE16)|(1<<PTE0)|(1<<PTE1)|(1<<PTE6)|(1<<PTE9);
}



void SEGNUM(int num){

	GPIOE_PCOR |= (1<<PTE16)|(1<<PTE15)|(1<<PTE1)|(1<<PTE13)|(1<<PTE14)|(1<<PTE9)|(1<<PTE0);

	switch(num){
		case 0:
			GPIOE_PSOR |= (1<<PTE16)|(1<<PTE15)|(1<<PTE1)|(1<<PTE13)|(1<<PTE14)|(1<<PTE9);
			break;

		case 1:
			GPIOE_PSOR |= (1<<PTE15)|(1<<PTE1);
			break;

		case 2:
			GPIOE_PSOR |= (1<<PTE16)|(1<<PTE15)|(1<<PTE13)|(1<<PTE14)|(1<<PTE0);
	   		break;

	   	case 3:
	   		GPIOE_PSOR |= (1<<PTE16)|(1<<PTE15)|(1<<PTE1)|(1<<PTE13)|(1<<PTE0);
			break;

  		case 4:
  			GPIOE_PSOR |= (1<<PTE15)|(1<<PTE1)|(1<<PTE9)|(1<<PTE0);
	   		break;

	   	case 5:
			GPIOE_PSOR |= (1<<PTE16)|(1<<PTE1)|(1<<PTE13)|(1<<PTE9)|(1<<PTE0);
			break;

	   	case 6:
	   		GPIOE_PSOR |= (1<<PTE16)|(1<<PTE1)|(1<<PTE13)|(1<<PTE14)|(1<<PTE9)|(1<<PTE0);;
	   		break;

	   	case 7:
	   		GPIOE_PSOR |= (1<<PTE16)|(1<<PTE15)|(1<<PTE1);
	   		break;

		case 8:
			GPIOE_PSOR |= (1<<PTE16)|(1<<PTE15)|(1<<PTE1)|(1<<PTE13)|(1<<PTE14)|(1<<PTE9)|(1<<PTE0);
			break;

		case 9:
			GPIOE_PSOR |= (1<<PTE16)|(1<<PTE15)|(1<<PTE1)|(1<<PTE13)|(1<<PTE9)|(1<<PTE0);
			break;
	}


}