// process.h

#ifndef _PROCESS_h
#define _PROCESS_h

void setGenSpeed(int pSpeed);
void setSpeedMotors();
void setSpeedMotors(float pControllerPitch, float pControllerRoll);

int checkSpeedAdd(int pGlobSpeed, int pGyroSpeed);
int checkSpeedSupp(int pGlobSpeed, int pGyroSpeed);

unsigned long getInterval();
unsigned long getIntervalRf();
short getGenMotorSpeed();

#endif //_PROCESS_h

