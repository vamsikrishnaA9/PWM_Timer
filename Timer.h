/* This library is developed on 5/31/2023. by Vamsi 
This is mainly usedfor the PWM wave generation for the stepper motors. 
In this library I have taken general purpose timers for the generation of PWM wave with required frequency. 
Through this library we can only enable Tim2, Tim3, Tim4, Tim5 general purpose timers.

Each Timer in stm32F103 have 4 different channels for the genartion of PWM wave. I have designed using different channels for the different timers.

This library only sets all the required registers and Timx->CNT has the PWM signal. We have to use this to write on the GPIO pin to enable the 
actual pwm signal out. for continious siganl generation we have to write it in the loop.
*/


#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "stdbool.h"	 

#define RCC_APB1ENR  (*((volatile unsigned long *) 0x4002101C))

#define Timer_2 (*((volatile unsigned long *) 0x40000000))
#define Timer_3 (*((volatile unsigned long *) 0x40000400))
#define Timer_4 (*((volatile unsigned long *) 0x40000800))
#define Timer_5 (*((volatile unsigned long *) 0x40000C00))

#define Timer2 2;
#define Timer3 3;
#define Timer4 4;
#define Timer5 5;



#define duty_cycle1 25
#define duty_cycle2 50
//#define duty_cycle3 75


/* Frequency can be given only in even numbers 
ex : 1 - 1khz,
     2 - 2khz,
     10 - 100hz. There is difference in the calcuation part. check the .c file to exact function
Duty cycle is given only in 2 modes i.e 25 - clock is divided by 4 and only 25% is the time signal will be active.
                                        50 - clock is divided by 2, 50% of the time pwm will be active.  */


	
void Timer_init(unsigned short port,unsigned short pin,unsigned short timer,unsigned short freq, unsigned short dutycycle);
//void Pwm_set(unsigned short  freq, unsigned short  dutycycle);


void Timerfunc(volatile unsigned long* var, unsigned short freq, unsigned short dutycycle);

unsigned int Pwm_Out(unsigned short timer);



#ifdef __cplusplus
}
#endif

#endif
