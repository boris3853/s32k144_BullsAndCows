#include "_4ND_7seg.h"

int main(){
	_4ND_7SEG_init();

	for(;;){
		d_output(3,5);
		delay_ms(1000);
		d_output(1,2);
		delay_ms(1000);
		d_output(2,1);
		delay_ms(1000);
	}
}

