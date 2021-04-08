#include <at89c5131.h>

void sdelay(unsigned int);

sbit out=P0^7;

void timer0_isr(void) interrupt 1
{
    TH0  = 0xEF;        //ReLoad the timer value
    TL0  = 0xB8;
    out = !out;        // Toggle the LED pin 
}

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
    TMOD |= 0x01;       //Timer0 mode 1 
    TH0 = 0xEF;        //Load the timer value
    TL0 = 0xB8;
    ET0 = 1;           //Enable Timer0 Interrupt
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

// Uncomment to debug working of dot and dash function or to tune the timer0 parameters

// void main(void)
// {
// 	while(1)
// 	{
// 		dot();
// 		// dash();
// 	}
// }