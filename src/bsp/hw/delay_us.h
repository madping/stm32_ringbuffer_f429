
#ifndef SRC_BSP_HW_DELAY_US_H_
#define SRC_BSP_HW_DELAY_US_H_

#include "def.h"
#define delay_ms HAL_Delay


void delay_us(uint32_t us);
void delay(uint32_t ms);
uint32_t millis();

#endif /* SRC_BSP_HW_DELAY_US_H_ */
