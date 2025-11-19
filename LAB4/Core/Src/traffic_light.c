/*
 * traffic_light.c
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#include "traffic_light.h"

void RED_1(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
}

void GREEN_1(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
}

void YELLOW_1(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
}

void RED_2(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}

void GREEN_2(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}

void YELLOW_2(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
}

//Blink
void blink_RED_1(){
	if(timer_flag[3]==1){
	HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
	setTimer(3, 250);
	}
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
}

void blink_GREEN_1(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	if(timer_flag[3]==1){
	HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
	setTimer(3, 250);
	}
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
}

void blink_YELLOW_1(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	if(timer_flag[3]==1){
	HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
	setTimer(3, 250);
	}
}

void blink_RED_2(){
	if(timer_flag[4]==1){
	HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
	setTimer(4, 250);
	}
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}

void blink_GREEN_2(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	if(timer_flag[4]==1){
	HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
	setTimer(4, 250);
	}
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
}

void blink_YELLOW_2(){
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
	if(timer_flag[4]==1){
	HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
	setTimer(4, 250);
	}
}

