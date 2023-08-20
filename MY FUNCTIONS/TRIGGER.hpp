/*
 * semafor.hpp
 *
 *  Created on: Aug 14, 2023
 *      Author: mjqsg1
 */

#ifndef TRIGGER_HPP_
#define TRIGGER_HPP_

class Trigger
{
	public:
		/*CONSTRUCTOR DECLARATION START*/
		Trigger(int time_lngth);					// constructor, accepting desired time delay in milliseconds
		/*CONSTRUCTOR DECLARATION FINISH*/

		/* VARIABLES DECLARATION START*/

		/* VARIABLES DECLARATION FINISH*/

		/* METHODS DECLARATION START*/
		void trigger_update();						// trigger strobe input, incrementing internal trigger time counter
		void trigger_set();							// trigger setting to the HI state
		void trigger_reset();						// trigger resetting to the LO state
		bool trigger_get_state();					// trigger current state returns
		/* METHODS DECLARATION FINISH*/
	private:
		volatile bool trigger_state = 0;			// trigger sate flag
		volatile int  trigger_time_cntr    =  1;		// trigger 1ms intervals counter
		int 		  trigger_time_delay   =  0;		// destined 1ms intervals amount
};

#endif /* TRIGGER_HPP_ */
