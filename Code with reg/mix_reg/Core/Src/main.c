#include"main.h"

void Delay(int t)
{
while(t--)
{
	for(int i=0;i<4000;i++);
}
}


int main()
{
	//DISABLE THE JTAG
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

//	RCC->AHB1ENR |=0x1;// ENABLE PORT A
//	RCC->AHB1ENR |=0x2;// ENABLE PORT B
//	RCC->AHB1ENR |=0x4;// ENABLE PORT C
	RCC->AHB1ENR |=0x7;// ENABLE PORT A,B,C

	GPIOA->MODER |=0x400;// SET THE PIN A5 AS GPIO OUT
	GPIOA->MODER |=0x1000;// SET THE PIN A6 AS GPIO OUT
	GPIOB->MODER |=0x1000;// SET THE PIN B6 AS GPIO OUT
	GPIOC->MODER |=0x1000;// SET THE PIN C6 AS GPIO OUT
while(1)
	{
	GPIOA->ODR |=0X20;// PASS THE DIGITAL ONE SGNAL TO 5TH PIN of PORT A
	Delay(250);
	GPIOA->ODR &= ~(0X20);// PASS THE DIGITAL ZERO SIGNAL TO 5TH PIN of PORT A
	Delay(250);

	GPIOA->ODR |=0X40;// PASS THE DIGITAL ONE SGNAL TO 6TH PIN of PORT A
	Delay(250);
	GPIOA->ODR &= ~(0X40);// PASS THE DIGITAL ZERO SIGNAL TO 6TH PIN of PORT A
	Delay(250);

	GPIOB->ODR |=0X40;// PASS THE DIGITAL ONE SGNAL TO 4TH PIN of PORT B
	Delay(250);
	GPIOB->ODR &= ~(0X40);// PASS THE DIGITAL ZERO SIGNAL TO 4TH PIN of PORT B
	Delay(250);

	GPIOC->ODR |=0X40;// PASS THE DIGITAL ONE SGNAL TO 5TH PIN of PORT C
	Delay(250);
	GPIOC->ODR &= ~(0X40);// PASS THE DIGITAL ZERO SIGNAL TO 5TH PIN of PORT C
	Delay(250);
	}
}