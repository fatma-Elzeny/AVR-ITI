#ifndef BIT_MATH_H_
#define BIT_MATH_H_

// Set bit BIT in REG
#define SET_BIT(REG, BIT_NUM) REG |= (1 << BIT_NUM)
// Clear bit BIT in REG
#define CLR_BIT(REG, BIT_NUM) REG &= (~(1 << BIT_NUM))
// Toggle bit BIT in REG
#define TOG_BIT(REG, BIT_NUM) REG ^= (1 << BIT_NUM)
// Get bit BIT in REG
#define GET_BIT(REG, BIT_NUM) ((REG >> BIT_NUM) & 0X01)
// Set high nibble in REG
#define SET_HIGH_NIB(REG) ((REG) |= 0xF0)
// Clear high nibble in REG
#define CLR_HIGH_NIB(REG) ((REG) &= 0x0F)
// Get high nibble in REG
#define GET_HIGH_NIB(REG) (REG >> 4) & 0X0F
// Toggle high nibble in REG
#define TGL_HIGH_NIB(REG) ((REG) ^= 0xF0)
// Set low nibble in REG
#define SET_LOW_NIB(REG) ((REG) |= 0x0F)
// Clear low nibble in REG
#define CLR_LOW_NIB(REG) ((REG) &= 0xF0)
// Get low nibble in REG
#define GET_LOW_NIB(REG) (REG) & 0X0F
// Toggle low nibble in REG
#define TGL_LOW_NIB(REG) ((REG) ^= 0x0F)

// Assign VALUE to REG
#define ASSIGN_REG(REG, VALUE) ((REG) = ((REG & 0x00) | (VALUE)))
// Assign VALUE to high nibble REG
#define ASSIGN_HIGH_NIB(REG, VALUE) ((REG) = ((REG & 0x0F) | ((VALUE) << 4)))
// Assign VALUE to low nibble REG
#define ASSIGN_LOW_NIB(REG, VALUE) ((REG) = ((REG & 0xF0) | (VALUE)))
// Right shift by NO in REG
#define RSHFT_REG(REG, NO) ((REG) >> (NO))
// Left shift by NO in REG
#define LSHFT_REG(REG, NO) ((REG) << (NO))
// Circular right shift by NO in REG
#define CRSHFT_REG(REG, NO) (((REG) >> (NO)) | ((REG) << (sizeof(REG) * 8 - (NO))))
// Circular left shift by NO in REG
#define CLSHFT_REG(REG, NO) (((REG) << (NO)) | ((REG) >> (sizeof(REG) * 8 - (NO))))

#endif