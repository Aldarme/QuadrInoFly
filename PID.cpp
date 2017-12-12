
#include "Define.h"

/*--------------Preprocessor---------*/
#define KP_X 1
#define KI_X 0
#define KD_X 0

#define KP_Y 0
#define KI_Y 0
#define KD_Y 0

#define deposit 0

/*-----------------Variable----------*/

float X_sum = 0;
float Y_sum = 0;
float * pX_sum = &X_sum;
float * pY_sum = &Y_sum;


/*------------Function---------------*/

/*
*	Controller P
*	return type: short
*/
short controllerP(float * pDatasensor)
{
	short P = (short)((deposit - *pDatasensor) * KP_X);
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
short controllerPI(float * pDatasensor)
{
	*pX_sum += *pDatasensor; //ask if it is a better idea to calcule integral on the 5 last value
	return (short)( ((deposit - *pDatasensor) * KP_X) + (*pX_sum * KI_X) );
}


