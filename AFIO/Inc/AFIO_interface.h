/*********************************************************************************/
/*	Module		: AFIO
 *	File name	: AFIO_interface.h
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 09/09/2023
*********************************************************************************/
#include "STD_TYPES.h"

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

typedef enum
{
	SPI1_REMAP = 0,
	I2C1_REMAP,
	USART1_REMAP,
	USART2_REMAP,
	USART3_REMAP,
	TIM1_REMAP = 6,
	TIM2_REMAP = 8,
	TIM3_REMAP = 10,
	TIM4_REMAP = 12,
	CAN_REMAP,
	PD01_REMAP = 15,
	TIM5CH4_IREMAP,
	ADC1_ETRGINJ_REMAP,
	ADC1_ETRGREG_REMAP,
	ADC2_ETRGINJ_REMAP,
	ADC2_ETRGREG_REMAP,
	SWJ_CFG = 26,
}Memory_remaping_t;

/*******	Function prototypes	******/
void AFIO_voidSetEXTIConfiguration(uint8 Copy_u8EXTI_Line, uint8 Copy_u8Port);
void AFIO_voidRemapPeripheralPins(uint8 Copy_u8Port);

#endif /* AFIO_INTERFACE_H_ */
