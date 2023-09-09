/*********************************************************************************/
/*	Module		: NVIC
 *	File name	: NVIC_program.c
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 09/09/2023
*********************************************************************************/

#include "NVIC_Cfg.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

void NVIC_voidSetGrouping(void)
{
	SCB-> AIRCR = GROUPING_PRIO_SUBGROUPING_PRIO;
}

void NVIC_voidEnableInterrupt(IRQn_t IRQn)
{
	if(IRQn >=0 && IRQn < 32)
	{
		SET_BIT(NVIC->ISER[0], IRQn);
	}
	else if(IRQn < 60)
	{
		SET_BIT(NVIC->ISER[1], IRQn);
	}
	else
	{
		/*	Do nothing; error handling	*/
	}
}

void NVIC_voidDisableInterrupt(IRQn_t IRQn)
{
	if(IRQn >=0 && IRQn < 32)
		{
			SET_BIT(NVIC->ICER[0], IRQn);
		}
		else if(IRQn < 60)
		{
			SET_BIT(NVIC->ICER[1], IRQn);
		}
		else
		{
			/*	Do nothing; error handling	*/
		}
}

uint8 NVIC_u8GetActiveFlag(IRQn_t IRQn)
{
	uint8 u8LocalFlag = 0;

	if(IRQn >=0 && IRQn < 32)
			{
				u8LocalFlag = GET_BIT(NVIC->IABR[0], IRQn);
			}
			else if(IRQn < 60)
			{
				u8LocalFlag = GET_BIT(NVIC->IABR[1], IRQn);
			}
			else
			{
				/*	Do nothing; error handling	*/
			}
	return u8LocalFlag;
}

void NVIC_voidSetPriority(IRQn_t IRQn, uint8 Copy_u8Group, uint8 Copy_u8SubGroup)
{
	uint8 u8LocalPriority = 0;

	if(IRQn >= 0 && IRQn < 60)
	{
			u8LocalPriority = Copy_u8SubGroup | (Copy_u8Group << (GROUPING_PRIO_SUBGROUPING_PRIO - GROUP_16_SUB_0) / 0x100);

			NVIC-> IP[IRQn] = u8LocalPriority << 4;
	}
	else
	{
		/*	do nothing; error handling	*/
	}
}
