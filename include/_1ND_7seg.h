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

void _1ND_7SEG_init(void);
void SEGNUM(int num);

#endif /* 1ND_7SEG_H_ */

