/*
    MPU6050 Triple Axis Gyroscope & Accelerometer. Pitch & Roll Accelerometer Example.
*/

#include <Wire.h>
#include "MPU6050.h"
#include"uKitExplore.h"
MPU6050 mpu;

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
  // Read normalized values 
  Vector normAccel = mpu.readNormalizeAccel();

  // Calculate Pitch & Roll
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;

  // Output
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.println(roll);
  
  delay(10);
}



