/*
 * Task_3_ITI.c
 *
 * Created: 12/11/2024 12:31:18 PM
 * Author : Fatma Yosry Mohamed 
 */ 
#include <util/delay.h>
#include <avr/io.h>
#define F_CPU 8000000UL 

int main(void)
{
	
	 DDRA |= (1 << PA3);

	 // Configure PB1 as input for button with internal pull-up enabled
	 DDRC &= ~(1 << PC4);  // Set PC4 as input
	 PORTC |= (1 << PC4);  // Enable internal pull-up resistor on PC4
    /* Replace with your application code */
    

		 while (1) {
			 
			 if (!(PINC & (1 << PC4))) {  // Button pressed 
				 PORTA |= (1 << PA3);  // Turn on LED
				 } else {  // Button not pressed
				 PORTA &= ~(1 << PA3);  // Turn off LED
			 }

			 

		 
    }
}
