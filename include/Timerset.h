#ifndef _TIMERSET_H_
#define _TIMERSET_H_

#define PCC_LPIT			*((volatile unsigned*)(PCC_BASE + 0xDC))

#define CGC_BIT			30 // Clock Enable
#define PCS_BITS		24 // Peripheral Clock Source Select(0b010)

// LPIT Reg
#define LPIT_BASE			(0x40037000)
#define LPIT_MCR			*((volatile unsigned*)(LPIT_BASE + 0x8))
#define LPIT_MSR			*((volatile unsigned*)(LPIT_BASE + 0xC))
#define LPIT_MIER			*((volatile unsigned*)(LPIT_BASE + 0x10))
#define LPIT_TVAL0			*((volatile unsigned*)(LPIT_BASE + 0x20))
#define LPIT_TCTRL0			*((volatile unsigned*)(LPIT_BASE + 0x28))
#define LPIT_TVAL1			*((volatile unsigned*)(LPIT_BASE + 0x30))
#define LPIT_TCTRL1			*((volatile unsigned*)(LPIT_BASE + 0x38))

#define M_CEN_BIT			0
#define TIF0_BIT			0
#define TIE0_BIT			0
#define TIF1_BIT			1
#define TIE1_BIT			1
#define MODE_BITS			2
#define T_EN_BIT			0

#define NVIC_ISER_BASE		(0xE000E100)
#define NVIC_ISER1			*((volatile unsigned*)(NVIC_ISER_BASE + 0x4))

#define NVIC_ICPR_BASE		(0xE000E280)
#define NVIC_ICPR1			*((volatile unsigned*)(NVIC_ICPR_BASE + 0x4))

#define NVIC_IPR_BASE		(0xE000E400)
#define NVIC_IPR48			*((volatile unsigned*)(NVIC_IPR_BASE + 0x30))
#define NVIC_IPR49			*((volatile unsigned*)(NVIC_IPR_BASE + 0x31))

void NVIC_init_IRQs(void);
void LPIT0_init(void);

#endif /* _USERTIME_H_ */

