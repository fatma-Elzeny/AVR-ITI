/*
 * App3.c
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
	MDIO_enuErrorStatus_t ErrorState1;
	MDIO_enuErrorStatus_t ErrorState2;
	MDIO_enuErrorStatus_t ErrorState3;

	u8 result1;
	u8 result2;
	u8 result3;
	
	
	PORT_vInit();

    while (1) 
    {
		
	ErrorState1 = MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN7, &result1);
	if (ErrorState1 == MDIO_enuOK){
		if (result1 == 0){
			 MDIO_enuSetPinValue(MDIO_enuPORTB,MDIO_enuPIN4,MDIO_enuHIGH );
		
		}else {
		
			MDIO_enuSetPinValue(MDIO_enuPORTB, MDIO_enuPIN4, MDIO_enuLOW);
		}
	}
	
	ErrorState2= MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN6,&result2);
	if (ErrorState2 ==MDIO_enuOK){	
		if (result2 == 0){
			MDIO_enuSetPinValue(MDIO_enuPORTB,MDIO_enuPIN3,MDIO_enuHIGH );
		
			}else {
		
			MDIO_enuSetPinValue(MDIO_enuPORTB, MDIO_enuPIN3, MDIO_enuLOW);
		}
	}
	
	ErrorState3 =MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN5, &result3);
	if(ErrorState3==MDIO_enuOK){
		if (result3== 0){
			MDIO_enuSetPinValue(MDIO_enuPORTB,MDIO_enuPIN2,MDIO_enuHIGH );
			
			}else {
			
			MDIO_enuSetPinValue(MDIO_enuPORTB, MDIO_enuPIN2, MDIO_enuLOW);
		}
	}
	
    }
}
