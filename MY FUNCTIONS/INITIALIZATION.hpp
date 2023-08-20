/*
 * INITIALIZATION.hpp
 *
 *  Created on: 20 мар. 2023 г.
 *      Author: Sanchos
 */

#ifndef INITIALIZATION_HPP_
#define INITIALIZATION_HPP_

void init_sysClock();
void init_SysTick();
void init_GPIO();
void init_DMA();
void init_ADC();
void init_USART();
void init_TIM2(int ms);

#endif /* INITIALIZATION_HPP_ */
