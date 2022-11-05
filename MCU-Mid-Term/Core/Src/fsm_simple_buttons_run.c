/*
 * fsm_simple_buttons_run.c
 *
 *  Created on: 5 Nov 2022
 *      Author: HP PV
 */


#include "fsm_simple_buttons_run.h"

//bat dau tu trang thai INIT
int status = INIT;

//bat dau tu gia tri 0
int counter = 0;

void fsm_simple_buttons_run(){
	if(timer1_flag == 1){
		HAL_GPIO_TogglePin(Led_Red_GPIO_Port, Led_Red_Pin);
		setTimer1(1000);
	}

	switch(status){
	case INIT:
		//lap tuc chuyen den RESET_MODE
		status = RESET_MODE;
		break;
	case RESET_MODE:
		//doi 10s, neu khong co phan hoi tu cac nut nhan thi chuyen sang trang thai COUNT_DOWN
		if(timer2_flag == 1 && counter != 0){
			status = COUNT_DOWN;
			setTimer2(10000);
		}

		//giu nguyen trang thai khi nhan nut RESET_MODE
		if(isButton1Pressed() == 1){
			counter = 0;
			status = RESET_MODE;
		}

		//chuyen sang tang counter
		if(isButton2Pressed() == 1){
			status = INCMODE;
		}

		//chuyen sang giam counter
		if(isButton3Pressed() == 1){
			status = DECMODE;
		}
		break;
	case COUNT_DOWN:
		//giam gia tri counter, sau khi giam khong la so am,
		//tro ve trang thai COUNT_DOWN de tiep tuc giam counter neu counter khong la so am
		if(timer2_flag == 1 && counter > 0){
			counter--;
			status = COUNT_DOWN;
			setTimer2(1000);
		}

		//ve trang thai RESET_MODE khi COUNT_DOWN toi diem gioi han (counter == 0)
		if(counter == 0){
			status = RESET_MODE;
		}

		//ve trang thai RESET_MODE khi nhan nut RESET_MODE (counter = 0)
		if(isButton1Pressed() == 1){
			counter = 0;
			status = RESET_MODE;
		}

		//chuyen sang tang counter
		if(isButton2Pressed() == 1){
			status = INCMODE;
		}

		//chuyen sang giam counter
		if(isButton3Pressed() == 1){
			status = DECMODE;
		}
		break;
	case INCMODE:
		setTimer2(10000); //10s cho doi phan hoi tu cac nut nhan

		//thuc hien chuc nang tang counter
		if(counter >= 9)
			counter = 0; //xoay vong gia tri counter
		else
			counter++;

		//tro ve trang thai COUNT_DOWN nhung doi 10s,
		//neu nhan INC thi tiep tuc trang thai INCMODE,
		//neu nhan DEC thi chuyen sang trang thai DECMODE
		status = COUNT_DOWN;
		break;
	case DECMODE:
		setTimer2(10000); //10s cho doi phan hoi tu cac nut nhan

		//thuc hien chuc nang giam counter
		if(counter <= 0)
			counter = 9; //xoay vong gia tri counter
		else
			counter--;

		//tro ve trang thai COUNT_DOWN nhung doi 10s,
		//neu nhan INC thi tiep tuc trang thai INCMODE,
		//neu nhan DEC thi chuyen sang trang thai DECMODE
		status = COUNT_DOWN;
		break;
	default:
		break;
	}
	display7SEG(counter);
}
