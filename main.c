/*
Generating a PWM signal of 1KHZ using Timer4 
We can change frequency by changing TIM4->CCR4 value. 

*/


#include "stm32f10x.h"
#include "gp_drive.h"
#include "Delay.h"
#include "Timer.h"
unsigned int i=0;
int main(){
	init_gpio(PA,8,OP_50,O_GP_PP,0);
	init_gpio(PB,9,OP_50,O_GP_PP,1);
	DelayInit();
		
 Timer_init(PB,9,4,1,50);

	
	while(1){
	
	 //led blinking with 1Khz signal frequeny
		//TIM2, TIM3,TIM4 can be 
		i=Pwm_Out(4);
Write_gp(PB,9,i);
		
	}
		
	
	
}


