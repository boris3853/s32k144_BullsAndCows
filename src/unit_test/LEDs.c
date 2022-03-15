#include "define.h"


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

	GPIOD_PDDR |= (1<<S1);
	GPIOD_PDDR |= (1<<S2);
	GPIOD_PDDR |= (1<<B1);
	GPIOD_PDDR |= (1<<B2);
	GPIOD_PDDR |= (1<<B3);
	GPIOD_PDDR |= (1<<OUT);
	GPIOD_PDDR |= (1<<TURN);


}


int main(){
	LEDS_PORT_init();
	GPIOD_PSOR |= (1<<B1);
	GPIOD_PSOR |= (1<<B2);
	GPIOD_PSOR |= (1<<B3);
	GPIOD_PSOR |= (1<<TURN);


	while(1){
		int k = 10000;
		GPIOD_PTOR |= (1<<S1);
		GPIOD_PTOR |= (1<<S2);
		GPIOD_PTOR |= (1<<OUT);

		while(k--){
			GPIOD_PTOR |= (1<<B1);
			GPIOD_PTOR |= (1<<B2);
			GPIOD_PTOR |= (1<<B3);
			GPIOD_PTOR |= (1<<TURN);
		}


	}
}
