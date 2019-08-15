#include "ucode.h"
unsigned char id[2]={1,2};
int dir[2]={-118,118};
int speed[2]={60,60};
void setup() {
    Initialization();
    if (protocolRunState == false) {

      
    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
      uKitServo.setServoAngles(id,dir,600);

    }
}
