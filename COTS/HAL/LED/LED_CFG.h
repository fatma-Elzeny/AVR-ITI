/*
 * LED_CFG.h
 *
 * Created: 1/3/2025 8:18:45 AM
 *  Author: lenovo
 */

#ifndef LED_CFG_H_
#define LED_CFG_H_
#include "../../../LIB/STD_TYPES.h"
#include "LED.h"
typedef struct
{
    u8 port;
    u8 pin;
    HLED_enuLed_Connection_t connection_Type;
} ledcfg_t;

#define NUM_OF_LEDS 3
#define LED_START 0
#define LED_STOP 1
#define LED_ALERT 2

#endif /* LED_CFG_H_ */