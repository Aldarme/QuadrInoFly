/****************************************************

Use Default connection for I2C:
Connect Motor A to pin 6
Connect Motor B to pin 5
Connect Motor C to pin 10
Connect Motor D to pin 9
****************************************************/

#include "Define.h"

/******************Preprocessor****************/


/*******************Variable******************/
Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;



/*******************Function******************/
/*
*   Init & Configure ESC
*   Use pwm Pin 5,6,9,10
*/
void configMotor()
{
    ESC1.attach(5);
    ESC2.attach(6);
    ESC3.attach(10);
    ESC4.attach(9);

    ESC1.writeMicroseconds(1000);
    ESC2.writeMicroseconds(1000);
    ESC3.writeMicroseconds(1000);
    ESC4.writeMicroseconds(1000);

    //After setting initialisation, ESC need a delay before setting speed for motor
    delay(2000);
}

/*
*   Allow to set motor's speed
*/
void setSpeedGlobal(int pPpm)
{
    ESC1.writeMicroseconds(pPpm);
	ESC2.writeMicroseconds(pPpm);
	ESC3.writeMicroseconds(pPpm);
	ESC4.writeMicroseconds(pPpm);
}

void setSpeedA(int pPpm)
{
    ESC1.writeMicroseconds(pPpm);
}

void setSpeedB(int pPpm)
{
	ESC2.writeMicroseconds(pPpm);
}

/*
*   Allow to set motor's speed
*/
void setSpeedC(int pPpm)
{
	ESC3.writeMicroseconds(pPpm);
}

void setSpeedD(int pPpm)
{
	ESC4.writeMicroseconds(pPpm);
}
