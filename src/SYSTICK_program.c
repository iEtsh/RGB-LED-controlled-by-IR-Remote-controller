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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"


static void (*pvCallBackFunction)(void) = NULL;
static u8   u8IntervalFlag = SINGLE_INTERVAL_FLAG;

void MSTK_voidinit               (void)
{

	/*Initiate Source Mode*/
	 #if     STK_CLK_SOURCE   ==  AHB_DIV_8
	 CLR_BIT(SYSTICK->CTRL,2);

	 #elif   STK_CLK_SOURCE   ==  AHB_DIV_1
	 SET_BIT(SYSTICK->CTRL,2);

	 #else
	 #error "MSYSTICK_CLK_SOURCE Configuration Error"
 	 #endif

	 /*Initiate Interrupt Mode*/
	 #if     STK_INTERRUPT_ENABLE   ==   ENABLE
	 SET_BIT(SYSTICK->CTRL,1);

	#elif   STK_INTERRUPT_ENABLE   ==   DISABLE
	 CLR_BIT(SYSTICK->CTRL,1);

	 #else
	 #error "MSYSTICK_INTERRUPT Configuration Error"
	 #endif



    /*Initiate Enable Mode*/
    #if     STK_ENABLE   ==   ENABLE
    SET_BIT(SYSTICK->CTRL,0);

    #elif   STK_ENABLE   ==   DISABLE
    CLR_BIT(SYSTICK->CTRL,0);

    #else
	#error "MSYSTICK_ENABLE Configuration Error"
    #endif





}

void MSTK_voidSetBusyWait (u32 Copy_u32TicksToWait)
{   
    /*Load Ticks Number in Micro*/
    SYSTICK->LOAD = Copy_u32TicksToWait;

    /*Polling Till Flag Rised*/

    while(GET_BIT(SYSTICK->CTRL,16)==0);

    /*Make sure*/
    SYSTICK->VAL=0;
}   

u32 MSTK_u32GetElapsedTime(void)
{
	/*Elapsed*/
	u32 local_u32ElapsedTime = (SYSTICK-> LOAD) - (SYSTICK-> VAL);
	return local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime(void)
{
	/*Remaining*/
	u32 local_u32RemainingTime =  SYSTICK-> VAL;
	return local_u32RemainingTime;
}

void MSTK_voidSetPreLoadValue(u32 Copy_u8LoadValue)
{
	SYSTICK -> LOAD = Copy_u8LoadValue;
}

void MSTK_voidResetSYSTICK(void)
{
	SYSTICK -> VAL = 0x00000000;
}

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks , void(*NotificationFunction)(void))
{
	/*Set PreLoad Value*/
	SYSTICK->LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
	u8IntervalFlag = SINGLE_INTERVAL_FLAG;

	/*Enable STK Interrupt*/
	SET_BIT(SYSTICK->CTRL ,1);
	/*Enable STK*/
	SET_BIT(SYSTICK->CTRL ,0);
}

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks , void(*NotificationFunction)(void))
{
	/*Set PreLoad Value*/
	SYSTICK->LOAD = Copy_u32Ticks;


	pvCallBackFunction = NotificationFunction;

	u8IntervalFlag = PERIODIC_INTERVAL_FLAG;

	/*Enable STK Interrupt*/
	SET_BIT(SYSTICK->CTRL ,1);
	/*Enable STK*/
	SET_BIT(SYSTICK->CTRL ,0);
}



void SysTick_Handler(void)
{
	u32 Local_u32TempVariable;

	if(u8IntervalFlag == SINGLE_INTERVAL_FLAG)
	{

		SYSTICK->LOAD = 0;

		SYSTICK->VAL = 0;

		CLR_BIT(SYSTICK->CTRL, 0);

	}

	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}

	Local_u32TempVariable = GET_BIT(SYSTICK->CTRL, 16);
}


