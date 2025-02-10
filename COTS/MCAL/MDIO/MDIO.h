/*
 * DIO.h
 *
 * Created: 12/17/2024 10:15:35 AM
 *  Author: Fatma Yosry Mohamed
 */

#ifndef DIO_H_
#define DIO_H_
#include "../../../LIB/STD_TYPES.h"

// Enum for error states
typedef enum
{

    MDIO_enuNOK = 0,
    MDIO_enuOK,
    MDIO_enuINVALIDPIN,
    MDIO_enuINVALIDPORT,
    MDIO_enuINVALIDCONFIG,
    MDIO_enuINVALIDSTATUS,
    MDIO_NULL_PTR,
    MDIO_enuINVALIDMODE

} MDIO_enuErrorStatus_t;

// Enum for ports
typedef enum
{
    MDIO_enuPORTA = 0,
    MDIO_enuPORTB,
    MDIO_enuPORTC,
    MDIO_enuPORTD,
} MDIO_enuPortNames_t;

// Enum for pins
typedef enum
{
    MDIO_enuPIN0 = 0,
    MDIO_enuPIN1,
    MDIO_enuPIN2,
    MDIO_enuPIN3,
    MDIO_enuPIN4,
    MDIO_enuPIN5,
    MDIO_enuPIN6,
    MDIO_enuPIN7,

} MDIO_enuPinNames_t;

// Enum for states for pins
typedef enum
{
    MDIO_enuLOW = 0,
    MDIO_enuHIGH
} MDIO_enuStates_t;

// Enum for states for ports
typedef enum
{
    MDIO_enuALLLOW = 0,
    MDIO_enuALLHIGH
} MDIO_enuPortStates_t;
// Enum for configuration
typedef enum
{
    MDIO_enuOUTPUT = 0,
    MDIO_enuINPUTPULLUP,
    MDIO_enuINPUT

} MDIO_enuConfiguration_t;


// Function to set state on pin (LOW,HIGH)
/****************************** MDIO_enuSetPinValue *******************************************************
 * @description  :  This API sets the logical state of a specific pin (e.g., HIGH or LOW)                  *                   *
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
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuStates_t Copy_enuState);

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
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPortStates_t Copy_enuPortState);

// Function to get status of pin

/****************************** MDIO_enuGetPinValue *******************************************************
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
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, u8 *Add_pu8PinValue);
//
void MDIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue);
//
void MDIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue);

#endif /* DIO_H_ */