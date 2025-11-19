/*
 * button.c
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#include "button.h"

//define
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define DURATION 500
#define TICK 10

//debouncing
int keyReg0[N0_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[N0_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[N0_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

//buffer button
int bufferButton[N0_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

//button flag & timer for key press
int button_flag[N0_OF_BUTTONS];
int timerforkeypress[N0_OF_BUTTONS];

//is button press
int is_button_pressed(int index){
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

//get input
void getKeyInput(){

	for (int i = 0; i < N0_OF_BUTTONS; i++){
		keyReg2[i] = keyReg1[i];
		keyReg1[i] = keyReg0[i];
	}

	keyReg0[0] = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
	keyReg0[1] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
	keyReg0[2] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);

	for (int i = 0; i < N0_OF_BUTTONS; i++){
		if ((keyReg1[i] == keyReg0[i]) && (keyReg2[i] == keyReg1[i])){
			if (bufferButton[i] != keyReg0[i]){
				bufferButton[i] = keyReg0[i];
				if (bufferButton[i] == PRESSED_STATE){
					button_flag[i] = 1;
					timerforkeypress[i] = DURATION / TICK;
				}
			} else{
				timerforkeypress[i]--;
				if (timerforkeypress[i] == 0){
					bufferButton[i] = NORMAL_STATE;
				}
			}
		}
	}
}
