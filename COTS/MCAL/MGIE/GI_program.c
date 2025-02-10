

/* UTILES_LIB */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

/* MCAL */
#include "GI_interface.h"
#include "GI_register.h"


void GI_voidEnable(void)
{
	SET_BIT(SREG_REG, I);
}

void GI_voidDisable(void)
{
	CLR_BIT(SREG_REG, I);
}
