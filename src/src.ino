#include "uKitExplore2.h"

#include "MPU6050s.h"

MPU6050 mpu;

void setup() {
    Initialization();
    while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)){
       Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
       delay(500);
    }
}

void loop() {
    Vector normAccel = mpu.readNormalizeAccel();
    int accel_roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
    Serial.println(accel_roll);

}

