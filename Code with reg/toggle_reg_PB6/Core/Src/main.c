/*
 Application - it is to toggle the LED

 GPIO's - GPIO Port A pin 5

 step1- enable AHB1
 step2- enable MODER
 step3- select the output or input
 step4- set the logic to toggle the LED
 */


#include "main.h"

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
	//for blink of PB 4
	RCC->AHB1ENR |=0x2;
	GPIOB->MODER |=0x1000;
	while(1)
	{
		GPIOB->ODR |= 0x40;
		delay(500);
		GPIOB->ODR |= (0x40);
		delay(500);
	}
}
