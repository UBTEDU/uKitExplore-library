/* 
 * UKIT Advanced  
 * <Circuitry> 
 * Gyroscope
 */  
 
#include"UKIT_Advance.h" 
#include "MPU6050.h"
#include <Wire.h>

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
    Initialization();
    Wire.begin();
    accelgyro.initialize();
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop() {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.print("X:");
    Serial.print(ax/32768.00*2*9.7913);
    Serial.print("，");
    Serial.print("Y:");
    Serial.println(ay/32768.00*2*9.7913);
    delay(1000);

}

