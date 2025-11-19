/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

// Timer flags and counters
extern int timer_flag[];
extern int timer_counter[];

//
void setTimer(int index, int counter);
void clearTimer(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
