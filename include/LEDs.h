
#ifndef _LEDs_H_
#define _LEDs_H_

#define PCC_BASE (0x40065000)
#define PCC_PORTB *((volatile unsigned*)(PCC_BASE + 0x128))

#define CGC 30

#define PORTB_BASE (0x4004A000)
#define PORTB_S1 *((volatile unsigned*)(PORTB_BASE + 0x0))
#define PORTB_S2 *((volatile unsigned*)(PORTB_BASE + 0x04))
#define PORTB_B1 *((volatile unsigned*)(PORTB_BASE + 0x44))
#define PORTB_B2 *((volatile unsigned*)(PORTB_BASE + 0x38))
#define PORTB_B3 *((volatile unsigned*)(PORTB_BASE + 0x3C))
#define PORTB_OUT *((volatile unsigned*)(PORTB_BASE + 0x40))
#define PORTB_TURN *((volatile unsigned*)(PORTB_BASE + 0x34))

#define MUX 8

#define GPIOB_BASE (0x400FF040)
#define GPIOB_PSOR *((volatile unsigned*)(GPIOB_BASE + 0x4))
#define GPIOB_PCOR *((volatile unsigned*)(GPIOB_BASE + 0x8))
#define GPIOB_PTOR *((volatile unsigned*)(GPIOB_BASE + 0xC))
#define GPIOB_PDDR *((volatile unsigned*)(GPIOB_BASE + 0x14))

#define GPIOD_PCOR *((volatile unsigned*)(GPIOB_BASE + 0x8))
#define GPIOD_PTOR *((volatile unsigned*)(GPIOB_BASE + 0xC))
#define GPIOD_PDDR *((volatile unsigned*)(GPIOB_BASE + 0x14))

#define S1 0
#define S2 1
#define B1 17
#define B2 14
#define B3 15
#define OUT 16
#define TURN 13

void LEDS_PORT_init(void);

#endif /* _LEDs_H_ */
