/*
 * global.h
 *
 *  Created on: Nov 4, 2025
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//MODE
#define INIT 0
#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4

extern int mode;

//lED
#define LED_INIT 0
#define LED0 1
#define LED1 2
#define LED2 3
#define LED3 4

extern int led_status;

//Status of traffic light
#define STATUS1 1
#define STATUS2 2
#define STATUS3 3
#define STATUS4 4

//default time duration
#define DEFAULT_RED 5
#define DEFAULT_GREEN 3
#define DEFAULT_YELLOW 2

//time duration of traffic light
extern int red_duration;
extern int green_duration;
extern int yellow_duration;

//value of 2 led
extern int led1_value;
extern int led2_value;

extern int status;


#endif /* INC_GLOBAL_H_ */
