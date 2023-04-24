/*
 Application - it is to toggle the LED

 GPIO's - GPIO Port A pin 5

 step1- enable AHB1
 step2- enable MODER
 step3- select the output or input
 step4- set the logic to toggle the LED
 */

#include <stdint.h>
#include "main.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_conf.h"

void delay(int t)
{
	while(t--)
		{
		int i;
		for(i=0;i<4000;i++);
		}
}

int main()
{
	//for blink of PA 5
	RCC->AHB1ENR |=0x1;
	GPIOA->MODER |=0x400;
	while(1)
	{

		GPIOA->BSRR =0x20;
		//delay(500);
		HAL_Delay(1000);

		GPIOA->BSRR =0x200000;
		//delay(500);
		HAL_Delay(1000);

	}
}
