// process.h

#ifndef _PROCESS_h
#define _PROCESS_h

void setGenSpeed(int pSpeed);
void setSpeedMotors();
void setSpeedMotors(float pControllerPitch, float pControllerRoll);

short checkSpeedAdd(short pGlobSpeed, short pGyroSpeed);
short checkSpeedSupp(short pGlobSpeed, short pGyroSpeed);

#endif //_PROCESS_h

