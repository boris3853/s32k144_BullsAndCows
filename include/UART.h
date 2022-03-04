
#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>
#include "define.h"

void UART_PORT_init(void);
void LPUART1_init(void);
char LPUART1_receive_char(void);
void LPUART1_transmit_char(char send);
void LPUART1_transmit_string(char data_string[]);

#endif  /* UART_H */
