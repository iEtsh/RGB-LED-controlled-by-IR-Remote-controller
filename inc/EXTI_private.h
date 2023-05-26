/*
 * EXTI_private.h
 *
 *  Created on: May 21, 2023
 *      Author: ihesh
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_t;


#define 		MEXTI 		  ( ( volatile EXTI_t * ) 0x40013C00 )

/*0x40013800(baseaddress) + 0x08(offset) = 0x40013808(Reg address) */
#define 		SYS_CFG_CR1  *( ( volatile u32    * ) 0x40013808  )


#endif /* EXTI_PRIVATE_H_ */
