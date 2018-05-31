/*
    MPU6050 Triple Axis Gyroscope & Accelerometer. Temperature Example.
*/

#include <Wire.h>
#include "MPU6050s.h"
#include"uKitExplore.h"
MPU6050s mpu;
void setup() 
{
  Initialization();

  Serial.println("Initialize MPU6050");

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
}

void loop()
{
  float temp = mpu.readTemperature();

  Serial.print(" Temp = ");
  Serial.print(temp);
  Serial.println(" *C");
  
  delay(500);
}


