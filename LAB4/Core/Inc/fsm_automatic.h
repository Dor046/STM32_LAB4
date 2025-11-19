/*
 * fsm_automatic.h
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "software_timer.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "global.h"

void update_led7seg();
void led7_segRun();
void fsm_automatic();

#endif /* INC_FSM_AUTOMATIC_H_ */
