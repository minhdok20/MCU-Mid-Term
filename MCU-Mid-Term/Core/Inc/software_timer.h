/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP PV
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag; //blinky led red
extern int timer2_flag; //count down and wait 10s
extern int timer3_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void clearTimer1();
void clearTimer2();
void clearTimer3();

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
