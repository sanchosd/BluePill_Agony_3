/*
 * data_filtering.hpp
 *
 *  Created on: 13 мая 2023 г.
 *      Author: Sanchos
 */

#ifndef PROCESS_DATA_HPP_
#define PROCESS_DATA_HPP_

#include <stdint.h>
#include "!!!CONFIG.hpp"

void PROCESS_DATA(volatile uint32_t array[AVERAGING_RATIO][SENSORS_QTY]);

#endif /* DATA_AVERAGING_HPP_ */
