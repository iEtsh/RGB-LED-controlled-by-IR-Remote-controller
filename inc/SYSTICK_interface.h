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
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


/*STK_CTRL Register bits*/
#define STK_ENABLE  0
#define STK_INTERRUPT_ENABLE  1
#define STK_CLK_SOURCE        2
#define STK_COUNT_FLAG        16




void MSTK_voidinit               (void);

void MSTK_voidSetBusyWait        (u32 Copy_u32TicksToWait);

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks , void(*NotificationFunction)(void));

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks , void(*NotificationFunction)(void));

u32 MSTK_u32GetRemainaingTime    (void);

u32 MSTK_u32GetElapsedTime       (void);
#endif
