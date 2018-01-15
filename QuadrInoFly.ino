
/**********************************************
Insert information about licence
**********************************************/

#include "Define.h"

/***************Prepocessor*******************/


/*******************Variable******************/
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

//byte varCompteur = 0; // cout var for ISR

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
//const long interval = 10; //time period to get value fron sensor in millisecond

unsigned long currentMillisRF = 0;
unsigned long previousMillisRF = 0;
//const long intervalRF = 100; //time period to get value fron RF controller in millisecond

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

	/*RF Throttle Config*/
	AxeThrottle(4);	//declare throttle on PIN4
	AxePitch(3);
	AxeRoll(2);
	
}

void loop()
{
	//Returns the number of milliseconds since the Arduino board began running the current program.
	currentMillis = millis();
	currentMillisRF = currentMillis;
	
	//set Motors speed, depending on values return gy Gyro
	setSpeedMotors();

	if(currentMillis - previousMillis >= getInterval())
	{
		//save the last time you blinked the LED
		previousMillis = currentMillis;

		//get data from sensor (gyro)
		SensorGet();
	 }

	if(currentMillisRF - previousMillisRF >= getIntervalRf())
	{
		previousMillisRF = currentMillisRF;

		/*Serial.println("throttle input: ");
		Serial.println(i);*/
		setGenSpeed(readThrottle());
		readPitch();
		readRoll();
	}
}



/*
Serial Read Pin INPUT interrupt*/
//void serialEvent() {
//	while (Serial.available())
//	{
//		//get data from controller
//		serialAnalyser();
//	}
//}

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