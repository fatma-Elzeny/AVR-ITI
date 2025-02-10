/*
 * MPORT.c
 *
 * Created: 12/25/2024 12:41:58 PM
 *  Author: Fatma Yosry Mohamed
 */

#include "../../../LIB/BIT_MATH.h"
#include "MPORT.h"
#include "MPORT_private.h"
#include "../MDIO/MDIO.h"
#include "../../../LIB/STD_TYPES.h"
#include "MPORT_CFG.h"



#define IS_INVALID_PORT_NUM(X)			((((MDIO_enuPortNames_t)X) > MDIO_enuPORTD) || (((MDIO_enuPortNames_t)X) < MDIO_enuPORTA))
#define IS_INVALID_PIN_NUM(X)			((((MDIO_enuPinNames_t)X) > MDIO_enuPIN7) || (((MDIO_enuPinNames_t)X) < MDIO_enuPIN0))
#define IS_INVALID_PIN_CONFIG(X)		((((MDIO_enuConfiguration_t)X) != MDIO_enuOUTPUT) && (((MDIO_enuConfiguration_t)X) != MDIO_enuINPUTPULLUP) && (((MDIO_enuConfiguration_t)X) != MDIO_enuINPUT))
#define IS_INVALID_PIN_STATE(X)			((((MDIO_enuStates_t)X) != MDIO_enuHIGH) && (((MDIO_enuStates_t)X) != MDIO_enuLOW))
#define IS_INVALID_PORT_STATE(X)		((((MDIO_enuPortStates_t)X) != MDIO_enuALLHIGH) && (((MDIO_enuPortStates_t)X) != MDIO_enuALLLOW))
#define IS_INVALID_PTR(X)				((X) == NULL)


extern MDIO_enuConfiguration_t MDIO_enuArrPinConfig[NUM_OF_PORTS * NUM_OF_PINS];

// Function to initialize 
/****************************** PORT_voidInit *******************************************
 * @brief        :  Initialize direction of all pins as specified by user in _LCFG.c     *
 * @param        :  None --- But user must fill in MDIO_enuArrPinConfig array            *
 * @return       :  None                                                                 *
 ****************************************************************************************/
void PORT_vInit(void)
{
    u8 Local_uint8Iter;
    MDIO_enuPortNames_t Local_enuPortNum;
    MDIO_enuPinNames_t Local_enuPinNum;

    for (Local_uint8Iter = 0; Local_uint8Iter < (NUM_OF_PORTS * NUM_OF_PINS); Local_uint8Iter++)
    {
        Local_enuPortNum = ((Local_uint8Iter) / NUM_OF_PINS);
        Local_enuPinNum = ((Local_uint8Iter) % NUM_OF_PINS);
        MDIO_enuSetPinConfigration(Local_enuPortNum, Local_enuPinNum, MDIO_enuArrPinConfig[Local_uint8Iter]);
    }
}

// Function to set configuration for pin (OUTPUT , INPUT , INPUT PULLUP )
/****************************** MDIO_enuSetPinConfigration ************************************************
* @description  : This API configures a specific pin within a port with the desired functionality,                        *
*				 such as input, output, or pull-up/down configuration. It allows precise control          *
*				 over individual pins in a microcontroller's GPIO.                                        *
*                                                                                                                         *
*@Parameters:                                                                                                             *
*			   Copy_enuPortNum:                                                                               *
*				Specifies the port containing the pin to configure (e.g., PORTA, PORTB, PORTC, etc.).     *
*                                                                                                         *
*				Copy_enuPinNum:                                                                           *
*				Specifies the pin within the port to configure (e.g., PIN0, PIN1, PIN2, etc.).            *
*                                                                                                         *
*				Copy_enuConfigration:                                                                     *
*				Specifies the desired configuration for the pin. Examples:                                *
*				OUTPUT,INPUT_PULLUP,INPUT_PULLDOWN                                                        *
*@Return:                                                                                                                 *
*				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *

***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuConfiguration_t Copy_enuConfigration)
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
    else if (IS_INVALID_PIN_CONFIG(Copy_enuConfigration))
    {
        Ret_enuError = MDIO_enuINVALIDCONFIG;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        if (Copy_enuConfigration == MDIO_enuOUTPUT)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                SET_BIT(DDRA, Copy_enuPinNum);
                break;
            case MDIO_enuPORTB:
                SET_BIT(DDRB, Copy_enuPinNum);
                break;
            case MDIO_enuPORTC:
                SET_BIT(DDRC, Copy_enuPinNum);
                break;
            case MDIO_enuPORTD:
                SET_BIT(DDRD, Copy_enuPinNum);
                break;
            }
        }
        else if (Copy_enuConfigration == MDIO_enuINPUTPULLUP)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                CLR_BIT(DDRA, Copy_enuPinNum);
                SET_BIT(PORTA, Copy_enuPinNum);
                break;
            case MDIO_enuPORTB:
                CLR_BIT(DDRB, Copy_enuPinNum);
                SET_BIT(PORTB, Copy_enuPinNum);
                break;
            case MDIO_enuPORTC:
                CLR_BIT(DDRC, Copy_enuPinNum);
                SET_BIT(PORTC, Copy_enuPinNum);
                break;
            case MDIO_enuPORTD:
                CLR_BIT(DDRD, Copy_enuPinNum);
                SET_BIT(PORTD, Copy_enuPinNum);
                break;
            }
        }
        else if (Copy_enuConfigration == MDIO_enuINPUT)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                CLR_BIT(DDRA, Copy_enuPinNum);
                break;
            case MDIO_enuPORTB:
                CLR_BIT(DDRB, Copy_enuPinNum);
                break;
            case MDIO_enuPORTC:
                CLR_BIT(DDRC, Copy_enuPinNum);
                break;
            case MDIO_enuPORTD:
                CLR_BIT(DDRD, Copy_enuPinNum);
                break;
            }
        }
    }
    return Ret_enuError;
}
// Function to set configuration for PORT (OUTPUT , INPUT , INPUT PULLUP )
/****************************** MDIO_enuSetPortConfigration ************************************************
 * @description  : This API configures all pins in a specific port at once, saving time when multiple pins *
 *                   need the same configuration (e.g., all as inputs or outputs).                         *
 *                                                                                                         *
 *@Parameters:                                                                                             *
 *			    Copy_enuPortNum:                                                                          *
 *                Specifies the port to configure (e.g., PORTA, PORTB, PORTC, etc.).                       *
 *                                                                                                         *
 *				Copy_enuConfigration:                                                                     *
 *				Specifies the configuration to apply to all pins in the port (e.g., all INPUT,all OUTPUT).*
 *                                                                                                         *
 *@Return:                                                                                                 *
 *				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *
 *                                                                                                         *
 ***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuConfiguration_t Copy_enuConfigration)
{
    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (IS_INVALID_PIN_CONFIG(Copy_enuConfigration))
    {
        Ret_enuError = MDIO_enuINVALIDCONFIG;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        if (Copy_enuConfigration == MDIO_enuOUTPUT)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                DDRA = 0xFF;
                break;
            case MDIO_enuPORTB:
                DDRB = 0xFF;
                break;
            case MDIO_enuPORTC:
                DDRC = 0xFF;
                break;
            case MDIO_enuPORTD:
                DDRD = 0xFF;
                break;
            }
        }
        else if (Copy_enuConfigration == MDIO_enuINPUTPULLUP)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                DDRA = 0x00;
                PORTA = 0xFF;
                break;
            case MDIO_enuPORTB:
                DDRB = 0x00;
                PORTB = 0xFF;
                break;
            case MDIO_enuPORTC:
                DDRC = 0x00;
                PORTC = 0xFF;
                break;
            case MDIO_enuPORTD:
                DDRD = 0x00;
                PORTD = 0xFF;
                break;
            }
        }
        else if (Copy_enuConfigration == MDIO_enuINPUT)
        {
            switch (Copy_enuPortNum)
            {
            case MDIO_enuPORTA:
                DDRA = 0x00;
                break;
            case MDIO_enuPORTB:
                DDRB = 0x00;
                break;
            case MDIO_enuPORTC:
                DDRC = 0x00;
                break;
            case MDIO_enuPORTD:
                DDRD = 0x00;
                break;
            }
        }
    }
    return Ret_enuError;
}
// Function to set configuration for PORT (OUTPUT , INPUT , INPUT PULLUP )
/****************************** MPORT_enuSetPinDirection ************************************************
* @description  : The Port_SetPinDirection API is part of the AUTOSAR Port Driver module. it allows you   *
                 to change the direction of a specific microcontroller pin at runtime.                    *
                 Pin direction determines whether the pin:                                                *
                                                                                                          *
                    Acts as an input  (reads data/signals from external devices).                         *
                    Acts as an output (sends data/signals to external devices).                           *
                                                                                                          *
                                                                                                          *
*                                                                                                         *
*@Parameters:                                                                                             *
*			     Copy_enuPinNum:                                                                          *
                    Typically defined using a combination of the port and pin numbers                     *
                    (e.g., 0x10 might represent Pin 0 on Port B in an 8-bit architecture).                *
                    Example : #define PIN_A0 0x00 // Port A, Pin 0      ,                                 *
                     #define PIN_C3  0x23 // Port C, Pin 3                                                *
                                                                                                          *
                    Copy_enuPinDirection:                                                                 *
                    Specifies the desired configuration for the pin. Examples:                            *
                    OUTPUT,INPUT.                                                                         *
                                                                                                          *
*                                                                                                         *
*@Return:                                                                                                 *
*				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *
*                                                                                                         *
***********************************************************************************************************/

MDIO_enuErrorStatus_t MPORT_enuSetPinDirection(u8 Copy_enuPinNum, MPORT_enuConfiguration_t Copy_enuPinDirection)
{
    u8 Local_enuPortNum = Copy_enuPinNum >> 4;
    u8 Local_enuPinNum = Copy_enuPinNum & 0x0F;

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (IS_INVALID_PORT_NUM(Local_enuPortNum))
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (IS_INVALID_PIN_NUM(Local_enuPinNum))
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (Copy_enuPinDirection > MPORT_enuINPUT)
    {
        Ret_enuError = MDIO_enuINVALIDCONFIG;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        if (Copy_enuPinDirection == MPORT_enuOUTPUT)
        {
            switch (Local_enuPortNum)
            {
            case PORT_A:
                SET_BIT(DDRA, Local_enuPinNum);
                break;
            case PORT_B:
                SET_BIT(DDRB, Local_enuPinNum);
                break;
            case PORT_C:
                SET_BIT(DDRC, Local_enuPinNum);
                break;
            case PORT_D:
                SET_BIT(DDRD, Local_enuPinNum);
                break;
            }
        }
        else if (Copy_enuPinDirection == MPORT_enuINPUT)
        {
            switch (Local_enuPortNum)
            {
            case PORT_A:
                CLR_BIT(DDRA, Local_enuPinNum);
                break;
            case PORT_B:
                CLR_BIT(DDRB, Local_enuPinNum);
                break;
            case PORT_C:
                CLR_BIT(DDRC, Local_enuPinNum);
                break;
            case PORT_D:
                CLR_BIT(DDRD, Local_enuPinNum);
                break;
            }
        }
    }
    return Ret_enuError;
}

// Function to set mode for pin (UART, INPUT PULL DOWN , INPUT PULLUP )
/****************************** MPORT_enuSetPinMode *******************************************************
* @description  :     The Port_SetPinMode function is part of the AUTOSAR Port Driver module.             *
                      Its primary purpose is to configure the mode of a specific pin during runtime.      *
                      The mode determines the pin's behavior -> digital communication pin                 *
                      (e.g., UART, SPI), or if it uses internal pull-up or pull-down resistors.           *
                                                                                                          *
                                                                                                          *
*                                                                                                         *
*@Parameters:                                                                                             *
*			     Copy_enuPinNum:                                                                          *
                    Typically defined using a combination of the port and pin numbers                     *
                    (e.g., 0x10 might represent Pin 0 on Port B in an 8-bit architecture).                *
                    Example : #define PIN_A0 0x00 // Port A, Pin 0      ,                                 *
                     #define PIN_C3  0x23 // Port C, Pin 3                                                *

                Copy_enuPinMode:                                                                          *
                    Specifies the mode to be set for the pin.                                             *
                    Examples of possible modes (depending on microcontroller configuration):              *
                    PORT_PIN_MODE_INPUT_PULLUP  : Input with internal pull-up resistor.                   *
                    PORT_PIN_MODE_INPUT_PULLDOWN: Input with pull-down resistor.                          *
                    PORT_PIN_MODE_UART          : UART communication mode.                                *
                    .                                                                                     *
                    .                                                                                     *
                    .                                                                                     *
                                                                                                          *
                                                                                                          *
*                                                                                                         *
*@Return:                                                                                                 *
*				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *
*                                                                                                         *
***********************************************************************************************************/

MDIO_enuErrorStatus_t MPORT_enuSetPinMode(u8 Copy_enuPinNum, MPORT_enuPinMode_t Copy_enuPinMode)
{
    u8 Local_enuPortNum = Copy_enuPinNum >> 4;
    u8 Local_enuPinNum = Copy_enuPinNum & 0x0F;

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (IS_INVALID_PORT_NUM(Local_enuPortNum ))
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (IS_INVALID_PIN_NUM(Local_enuPinNum))
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (Copy_enuPinMode > PORT_PIN_MODE_UART)
    {
        Ret_enuError = MDIO_enuINVALIDMODE;
    }
    else
    {
        Ret_enuError = MDIO_enuOK;
        if (Copy_enuPinMode == PORT_PIN_MODE_INPUT_PULLUP)
        {
            switch (Local_enuPortNum)
            {
            case PORT_A:
                CLR_BIT(DDRA, Local_enuPinNum);
                SET_BIT(PORTA, Local_enuPinNum);
                break;
            case PORT_B:
                CLR_BIT(DDRB, Local_enuPinNum);
                SET_BIT(PORTB, Local_enuPinNum);
                break;
            case PORT_C:
                CLR_BIT(DDRC, Local_enuPinNum);
                SET_BIT(PORTC, Local_enuPinNum);
                break;
            case PORT_D:
                CLR_BIT(DDRD, Local_enuPinNum);
                SET_BIT(PORTD, Local_enuPinNum);
                break;
            }
        }
        else if (Copy_enuPinMode == PORT_PIN_MODE_INPUT_PULLDOWN)
        {
            switch (Local_enuPortNum)
            {
            case PORT_A:
                CLR_BIT(DDRA, Local_enuPinNum);
                break;
            case PORT_B:
                CLR_BIT(DDRB, Local_enuPinNum);
                break;
            case PORT_C:
                CLR_BIT(DDRC, Local_enuPinNum);
                break;
            case PORT_D:
                CLR_BIT(DDRD, Local_enuPinNum);
                break;
            }
        }
    }
    return Ret_enuError;
}
