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
| ~ v2.0        09 May, 2023                      MGPIO_voidOutputSetSpecifcValue|
|                                                 MGPIO_voidSetPortSpecifcMode   |
|________________________________________________________________________________|
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidInit(void)
{
    /*Enable All GPIO*/
        /*Initialize System Clock*/
        MRCC_voidInit();
        /*Enable GPIOA*/
        MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_EN);
        /*Enable GPIOB*/
        MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOB_EN);
        /*Enable GPIOC*/
        MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOC_EN);
}


void MGPIO_voidSetPinDirection(u8 Copy_u8GPIOPort, u8 Copy_u8GPIOPin, u8 Copy_u8GPIODirection)
{
    /*Direction:
      INPUT   = 00
      OUTPUT  = 01
      AF      = 10
      ANALOG  = 11
    */

   /*
     To access The 'REQUIRED TWO BITS' , follow this equation:
     For Pin  "P" , Configuer -> 2*P , (2*P)+1
     Ex : PIN5    , BITS = 2*5 , (2*5)+1  -->> 10,11
    */
    switch (Copy_u8GPIOPort)
    {
    case GPIO_PORTA:
    
        switch (Copy_u8GPIODirection)
        {
        case INPUT:
        /*00*/
        CLR_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;
       case OUTPUT:
       /*01*/ 
        SET_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;
       case AF:
       /*10*/ 
        CLR_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;
       case ANALOG:
       /*11*/ 
        SET_BIT( GPIOA -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOA -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }

        break;

   
    case GPIO_PORTB:
    
        switch (Copy_u8GPIODirection)
        {
        case INPUT:
        CLR_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 

       case OUTPUT: 
        SET_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 

       case AF: 
        CLR_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 

       case ANALOG: 
        SET_BIT( GPIOB -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOB -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }
        break;
        
    /*P13,P14,P15 ONLY*/
    case GPIO_PORTC:
    
        switch (Copy_u8GPIODirection)
        {
        case INPUT:
        CLR_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case OUTPUT: 
        SET_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case AF: 
        CLR_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break; 
             
       case ANALOG: 
        SET_BIT( GPIOC -> MODER , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOC -> MODER , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }
        break;
        
    
    default:
    /*Return Error*/
        break;
    }

}
void MGPIO_voidOutputConnectionType(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin ,u8 Copy_u8GPIOOutputConnectionType )
{
    /*
    Connection Type:
      PushPull  = 0
      OpenDrain = 1
    */
   
   switch (Copy_u8GPIOPort)
    {
    case GPIO_PORTA:
    
        switch (Copy_u8GPIOOutputConnectionType)
        {
            case PUSH_PULL:
            CLR_BIT( GPIOA -> OTYPER , Copy_u8GPIOPin );
            break;

            case OPEN_DRAIN:
            SET_BIT( GPIOA -> OTYPER , Copy_u8GPIOPin );
            break;
            default:
            /*Return Error*/
            break;
        }
    break;
    case GPIO_PORTB:
    
        switch (Copy_u8GPIOOutputConnectionType)
        {
            case PUSH_PULL:
            CLR_BIT( GPIOB -> OTYPER , Copy_u8GPIOPin );
            break;

            case OPEN_DRAIN:
            SET_BIT( GPIOB -> OTYPER , Copy_u8GPIOPin );
            break;
            default:
            /*Return Error*/
            break;
        }
    break;
    
    case GPIO_PORTC:
    
        switch (Copy_u8GPIOOutputConnectionType)
        {
            case PUSH_PULL:
            CLR_BIT( GPIOC -> OTYPER , Copy_u8GPIOPin );
            break;

            case OPEN_DRAIN:
            SET_BIT( GPIOC -> OTYPER , Copy_u8GPIOPin );
            break;
            default:
            /*Return Error*/
            break;
        }
    break;
    
     default:
     /*Return Error*/
     break;
    }

}

void MGPIO_voidOutputSpeed(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin ,u8 Copy_u8GPIOSpeed )
{
    /*Speed:
    LOW     =    00
    MEDIUM  =    01
    FAST    =    10
    HIGH    =    11
    */
    switch (Copy_u8GPIOPort)
    {
    case GPIO_PORTA:
    
        switch (Copy_u8GPIOSpeed)
        {
        case LOW_SPEED:
        /*00*/
        CLR_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break;
       case MEDIUM_SPEED:
       /*01*/ 
        SET_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break;
       case FAST_SPEED:
       /*10*/ 
        CLR_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break;
       case HIGH_SPEED:
       /*11*/ 
        SET_BIT( GPIOA -> OSPEEDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOA -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }
    break;

   
    case GPIO_PORTB:
    
        switch (Copy_u8GPIOSpeed)
        {
        case LOW_SPEED:
        CLR_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break; 

       case MEDIUM_SPEED: 
        SET_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break; 

       case FAST_SPEED: 
        CLR_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break; 

       case HIGH_SPEED: 
        SET_BIT( GPIOB -> OSPEEDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOB -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }

    break;
        
  
    case GPIO_PORTC:
    
        switch (Copy_u8GPIOSpeed)
        {
        case LOW_SPEED:
        CLR_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case MEDIUM_SPEED: 
        SET_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case FAST_SPEED: 
        CLR_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break; 
             
       case HIGH_SPEED: 
        SET_BIT( GPIOC -> OSPEEDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOC -> OSPEEDR , ((2*Copy_u8GPIOPin)+1));
            break;

        default:
        /*Return Error*/
            break;
        }
    break;
        
    
    default:
    /*Return Error*/
        break;
    }

}

void MGPIO_voidOutputSetPinValue(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOValue )
{
    /*
    Output Value:
      LOW  (  0v  )   =   0
      HIGH ( 3.3v )   =   1
    */  
   
   switch (Copy_u8GPIOPort)
    {
    case GPIO_PORTA:
    
        switch (Copy_u8GPIOValue)
        {
            case LOW:
            CLR_BIT( GPIOA -> ODR , Copy_u8GPIOPin );
            break;

            case HIGH:
            SET_BIT( GPIOA -> ODR , Copy_u8GPIOPin );
            break;
            default:
            /*Return Error*/
            break;
        }
    break;

    case GPIO_PORTB:
    
        switch (Copy_u8GPIOValue)
        {
            case LOW:
            CLR_BIT( GPIOB -> ODR , Copy_u8GPIOPin );
            break;

            case HIGH:
            SET_BIT( GPIOB -> ODR , Copy_u8GPIOPin );
            break;
            default:
            /*Return Error*/
            break;
        }
    break;

    case GPIO_PORTC:
    
        switch (Copy_u8GPIOValue)
        {
            case LOW:
            CLR_BIT( GPIOC -> ODR , Copy_u8GPIOPin );
            break;

            case HIGH:
            SET_BIT( GPIOC -> ODR , Copy_u8GPIOPin );
            break;
            default:
            /*Return Error*/
            break;
        }
    break;
    
     default:
     /*Return Error*/
     break;
    }

}

void MGPIO_voidInputPULLUP_PULLDOWN(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin , u8 Copy_u8GPIOPullType )
{
    /*
    NONE     =  00
    PULLUP   =  01
    PULLDOWN =  10
    RESERVED =  11
    */

    switch (Copy_u8GPIOPort)
    {
    case GPIO_PORTA:
    
        switch (Copy_u8GPIOPullType)
        {
        case NO_PULLUP_NO_PULLDOWN:
        /*00*/
        CLR_BIT( GPIOA -> PUPDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOA -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break;
       case PULLUP:
       /*01*/ 
        SET_BIT( GPIOA -> PUPDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOA -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break;
       case PULLDOWN:
       /*10*/ 
        CLR_BIT( GPIOA -> PUPDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOA -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break;
       case RESERVED:
        /*Reserved Error*/
            break;

        default:
        /*Return Error*/
            break;
        }
        break;

   
    case GPIO_PORTB:
    
        switch (Copy_u8GPIOPullType)
        {
        case NO_PULLUP_NO_PULLDOWN:
        CLR_BIT( GPIOB -> PUPDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOB -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break; 

       case PULLUP: 
        SET_BIT( GPIOB -> PUPDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOB -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break; 

       case PULLDOWN: 
        CLR_BIT( GPIOB -> PUPDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOB -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break; 

       case RESERVED: 
        /*Reserved Error*/
            break;

        default:
        /*Return Error*/
            break;
        }
    break;
        
  
    case GPIO_PORTC:
    
        switch (Copy_u8GPIOPullType)
        {
        case NO_PULLUP_NO_PULLDOWN:
        CLR_BIT( GPIOC -> PUPDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOC -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case PULLUP: 
        SET_BIT( GPIOC -> PUPDR , (2*Copy_u8GPIOPin));
        CLR_BIT( GPIOC -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break; 
 
       case PULLDOWN: 
        CLR_BIT( GPIOC -> PUPDR , (2*Copy_u8GPIOPin));
        SET_BIT( GPIOC -> PUPDR , ((2*Copy_u8GPIOPin)+1));
            break; 
             
       case RESERVED: 
        /*Reserved Error*/
            break;

        default:
        /*Return Error*/
            break;
        }

    break;
        
    
    default:
    /*Return Error*/
        break;
    }

}


u8 MGPIO_voidInputGetPin(u8 Copy_u8GPIOPort , u8 Copy_u8GPIOPin )
{
    /*PIN In AVR*/
    /*
    Get Input Value:
      LOW    =   0
      HIGH   =   1
    */
   
   switch (Copy_u8GPIOPort)
    {
    case GPIO_PORTA:
        return GET_BIT(GPIOA -> IDR , Copy_u8GPIOPin);
        break;

    case GPIO_PORTB:
        return GET_BIT(GPIOB -> IDR , Copy_u8GPIOPin);
        break;

    case GPIO_PORTC:
        return GET_BIT(GPIOC -> IDR , Copy_u8GPIOPin);
        break;

    default:
     /*Return Error*/
    	return 0;
     break;
    }

}
///////////////////////////////////
void MGPIO_voidOutputSetSpecifcValue(u8 Copy_u8GPIOPort , u16 Copy_u8GPIOSpecificValue )
{


   switch (Copy_u8GPIOPort)
    {
    case GPIO_PORTA:
    	(GPIOA -> ODR = Copy_u8GPIOSpecificValue);
    break;
    case GPIO_PORTB:
    	(GPIOB -> ODR = Copy_u8GPIOSpecificValue);
    break;
    case GPIO_PORTC:
    	(GPIOC -> ODR = Copy_u8GPIOSpecificValue);
    break;
     default:
     /*Return Error*/
     break;

    }
}

void MGPIO_voidSetPortSpecifcMode(u8 Copy_u8GPIOPort , u32 Copy_u8GPIOSpecificValue )
{

		/*Choose:
		 * OUTPUT_ALL	0x5555 5555
		 * INPUT_ALL	0x0000 0000
		 * AF_ALL		0xAAAA AAAA
		 * ANALOG_ALL	0xFFFF FFFF
		 * */

      switch (Copy_u8GPIOPort)
       {
       case GPIO_PORTA:
       	(GPIOA -> MODER = Copy_u8GPIOSpecificValue);
       break;
       case GPIO_PORTB:
       	(GPIOB -> MODER = Copy_u8GPIOSpecificValue);
       break;
       case GPIO_PORTC:
       	(GPIOC -> MODER = Copy_u8GPIOSpecificValue);
       break;
        default:
        /*Return Error*/
        break;
       }

}




