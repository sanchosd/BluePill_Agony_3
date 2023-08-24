/*
 * TRIGGER.cpp
 *
 *  Created on: Aug 14, 2023
 *      Author: mjqsg1
 */

#include "DELAY.hpp"

	/*CONSTRUCTOR DEFINITION START*/
 	/*!
	 * @brief Constructor for the Delay class.
	 *
	 * This constructor takes a list of integer delays and creates a mapping of delay values.
	 * Each delay value is associated with a corresponding instance of the delay_details_t structure.
	 * The delay_details_t instance is inserted as the value in the delay_map, using the delay value as the key.
	 *
	 * @param delays_list A list of integer delays.
	 * @note Assumes the function is called to initialize the Delay object.
	 * @retval None.
	 */
	Delay::Delay(std::list<int>delays_list){
		for(auto it = delays_list.begin(); it != delays_list.end(); it++)
		{
			delay_details_t delay_details;									// variable instance creation
			delays_map.insert(std::make_pair(*it, delay_details));			// map key:value pair appending
		}
	}

	/*CONSTRUCTOR DEFINITION FINISH*/

	/*METHODS DEFINITION START*/
	 /*
	 * @brief	updates time intervals counter
	 * @note	each metod call, increments counter value.
	 * @note	assumed to be called in SysTick callback, with 1ms interval
	 * @param	no parameters
     * @retval	no return value
     */
//	void Trigger::trigger_update(){
//
//		if(trigger_time_cntr < trigger_time_delay)
//		{
//			trigger_time_cntr++;
//		}
//		else
//		{
//			trigger_set();
//			trigger_time_cntr = 1;
//		}
//	}

	void Delay::delay_trigger_rise()
	{
		for(auto it = delays_map.begin(); it != delays_map.end(); it++)
		{
			it->second.trigger_state = HI;	// second it is map value, what is actually "delay_details" structure.
		}

	}

	void Delay::delay_trigger_reset()
	{

	}

//	bool Trigger::trigger_get_state(){
//		return trigger_state;			// getting variable state
//	}
//	/*METHODS DEFINITION FINISH*/


