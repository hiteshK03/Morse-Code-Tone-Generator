#include <at89c5131.h>
#include "lcd.h"

sbit out=P1^4;

void timer0_isr() interrupt 1
{
    TH0  = 0x8C;        //ReLoad the timer value
    TL0  = 0x4F;
    out = !out;        // Toggle the LED pin 
}

void sdelay(unsigned int time)
{	
	TMOD = 0x10;
	int i;
	for(i=0;i<time;i++)
	{
		TH1 = 0x63;
		TL1 = 0xCD;
		TR1 = 1;
		while(!TF1)
		{
			continue;
		}
		TR1 = 0;
		TF1 = 0;
	}
}

void timer_init()
{
    TMOD = 0x01;       //Timer0 mode 1 
    TH0 = 0x8C;        //Load the timer value
    TL0 = 0x4F;
    ET0 = 1;           //Enable TImer0 Interrupt
    EA = 1;            //Enable Global Interrupt bit
    out = !out;
    TR0 = 1;           //turn ON Timer zero	
}

void dot()
{
	timer_init();
    sdelay(50);
}

void dash()
{
	timer_init();
	sdelay(100);
}

void silence()
{
	sdelay(50);
}