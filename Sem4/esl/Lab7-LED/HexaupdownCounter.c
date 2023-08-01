#include<LPC17xx.h>

int i,j;
unsigned int seg[16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
int d[4];

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0XFF0000FF; // OUTPUT TO 7 SEG 0.4-0.11
	LPC_PINCON->PINSEL3 = 0X0; // DECODER TO ENABLE 1.23-1.26
	
	LPC_GPIO0->FIODIR = 0X00000FF0; //SETTING OUTPUUT PINS
	LPC_GPIO1->FIODIR |= 0X07800000; // SETTING OUTPUT PINS

	LPC_PINCON->PINSEL1 = 0x0;
	
	while(1)
	{
		unsigned int k = ((LPC_GPIO0->FIOPIN)&(1<<21));
		
		if(k==0){
			for(d[3] = 0 ;d[3] < 16;d[3]++){		
				for(d[2] = 0 ; d[2] < 16 ; d[2] ++ ){	
					for(d[1] = 0; d[1] < 16 ; d[1]++){
						for(d[0] = 0; d[0] <16; d[0]++){
							for(i = 0; i < 4; i++){
								LPC_GPIO1->FIOPIN = i << 23;
								LPC_GPIO0->FIOPIN = seg[d[i]]<<4;
								for(j = 0; j<10000 ; j++);						
							}
							for(j = 0; j<10000 ; j++);	
							LPC_GPIO0->FIOCLR = 0X00000FF0;				
					
						}
				
					}		
				}		
			}
		}
		else{
			for(d[3] = 15 ;d[3] >= 0 ;d[3]--){		
				for(d[2] = 15 ; d[2] >=0  ; d[2] -- ){		
					for(d[1] = 15; d[1] >=0; d[1]--){
						for(d[0] = 15; d[0]>=0; d[0]--){
							for(i = 3; i >= 0 ; i--){
								LPC_GPIO1->FIOPIN = i << 23;
								LPC_GPIO0->FIOPIN = seg[d[i]]<<4;
								for(j = 0; j<10000 ; j++);		
							}
							for(j = 0; j<10000 ; j++);		
							LPC_GPIO0->FIOCLR = 0X00000FF0;				
						}
					}		
				}		
			}
		}
	}
}
