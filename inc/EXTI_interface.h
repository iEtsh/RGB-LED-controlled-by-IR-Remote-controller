/*
 * EXTI_INTERFACE.h
 *
 *  Created on: May 21, 2023
 *      Author: ihesh
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


void MEXTI_voidInit(void);

void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine);

void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine);

void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal);

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void));



#define MEXTI_RISING_EDGE 	                  0
#define MEXTI_FALLING_EDGE 	                  1
#define MEXTI_ON_CHANGE 	                  2


/*16 Lines*/
#define MEXTI_LINE0 0



#endif /* EXTI_INTERFACE_H_ */
