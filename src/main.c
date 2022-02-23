#include "S32K144.h"
#include "LEDs.h"
#include "_1ND_7seg.h"
#include "_4ND_7seg.h"
#include "clocks_and_modes.h"
#include "UART.h"

void PORT_set(){
	_4ND_7SEG_init();
	_1ND_7SEG_init();
	LEDS_PORT_init();
	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRUNmode_80MHz();
	UART_PORT_init();
}

void INIT_set(){

}

int main(){
	// 포트 세팅
	PORT_set();

	// 초기 설정
	INIT_set();

	while(1){
	}
}
