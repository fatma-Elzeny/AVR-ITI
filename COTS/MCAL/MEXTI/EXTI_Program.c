
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"

static void (*EXTI0_Callback) (void) = NULL;
static void (*EXTI1_Callback) (void) = NULL;
static void (*EXTI2_Callback) (void) = NULL;


void EXTI_voidEnable(EXTI_uddtIntID_t Copy_uddtIntID)
{
	switch (Copy_uddtIntID)
	{
	case EXTI_enuEXTI0: SET_BIT(GICR, GICR_INT0); break;
	case EXTI_enuEXTI1: SET_BIT(GICR, GICR_INT1); break;
	case EXTI_enuEXTI2: SET_BIT(GICR, GICR_INT2); break;
	default: break;
	}
}

void EXTI_voidDisable(EXTI_uddtIntID_t Copy_uddtIntID)
{
	switch (Copy_uddtIntID)
	{
		case EXTI_enuEXTI0: CLR_BIT(GICR, GICR_INT0); break;
		case EXTI_enuEXTI1: CLR_BIT(GICR, GICR_INT1); break;
		case EXTI_enuEXTI2: CLR_BIT(GICR, GICR_INT2); break;
		default: break;
	}
}

void EXTI_voidSetSenseControl(EXTI_uddtIntID_t Copy_uddtIntID, EXTI_uddtSenseCtrl_t Copy_uddtSenseCntrl)
{
	u8 Loc_u8TmpReg = 0U;
	
	switch (Copy_uddtIntID)
	{
		case EXTI_enuEXTI0:
		{
			Loc_u8TmpReg = MCUCR;
			Loc_u8TmpReg &= MCUCR_ISC0_MUSK;
			Loc_u8TmpReg |= (Copy_uddtSenseCntrl << MCUCR_ISC00);
			MCUCR = Loc_u8TmpReg;
			break;
		}
		case EXTI_enuEXTI1:
		{
			Loc_u8TmpReg = MCUCR;
			Loc_u8TmpReg &= MCUCR_ISC1_MUSK;
			Loc_u8TmpReg |= (Copy_uddtSenseCntrl << MCUCR_ISC10);
			MCUCR = Loc_u8TmpReg;
			break;
		}
		case EXTI_enuEXTI2:
		{
			switch (Copy_uddtSenseCntrl)
			{
			case EXTI_enu_RISING_EDGE: SET_BIT(MCUCSR, MCUCSR_ISC2); break;
			case EXTI_enu_FALLING_EDGE: CLR_BIT(MCUCSR, MCUCSR_ISC2); break;
			default: break;
			}
			
			break;
		}
		default: break;
	}
}

void EXTI_voidSetCallbackEXTI0(void (*Copy_pfEXTI0_Callback) (void))
{
	if (NULL != Copy_pfEXTI0_Callback)
	{
		EXTI0_Callback = Copy_pfEXTI0_Callback;
	}
}

void EXTI_voidSetCallbackEXTI1(void (*Copy_pfEXTI1_Callback) (void))
{
	if (NULL != Copy_pfEXTI1_Callback)
	{
		EXTI1_Callback = Copy_pfEXTI1_Callback;
	}
}

void EXTI_voidSetCallbackEXTI2(void (*Copy_pfEXTI2_Callback) (void))
{
	if (NULL != Copy_pfEXTI2_Callback)
	{
		EXTI2_Callback = Copy_pfEXTI2_Callback;
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (NULL != EXTI0_Callback)
	{
		EXTI0_Callback();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (NULL != EXTI1_Callback)
	{
		EXTI1_Callback();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (NULL != EXTI2_Callback)
	{
		EXTI2_Callback();
	}
}
