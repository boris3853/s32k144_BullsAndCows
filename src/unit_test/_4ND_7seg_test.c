#include "_4ND_7seg.h"
#include "Timerset.h"
#include "S32K144.h"
#include "clocks_and_modes.h"

int i = 0;
int main(void) {
	_4ND_7SEG_init();
	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRUNmode_80MHz();
	NVIC_init_IRQs();
	LPIT0_init();

    for (;;) {
    	SEG3NUM(i);
    }
}

void LPIT0_Ch0_IRQHandler(){
	LPIT_MSR |= (1<<TIF0_BIT);
}

void LPIT0_Ch1_IRQHandler(){
	i++;

	if(i == 1000) i = 0;

	LPIT_MSR |= (1<<TIF1_BIT);
}

