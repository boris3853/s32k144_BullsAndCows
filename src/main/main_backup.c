#include "S32K144.h"
#include "LEDs.h"
#include "_1ND_7seg.h"
#include "_4ND_7seg.h"
#include "clocks_and_modes.h"
#include "UART.h"
#include "define.h"
#include "Timerset.h"

void PORT_set(){
	_4ND_7SEG_init();
	_1ND_7SEG_init();
	LEDS_PORT_init();
	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRUNmode_80MHz();
	UART_PORT_init();
}

void Timer_set(){

	NVIC_init_IRQs();
	LPIT0_init();
}


int counterSec = 0;
int myTurn = ~0; // if myTurn != 0 -> my turn


void INIT_set(){

}

int main(){
	// 포트 세팅
	PORT_set();
	Timer_set();

	// 초기 설정
	INIT_set();

	while(1){
		
	}
}



/**** Timer Settings ****/
void LPIT0_Ch0_IRQHandler(void){

	

	SEGNUM(counterSec);
	if(myTurn != 0){
		counterSec++;
		if(counterSec == 10){
			counterSec = 0;

			myTurn = ~myTurn;
			}
		}

	else{ // not my turn
		counterSec = 0;

	}

	LPIT_MSR |= (1<<TIF0_BIT);
}

