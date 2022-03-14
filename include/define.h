/*
 * define.h
 *
 *  Created on: 2022. 3. 4.
 *      Author: Heeseung
 */

#ifndef DEFINE_H_
#define DEFINE_H_

//---------------------------------------------------------------------------
//PCC
#define PCC_BASE		(0x40065000)
#define PCC_PORTC		*((volatile unsigned*)(PCC_BASE + 0x12C))
#define PCC_PORTD		*((volatile unsigned*)(PCC_BASE + 0x130))
#define PCC_PORTE		*((volatile unsigned*)(PCC_BASE + 0x134))
#define PCC_LPIT		*((volatile unsigned*)(PCC_BASE + 0xDC))
#define PCC_FlexCAN0 	*((volatile unsigned*)(PCC_BASE + 0x90))
#define PCC_LPUART1 *((volatile unsigned*)(PCC_BASE + 0x1AC))

#define CGC		30 // Clock Enable
#define PCS		24 // Peripheral Clock Source Select(0b010)


//---------------------------------------------------------------------------
// LPIT Reg
#define LPIT_BASE			(0x40037000)
#define LPIT_MCR			*((volatile unsigned*)(LPIT_BASE + 0x8))
#define LPIT_MSR			*((volatile unsigned*)(LPIT_BASE + 0xC))
#define LPIT_MIER			*((volatile unsigned*)(LPIT_BASE + 0x10))
#define LPIT_TVAL0		*((volatile unsigned*)(LPIT_BASE + 0x20))
#define LPIT_TCTRL0		*((volatile unsigned*)(LPIT_BASE + 0x28))
#define LPIT_TVAL1		*((volatile unsigned*)(LPIT_BASE + 0x30))
#define LPIT_TCTRL1		*((volatile unsigned*)(LPIT_BASE + 0x38))
#define LPIT_TVAL2    		*((volatile unsigned*)(LPIT_BASE + 0x40))
#define LPIT_TCTRL2   		*((volatile unsigned*)(LPIT_BASE + 0x48))
#define LPIT_TVAL3    		*((volatile unsigned*)(LPIT_BASE + 0x50))
#define LPIT_TCTRL3   		*((volatile unsigned*)(LPIT_BASE + 0x58))


#define M_CEN			0
#define TIF0			0
#define TIE0			0
#define TIF1			1
#define TIE1			1
#define TIF2			2
#define TIE2			2
#define TIF3			3
#define TIE3			3
#define MODE			2
#define T_EN			0




//---------------------------------------------------------------------------
//NVIC Register
#define NVIC_ISER_BASE		(0xE000E100)
#define NVIC_ISER1			*((volatile unsigned*)(NVIC_ISER_BASE + 0x4))

#define NVIC_ICPR_BASE		(0xE000E280)
#define NVIC_ICPR1			*((volatile unsigned*)(NVIC_ICPR_BASE + 0x4))

#define NVIC_IPR_BASE		(0xE000E400)
#define NVIC_IPR48			*((volatile unsigned*)(NVIC_IPR_BASE + 0x30))
#define NVIC_IPR49			*((volatile unsigned*)(NVIC_IPR_BASE + 0x31))
#define NVIC_IPR50			*((volatile unsigned*)(NVIC_IPR_BASE + 0x32))
#define NVIC_IPR51			*((volatile unsigned*)(NVIC_IPR_BASE + 0x33))

//---------------------------------------------------------------------------
//FlexCAN Reg
#define FlexCAN0_BASE (0x40024000)
#define FlexCAN0_MCR *((volatile unsigned*)(FlexCAN0_BASE+0x0))
#define FlexCAN0_CTRL1 *((volatile unsigned*)(FlexCAN0_BASE+0x4))
#define FlexCAN0_TIMER *((volatile unsigned*)(FlexCAN0_BASE+0x8))
#define FlexCAN0_RXMGMASK *((volatile unsigned*)(FlexCAN0_BASE+0x10))
#define FlexCAN0_IFLAG1 *((volatile unsigned*)(FlexCAN0_BASE+0x30))
#define FlexCAN0_MB0_0 *((volatile unsigned*)(FlexCAN0_BASE+0x80))
#define FlexCAN0_MB0_1 *((volatile unsigned*)(FlexCAN0_BASE+0x84))
#define FlexCAN0_MB0_2 *((volatile unsigned*)(FlexCAN0_BASE+0x88))
#define FlexCAN0_MB0_3 *((volatile unsigned*)(FlexCAN0_BASE+0x8C))
#define FlexCAN0_MB4_0 *((volatile unsigned*)(FlexCAN0_BASE+0xC0))
#define FlexCAN0_MB4_1 *((volatile unsigned*)(FlexCAN0_BASE+0xC4))
#define FlexCAN0_MB4_2 *((volatile unsigned*)(FlexCAN0_BASE+0xC8))
#define FlexCAN0_MB4_3 *((volatile unsigned*)(FlexCAN0_BASE+0xCC))
#define FlexCAN0_RXIMR4 *((volatile unsigned*)(FlexCAN0_BASE+0x890))

#define MDIS 31
#define FIZ 30
#define HALT 28
#define NOTRDY 27
#define FRZACK 24
#define MAXMB 0
#define RJW 22
#define PSEG1 19
#define PSEG2 16
#define CLKSRC 13
#define SMP 7
#define PROPSEG 0
#define BUF4T01I 1
#define BUF0I 0
#define CODE 24
#define SRR 22
#define DLC 16
#define STD_ID 18

//---------------------------------------------------------------------------
//PORT Reg 
#define PORTB_BASE (0x4004A000)
#define PORTB_S1 *((volatile unsigned*)(PORTB_BASE + 0x0))
#define PORTB_S2 *((volatile unsigned*)(PORTB_BASE + 0x04))
#define PORTB_B1 *((volatile unsigned*)(PORTB_BASE + 0x44))
#define PORTB_B2 *((volatile unsigned*)(PORTB_BASE + 0x38))
#define PORTB_B3 *((volatile unsigned*)(PORTB_BASE + 0x3C))
#define PORTB_OUT *((volatile unsigned*)(PORTB_BASE + 0x40))
#define PORTB_TURN *((volatile unsigned*)(PORTB_BASE + 0x34))

#define PORTC_BASE (0x4004B000)
#define PORTC_PCR6 *((volatile unsigned*)(PORTC_BASE+0x18))
#define PORTC_PCR7 *((volatile unsigned*)(PORTC_BASE+0x1C))
#define PORTC_PCR12  *((volatile unsigned*)(PORTC_BASE + 0x30))

#define PORTD_BASE	(0x4004C000)
#define PORTD_PCR0	*((volatile unsigned*)(PORTD_BASE + 0x0))
#define PORTD_PCR1	*((volatile unsigned*)(PORTD_BASE + 0x4))
#define PORTD_PCR2	*((volatile unsigned*)(PORTD_BASE + 0x8))
#define PORTD_PCR3	*((volatile unsigned*)(PORTD_BASE + 0xC))
#define PORTD_PCR5	*((volatile unsigned*)(PORTD_BASE + 0x14))
#define PORTD_PCR9	*((volatile unsigned*)(PORTD_BASE + 0x24))
#define PORTD_PCR10	*((volatile unsigned*)(PORTD_BASE + 0x28))
#define PORTD_PCR11	*((volatile unsigned*)(PORTD_BASE + 0x2C))
#define PORTD_PCR12	*((volatile unsigned*)(PORTD_BASE + 0x30))
#define PORTD_PCR15	*((volatile unsigned*)(PORTD_BASE + 0x3C))
#define PORTD_PCR16	*((volatile unsigned*)(PORTD_BASE + 0x40))


#define PORTE_BASE		(0x4004D000)
#define PORTE_PCR0		*((volatile unsigned*)(PORTE_BASE + 0x00))
#define PORTE_PCR1		*((volatile unsigned*)(PORTE_BASE + 0x04))
#define PORTE_PCR4 		*((volatile unsigned*)(PORTE_BASE + 0x10))
#define PORTE_PCR5 		*((volatile unsigned*)(PORTE_BASE + 0x14))
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

#define MUX 			8

//UART Reg  
// ---------------------------------------------------------------------------
#define LPUART1_BASE (0x4006B000)
#define LPUART1_BAUD *((volatile unsigned*)(LPUART1_BASE + 0x10))
#define LPUART1_STAT *((volatile unsigned*)(LPUART1_BASE + 0x14))
#define LPUART1_CTRL *((volatile unsigned*)(LPUART1_BASE + 0x18))
#define LPUART1_DATA *((volatile unsigned*)(LPUART1_BASE + 0x1C))

#define M10 29
#define OSR 24
#define SBNS 13
#define SBR 0
#define TDRE 23
#define RDRF 21
#define TE 19
#define RE 18
#define M7 11
#define M 4
#define PE 1


//GPIO Reg  
// ---------------------------------------------------------------------------
#define GPIOB_BASE (0x400FF040)
#define GPIOB_PSOR *((volatile unsigned*)(GPIOB_BASE + 0x4))
#define GPIOB_PCOR *((volatile unsigned*)(GPIOB_BASE + 0x8))
#define GPIOB_PTOR *((volatile unsigned*)(GPIOB_BASE + 0xC))
#define GPIOB_PDDR *((volatile unsigned*)(GPIOB_BASE + 0x14))

#define GPIOC_BASE (0x400FF080)
#define GPIOC_PDIR *((volatile unsigned*)(GPIOC_BASE+0x10))
#define GPIOC_PDDR *((volatile unsigned*)(GPIOC_BASE+0x14))

#define GPIOD_BASE	(0x400FF0C0)
#define GPIOD_PDOR	*((volatile unsigned*)(GPIOD_BASE + 0x0))
#define GPIOD_PSOR  *((volatile unsigned*)(GPIOD_BASE + 0x4))
#define GPIOD_PCOR  *((volatile unsigned*)(GPIOD_BASE + 0x8))
#define GPIOD_PTOR 	*((volatile unsigned*)(GPIOD_BASE + 0xC))
#define GPIOD_PDDR	*((volatile unsigned*)(GPIOD_BASE + 0x14))

#define GPIOE_BASE		(0x400FF100)
#define GPIOE_PSOR		*((volatile unsigned*)(GPIOE_BASE + 0x4))
#define GPIOE_PCOR		*((volatile unsigned*)(GPIOE_BASE + 0x8))
#define GPIOD_PTOR *((volatile unsigned*)(GPIOB_BASE + 0xC))
#define GPIOE_PDDR		*((volatile unsigned*)(GPIOE_BASE + 0x14))

#define S1 0
#define S2 1
#define B1 17
#define B2 14
#define B3 15
#define OUT 16
#define TURN 13
#define SEG1	0
#define SEG2	16
#define SEG6	15
#define SEG8	3
#define SEG14	5
#define SEG16	12
#define SEG13	11
#define SEG3	10
#define SEG5	1
#define SEG11	2
#define SEG15	9

#endif /* DEFINE_H_ */
