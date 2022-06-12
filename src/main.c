#include "main.h"


int main(void)
{


	bspInit();
	uartInit();


	//LED_Init();

    uartOpen(_DEF_UART1, 57600);

    //uint32_t pre_time;
    //pre_time = millis();


	while(1)
	{

		//if(millis()-pre_time >= 100)
		//{
		//	 pre_time = millis();

		  if(uartAvailable(_DEF_UART1)>0)
		  {
			 uint8_t rx_data;

			 rx_data = uartRead(_DEF_UART1);
		     uartPrintf(_DEF_UART1, "uart1 %c %X\n", rx_data, rx_data);

		  }
		//}

	}

	return 0;
}

