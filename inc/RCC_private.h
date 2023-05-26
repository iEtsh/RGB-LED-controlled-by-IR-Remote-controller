/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|________________________________________________________________________________|
| ~ Author:          Hesham Abdallah NourEldeen                                  |                                                    
| ~ Creation Data:   01 May 2023                                                 |    
| ~ Version:         v1.0                                                        |
| ~ Compiler:        GNU ARM-GCC                                                 |    
| ~ Controller:      STM32F401CCU6												 |
| ~ Driver:			 RCC            								             |
|________________________________________________________________________________|
| ~ Version     Date                  Author                  Description        |    
| ~ v1.0        03 May, 2023    Hesham Abdallah NourEldeen    Initial Creation   |    
|________________________________________________________________________________|
|                                                                                |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS        0x40023800
//0x4002 3800
//#define RCC_CR      * ( (volatile u32 *) (0x00 + RCC_BASE_ADDRESS) )


typedef struct
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR; //Enable perphirals on ahb1
    volatile u32 AHB2RSTR; //Enable perphirals on ahb2
    volatile u32 RESERVED[2];//because there're two consecutive reserved locations
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 RESERVED2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 RESERVED3[2];
    volatile u32 APB1ENR; //Enable perphirals on apb1
    volatile u32 APB2ENR; //Enable perphirals on apb2
    volatile u32 RESERVED4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 RESERVED5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 RESERVED6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 RESERVED7[2];
    volatile u32 SSCGR;
    volatile u32 _PLLI2SCFGR;
    volatile u32 RESERVED8;
    volatile u32 DCKCFGR;
}RCC_t;

/*Pointer To Structure Started From BaseAddress*/
#define RCC             ((volatile RCC_t*)RCC_BASE_ADDRESS)

/*Prescaller for APB1 and APB2*/
#define APB1_2_DIVIDE_BY_2     0
#define APB1_2_DIVIDE_BY_4     1
#define APB1_2_DIVIDE_BY_8     2


/*Prescaller for AHB*/
/*SYSCLOCK options:
    HSI - HSE - PLL*/
#define SYSCLOCK_DIVIDE_BY_1   0
#define SYSCLOCK_DIVIDE_BY_2   8
#define SYSCLOCK_DIVIDE_BY_4   9
#define SYSCLOCK_DIVIDE_BY_8   10
#define SYSCLOCK_DIVIDE_BY_16  11
#define SYSCLOCK_DIVIDE_BY_32  12
#define SYSCLOCK_DIVIDE_BY_64  13
#define SYSCLOCK_DIVIDE_BY_128  14
#define SYSCLOCK_DIVIDE_BY_256  15




#endif
