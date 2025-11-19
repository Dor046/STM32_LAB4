/*
 * fsm_manual.c
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#include "fsm_manual.h"


//increse duration traffic light
void increase_duration(){
	led1_value++;
	if (led1_value == 100) {
		led1_value = 0;
	}
}

void fsm_manual(){

	switch (mode){
	case MODE1: //AUTO
		fsm_automatic();

		//change MODE
		if (is_button_pressed(0)){
			led1_value = 0;
			led2_value = 2;
			update_led7seg();
			led_status = INIT;
			mode = MODE2;
			setTimer(3, 250);
			setTimer(4, 250);
		}
		break;
	case MODE2: //increase red time duration

		//red display
		blink_RED_1();
		blink_RED_2();

		//increase red_duration
		if (is_button_pressed(1)){
			increase_duration();
			update_led7seg();
		}

		//change MODE
		if (is_button_pressed(0)){
			red_duration = -1;
			led1_value = 0;
			led2_value = 3;
			update_led7seg();
			led_status = INIT;
			mode = MODE3;
		}
		if (is_button_pressed(2)){
			red_duration = led1_value;
			led1_value = 0;
			led2_value = 3;
			update_led7seg();
			led_status = INIT;
			mode = MODE3;
		}

		led7_segRun();
		break;
	case MODE3: // increase yellow time duration

		//yellow display
		blink_YELLOW_1();
		blink_YELLOW_2();

		//increase yellow_duration
		if (is_button_pressed(1)){
			increase_duration();
			update_led7seg();
		}

		//change MODE
		if (is_button_pressed(0)){
			yellow_duration = -1;
			led1_value = 0;
			led2_value = 4;
			update_led7seg();
			led_status = INIT;
			mode = MODE4;
		}
		if (is_button_pressed(2)){
			yellow_duration = led1_value;
			led1_value = 0;
			led2_value = 4;
			update_led7seg();
			led_status = INIT;
			mode = MODE4;
		}

		led7_segRun();
		break;
	case MODE4: // increase green time duration

		//green display
		blink_GREEN_1();
		blink_GREEN_2();

		//increase green_duration
		if (is_button_pressed(1)){
			increase_duration();
			update_led7seg();
		}

		//change MODE
		if (is_button_pressed(0)){
			green_duration = -1;

			//check available
			if (((red_duration == -1) && (green_duration == -1)) ||
			((green_duration == -1) && (yellow_duration == -1)) ||
			((yellow_duration == -1) && (red_duration == -1))){
				red_duration = DEFAULT_RED;
				green_duration = DEFAULT_GREEN;
				yellow_duration = DEFAULT_YELLOW;
			}else if (red_duration == -1){
				red_duration = green_duration + yellow_duration;
			}else if (green_duration == -1){
				green_duration = red_duration - yellow_duration;
			}else if (yellow_duration == -1){
				yellow_duration = red_duration - green_duration;
			}else if (red_duration != green_duration + yellow_duration){
				red_duration = DEFAULT_RED;
				green_duration = DEFAULT_GREEN;
				yellow_duration = DEFAULT_YELLOW;

			}

			//change MODE
			led_status = INIT;
			status = INIT;
			mode = MODE1;
		}
		if (is_button_pressed(2)){
			green_duration = led1_value;

			//check available
			if (((red_duration == -1) && (green_duration == -1)) ||
			((green_duration == -1) && (yellow_duration == -1)) ||
			((yellow_duration == -1) && (red_duration == -1))){
				red_duration = DEFAULT_RED;
				green_duration = DEFAULT_GREEN;
				yellow_duration = DEFAULT_YELLOW;
			}else if (red_duration == -1){
				red_duration = green_duration + yellow_duration;
			}else if (green_duration == -1){
				green_duration = red_duration - yellow_duration;
			}else if (yellow_duration == -1){
				yellow_duration = red_duration - green_duration;
			}else if (red_duration != green_duration + yellow_duration){
				red_duration = DEFAULT_RED;
				green_duration = DEFAULT_GREEN;
				yellow_duration = DEFAULT_YELLOW;

			}

			//change MODE
			led_status = INIT;
			status = INIT;
			mode = MODE1;
		}

		led7_segRun();
		break;
	default:
		break;
	}
}
