/*
 * LED.c
 *
 * Created: 1/3/2025 8:02:18 AM
 *  Author: lenovo
 */
#include "LED.h"
#include "LED_CFG.h"
#include "../../MCAL/MPORT/MPORT.h"
#include "../../MCAL/MDIO/MDIO.h"

extern ledcfg_t ledcfg[NUM_OF_LEDS];
void LED_init(void)
{

    u8 Local_u8_currentPinPort = 0;
    u8 Local_u8_i = 0;
    for (Local_u8_i = 0; Local_u8_i < NUM_OF_LEDS; Local_u8_i++)
    {
        Local_u8_currentPinPort = ((ledcfg[Local_u8_i].port << 4) + ledcfg[Local_u8_i].pin);
        MPORT_enuSetPinDirection(Local_u8_currentPinPort, MPORT_enuOUTPUT);
    }
}

HLED_enuErrorStatus_t LED_enuSetLedState(u8 Copy_u8LedName, u8 Copy_u8State)
{

    HLED_enuErrorStatus_t Ret_enuError = HLED_enuNOK;
    if (Copy_u8LedName > LED_ALERT)
    {

        Ret_enuError = HLED_enuINVALIDLED;
    }
    else if (Copy_u8State > HLED_enuHIGH)
    {

        Ret_enuError = HLED_enuINVALIDSTATUS;
    }
    else
    {

        Ret_enuError = HLED_enuOK;
        switch (Copy_u8LedName)
        {

        case LED_START:
            MDIO_enuSetPinValue(ledcfg[LED_START].port, ledcfg[LED_START].pin, Copy_u8State);
            break;
        case LED_STOP:
            MDIO_enuSetPinValue(ledcfg[LED_STOP].port, ledcfg[LED_STOP].pin, Copy_u8State);
            break;
        case LED_ALERT:
            MDIO_enuSetPinValue(ledcfg[LED_ALERT].port, ledcfg[LED_ALERT].pin, Copy_u8State);
            break;
        }
    }
	return Ret_enuError;
};
