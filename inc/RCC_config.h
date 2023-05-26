/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|________________________________________________________________________________|
| ~ Author:          Hesham Abdallah NourEldeen                                  |                                                    
| ~ Creation Data:   01 May 2023                                                 |    
| ~ Version:         v1.0                                                        |
| ~ Compiler:        GNU ARM-GCC                                                 |    
| ~ Controller:      STM32F401CCU6                                               |        
|________________________________________________________________________________|
| ~ Version     Date                  Author                  Description        |    
| ~ v1.0        03 May, 2023    Hesham Abdallah NourEldeen    Initial Creation   |    
|________________________________________________________________________________|
|                                                                                |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*RCC_CPU_CLK_SOURCE*/
/*
Choose:
    - HSI
    - HSE
    - PLL
    */

#define HSI 0
#define HSE 1
#define PLL 2
//HSE
#define     CPU_CLK_SOURCE          HSI

/*
Choose:
   - HSI
   - HSE 
   */
#define     PLL_SOURCE              HSI


#define     AHB_PRESCALLER           SYSCLOCK_DIVIDE_BY_2

#define     AHB1_PRESCALLER          APB1_2_DIVIDE_BY_2
#define     AHB2_PRESCALLER          APB1_2_DIVIDE_BY_2








/*  
Choose:
  - RC
  - OSCI
*/
#define     HSE_CLK_SOURCE       OSCI

/*  
Choose:
   - PLL_DIV_2
   - PLL_DIV_4
   - PLL_DIV_6
   - PLL_DIV_8
*/
#define     PLL_DIV_FACTOR      PLL_DIV_2

/* 
Choose:
    192 - 432 
*/
#define     PLL_MULT_FACTOR     192    


#endif
