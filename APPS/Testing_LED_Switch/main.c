/* App1.c
 *
 * Created: 12/17/2024 10:14:21 AM
 * Author : Fatma Yosry Mohamed 
 */ 

#include "../COTS/MCAL/MDIO/MDIO.h"
#include "../COTS/MCAL/MPORT/MPORT.h"
#include "../COTS/HAL/LED/LED.h"
#include "../COTS/HAL/SWITCH/SWITCH.h"
#include "../COTS/MCAL/MPORT/MPORT_CFG.h"
#include "../COTS/HAL/LED/LED_CFG.h"
#include "../COTS/HAL/SWITCH/SWITCH_CFG.h"



int main(void)
{
	MDIO_enuErrorStatus_t ErrorState1;
	MDIO_enuErrorStatus_t ErrorState2;
	MDIO_enuErrorStatus_t ErrorState3;
	
	u8 result1,result2,result3;
	SWITCH_init();
	LED_init();

    while (1) 
    {
		
	ErrorState1 = SWITCH_enuGetSwitchState(SWITCH_START, &result1);
	if (ErrorState1 == MDIO_enuOK){
		if (result1 == 0){
			 LED_enuSetLedState(LED_START, HLED_enuHIGH);
		
		}else {
		
			LED_enuSetLedState(LED_START,HLED_enuLow);
		}
	}
	ErrorState2 = SWITCH_enuGetSwitchState(SWITCH_ALERT, &result2);
	if (ErrorState2 == MDIO_enuOK){
		if (result2 == 0){
			 LED_enuSetLedState(LED_ALERT, HLED_enuHIGH);
		
		}else {
		
			LED_enuSetLedState(LED_ALERT,HLED_enuLow);
		}
	}
	ErrorState3 = SWITCH_enuGetSwitchState(SWITCH_STOP, &result3);
	if (ErrorState3 == MDIO_enuOK){
		if (result3 == 0){
			 LED_enuSetLedState(LED_STOP, HLED_enuHIGH);
		
		}else {
		
			LED_enuSetLedState(LED_STOP,HLED_enuLow);
		}
	}
	
	
	
	
	
	

	}
}
