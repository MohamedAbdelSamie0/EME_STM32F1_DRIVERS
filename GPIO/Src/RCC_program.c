/*********************************************************************************/
/*	Module		: RCC
 *	File name	: RCC_program.c
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 08/09/2023
*********************************************************************************/

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_Cfg.h"

/*	name:		RCC_voidInitSysClock
 * description: Function to select clock source
 * reentrant:	Non Reentrant function
 * input:		void
 * output:		void
 */
void RCC_voidInitSysClock(void)
{
    #if     RCC_CLOCK_TYPE == RCC_HSI
        CLR_BIT(RCC->CFGR,0);     /* HSI selected as system clock */
        CLR_BIT(RCC->CFGR,1);
    	SET_BIT(RCC->CR, 0);	   /* Enable HSI + Trimming = 0 */
    #elif   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        SET_BIT(RCC->CFGR,0);	  /* HSE selected as system clock */
        CLR_BIT(RCC->CFGR,1);
		CLR_BIT(RCC->CR, 18);	  /* Enable HSE with no bypass */
    	SET_BIT(RCC->CR, 16);
    #elif    RCC_CLOCK_TYPE == RCC_PLL
        /* PLL selected as system clock */
		CLR_BIT(RCC->CFGR,0);
		SET_BIT(RCC->CFGR,1);
        /* PLL MUL FECTOR */
		RCC->CFGR &= ~((0b1111) << 18);  	/* clear bits 18~21*/
		RCC->CFGR |= (RCC_PLL_MUL_VAL) << 18;  /* set pll multiplication factor*/
        #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			CLR_BIT(RCC->CFGR,0);     /* HSI selected as system clock */
			CLR_BIT(RCC->CFGR,1);
            CLR_BIT(RCC->CFGR, 16); 	/* Enable HSI + Trimming = 0 + ENABLE PLL*/

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
        /* Enable HSE with no bypass   */
    	    SET_BIT(RCC->CR, 16);
    	 /* 	HSE/2 selected		*/
    	    SET_BIT(RCC->CFGR,16);
    	    SET_BIT(RCC->CFGR,17);

        #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
        /* Enable HSE with no bypass   */
    	    SET_BIT(RCC->CR, 16);
    	/* 	HSE selected		*/
    	    SET_BIT(RCC->CFGR,16);
    	    CLR_BIT(RCC->CFGR,17);
        #endif // RCC_PLL_INPUT

		SET_BIT(RCC->CFGR,10); /*	divide APB1 clock by 2 for clock not to exceed 36MHZ	*/
		/* Enable PLL */
		SET_BIT(RCC->CR, 24);
		while(GET_BIT(RCC->CR,25)== 0){}
    #else
        #error("Wrong Clock configuration")
    #endif
}

/*	name:		RCC_voidEnableClock
 * description: Function to enable peripheral clock
 * reentrant:	Non Reentrant function
 * input:		BUS_id, peripheral_id
 * output:		void
 */
void RCC_voidEnableClock(uint8 Copy_u8BusId, uint16 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB  :
            	SET_BIT(RCC->AHBENR  ,Copy_u8PerId);
            	break;
            case RCC_APB1 :
            	SET_BIT(RCC->APB1ENR ,Copy_u8PerId);
            	break;
            case RCC_APB2 :
            	SET_BIT(RCC->APB2ENR ,Copy_u8PerId);
            	break;
            default	:
            	break;
        }
    }

    else
    {
        /* DO NOTHING; ERROR handling */
    }
}

/*	name:		RCC_voidDisableClock
 * description: Function to disable peripheral clock
 * reentrant:	Non Reentrant function
 * input:		BUS_id, peripheral_id
 * output:		void
 */
void RCC_voidDisableClock(uint8 Copy_u8BusId, uint8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB  :
            	CLR_BIT(RCC->AHBENR  ,Copy_u8PerId);
            	break;
            case RCC_APB1 :
            	CLR_BIT(RCC->APB1ENR ,Copy_u8PerId);
            	break;
            case RCC_APB2 :
            	CLR_BIT(RCC->APB2ENR ,Copy_u8PerId);
            	break;
            default	:
            	break;
        }
    }

    else
    {
        /* DO NOTHING; ERROR handling */
    }
}