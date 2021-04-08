# Morse-Code-Tone-Generator
Generate Morse code audio tones for a series of characters typed on a keyboard connected to the Pt-51 board via UART  

Features implemented:
* When the program starts, the LCD displays the message "Input please".
* The user types a character on the keyboard which is one of the 26 letters or the 10 numerals.
* If the user types a character other than these 36 characters, the LCD should display "Invalid input" for 2 seconds and go back to displaying "Input please".
* For a valid character input, the board should output the series of audio tones corresponding to the Morse code equivalent of the character.
	* Use the International Morse Code as described at https://en.wikipedia.org/wiki/Morse_code.
	* Use a tone of 1 second duration for a dot and a tone of 2 seconds duration for a dash.
	* Use a 1 second silence between tones.
	* The LCD should be blank during the output of the Morse code for a character.
* For example, if the character typed is A, then the Morse code equivalent is dot dash. This will be output as a audio tone of 1 second duration, 1 second silence, and finally an audio tone of 2 seconds duration.
* Any characters typed during the output of the current character will be ignored. This is indicated by the blank LCD screen.
* Once the output of the Morse code for a character is complete, the LCD display again has the text Input please.