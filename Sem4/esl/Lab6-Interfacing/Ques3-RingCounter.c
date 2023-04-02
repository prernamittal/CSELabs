#include <LPC17xx.h>
unsigned int i,j; 
unsigned long LED = 0x10;
int main(void)
{
	SystemInit(); 
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF; 
	LPC_PINCON->PINSEL4 &= 0xF0FFFFFF; 
	LPC_GPIO2->FIODIR &= ~(1 << 12); 
	LPC_GPIO0->FIODIR |= 0xFF0; 
	LED = 0x10; 

	while(1)
 {
	  if ( (LPC_GPIO2->FIOPIN & (1 << 12)) == 0 ) {
						LPC_GPIO0->FIOCLR = LED;
						for(j=0;j<5000;j++); 
						LED <<= 1;
						if (LED == (0x10 << 8))
							LED = 0x10;
				
		}
			LPC_GPIO0->FIOSET = LED; 
			for(j=0;j<5000;j++); 
	}
}