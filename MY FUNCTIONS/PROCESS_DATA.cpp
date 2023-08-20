/*
 * DATA_FILTERING.cpp
 *
 *  Created on: 13 мая 2023 г.
 *      Author: Sanchos
 */

#include <PROCESS_DATA.hpp>

void PROCESS_DATA(volatile uint32_t array[AVERAGING_RATIO][SENSORS_QTY])
{
	for(int i = 0; i < SENSORS_QTY; i++)
	{
		uint32_t summ = 0;
		for(int y = 0; y < AVERAGING_RATIO; y++)
		{
			summ += array[y][i];
		}
		my_sensors[i].raw_result = summ / AVERAGING_RATIO;
	}
}



