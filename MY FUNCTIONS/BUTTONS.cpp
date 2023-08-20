/*
 * BUTTONS.cpp
 *
 *  Created on: 9 июл. 2023 г.
 *      Author: Sanchos
 */

#include "!!!CONFIG.hpp"
#include "BUTTONS.hpp"

// ******************************
// CONSTRUCTOR DEFINITION STARTS!
Buttons::Buttons(buttons_t my_buttons[BUTTONS_QTY])
{
// HERE IS PERYPHERY AUTOMATIC CONFIGURATION
/*user manually filled array with the buttons parameters, like GPIO port/pin, PU/PD, etc. is read. GPIO port is being configured
 * accordingly to the array content*/

	for(int i=0; i < BUTTONS_QTY; i++)
	{
		if(my_buttons[i].GPIO_PORT_NAME == GPIOA)
		{
			RCC->APB2ENR 	|= RCC_APB2ENR_IOPAEN;												// PORT B CLOCK ENABLE FOR GPIO PURPOSE

			// configure bits CNFx in registers CRH and CRL to configure GPIO ports as inputs.
			if(my_buttons[i].GPIO_PIN_NUMBER <=7 )
				{																				// FOR ADC CHANNELS <=7 USE CRL REGISTER
				GPIOA->CRL &= ~(0b11 << (((my_buttons[i].GPIO_PIN_NUMBER - 0) *4 ) +2));		// CLEAN TWO BITS ACCORDIGNLY TO THE MASK
				GPIOA->CRL |=  (0b10 << (((my_buttons[i].GPIO_PIN_NUMBER - 0) *4 ) +2));		// USE Y=kX+B TO CALCULATE MASK SHIFT
				}
			else
				{																				// FOR ADC CHANNELS >7 USE CRH REGISTER
				GPIOA->CRH &= ~(0b11 << (((my_buttons[i].GPIO_PIN_NUMBER - 8) *4 ) +2));		// CLEAN TWO BITS ACCORDIGNLY TO THE MASK
				GPIOA->CRH |=  (0b10 << (((my_buttons[i].GPIO_PIN_NUMBER - 8) *4 ) +2));		// USE Y=kX+B TO CALCULATE MASK SHIFT
				}

			// configuring bits PU PD in resister ODR
			if(my_buttons[i].btn_needs_PU_PD == 'U')											// IF BUTTON REQUIRES PULL-UP
				{
				GPIOA->ODR |=  (0b01  <<    my_buttons[i].GPIO_PIN_NUMBER);						// activate PULL-UP
				}
			else if(my_buttons[i].btn_needs_PU_PD == 'D')										// IF BUTTON REQUIRES PULL-DOWN
				{
				GPIOA->ODR &= ~(0b01  <<    my_buttons[i].GPIO_PIN_NUMBER);						// activate PULL-DOWN
				}
		}
		else if(my_buttons[i].GPIO_PORT_NAME == GPIOB)
		{
			RCC->APB2ENR 	|= RCC_APB2ENR_IOPBEN;						// PORT B CLOCK ENABLE FOR GPIO PURPOSE

			// configure bits CNFx in registers CRH and CRL to configure GPIO ports as inputs.
			if(my_buttons[i].GPIO_PIN_NUMBER <=7 )
				{																				// FOR ADC CHANNELS <=7 USE CRL REGISTER
				GPIOB->CRL &= ~(0b11 << (((my_buttons[i].GPIO_PIN_NUMBER - 0) *4 ) +2));		// CLEAN TWO BITS ACCORDIGNLY TO THE MASK
				GPIOB->CRL |=  (0b10 << (((my_buttons[i].GPIO_PIN_NUMBER - 0) *4 ) +2));		// USE Y=kX+B TO CALCULATE MASK SHIFT
				}
			else
				{																				// FOR ADC CHANNELS >7 USE CRH REGISTER
				GPIOB->CRH &= ~(0b11 << (((my_buttons[i].GPIO_PIN_NUMBER - 8) *4 ) +2));		// CLEAN TWO BITS ACCORDIGNLY TO THE MASK
				GPIOB->CRH |=  (0b10 << (((my_buttons[i].GPIO_PIN_NUMBER - 8) *4 ) +2));		// USE Y=kX+B TO CALCULATE MASK SHIFT
				}

			// configuring bits PU PD in resister ODR
			if(my_buttons[i].btn_needs_PU_PD == 'U')
				{
				GPIOB->ODR |=  (0b01  <<    my_buttons[i].GPIO_PIN_NUMBER);					// PULL-UP activation
				}
			else if(my_buttons[i].btn_needs_PU_PD == 'D')
				{
				GPIOB->ODR &= ~(0b01  <<    my_buttons[i].GPIO_PIN_NUMBER);					// CLEAN BIT ACCORDIGNLY TO THE MASK
				}
		}
	}

}
// CONSTRUCTOR DEFINITION FINISHED!!!
// ***********************************************************************************************************************************************************************************
// *****************************************************************
// METHOD "SCAN BUTTONS", checks whether button is pressed by user
void Buttons::scan_buttons()
{
	for(int i=0; i<BUTTONS_QTY; i++)
	{
		if(my_buttons[i].GPIO_PORT_NAME == GPIOA)
		{
			// if default button state is HIGH, and IDR register, button line corresponding state is 1, then button isn't pressed
			if((my_buttons[i].btn_def_lvl_H_L == 'H') && ((GPIOA->IDR & (0b01 << my_buttons[i].GPIO_PIN_NUMBER)) == 0) )
			{
				set_button_state(i, ACTIVATED);
			}
			else
			{
				set_button_state(i, DEACTIVATED);
			}
		}
	}
}
// *****************************************************************
// METHOD "get_button_state"
/*
@brief returns button state
@note  states are follows: PRESSED, CLICKED, RELEASED, DOUBLE-CLICKED, etc.
@param accepts buttons array index
@retval	returns current buttons state
*/
Buttons::btn_state_t Buttons::get_button_state(int array_index)
{
	return btns_processing_array[array_index].btn_state;
}
// *****************************************************************
// METHOD "set_button_state"
/*
@brief set button state
@note  states are follows: PRESSED, CLICKED, RELEASED, DOUBLE-CLICKED, etc.
@param accepts buttons array index
@retval	returns current buttons state
*/
void Buttons::set_button_state(int array_index, btn_state_t button_state)
{
	btns_processing_array[array_index].btn_state = button_state;
}
// *****************************************************************
// METHOD "SCAN BUTTONS"
/*
@brief scans buttons
@note  checks buttons for user activation, counts debounce time counters
@param
@retval
*/
void Buttons::process_buttons()
{
	// SCAN ALL BUTTONS
	for(int i=0; i < BUTTONS_QTY; i++)
	{
		if(get_button_state(0) == ACTIVATED)
		{
			GPIOC->ODR &= ~GPIO_ODR_ODR13;	  // SET LED GPIO LOW (LIGHT ON)
//			if(btns_processing_array[i].debounce_counter < my_buttons[i].filter_time)
//			{
//			   btns_processing_array[i].debounce_counter++;
//			}
//			else
//			{
//				set_button_state(i, PRESSED);	// set button state, for button by i index in array
//			}
		}
		// IF BUTTON SIGNAL LINE IS LO, and, button default state is HI:
		else if(get_button_state(0) == DEACTIVATED)
		{
			GPIOC->ODR  |= GPIO_ODR_ODR13;	  // SET LED GPIO HIGH (LIGHT OFF)
//			if(btns_processing_array[i].debounce_counter > 0)
//			{
//			   btns_processing_array[i].debounce_counter--;
//			}
//			else
//			{
//				set_button_state(i, RELEASED);	// set button state, for button by i index in array
//			}
//		}
//		else if(btns_processing_array[i].pressed_state_counter >= 3000)
//		{
//			set_button_state(i, PRESSED_LONG);
//
		}
	}

}

