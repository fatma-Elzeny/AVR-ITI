

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	EXTI_enuEXTI0 ,
	EXTI_enuEXTI1,
	EXTI_enuEXTI2
} EXTI_uddtIntID_t;

typedef enum
{
	EXTI_enu_LOW_LEVEL ,
	EXTI_enu_ON_CHANGE,
	EXTI_enu_FALLING_EDGE,
	EXTI_enu_RISING_EDGE
} EXTI_uddtSenseCtrl_t;

void EXTI_voidEnable(EXTI_uddtIntID_t Copy_uddtIntID);

void EXTI_voidDisable(EXTI_uddtIntID_t Copy_uddtIntID);

void EXTI_voidSetSenseControl(EXTI_uddtIntID_t Copy_uddtIntID, EXTI_uddtSenseCtrl_t Copy_uddtSenseCntrl);

void EXTI_voidSetCallbackEXTI0(void (*Copy_pfEXTI0_Callback) (void));

void EXTI_voidSetCallbackEXTI1(void (*Copy_pfEXTI1_Callback) (void));

void EXTI_voidSetCallbackEXTI2(void (*Copy_pfEXTI2_Callback) (void));

#endif /* EXTI_INTERFACE_H_ */