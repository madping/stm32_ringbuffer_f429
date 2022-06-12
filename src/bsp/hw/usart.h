#ifndef SRC_BSP_HW_USART_H_
#define SRC_BSP_HW_USART_H_

#include "def.h"

//#ifdef _USE_HW_UART



#define UART_MAX_CH    1

#define _DEF_UART1     0
#define _DEF_UART2     1
#define _DEF_UART3     2
#define _DEF_UART4     3

extern UART_HandleTypeDef huart1;

//void MX_USART3_UART_Init(void);
void Error_Handler(void);



bool     uartInit(void);
bool     uartOpen(uint8_t ch, uint32_t baud);
uint32_t uartAvailable(uint8_t ch);
uint8_t  uartRead(uint8_t ch);
uint8_t  uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length);
uint32_t uartPrintf(uint8_t ch, char *fmt, ...);
uint32_t uartGetBaud(uint8_t ch);


#endif
//#endif
