#include"main.h"
void delay(int T)
{
   int i;
    while (T--){
    	for(i=0;i<500;i++);

    	}
    }

void led_toggleon(){
	    GPIOA->ODR |= 0x20;
}
void led_toggleOff(){
	GPIOA->ODR &= ~(0x20);
}
int main(){
	RCC->AHB1ENR |= 0x5;
	GPIOA->MODER |= 0x400;
	GPIOC->MODER |= 0x0000;


		while(1){

		int a = (GPIOC->IDR |= 0x0000);

		 if(a==0){
			led_toggleon();
			delay(10);
		}
		else {
			led_toggleOff();
			delay(10);
		}
		}
	}
