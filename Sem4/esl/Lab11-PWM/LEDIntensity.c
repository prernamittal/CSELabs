#include<LPC17xx.h>

void initPWM(void);
void updatePulseWidth(unsigned int pulseWidth);
void delayMS(unsigned int milliseconds);
int scan(void);
unsigned int temp3;
int pulsewidth[]={0,2500,5000,10000};
int dir=0;

int main(void){
	LPC_GPIO0->FIODIR = 0xf00;
	initPWM();
	while(1)
	{
		int count=scan();
		if(count==0x1)
			updatePulseWidth(pulsewidth[0]);
		else if(count==0x2)
			updatePulseWidth(pulsewidth[1]);
		else if(count==0x4)
			updatePulseWidth(pulsewidth[2]);
		else if(count==0x8)
			updatePulseWidth(pulsewidth[3]);
		delayMS(100000);
	}
}

int scan(void){
	LPC_GPIO0->FIOSET = 0x100;
	temp3 = LPC_GPIO0->FIOPIN;
	temp3 &= 0xf0;
	if(temp3!=0)
		return temp3>>4;
	return 1;
}

void initPWM(void){
	LPC_PINCON->PINSEL3 |= 0x8000; //Select PWM1.4 output for Pin1.23, function 2
	LPC_PWM1->PCR = 0x1000; //enable PWM1.4, by default it is single Edged 
	LPC_PWM1->PR = 0; 
	LPC_PWM1->MR0 = 30000; //period=10ms if pclk=cclk/4
	LPC_PWM1->MCR = (1<<1); //Reset PWM TC on PWM1MR0 match
	LPC_PWM1->LER = 0xff; //update values in MR0 and MR1
	LPC_PWM1->TCR = 0x00000002; //RESET COUNTER TC and PC
	LPC_PWM1->TCR = 0x00000009; //enable TC and PC
}

void updatePulseWidth(unsigned int pulseWidth){
	LPC_PWM1->MR4 = pulseWidth; //Update MR4 with new value
	LPC_PWM1->LER = 0xff; //Load the MR4 new value at start of next cycle
}
void delayMS(unsigned int milliseconds){ //Using Timer0
	LPC_TIM0->CTCR = 0x0; //Timer mode
	LPC_TIM0->PR = 2; //Increment TC at every 3 pclk
	LPC_TIM0->TCR = 0x02; //Reset Timer
	LPC_TIM0->TCR = 0x01; //Enable timer
	while(LPC_TIM0->TC < milliseconds); //wait until timer counter reaches the desired delay
	LPC_TIM0->TCR = 0x00; //Disable timer
}
