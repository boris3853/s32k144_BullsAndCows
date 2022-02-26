#### 1) 4ND 7-seg : "_4ND_7seg.h"
- void _4ND_7SEG_init(void) : 4ND-7세그먼트 Port 설정
- void d_clear(void) : 4ND-7세그먼트 모든 핀 초기화
- void d_output(int, int) : 4ND-7세그먼트 자리수에 맞게 값 설정
- void delay_us(void) : 지연 함수 us
- void delay_ms(void) : 지연 함수 ms
- void SEG3NUM(int) : 4ND-7세그먼트 세자리 출력

#### 2) 1ND 7-seg : "_1ND_7seg.h"
- void _1ND_7SEG_init(void) : 1ND-7세그먼트 Port 설정
- void SEGNUM(int) : 1ND-7세그먼트 한자리 출력

#### 3) LEDs : "LEDs.h"
- void LEDS_PORT_init(void) : LED(O / S / B / T) Port 설정

#### 4) Clocks and Modes : "clocks_and_modes.h" 

- void SOSC_init_8MHz(void) : XTAL(EXTAL)로부터 8Mhz SOSC_CLK 생성
- void SPLL_init_160MHz(void) : SOSC_CLK 통해서 160Mhz SPLL_CLK 와 40Mhz SPLLDIV2_CLK 생성
- void NormalRUNmode_80MHz(void) : SPLL_CLK 통해서 각각 System Clock : 80Mhz / Bus Clock : 40Mhz / Flash Clock : 26.67Mhz 설정

#### 5) UART : "UART.h"
- void UART_PORT_init(void) : LPUART1 Port 설정
- char LPUART1_receive_char(void) : char 타입 문자 받기
- void LPUART1_transmit_char(char) : char 타입 문자 보내기
- void LPUART1_transmit_string(char *) : 문자열 보내기

#### 6) Timer : "Timerset.h"
- void NVIC_init_IRQs(void) : NVIC Interrupt 허용
- void LPIT0_init(void) : LPIT0 Ch0 Ch1 설정
