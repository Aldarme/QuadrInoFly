
#include "Define.h"

#define PERIODE 20000 /*PWM signal Periode, in output sensor */
#define PWM_MIN 1100
#define PWM_MAX 2000

int throttlePin = 0;
int pitchPin = 0;
int rollPin = 0;

int throttleRead = 0;
int pitchRead = 0;
int rollRead = 0;

void AxeThrottle(int pinCanal)
{
	throttlePin = pinCanal;
	pinMode(throttlePin, INPUT);
}

void AxePitch(int pinCanal, int minVal, int maxVal)
{
	pitchPin = pinCanal;
	pinMode(pitchPin, INPUT);
}

void AxeRoll(int pinCanal, int minVal, int maxVal)
{
	rollPin = pinCanal;
	pinMode(rollPin, INPUT);
}

int readThrottle()
{
	throttleRead = pulseIn(throttlePin, HIGH, PERIODE);
	return map(throttleRead, 1000, 2000, 1100, 2000);
	/*if (throttleRead > PWM_MIN && throttleRead < PWM_MAX)
	{		
		return throttleRead;
	}
	else
	{
		return 1;
	}*/
}

int readPitch()
{
	pitchRead = pulseIn(pitchPin, HIGH, PERIODE);
	if (pitchRead > PWM_MIN && pitchRead < PWM_MAX)
	{
		return pitchRead;
	}
	else
	{
		return 1;
	}
}

int readRoll()
{
	rollRead = pulseIn(rollPin, HIGH, PERIODE);
	if (rollRead > PWM_MIN && rollRead < PWM_MAX)
	{
		return rollRead;
	}
	else
	{
		return 1;
	}
}

