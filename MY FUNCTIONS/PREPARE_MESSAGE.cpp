/*
 * PREPARE_MESSAGE.cpp
 *
 *  Created on: 22 мар. 2023 г.
 *      Author: Sanchos
 */
#include "!!!CONFIG.hpp"
#include "UART_TRANSMIT_STRING.hpp"
#include <stdio.h>

void PREPARE_MESSAGE()
{
	for(int i=0; i<SENSORS_QTY; i++)
	{
		char temp_buf[32];
		snprintf(temp_buf, 32, "%d",i+1);
		UART_transmit_string((const char*)temp_buf);			// отправка последовательного номера строки
		UART_transmit_string(" ");
		UART_transmit_string(my_sensors[i].sensor_name);
		UART_transmit_string(" ");


		if(my_sensors[i].sensor_type == 'C')
		{
			my_sensors[i].current = ((((my_sensors[i].raw_result * VREF)/4095) * ((RH + RL)/RL)) - 2.5 ) / my_sensors[i].current_sensitivity;
			UART_transmit_string("Current= ");
			snprintf(temp_buf, 32, "%.3fA",my_sensors[i].current);
			UART_transmit_string((const char*)temp_buf);
		}
		else if(my_sensors[i].sensor_type == 'V')
		{
			my_sensors[i].voltage = ((my_sensors[i].raw_result * VREF) / 4095) * my_sensors[i].attenuation_factor ;
			UART_transmit_string("Voltage= ");
			snprintf(temp_buf, 32, "%.2fV", my_sensors[i].voltage);
			UART_transmit_string((const char*)temp_buf);
		}
		else if(my_sensors[i].sensor_type == 'T')
		{
			my_sensors[i].temperature =  (1.43f - my_sensors[i].raw_result * VREF / 4095.0f) / 4.3f + 25; //Temperature (in °C) = {(V25 - VSENSE) / Avg_Slope} + 25.
			UART_transmit_string("Temper.= ");
			snprintf(temp_buf, 32, "%.2fC", my_sensors[i].temperature);
			UART_transmit_string((const char*)temp_buf);
		}
		else if(my_sensors[i].sensor_type == 'R')
		{
			my_sensors[i].voltage = (my_sensors[i].raw_result * VREF) / 4095;
			UART_transmit_string("R.Volt.= ");
			snprintf(temp_buf, 32, "%.3fV", my_sensors[i].voltage);
			UART_transmit_string((const char*)temp_buf);
		}

		UART_transmit_string("\n");
	}

}

