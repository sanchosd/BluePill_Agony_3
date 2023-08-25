/*
 * TRIGGER.cpp
 *
 *  Created on: Aug 14, 2023
 *      Author: mjqsg1
 */

#include "DELAY.hpp"
#include <stdio.h>
//#include <iostream>

	/*CONSTRUCTOR DEFINITION START*/
 	/*!
	 * @brief Constructor for the Delay class.
	 *
	 * This constructor takes a list of integer delays and creates a mapping of delay values.
	 * Each delay value is associated with a corresponding instance of the delay_details_t structure.
	 * The delay_details_t instance is inserted as the value in the delay_map, using the delay value as the key.
	 * @param delays_list A list of integer delays.
	 * @note Assumes the function is called to initialize the Delay object.
	 * @retval None.
	 */
	Delay::Delay(const std::list<int>& delays_list){
		for(auto it = delays_list.begin(); it != delays_list.end(); it++)	// for each list container element
		{
			delay_details_t delay_details;									// structure variable instance creation
			delay_details.delay_target_ms = *it;							// desired delay in ms, copied from delays list.
			delays_map.insert(std::make_pair(*it, delay_details));			// map key:value pair appending
		}
	}

	/*CONSTRUCTOR DEFINITION FINISH*/

	/*METHODS DEFINITION START*/

	 /*!
	 * @brief	updates time intervals counter.
	 * @note	pass through all the map entries
	 * @note 	checks if the trigger is in HI state.
	 * @note	if so- increments time intervals counter.
	 * @note	resets particular trigger.
	 * @note	should be called in the main program cycle
	 * @param	no parameters
     * @retval	no return value
     */
	void Delay::delay_update()
	{
		for(auto it = delays_map.begin(); it != delays_map.end(); it++)			// checks all the map entries
		{																		//																//
			if(it->second.delay_counter_ms == it->second.delay_target_ms)	// if 1ms counter reached threshold value
			{
				it->second.delay_over = true;								// set TRUE for delay_over
				it->second.delay_counter_ms = 0;							// reset 1ms counter
			}
			else
			{
				it->second.delay_counter_ms++;								// increment 1ms intervals counter
			}
		}
	}

	/*!
	 * @brief	returns TRUE if delay is over
	 * @note	pass through all the map entries
	 * @note 	checks if the delay is over
	 * @note	if so- returns TRUE
	 * @note	resets particular delay status
	 * @note	should be called in the main program cycle with argument of delay length
	 * @note	if, argument isn't present within the map keys - ERROR precompilation
	 * @param	int, delay, in ms. Argument value should be present within the map container keys.
	 * @retval	returns TRUE in case of delay already over.
	 */
	bool Delay::delay_is_over(int delay)
	{
		auto it = delays_map.find(delay);			//searches for argument value within map keys
		if(it != delays_map.end())					// if key is found
			{										//
				if(it->second.delay_over == true) 	// if delay is already over.
				{									//
					it->second.delay_over = 0;		// reset delay_over to the FALSE state.
					return true;					// return TRUE, means delay_is_over.
				}
				else								// if delay isn't over yet
				{									//
					return false;					// return FALSE
				}
			}
		else
		{
			printf ("ARGUMENT VALUE NOT FOUND WITHIN THE CONSTRUCTOR ARGUMENT VALUES\n");
		}
		return false;
	}
//	/*METHODS DEFINITION FINISH*/


