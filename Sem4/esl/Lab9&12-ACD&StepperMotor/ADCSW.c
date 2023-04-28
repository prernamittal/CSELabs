#include<LPC17xx.h>
#include<stdio.h>
#define	Ref_Vtg		3.300
#define	Full_Scale	0xFFF			//12 bit ADC

void lcd_init(void);
void write(int, int);
void delay_lcd(unsigned int);
void lcd_comdata(int, int); 
void clear_ports(void);
void lcd_puts(unsigned char *);
//lcd initialization
void lcd_init()
{
	/*Ports initialized as GPIO */
	 LPC_PINCON->PINSEL1 &= 0xFC003FFF; //P0.23 to P0.28
	/*Setting the directions as output */
	 LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;
	 
	 clear_ports();
	delay_lcd(3200);
	lcd_comdata(0x33, 0); 
	delay_lcd(30000); 
	lcd_comdata(0x32, 0);
	delay_lcd(30000);
	lcd_comdata(0x28, 0); //function set
	delay_lcd(30000);
	lcd_comdata(0x0c, 0);//display on cursor off
	delay_lcd(800);
	lcd_comdata(0x06, 0); //entry mode set increment cursor right
	delay_lcd(800);
	lcd_comdata(0x01, 0); //display clear
	delay_lcd(10000);
	return;
}
void lcd_comdata(int temp1, int type)
{
	int temp2 = temp1 & 0xf0; //move data (26-8+1) times : 26 - HN place, 4 - Bits
	temp2 = temp2 << 19; //data lines from 23 to 26
	write(temp2, type);
	temp2 = temp1 & 0x0f; //26-4+1
	temp2 = temp2 << 23; 
	write(temp2, type);
	delay_lcd(1000);
	return;
}
void write(int temp2, int type) //write to command/data reg
{ 
	clear_ports();
	LPC_GPIO0->FIOPIN = temp2; // Assign the value to the data lines 
	if(type==0)
	LPC_GPIO0->FIOCLR = 1<<27; // clear bit RS for Command
	else
	LPC_GPIO0->FIOSET = 1<<27; // set bit RS for Data
	LPC_GPIO0->FIOSET = 1<<28; // EN=1
	delay_lcd(25);
	LPC_GPIO0->FIOCLR = 1<<28; // EN =0
	 return;
}
void delay_lcd(unsigned int r1)
{
 unsigned int r;
 for(r=0;r<r1;r++);
 return;
}
void clear_ports(void)
{
	 /* Clearing the lines at power on */
	LPC_GPIO0->FIOCLR = 0x0F<<23; //Clearing data lines
	LPC_GPIO0->FIOCLR = 1<<27; //Clearing RS line
	LPC_GPIO0->FIOCLR = 1<<28; //Clearing Enable line
	return;
}
void lcd_puts(unsigned char *buf1)
{
	 unsigned int i=0;
	unsigned int temp3;
	 while(buf1[i]!='\0')
	 {
	 temp3 = buf1[i];
	 lcd_comdata(temp3, 1);
	 i++;
	 if(i==16)
	 {
	 lcd_comdata(0xc0, 0);
	 }
	 }
	 return;
 }

int main(void)
{
	unsigned long adc_temp;
	unsigned int i;
	float in_vtg;
	unsigned char vtg[7],dval[7];
	unsigned char Msg1[11] = {"ANLOG IP:"};
	unsigned char Msg2[12] = {"ADC O/P:"};
	
	 
    lcd_init();
    LPC_PINCON->PINSEL3 = 3<<30;	//P1.31 as AD0.5
	  LPC_SC->PCONP |= (1<<12);			//enable the peripheral ADC
	
	lcd_comdata(0x80, 0);
	delay_lcd(800);
	lcd_puts(&Msg1[0]);

	lcd_comdata(0xC0, 0);
	delay_lcd(800);
	lcd_puts(&Msg2[0]);

	while(1)
	{
		LPC_ADC->ADCR = (1<<5)|(1<<21)|(1<<24); 	//AD0.5, operational and start conversion	
		while(!(LPC_ADC->ADDR5 & 0x80000000));	//wait till 'done' bit is 1, indicates conversion complete                                                                                                                                                      
		adc_temp = LPC_ADC->ADDR5;
		adc_temp >>= 4;
		adc_temp &= 0x00000FFF;			//12 bit ADC
		in_vtg = ((float)adc_temp * Ref_Vtg)/(Full_Scale);	//calculating input analog voltage
		sprintf(vtg,"%3.2fV",in_vtg);	//convert the readings into string to display on LCD
		sprintf(dval,"%x",adc_temp);
		for(i=0;i<2000;i++);

		lcd_comdata(0x89, 0); //Firstline 9th charecter
		delay_lcd(800);
		lcd_puts(&vtg[0]);
                                   for(i=0;i<20000;i++);
		lcd_comdata(0xC8, 0);  //Secondline 8th character
		delay_lcd(800);
		lcd_puts(&dval[0]);

        for(i=0;i<20000;i++);
        for(i=0;i<7;i++)
        vtg[i] = dval[i] = 0x00;
        adc_temp = 0;
        in_vtg = 0;
	}
}