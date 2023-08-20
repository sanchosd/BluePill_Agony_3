/*
 * ADC_CONVERSION.cpp
 *
 *  Created on: 7 мая 2023 г.
 *      Author: Sanchos
 */
#include "ADC_CONVERSION.hpp"

extern volatile uint32_t global_ADC_restart_timer;

void ADC_CONVERSION_INTERVAL_ms(uint32_t delay_ms)
{
	if(global_ADC_restart_timer >= delay_ms)
	{
		global_ADC_restart_timer = 0;		// clear variable
		ADC1->CR2 	|= ADC_CR2_SWSTART;   	// Start ADC conversion
	}
}




