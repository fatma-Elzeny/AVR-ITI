/*
 * SWITCH_CFG.h
 *
 * Created: 1/3/2025 8:18:45 AM
 *  Author: lenovo
 */

#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_
#include "../../../LIB/STD_TYPES.h"
typedef struct
{
    u8 port;
    u8 pin;
    
} switchcfg_t;

#define NUM_OF_SWITCHES 3
#define SWITCH_START 0
#define SWITCH_STOP  1
#define SWITCH_ALERT 2

#endif /* LED_CFG_H_ */