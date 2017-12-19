
/**********************************************
Insert information about licence
**********************************************/

#include "Define.h"

/***************Prepocessor*******************/


/*******************Variable******************/
byte varCompteur = 0; // cout var for ISR

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;;
const long interval = 10; //time period to get value fron sensor in millisecond

void setup()
{
	/*Init serial com at 9600 Baud*/
	Serial.begin(9600);	

	/*Motor configuration*/
	configMotor();
	
	/*Sensor Configuration*/
	SensorInit();
	
	/*Timer2 config*/
    //Timer2Config();	
	
}

void loop()
{
	//Returns the number of milliseconds since the Arduino board began running the current program.
	currentMillis = millis();

	//set Motors speed, depending on values return gy Gyro
	setSpeedMotors();

	if (currentMillis - previousMillis >= interval)
	{
		//save the last time you blinked the LED
		previousMillis = currentMillis;

		//get data from sensor (gyro)
		SensorGet();

		//get data from controller
	    serialAnalyser();
	 }
}



/*
*Reserve interrupt routine service (ISR) by Arduino
*/
//ISR(TIMER2_OVF_vect)
//{
//	TCNT2 = 256 - 250; // 250 x 16 µS = 4 ms
//	if (varCompteur++ > 25)// 25 * 4 ms = 100 ms (half-period)
//	{
//		varCompteur = 0;
//		//Serial.println("debugFromISR");
//		serialAnalyser();
//	}
//}