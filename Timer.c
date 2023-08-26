#include "Timer.h"
//#include "stm32f10x.h"
#include "gp_drive.h"


	/*
	CCER = (volatile unsigned long *)(&Timer_2 + 8);     //Base timer2 address + 8 --> increment by 8 memory spaces to reach the CCER register.
	*CCER |= (0x01<<0);  //channel 1 enabled
	CR1 = (volatile unsigned long *) (&Timer_2 + 0);
	*CR1 |= (0x01 << 7);
	CCMR1 = (volatile unsigned long *) (&Timer_2 + 6);
	*CCMR1 |= (0x06 << 4);
	*CCMR1 |= (0x01 <<3);
	
	//PWM freq = Fclk/PSC/ARR  72Mhz/72000 = 1Kzh pwm	
	PSC = (volatile unsigned long *)(&Timer_2 + 10);
	*PSC = 72;
	ARR = (volatile unsigned long*)(&Timer_2 +11); 
	*ARR = freq *1000;
	CCR = (volatile unsigned long *)(&Timer_2 + 13);
	
	if(dutycycle == 25){
		*CCR = (freq*1000)/4;
	}
	else if (dutycycle==50){
		*CCR = (freq*1000)/2;}
	
	EGR = (volatile unsigned long *) (&Timer_2 +5);
	*EGR |= (0x01)<<0;   ////update on reaching desired counter
	*CR1 |= (0x01)<<0;  //Counter intiated here:start counting here
		*/



/* Init funtion for timer */
void Timer_init(unsigned short port,unsigned short pin,unsigned short timer,unsigned short freq,unsigned short dutycycle){
	
	init_gpio(port,pin,OP_50,O_GP_PP,1);
	
switch(timer){
	
	case 2:    //If it is Timer2
	RCC_APB1ENR |= 0x01;   //Timer2 will be enabled
	 Timerfunc(&Timer_2,freq,dutycycle); break;
	  case 3:
		RCC_APB1ENR |= (1<<1); 
	  Timerfunc(&Timer_3,freq,dutycycle); break;
		case 4: 
		RCC_APB1ENR |= (0x01<<2);
		
    Timerfunc( &Timer_4,freq,dutycycle);		break;
	  case 5: 
	//	RCC_APB1ENR &= ~(1<<3);
		RCC_APB1ENR |= 0x08;
    Timerfunc(&Timer_5,freq,dutycycle);	break;
	
	default :
		break;

	
}}

void Timerfunc(volatile unsigned long* var,unsigned short freq,unsigned short dutycycle){
	
	
		volatile unsigned long *CCER;  //Pointer variables for storing the address
	volatile unsigned long *CR1;
	volatile unsigned long *CCMR1;
	//volatile unsigned long *CCMR2;
	volatile unsigned long *EGR;
	
	volatile unsigned long *PSC, *ARR, *CCR;
	
			CCER = (volatile unsigned long *)(var + 8);     //Base timer2 address + 8 --> increment by 8 memory spaces to reach the CCER register.
	*CCER |= (0x01<<0);  //channel 1 enabled
	CR1 = (volatile unsigned long *) (var + 0);
	*CR1 |= (0x01 << 7);
	CCMR1 = (volatile unsigned long *) (var + 6);
	*CCMR1 |= (0x06 <<4);
	*CCMR1 |= (0x01 <<3);
	
	//PWM freq = Fclk/PSC/ARR  72Mhz/72000 = 1Kzh pwm	
	PSC = (volatile unsigned long *)(var + 10);
	*PSC = 72;
	ARR = (volatile unsigned long*)(var +11); 
	*ARR = freq *1000;
	CCR = (volatile unsigned long *)(var + 13);
	
	if(dutycycle == 25){
		*CCR = (freq*1000)/4;
	}
	else if (dutycycle==50){
		*CCR = (freq*1000)/2;}
	
	EGR = (volatile unsigned long *) (var +5);
	*EGR |= (0x01)<<0;   ////update on reaching desired counter
	*CR1 |= (0x01)<<0;  //Counter intiated here:start counting here
	

	
}

	
unsigned int Pwm_Out(unsigned short timer){
	volatile unsigned long *CNT;
	if(timer ==2){
		CNT = (volatile unsigned long *) (&Timer_2 + 0);
		return *CNT;}
		else if(timer ==3){
		CNT = (volatile unsigned long *) (&Timer_3 + 0);
		return *CNT;}
		else {
		CNT = (volatile unsigned long *) (&Timer_4 + 0);
		return *CNT;}
}


