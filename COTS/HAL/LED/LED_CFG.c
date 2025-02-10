/*
 * LED_CFG.c
 *
 * Created: 1/3/2025 8:20:43 AM
 *  Author: lenovo
 */

#include "LED_CFG.h"
#include "LED.h"

ledcfg_t ledcfg[NUM_OF_LEDS] = {

    [LED_START] = {
        .port = HLED_enuPORTB,
        .pin = HLED_enuPIN2,
        .connection_Type = HLED_enuForward
        },
    [LED_ALERT] = {
        .port = HLED_enuPORTB, 
        .pin = HLED_enuPIN3,
        .connection_Type = HLED_enuForward
        },
    [LED_STOP] = {
        .port = HLED_enuPORTB, 
        .pin = HLED_enuPIN4,
        .connection_Type = HLED_enuForward
        }
        
     };