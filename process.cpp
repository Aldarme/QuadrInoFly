// 
// 
// 

#include "Define.h"

/******************Variable***********************/
float RollX;
float PitchY;

float * pRollX = &RollX;
float * pPitchY = &PitchY;

short genMotorSpeed = 1200;

/********************Function*******************/

/*
* Set motor speed, based on value return by gyro sensor
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

short checkSpeedAdd(short pGlobSpeed, short pGyroSpeed)
{
	if ((pGlobSpeed + pGyroSpeed) > 2000)
	{
		return (2000);
	}
	return (pGlobSpeed + pGyroSpeed);
}

short checkSpeedSupp(short pGlobSpeed, short pGyroSpeed)
{
	if ((pGlobSpeed - pGyroSpeed) < 1100)
	{
		return (1100);
	}
	return (pGlobSpeed - pGyroSpeed);
}
