/*
 * TRIGGER.cpp
 *
 *  Created on: Aug 14, 2023
 *      Author: mjqsg1
 */

#include "TRIGGER.hpp"

	/*CONSTRUCTOR DEFINITION START*/
	Trigger::Trigger(int time_length){
		trigger_time_delay = time_length;	// time delay value, specified by customer, copied from the constructor argument to the variable
	}
	/*CONSTRUCTOR DEFINITION FINISH*/

	/*METHODS DEFINITION START*/
	/**
	 * @brief	updates time intervals counter
	 * @note	each metod call, increments counter value.
	 * @note	assumed to be called in SysTick callback, with 1ms interval
	 * @param	no parameters
     * @retval	no return value
	 */
	void Trigger::trigger_update(){

		if(trigger_time_cntr < trigger_time_delay)
		{
			trigger_time_cntr++;
		}
		else
		{
			trigger_set();
			trigger_time_cntr = 1;
		}
	}

	void Trigger::trigger_set()
	{
		trigger_state = true;	// setting trigger
	}

	void Trigger::trigger_reset()
	{
		trigger_state = false;
	}

	bool Trigger::trigger_get_state(){
		return trigger_state;			// getting variable state
	}
	/*METHODS DEFINITION FINISH*/


