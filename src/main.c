#include "S32K144.h"
#include "LEDs.h"
#include "_1ND_7seg.h"
#include "_4ND_7seg.h"
#include "clocks_and_modes.h"
#include "UART.h"

void init_set(){
	_4ND_7SEG_init();
	_1ND_7SEG_init();
	PORT_init();
	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRUNmode_80MHz();
	UART_PORT_init();
	}

int main(){
	init_set();




}



