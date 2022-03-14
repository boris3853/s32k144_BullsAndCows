#ifndef CAN_H_
#define CAN_H_

#include "define.h"

void CAN_init(void);
void CAN_transmit_msg(uint32_t sw_flag);
void CAN_receive_msg(void);

#endif /* CAN_H_ */
