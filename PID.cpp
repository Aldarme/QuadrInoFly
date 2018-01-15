
#include "Define.h"

/*--------------Preprocessor---------*/
#define KP 1
#define KI 0.5
#define KD 0.2

#define deposit 0

/*------------Function---------------*/

/*
*	Controller P
*	return type: short
*/
short controllerP(float * pDatasensor)
{
	short P = (short)((deposit - *pDatasensor) * KP);
	//Serial.println(P);
	return P;
	
	/*
	* Positif -> Negatif
	* Negatif -> positif
	* Range integer value: [-160 ; 160] 
	*/
}

/*
*	Controller PI
*	return type: Short
*/
short controllerPI(float * pDatasensor, float pTabSum)
{
	return (short)( ((deposit - *pDatasensor) * KP)
					+ (pTabSum * KI) );
}

/*
*	Controller PID
*	return type: Short
*/
short controllerPID(float * pDatasensor, float pTabSum)
{
	return (short)(((deposit - *pDatasensor) * KP)
					+ (pTabSum * KI)
					+ (getInterval() * KD) );
}




