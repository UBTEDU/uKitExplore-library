#include "uKitExplore2.h"
#include "MPU6050.h"
#include <Wire.h>

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
    Wire.begin();
    delay(5);
    accelgyro.initialize();
    delay(5);
    Initialization();

    
}

void loop() {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.print(ax/32768.00*2*9.7913);
    delay(12);


}
