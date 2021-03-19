#include <at89c5131.h>

void sdelay(unsigned int);

sbit out=P0^7;

void timer0_isr(void) interrupt 1
{
    TH0  = 0xEF;        //ReLoad the timer value
    TL0  = 0x80;
    out = !out;        // Toggle the LED pin 
}

// unsigned int i;
// void sdelay(unsigned int time)
// {	
// 	TMOD = 0x10;
// 	for(i=0;i<time;i++)
// 	{
// 		TH1 = 0x63;
// 		TL1 = 0xD6;
// 		TR1 = 1;
// 		while(TF1==0);
// 		TR1 = 0;
// 		TF1 = 0;
// 	}
// }

void sdelay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<356;j++);
	}
}


void timer_init(void)
{
    TMOD = 0x01;       //Timer0 mode 1 
    TH0 = 0xEF;        //Load the timer value
    TL0 = 0x80;
    ET0 = 1;           //Enable TImer0 Interrupt
    EA = 1;            //Enable Global Interrupt
    out = !out;
    TR0 = 1;           //turn ON Timer zero	
}

void dot(void)
{
	timer_init();
    sdelay(1000);
    TR0 = 0;
}

void dot_s(void)
{
	timer_init();
    sdelay(1000);
    TR0 = 0;
    sdelay(1000);
}

void dash(void)
{
	timer_init();
	sdelay(2000);
	TR0 = 0;
}

void dash_s(void)
{
	timer_init();
	sdelay(2000);
    TR0 = 0;
    sdelay(1000);
}

// void main(void)
// {
// 	while(1)
// 	{
// 		dot();
// 		// dash();
// 	}
// }