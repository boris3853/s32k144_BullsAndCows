#include "S32K144.h"

/********** USER Header ****************/
#include "_1ND_7seg.h"
#include "_4ND_7seg.h"
#include "CAN.h"
#include "clocks_and_modes.h"
#include "define.h"
#include "LEDs.h"
#include "Timerset.h"
#include "UART.h"

#define STR_MAXLEN		100

void PORT_set(){
	_4ND_7SEG_init();
	_1ND_7SEG_init();
	LEDS_PORT_init();
	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRUNmode_80MHz();
	UART_PORT_init();
	LPUART1_init();
	CAN_init();
	NVIC_init_IRQs();

	// change this code to use multiple channels of LPIT0
	// ex) LPIT0_init(0,0,1,0);
	LPIT0_init(0,1,0,0);
}

int j = 0;
int main(){
	PORT_set();

	for (;;) {
	    	SEGNUM(j);
	}
}

void LPIT0_Ch1_IRQHandler(){
	j++;

	if(j == 10) j = 0;

	LPIT_MSR |= (1<<TIF1);
}
