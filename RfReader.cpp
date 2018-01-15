
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

void AxePitch(int pinCanal)
{
	pitchPin = pinCanal;
	pinMode(pitchPin, INPUT);
}

void AxeRoll(int pinCanal)
{
	rollPin = pinCanal;
	pinMode(rollPin, INPUT);
}

int readThrottle()
{
	throttleRead = pulseIn(throttlePin, HIGH, PERIODE);
	return map(throttleRead, 1000, 2000, 1100, 2000);
}

int readPitch()
{
	pitchRead = pulseIn(pitchPin, HIGH, PERIODE);
	short temp = map(pitchRead, 1000, 2000, 1100, 2000);
	if (temp >= 1550)
	{
		short vPitch = 0;
		vPitch = map(temp, 1550, 2000, 1100, 2000);

		setSpeedA(checkSpeedSupp(getGenMotorSpeed(), vPitch));
		setSpeedC(checkSpeedSupp(getGenMotorSpeed(), vPitch));

		setSpeedB(checkSpeedAdd(getGenMotorSpeed(), vPitch));
		setSpeedD(checkSpeedAdd(getGenMotorSpeed(), vPitch));
	}
	else
	{
		short vPitch = 0;
		vPitch = map(temp, 1550, 1100, 1100, 2000);

		setSpeedB(checkSpeedSupp(getGenMotorSpeed(), vPitch));
		setSpeedD(checkSpeedSupp(getGenMotorSpeed(), vPitch));

		setSpeedA(checkSpeedAdd(getGenMotorSpeed(), vPitch));
		setSpeedC(checkSpeedAdd(getGenMotorSpeed(), vPitch));
	}
}

int readRoll()
{
	rollRead = pulseIn(rollPin, HIGH, PERIODE);
	int temp = map(rollRead, 1000, 2000, 1100, 2000);
	if (temp >= 1550)
	{
		short vRoll = 0;
		vRoll = map(temp, 1550, 2000, 1100, 2000);

		setSpeedA(checkSpeedSupp(getGenMotorSpeed(), vRoll));
		setSpeedD(checkSpeedSupp(getGenMotorSpeed(), vRoll));

		setSpeedB(checkSpeedAdd(getGenMotorSpeed(), vRoll));
		setSpeedC(checkSpeedAdd(getGenMotorSpeed(), vRoll));
	}
	else
	{
		short vRoll = 0;
		vRoll = map(temp, 1550, 2000, 1100, 2000);

		setSpeedB(checkSpeedSupp(getGenMotorSpeed(), vRoll));
		setSpeedC(checkSpeedSupp(getGenMotorSpeed(), vRoll));

		setSpeedA(checkSpeedAdd(getGenMotorSpeed(), vRoll));
		setSpeedD(checkSpeedAdd(getGenMotorSpeed(), vRoll));
	}
}

