/*
 * _1ND_7seg.h
 *
 *  Created on: Feb 22, 2022
 *      Author: Kyung
 */

#ifndef _1ND_7SEG_H_
#define _1ND_7SEG_H_

//PCC Reg, Clock enable
#define PCC_BASE		(0x40065000)
#define PCC_PORTE		*((volatile unsigned*)(PCC_BASE + 0x134))

#define CGC_BIT			30
#define MUX_BITS		8


#define GPIOE_BASE		(0x400FF100)
#define GPIOE_PSOR		*((volatile unsigned*)(GPIOE_BASE + 0x4))
#define GPIOE_PCOR		*((volatile unsigned*)(GPIOE_BASE + 0x8))
#define GPIOE_PDDR		*((volatile unsigned*)(GPIOE_BASE + 0x14))


#define PORTE_BASE		(0x4004D000)
#define PORTE_PCR0		*((volatile unsigned*)(PORTE_BASE + 0x00))
#define PORTE_PCR1		*((volatile unsigned*)(PORTE_BASE + 0x04))

#define PORTE_PCR6		*((volatile unsigned*)(PORTE_BASE + 0x18))

#define PORTE_PCR9		*((volatile unsigned*)(PORTE_BASE + 0x24))
#define PORTE_PCR13		*((volatile unsigned*)(PORTE_BASE + 0x34))
#define PORTE_PCR14		*((volatile unsigned*)(PORTE_BASE + 0x38))
#define PORTE_PCR15		*((volatile unsigned*)(PORTE_BASE + 0x3C))
#define PORTE_PCR16		*((volatile unsigned*)(PORTE_BASE + 0x40))


#define PTE0			0
#define PTE1			1
#define PTE6			6
#define PTE9			9
#define PTE13			13
#define PTE14			14
#define PTE15			15
#define PTE16			16


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


#endif /* 1ND_7SEG_H_ */

