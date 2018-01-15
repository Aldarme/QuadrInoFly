// RfReader.h

#ifndef _RFREADER_h
#define _RFREADER_h

void AxeThrottle(int pinCanal);
void AxePitch(int pinCanal);
void AxeRoll(int pinCanal);

int readThrottle();
int readPitch();
int readRoll();

#endif

