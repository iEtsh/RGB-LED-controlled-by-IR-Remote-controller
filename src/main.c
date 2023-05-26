/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|________________________________________________________________________________|
| ~ Author:          Hesham Abdallah NourEldeen                                  |
| ~ Creation Data:   23 May 2023                                                 |
| ~ Version:         v1.0                                                        |
| ~ Compiler:        GNU ARM-GCC                                                 |
| ~ Controller:      STM32F401CCU6                                               |
|________________________________________________________________________________|
| ~ Version     Date                  Author                  Description        |
| ~ v1.0        22 May, 2023    Hesham Abdallah NourEldeen    Initial Creation   |
|________________________________________________________________________________|
|                                                                                |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "IR_interface.h"

void main(void)
{
	HIR_voidInit();


	while(1)
	{
		HIR_voidPlay();
	}
}

