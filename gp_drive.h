#define RCC_APB2ENR    (*((volatile unsigned long *) 0x40021018))  //pointers for these address. memory address from RF manu
																																	 // manual i.e from memory map topic.
	
#define GPIO_A    (*((volatile unsigned long *) 0x40010800))
#define GPIO_B    (*((volatile unsigned long *) 0x40010C00))
#define GPIO_C    (*((volatile unsigned long *) 0x40011000))
#define GPIO_D    (*((volatile unsigned long *) 0x40011400))

// CRL and CRH registers in the GPIO selection
#define PA 1     // port selection
#define PB 2
#define PC 3
#define PD 4

//direction -dir
#define IN 0				// input mode
#define OP_10 1			//output with 10kHz ,2kHz,50Khz
#define OP_2 2
#define OP_50 3

//OPT - INPUT mode
#define I_AN 0     //input selection with analog mode, float mode, push pull
#define I_F 1
#define I_PP 2

//OPT --OUTPUT mode
#define O_GP_PP 0     //output selection with general purpose push pull, open drain
#define O_GP_OD 1			
#define O_AF_PP 2			// alaternative function with push pull, open drain
#define O_AF_OD 3

// write state of GPIO
#define LOW 0
#define HIGH 1

//alternate function enable
#define alt_en 1;
#define alt_dis 0;

void init_gpio(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt,unsigned short alt);

int Read_gp (unsigned short port, unsigned short pin);
void Write_gp(unsigned short port, unsigned short pin, unsigned state);

/*Driver usage
PA, PB PC, PD are the port selections 

dir - It defines the INPUT or OUTPUT modes 
if dir - IN or 0. Pin will go into INput mode
THE GPIOx_CRL register with CNF blocks will set to input 

The OPT in init_gpio will be activate for the INPUT modes
i.e I_AN, I_F, I_PP

when the dir is set to other than 0 of IN, registers will be set to
OUPUT modes.
NOW the OPT will activate the OUPUT modes available 
i.e O_GP_PP,O_GP_OD ,O_GP_PP,O_GP_OD.

alt - defines whether gpio will be used for alternate functions like timers ,spi..
*/

