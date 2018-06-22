#include"uKitExplore.h"
uint16_t a=-100;
void setup() {
    Initialization();
}

void loop() {

    MotorRotate(1,120);
    delay(1000);
    MotorRotate(1,-120);
    delay(1000);

}
