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
	setGenSpeed(pThrottle);
}

/*
*	set Pitch, get from controller, of quadricoter 
*/
void PitchCb(int pPtich)
{
	setSpeedMotors(float(pPtich), 0.0f);
}

/*
*	set Roll, get from controller, of quadricoter 
*/
void RollCb(int pRoll)
{
	setSpeedMotors(0.0f, float(pRoll));
}

/*
*	send current software version throught serial com
*/
void VersionCb(int)
{
	PrintToSerial(SW_VERSION);
}

