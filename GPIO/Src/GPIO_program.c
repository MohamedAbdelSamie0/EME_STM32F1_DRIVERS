/*********************************************************************************/
/*	Module		: GPIO
 *	File name	: GPIO_program.c
 *
 * 	Author    	: Mohamed Abdelsamie
 * 	Date      	: 08/09/2023
*********************************************************************************/

#include "GPIO_private.h"
#include "GPIO_interface.h"

/*	name:		GPIO_voidSetPinDirection
 * description: Function to set pin direction
 * reentrant:	Reentrant function
 * input:		port, pin, mode(input or output modes)
 * output:		none
 */
void  GPIO_voidSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Mode)
{
	if(Copy_u8Port < 3)
	{
		switch (Copy_u8Port)
		    {
		         /*** PORT A ***/
		        case GPIO_A:
		            if (Copy_u8Pin <= 7)
		            {	/*	port configuration low register	*/
		                GPIO_A_PORT->CRL &= ~((0b1111) << (Copy_u8Pin * 4));
		                GPIO_A_PORT->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
		            }
		            else if (Copy_u8Pin <= 15)
		            {	/*	port configuration high register	*/
		                GPIO_A_PORT->CRH &= ~((0b1111)      << ((Copy_u8Pin - 8) * 4));
		                GPIO_A_PORT->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
		            }
		            break;

		        /*** PORT B ***/
		        case GPIO_B:
		            if (Copy_u8Pin <= 7)
		            {	/*	port configuration low register	*/
		                GPIO_B_PORT->CRL &= ~((0b1111)      << (Copy_u8Pin * 4));
		                GPIO_B_PORT->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
		            }
		            else if (Copy_u8Pin <= 15)
		            {	/*	port configuration high register	*/
		                GPIO_B_PORT->CRH &= ~((0b1111)      << ((Copy_u8Pin - 8) * 4));
		                GPIO_B_PORT->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
		            }
		            break;

		        /*** PORT C ***/
		        case GPIO_C:
		            if (Copy_u8Pin <= 7)
		            {	/*	port configuration low register	*/
		                GPIO_C_PORT->CRL &= ~((0b1111)      << (Copy_u8Pin * 4));
		                GPIO_C_PORT->CRL |=  ((Copy_u8Mode) << (Copy_u8Pin * 4));
		            }
		            else if (Copy_u8Pin <= 15)
		            {	/*	port configuration high register	*/
		                GPIO_C_PORT->CRH &= ~((0b1111)      << ((Copy_u8Pin - 8) * 4));
		                GPIO_C_PORT->CRH |=  ((Copy_u8Mode) << ((Copy_u8Pin - 8) * 4));
		            }
		            break;
		        default:
		        	break;
		    }
	}
	else
	    {
	        /* DO NOTHING; ERROR handling */
	    }
}

/*	name:		GPIO_voidSetPinValue
 * description: Function to set pin value
 * reentrant:	Reentrant function
 * input:		port, pin, value(HIGH OR LOW)
 * output:		none
 */
void  GPIO_voidSetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value)
{
	if(Copy_u8Port < 3)
	{
		switch (Copy_u8Port)
		{
			 /*** PORT A ***/
			case GPIO_A:
				if (Copy_u8Value == HIGH)
				{	/*	USE SET AND RESET REGISTER FOR SET	*/
					SET_BIT (GPIO_A_PORT->BSRR, Copy_u8Pin);
				}
				else if (Copy_u8Value == LOW)
				{	/*	USE RESET REGISTER FOR CLEAR	*/
					SET_BIT (GPIO_A_PORT->BRR, Copy_u8Pin);
				}
				break;

			/*** PORT B ***/
			case GPIO_B:
				if (Copy_u8Value == HIGH)
				{	/*	USE SET AND RESET REGISTER FOR SET	*/
					SET_BIT (GPIO_B_PORT->BSRR, Copy_u8Pin);
				}
				else if (Copy_u8Value == LOW)
				{	/*	USE RESET REGISTER FOR CLEAR	*/
					SET_BIT (GPIO_B_PORT->BRR, Copy_u8Pin);
				}
				break;

			/*** PORT C ***/
			case GPIO_C:
				if (Copy_u8Value == HIGH)
				{	/*	USE SET AND RESET REGISTER FOR SET	*/
					SET_BIT (GPIO_C_PORT->BSRR, Copy_u8Pin);
				}
				else if (Copy_u8Value == LOW)
				{	/*	USE RESET REGISTER FOR CLEAR	*/
					SET_BIT (GPIO_C_PORT->BRR, Copy_u8Pin);
				}
				break;

			default :
				break;
		}
	}
	else
	    {
	        /* DO NOTHING; ERROR handling */
	    }
}

/*	name:		GPIO_u8GetPinValue
 * description: Function to read the pin value
 * reentrant:	Reentrant function
 * input:		port, pin
 * output:		uint8 pin_value
 */
uint8 GPIO_u8GetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{
    uint8 LOC_u8Result = 0;
    if(Copy_u8Port < 3)
    {
		switch (Copy_u8Port)
		{
			 /*** PORT A ***/
			case GPIO_A:
				LOC_u8Result = GET_BIT (GPIO_A_PORT->IDR, Copy_u8Pin);
				break;

			/*** PORT B ***/
			case GPIO_B:
				LOC_u8Result = GET_BIT (GPIO_B_PORT->IDR, Copy_u8Pin);
				break;

			/*** PORT C ***/
			case GPIO_C:
				LOC_u8Result = GET_BIT (GPIO_C_PORT->IDR, Copy_u8Pin);
				break;

			default :
				break;
		}
    return LOC_u8Result;
    }
    else
        {
            /* ERROR handling */
    	return 0xFF;	/*	value to indicate error	*/
        }
}

/*	name:		GPIO_voidTogglePinValue
 * description: Function to toggle the pins
 * reentrant:	Reentrant function
 * input:		port, pin
 * output:		None
 */
void  GPIO_voidTogglePinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{
	if(Copy_u8Port < 3)
	{
		switch (Copy_u8Port)
		{
			 /*** PORT A ***/
			case GPIO_A:
						TOG_BIT(GPIO_A_PORT->ODR,Copy_u8Pin);
			  break;

			/*** PORT B ***/
			case GPIO_B:
						TOG_BIT(GPIO_B_PORT->ODR,Copy_u8Pin);
			  break;

			/*** PORT C ***/
			case GPIO_C:
			  TOG_BIT(GPIO_C_PORT->ODR,Copy_u8Pin);
			  break;

			default :
				break;
		}
	}
	else
	{
		/* DO NOTHING; ERROR handling */
	}
}

/*	name:		GPIO_voidSetPinPull
 * description: Function to set pin resistor configuration
 * reentrant:	Reentrant function
 * input:		port, pin, resistor_mode(PULL_UP or PULL_DOWN)
 * output:		None
 */
void  GPIO_voidSetPinPull(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Pull)
{
	if(Copy_u8Port < 3)
	{
		switch (Copy_u8Port)
		{
			 /*** PORT A ***/
			case GPIO_A:
				if (Copy_u8Pull == PULL_UP)
				{
					SET_BIT (GPIO_A_PORT->ODR, Copy_u8Pin);
				}
				else if (Copy_u8Pull == PULL_DOWN)
				{
					CLR_BIT (GPIO_A_PORT->ODR, Copy_u8Pin);
				}
				break;

			/*** PORT B ***/
			case GPIO_B:
				if (Copy_u8Pull == PULL_UP)
				{
					SET_BIT (GPIO_B_PORT->ODR, Copy_u8Pin);
				}
				else if (Copy_u8Pull == PULL_DOWN)
				{
					CLR_BIT (GPIO_B_PORT->ODR, Copy_u8Pin);
				}
				break;

			/*** PORT C ***/
			case GPIO_C:
				if (Copy_u8Pull == PULL_UP)
				{
					SET_BIT (GPIO_C_PORT->ODR, Copy_u8Pin);
				}
				else if (Copy_u8Pull == PULL_DOWN)
				{
					CLR_BIT (GPIO_C_PORT->ODR, Copy_u8Pin);
				}
				break;

			default :
				break;
		}
	}
	else
	{
		/* DO NOTHING; ERROR handling */
	}
}

/*	name:		GPIO_u8LockPinConfiguration
 * description: Function to lock configuration of a pin till next reset
 * reentrant:	Non-reentrant function
 * input:		port, pin
 * output:		Lock success or fail
 */
uint8 GPIO_u8LockPinConfiguration(uint8 Copy_u8Port, uint8 Copy_u8Pin)
{
	uint8 Local_u8LockState = LOCK_FAIL;

	if(Copy_u8Port < 3)
		{
			switch (Copy_u8Port)
			{
				 /*** PORT A ***/
				case GPIO_A:
					if(Copy_u8Pin < LOCK_BIT)
					{
						SET_BIT(GPIO_A_PORT-> LCKR, Copy_u8Pin);
						/*	start locking sequence on bit 16	*/
						SET_BIT(GPIO_A_PORT-> LCKR, LOCK_BIT);
						CLR_BIT(GPIO_A_PORT-> LCKR, LOCK_BIT);
						SET_BIT(GPIO_A_PORT-> LCKR, LOCK_BIT);
						Local_u8LockState = GET_BIT(GPIO_A_PORT-> LCKR, LOCK_BIT);
						if(GET_BIT(GPIO_A_PORT-> LCKR, LOCK_BIT) == 1)
						{
							Local_u8LockState = LOCK_SUCCES;
						}
					}
					break;

				/*** PORT B ***/
				case GPIO_B:
					if(Copy_u8Pin < LOCK_BIT)
					{
						/*	start locking sequence on bit 16	*/
						SET_BIT(GPIO_B_PORT-> LCKR, LOCK_BIT);
						CLR_BIT(GPIO_B_PORT-> LCKR, LOCK_BIT);
						SET_BIT(GPIO_B_PORT-> LCKR, LOCK_BIT);
						Local_u8LockState = GET_BIT(GPIO_B_PORT-> LCKR, LOCK_BIT);
						if(GET_BIT(GPIO_B_PORT-> LCKR, LOCK_BIT) == 1)
						{
							Local_u8LockState = LOCK_SUCCES;
						}
					}
					break;

				/*** PORT C ***/
				case GPIO_C:
					if(Copy_u8Pin < LOCK_BIT)
					{
						/*	start locking sequence on bit 16	*/
						SET_BIT(GPIO_C_PORT-> LCKR, LOCK_BIT);
						CLR_BIT(GPIO_C_PORT-> LCKR, LOCK_BIT);
						SET_BIT(GPIO_C_PORT-> LCKR, LOCK_BIT);
						Local_u8LockState = GET_BIT(GPIO_C_PORT-> LCKR, LOCK_BIT);
						if(GET_BIT(GPIO_C_PORT-> LCKR, LOCK_BIT) == 1)
						{
							Local_u8LockState = LOCK_SUCCES;
						}
					}
					break;

				default :
					break;
			}
		}
		else
		{
			/* DO NOTHING; ERROR handling */
		}
	return Local_u8LockState;
}

