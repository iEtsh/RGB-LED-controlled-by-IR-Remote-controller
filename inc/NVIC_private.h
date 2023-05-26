/*
 * NVIC_private.h
 *
 *  Created on: May 21, 2023
 *      Author: ihesh
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

typedef struct
{
	volatile u32 ISER[8];
	volatile u32 reserved0[24]; // 100/u32=25 , -1 , 3shan e7na 3ayzeen el reserved bas
	volatile u32 ICER[8];
	volatile u32 reserved1[24];
	volatile u32 ISPR[8];
	volatile u32 reserved2[24];
	volatile u32 ICPR[8];
	volatile u32 reserved3[24];
	volatile u32 IABR[8];
	volatile u32 reserved4[56];
	volatile u8  IPR[240]; /*byte accessable*/ /*60 Register each one has 4 bytes */
	volatile u32 reserved5[580];
	volatile u8  STIR;
}NVIC_t;


#define 		MNVIC 		((volatile NVIC_t*)0xE000E100)
#define 		SCB_AIRCR  *((volatile u32*)0xE000ED0C)


/*Password value*/
#define 	AIRCR_PRIVATEKEY 		0x05FA

/*Group-Subs values*/
#define 	GRP_4_SUB_0_BITS		0b000
#define 	GRP_3_SUB_1_BITS		0b100
#define 	GRP_2_SUB_2_BITS		0b101
#define 	GRP_1_SUB_3_BITS		0b110
#define 	GRP_0_SUB_4_BITS		0b111



#endif /* NVIC_PRIVATE_H_ */
