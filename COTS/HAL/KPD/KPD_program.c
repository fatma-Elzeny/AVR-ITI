

/* UTILES_LIB */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/MDIO/MDIO.h"
#include "../../MCAL/MPORT/MPORT.h"


/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"


/*
 * @fn KPD_voidInit
 * @brief the function initializes the KPD ROWS pins as I/P with PullUp and COLS pins as O/P initialy high
 * @param[in] void
 * @retVal void
 */
void KPD_voidInit(void)
{
	/* Config ROWS pins as I/P PULL UP pins */ 
	MDIO_enuSetPinConfigration(KPD_ROW0_PORT, KPD_ROW0_PIN, MDIO_enuINPUTPULLUP);
	MDIO_enuSetPinConfigration(KPD_ROW1_PORT, KPD_ROW1_PIN, MDIO_enuINPUTPULLUP);
	MDIO_enuSetPinConfigration(KPD_ROW2_PORT, KPD_ROW2_PIN, MDIO_enuINPUTPULLUP);
	MDIO_enuSetPinConfigration(KPD_ROW3_PORT, KPD_ROW3_PIN, MDIO_enuINPUTPULLUP);

	/* Config COLS pins as O/P pins */
	MDIO_enuSetPinConfigration(KPD_COL0_PORT, KPD_COL0_PIN, MDIO_enuOUTPUT);
	MDIO_enuSetPinConfigration(KPD_COL1_PORT, KPD_COL1_PIN, MDIO_enuOUTPUT);
	MDIO_enuSetPinConfigration(KPD_COL2_PORT, KPD_COL2_PIN, MDIO_enuOUTPUT);
	MDIO_enuSetPinConfigration(KPD_COL3_PORT, KPD_COL3_PIN, MDIO_enuOUTPUT);

	/* Set COLS pins as Initialy high */ 
	MDIO_enuSetPinValue(KPD_COL0_PORT, KPD_COL0_PIN, MDIO_enuHIGH);
	MDIO_enuSetPinValue(KPD_COL1_PORT, KPD_COL1_PIN, MDIO_enuHIGH);
	MDIO_enuSetPinValue(KPD_COL2_PORT, KPD_COL2_PIN, MDIO_enuHIGH);
	MDIO_enuSetPinValue(KPD_COL3_PORT, KPD_COL3_PIN, MDIO_enuHIGH);
}


/*
 * @fn KPD_voidGetValue
 * @brief the function Loop on COLS and activate each one, Loop on ROWS and check each one  
 * @param[out] copy_pu8ReturnedValue: The ASCII of pressed key if there is one.
 * @retVal void
 */
void KPD_voidGetValue(u8* copy_pu8ReturnedValue)
{
	if(copy_pu8ReturnedValue != NULL)
	{
		u8 local_u8ColsCounter, local_u8RowsCounter;
		u8 local_u8PinState;
		u8 local_u8ColsPorts[4] = {KPD_COL0_PORT, KPD_COL1_PORT, KPD_COL2_PORT, KPD_COL3_PORT};
		u8 local_u8ColsPins [4] = {KPD_COL0_PIN , KPD_COL1_PIN , KPD_COL2_PIN , KPD_COL3_PIN};
		u8 local_u8RowsPorts[4] = {KPD_ROW0_PORT, KPD_ROW1_PORT, KPD_ROW2_PORT, KPD_ROW3_PORT};
		u8 local_u8RowsPins [4] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
		u8 local_u8KPD_Chars[4][4] = KPD_KEYS; 

		*copy_pu8ReturnedValue = KPD_NOT_PRESSED;
		for(local_u8ColsCounter = 0;local_u8ColsCounter < 4; local_u8ColsCounter++)
		{
			/* Activate Each Column with low value */
			MDIO_enuSetPinValue(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], MDIO_enuLOW);

			for(local_u8RowsCounter = 0; local_u8RowsCounter < 4; local_u8RowsCounter++)
			{
				/* Check Each Row (if == 0?) */
				MDIO_enuGetPinValue(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter], &local_u8PinState);

				/* Is Pressed? */
				if(0 == local_u8PinState)
				{
					while(0 == local_u8PinState)
					{
						MDIO_enuGetPinValue(local_u8RowsPorts[local_u8RowsCounter], local_u8RowsPins[local_u8RowsCounter], &local_u8PinState);
					}
					*copy_pu8ReturnedValue = local_u8KPD_Chars[local_u8RowsCounter][local_u8ColsCounter];
					break;
				}
			}

			/* Deactivate Current Column with high value */
			MDIO_enuSetPinValue(local_u8ColsPorts[local_u8ColsCounter], local_u8ColsPins[local_u8ColsCounter], MDIO_enuHIGH);

			if(local_u8RowsCounter < 4)
			{
				break;
			}
		}
	}
	else
	{
		// return Error State
	}
}

