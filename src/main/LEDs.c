#include "LEDs.h"

void LEDS_PORT_init(){
	PCC_PORTB |= (1<<CGC);

	PORTB_S1 &= ~((0b111)<<MUX);
	PORTB_S1 |= (1<<MUX);

	PORTB_S2 &= ~((0b111)<<MUX);
	PORTB_S2 |= (1<<MUX);

	PORTB_B1 &= ~((0b111)<<MUX);
	PORTB_B1 |= (1<<MUX);

	PORTB_B2 &= ~((0b111)<<MUX);
	PORTB_B2 |= (1<<MUX);

	PORTB_B3 &= ~((0b111)<<MUX);
	PORTB_B3 |= (1<<MUX);

	PORTB_OUT &= ~((0b111)<<MUX);
	PORTB_OUT |= (1<<MUX);

	PORTB_TURN &= ~((0b111)<<MUX);
	PORTB_TURN |= (1<<MUX);

	GPIOB_PDDR |= (1<<S1);
	GPIOB_PDDR |= (1<<S2);
	GPIOB_PDDR |= (1<<B1);
	GPIOB_PDDR |= (1<<B2);
	GPIOB_PDDR |= (1<<B3);
	GPIOB_PDDR |= (1<<OUT);
	GPIOB_PDDR |= (1<<TURN);
}