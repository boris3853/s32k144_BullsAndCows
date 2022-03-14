#include "S32K144.h"
#include "LEDs.h"
#include "_1ND_7seg.h"
#include "_4ND_7seg.h"
#include "clocks_and_modes.h"
#include "UART.h"
#include "define.h"
#include "Timerset.h"





/********** Add CAN communication, But Not Check this code. PLZ RUN AND TEST THIS ON BOARD ****************/
/*
 * Edit num_PlaySet -> num_PlayCmp
 * Changed lots of codes... please check these... ,,
 * 
 */



#define STR_MAXLEN		100


int num_Baseball = 0; // Player's number for playing this game
int num_PlayCmp = 0; // this variable is use for INIT_set() and compare opponent's number!
int num_Order = 0; // 1st == 0, 2nd == 1;



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
	ex) LPIT0_init(0,0,0,0);
}



int main(void){

	PORT_init();


	LPUART1_transmit_string("> Start Setting the Game.\n\r");


	/**** For Setting the Order ****/
	num_PlayCmp = rand()%10; // CAN -> get the other player's number and compare these
	SEGNUM(num_PlaySet); 	// Turn on _1ND_SEG for display random number
	Flex_transmin_msg(num_PlaySet);


	while((FlexCAN0_IFLAG1 & (1<<4))!= 0)
		CAN_receive_msg();

	if(num_PlayCmp > RxDATA[0]){ // My Random number is Bigger
		num_Order = 0;
		SEGNUM(num_Order + 1); // output is 1 (read easily for player)
		LPUART1_transmit_string("> Your Order: 1st \n\r");
	}
	else{
		num_Order = 1;
		SEGNUM(num_Order + 1); // output is 2 (read easily for player)
		LPUART1_transmit_string("> Your Order: 2nd \n\r");

	   }





	/**** For Setting Player's Number to play baseball game ****/
	num_PlayCmp = 1;

	char str[STR_MAXLEN] = {0};
	int str_cur_len = 0;
	LPUART1_transmit_string("Input your number\n\r");

	while(num_PlayCmp){

		char receive;

		receive = LPUART1_receive_char();

		if(receive != '\r'){
			str[str_cur_len] = receive;

			str_cur_len++;
		}
		else{

			str[str_cur_len] = '\0';
			num_Baseball = atoi(str);

			if(num_Baseball < 1000){

				LPUART1_transmit_string("> The Number You Set: ");
				LPUART1_transmit_string(str);
				LPUART1_transmit_char('\n');
				LPUART1_transmit_char('\r');
				num_PlayCmp = 0;
			}

			else{

				LPUART1_transmit_string("> Invalid Number \n\r");
				LPUART1_transmit_string("> Input Your Number \n\r");
			}

			str_cur_len = 0;

		}
	}
	SEG3NUM(num_Baseball);	// Turn on _4ND_SEG for display my number
	Flex_transmin_msg(num_Baseball);

	while((FlexCAN0_IFLAG1 & (1<<4))!= 0){
		CAN_receive_msg();
		num_PlayCmp |= (RxDATA[1] << 32)|(RxDATA[0] << 0); // is this right expression? Check Plz T.T
	}



	LPUART1_transmit_string("\n\n> Lets Start the Baseball Game.\n\r");



	for(;;){

		// empty

	}

}
