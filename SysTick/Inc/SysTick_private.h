/*********************************************************************************/
/*	Module		: SysTick
 *	File name	: SysTick_private.h
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 13/09/2023
*********************************************************************************/

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#include "STD_TYPES.h"

/*******************   BASE Address    *********************/
#define SysTick_BASE_ADDRESS		0xE000E010
#define SysTick						( (volatile SysTick_t*) SysTick_BASE_ADDRESS )

/*******************   SysTick Registers     ***********************/
typedef struct
{
	volatile uint32 CTRL;
	volatile uint32 LOAD;
	volatile uint32 VAL;
	volatile uint32 CALIB;
}SysTick_t;

#endif /* SYSTICK_PRIVATE_H_ */
