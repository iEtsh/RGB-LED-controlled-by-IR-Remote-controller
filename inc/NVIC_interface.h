/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|________________________________________________________________________________|
| ~ Author:          Hesham Abdallah NourEldeen                                  |
| ~ Creation Data:   21 May 2023                                                 |
| ~ Version:         v1.0                                                        |
| ~ Compiler:        GNU ARM-GCC                                                 |
| ~ Controller:      STM32F401CCU6                                               |
|________________________________________________________________________________|
| ~ Version     Date                  Author                  Description        |
| ~ v1.0        21 May, 2023    Hesham Abdallah NourEldeen    Initial Creation   |
|________________________________________________________________________________|
|                                                                                |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/**/
void MNVIC_voidInit(void);

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID);

void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID);

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID);

u8 MNVIC_voidGetActiveFlag(u8 Copy_u8PeripheralID);

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID , u8 Copy_u8Priority);

#endif /* NVIC_INTERFACE_H_ */
