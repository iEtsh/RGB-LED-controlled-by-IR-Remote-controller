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
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIOA_EN 0
#define GPIOB_EN 1
#define GPIOC_EN 2

#define GPIO_PORTA              0
#define GPIO_PORTB              1
#define GPIO_PORTC              2
         
#define INPUT                   0
#define OUTPUT                  1
#define AF                      2
#define ANALOG                  3
         
         
#define PUSH_PULL               0
#define OPEN_DRAIN              1


#define LOW_SPEED               0
#define MEDIUM_SPEED            1
#define FAST_SPEED              2
#define HIGH_SPEED              3

#define NO_PULLUP_NO_PULLDOWN   0
#define PULLUP                  1
#define PULLDOWN                2
#define RESERVED                3

#define HIGH                    1
#define LOW                     0

#define PIN0                    0
#define PIN1                    1
#define PIN2                    2
#define PIN3                    3
#define PIN4                    4
#define PIN5                    5
#define PIN6                    6
#define PIN7                    7
#define PIN8                    8
#define PIN9                    9
#define PIN10                   10
#define PIN11                   11
#define PIN12                   12
#define PIN13                   13
#define PIN14                   14
#define PIN15                   15
#define PIN16                   16
#define PIN17                   17
#define PIN18                   18
#define PIN19                   19
#define PIN20                   20
#define PIN21                   21
#define PIN22                   22
#define PIN23                   23
#define PIN24                   24
#define PIN25                   25
#define PIN26                   26
#define PIN27                   27
#define PIN28                   28
#define PIN29                   29
#define PIN30                   30
#define PIN31                   31


#define INPUT_ALL         0x00000000
#define AF_ALL            0xAAAAAAAA
#define OUTPUT_ALL        0x55555555
#define ANALOG_ALL        0xFFFFFFFF



void MGPIO_voidInit                 (                                    void                                         );
void MGPIO_voidSetPinDirection      (   u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIODirection              );
void MGPIO_voidOutputConnectionType (   u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOOutputConnectionType   );
void MGPIO_voidOutputSpeed          (   u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOSpeed                  );
void MGPIO_voidOutputSetPinValue    (   u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOValue                  );
void MGPIO_voidInputPULLUP_PULLDOWN (   u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOPullType               );
u8   MGPIO_voidInputGetPin          (   u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin                                        );
void MGPIO_voidOutputSetSpecifcValue(   u8 Copy_u8GPIOPort , u16 Copy_u8GPIOSpecificValue 						      );
void MGPIO_voidSetPortSpecifcMode	(	u8 Copy_u8GPIOPort , u32 Copy_u8GPIOSpecificValue 							  );

#endif
