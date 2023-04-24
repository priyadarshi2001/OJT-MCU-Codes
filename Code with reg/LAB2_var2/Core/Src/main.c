#include "main.h"


int main(){

	RCC->AHB1ENR |= 0x5;      //STEP1 : Enable Port Clock on AHB1
	GPIOA->MODER |= 0x400;    //STEP2 : Set the mode of PA & PC
	GPIOC->MODER |= 0x00;

	while(1){
		//STEP3 : Read the Pin status for PC
		if(GPIOC->IDR & 0x2000){
			GPIOA->BSRR |= 0x200000;    // LED   OFF
		}else{
			GPIOA->BSRR |= 0x20;        // LED  ON
		}
	}

}
