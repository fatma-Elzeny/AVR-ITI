/* App1.c
 *
 * Created: 12/17/2024 10:14:21 AM
 * Author : Fatma Yosry Mohamed 
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../CTOS/MCAL/MDIO/inc/MDIO.h"
#define NULL 0 


int main(void)
{
	MDIO_enuErrorStatus_t ErrorState1;
	MDIO_enuErrorStatus_t ErrorState2;
	MDIO_enuErrorStatus_t ErrorState3;
	MDIO_enuErrorStatus_t ErrorState4;
	u8 result1,result2,result3,result4;
	 MDIO_enuSetPinConfigration(MDIO_enuPORTA, MDIO_enuPIN4, MDIO_enuOUTPUT);
	 MDIO_enuSetPinConfigration(MDIO_enuPORTA, MDIO_enuPIN5, MDIO_enuOUTPUT);
	 MDIO_enuSetPinConfigration(MDIO_enuPORTA, MDIO_enuPIN6, MDIO_enuOUTPUT);
	 MDIO_enuSetPinConfigration(MDIO_enuPORTA, MDIO_enuPIN7, MDIO_enuOUTPUT);
	
     MDIO_enuSetPinConfigration(MDIO_enuPORTD, MDIO_enuPIN1, MDIO_enuINPUTPULLUP);
	 MDIO_enuSetPinConfigration(MDIO_enuPORTD, MDIO_enuPIN2, MDIO_enuINPUTPULLUP);
	 MDIO_enuSetPinConfigration(MDIO_enuPORTD, MDIO_enuPIN6, MDIO_enuINPUTPULLUP);
	 MDIO_enuSetPinConfigration(MDIO_enuPORTD, MDIO_enuPIN7, MDIO_enuINPUTPULLUP);

    while (1) 
    {
		
	ErrorState1 = MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN1, &result1);
	if (ErrorState1 == MDIO_enuOK){
		if (result1 == 0){
			 MDIO_enuSetPinValue(MDIO_enuPORTA,MDIO_enuPIN4,MDIO_enuHIGH );
		
		}else {
		
			MDIO_enuSetPinValue(MDIO_enuPORTA, MDIO_enuPIN4, MDIO_enuLOW);
		}
	}
	
	ErrorState2= MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN2, &result2);
	if (ErrorState2 ==MDIO_enuOK){	
		if (result2 == 0){
			MDIO_enuSetPinValue(MDIO_enuPORTA,MDIO_enuPIN5,MDIO_enuHIGH );
		
			}else {
		
			MDIO_enuSetPinValue(MDIO_enuPORTA, MDIO_enuPIN5, MDIO_enuLOW);
		}
	}
	
	ErrorState3 =MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN6, &result3);
	if(ErrorState3==MDIO_enuOK){
		if (result3== 0){
			MDIO_enuSetPinValue(MDIO_enuPORTA,MDIO_enuPIN6,MDIO_enuHIGH );
			
			}else {
			
			MDIO_enuSetPinValue(MDIO_enuPORTA, MDIO_enuPIN6, MDIO_enuLOW);
		}
	}
	
	
	ErrorState4 = MDIO_enuGetPinValue(MDIO_enuPORTD, MDIO_enuPIN7, &result4);
	if(ErrorState4==MDIO_enuOK){
		if (result4 == 0){
			MDIO_enuSetPinValue(MDIO_enuPORTA,MDIO_enuPIN7,MDIO_enuHIGH );
			
			}else {
			
			MDIO_enuSetPinValue(MDIO_enuPORTA, MDIO_enuPIN7, MDIO_enuLOW);
		}
	}
    }
}
