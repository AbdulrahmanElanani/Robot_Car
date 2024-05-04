/*
 * Control_car.c
 *
 *  Created on: May 1, 2024
 *      Author: TOP_WORLD
 */
#include "Control_Car.h"
void APP_Control_Car_Init(void) {
	//Init Buzzer
	HAL_Buzzer_u8BuzzerInit(PortA, Pin3);
	//Init LCD
	HAL_LCD_u8LCDInit();
	//Init Servo Motor
	HAL_SM_voidSMInit();
	//Init UltraSonic Sensor
	HAL_Ultrasonic_Sensor_voidInit();
	//Init H_Bridge
	HAL_void_H_BridgeInit();
	//Leds
	HAL_LED_u8LedInit(PortA, Pin0);
	HAL_LED_u8LedInit(PortA, Pin1);
	//UART
	MCAL_UART_UARTInit();
}
void APP_Control_Car_App(void) {

	u8 Loc_u8state = 0;
	u8 Loc_u8Event = 'N';
	f32 Loc_f32distance = 0;
	//	Initially Set Servo Angle 90
	HAL_SM_voidSMSetAngle(START_ANGLE);
	//Light Front LEDS
	HAL_LED_u8LedMode(PortA, Pin0, LED_ON);
	while (1) {
		MCAL_UART_UARTReceive(&Loc_u8Event);
		if (Loc_u8Event == 'F') {
			HAL_LED_u8LedMode(PortA,Pin0,LED_ON);
			HAL_LED_u8LedMode(PortA,Pin1,LED_OFF);
			//Loc_u8state = 1;
			//HAL_Ultrasonic_Sensor_voidCalcDistancse(&Loc_f32distance);
			//_delay_ms(50);
			//if (Loc_f32distance > 30) {
				//HAL_LCD_u8Clear();
			//	HAL_LCD_u8SendString("Moving Front...");
				//HAL_LCD_u8GoTo(Second_Line, NUM0);
				//HAL_LCD_u8SendString("Distance: ");
				//_delay_ms(50);
				HAL_void_H_BridgeFront(MAX_SPEED);
//			} else if (Loc_f32distance <= 30) {
//				HAL_void_H_BridgeStop(NUM0);
//			}
			//else {
			//NOTHING
			//}
		} else if (Loc_u8Event == 'B') {
			//Loc_u8state = 1;
			//HAL_LCD_u8Clear();
			//HAL_LCD_u8SendString("Moving Back...");
			HAL_void_H_BridgeBack(MAX_SPEED);
			HAL_LED_u8LedMode(PortA,Pin1,LED_ON);
			//_delay_ms(1000);
		} else if (Loc_u8Event == 'L') {
			//Loc_u8state = 0;
		//	HAL_LCD_u8Clear();
			//HAL_LCD_u8SendString("Moving Left...");
			HAL_void_H_BridgeCCW(MAX_SPEED);
			//_delay_ms(900);

		} else if (Loc_u8Event == 'R') {
			//Loc_u8state = 0;
			//HAL_LCD_u8Clear();
			//HAL_LCD_u8SendString("Moving Right...");
			HAL_void_H_BridgeCW(MAX_SPEED);
			//_delay_ms(900);

		} else if (Loc_u8Event == 'S') {
			//HAL_LCD_u8Clear();
			//HAL_LCD_u8SendString("Stoped...");
			HAL_void_H_BridgeStop(NUM0);
//			if (Loc_u8state == 0) {
//				Loc_u8state = 1;
//				HAL_Ultrasonic_Sensor_voidCalcDistancse(&Loc_f32distance);
//				if (Loc_f32distance > 30) {
//					HAL_LCD_u8Clear();
//					HAL_LCD_u8SendString("Moving Front...");
//					HAL_LCD_u8GoTo(Second_Line, NUM0);
//					HAL_LCD_u8SendString("Distance: ");
//					_delay_ms(50);
//					HAL_void_H_BridgeFront(MAX_SPEED);
//				} else if (Loc_f32distance <= 30) {
//					HAL_void_H_BridgeStop(NUM0);
//				} else {
//					//NOTHING
//				}
//			} else if (Loc_u8state == 1) {
//				Loc_u8state = 0;
//				HAL_void_H_BridgeStop(NUM0);
//			} else {
//				//NOTHING
//			}

		} else if (Loc_u8Event == 'W') {
			HAL_LED_u8LedMode(PortA, PIN0, LED_ON);
		} else if (Loc_u8Event == 'w') {
			HAL_LED_u8LedMode(PortA, PIN0, LED_OFF);
		} else if (Loc_u8Event == 'U') {
			HAL_LED_u8LedMode(PortA, PIN1, LED_ON);
		} else if (Loc_u8Event == 'u') {
			HAL_LED_u8LedMode(PortA, PIN1, LED_OFF);
		} else if (Loc_u8Event == 'V') {
			HAL_Buzzer_u8BuzzerMode(PortA, Pin3, Buzzer_ON);
		} else if (Loc_u8Event == 'v') {
			HAL_Buzzer_u8BuzzerMode(PortA, Pin3, Buzzer_OFF);
		} else if (Loc_u8Event == 'X') {
			APP_Autonomous_Car_voidApp();
		} else {
			//NOTHING
		}
	}

}
