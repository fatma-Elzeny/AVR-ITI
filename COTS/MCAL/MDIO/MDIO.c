/*
 * DIO.c
 *
 * Created: 12/17/2024 10:15:16 AM
 *  Author: Fatma Yosry Mohamed
 */

#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_TYPES.h"
#include "MDIO.h"
#include "MDIO_private.h"
#include "../MPORT/MPORT_CFG.h"




#define IS_INVALID_PORT_NUM(X)			((((MDIO_enuPortNames_t)X) > MDIO_enuPORTD) || (((MDIO_enuPortNames_t)X) < MDIO_enuPORTA))
#define IS_INVALID_PIN_NUM(X)			((((MDIO_enuPinNames_t)X) > MDIO_enuPIN7) || (((MDIO_enuPinNames_t)X) < MDIO_enuPIN0))
#define IS_INVALID_PIN_CONFIG(X)		((((MDIO_enuConfiguration_t)X) != MDIO_enuOUTPUT) && (((MDIO_enuConfiguration_t)X) != MDIO_enuINPUTPULLUP) && (((MDIO_enuConfiguration_t)X) != MDIO_enuINPUT))
#define IS_INVALID_PIN_STATE(X)			((((MDIO_enuStates_t)X) != MDIO_enuHIGH) && (((MDIO_enuStates_t)X) != MDIO_enuLOW))
#define IS_INVALID_PORT_STATE(X)		((((MDIO_enuPortStates_t)X) != MDIO_enuALLHIGH) && (((MDIO_enuPortStates_t)X) != MDIO_enuALLLOW))
#define IS_INVALID_PTR(X)				((X) == NULL)


// Function to set state on pin (LOW,HIGH)
/****************************** MDIO_enuSetPinValue *******************************************************
 * @description  :  This API sets the logical state of a specific pin (e.g., HIGH or LOW)                  *
 *                                                                                                         *
 *@Parameters:                                                                                             *
 *			   Copy_enuPortNum:                                                                *
 *				Specifies the port containing the pin to configure (e.g., PORTA, PORTB, 
                                PORTC, etc.).     *
 *                                                                                                         *
 *				Copy_enuPinNum:                                                                           
 *				Specifies the pin within the port to configure (e.g., PIN0, PIN1, PIN2, etc.).            
 *                                                                                                         *
 *				Copy_enuState:                                                                            
 *                Specifies the desired state for the pin: HIGH,LOW                                        *
 *                                                                                                         *
 *@Return:                                                                                                 *
 *				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           
 *                                                                                                         *
 ***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuStates_t Copy_enuState)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (IS_INVALID_PIN_NUM(Copy_enuPinNum))
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (IS_INVALID_PIN_STATE(Copy_enuState))
    {
        Ret_enuError = MDIO_enuINVALIDSTATUS;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        if (Copy_enuState == MDIO_enuLOW)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                SET_BIT(DDRA, Copy_enuPinNum);
                CLR_BIT(PORTA, Copy_enuPinNum);
                break;
            case MDIO_enuPORTB:
                SET_BIT(DDRB, Copy_enuPinNum);
                CLR_BIT(PORTB, Copy_enuPinNum);
                break;
            case MDIO_enuPORTC:
                SET_BIT(DDRC, Copy_enuPinNum);
                CLR_BIT(PORTC, Copy_enuPinNum);
                break;
            case MDIO_enuPORTD:
                SET_BIT(DDRD, Copy_enuPinNum);
                CLR_BIT(PORTD, Copy_enuPinNum);
                break;
            }
        }
        else if (Copy_enuState == MDIO_enuHIGH)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                SET_BIT(DDRA, Copy_enuPinNum);
                SET_BIT(PORTA, Copy_enuPinNum);
                break;
            case MDIO_enuPORTB:
                SET_BIT(DDRB, Copy_enuPinNum);
                SET_BIT(PORTB, Copy_enuPinNum);
                break;
            case MDIO_enuPORTC:
                SET_BIT(DDRC, Copy_enuPinNum);
                SET_BIT(PORTC, Copy_enuPinNum);
                break;
            case MDIO_enuPORTD:
                SET_BIT(DDRD, Copy_enuPinNum);
                SET_BIT(PORTD, Copy_enuPinNum);
                break;
            }
        }
    }
    return Ret_enuError;
}

// Function to set state on all pins in port (LOW,HIGH)

/****************************** MDIO_enuSetPortValue ******************************************************
* @description  : This API sets the logical states of all pins in a specified port at once, which is      *
                   useful for initializing or modifying the state of a port efficiently                   *
*                                                                                                         *
*@Parameters:                                                                                             *
*			   Copy_enuPortNum:                                                               *
*				Specifies the port containing the pin to configure (e.g., PORTA, PORTB,
                                PORTC, etc.).     
*                                                                                                         *
*				                                                                                          *                                                                                    
*				Copy_enuState:                                                            *
*                 Specifies the collective state for all pins in the port (e.g. all HIGH, all LOW)        *
*                                                                                                         *
*@Return:                                                                                                 *
*				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                           *
*                                                                                                         *
***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPortStates_t Copy_enuPortState)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (IS_INVALID_PORT_STATE(Copy_enuPortState))
    {
        Ret_enuError = MDIO_enuINVALIDSTATUS;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        if (Copy_enuPortState == MDIO_enuALLLOW)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                DDRA = 0xFF;
                PORTA = 0x00;
                break;
            case MDIO_enuPORTB:
                DDRB = 0xFF;
                PORTB = 0x00;
                break;
            case MDIO_enuPORTC:
                DDRC = 0xFF;
                PORTC = 0x00;
                break;
            case MDIO_enuPORTD:
                DDRD = 0xFF;
                PORTD = 0x00;
                break;
            }
        }
        else if (Copy_enuPortState == MDIO_enuALLHIGH)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                DDRA = 0xFF;
                PORTA = 0xFF;
                break;
            case MDIO_enuPORTB:
                DDRB = 0xFF;
                PORTB = 0xFF;
                break;
            case MDIO_enuPORTC:
                DDRC = 0xFF;
                PORTC = 0xFF;
                break;
            case MDIO_enuPORTD:
                DDRD = 0xFF;
                PORTD = 0xFF;
                break;
            }
        }
    }
    return Ret_enuError;
}
/****************************** MDIO_enuGetPinValue ************************************************
 * @description  :   This API retrieves the logical state (HIGH or LOW) of a specific pin                  *
 *                                                                                                         *
 *@Parameters:                                                                                             *
 *			   Copy_enuPortNum:                                                                *
 *				Specifies the port containing the pin to configure (e.g., PORTA, PORTB, 
                                 PORTC, etc.).     
 *                                                                                                         *
 *				Copy_enuPinNum:                                                                           
 *				Specifies the pin within the port to configure (e.g., PIN0, PIN1, PIN2, etc.).            
 *                                                                                                         *
 *				 Add_pu8PinValue:                                                                         
 *                Pointer to store the retrieved pin value                                                 *
 *                                                                                                         *
 *@Return:                                                                                                 *
 *				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           
 *                                                                                                         *
 ***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, u8 *Add_pu8PinValue)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (IS_INVALID_PIN_NUM(Copy_enuPinNum))
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (IS_INVALID_PTR(Add_pu8PinValue))
    {
        Ret_enuError = MDIO_NULL_PTR;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        switch (Copy_enuPortNum)
        {
        case MDIO_enuPORTA:
            *Add_pu8PinValue = GET_BIT(PINA, Copy_enuPinNum);
            break;
        case MDIO_enuPORTB:
            *Add_pu8PinValue = GET_BIT(PINB, Copy_enuPinNum);
            break;
        case MDIO_enuPORTC:
            *Add_pu8PinValue = GET_BIT(PINC, Copy_enuPinNum);
            break;
        case MDIO_enuPORTD:
            *Add_pu8PinValue = GET_BIT(PIND, Copy_enuPinNum);
            break;
        }
    }
    return Ret_enuError;
}


void MDIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	if((copy_u8PortId <= MDIO_enuPORTD))
	{
		switch(copy_u8PortId)
		{
		case MDIO_enuPORTA:
			PORTA = copy_u8PortValue;
			break;

		case MDIO_enuPORTB:
			PORTB = copy_u8PortValue;
			break;

		case MDIO_enuPORTC:
			PORTC = copy_u8PortValue;
			break;

		case MDIO_enuPORTD:
			PORTD= copy_u8PortValue;
			break;
		}
	}
	else
	{
		// return Error State
	}
}


void MDIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	if((copy_u8PortId <= MDIO_enuPORTD) && (copy_pu8PortValue != NULL))
	{
		switch(copy_u8PortId)
		{
		case MDIO_enuPORTA:
			*copy_pu8PortValue = PINA;
			break;

		case MDIO_enuPORTB:
			*copy_pu8PortValue = PINB;
			break;

		case MDIO_enuPORTC:
			*copy_pu8PortValue = PINC;
			break;

		case MDIO_enuPORTD:
			*copy_pu8PortValue = PIND;
			break;
		}
	}
	else
	{
		// return Error State
	}
}

