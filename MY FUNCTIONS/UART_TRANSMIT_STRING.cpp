/*
 * UART_TRANSMITTING.cpp
 *
 *  Created on: 4 мар. 2023 г.
 *      Author: Sanchos
 */
// USE <> for system files, and "" for user files

using namespace std;
#include <stm32f1xx.h>
#include "string.h"
#include <UART_TRANSMIT_STRING.hpp>
//#include <CONFIG.hpp>


void UART_transmit_string(const char* str_to_send){

		for(size_t i=0; i < strlen(str_to_send); i++)
		{
			while((USART3->SR & USART_SR_TXE) == 0){};
			USART3->DR = str_to_send[i];
		}

}



