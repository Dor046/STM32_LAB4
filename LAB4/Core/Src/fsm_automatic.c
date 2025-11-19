/*
 * fsm_automatic.c
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#include "fsm_automatic.h"


//led_buffer
int led_buffer[4];

//update 4led7seg
void update_led7seg(){
	led_buffer[0] = led1_value / 10;
	led_buffer[1] = led1_value % 10;
	led_buffer[2] = led2_value / 10;
	led_buffer[3] = led2_value % 10;
}

void update_led_for_1s(){
	//timer of realtime for led7seg
	if (timer_flag[2] == 1){
		led1_value--;
		led2_value--;
		update_led7seg();
		setTimer(2, 1000);
	}
}

//led7seg run
void led7_segRun(){

	//led status
	switch (led_status){
	case LED_INIT:
		update_led7seg();
		led_status = LED0;
		setTimer(1, 250);
		break;
	case LED0:
		//led0 ON
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		numToLed(led_buffer[0]);

		//change status
		if (timer_flag[1] == 1){
			led_status = LED1;
			setTimer(1, 250);
		}
		break;
	case LED1:
		//led1 ON
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		numToLed(led_buffer[1]);

		//change status
		if (timer_flag[1] == 1){
			led_status = LED2;
			setTimer(1, 250);
		}
		break;
	case LED2:
		//led2 ON
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		numToLed(led_buffer[2]);

		//change status
		if (timer_flag[1] == 1){
			led_status = LED3;
			setTimer(1, 250);
		}
		break;
	case LED3:
		//led3 ON
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		numToLed(led_buffer[3]);

		//change status
		if (timer_flag[1] == 1){
			led_status = LED0;
			setTimer(1, 250);
		}
		break;
	default:
		break;
	}
}

//traffic light run
void traffic_lightRun(){

	//traffic light status
	switch (status){
	case INIT:

		//2 led value
		led1_value = green_duration;
		led2_value = red_duration;
		update_led7seg();

		setTimer(2, 1000);

		status = STATUS1;
		break;
	case STATUS1: //GREEN RED
		//traffic light
		GREEN_1();
		RED_2();

		//change status
		if (led1_value == 0){
			led1_value = yellow_duration;
			led2_value = yellow_duration;
			update_led7seg();
			status = STATUS2;
		}
		break;
	case STATUS2: //YELLOW RED
		//traffic light
		YELLOW_1();
		RED_2();

		//change status
		if (led1_value == 0){
			led1_value = red_duration;
			led2_value = green_duration;
			update_led7seg();
			status = STATUS3;
		}
		break;
	case STATUS3: //RED GREEN
		//traffic light
		RED_1();
		GREEN_2();

		//change status
		if (led2_value == 0){
			led1_value = yellow_duration;
			led2_value = yellow_duration;
			update_led7seg();
			status = STATUS4;
		}
		break;
	case STATUS4: //RED YELLOW
		//traffic light
		YELLOW_2();
		RED_1();

		//change status
		if (led2_value == 0){
			led1_value = green_duration;
			led2_value = red_duration;
			update_led7seg();
			status = STATUS1;
		}
		break;
	default:
		break;
	}
}

//AUTO
void fsm_automatic(){
	traffic_lightRun();
	led7_segRun();
	update_led_for_1s();
}
