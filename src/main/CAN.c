#include "CAN.h"
#include "define.h"

#define NODE_A

uint32_t RxDATA[2];
uint32_t flag;

void NVIC_init_IRQs(void){  // pass
   NVIC_ICPR1 |= (1<<(48%32));
   NVIC_ISER1 |= (1<<(48%32));
   NVIC_IPR48 = 10;
}


void LPIT0_init(void){ // pass
   PCC_LPIT &= ~((0b111)<<PCS);
   PCC_LPIT |= ((0b110)<<PCS);
   PCC_LPIT |= (1<<CGC);

   LPIT_MCR |= (1<<M_CEN);

   LPIT_MIER |= (1<<TIE0);

   LPIT_TVAL0 = 4000000;

   LPIT_TCTRL0 &= ~((0b11)<<MODE);
   LPIT_TCTRL0 |= (1<<T_EN);
}


void CAN_init(){
#define MSG_BUF_SIZE 4

   PCC_FlexCAN0 |= (1<<CGC);

   FlexCAN0_MCR |= (1<<MDIS);
   FlexCAN0_CTRL1 &= ~(1<<CLKSRC);
   FlexCAN0_MCR &= ~(1<<MDIS);

   while(!(FlexCAN0_MCR & (1<<FRZACK)));

   FlexCAN0_CTRL1 &= ~((0b111)<<PSEG2);
   FlexCAN0_CTRL1 |= (3<<PSEG2);
   FlexCAN0_CTRL1 &= ~((0b111)<<PSEG1);
   FlexCAN0_CTRL1 |= (3<<PSEG1);
   FlexCAN0_CTRL1 &= ~((0b111)<<PROPSEG);
   FlexCAN0_CTRL1 |= (6<<PROPSEG);
   FlexCAN0_CTRL1 &= ~((0b11)<<RJW);
   FlexCAN0_CTRL1 |= (3<<RJW);
   FlexCAN0_CTRL1 |= (1<<SMP);

   FlexCAN0_MB0_0 = 0;
   FlexCAN0_MB0_1 = 0;
   FlexCAN0_MB0_2 = 0;
   FlexCAN0_MB0_3 = 0;

   FlexCAN0_MB4_0 = 0;
   FlexCAN0_MB4_1 = 0;
   FlexCAN0_MB4_2 = 0;
   FlexCAN0_MB4_3 = 0;

   FlexCAN0_RXIMR4 = 0xFFFFFFFF;

   FlexCAN0_RXMGMASK = 0x1FFFFFFF;

   FlexCAN0_MB4_0 |= ((0b0100)<<CODE);

#ifdef NODE_A
   FlexCAN0_MB4_1 |= ((0x511)<<STD_ID);
#else
   FlexCAN0_MB4_1 |= ((0x555)<<STD_ID);
#endif

   FlexCAN0_MCR |= ((0x1F)<<MAXMB);
   FlexCAN0_MCR &= ~(1<<HALT);

   while((FlexCAN0_MCR & (1<<FRZACK)));
   while((FlexCAN0_MCR & (1<<NOTRDY)));
}


void CAN_transmit_msg(uint32_t sw_flag){
   FlexCAN0_IFLAG1 |= 0x00000001;

   FlexCAN0_MB0_2 = sw_flag;
   FlexCAN0_MB0_3 = 0x44556677;

#ifdef NODE_A
   FlexCAN0_MB0_1 |= ((0x555)<<STD_ID);
#else
   FlexCAN0_MB0_1 |= ((0x511)<<STD_ID);
#endif
   FlexCAN0_MB0_0 |= (12<<CODE) | (1<<SRR) | (8<<DLC);
}


void CAN_receive_msg(void){
   uint32_t dummy;

   RxDATA[0] = FlexCAN0_MB4_2;
   RxDATA[1] = FlexCAN0_MB4_3;

   dummy = FlexCAN0_TIMER;

   FlexCAN0_IFLAG1 |= 0x00000010;
}


void CAN_PORT_init(void){
   PCC_PORTC |= (1<<CGC);
   PORTC_PCR12 &= ~((0b111)<<MUX);
   PORTC_PCR12 |= ((0b001)<<MUX);
   GPIOC_PDDR &= ~(1<<PTC12);

   PCC_PORTD |= (1<<CGC);
   PORTD_PCR16 &= ~((0b111)<<MUX);
   PORTD_PCR16 |= ((0b001)<<MUX);
   GPIOD_PDDR |= (1<<PTD16);


   PCC_PORTE |= (1<<CGC);
   PORTE_PCR4 &= ~((0b111)<<MUX);
   PORTE_PCR4 |= ((0b101)<<MUX);
   PORTE_PCR5 &= ~((0b111)<<MUX);
   PORTE_PCR5 |= ((0b101)<<MUX);
}

void LPIT0_Ch0_IRQHandler(void){
   flag = ((GPIOC_PDIR & (1<<PTC12)) >> PTC12);

   CAN_transmit_msg(flag);
   LPIT_MSR |= (1<<TIF0);
}
