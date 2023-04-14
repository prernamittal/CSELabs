#include <LPC17xx.h>
 unsigned int i,x=0;
 unsigned char array_dec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 unsigned int dig_value[4]={1,2,3,4};
 
void display(void)      //To Display on 7-segments
{
	LPC_GPIO1->FIOPIN = x<<23;               
	LPC_GPIO0->FIOPIN = array_dec[dig_value[x]]<<4; 
  x=(x+1)%4;	
}

void delay(void)
{ 
	for(i=0;i<100000;i++);	
}
 
int main(void)
{
SystemInit(); 
SystemCoreClockUpdate();
LPC_PINCON->PINSEL0 &= 0xFF0000FF; //Configure Port0 PINS P0.4-P0.11 as GPIO function
LPC_PINCON->PINSEL3 &= 0xFFC03FFF; //P1.23 to P1.26
LPC_GPIO0->FIODIR |= 0xFF<<4;	//P0.4 to P0.11 output         
LPC_GPIO1->FIODIR |= 0XF<<23;	//P1.23 to P1.26 output 
while(1)
{
	delay();
	display();
} //end of while(1)
}//end of main



