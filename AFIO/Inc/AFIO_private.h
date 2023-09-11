/*********************************************************************************/
/*	Module		: AFIO
 *	File name	: AFIO_private.h
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 09/09/2023
*********************************************************************************/
#include "STD_TYPES.h"

#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

/*		AFIO BASE ADRESS and REGISTER MAP		*/
#define AFIO_BASE_ADDRESS		0x40010000
#define AFIO					( (volatile AFIO_t*) AFIO_BASE_ADDRESS)

typedef struct
{
	volatile uint32 EVCR;
	volatile uint32 MAPR;
	volatile uint32 EXTICR[4];
	volatile uint32 MAPR2;
}AFIO_t;

#endif /* AFIO_PRIVATE_H_ */
