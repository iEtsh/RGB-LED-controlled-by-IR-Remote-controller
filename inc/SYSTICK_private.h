/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|________________________________________________________________________________|
| ~ Author:          Hesham Abdallah NourEldeen                                  |
| ~ Creation Data:   09 May 2023                                                 |
| ~ Version:         v1.0                                                        |
| ~ Compiler:        GNU ARM-GCC                                                 |
| ~ Controller:      STM32F401CCU6												 |
| ~ Driver:			 SYSTICK   								            		 |
|________________________________________________________________________________|
| ~ Version     Date                  Author                  Description        |
| ~ v1.0        09 May, 2023    Hesham Abdallah NourEldeen    Initial Creation   |
|________________________________________________________________________________|
|                                                                                |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_BASE_ADDRESS        0xE000E010

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CAL;

}SYSTICK_t;

/*Pointer To Structure Started From BaseAddress*/
#define SYSTICK         ((volatile SYSTICK_t*)SYSTICK_BASE_ADDRESS)

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define AHB_DIV_1 0
#define AHB_DIV_8 1

#define SINGLE_INTERVAL_FLAG	0
#define PERIODIC_INTERVAL_FLAG	1

#define DISABLE					0
#define ENABLE					1

#define AHB_DIV_1				0
#define AHB_DIV_8				1


#endif
