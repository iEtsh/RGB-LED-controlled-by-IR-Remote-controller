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
|________________________________________________   ________________________________|
|                                                                                |
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


/*Choose Input Clock To Processor*/
void MRCC_voidInit(void)
{
#if CPU_CLK_SOURCE == HSI
    /*Enable HSI*/
    SET_BIT(RCC -> CR , 0);

    /*Select HSI as system clock (CPU Clk Source)*/
    CLR_BIT(RCC -> CFGR , 0);
    CLR_BIT(RCC -> CFGR , 1);

#elif CPU_CLK_SOURCE == HSE
    /*Check HSE Bypass*/
    #if HSE_CLK_SOURCE == OSCI
        CLR_BIT(RCC->CR,18);
    #elif HSE_CLK_SOURCE == RC
        SET_BIT(RCC->CR,18);
    #else
        #error "RCC HSE_CLK_SOURCE Configuration Error"
    #endif
    /*Enable HSE*/
    SET_BIT(RCC -> CR,16);
    /*Select HSE as System Clock (CPU CLK Source)*/
    SET_BIT(RCC -> CFGR , 0);
    CLR_BIT(RCC -> CFGR , 1);

#elif CPU_CLK_SOURCE == PLL

        #if PLL_SOURCE == HSI
            /*Enable HSI*/
            SET_BIT(RCC -> CR , 0);

        #elif PLL_SOURCE == HSE
            /*Enable HSE*/
            SET_BIT(RCC -> CR , 16);
        #else
            #error "RCC PLL_SOURCE Configuration Error"
        #endif

        /* Select HSI as PLL Source */
        RCC->PLLCFGR  &=  PLL_SCR_SEL_MSK;
        RCC->PLLCFGR  |=  (PLL_SCR_HSI     <<  PLLCFGR_PLLSRC);

        /* Set Division Factor */
        RCC->PLLCFGR  &=  PLL_DIV_FACTOR_MSK;
        RCC->PLLCFGR  |=  (PLL_DIV_FACTOR   <<  PLLCFGR_PLLP);

        /* Set Multiplication Factor */
        RCC->PLLCFGR  &=  PLL_MULT_FACTOR_MSK;
        RCC->PLLCFGR  |=  (PLL_MULT_FACTOR  <<  PLLCFGR_PLLN);

        /* Enable PLL */
        SET_BIT(RCC->CR,24);

        /* Select PLL as System Clock (CPU CLK SRC)*/
        RCC->CFGR  &=  CFGR_SYS_CLK_SEL_MSK;
        RCC->CFGR  |=  (CFGR_SYS_CLK_PLL<<CFGR_SW);

#else
        #error "RCC_CPU_CLK_SOURCE Configration Error"
    #endif
        //Set prescaller for AHB
        RCC->CFGR |= (AHB_PRESCALLER <<4);
}
/*Bus ABP1 , Bit 30 */
/*AHP2 , USB*/
/*AHP1 , GPIOA*/
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralId)
{
    switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1:
    SET_BIT(RCC -> AHB1ENR, Copy_u8PeripheralId);
    break;
    case RCC_AHB2:
    SET_BIT(RCC -> AHB2ENR, Copy_u8PeripheralId);
    break;
    case RCC_APB1:
    SET_BIT(RCC -> APB1ENR, Copy_u8PeripheralId);
    break;
    case RCC_APB2:
    SET_BIT(RCC -> APB2ENR, Copy_u8PeripheralId);
    break;
    
    default:
    //Return ERROR
        break;
    }


}

void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeripheralId)
{
    switch (Copy_u8PeripheralBus)
    {
    case RCC_AHB1:
    CLR_BIT(RCC -> AHB1ENR, Copy_u8PeripheralId);
    break;
    case RCC_AHB2:
    CLR_BIT(RCC -> AHB2ENR, Copy_u8PeripheralId);
    break;
    case RCC_APB1:
    CLR_BIT(RCC -> APB1ENR, Copy_u8PeripheralId);
    break;
    case RCC_APB2:
    CLR_BIT(RCC -> APB2ENR, Copy_u8PeripheralId);
    break;
    
    default:
    //Return ERROR
        break;
    }

}
