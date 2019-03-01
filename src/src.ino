#include "ucode2.h"

void setup() {
    Initialization();
}

void loop() {
    protocol();
    if (protocolRunState == false) {
        consoleLog(0, String("R:") + String(readColor(1,"Red")));
        delay(200);
        consoleLog(0, String("W:") + String(readColor(2,"White")));
        delay(200);

    }
}
