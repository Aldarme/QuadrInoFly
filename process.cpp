// 
// 
// 

#include "Define.h"

/******************Variable***********************/
#define INTERVAL	10		//time period to get value fron sensor in millisecond
#define INTERVAL_RF	100		//time period to get value fron RF controller in millisecond

float RollX;
float PitchY;

float * pRollX = &RollX;
float * pPitchY = &PitchY;

//1100 -> motor activate, no rotation
//2000 -> motor activate, max speed
int genMotorSpeed = 1100;

/********************Function*******************/

/*
*	Set general motor speed, based on value return by controller
*/
void setGenSpeed(int pSpeed)
{
	genMotorSpeed = pSpeed;
	setSpeedGlobal(genMotorSpeed);
}

/*
*	Set motor speed, based on value return by gyro sensor
*/
void setSpeedMotors()
{
	*pRollX	 = GiroX_Read();
	*pPitchY = GiroY_Read();

	//controllerP(pRollX);

	if ( *pRollX < 0)
	{
		setSpeedC(checkSpeedSupp(genMotorSpeed, controllerP(pRollX)));
		setSpeedD(checkSpeedAdd(genMotorSpeed, controllerP(pRollX)));
		
	}
	else 
	{
		setSpeedC(checkSpeedSupp(genMotorSpeed, controllerP(pRollX)));
		setSpeedD(checkSpeedAdd(genMotorSpeed, controllerP(pRollX)));
	}

	if (*pPitchY < 0)
	{
		setSpeedA(checkSpeedSupp(genMotorSpeed, controllerP(pPitchY)));
		setSpeedB(checkSpeedAdd(genMotorSpeed, controllerP(pPitchY)));
	}
	else {
		setSpeedA(checkSpeedSupp(genMotorSpeed, controllerP(pPitchY)));
		setSpeedB(checkSpeedAdd(genMotorSpeed, controllerP(pPitchY)));
	}
}

/*
*	Controller set motor speed (based on value return by controller, in our case "XBOX controller"
*/
void setSpeedMotors(float pControllerPitch, float pControllerRoll )
{
	*pRollX = pControllerRoll;
	*pPitchY = pControllerPitch;

	//controllerP(pRollX);

	if (*pRollX < 0)
	{
		setSpeedC(checkSpeedSupp(genMotorSpeed, controllerP(pRollX)));
		setSpeedD(checkSpeedAdd(genMotorSpeed, controllerP(pRollX)));
	}
	else
	{
		setSpeedC(checkSpeedSupp(genMotorSpeed, controllerP(pRollX)));
		setSpeedD(checkSpeedAdd(genMotorSpeed, controllerP(pRollX)));
	}

	if (*pPitchY < 0)
	{
		setSpeedA(checkSpeedSupp(genMotorSpeed, controllerP(pPitchY)));
		setSpeedB(checkSpeedAdd(genMotorSpeed, controllerP(pPitchY)));
	}
	else {
		setSpeedA(checkSpeedSupp(genMotorSpeed, controllerP(pPitchY)));
		setSpeedB(checkSpeedAdd(genMotorSpeed, controllerP(pPitchY)));
	}
}

int checkSpeedAdd(int pGlobSpeed, int pGyroSpeed)
{
	if ((pGlobSpeed + pGyroSpeed) > 2000)
	{
		return (2000);
	}
	return (pGlobSpeed + pGyroSpeed);
}

int checkSpeedSupp(int pGlobSpeed, int pGyroSpeed)
{
	if ((pGlobSpeed - pGyroSpeed) < 1100)
	{
		return (1100);
	}
	return (pGlobSpeed - pGyroSpeed);
}

/*
*	Return time period to get value fron sensor in millisecond
*/
unsigned long getInterval()
{
	return INTERVAL;
}

/*
*	Return time period to get value fron RF controller in millisecond
*/
unsigned long getIntervalRf()
{
	return INTERVAL_RF;
}

short getGenMotorSpeed()
{
	return genMotorSpeed;
}
