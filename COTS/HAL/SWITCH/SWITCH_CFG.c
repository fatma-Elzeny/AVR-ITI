/*
 * SWITCH_CFG.c
 *
 * Created: 1/3/2025 8:20:43 AM
 *  Author: lenovo
 */

#include "SWITCH_CFG.h"
#include "SWITCH.h"

switchcfg_t switchcfg[NUM_OF_SWITCHES] = {

    [SWITCH_START] = {
        .port = HSWITCH_enuPORTD,
        .pin = HSWITCH_enuPIN5,
       
        },
    [SWITCH_ALERT] = {
        .port = HSWITCH_enuPORTD, 
        .pin = HSWITCH_enuPIN6,
       
        },
    [SWITCH_STOP] = {
        .port = HSWITCH_enuPORTD, 
        .pin = HSWITCH_enuPIN7,
        
        }
        
     };
