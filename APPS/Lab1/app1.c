/*
 * Task_1_ITI.c
 *
 * Created: 12/11/2024 11:47:24 AM
 * Author : Fatma Yosry Mohamed
 */ 
#include "BIT_MATH.h"
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL

int main(void)
{
	DDRD |= (1<< PD1);
    /* Replace with your application code */
    while (1) 
    {
		
		TOG_BIT(PORTD,PD1);
		_delay_ms(1000);
		
			
    }
}
