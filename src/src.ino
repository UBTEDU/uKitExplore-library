#include "uKitExplore2.h"



void setup() {
    Initialization();
}

void loop() {
setServoAngle(1,118,600);
delay(600);
setServoAngle(1,0,600);
delay(600);
}
