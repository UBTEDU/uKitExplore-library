#include "uKitExplore.h"

void setup() {
    Initialization();
}

void loop() {
Serial.println(uKit_Sound_Read(1));
delay(400);
}
