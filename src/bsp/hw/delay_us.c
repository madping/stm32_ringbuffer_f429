#include "delay_us.h"

#define SYS_CLOCK    216
#define SYSTICK_LOAD 215999

/*
void delay(uint32_t ms)
{
	HAL_Delay(ms);
}

uint32_t mill(void)
{
	return HAL_GetTick();
}
*/

uint32_t millis_cnt=0;

uint32_t millis(){
    return millis_cnt;
}

uint32_t micros(){
    return (millis_cnt&0x3FFFFF)*1000 + (SYSTICK_LOAD-SysTick->VAL)/SYS_CLOCK;
}

void delay_us(uint32_t us){
    uint32_t temp = micros();
    uint32_t comp = temp + us;
    uint8_t  flag = 0;
    while(comp > temp){
        uint32_t mil = millis_cnt;
        if(((mil&0x3FFFFF)==0)&&(mil>0x3FFFFF)&&(flag==0)){
            flag = 1;
        }
        if(flag) temp = micros() + 0x400000UL * 1000;
        else     temp = micros();
    }
}
