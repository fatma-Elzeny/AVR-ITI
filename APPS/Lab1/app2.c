/*
 * Task_2_ITI.c
 *
 * Created: 12/11/2024 12:17:32 PM
 * Author : Fatma Yosry Mohamed 
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"

#define F_CPU 8000000UL

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
			DDRD |= (1<< PC2);
			SET_BIT(PORTC,PC2);
			_delay_ms(5000);
			CLR_BIT(PORTC,PC2);
			
			DDRD |= (1<< PD0);
			SET_BIT(PORTD,PD0);
			_delay_ms(2000);
			CLR_BIT(PORTD,PD0);
			
			DDRD |= (1<< PD7);
			SET_BIT(PORTD,PD7);
			_delay_ms(5000);
			CLR_BIT(PORTD,PD7);
    }
}
