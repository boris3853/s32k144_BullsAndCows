#include "UART.h"

void UART_PORT_init(void){
	PCC_PORTC |= (1<<CGC);

	PORTC_PCR6 &= ~((0b111)<<MUX);
	PORTC_PCR6 |= ((0b010)<<MUX);

	PORTC_PCR7 &= ~((0b111)<<MUX);
	PORTC_PCR7 |= ((0b010)<<MUX);
}


void LPUART1_init(void){
	PCC_LPUART1 &= ~(1<<CGC);
	PCC_LPUART1 &= ~((0b111)<<PCS);
	PCC_LPUART1 |= ((0b010)<<PCS);
	PCC_LPUART1 |= (1<<CGC);

	LPUART1_BAUD &= ~(1<<M10);
	LPUART1_BAUD &= ~(1<<SBNS);

	LPUART1_BAUD &= ~((0b11111)<<OSR);
	LPUART1_BAUD |= (15<<OSR);  // oversampling ratio
	LPUART1_BAUD &= ~(8191<<SBR);
	LPUART1_BAUD |= (52<<SBR); // for 9600 baud rate

	LPUART1_CTRL &= ~(1<<M7); // use 8bit to 10bit
    LPUART1_CTRL &= ~(1<<M);
	LPUART1_CTRL &= ~(1<<PE);

	LPUART1_CTRL |= (1<<TE);
	LPUART1_CTRL |= (1<<RE);
}

char LPUART1_receive_char(void){
	char receive;

	while((LPUART1_STAT & (1<<RDRF)) == 0);

	receive = LPUART1_DATA;

	return receive;
}

void LPUART1_transmit_char(char send){
	while((LPUART1_STAT & (1<<TDRE)) == 0);

	LPUART1_DATA = send;
}


void LPUART1_transmit_string(char data_string[]){
	uint32_t i=0;

	while(data_string[i] != '\0'){
		LPUART1_transmit_char(data_string[i]);
		i++;
	}
}
