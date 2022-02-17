#define PCC_BASE 	(0x40065000)
#define PCC_PORTD	*((volatile unsigned*)(PCC_BASE + 0x130))
#define CGC_BIT 30

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

#define MUX_BITS 8

#define GPIOD_BASE	(0x400FF0C0)
#define GPIOD_PDOR	*((volatile unsigned*)(GPIOD_BASE + 0x0))
#define GPIOD_PSOR  *((volatile unsigned*)(GPIOD_BASE + 0x4))
#define GPIOD_PCOR  *((volatile unsigned*)(GPIOD_BASE + 0x8))
#define GPIOD_PTOR 	*((volatile unsigned*)(GPIOD_BASE + 0xC))
#define GPIOD_PDDR	*((volatile unsigned*)(GPIOD_BASE + 0x14))
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

int main(){
	PCC_PORTD |= (1 << CGC_BIT);
	PORTD_PCR0 &= ~((0b111) << MUX_BITS);
	PORTD_PCR0 |= (1 << MUX_BITS);
	PORTD_PCR1 |= (1 << MUX_BITS);
	PORTD_PCR2 |= (1 << MUX_BITS);
	PORTD_PCR3 |= (1 << MUX_BITS);
	PORTD_PCR5 |= (1 << MUX_BITS);
	PORTD_PCR9 |= (1 << MUX_BITS);
	PORTD_PCR10 |= (1 << MUX_BITS);
	PORTD_PCR11 |= (1 << MUX_BITS);
	PORTD_PCR12 |= (1 << MUX_BITS);
	PORTD_PCR15 |= (1 << MUX_BITS);
	PORTD_PCR16 |= (1 << MUX_BITS);

	GPIOD_PDDR |= (1 << SEG1) | (1 << SEG2) | (1 << SEG6) | (1 << SEG8) | (1 << SEG14) |
			(1 << SEG16) | (1 << SEG13) | (1 << SEG3) | (1 << SEG5) | (1 << SEG11) | (1 << SEG15);

	for(;;){
		GPIOD_PSOR |= (1 << SEG1) | (1 << SEG2) | (1 << SEG6) | (1 << SEG8);
	}
}