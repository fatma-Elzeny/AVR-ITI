/*
 * SWITCH.h
 *
 * Created: 1/3/2025 8:02:38 AM
 *  Author: lenovo
 */

#ifndef SWITCH_H_
#define SWITCH_H_
#include "../../../LIB/STD_TYPES.h"

// Enum for error states
typedef enum
{

    HSWITCH_enuNOK = 0,
    HSWITCH_enuOK,
    HSWITCH_enuINVALIDPIN,
    HSWITCH_enuINVALIDPORT,
    HSWITCH_enuINVALIDCONFIG,
    HSWITCH_enuINVALIDSTATUS,
    HSWITCH_NULL_PTR,
    HSWITCH_enuINVALIDMODE,
    HSWITCH_enuINVALIDSWITCH

} SWITCH_enuErrorStatus_t;

// Enum for ports
typedef enum
{
    HSWITCH_enuPORTA = 0,
    HSWITCH_enuPORTB,
    HSWITCH_enuPORTC,
    HSWITCH_enuPORTD,
} HSWITCH_enuPortNames_t;

// Enum for pins
typedef enum
{
    HSWITCH_enuPIN0 = 0,
    HSWITCH_enuPIN1,
    HSWITCH_enuPIN2,
    HSWITCH_enuPIN3,
    HSWITCH_enuPIN4,
    HSWITCH_enuPIN5,
    HSWITCH_enuPIN6,
    HSWITCH_enuPIN7,

} HSWITCH_enuPinNames_t;





/*************** APIS PROTO TYPES ***************/
void SWITCH_init(void);
SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8*Add_pu8State);

#endif 
/* LED_H_ */