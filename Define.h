// Define.h

#ifndef _DEFINE_h
#define _DEFINE_h

#include <Arduino.h>
#include <Servo.h>
#include <SPI.h>
#include <Wire.h>

#include "Adafruit_Sensor.h"
#include "Adafruit_LSM9DS0.h"

#include "Motor.h"
#include "Sensor.h"
#include "Timer.h"
#include "PID.h"
#include "process.h"

/******************Global Variable*************/

/*
*	limited between 1100 <-> 2000
*	actualy assign in "process.h"
*/
extern short genMotorSpeed;

#endif //_DEFINE_h

