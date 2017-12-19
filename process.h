// process.h

#ifndef _PROCESS_h
#define _PROCESS_h

void setGenSpeed(int pSpeed);
void setSpeedMotors();
void setSpeedMotors(float pControllerPitch, float pControllerRoll);

int checkSpeedAdd(int pGlobSpeed, int pGyroSpeed);
int checkSpeedSupp(int pGlobSpeed, int pGyroSpeed);

#endif //_PROCESS_h

