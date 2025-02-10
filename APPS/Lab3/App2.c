/*
 * App2.c
 *
 * Created: 12/17/2024 10:14:21 AM
 * Author : Fatma Yosry Mohamed 
 */ 
//#define F_CPU 8000000UL


//#include <util/delay.h>
#include "../../COTS/MCAL/MDIO/MDIO.h"
#include "../../COTS/MCAL/MPORT/MPORT.h"

#include "../../LIB/STD_TYPES.h"




int main(void)
{
     u8 buttonState = 0;
     u8 previousButtonState = 0;
     u8 counter = 0;
     u8 started = 0;

     // Configure the button pin as input
     MDIO_enuSetPinConfigration(MDIO_enuPORTD, MDIO_enuPIN6, MDIO_enuINPUTPULLUP);

     // Configure the LED port as output
     MDIO_enuSetPortConfigration(MDIO_enuPORTB, MDIO_enuOUTPUT);
    while (1) 
    {
		 // Read the button state
		 MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN6, &buttonState);

		 // Detect button press (falling edge detection)
		 if (buttonState == 0 && previousButtonState == 1) {
			 started = !started; // Toggle start state
			 counter ++;
		 }
		 previousButtonState = buttonState;
		 
		  if (started) {
			  // Display the counter value using LEDs
			  for (u8 pin = 0; pin < 8; pin++) {
				  if (counter & (1 << pin)) {
					  MDIO_enuSetPinValue(MDIO_enuPORTB, pin, MDIO_enuHIGH); // Set pin HIGH
					  } else {
					  MDIO_enuSetPinValue(MDIO_enuPORTB, pin, MDIO_enuLOW); // Set pin LOW
				  }
			  }

			  
			  }
    }
	
}
