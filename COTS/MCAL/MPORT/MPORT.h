/*
 * MPORT.h
 *
 * Created: 12/25/2024 12:41:27 PM
 *  Author: lenovo
 */

#ifndef MPORT_H_
#define MPORT_H_
#include "../MDIO/MDIO.h"
#include "../../../LIB/STD_TYPES.h"
typedef enum
{
    MPORT_enuOUTPUT = 0,
    MPORT_enuINPUT

} MPORT_enuConfiguration_t;
typedef enum
{

    PORT_PIN_MODE_INPUT_PULLUP,   // Input with internal pull-up resistor.
    PORT_PIN_MODE_INPUT_PULLDOWN, // Input with pull-down resistor.
    PORT_PIN_MODE_UART            // UART communication mode.

} MPORT_enuPinMode_t;


#define PORT_MAX_NUM 3
#define PIN_MAX_NUM 7

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN_A0 0x00
#define PIN_A1 0x01
#define PIN_A2 0x02
#define PIN_A3 0x03
#define PIN_A4 0x04
#define PIN_A5 0x05
#define PIN_A6 0x06
#define PIN_A7 0x07

#define PIN_B0 0x10
#define PIN_B1 0x11
#define PIN_B2 0x12
#define PIN_B3 0x13
#define PIN_B4 0x14
#define PIN_B5 0x15
#define PIN_B6 0x16
#define PIN_B7 0x17

#define PIN_C0 0x20
#define PIN_C1 0x21
#define PIN_C2 0x22
#define PIN_C3 0x23
#define PIN_C4 0x24
#define PIN_C5 0x25
#define PIN_C6 0x26
#define PIN_C7 0x27

#define PIN_D0 0x30
#define PIN_D1 0x31
#define PIN_D2 0x32
#define PIN_D3 0x33
#define PIN_D4 0x34
#define PIN_D5 0x35
#define PIN_D6 0x36
#define PIN_D7 0x37

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
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuConfiguration_t Copy_enuConfigration);

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
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuConfiguration_t Copy_enuConfigration);

// Function to set pin Direction (OUTPUT , INPUT )
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

MDIO_enuErrorStatus_t MPORT_enuSetPinDirection(u8 Copy_enuPinNum,  MPORT_enuConfiguration_t Copy_enuPinDirection);

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

MDIO_enuErrorStatus_t MPORT_enuSetPinMode(u8 Copy_enuPinNum, MPORT_enuPinMode_t Copy_enuPinMode);

#endif /* MPORT_H_ */