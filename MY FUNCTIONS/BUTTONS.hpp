/*
 * BUTTONS.hpp
 *
 *  Created on: 9 июл. 2023 г.
 *      Author: Sanchos
 */

#ifndef BUTTONS_HPP_
#define BUTTONS_HPP_

#include "!!!CONFIG.hpp"

class Buttons{

	public:
	/*********************************************/
	/* CONSTRUCTOR DECLARATION STARTED*/
	Buttons(buttons_t my_buttons[BUTTONS_QTY]);	// constructor declaration
	/* CONSTRUCTOR DECLARATION FINISHED***********/
	//***************************************************************************************************************************
	// VAR "AVAILABLE BUTTONS STATES"
	enum btn_state_t{
				UNDEFINED   	,
				ACTIVATED 		,
				DEACTIVATED		,
				PRESSED     	,
				RELEASED    	,
				HI		    	,
				LO          	,
				DEBOUNCE    	,
				CLICKED_ONCE	,
				CLICKED_TWICE	,
				PRESSED_LONG
			};

	typedef struct{
				bool fall_edge_detected 	= 0;
				bool rise_edge_detected 	= 0;
				int debounce_counter		= 0;
				int pressed_state_counter 	= 0;
				int released_state_counter 	= 0;
				btn_state_t btn_state   	= UNDEFINED;
			} buttons_processing_t;

	// METHODS DECLARATION //************************************************************************************************
    void scan_buttons();							// method scans buttons states
	void process_buttons();							// method scans buttons
	bool check_btn_pressed(int btn_number);			// method checks whether user pressed button, returns TRUE if pressed
	btn_state_t get_button_state(int array_index);	// method checks private variable, keeping button state
	void 	    set_button_state(int array_index, btn_state_t btn_state);	// method sets buttons state

	// PUBLIC VARIABLES DECLARATION FINISHED
	private:
	// PRIVATE VARIABLES DEFINITION

	// VAR "BUTONS_PROCESSING_ARRAY"
		buttons_processing_t btns_processing_array[BUTTONS_QTY] = {
		[0]={
			.fall_edge_detected = 0,
			.rise_edge_detected = 0,
			.debounce_counter	= 0,
			.pressed_state_counter 	= 0,
			.released_state_counter 	= 0,
			.btn_state   		= UNDEFINED,
		},
		[1]={
			.fall_edge_detected = 0,
			.rise_edge_detected = 0,
			.debounce_counter	= 0,
			.pressed_state_counter 		= 0,
			.released_state_counter 	= 0,
			.btn_state   		= UNDEFINED,
			},
		[2]={
			.fall_edge_detected 	= 0,
			.rise_edge_detected 	= 0,
			.debounce_counter		= 0,
			.pressed_state_counter 	= 0,
			.released_state_counter = 0,
			.btn_state   			= UNDEFINED,
			},
		};
};

#endif /* BUTTONS_HPP_ */
