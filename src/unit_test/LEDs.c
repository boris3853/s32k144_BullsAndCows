#include "define.h"
#include "LEDs.h"

int main(){
	LEDS_PORT_init();

	while(1){
		int k = 1000000;
		GPIOB_PTOR |= (1<<S1);
		GPIOB_PTOR |= (1<<S2);
		GPIOB_PTOR |= (1<<OUT);
		GPIOB_PTOR |= (1<<B1);
		GPIOB_PTOR |= (1<<B2);
		GPIOB_PTOR |= (1<<B3);
		GPIOB_PTOR |= (1<<TURN);
		while(k--){
		}
	}
}
