/*
 * LED.h
 *
 * Created: 1/3/2025 8:02:38 AM
 *  Author: lenovo
 */

#ifndef LED_H_
#define LED_H_
#include "../../../LIB/STD_TYPES.h"

// Enum for error states
typedef enum
{

    HLED_enuNOK = 0,
    HLED_enuOK,
    HLED_enuINVALIDPIN,
    HLED_enuINVALIDPORT,
    HLED_enuINVALIDCONFIG,
    HLED_enuINVALIDSTATUS,
    HLED_NULL_PTR,
    HLED_enuINVALIDMODE,
    HLED_enuINVALIDLED

} HLED_enuErrorStatus_t;

// Enum for ports
typedef enum
{
    HLED_enuPORTA = 0,
    HLED_enuPORTB,
    HLED_enuPORTC,
    HLED_enuPORTD,
} HLED_enuPortNames_t;

// Enum for pins
typedef enum
{
    HLED_enuPIN0 = 0,
    HLED_enuPIN1,
    HLED_enuPIN2,
    HLED_enuPIN3,
    HLED_enuPIN4,
    HLED_enuPIN5,
    HLED_enuPIN6,
    HLED_enuPIN7,

} HLED_enuPinNames_t;

typedef enum
{
    HLED_enuForward = 0,
    HLED_enuReverse

} HLED_enuLed_Connection_t;

typedef enum
{
    HLED_enuLow = 0,
    HLED_enuHIGH

} HLED_enuLed_Status_t;

/*************** APIS PROTO TYPES ***************/
void LED_init(void);
HLED_enuErrorStatus_t LED_enuSetLedState(u8 Copy_u8LedName, u8 Copy_u8State);

#endif 
/* LED_H_ */