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
| ~ v1.0        23 May, 2023    Hesham Abdallah NourEldeen    Initial Creation   |
|________________________________________________________________________________|
|                                                                                |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#include "BIT_MATH.H"
#include "STD_TYPES.H"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"


#include "IR_interface.h"

/*First Edge*/
static u8 Global_u8StartEdgeFlag = 0;

/*Time between every two falling edges*/
static u32 Global_u32ReceivedFrame[50] = {0};

/*Carry Decimal Number*/
static u8 Global_u8ButtonData = 0;

/*Edge Number*/
static u8 Global_u8EdgeCounter = 0;


void HIR_voidInit(void)
{
	/*RCC Init*/
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);

	/*Configure PA0*/
	MGPIO_voidSetPinDirection	   (GPIO_PORTA,PIN0,INPUT);
	MGPIO_voidInputPULLUP_PULLDOWN (GPIO_PORTA,PIN0,PULLUP);


	/*Configure PA1*/
	MGPIO_voidSetPinDirection	   (GPIO_PORTA,PIN1,OUTPUT);
	/*Configure PA2*/
	MGPIO_voidSetPinDirection	   (GPIO_PORTA,PIN2,OUTPUT);
	/*Configure PA3*/
	MGPIO_voidSetPinDirection	   (GPIO_PORTA,PIN3,OUTPUT);


	/*Init STK*/
	/*On But not counting cuz load = 0 */
	MSTK_voidinit();


	/*EXTI Init*/
	MEXTI_voidInit();
	/*Falling*/
	MEXTI_voidChangeSenseMode(MEXTI_LINE0 , MEXTI_FALLING_EDGE);
	/*Pass The Function*/
	MEXTI_voidSetCallBack(MEXTI_LINE0 , &HIR_voidGetFrame);
	/*Enable Interrupt*/
	MEXTI_voidEnableInterrupt(MEXTI_LINE0);


	/*NVIC Init*/
	MNVIC_voidInit();
	/*Enable EXT0 Interrupt*/
	MNVIC_voidEnablePeripheralInterrupt(6);
}

void HIR_voidGetFrame(void)
{
	if(Global_u8StartEdgeFlag == 0)
	{
		/*Set timer with Total FrameTime*/
		MSTK_voidSetSingleInterval(60000,&HIR_voidTakeAction);

		Global_u8StartEdgeFlag = 1;
	}
	else
	{	/*Get the counted TIME*/
		Global_u32ReceivedFrame[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		/*Reset Timer*/
		MSTK_voidResetSYSTICK();
		/*Set PreLoad Value*/
		MSTK_voidSetSingleInterval(60000,&HIR_voidTakeAction);
		/*Inc Edge Counter*/
		Global_u8EdgeCounter++;


	}
}

void HIR_voidTakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8 ; Local_u8LoopCounter ++)
	{
		/*Data From 17 to 24*/
		if ((Global_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
				(Global_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
		{
			/*Zero*/
			CLR_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}

		else
		{	/*One*/
			SET_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}
	}
	/*Prepare new frame*/
	Global_u8StartEdgeFlag = 0;
	Global_u8EdgeCounter = 0;
}

void HIR_voidPlay(void)
{
	switch(Global_u8ButtonData)
	{

	  case 22://0
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,HIGH);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,LOW);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,LOW);
	  	break;
	  case 12://1
	    MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,LOW);
	    MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,HIGH);
	    MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,LOW);
	  	break;
	  case 24://2
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,LOW);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,LOW);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,HIGH);
	  	break;
	  case 94://3
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,HIGH);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,HIGH);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,LOW);
	  	break;
	  case 8://4
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,HIGH);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,LOW);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,HIGH);
	  	break;
	  case 28://5
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,LOW);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,HIGH);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,HIGH);
	  	break;
	  case 90://6
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,HIGH);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,HIGH);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,HIGH);
	  	break;
	  case 69://ON-OFF
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN1,LOW);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN2,LOW);
	  	MGPIO_voidOutputSetPinValue(GPIO_PORTA,PIN3,LOW);
	  	break;
	}
}


