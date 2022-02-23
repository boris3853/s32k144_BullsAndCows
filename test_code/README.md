## 1. /src/unit_test/ : Unit 테스트
#### 1) 7-segment(3글자 출력)
- _4ND_7seg_test.c : 4FND 출력 테스트
<img src="https://user-images.githubusercontent.com/60434800/154794185-8f5fc3ca-4b00-4517-acb9-4a86066f878c.png" width="400" height="300">


#### 2) 7-segment(1글자 출력)
- single_7seg_test.c : 단일 segment 출력 테스트

#### 3) LED 7개 출력
- led_address.c : LED 7개 출력 테스트

#### 4) UART 테스트
- uart.c : UART 한글자 송수신 테스트

## 2. /src/include/ : 각 테스트 코드를 헤더파일로 
#### 1) 4ND 7-seg : "_4ND_7seg.h"
- void _4ND_7SEG_init(void) : 4ND-7세그먼트 Port 설정
- void d_clear(void) : 4ND-7세그먼트 모든 핀 초기화
- void d_output(int, int) : 4ND-7세그먼트 자리수에 맞게 값 설정
- void delay_ms(void) : 지연 함수

#### 2) 1ND 7-seg : "_1ND_7seg.h"
- void _1ND_7SEG_init(void) : 1ND-7세그먼트 Port 설정
- void SEGNUM(int) : 1ND-7세그먼트 값 설정

#### 3) LEDs : "LEDs.h"
- void PORT_init(void) : LED(O / S / B / T) Port 설정

#### 4) Clocks and Modes : "clocks_and_modes.h" / "clocks_and_modes.c" 

- void SOSC_init_8MHz(void) : XTAL(EXTAL)로부터 8Mhz SOSC_CLK 생성
- void SPLL_init_160MHz(void) : SOSC_CLK 통해서 160Mhz SPLL_CLK 와 40Mhz SPLLDIV2_CLK 생성
- void NormalRUNmode_80MHz(void) : SPLL_CLK 통해서 각각 System Clock : 80Mhz / Bus Clock : 40Mhz / Flash Clock : 26.67Mhz 설정

#### 5) UART : "UART.h"
- void UART_PORT_init(void) : LPUART1 Port 설정
- char LPUART1_receive_char(void) : char 타입 문자 받기
- void LPUART1_transmit_char(char) : char 타입 문자 보내기
- void LPUART1_transmit_string(char *) : 문자열 보내기

## 3. /src : 메인 코드 구현

