#include "kuka.h"

void setup() {
    Initialization();
    if (protocolRunState == false) {
    }
}


void loop() {
    protocol();
    if (protocolRunState == false) {
    _E5_88_9D_E5_A7_8B_E5_8C_96();
    delay(2000);
    setServoAngle(1,-32,1000);
    setServoAngle(2,4,1000);
    setServoAngle(3,-118,1000);
    setServoAngle(4,-91,1000);
    setServoAngle(5,-25,1000);
    setServoAngle(6,139,1000);
    delay(1000);
    setServoAngle(7,75,1000);
    delay(1000);
    setServoAngle(2,-8,1000);
    delay(1000);
    setServoAngle(1,-64,1000);
    setServoAngle(2,-4,1000);
    setServoAngle(3,-118,1000);
    setServoAngle(4,-90,1000);
    setServoAngle(5,-38,1000);
    setServoAngle(6,139,1000);
    delay(1000);
    setServoAngle(1,-64,1000);
    setServoAngle(2,-1,1000);
    setServoAngle(3,-116,1000);
    setServoAngle(4,-90,1000);
    setServoAngle(5,-38,1000);
    setServoAngle(6,139,1000);
    delay(1000);    
    
    
          
   
    while(true);


    }
}
void loops() {
    protocol();
    if (protocolRunState == false) {
          _E5_88_9D_E5_A7_8B_E5_8C_96();
          delay(2000);
    _E6_8A_93_E4_B8_9C_E8_A5_BF();
    setServoAngle(7,45,1000);
    delay(1000);
    setServoAngle(1,-32,1000);
    setServoAngle(2,-70,1000);
    setServoAngle(3,-113,1000);
    setServoAngle(4,25,1000);
    setServoAngle(5,9,1000);
    setServoAngle(6,82,1000);
    delay(1000);
    setServoAngle(1,-112,1000);
    setServoAngle(2,-47,1000);
    setServoAngle(3,-105,1000);
    setServoAngle(4,11,1000);
    setServoAngle(5,96,1000);
    setServoAngle(6,82,1000);
    delay(1000);
    setServoAngle(7,-75,1000);
    delay(1000);

    setServoAngle(1,-112,1000);
    setServoAngle(2,-47,1000);
    setServoAngle(3,-93,1000);
    setServoAngle(4,11,1000);
    setServoAngle(5,96,1000);
    setServoAngle(6,82,1000);
    delay(1000);
    _E5_88_9D_E5_A7_8B_E5_8C_96();
    delay(1000);
    
    while(true);


    }
}
void _E5_88_9D_E5_A7_8B_E5_8C_96() {
    setServoAngle(1,-30,1000);
    setServoAngle(2,-52,1000);
    setServoAngle(3,-115,1000);
    setServoAngle(4,-32,1000);
    setServoAngle(5,6,1000);
    setServoAngle(6,-49,1000);
    setServoAngle(7,-75,1000);
    delay(1000);
}

void _E6_8A_93_E4_B8_9C_E8_A5_BF() {
    setServoAngle(1,-31,1000);
    setServoAngle(2,11,1000);
    setServoAngle(3,-120,1000);
    setServoAngle(4,25,1000);
    setServoAngle(5,25,1000);
    setServoAngle(6,82,1000);
    setServoAngle(7,-75,1000);
    delay(1000);
}
