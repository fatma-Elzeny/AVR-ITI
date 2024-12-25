/*
 * DIO.c
 *
 * Created: 12/17/2024 10:15:16 AM
 *  Author: Fatma Yosry Mohamed
 */

#include "../../../STD_LIB/inc/BIT_MATH.h"
#include "../inc/MDIO_CFG.h"
#include "../inc/MDIO.h"
#define NULL 0

typedef unsigned char u8;

// definition of registers
#define PORTA (*((volatile u8 *)0x3B))
#define DDRA (*((volatile u8 *)0x3A))
#define PINA (*((volatile u8 *)0x39))

#define PORTB (*((volatile u8 *)0x38))
#define DDRB (*((volatile u8 *)0x37))
#define PINB (*((volatile u8 *)0x36))

#define PORTC (*((volatile u8 *)0x35))
#define DDRC (*((volatile u8 *)0x34))
#define PINC (*((volatile u8 *)0x33))

#define PORTD (*((volatile u8 *)0x32))
#define DDRD (*((volatile u8 *)0x31))
#define PIND (*((volatile u8 *)0x30))

extern MDIO_enuConfiguration_t MDIO_enuArrPinConfig[NUM_OF_PORTS * NUM_OF_PINS];

// Function to initialize DIO
/****************************** MDIO_voidInit *******************************************
 * @brief        :  Initialize direction of all pins as specified by user in _LCFG.c     *
 * @param        :  None --- But user must fill in MDIO_enuArrPinConfig array            *
 * @return       :  None                                                                 *
 ****************************************************************************************/
void MDIO_vInit(void)
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
* @description  : This API configures a specific pin within a port with the desired functionality,        *
*				 such as input, output, or pull-up/down configuration. It allows precise control          *
*				 over individual pins in a microcontroller's GPIO.                                        *
*                                                                                                         *
*@Parameters:                                                                                             *
*			   Copy_enuPortNum:                                                                           *
*				Specifies the port containing the pin to configure (e.g., PORTA, PORTB, PORTC, etc.).     *
*                                                                                                         *
*				Copy_enuPinNum:                                                                           *
*				Specifies the pin within the port to configure (e.g., PIN0, PIN1, PIN2, etc.).            *
*                                                                                                         *
*				Copy_enuConfigration:                                                                     *
*				Specifies the desired configuration for the pin. Examples:                                *
*				OUTPUT,INPUT_PULLUP,INPUT_PULLDOWN                                                        *
*@Return:                                                                                                 *
*				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *

***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuConfiguration_t Copy_enuConfigration)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (Copy_enuPinNum > MDIO_enuPIN7)
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (Copy_enuConfigration > MDIO_enuINPUT)
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
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (Copy_enuConfigration > MDIO_enuINPUT)
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

// Function to set state on pin (LOW,HIGH)
/****************************** MDIO_enuSetPinValue *******************************************************
 * @description  :  This API sets the logical state of a specific pin (e.g., HIGH or LOW)                  *
 *                                                                                                         *
 *@Parameters:                                                                                             *
 *			   Copy_enuPortNum:                                                                           *
 *				Specifies the port containing the pin to configure (e.g., PORTA, PORTB, PORTC, etc.).     *
 *                                                                                                         *
 *				Copy_enuPinNum:                                                                           *
 *				Specifies the pin within the port to configure (e.g., PIN0, PIN1, PIN2, etc.).            *
 *                                                                                                         *
 *				Copy_enuState:                                                                            *
 *                Specifies the desired state for the pin: HIGH,LOW                                        *
 *                                                                                                         *
 *@Return:                                                                                                 *
 *				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *
 *                                                                                                         *
 ***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuStates_t Copy_enuState)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (Copy_enuPinNum > MDIO_enuPIN7)
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (Copy_enuState > MDIO_enuHIGH)
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
*			   Copy_enuPortNum:                                                                           *
*				Specifies the port containing the pin to configure (e.g., PORTA, PORTB, PORTC, etc.).     *
*                                                                                                         *
*				                                                                                          *                                                                                    *
*				Copy_enuState:                                                                            *
*                 Specifies the collective state for all pins in the port (e.g. all HIGH, all LOW)        *
*                                                                                                         *
*@Return:                                                                                                 *
*				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *
*                                                                                                         *
***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPortStates_t Copy_enuPortState)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (Copy_enuPortState > MDIO_enuALLHIGH)
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
 *			   Copy_enuPortNum:                                                                           *
 *				Specifies the port containing the pin to configure (e.g., PORTA, PORTB, PORTC, etc.).     *
 *                                                                                                         *
 *				Copy_enuPinNum:                                                                           *
 *				Specifies the pin within the port to configure (e.g., PIN0, PIN1, PIN2, etc.).            *
 *                                                                                                         *
 *				 Add_pu8PinValue:                                                                         *
 *                Pointer to store the retrieved pin value                                                 *
 *                                                                                                         *
 *@Return:                                                                                                 *
 *				MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........                                           *
 *                                                                                                         *
 ***********************************************************************************************************/
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, u8 *Add_pu8PinValue)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (Copy_enuPortNum > MDIO_enuPORTD)
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (Copy_enuPinNum > MDIO_enuPIN7)
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (Add_pu8PinValue == NULL)
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

// Function to set state on pin (LOW,HIGH)
/****************************** MDIO_enuSetPinValue *******************************************************
* @description  :  The DIO_setPin function is used to control the digital state of a specific pin on      *
                    a given port in a microcontroller.                                                    *
                   It allows setting a pin to either a high (logic 1) or low (logic 0) state.             *
*                                                                                                         *
*@Parameters:                                                                                             *
                 uint8_t Copy_u8PortNum:                                                                  *
                The port number to which the pin belongs.                                                 *
                                                                                                          *
                uint8_t Copy_u8PinNum:                                                                    *
                The specific pin number within the selected port to be modified.                          *
                                                                                                          *
                uint8_t Copy_u8Value:                                                                     *
                The desired state to set the pin to:                                                      *
                -High state (logic 1).                                                                    *
                -Low state (logic 0) .                                                                    *
*                                                                                                         *
*@Return:                                                                                                 *
*			void                                                                                          *
*                                                                                                         *
***********************************************************************************************************/
void MDIO_vSetPin(u8 Copy_enuPortNum, u8 Copy_enuPinNum, u8 Copy_enuState)
{

    MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
    if (Copy_enuPortNum > NUM_OF_PORTS)
    {
        Ret_enuError = MDIO_enuINVALIDPORT;
    }
    else if (Copy_enuPinNum > NUM_OF_PINS)
    {
        Ret_enuError = MDIO_enuINVALIDPIN;
    }
    else if (Copy_enuState > MDIO_enuHIGH)
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
}