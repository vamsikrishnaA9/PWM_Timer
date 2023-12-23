# PWM Timer
## Bare metal STM32 PWM driver  
**Software used** Keil  
**Micro controller** STM32F103C8T6  
**Hardware Module** STM32 Bluepill


This library is used to generate the PWM wave of a desired frequency on STM32.
To generate the PWM signal I have used Timers in STM32.

### Key Points
TIM2, TIM3, TIM4, TIM5 can only enabled through this library.

### Timer Library usage

_1.void Timer_init(unsigned short port,unsigned short pin,unsigned short timer,unsigned short freq, unsigned short dutycycle)_  
_ex : Timer_init(PB,9,4,1,50); Port PB, Pin - 9, Timer4, Freq1- 1Khz, 50 - 50% Dutycycle_

**PORT** PA, PB, PC - Ports which support the PWM signal  
**PIN** GPIO pins which support PWM signal  
**Timer** Specify the Number on which the timer should be active  
`Timer2 - 2, Timer3 -3, Timer4 -4, Timer5 -5`  
**Freq** Desried Frequency  
Frequency should be in even numbers only.  
1- 1Khz  
2- 2Khz  
3- 3Khz... until 9- 9Khz,but  
10 - 100hz  
20 -200hz...  
There is a change in the calculation of frequency in the Prescaler `PSC` and Autoreload `ARR` registers.  
**dutycycle** This function supports only 25% and 50%.  

_2. unsigned int Pwm_Out(unsigned short timer);_  
**General usage **  
_unsigned int i = Pwm_Out(Timer4);_  
This function generates the PWM signal on the mentioned pin and Timer.












