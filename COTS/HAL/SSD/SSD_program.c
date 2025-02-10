
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "../../MCAL/MPORT/MPORT.h"
#include "../../MCAL/MDIO/MDIO.h"

/* HAL */
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

static u8 PRV_u8Numbers[10]= {SSD_ZERO, SSD_ONE, SSD_TWO, SSD_THREE, SSD_FOUR, SSD_FIVE, SSD_SEX, SSD_SEVEN, SSD_EIGHT, SSD_NINE};

void SSD_voidInit(void)
{
	MDIO_enuSetPortConfigration(SSD_DATA_PORT, MDIO_enuOUTPUT);
	MDIO_enuSetPinConfigration(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuOUTPUT);
	MDIO_enuSetPinConfigration(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuOUTPUT);
}


void SSD_voidDisplayNumber(u8 copy_u8DesiredNumber, u8 copy_u8Id)
{
	if(copy_u8DesiredNumber<=9)
	{
		switch(copy_u8Id)
		{
		    case SSD_A:
#if SSD_TYPE == SSD_COM_CATHODE
			MDIO_voidSetPortValue(SSD_DATA_PORT, PRV_u8Numbers[copy_u8DesiredNumber]);
			MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuLOW);

#elif SSD_TYPE == SSD_COM_ANNODE
			MDIO_voidSetPortValue(SSD_DATA_PORT, ~PRV_u8Numbers[copy_u8DesiredNumber]);
			MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuHIGH);
#endif
			break;

		    case SSD_B:
#if SSD_TYPE == SSD_COM_CATHODE
			MDIO_voidSetPortValue(SSD_DATA_PORT, PRV_u8Numbers[copy_u8DesiredNumber]);
			MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuLOW);

#elif SSD_TYPE == SSD_COM_ANNODE
			MDIO_voidSetPortValue(SSD_DATA_PORT, ~PRV_u8Numbers[copy_u8DesiredNumber]);
			MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuHIGH);
#endif
			break;
		}
	}
	else
	{
		// return Error state
	}
}


void SSD_voidDisplayMultiplexedNumber(u8 copy_u8DesiredNumber)
{
	if(copy_u8DesiredNumber<=99)
	{
		u8 local_u8Ones = copy_u8DesiredNumber%10;
		u8 local_u8Tens = copy_u8DesiredNumber/10;

#if SSD_TYPE == SSD_COM_CATHODE
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuHIGH);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuHIGH);
		MDIO_voidSetPortValue(SSD_DATA_PORT, PRV_u8Numbers[local_u8Tens]);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuLOW);
		_delay_ms(10);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuHIGH);

		MDIO_voidSetPortValue(SSD_DATA_PORT, PRV_u8Numbers[local_u8Ones]);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuLOW);
		_delay_ms(10);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuHIGH);

#elif SSD_TYPE == SSD_COM_ANNODE
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuLOW);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuLOW);
		MDIO_voidSetPortValue(SSD_DATA_PORT, ~PRV_u8Numbers[local_u8Tens]);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuHIGH);
		_delay_ms(10);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K1_ENABLE_PIN, MDIO_enuLOW);

		MDIO_voidSetPortValue(SSD_DATA_PORT, ~PRV_u8Numbers[local_u8Ones]);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuHIGH);
		_delay_ms(10);
		MDIO_enuSetPinValue(SSD_ENABLE_PORT, SSD_K2_ENABLE_PIN, MDIO_enuLOW);
#endif
	}
	else
	{
		// return Error state
	}
}
