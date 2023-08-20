
#include <stdint.h>
#include <stdio.h>
#include "stm32f1xx.h"
#include "INITIALIZATION.hpp"
#include "DELAY_ms.hpp"
#include "UART_transmit_string.hpp"
#include "!!!CONFIG.hpp"
#include "PREPARE_MESSAGE.hpp"
#include "ADC_CONVERSION.hpp"
#include "PROCESS_DATA.hpp"
#include "BUTTONS.hpp"
#include "TRIGGER.hpp"
using namespace std;
// GLOBAL VARIABLES DECLARATION STARTED
//volatile uint32_t global_ADC_DMA_BUFFER[SENSORS_QTY] = {};	// data array to store ADC results transfered by DMA
volatile uint32_t 	global_SysTick_Cnt;							//
volatile uint32_t 	global_ADC_restart_timer = 0;				//
volatile ADC_dump_struct ADC_DATA_DUMP;							// variable creation
// GLOBAL VARIABLES DECLARATION FINISHED
Buttons buttons_instance(my_buttons);							// CREATING CLASS "Buttons" instance
Trigger trigger_0001ms(1);										// CREATING CLASS "TRIGGER" instance, with argument "1ms"
Trigger trigger_0010ms(10);										// CREATING CLASS "TRIGGER" instance, with argument "10ms"
Trigger trigger_0100ms(100);										// CREATING CLASS "TRIGGER" instance, with argument "100ms"
Trigger trigger_0500ms(500);										// CREATING CLASS "TRIGGER" instance, with argument "500ms"
Trigger trigger_1000ms(1000);										// CREATING CLASS "TRIGGER" instance, with argument "500ms"

///////////////////////////////////////////////////////////////////////////////////////
// HANDLERS START HERE/////////////////////////////////////
extern "C" void SysTick_Handler(void)
{
	if(global_SysTick_Cnt>0){
		global_SysTick_Cnt--;
	}
	trigger_0001ms.trigger_update();	// ping trigger
	trigger_0010ms.trigger_update();	// ping trigger
	trigger_0100ms.trigger_update();	// ping trigger
	trigger_0500ms.trigger_update();	// ping trigger
	trigger_1000ms.trigger_update();	// ping trigger
}

extern "C" void ADC1_2_IRQHandler(void)
{
	ADC1->SR   &= ~ADC_SR_EOC;	 	  // END OF CONVERSION flag reset
}

extern "C" void DMA1_Channel1_IRQHandler(void)
{
	DMA1->IFCR |= DMA_IFCR_CTCIF1;  // CLEAR DMA INTERUPT

	if(ADC_DATA_DUMP.averaging_step == AVERAGING_RATIO)
	{
		ADC_DATA_DUMP.averaging_step = 0;
		DMA1_Channel1->CMAR = (uint32_t)ADC_DATA_DUMP.ADC_DMA_buffer_array; // return original receiver adress
		ADC_DATA_DUMP.ADC_DATA_READY = true;
	}
	else
	{
		DMA1_Channel1->CCR	 &= ~DMA_CCR_EN;						// CHANNEL DISABLE
		while(DMA1_Channel1->CCR & DMA_CCR_EN);						// wait for DMA turn-off
		/*DMA address update* start*/
		DMA1_Channel1->CMAR = (uint32_t)(ADC_DATA_DUMP.ADC_DMA_buffer_array) + ADC_DATA_DUMP.averaging_step * SENSORS_QTY * sizeof(uint32_t);
		/*DMA address update* finish*/
		DMA1_Channel1->CCR	 |= DMA_CCR_EN;							// CHANNEL 1 ENABLE
		while((DMA1_Channel1->CCR & DMA_CCR_EN) != DMA_CCR_EN);
		ADC_DATA_DUMP.averaging_step++;
	}
}

extern "C" void TIM2_IRQHandler(void)
{
	TIM2 ->SR  &= ~TIM_SR_UIF;			// CLEAR INTERRUPT FLAG
//	ADC1->CR2  |= ADC_CR2_SWSTART;   	// Start ADC conversion
}
/*******************************************************/
// HANDLERS END HERE/////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN //////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    init_sysClock();
    init_SysTick();
    init_GPIO();
    init_DMA();
    init_ADC();
    init_USART();
    init_TIM2(100);										// initialize TIM2 with 100ms overflow interval
    NVIC_EnableIRQ(SysTick_IRQn);	  					// ENABLE SysTick interrupt
    NVIC_EnableIRQ(ADC1_2_IRQn);	  					// ENABLING ADC INTERRUPTION
    NVIC_EnableIRQ(DMA1_Channel1_IRQn);					// ENABLING DMA INTERRUPT
    NVIC_EnableIRQ(TIM2_IRQn);							// ENABLING INTERRUPT FOR TIM2
    GPIOC->ODR  |= GPIO_ODR_ODR13;	  					// SET LED GPIO HIGH (LIGHT OFF)

    /* Loop forever */
	while(1)
	{
		// 		reminder for idiot:
		//		GPIOC->ODR &= ~GPIO_ODR_ODR13;	  // SET LED GPIO LOW (LIGHT ON)
		//		GPIOC->ODR |= GPIO_ODR_ODR13;	  // SET LED GPIO HIGH (LIGHT OFF)
		//		GPIOC->ODR ^= GPIO_ODR_ODR13;	  // INVERT LED GPIO
		//		delay_ms(500);
		//		GPIOC->ODR ^= GPIO_ODR_ODR13;	  // INVERT LED GPIO

		// 		const char* message = "---5s of your life is gone--- \n";
		//		UART_transmit_string(message);
		//		PROCESS_DATA(ADC_DATA_DUMP.ADC_DMA_buffer_array);
		//		PREPARE_MESSAGE();	// SENDS ALL THE PREPARED DATA THROUGH UART
		if(trigger_0001ms.trigger_get_state() == true)
		{
			trigger_0001ms.trigger_reset();
			//		GPIOC->ODR &= ~GPIO_ODR_ODR13;	  // SET LED GPIO LOW (LIGHT ON)
			//		GPIOC->ODR |= GPIO_ODR_ODR13;	  // SET LED GPIO HIGH (LIGHT OFF)
			//		GPIOC->ODR ^= GPIO_ODR_ODR13;	  // INVERT LED GPIO
		}

		if(trigger_0100ms.trigger_get_state() == true)
		{
			trigger_0100ms.trigger_reset();
		}

		if(trigger_0500ms.trigger_get_state() == true)
		{
			trigger_0500ms.trigger_reset();
			//		GPIOC->ODR &= ~GPIO_ODR_ODR13;	  // SET LED GPIO LOW (LIGHT ON)
			//		GPIOC->ODR |= GPIO_ODR_ODR13;	  // SET LED GPIO HIGH (LIGHT OFF)
			//		GPIOC->ODR ^= GPIO_ODR_ODR13;	  // INVERT LED GPIO
		}

		if(trigger_1000ms.trigger_get_state() == true)
		{
				{
					trigger_1000ms.trigger_reset();
					//		GPIOC->ODR &= ~GPIO_ODR_ODR13;	  // SET LED GPIO LOW (LIGHT ON)
					//		GPIOC->ODR |= GPIO_ODR_ODR13;	  // SET LED GPIO HIGH (LIGHT OFF)
							GPIOC->ODR ^= GPIO_ODR_ODR13;	  // INVERT LED GPIO
				}

		}
	}// WHILE ENDS HERE
}// MAIN ENDS HERE
