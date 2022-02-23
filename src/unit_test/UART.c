#include "LEDs.h"
#include "clocks_and_modes.h"
#include "UART.h"

int main(void){
	SOSC_init_8MHz();
	SPLL_init_160MHz();
	NormalRunmode_80MHz();
	PORT_init();
  UART_PORT_init();
	LPUART1_init();

	char ans, num;

	LPUART1_transmit_string("Game Start?[Y/N]\n\r");
	ans = LPUART1_receive_char();
	if(ans=='N') return 0;

	while(1){
		LPUART1_transmit_string("Input number you like\n\r");
		num = LPUART1_receive_char();

		if(num=='a')
			GPIOB_PTOR |= (1<<S1);

		else if(num=='b')
			GPIOB_PTOR |= (1<<B1);

		else if(num=='c')
			GPIOB_PTOR |= (1<<OUT);
	}
    else
      LPUART1_transmit_string("blah blah\n\r");

	return 0;
}
