/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: HP PV
 */


#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

//cac trang thai cua nut nhan RESET
int KeyReg0Button1 = NORMAL_STATE;
int KeyReg1Button1 = NORMAL_STATE;
int KeyReg2Button1 = NORMAL_STATE;
int KeyReg3Button1 = NORMAL_STATE;

//cac trang thai cua nut nhan INC
int KeyReg0Button2 = NORMAL_STATE;
int KeyReg1Button2 = NORMAL_STATE;
int KeyReg2Button2 = NORMAL_STATE;
int KeyReg3Button2 = NORMAL_STATE;

//cac trang thai cua nut nhan DEC
int KeyReg0Button3 = NORMAL_STATE;
int KeyReg1Button3 = NORMAL_STATE;
int KeyReg2Button3 = NORMAL_STATE;
int KeyReg3Button3 = NORMAL_STATE;

//khai bao cac bien dem LONG PRESS, FLAG
int TimeOutForKeyPress1 = 300;
int flagTimeOut1 = 0;

int TimeOutForKeyPress2 = 300;
int flagTimeOut2 = 0;

int TimeOutForKeyPress3 = 300;
int flagTimeOut3 = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyPocess1(){
	button1_flag = 1;
}

void subKeyPocess2(){
	button2_flag = 1;
}

void subKeyPocess3(){
	button3_flag = 1;
}

void getKeyInput1(){
	KeyReg0Button1 = KeyReg1Button1;
	KeyReg1Button1 = KeyReg2Button1;
	KeyReg2Button1 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
	//kiem tra do on dinh cua nut nhan bang viec so sanh lich su cac trang thai cua nut nhan
	if((KeyReg1Button1 == KeyReg0Button1) && (KeyReg1Button1 == KeyReg2Button1)){
		if(KeyReg2Button1 != KeyReg3Button1){
			KeyReg3Button1 = KeyReg2Button1;
			if(KeyReg2Button1 == PRESSED_STATE){
				TimeOutForKeyPress1 = 300;
				subKeyPocess1();
			}
		} else{
			TimeOutForKeyPress1--;
			if(TimeOutForKeyPress1 == 0){
				KeyReg3Button1 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput2(){
	KeyReg0Button2 = KeyReg1Button2;
	KeyReg1Button2 = KeyReg2Button2;
	KeyReg2Button2 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
	//kiem tra do on dinh cua nut nhan bang viec so sanh lich su cac trang thai cua nut nhan
	if((KeyReg1Button2 == KeyReg0Button2) && (KeyReg1Button2 == KeyReg2Button2)){
		if(KeyReg2Button2 != KeyReg3Button2){
			KeyReg3Button2 = KeyReg2Button2;
			if(KeyReg2Button2 == PRESSED_STATE){
				//sau khi nhan giu 3s de tang gia tri counter, chuyen sang nhan giu 1s se tang gia tri counter
				if(flagTimeOut2 == 1)
					TimeOutForKeyPress2 = 100;
				else
					TimeOutForKeyPress2 = 300;
				subKeyPocess2();
			}
		} else{
			TimeOutForKeyPress2--;
			if(TimeOutForKeyPress2 == 0){
				KeyReg3Button2 = NORMAL_STATE;
				flagTimeOut2 = 1;
			}
		}
	}
	else
		//tro ve nhan giu 3s de tang gia tri counter
		flagTimeOut2 = 0;
}

void getKeyInput3(){
	KeyReg0Button3 = KeyReg1Button3;
	KeyReg1Button3 = KeyReg2Button3;
	KeyReg2Button3 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
	//kiem tra do on dinh cua nut nhan bang viec so sanh lich su cac trang thai cua nut nhan
	if((KeyReg1Button3 == KeyReg0Button3) && (KeyReg1Button3 == KeyReg2Button3)){
		if(KeyReg2Button3 != KeyReg3Button3){
			KeyReg3Button3 = KeyReg2Button3;
			if(KeyReg2Button3 == PRESSED_STATE){
				//sau khi nhan giu 3s de giam gia tri counter, chuyen sang nhan giu 1s se giam gia tri counter
				if(flagTimeOut3 == 1)
					TimeOutForKeyPress3 = 100;
				else
					TimeOutForKeyPress3 = 300;
				subKeyPocess3();
			}
		} else{
			TimeOutForKeyPress3--;
			if(TimeOutForKeyPress3 == 0){
				KeyReg3Button3 = NORMAL_STATE;
				flagTimeOut3 = 1;
			}
		}
	}
	else
		//tro ve nhan giu 3s de giam gia tri counter
		flagTimeOut3 = 0;
}
