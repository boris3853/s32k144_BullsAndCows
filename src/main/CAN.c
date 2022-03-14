#include "CAN.h"

#define NODE_A

uint32_t RxDATA[2];
uint32_t flag;

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
