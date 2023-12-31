/*********************************************************************************/
/*	Module		: EXTI
 *	File name	: EXTI_private.h
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 09/09/2023
*********************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*******************   BASE Addresses    *********************/
#define EXTI_BASE_ADDRESS	0x40010400
#define EXTI				( (volatile EXTI_t *) EXTI_BASE_ADDRESS )

/*********	EXTI registers	***********/
typedef struct
{
	volatile uint32 IMR;
	volatile uint32 EMR;
	volatile uint32 RTSR;
	volatile uint32 FTSR;
	volatile uint32 SWIER;
	volatile uint32 PR;
}EXTI_t;


#endif /* EXTI_PRIVATE_H_ */
