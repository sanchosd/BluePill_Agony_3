#ifndef __config_hpp
#define __config_hpp

#include <stm32f1xx.h>


// USER DEIFINES STARTS HERE
#define SysClock 48000000U		// define SYSTEM FREQUENCY
#define VREF 3.3f				// define REFERENCE VOLTAGE
#define VREFINT 1.2f			// define INTERNAL REFERENCE VOLTAGE
#define RH 10					// define RESISTIVE DEVIDER Rh=10kOhm
#define RL 13.7					// define RESISTIVE DEVIDER Rh=13.7kOhm
#define SENSORS_QTY 10			// define SENSORS QUANTITY
#define BUTTONS_QTY 3			// define BUTTONS QUANTITY
#define AVERAGING_RATIO 10		// define ADC data averaging ratio
// USER DEIFINES ENDS HERE

typedef struct{
	uint32_t ADC_DMA_buffer_array[AVERAGING_RATIO][SENSORS_QTY]={0};
	uint32_t averaging_step;
	bool	 ADC_DATA_READY;
}ADC_dump_struct;
//***************************
// HER IS DEFINED STRUCTURE WITH THE SENSORS DATA AND PARAMETERS
typedef struct {
	int    			sensor_number;		// SENSOR SEQUENTIONAL NUMBER
	char 			sensor_type;		// (C - current, V - voltage, T - temperature, R - reference)
	char* 			sensor_name;		// SENSOR NAME, F.EX "STARTER"
	GPIO_TypeDef*   GPIO_PORT_NAME;		// SENSOR PORT NAME, F.EX "PORTA"
	int    			GPIO_PIN_NUMBER;	// SENSOR PIN NAME, F.EX "PA9"
	int 			ADC_CHANNEL;		// ADC CHANNELNEL NUMBER
	int    			current_rate;		// CURRENT, SENSOR SPECIFIED FOR
	float  			current_sensitivity;// mV per A
	float  			attenuation_factor;	// resistive divider division factor
	float  			current;			// sensor's current, in Amps
	float  			voltage;			// sensor's voltage, in Volts
	float			temperature;		// sensor's temperature, in Celsius
	uint32_t 		raw_result;			// ADC's conversion result.
	char* 			current_direction;	// current direction in the sensor, POS or NEG
}Sensors;
// HERE IS DEFINITION FINISHED
//****************************

inline Sensors my_sensors[SENSORS_QTY] = {
		[0]={
			.sensor_number       = 1,
			.sensor_type 		 = 'C',
			.sensor_name 		 = (char*)"6A-SENSOR--",
			.GPIO_PORT_NAME	 	 = GPIOA,
			.GPIO_PIN_NUMBER	 = 1,
			.ADC_CHANNEL		 = 1,
			.current_rate		 = 6,
			.current_sensitivity = 0.3267f,
//			.attenuation_factor	 = 0,
			.current			 = 0,
//			.voltage			 = 0,
//			.temperature		 = 0,
			.raw_result			 = 0,
			.current_direction	 = (char*)"POS"

		},
		[1]={
			.sensor_number       = 2,
			.sensor_type 		 = 'C',
			.sensor_name 		 = (char*)"HEAD LAMP--",
			.GPIO_PORT_NAME	 	 = GPIOA,
			.GPIO_PIN_NUMBER	 = 2,
			.ADC_CHANNEL		 = 2,
			.current_rate		 = 6,
			.current_sensitivity = 0.3267f,
//			.attenuation_factor	 = 0,
			.current			 = 0,
//			.voltage			 = 0,
//			.temperature		 = 0,
			.raw_result			 = 0,
			.current_direction	 = (char*)"POS"

		},
		[2]={
			.sensor_number       = 3,
			.sensor_type 		 = 'C',
			.sensor_name 		 = (char*)"REAR LAMP--",
			.GPIO_PORT_NAME	 	 = GPIOA,
			.GPIO_PIN_NUMBER	 = 3,
			.ADC_CHANNEL		 = 3,
			.current_rate		 = 6,
			.current_sensitivity = 0.3267f,
//			.attenuation_factor	 = 0,
			.current			 = 0,
//			.voltage			 = 0,
//			.temperature		 = 0,
			.raw_result			 = 0,
			.current_direction	 = (char*)"POS"

		},
		[3]={
			.sensor_number       = 4,
			.sensor_type 		 = 'C',
			.sensor_name 		 = (char*)"REAR HEATER",
			.GPIO_PORT_NAME	 	 = GPIOA,
			.GPIO_PIN_NUMBER	 = 4,
			.ADC_CHANNEL		 = 4,
			.current_rate		 = 6,
			.current_sensitivity = 0.3267f,
//			.attenuation_factor	 = 0,
			.current			 = 0,
//			.voltage			 = 0,
//			.temperature		 = 0,
			.raw_result			 = 0,
			.current_direction	 = (char*)"POS"

		},
		[4]={
			.sensor_number       = 5,
			.sensor_type 		 = 'C',
			.sensor_name 		 = (char*)"FOG LAMP---",
			.GPIO_PORT_NAME	 	 = GPIOA,
			.GPIO_PIN_NUMBER	 = 5,
			.ADC_CHANNEL		 = 5,
			.current_rate		 = 100,
			.current_sensitivity = 145.5f,
//			.attenuation_factor	 = 0,
			.current			 = 0,
//			.voltage			 = 0,
//			.temperature		 = 0,
			.raw_result			 = 0,
			.current_direction	 = (char*)"POS"

		},
		[5]={
			.sensor_number       = 6,
			.sensor_type 		 = 'C',
			.sensor_name 		 = (char*)"SPARE-1----",
			.GPIO_PORT_NAME	 	 = GPIOA,
			.GPIO_PIN_NUMBER	 = 6,
			.ADC_CHANNEL		 = 6,
			.current_rate		 = 100,
			.current_sensitivity = 145.5f,
//			.attenuation_factor	 = 0,
			.current			 = 0,
//			.voltage			 = 0,
//			.temperature		 = 0,
			.raw_result			 = 0,
			.current_direction	 = (char*)"POS"

		},
		[6]={
			.sensor_number       = 7,
			.sensor_type 		 = 'V',
			.sensor_name 		 = (char*)"+5V.CALIBR-",
			.GPIO_PORT_NAME	 	 = GPIOA,
			.GPIO_PIN_NUMBER	 = 7,
			.ADC_CHANNEL		 = 7,
//			.current_rate		 = 0,
//			.current_sensitivity = 0,
			.attenuation_factor	 = 2,
//			.current			 = 0,
			.voltage			 = 0,
//			.temperature		 = 0,
			.raw_result			 = 0,
//			.current_direction	 = (char*)"POS"

		},
		[7]={
			.sensor_number       = 8,
			.sensor_type 		 = 'V',
			.sensor_name 		 = (char*)"ACC.VOLT.--",
			.GPIO_PORT_NAME	 	 = GPIOB,
			.GPIO_PIN_NUMBER	 = 1,
			.ADC_CHANNEL		 = 9,
//			.current_rate		 = 0,
//			.current_sensitivity = 0,
			.attenuation_factor	 = 11,
//			.current			 = 0,
			.voltage			 = 0,
//			.temperature		 = 23,
			.raw_result			 = 0,
//			.current_direction	 = (char*)"POS"

		},
		[8]={	// INTERNAL STM32 TEMPERATURE SENSOR
			.sensor_number       = 9,
			.sensor_type 		 = 'T',
			.sensor_name 		 = (char*)"TEMP.------",
//			.GPIO_PORT_NAME	     = N/A
//			.GPIO_PIN_NUMBER	 = N/A
			.ADC_CHANNEL		 = 16,
//			.current_rate		 = N/A
//			.current_sensitivity = N/A
//			.attenuation_factor	 = N/A
//			.current			 = N/A
//			.voltage			 = N/A
			.temperature		 = 0,
			.raw_result			 = 0,
//			.current_direction	 = (char*)"POS"

		},
		[9]={
			.sensor_number       = 10,
			.sensor_type 		 = 'R',
			.sensor_name 		 = (char*)"REF.VOLT---",
//			.GPIO_PORT_NAME	     = N/A
//			.GPIO_PIN_NUMBER	 = N/A
			.ADC_CHANNEL		 = 17,
//			.current_rate		 = N/A
//			.current_sensitivity = N/A
//			.attenuation_factor	 = N/A
//			.current			 = N/A
			.voltage			 = 0,
//			.temperature		 = N/A
			.raw_result			 = 0,
//			.current_direction	 = N/A

		},
};


//***************************
// HERE IS DEFINED STRUCTURE WITH THE BUTTONS DATA AND PARAMETERS
typedef struct {
	const int 			btn_number;			// button sequential number
	GPIO_TypeDef*		GPIO_PORT_NAME;		// GPIO port name by GPIOx
	const int			GPIO_PIN_NUMBER;	// GPIO pin number, 0 ... 16
	const char*			btn_unique_name;	// button personal name, for ex. "START"
	const char			btn_needs_PU_PD;	// if button needs Pull-UP/DOWN -> set 'U', 'D', or 'N', if no pull-up needed
	const char  		btn_def_lvl_H_L;	// default level at the button sense line H or L
	const char			btn_def_NO_NC;		// default button state, NORMAL OPEN/CLOSE -> 'O' or 'C'
	const int			filter_time;		// time to wait till button state assertion, in milliseconds
//	int 				debounce_cntr;		// counter, counting
//	btn_state_t 		btn_state ;			// button current state
}buttons_t;
// HERE IS DEFINITION FINISHED
//****************************

inline buttons_t my_buttons[BUTTONS_QTY] = {
	[0]={
		.btn_number 			 = 1,
		.GPIO_PORT_NAME          = GPIOA,
		.GPIO_PIN_NUMBER		 = 10,
		.btn_unique_name 		 = (char*)"UP",
		.btn_needs_PU_PD		 = 'U',
		.btn_def_lvl_H_L		 = 'H',
		.btn_def_NO_NC			 = 'O',
		.filter_time 			 = 10,
//		.debounce_cntr			 = 0,
//		.btn_state				 = UNDEFINED
	},
	[1]={
		.btn_number 			 = 2,
		.GPIO_PORT_NAME          = GPIOA,
		.GPIO_PIN_NUMBER		 = 11,
		.btn_unique_name 		 = (char*)"DOWN",
		.btn_needs_PU_PD		 = 'U',
		.btn_def_lvl_H_L		 = 'H',
		.btn_def_NO_NC			 = 'O',
		.filter_time 			 = 10,
//		.debounce_cntr			 = 0,
//		.btn_state				 = UNDEFINED
	},
	[2]={
		.btn_number 			 = 3,
		.GPIO_PORT_NAME          = GPIOA,
		.GPIO_PIN_NUMBER		 = 12,
		.btn_unique_name 		 = (char*)"ENTER",
		.btn_needs_PU_PD		 = 'U',
		.btn_def_lvl_H_L		 = 'H',
		.btn_def_NO_NC			 = 'O',
		.filter_time 			 = 10,
//		.debounce_cntr			 = 0,
//		.btn_state				 = UNDEFINED
	},
};

#endif
