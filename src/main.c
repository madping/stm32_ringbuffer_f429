#include "main.h"


int main(void)
{


	bspInit();
	Segment_Init();

	//uartInit();


	//LED_Init();

    //uartOpen(_DEF_UART1, 57600);

   uint8_t fnd [] = {0x7B, 0x0A, 0xB3, 0x9B, 0xCA, 0xD9, 0xF9, 0x0B, 0xFB, 0xDB};


	while(1)
	{


          /*
		  if(uartAvailable(_DEF_UART1)>0)
		  {
			 uint8_t rx_data;

			 rx_data = uartRead(_DEF_UART1);
		     uartPrintf(_DEF_UART1, "uart1 %c %X\n", rx_data, rx_data);

		  }
		  */

	   for(int i=0; i<=10; i++)
	   {
           GPIOB -> ODR = fnd[i];
	       HAL_Delay(1000);
	   }

	}

	return 0;
}

