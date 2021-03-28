#include <at89c5131.h>
#include "lcd.h"		//Header file with LCD interfacing functions
#include "serial.c"	//C file with UART interfacing functions
#include "tone.c"

sbit LED=P1^7;

//Test function definitions

/************************************************
   lcd_test():
	LCD test function that gets called when
	'1' is received from UART
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

				case '4': transmit_string("User Pressed : 4\r\n");
						  dot_s();
						  dot_s();
						  dot_s();
						  dot_s();
						  dash();
						  break;

				case '5': transmit_string("User Pressed : 5\r\n");
						  dot_s();
						  dot_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case '6': transmit_string("User Pressed : 6\r\n");
						  dash_s();
						  dot_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case '7': transmit_string("User Pressed : 7\r\n");
						  dash_s();
						  dash_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case '8': transmit_string("User Pressed : 8\r\n");
						  dash_s();
						  dash_s();
						  dash_s();
						  dot_s();
						  dot();
						  break;

				case '9': transmit_string("User Pressed : 9\r\n");
						  dash_s();
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

				case 'A': transmit_string("User Pressed : A\r\n");
						  dot_s();
						  dash();
						  break;

				case 'B': transmit_string("User Pressed : B\r\n");
						  dash_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case 'C': transmit_string("User Pressed : C\r\n");
						  dash_s();
						  dot_s();
						  dash_s();
						  dot();
						  break;

				case 'D': transmit_string("User Pressed : D\r\n");
						  dash_s();
						  dot_s();
						  dot();
						  break;

				case 'E': dot();
						  break;

				case 'F': dot_s();
						  dot_s();
						  dash_s();
						  dot();
						  break;

				case 'G': dash_s();
						  dash_s();
						  dot();
						  break;

				case 'H': dot_s();
						  dot_s();
						  dot_s();
						  dot();
						  break;

				case 'I': dot_s();
						  dot();
						  break;

				case 'J': dot_s();
						  dash_s();
						  dash_s();
						  dash();
						  break;

				case 'K': dash_s();
						  dot_s();
						  dash();
						  break;

				case 'L': dot_s();
						  dash_s();
						  dot_s();
						  dot();
						  break;

				case 'M': dash_s();
						  dash();
						  break;

				case 'N': dash_s();
						  dot();
						  break;

				case 'O': dash_s();
						  dash_s();
						  dash();
						  break;

				case 'P': dot_s();
						  dash_s();
						  dash_s();
						  dot();
						  break;

				case 'Q': dash_s();
						  dash_s();
						  dot_s();
						  dash();
						  break;

				case 'R': dot_s();
						  dash_s();
						  dot();
						  break;

				case 'S': dot_s();
						  dot_s();
						  dot();
						  break;

				case 'T': dash();
						  break;

				case 'U': dot_s();
						  dot_s();
						  dash();
						  break;

				case 'V': dot_s();
						  dot_s();
						  dot_s();
						  dash();
						  break;

				case 'W': dot_s();
						  dash_s();
						  dash();
						  break;

				case 'X': dash_s();
						  dot_s();
						  dot_s();
						  dash();
						  break;

				case 'Y': dash_s();
						  dot_s();
						  dash_s();
						  dash();
						  break;

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
