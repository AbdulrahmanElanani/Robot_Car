/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */

#include "Autonomous_Car/Autonomous_Car.h"
#include "Control_Car/Control_car.h"
int main(void) {
	u8 Loc_u8Mode='X';
	APP_Autonomous_Car_voidInit();
	Control_Car_Init();
	while(1){
	MCAL_UART_UARTReceive(&Loc_u8Mode);
	if(Loc_u8Mode=='C'){
		Control_Car_App();
	}else if(Loc_u8Mode=='H'){
		APP_Autonomous_Car_voidApp();
	}else{
		//Nothing
	}
	}

}
