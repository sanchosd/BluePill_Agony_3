/*
 * DELAY_MS.cpp
 *
 *  Created on: 26 мар. 2023 г.
 *      Author: Jupiter
 */

//#include "main.hpp"

#include "DELAY_ms.hpp"

extern volatile uint32_t global_SysTick_Cnt;

void delay_ms(uint32_t ms){
	global_SysTick_Cnt = ms;
	while(global_SysTick_Cnt !=0);
}




