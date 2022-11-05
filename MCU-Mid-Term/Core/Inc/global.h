/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP PV
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"

#define INIT		0
#define RESET_MODE	1
#define COUNT_DOWN	2

#define INCMODE		10
#define DECMODE		11

extern int status;

extern int counter;

void display7SEG(int num);

#endif /* INC_GLOBAL_H_ */
