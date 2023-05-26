/*********************************************
 * Author:          Hesham Abdallah NourEldeen
 * Creation Data:   22 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         22 MAR, 2023    Hesham Abdallah NourEldeen    Initial Creation
*********************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H




#define    SET_BIT(REG_NAME, BIT_NUM)          (REG_NAME |= (1 << BIT_NUM))
#define    CLR_BIT(REG_NAME, BIT_NUM)          (REG_NAME &= (~(1 << BIT_NUM)))
#define    GET_BIT(REG_NAME, BIT_NUM)          ((REG_NAME >> BIT_NUM) & 0x01)
#define    TOG_BIT(REG_NAME, BIT_NUM)          (REG_NAME ^= (1 << BIT_NUM))
#define    SET_REG(REG_NAME, VALUE)            (REG_NAME = VALUE)
#define    GET_REG(REG_NAME)                   (REG_NAME)
#define    CLR_REG(REG_NAME)                   (REG_NAME = 0x00)





#endif
