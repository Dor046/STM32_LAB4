/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#include "software_timer.h"

#define TICK 10
#define N0_OF_TIMER 5

int timer_counter[N0_OF_TIMER];
int timer_flag[N0_OF_TIMER];

void setTimer(int index, int counter){
	timer_counter[index] = counter / TICK;
	timer_flag[index] = 0;
}

void clearTimer(int index){
	timer_counter[index] = 0;
	timer_flag[index] = 0;
}

void timerRun(){
	for (int i = 0; i < N0_OF_TIMER; i++){
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
