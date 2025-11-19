/*
 * scheduler.h
 *
 *  Created on: Nov 10, 2025
 *      Author: User
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define SCH_MAX_TASKS	40
#define NO_TASK_ID 255
typedef struct{
	void (*pTask)(void);
	uint32_t	Delay;
	uint32_t	Period;
	uint8_t		RunMe;
	uint32_t	TaskID;
}sTasks;


void SCH_Init(void);

unsigned char SCH_Add_Task(void(*pFunction)(),
				   uint32_t DELAY,
				   uint32_t PERIOD); //Set timer

void SCH_Update(void);//timerRun
void SCH_Dispatch_Tasks(void);//Kiem tra (while 1)

//void SCH_Delete(uint32_t ID);
unsigned char SCH_Delete_Task(const uint8_t TASK_INDEX);
#endif /* INC_SCHEDULER_H_ */
