/*
 * button.h
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

//NUMBER OF BUTTON
#define N0_OF_BUTTONS 3

//check pressed button
int is_button_pressed(int index);

//run with timer
void getKeyInput();

#endif /* INC_BUTTON_H_ */
