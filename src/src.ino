#include "ucode.h"

void setup() {
    Initialization();
    if (protocolRunState == false) {
    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
        setRgbledColor(177,137,83);
        delay(1000);
        setRgbledColor(0, 0, 0);
        delay(1000);


    }
}
