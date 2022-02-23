#include "_1ND_7seg.h"

int main(void) {
	_1ND_7SEG_init();

	GPIOE_PSOR |= (1<<PTE6);

    for (;;) {

    	for (int i = 0; i<10; i++){

    		for (int j = 0; j<500000; j++){

    			SEGNUM(i);
    		}
    	}

    }
}
