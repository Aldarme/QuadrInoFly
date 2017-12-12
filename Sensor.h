#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

void SensorSensitivityConf();
void SensorInit();
void SensorValDisplay();

void SensorGet();

void GiroX_Feed(float pX);
float GiroX_Read();

void GiroY_Feed(float pY);
float GiroY_Read();

float avrgTab(float pTab[], short pSize);
float sumTotal(float pTab[], short pSize);

#endif // SENSOR_H_INCLUDED
