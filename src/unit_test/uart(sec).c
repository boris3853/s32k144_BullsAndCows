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
	LPIT0_init(0,0,0,0);
}

int main(void){
	PORT_set();

	LPUART1_transmit_string("Running LPUART example\n\r");
	LPUART1_transmit_string("Input string to echo...\n\r");

	char str[STR_MAXLEN] = {0};
	int str_cur_len = 0;

	for(;;){

		char receive;

		receive = LPUART1_receive_char();

		if(receive != '\r'){
			str[str_cur_len] = receive;

			str_cur_len++;
		}
		else{

			str[str_cur_len] = '\0';

			LPUART1_transmit_char('>');
			LPUART1_transmit_string(str);
			LPUART1_transmit_char('\n');
			LPUART1_transmit_char('\r');

			str_cur_len = 0;

		}
	}

}
