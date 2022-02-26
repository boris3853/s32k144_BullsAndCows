#ifndef CLOCKS_AND_MODES_H_
#define CLOCKS_AND_MODES_H_

#include "device_registers.h"	/* include peripheral declarations S32K144 */

void SOSC_init_8MHz(void);
void SPLL_init_160MHz(void);
void NormalRUNmode_80MHz (void);

#endif /* CLOCKS_AND_MODES_H_ */
