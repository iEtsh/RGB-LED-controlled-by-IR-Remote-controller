/*
 * EXTI_private.h
 *
 *  Created on: May 21, 2023
 *      Author: ihesh
 */

#include "BIT_MATH.H"
#include "STD_TYPES.H"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*pvCallBack[16])(void) ={NULL};

void MEXTI_voidInit(void)
{

}

void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine)
{
	/*Enable Chosen Peripheral*/
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
	SET_BIT(MEXTI->IMR,Copy_u8EXTILine);
}

void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine)
{
	/*Disable Chosen Peripheral*/
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
	CLR_BIT(MEXTI->IMR,Copy_u8EXTILine);
}




void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal)
{
	switch(Copy_u8SenseSignal)
		{
		case MEXTI_RISING_EDGE:
			/*Clear First*/
			CLR_BIT(MEXTI-> FTSR , Copy_u8EXTILine );	//Clear Falling Edge Sense Mode
			SET_BIT(MEXTI-> RTSR , Copy_u8EXTILine );   //Set Rising Edge Sense Mode
			break;
		case MEXTI_FALLING_EDGE:
			/*Clear First*/
			CLR_BIT(MEXTI-> RTSR , Copy_u8EXTILine );	//Clear Rising Edge Sense Mode
			SET_BIT(MEXTI-> FTSR , Copy_u8EXTILine );   //Set Falling Edge Sense Mode
			break;
		case MEXTI_ON_CHANGE:
			/*Does not matter*/
			SET_BIT(MEXTI-> FTSR , Copy_u8EXTILine );	//Set Rising Edge Sense Mode
			SET_BIT(MEXTI-> RTSR , Copy_u8EXTILine );	//Set Falling Edge Sense Mode
			break;
		default:
			break;
		}
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void))
{
	pvCallBack[Copy_u8EXTILine] = pvNotificationFunction;
}

/*EXTERNAL*/
/*MODULENAME _ InterruptRequestHandler*/

/*INTERNAL*/
/*ModuleName_Handler*/

void EXTI0_IRQHandler(void)
{
	if (pvCallBack[0] != NULL)
	{
		pvCallBack[0]();

	}
	SET_BIT(MEXTI->PR,0);
}



