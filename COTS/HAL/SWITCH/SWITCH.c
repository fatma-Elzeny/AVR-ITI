/*
 * SWITCH.c
 *
 * Created: 1/3/2025 8:02:18 AM
 *  Author: lenovo
 */
#include "SWITCH.h"
#include "SWITCH_CFG.h"
#include "../../MCAL/MPORT/MPORT.h"
#include "../../MCAL/MDIO/MDIO.h"

extern switchcfg_t switchcfg[NUM_OF_SWITCHES];
void SWITCH_init(void)
{

    u8 Local_u8_currentPinPort = 0;
    u8 Local_u8_i = 0;
    for (Local_u8_i = 0; Local_u8_i < NUM_OF_SWITCHES; Local_u8_i++)
    {
        Local_u8_currentPinPort = ((switchcfg[Local_u8_i].port << 4) + switchcfg[Local_u8_i].pin);
        MPORT_enuSetPinDirection(Local_u8_currentPinPort, MPORT_enuINPUT);
        MPORT_enuSetPinMode(Local_u8_currentPinPort,PORT_PIN_MODE_INPUT_PULLUP );
    }
}

SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8*Add_pu8State)
{

    SWITCH_enuErrorStatus_t Ret_enuError = HSWITCH_enuNOK;
    if (Copy_u8SwitchName > SWITCH_ALERT)
    {

        Ret_enuError = HSWITCH_enuINVALIDSWITCH;
    }
    else if (Add_pu8State == NULL)
    {

        Ret_enuError = HSWITCH_NULL_PTR;
    }
    else
    {

        Ret_enuError = HSWITCH_enuOK;
        switch (Copy_u8SwitchName)
        {

        case SWITCH_START:
            MDIO_enuGetPinValue(switchcfg[SWITCH_START].port, switchcfg[SWITCH_START].pin,Add_pu8State);
            break;
        case SWITCH_STOP:
            MDIO_enuGetPinValue(switchcfg[SWITCH_STOP].port, switchcfg[SWITCH_STOP].pin,Add_pu8State );
            break;
        case SWITCH_ALERT:
            MDIO_enuGetPinValue(switchcfg[SWITCH_ALERT].port, switchcfg[SWITCH_ALERT].pin,Add_pu8State);
            break;
        }
    }
	return Ret_enuError;
};