#include "S32K144.h"
#include "clocks_and_modes.h"
#include "device_registers.h"


#define PCC_BASE (0x40065000)
#define PCC_FlexCAN0 *((volatile unsigned*)(PCC_BASE + 0x90))
#define PCC_LPIT *((volatile unsigned*)(PCC_BASE + 0xDC))
#define PCC_PORTC *((volatile unsigned*)(PCC_BASE + 0x12C))
#define PCC_PORTD *((volatile unsigned*)(PCC_BASE + 0x130))
#define PCC_PORTE *((volatile unsigned*)(PCC_BASE + 0x134))

#define CGC 30
#define PCS 24


#define PORTC_BASE (0x4004B000)
#define PORTC_PCR12  *((volatile unsigned*)(PORTC_BASE + 0x30))

#define PORTD_BASE (0x4004C000)
#define PORTD_PCR16  *((volatile unsigned*)(PORTD_BASE + 0x40))

#define PORTE_BASE (0x4004D000)
#define PORTE_PCR4  *((volatile unsigned*)(PORTE_BASE + 0x10))
#define PORTE_PCR5  *((volatile unsigned*)(PORTE_BASE + 0x14))

#define MUX 8

#define FlexCAN0_BASE (0x40024000)
#define FlexCAN0_MCR *((volatile unsigned*)(FlexCAN0_BASE+0x0))
#define FlexCAN0_CTRL1 *((volatile unsigned*)(FlexCAN0_BASE+0x4))
#define FlexCAN0_TIMER *((volatile unsigned*)(FlexCAN0_BASE+0x8))
#define FlexCAN0_RXMGMASK *((volatile unsigned*)(FlexCAN0_BASE+0x10))
#define FlexCAN0_IFLAG1 *((volatile unsigned*)(FlexCAN0_BASE+0x30))
#define FlexCAN0_MB0_0 *((volatile unsigned*)(FlexCAN0_BASE+0x80))
#define FlexCAN0_MB0_1 *((volatile unsigned*)(FlexCAN0_BASE+0x84))
#define FlexCAN0_MB0_2 *((volatile unsigned*)(FlexCAN0_BASE+0x88))
#define FlexCAN0_MB0_3 *((volatile unsigned*)(FlexCAN0_BASE+0x8C))
#define FlexCAN0_MB4_0 *((volatile unsigned*)(FlexCAN0_BASE+0xC0))
#define FlexCAN0_MB4_1 *((volatile unsigned*)(FlexCAN0_BASE+0xC4))
#define FlexCAN0_MB4_2 *((volatile unsigned*)(FlexCAN0_BASE+0xC8))
#define FlexCAN0_MB4_3 *((volatile unsigned*)(FlexCAN0_BASE+0xCC))
#define FlexCAN0_RXIMR4 *((volatile unsigned*)(FlexCAN0_BASE+0x890))

#define MDIS 31
#define FIZ 30
#define HALT 28
#define NOTRDY 27
#define FRZACK 24
#define MAXMB 0
#define RJW 22
#define PSEG1 19
#define PSEG2 16
#define CLKSRC 13
#define SMP 7
#define PROPSEG 0
#define BUF4T01I 1
#define BUF0I 0
#define CODE 24
#define SRR 22
#define DLC 16
#define STD_ID 18

#define GPIOC_BASE (0x400FF080)
#define GPIOC_PDIR *((volatile unsigned*)(GPIOC_BASE+0x10))
#define GPIOC_PDDR *((volatile unsigned*)(GPIOC_BASE+0x14))

#define GPIOD_BASE (0x400FF0C0)
#define GPIOD_PSOR  *((volatile unsigned*)(GPIOD_BASE+0x4))
#define GPIOD_PCOR  *((volatile unsigned*)(GPIOD_BASE+0x8))
#define GPIOD_PTOR  *((volatile unsigned*)(GPIOD_BASE+0xC))
#define GPIOD_PDDR  *((volatile unsigned*)(GPIOD_BASE+0x14))

#define PTC12 12
#define PTD16 16


#define LPIT_BASE (0x40037000)
#define LPIT_MCR  *((volatile unsigned*)(LPIT_BASE+0x8))
#define LPIT_MSR  *((volatile unsigned*)(LPIT_BASE+0xC))
#define LPIT_MIER *((volatile unsigned*)(LPIT_BASE+0x10))
#define LPIT_TVAL0 *((volatile unsigned*)(LPIT_BASE+0x20))
#define LPIT_TCTRL0 *((volatile unsigned*)(LPIT_BASE+0x28))

#define M_CEN 0
#define TIF0 0
#define TIE0 0
#define MODE 2
#define T_EN 0

#define NVIC_ISER_BASE (0xE000E100)
#define NVIC_ISER1 *((volatile unsigned*)(NVIC_ISER_BASE+0x4))

#define NVIC_ICPR_BASE (0xE000E280)
#define NVIC_ICPR1 *((volatile unsigned*)(NVIC_ICPR_BASE + 0x4))

#define NVIC_IPR_BASE (0xE000E400)
#define NVIC_IPR48 *((volatile unsigned*)(NVIC_IPR_BASE + 0x30))





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


int main(void){ // pass

   SOSC_init_8MHz();
   SPLL_init_160MHz();
   NormalRunmode_80MHz();

   CAN_init();
   CAN_PORT_init();
   NVIC_init_IRQs();
   LPIT0_init();


   while(1){
      if((FlexCAN0_IFLAG1 & (1<<4))!= 0)
         CAN_receive_msg();

      if(RxDATA[0]!=0)
         GPIOD_PCOR |= (1<<PTD16);
      else
         GPIOD_PSOR |= (1<<PTD16);

   }
}

void LPIT0_Ch0_IRQHandler(void){
   flag = ((GPIOC_PDIR & (1<<PTC12)) >> PTC12);

   CAN_transmit_msg(flag);
   LPIT_MSR |= (1<<TIF0);
}
