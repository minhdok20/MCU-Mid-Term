/*
 * global.c
 *
 *  Created on: Nov 4, 2022
 *      Author: HP PV
 */


#include "global.h"

//hien thi led 7 doan
void display7SEG(int num) {
	int dis_arr[10] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
	int bit_var, var2;

	var2 = ~dis_arr[num];
	bit_var = var2 & 0x01;
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, bit_var);

	bit_var = (var2>>1) & 0x01;
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, bit_var);

	bit_var = (var2>>2) & 0x01;
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, bit_var);

	bit_var = (var2>>3) & 0x01;
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, bit_var);

	bit_var = (var2>>4) & 0x01;
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, bit_var);

	bit_var = (var2>>5) & 0x01;
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, bit_var);

	bit_var = (var2>>6) & 0x01;
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, bit_var);
}
