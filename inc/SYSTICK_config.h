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
#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

/*Choose:
  ENABLE
  DISABLE
  */
#define STK_ENABLE          ENABLE



/*Choose:
  AHB_DIV_1
  AHB_DIV_8*/
#define STK_CLK_SOURCE          AHB_DIV_8



/*Choose:
  ENABLE
  DISABLE
  */
#define STK_INTERRUPT_ENABLE    DISABLE
#endif
