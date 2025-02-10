

/* UTILES_LIB */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/MDIO/MDIO.h"
#include "../../MCAL/MPORT/MPORT.h"


/* HAL */
#include "BUZZER_interface.h"


void BUZZER_voidInit(u8 copy_u8BuzzerPort, u8 copy_u8BuzzerPin)
{
	MDIO_enuSetPinConfigration(copy_u8BuzzerPort, copy_u8BuzzerPin, MDIO_enuOUTPUT);
}


void BUZZER_voidOn(u8 copy_u8BuzzerPort, u8 copy_u8BuzzerPin)
{
	MDIO_enuSetPinValue(copy_u8BuzzerPort, copy_u8BuzzerPin, MDIO_enuHIGH);
}


void BUZZER_voidOff(u8 copy_u8BuzzerPort, u8 copy_u8BuzzerPin)
{
	MDIO_enuSetPinValue(copy_u8BuzzerPort, copy_u8BuzzerPin, MDIO_enuLOW);
}



