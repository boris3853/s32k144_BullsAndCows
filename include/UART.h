
#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

#define PCC_PORTC *((volatile unsigned*)(PCC_BASE + 0x12C)) // uart re, tr
#define PCC_LPUART1 *((volatile unsigned*)(PCC_BASE + 0x1AC))

#define CGC 30 // Clock Enable
#define PCS 24 // Peripheral Clock Source Select(0b010)


#define PORTC_BASE (0x4004B000)
#define PORTC_PCR6 *((volatile unsigned*)(PORTC_BASE+0x18))
#define PORTC_PCR7 *((volatile unsigned*)(PORTC_BASE+0x1C))


#define LPUART1_BASE (0x4006B000)
#define LPUART1_BAUD *((volatile unsigned*)(LPUART1_BASE + 0x10))
#define LPUART1_STAT *((volatile unsigned*)(LPUART1_BASE + 0x14))
#define LPUART1_CTRL *((volatile unsigned*)(LPUART1_BASE + 0x18))
#define LPUART1_DATA *((volatile unsigned*)(LPUART1_BASE + 0x1C))

#define M10 29
#define OSR 24
#define SBNS 13
#define SBR 0
#define TDRE 23
#define RDRF 21
#define TE 19
#define RE 18
#define M7 11
#define M 4
#define PE 1

void UART_PORT_init(void);
void LPUART1_init(void);
char LPUART1_receive_char(void);
void LPUART1_transmit_char(char send);
void LPUART1_transmit_string(char data_string[]);

#endif  /* UART_H */
