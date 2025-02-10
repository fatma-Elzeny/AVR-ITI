


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR			*((volatile u8*)0x5B)
#define GICR_INT1		(7U)
#define GICR_INT0		(6U)
#define GICR_INT2		(5U)

#define GIFR			*((volatile u8*)0x5A)
#define GIFR_INT1		(7U)
#define GIFR_INT0		(6U)
#define GIFR_INT2		(5U)

#define MCUCR			*((volatile u8*)0x55)
#define MCUCR_ISC11		(3U)
#define MCUCR_ISC10		(2U)		
#define MCUCR_ISC01		(1U)
#define MCUCR_ISC00		(0U)

#define MCUCSR			*((volatile u8*)0x54)
#define MCUCSR_ISC2		(6U)

#define MCUCR_ISC0_MUSK	(0xFCU)
#define MCUCR_ISC1_MUSK	(0xF3U)

#endif /* EXTI_PRIVATE_H_ */