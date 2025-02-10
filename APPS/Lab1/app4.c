/*
 * Task_4_ITI.c
 *
 * Created: 12/11/2024 12:53:23 PM
 * Author : Fatma Yosry Mohamed
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    
       uint8_t counter = 0;  // 4-bit counter (0-15)

       //LEDS
       DDRB |= 0x0F;  
	   

       // Configure PB4 as input for button with internal pull-up
       DDRC &= ~(1 << PC5);  // Set PC5 as input
       PORTC |= (1 << PC5);  // Enable internal pull-up resistor on PC5

	  while (1) {
		  // Check if the button is pressed
		  if (!(PINC & (1 << PC5))) {  // Button pressed 
			  _delay_ms(500);
			  if (!(PINC & (1 << PC5))) {
			    
				  counter++;  // Increment counter
				  counter &= 0x0F;  

				  // Display counter on LEDs
				  PORTB = (PORTB & 0xF0) | (counter & 0x0F);  // Update PB0-PB3
		
				  // Wait until button is released
				  while (!(PINC & (1 << PC5))) {
					  _delay_ms(10);  
				  }
	  }
  }		  
  }

    return 0;
}
