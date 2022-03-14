#include "_4ND_7seg.h"

int NUM[11] = {0x1C26, 0x1800, 0x1622, 0x1E20, 0x1A04, 0x0E24, 0x0E26, 0x1820, 0x1E26, 0x1A24};

void _4ND_7SEG_init(void){
	PCC_PORTD |= (1 << CGC);
	PORTD_PCR0 &= ~((0b111) << MUX);
	PORTD_PCR0 |= (1 << MUX);
	PORTD_PCR1 |= (1 << MUX);
	PORTD_PCR2 |= (1 << MUX);
	PORTD_PCR3 |= (1 << MUX);
	PORTD_PCR5 |= (1 << MUX);
	PORTD_PCR9 |= (1 << MUX);
	PORTD_PCR10 |= (1 << MUX);
	PORTD_PCR11 |= (1 << MUX);
	PORTD_PCR12 |= (1 << MUX);
	PORTD_PCR15 |= (1 << MUX);
	PORTD_PCR16 |= (1 << MUX);

	GPIOD_PDDR |= (1 << SEG1) | (1 << SEG2) | (1 << SEG6) | (1 << SEG8) | (1 << SEG14) |
				(1 << SEG16) | (1 << SEG13) | (1 << SEG3) | (1 << SEG5) | (1 << SEG11) | (1 << SEG15);
}

void delay_us(int num){
	for(int i=0;i<num;++i);
}

void delay_ms(int num){
	for(int i=0;i<num*1000;++i);
}

void d_clear(){
	GPIOD_PSOR |= (1 << SEG14) | (1 << SEG16) | (1 << SEG13) |
				(1 << SEG3) | (1 << SEG5) | (1 << SEG11) | (1 << SEG15);
}
// digit : 1 2 3
// num : 0 ~ 9
void d_output(int digit, int num){
	if(digit == 1){ // 첫번째 자리
		GPIOD_PSOR |= (1 << SEG1);
		GPIOD_PCOR |= (1 << SEG2) | (1 << SEG6);
	}else if(digit == 2){ // 두번째 자리
		GPIOD_PSOR |= (1 << SEG2);
		GPIOD_PCOR |= (1 << SEG1) | (1 << SEG6);
	}else if(digit == 3){ // 세번째 자리
		GPIOD_PSOR |= (1 << SEG6);
		GPIOD_PCOR |= (1 << SEG1) | (1 << SEG2);
	}

	d_clear();
	GPIOD_PCOR |= NUM[num];
	delay_ms(10);
}

void SEG3NUM(int num){
	d_output(3, num/100%100);
    	d_output(2, num/10%10);
    	d_output(1, num%10);
}