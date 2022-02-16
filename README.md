# s32k144_BullsAndCows
Simple Bulls_And_Cows game with s32k144 NXP MCU


## 1. 필요한 기능

1) CAN 통신: S32k끼리

2) Switch : External Interrupt

3) GPIO output 출력
- 4자리 7-segment 1개
- led : 7개(Y 1 R 2 B 3)


## 2. 숫자 야구 규칙

switch 2개
- switch1 : Counter (overflow 가능)

(1) 초기 세팅

1) 7-segment : 0000 출력
2) 0~9를 랜덤으로 띄우는데 숫자 높은 사람이 선 (중복 X) 
3) 원하는 숫자 3자리 입력(UART) => 자기 7-segment에 출력
3) 상대턴 : 똑같이 3자리 입력

(2) 정답 입력 완료 후
1) 턴 LED 출력 + 카운터 감소
2) UART 입력 => 자기 LED를 통해 상대의 정답 유사도를 알 수 있음(O/S/B)
3) 상대턴 : 똑같이

언제까지? => 승리하면 종료
1) 모든 LED blink

## 3. 테스트

## 4. 구현

### GPIO Layout
7-Segment(4글자) : 11개 => PORTD  /br 
7-Segment(1글자) : 7개 => PORTE /br  
Switch 1개 : 1개  => PORTC    /br
LED 7개 : 7개  => PORTC    /br
=> 총 : 26개




