/*
 * hw.h
 *
 *  Created on: 2022. 5. 14.
 *      Author: otaru
 */

#ifndef SRC_BSP_HW_HW_H_
#define SRC_BSP_HW_HW_H_

#include "def.h"

void bspInit(void);

void delay(uint32_t ms);
uint32_t millis(void);

void Error_Handler(void);

#endif /* SRC_BSP_HW_HW_H_ */
