/****************************************************
This code is based on "sensorapi.ino" file, available
in "Adafruit_LSM9DS0_Library-master", provide by
Kevin Townsend for Adafruit Industries.

Use Default connection for I2C:
    Connect SCL to analog 5
    Connect SDA to analog 4
    Connect VDD to 5V DC
    Connect GROUND to common ground*
****************************************************/

#include "Define.h"

/*******************preprocessor******************/

#define TABGYROXSIZE 30
#define TABGYROYSIZE 30


/*******************Variable******************/

	/* Assign a unique base ID for this sensor */
	Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(1000);  // Use I2C, ID #1000

	float tabGyroX[TABGYROXSIZE] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
									 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
									 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	float tabGyroY[TABGYROYSIZE] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
									 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
									 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

/*******************Function******************/
/*
    Configures the gain and integration time for the TSL2561
*/
void SensorSensitivityConf()
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);

  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

/*
    Arduino setup function (automatically called at startup)
*/
void SensorInit()
{
	//Serial.println(F("LSM9DS0 9DOF Sensor Test\r\n"));
	
    /* Initialise the sensor */
    if(!lsm.begin())
    {
		/* There was a problem detecting the LSM9DS0 ... check your connections */
		Serial.print(F("Ooops, no LSM9DS0 detected ... Check your wiring or I2C ADDR!\r\n"));
		while(1);
    }

    Serial.println("Found LSM9DS0 9DOF\r\n");

    /* Setup the sensor gain and integration time */
    SensorSensitivityConf();	
}

/*
    Display value from accelerometer, Giroscope & magnetometer
*/
void SensorValDisplay()
{
    sensors_event_t accel, mag, gyro, temp;
    lsm.getEvent(&accel, &mag, &gyro, &temp);

    // print out accelleration data
    Serial.print("Accel X: "); Serial.print(accel.acceleration.x); Serial.print(" ");
    Serial.print("  \tY: "); Serial.print(accel.acceleration.y);       Serial.print(" ");
    Serial.print("  \tZ: "); Serial.print(accel.acceleration.z);     Serial.println("  \tm/s^2");

    // print out magnetometer data
    Serial.print("Magn. X: "); Serial.print(mag.magnetic.x); Serial.print(" ");
    Serial.print("  \tY: "); Serial.print(mag.magnetic.y);       Serial.print(" ");
    Serial.print("  \tZ: "); Serial.print(mag.magnetic.z);     Serial.println("  \tgauss");

    // print out gyroscopic data
    Serial.print("Gyro  X: "); Serial.print(gyro.gyro.x); Serial.print(" ");
    Serial.print("  \tY: "); Serial.print(gyro.gyro.y);       Serial.print(" ");
    Serial.print("  \tZ: "); Serial.print(gyro.gyro.z);     Serial.println("  \tdps");

    // print out temperature data
    Serial.print("Temp: "); Serial.print(temp.temperature); Serial.println(" *C");

    Serial.println("**********************\n");
}

/*
*   Get Value from Gyro
*/
void SensorGet()
{	
	//get new value of sensors
	sensors_event_t accel, mag, gyro, temp;
	lsm.getEvent(&accel, &mag, &gyro, &temp);

    GiroX_Feed(gyro.gyro.x);
	GiroY_Feed(gyro.gyro.y);
}

/*
*   Feed giroX circular buffer
*/
void GiroX_Feed(float pX)
{
	static short index = 0;

	if (index >= (TABGYROXSIZE-1))
	{
		index = 0;
	}

	tabGyroX[index] = pX;
	index++;
}

/*
*   Read ROll/giroX circular buffer
*	return type: short
*/
float GiroX_Read()
{
	return (avrgTab(tabGyroX, TABGYROXSIZE));

	/*short index = 0;

	for(index; index < 30; index++)
	{
		Serial.println(tabGyroX[index]);
	}
	Serial.println("\r\n\r\n");*/
}

/*
*   Feed giroY circular buffer
*/
void GiroY_Feed(float pY)
{
	static short index = 0;

	if (index >= (TABGYROYSIZE - 1))
	{
		index = 0;
	}

	tabGyroY[index] = pY;
	index++;
}

/*
*   Read Pitch/giroY circular buffer
*	return type: short
*/
float GiroY_Read()
{
	return (avrgTab(tabGyroY, TABGYROYSIZE));
}

/*
* Return average value of tabSenss
* return Type : short
*/
float avrgTab(float pTab[], short pSize)
{
	short i = 0;
	float avrg = 0;

	for (i = 0; i < pSize; i++)
	{
		avrg += pTab[i];
	}

	return (avrg / pSize);
}

/*
* Return total sum of tabSenss
* return Type : short
*/
float sumTotal(float pTab[], short pSize)
{
	short i = 0;
	float sumTotal = 0;

	for (i = 0; i < pSize; i++)
	{
		sumTotal += pTab[i];
	}

	return (sumTotal);
}
