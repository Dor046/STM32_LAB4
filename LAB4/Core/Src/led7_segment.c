/*
 * led7_segment.c
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */


#include "led7_segment.h"

void numToLed(int num){
	switch(num){
	case 0:
		ZERO();
		break;
	case 1:
		ONE();
		break;
	case 2:
		TWO();
		break;
	case 3:
		THREE();
		break;
	case 4:
		FOUR();
		break;
	case 5:
		FIVE();
		break;
	case 6:
		SIX();
		break;
	case 7:
		SEVEN();
		break;
	case 8:
		EIGHT();
		break;
	case 9:
		NINE();
		break;
	default:
		break;
	}
}
void CLEAR(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, SET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, SET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, SET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
}
void ZERO(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
}
void ONE(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, SET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
}
void TWO(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, SET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
}
void THREE(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
}
void FOUR(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, SET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
}
void FIVE(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, SET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
}
void SIX(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, SET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
}
void SEVEN(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, SET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, SET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, SET);
}
void EIGHT(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, RESET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
}
void NINE(){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
}
