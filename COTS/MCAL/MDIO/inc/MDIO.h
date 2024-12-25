/*
 * DIO.h
 *
 * Created: 12/17/2024 10:15:35 AM
 *  Author: Fatma Yosry Mohamed
 */

#ifndef DIO_H_
#define DIO_H_

typedef enum
{

    MDIO_enuNOK,
    MDIO_enuOK,
    MDIO_enuINVALIDPIN,
    MDIO_enuINVALIDPORT,
    MDIO_enuINVALIDCONFIG,
    MDIO_enuINVALIDSTATUS,

} MDIO_enuErrorStatus_t;

typedef enum
{
    MDIO_enuPORTA,
    MDIO_enuPORTB,
    MDIO_enuPORTC,
    MDIO_enuPORTD,
} MDIO_enuPortNames_t;

typedef enum
{
    MDIO_enuPIN0,
    MDIO_enuPIN1,
    MDIO_enuPIN2,
    MDIO_enuPIN3,
    MDIO_enuPIN4,
    MDIO_enuPIN5,
    MDIO_enuPIN6,
    MDIO_enuPIN7,

} MDIO_enuPinNames_t;

typedef enum
{
    MDIO_enuLOW,
    MDIO_enuHIGH
} MDIO_enuStates_t;

typedef enum
{
    MDIO_enuALLLOW,
    MDIO_enuALLHIGH
} MDIO_enuPortStates_t;

typedef enum
{
    MDIO_enuOUTPUT,
    MDIO_enuINPUTPULLUP,
    MDIO_enuINPUTPULLDOWN

} MDIO_enuConfiguration_t;

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuConfiguration_t Copy_enuConfigration);
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuConfiguration_t Copy_enuConfigration);
MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, MDIO_enuStates_t Copy_enuState);
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPortStates_t Copy_enuPortState);
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNames_t Copy_enuPortNum, MDIO_enuPinNames_t Copy_enuPinNum, u8 *Add_pu8PinValue);

#endif /* DIO_H_ */