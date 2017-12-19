// 
// 
// 

#include "Define.h"

static int crntThrottle	= 0;
static int crntPitch	= 0;
static int crntRoll		= 0;

static void PrintToSerial(String pString)
{
	delay(10);
	Serial.print(pString + '\n');
}

/*
*	set general speed, get from controller, of quadricoter
*/
void throttleCb(int pThrottle)
{
	int throttle = map(pThrottle, -32767, 32768, 1100, 2000);
	setGenSpeed(throttle);
}

/*
*	set Pitch, get from controller, of quadricoter 
*/
void PitchCb(int pPtich)
{
	int pitch = map(pPtich, -32768, 32767, 0, 200);
	setSpeedMotors(float(pitch), 0.0f);
}

/*
*	set Roll, get from controller, of quadricoter 
*/
void RollCb(int pRoll)
{
	int roll = map(pRoll, -32768, 32767, 0, 200);
	setSpeedMotors(0.0f, float(roll));
}

/*
*	send current software version throught serial com
*/
void VersionCb(int a)
{
	PrintToSerial(SW_VERSION);
}

