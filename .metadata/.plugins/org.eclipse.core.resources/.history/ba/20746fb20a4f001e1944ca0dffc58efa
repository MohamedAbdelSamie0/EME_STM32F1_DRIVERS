/*********************************************************************************/
/*	Module		: EXTI
 *	File name	: EXTI_interface.h
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 09/09/2023
*********************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*	EXTI MODES	*/
#define RISING_EDGE		0
#define FALLING_EDGE	1
#define RISING_FALLING	2

/*******************   EXTI lines     ***************************/
typedef enum
{
	EXTI_LINE0 = 0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15
}EXTI_line_t;

/*********	Function Prototypes	********/
void EXTI_voidInit(void);
void EXTI_voidEnableEXTI(EXTI_line_t EXTILine_n, uint8 Copy_u8EXTImode);
void EXTI_voidDisableEXTI(EXTI_line_t EXTILine_n);
void EXTI_voidSoftwareTrigger(EXTI_line_t EXTILine_n);

void EXTI_voidSetCallBack(EXTI_line_t EXTILine_n, void (*func_ptr)(void));

#endif /* EXTI_INTERFACE_H_ */
