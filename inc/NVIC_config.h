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
#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_



/*Choose:
 *
	GRP_4_SUB_0_BITS
	GRP_3_SUB_1_BITS
	GRP_2_SUB_2_BITS
	GRP_1_SUB_3_BITS
	GRP_0_SUB_4_BITS
*/

#define		MNVIC_EXTI0							6
#define		MNVIC_EXTI1							7

#define 	MNVIC_GRP_SUB_DISTRUBTION			GRP_2_SUB_2_BITS



#endif /* NVIC_CONFIG_H_ */
