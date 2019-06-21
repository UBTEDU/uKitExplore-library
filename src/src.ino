#include "ucode.h"


void setup() {
    Initialization();
    if (protocolRunState == false) {


    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
      Serial.println(readInfraredDistance(1));
      delay(300);


    }
}
