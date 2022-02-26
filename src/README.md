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

## 2. /include : 각 테스트 코드를 헤더파일로 

## 3. /src : 메인 코드 구현
#### INIT_setting
[1. S32K_1]
  1) 4ND Seg 000 세팅
  2) 1ND Seg 0 ~ 9 중 랜덤 값 배정
  3) CAN 통신 이용해서 S32K2에게 랜덤 값 전달

[2. S32K_2]
1) 4ND Seg 000 세팅
2) 1ND Seg 0 ~ 9 (받은 값 제외) 중에서 값 배정
3) S32K_1와 S32K_2 중 선공 / 후공 결정
4) S32K_2가 선이면 Turn LED 출력
5) CAN 통신 이용해서 S32K_1에게 선/후 결과 전달 

[3. S32K_1]
1) S32K_1이 선이면 Turn LED 출력

[4. 선공 측]
1) UART 이용해서 "세자리 숫자(000 ~ 999) 입력: " 출력
2) 데이터 받고 잘못된 입력 값일 경우에 재출력
3) 정상 값이면 4ND LED 값 업데이트
4) Turn LED Off

[5. 후공 측]
1) Turn LED On
2) UART 이용해서 "세자리 숫자(000 ~ 999) 입력: " 출력
3) 데이터 받고 잘못된 입력 값일 경우에 재출력
4) 정상 값이면 4ND LED 값 업데이트
5) Turn LED Off

#### Main
