#include <at89c5131.h>
#include "lcd_p.h"		//Header file with LCD interfacing functions
#include "serial_p.c"	//C file with UART interfacing functions
#include "tone.c"

sbit LED=P1^7;

//function definitions

/************************************************
   lcd_start():
	Prints "Input please" on LCD till a character
	is pressed.
   lcd_inv():
    Print "Invalid input" on LCD for 2 secs
************************************************/
void lcd_start(void)
{
	 lcd_cmd(0x82);
	 lcd_write_string("Input please");
	 // msdelay(2000);
	 // lcd_cmd(0x01);
}

void lcd_inv(void)
{
	 lcd_cmd(0x81);
	 lcd_write_string("Invalid input");
	 sdelay(2000);
	 lcd_cmd(0x01);
}

//Main function
void main(void)
{
	unsigned char ch=0;
	
	//Initialize port P1 for output from P1.7-P1.4
	P1 = 0x0F;
	
	//Call initialization functions
	lcd_init();
	uart_init();
	
	//These strings will be printed in terminal software
	transmit_string("************************\r\n");
	
	while(1)
	{	
			uart_init();
			transmit_string("Press a character\r\n");
			lcd_start();
			ch = receive_char();
			lcd_cmd(0x01);

			//Receive a character
		
			//Decide which test function to run based on character sent
      //Displays the string on the terminal software
			switch(ch)
			{
				case '1': transmit_string("User Pressed : 1\r\n");
						  dot_s();
						  dash_s();
						  dash_s();
						  dash_s();
						  dash();
						  break;
				
				case '2': transmit_string("User Pressed : 2\r\n");
						  dot_s();
						  dot_s();
						  dash_s();
						  dash_s();
						  dash();
						  break;
							
				case '3': transmit_string("User Pressed : 3\r\n");
						  dot_s();
						  dot_s();
						  dot_s();
						  dash_s();
						  dash();
						  break;

				case '4': dot_s();
						  dot_s();
						  dot_s();
						  dot_s();
						  dash();
						  break;

				case '5': dot_s();
						  dot_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case '6': dash_s();
						  dot_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case '7': dash_s();
						  dash_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case '8': dash_s();
						  dash_s();
						  dash_s();
						  dot_s();
						  dot();
						  break;

				case '9': dash_s();
						  dash_s();
						  dash_s();
						  dash_s();
						  dot();
						  break;

				case '0': transmit_string("User Pressed : 0\r\n");
						  dash_s();
						  dash_s();
						  dash_s();
						  dash_s();
						  dash();
						  break;

				case 'a':
				case 'A': transmit_string("User Pressed : A\r\n");
						  dot_s();
						  dash();
						  break;

				case 'b':
				case 'B': transmit_string("User Pressed : B\r\n");
						  dash_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;
				
				case 'c':
				case 'C': transmit_string("User Pressed : C\r\n");
						  dash_s();
						  dot_s();
						  dash_s();
						  dot();
						  break;

				case 'd':
				case 'D': transmit_string("User Pressed : D\r\n");
						  dash_s();
						  dot_s();
						  dot();
						  break;

				case 'e':
				case 'E': dot();
						  break;

				case 'f':
				case 'F': dot_s();
						  dot_s();
						  dash_s();
						  dot();
						  break;

				case 'g':
				case 'G': dash_s();
						  dash_s();
						  dot();
						  break;

				case 'h':
				case 'H': dot_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case 'i':
				case 'I': dot_s();
						  dot();
						  break;

				case 'j':
				case 'J': dot_s();
						  dash_s();
						  dash_s();
						  dash();
						  break;

				case 'k':
				case 'K': dash_s();
						  dot_s();
						  dash();
						  break;

				case 'l':
				case 'L': dot_s();
						  dash_s();
						  dot_s();
						  dot();
						  break;

				case 'm':
				case 'M': dash_s();
						  dash();
						  break;

				case 'n':
				case 'N': dash_s();
						  dot();
						  break;

				case 'o':
				case 'O': dash_s();
						  dash_s();
						  dash();
						  break;

				case 'p':
				case 'P': dot_s();
						  dash_s();
						  dash_s();
						  dot();
						  break;

				case 'q':
				case 'Q': dash_s();
						  dash_s();
						  dot_s();
						  dash();
						  break;

				case 'r':
				case 'R': dot_s();
						  dash_s();
						  dot();
						  break;

				case 's':
				case 'S': dot_s();
						  dot_s();
						  dot();
						  break;

				case 't':
				case 'T': dash();
						  break;

				case 'u':
				case 'U': dot_s();
						  dot_s();
						  dash();
						  break;

				case 'v':
				case 'V': dot_s();
						  dot_s();
						  dot_s();
						  dash();
						  break;

				case 'w':
				case 'W': dot_s();
						  dash_s();
						  dash();
						  break;

				case 'x':
				case 'X': dash_s();
						  dot_s();
						  dot_s();
						  dash();
						  break;

				case 'y':
				case 'Y': dash_s();
						  dot_s();
						  dash_s();
						  dash();
						  break;

				case 'z':
				case 'Z': dash_s();
						  dash_s();
						  dot_s();
						  dot();
						  break;

				default:transmit_string("Invalid input\r\n");
								 lcd_inv();
								 break;
				
			}
			msdelay(100);
	}
}
