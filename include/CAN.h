#ifndef CAN_H_
#define CAN_H_

#include "define.h"

void NVIC_init_IRQs(void);
void LPIT0_init(void);
void CAN_init(void);
void CAN_transmit_msg(uint32_t sw_flag);
void CAN_receive_msg(void);
void CAN_PORT_init(void);

#endif /* CAN_H_ */
