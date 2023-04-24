/*
 APPLICATION - BLINK LED ON THE PRESS OF BUTTON
 LED - PA5
 BUTTON - PC13(ALWAYS IN HIGH-STATE)

 */

#include"main.h"

void Delay(int t)
{
while(t--)
{
	for(int i=0;i<4000;i++);
}
}

void ledon()
{
	GPIOA->BSRR |=0x20;
}

void ledoff()
{
	GPIOA->BSRR |= 0x200000;
}

int main()
{


	//RCC->AHB1ENR |=0x1;// ENABLE PORT A

	//RCC->AHB1ENR |=0x4;// ENABLE PORT C
	RCC->AHB1ENR |=0x5;// ENABLE PORT all

	GPIOA->MODER |=0x400;// SET THE PIN A5 AS GPIO OUT
	GPIOC->MODER |=0x00;// SET THE PIN C6 AS GPIO IN

	while(1)
	{
		int c= (GPIOC->IDR );
		if(c & 0x2000)
		{
			ledoff();
			Delay(10);
		}
		else
		{
			ledon();
			Delay(10);

		}

	}

}
