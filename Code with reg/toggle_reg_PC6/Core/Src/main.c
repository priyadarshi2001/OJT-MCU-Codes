/*
 Application - it is to toggle the LED

 GPIO's - GPIO Port A pin 6

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
	//for blink of PC 6
	RCC->AHB1ENR |=0x4;
	GPIOA->MODER |=0x1000;
	while(1)
	{
		GPIOA->ODR |=0x40;
		delay(500);
		GPIOA->ODR &= ~(0x40);
		delay(500);
	}
}
