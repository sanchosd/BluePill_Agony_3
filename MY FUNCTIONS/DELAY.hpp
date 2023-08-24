/*
 * semafor.hpp
 *
 *  Created on: Aug 14, 2023
 *      Author: mjqsg1
 */

#ifndef DELAY_HPP_
#define DELAY_HPP_

#include <map>
#include <vector>
#include <list>

class Delay
{
	public:
	/*CONSTRUCTOR DECLARATION START*/
	Delay(std::list<int> delays_list);	// constructor accepts array of user-defined delays, in milliseconds.
	/*CONSTRUCTOR DECLARATION FINSH*/

	/*VARIABLES DECLARATION START*/

	/*VARIABLES DECLARATION FINISH*/
	/* METHODS DECLARATION START*/
	void delay_trigger_rise();
	void delay_trigger_reset();
	void delay_get_state();
	/* METHODS DECLARATION FINISH*/
	private:
	/*VARIABLES DECLARATION START*/
	// KEEPS TRIGGER STATE
	enum trigger_state_t
	{
		HI,
		LO
	};
	// KEEPS PARTICULAR DELAY PARAMETERS
	struct delay_details_t{
		trigger_state_t trigger_state = LO;
		int delay_cntr_ms 	 		  = 0;
		int delay_desired_ms 		  = 0;
	};

	std::map<int, delay_details_t> delays_map;

	/*VARIABLES DECLARATION FINISH*/
};



//class Trigger
//{
//	public:
//		/*CONSTRUCTOR DECLARATION START*/
//		Trigger(int time_lngth);					// constructor, accepting desired time delay in milliseconds
//		/*CONSTRUCTOR DECLARATION FINISH*/
//
//		/* VARIABLES DECLARATION START*/
//
//		/* VARIABLES DECLARATION FINISH*/
//
//		/* METHODS DECLARATION START*/
//		void trigger_update();						// trigger strobe input, incrementing internal trigger time counter
//		void trigger_set();							// trigger setting to the HI state
//		void trigger_reset();						// trigger resetting to the LO state
//		bool trigger_get_state();					// trigger current state returns
//		/* METHODS DECLARATION FINISH*/
//	private:
//		volatile bool trigger_state = 0;				// trigger sate flag
//		volatile int  trigger_time_cntr    =  1;		// trigger 1ms intervals counter
//		int 		  trigger_time_delay   =  0;		// destined 1ms intervals amount
//};

#endif /* TRIGGER_HPP_ */
