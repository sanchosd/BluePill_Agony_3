/*
 * INITIALIZATION.cpp
 *
 *  Created on: 20 мар. 2023 г.
 *      Author: Sanchos
 */
#include <bitset>
#include "INITIALIZATION.hpp"
#include "stm32f1xx.h"
#include "!!!CONFIG.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init_sysClock(){

	// ENABLE HSE, WAIT FOR HSE BECOME READY
	RCC->CR |= RCC_CR_HSEON;									// HSE TURN ON
	while(!(RCC->CR & RCC_CR_HSERDY));							// HSE wait for ignition
	// TURN OFF PLL BEFORE INIT
	//RCC->CFGR	&= ~RCC_CR_PLLON;
	//while(RCC->CR & RCC_CR_PLLRDY);
	RCC->CFGR	|= RCC_CFGR_PLLSRC;			// PLL SOURCE: HSE IS USED AS SOURCE
	RCC->CFGR	|= RCC_CFGR_PLLMULL6;		// PLL multiplication factor is 6
	RCC->CR		|= RCC_CR_PLLON;			// PLL ON
	while(!(RCC->CR & RCC_CR_PLLRDY));		// WAIT TILL PLL BECOME READY

	// CONFIGURE FLASH PREFETCH AND THE LATENCY
	FLASH->ACR	|= FLASH_ACR_PRFTBE;		// preftch filter activated
	FLASH->ACR	|= FLASH_ACR_LATENCY_1;		// latency 1
	RCC->CFGR	|= RCC_CFGR_HPRE_DIV1;		// AHB PRESCALLER (SYSCLK not divided)
	RCC->CFGR	|= RCC_CFGR_MCO_SYSCLK;		// CLOCK OUTPUT TO THE MCO PIN
	RCC->CFGR	|= RCC_CFGR_SW_PLL;			// PLL FINALLLY SELECTED AS A SYSTEM CLOCk
	RCC->CFGR	|= RCC_CFGR_PPRE1_DIV1;		// APB1 PRESCALLER (HCLK not divided)
	RCC->CFGR	|= RCC_CFGR_PPRE2_DIV1;		// APB2 PRESCALLER (HCLK not divided)
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));	// wait for a flag confirming PLL is used as clock
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init_GPIO(){
	RCC->APB2ENR |=  RCC_APB2ENR_IOPAEN;						// PORT A CLOCK ENABLE
	RCC->APB2ENR |=  RCC_APB2ENR_IOPBEN;						// PORT B CLOCK ENABLE
	RCC->APB2ENR |=  RCC_APB2ENR_IOPCEN;						// PORT C CLOCK ENABLE
	GPIOC->CRH	 &=  ~GPIO_CRH_CNF13;							// LED PORT CONFIG
	GPIOC->CRH	 |=  GPIO_CRH_MODE13;							// LED PORT CONFIG
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init_SysTick(){
	SysTick->LOAD &= ~SysTick_LOAD_RELOAD_Msk;		// RELOAD register clear
	SysTick->LOAD  = SysClock/(1000-1);				// VALUE register gets 8000 to have 1kHz SysTick interruption
	SysTick->VAL   = ~SysTick_VAL_CURRENT_Msk;		// VALUE register clear
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk; 	// AHB bus is a clock source for SysTick
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;		// SysTick interruption enable
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;		// SysTick Enable
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init_ADC(){
	//	VREF - ADC channel 16
	//	TEMP - ADC channel 17
	RCC->APB2ENR 	|= RCC_APB2ENR_IOPAEN;						// PORT A CLOCK ENABLE FOR ADC PURPOSE
	RCC->APB2ENR 	|= RCC_APB2ENR_IOPBEN;						// PORT B CLOCK ENABLE FOR ADC PURPOSE
	RCC->APB2ENR 	|= RCC_APB2ENR_IOPCEN;						// PORT C CLOCK ENABLE FOR ADC PURPOSE
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONFIGURING GPIOs AS ANALOG INPUTS!!!!
	for(int i=0; i<SENSORS_QTY; i++){													// FOR SENSORS QUATITY
		if(my_sensors[i].GPIO_PORT_NAME == GPIOA) // IF SENSOR PORT IS GPIOA
		{																				// CONFIGURING GPIOA PIN AS ANALOG MODE (PROGRAMMING CNF BITS TO 00)
			if(my_sensors[i].GPIO_PIN_NUMBER <=7 ){										// FOR ADC CHANNELS <=7 USE CRL REGISTER
				GPIOA->CRL &= ~(0b11 << (((my_sensors[i].GPIO_PIN_NUMBER) 	  *4 ) +2) );	// USE Y=kX+B TO CALCULATE MASK SHIFT
			}else{																		// FOR ADC CHANNELS >7 USE CRH REGISTER
				GPIOA->CRH &= ~(0b11 << (((my_sensors[i].GPIO_PIN_NUMBER - 8) *4 ) +2) );	// USE Y=kX+B TO CALCULATE MASK SHIFT
			}
		}
		if(my_sensors[i].GPIO_PORT_NAME == GPIOB) // IF SENSOR PORT IS GPIOB
		{
			if(my_sensors[i].GPIO_PIN_NUMBER <=7 ){
				GPIOB->CRL &= ~(0b11 << (((my_sensors[i].GPIO_PIN_NUMBER) 	  *4 ) +2) );
			}else{
				GPIOB->CRH &= ~(0b11 << (((my_sensors[i].GPIO_PIN_NUMBER - 8) *4 ) +2) );
			}
		}
	}
// CONFIGURING GPIOs AS ANALOG INPUTS ENDED
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	RCC ->APB2ENR	|= RCC_APB2ENR_ADC1EN;					// EN clock for ADC1
	RCC ->CFGR 		&= ~RCC_CFGR_ADCPRE;			 		// ADC prescaller configured to division factor 2
//	ADC1->CR1 		|= ADC_CR1_EOCIE;						// Enable interrupt for regular channels.
	ADC1->CR1		|= ADC_CR1_SCAN;						// SCAN mode activated
	ADC1->CR2 		|= ADC_CR2_TSVREFE;						// Temperature sensor enable
	ADC1->CR2 		&= ~ADC_CR2_ALIGN;						// Align result to the right
	ADC1->CR2		|= ADC_CR2_EXTTRIG;					    // external trigger selected as event trigger for ADC
	ADC1->CR2		|= ADC_CR2_EXTSEL_Msk;					// SWSTART selected as external trigger for ADC
	ADC1->CR2		|= ADC_CR2_DMA;							// DMA REQUEST ENABLE
//	ADC1->CR2		|= ADC_CR2_CONT;						// CONT mode enabled

// CONFIGURING ADC CHANNELS SAMPLING RATE
	for(int i=0; i<SENSORS_QTY; i++)							// FOR SENSORS QUANTITY
	{
		if( (0 <= i) && (i <= 9) )								// for channels <=9 write to SMPR2
		{
			ADC1->SMPR2	|= 0b100 << ((i-0)*3);					// SAMPLE TIME 41.5 cycles
		}
		if( (10 <= i) && (i <=17) )								// for channels <=17 write to SMPR1
		{
			ADC1->SMPR1	|= 0b100 << ((i-10)*3);					// SAMPLE TIME 41.5 cycles
		}
	}

	// CONFIGURING ADC CHANNELS POLLING SEQUENCE
	for(int i=0; i<SENSORS_QTY; i++)								// FOR SENSORS QUANTITY
	{
		switch (i) {
			case 0:
				ADC1->SQR3  |= my_sensors[i].ADC_CHANNEL << ADC_SQR3_SQ1_Pos;	// 1-th sequential conversion
				break;
			case 1:
				ADC1->SQR3  |= my_sensors[i].ADC_CHANNEL << ADC_SQR3_SQ2_Pos;	// 2-th sequential conversion
				break;
			case 2:
				ADC1->SQR3  |= my_sensors[i].ADC_CHANNEL << ADC_SQR3_SQ3_Pos;	// 3-th sequential conversion
				break;
			case 3:
				ADC1->SQR3  |= my_sensors[i].ADC_CHANNEL << ADC_SQR3_SQ4_Pos;	// 4-th sequential conversion
				break;
			case 4:
				ADC1->SQR3  |= my_sensors[i].ADC_CHANNEL << ADC_SQR3_SQ5_Pos;	// 5-th sequential conversion
				break;
			case 5:
				ADC1->SQR3  |= my_sensors[i].ADC_CHANNEL << ADC_SQR3_SQ6_Pos;	// 6-th sequential conversion
				break;
			case 6:
				ADC1->SQR2  |= my_sensors[i].ADC_CHANNEL << ADC_SQR2_SQ7_Pos;	// 7-th sequential conversion
				break;
			case 7:
				ADC1->SQR2  |= my_sensors[i].ADC_CHANNEL << ADC_SQR2_SQ8_Pos;	// 8-th sequential conversion
				break;
			case 8:
				ADC1->SQR2  |= my_sensors[i].ADC_CHANNEL << ADC_SQR2_SQ9_Pos;	// 9-th sequential conversion
				break;
			case 9:
				ADC1->SQR2  |= my_sensors[i].ADC_CHANNEL << ADC_SQR2_SQ10_Pos;	// 10-th sequential conversion
				break;


		}
//
//		if( (0 <= i) && (i <= 6) )									// IF  0<= (ADC CHANNEL) <=6 -> WRITE TO SQR3 REG,
//		{
//			ADC1->SQR3  |= my_sensors[i].ADC_CHANNEL << ((i-0)*5);	//
//
//		}
//		if( (7 <= i) && (i <= 12) )									// IF  7<= (ADC CHANNEL) <=12 -> WRITE TO SQR2 REG,
//		{
//			ADC1->SQR2  |= my_sensors[i].ADC_CHANNEL << ((i-7)*5);
//		}
//		if( (13 <= i) && (i <= 16) )								// IF 13<= (ADC CHANNEL) <=16 -> WRITE TO SQR1 REG,
//		{
//			ADC1->SQR1  |= my_sensors[i].ADC_CHANNEL << ((i-13)*5);
//		}
	}

// CONFIGURING SEQUENCE LENGTH
	ADC1->SQR1 |= ((SENSORS_QTY - 1) << ADC_SQR1_L_Pos);	// AMOUNT OF ADC CONVERTIONS
// value in SQR1_L register part should be by -1 smaller, as ZERO corresponds to single conversion.

// LAUNCH ADC FIRST TIME
	ADC1->CR2 |= ADC_CR2_ADON;								// turn-on ADC

// ADC CALIBRATION START
	volatile int i=1000000;
	while(i>0)
	{
		i--;
	}
	ADC1->CR2 |= ADC_CR2_CAL;
	while ((ADC1->CR2 & ADC_CR2_CAL) != 0);
	// ADC CALIBRATION FINISH

    ADC1->CR2   |= ADC_CR2_ADON;	  	// SET ADON to ENABLE ADC SECOND TIME
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init_USART(){	// USART 3 IS USED
//	UART INTERNAL CLOCK IS 32MHz
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;	// USART 3 CLOCK ENABLE
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;	    // GPIOB CLOCK ENABLE FOR UART PURPOSE
//	TXD3 -> PB10, ALTERNATE FUNCTION OUTPUT WITH P-P
	GPIOB->CRH	 &= ~GPIO_CRH_CNF10_Msk;	// GPIOB.10, CLEARING CNF10[] BITS
	GPIOB->CRH	 |=	GPIO_CRH_CNF10_1;		// GPIOB.10, SET CNF10[1:0] (Alternate function output Push-pull)
	GPIOB->CRH	 &= ~GPIO_CRH_MODE10_Msk;	// GPIOB.10, CLEARING MODE10[] BITS
	GPIOB->CRH 	 |= GPIO_CRH_MODE10_1;		// GPIOB.10, SET MODE10[1:0] (Output mode PP, max speed 2 MHz)

//	UART CONFIGURATION
	USART3->CR1	 |= USART_CR1_UE;			// ENABLE USART1 MODULE
	USART3->BRR   = 208 << 4;				// (32MHz/(16*9600BAUD))=208
	USART3->CR1  |= USART_CR1_TE;			// ENABLE TRANSMITTER
//	USART3->CR2	 |= USART_CR1_RE;			// ENABLE RECEIVER
	USART3->CR2   = 0;						//
	USART3->CR3   = 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init_DMA(){
//	extern volatile uint32_t global_ADC_DMA_BUFFER[];
	extern volatile ADC_dump_struct ADC_DATA_DUMP;
	RCC->AHBENR 		 |= RCC_AHBENR_DMA1EN;				// DMA CHANNEL 1 CLOCK ANABLE
	DMA1_Channel1->CMAR   = (uint32_t)ADC_DATA_DUMP.ADC_DMA_buffer_array;// GLOBAL VARIABLE ADRESS TO THE CMAR REGISTER
	DMA1_Channel1->CPAR   = (uint32_t)(&ADC1->DR);			// ADC1 DATA REGISTER TO THE CPAR REGISTER. ADC START ADDRESS 0x4001 2400, DR FFSET 0x4001 27FF
 	DMA1_Channel1->CNDTR  = SENSORS_QTY;				// NUMBER DATA TO BE TRANSFERRED
 	DMA1_Channel1->CCR	 |= DMA_CCR_MSIZE_1;				// MEMORY SIZE 32BIT
	DMA1_Channel1->CCR	 |= DMA_CCR_PSIZE_1;				// PERYPH SIZE 32BIT
	DMA1_Channel1->CCR	 |= DMA_CCR_MINC;					// MEMORY INCREMENT MODE ENABLED
	DMA1_Channel1->CCR	 |= DMA_CCR_TCIE;					// TRANSFER COMPLETE INTERRUPT ENABLE
//	DMA1_Channel1->CCR	 |= DMA_CCR_HTIE;
	DMA1_Channel1->CCR	 |= DMA_CCR_CIRC;					// CICULAR MODE ENABLED
	DMA1_Channel1->CCR	 |= DMA_CCR_EN;						// CHANNEL 1 ENABLE
}
///////////////////////////////////////////////////////////////////////////////////////
void init_TIM2(int overflow_time_in_ms){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;			// ACTIVATE CLOCK FOR TIM2
	float TIM2_ARR_VALUE  = 0;
	float TIM2_PRESCALLER = 0;
	do
	{
		TIM2_PRESCALLER++;
		TIM2_ARR_VALUE = ( (float)overflow_time_in_ms/1000 )*( (float)(SysClock/TIM2_PRESCALLER) );
	}while(TIM2_ARR_VALUE > 65535);				// CHECK WHETHER VALUE LESS THAN (2^16-1)
	TIM2->PSC	  = TIM2_PRESCALLER ;			// TIMER CLOCK FREQUENCY IS SysClk/(x+1)
	TIM2->ARR	  = TIM2_ARR_VALUE;				// OVERFLOW PERIOD LOADING
	TIM2->CR1    |= TIM_CR1_URS;				// TIMER OVERFLOW GENERATES UPDATE INTERRUPT
	TIM2->DIER   |= TIM_DIER_UIE;				// UPDATE INTERRUPT ENABLE
	TIM2->CR1    |= TIM_CR1_CEN;				// ENABLE TIMER TIM2
}
