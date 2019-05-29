#include "ucode.h"
void setup() {
    Initialization();
    if (protocolRunState == false) {
    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
    int ButtonState1 = 0;
    ButtonState1 = readButtonValue(1);
    if (ButtonState1 == 1) {
      tone2(200,200);
    }   
    }
}
