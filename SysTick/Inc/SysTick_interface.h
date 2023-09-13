/*********************************************************************************/
/*	Module		: SysTick
 *	File name	: SysTick_interface.h
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 13/09/2023
*********************************************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

/*	SysTick Interval modes	*/
#define	MULTI_SHOT_TIMER			0
#define SINGLE_SHOT_TIMER			1

/*	SysTick	source clock options	*/
#define STK_SOURCE_CLK_AHB			0
#define STK_SOURCE_CLK_AHB_8		1

/*	Function prototypes	*/
void STK_voidInit(void);

void STK_voidSetDelay(uint32 Copy_u32Ticks);
void STK_voidSetIntervalSingleShot(uint32 Copy_u32Ticks, void(*Func_ptr)(void));
void STK_voidSetIntervalMultiShot(uint32 Copy_u32Ticks, void(*Func_ptr)(void));
void STK_voidGetElapsedTime(uint32* Ptr_u32ElapsedTime);
void STK_voidStopSingleShot(void);

#endif /* SYSTICK_INTERFACE_H_ */
