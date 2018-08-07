#include "uKitExplore2.h"

void setup() {
    Initialization();
}

void loop() {
    if (readGrayValue(1,0)) {
        Serial.print("1");

    }
    if (readGrayValue(2,0)) {
        Serial.print("2");

    }
    if (readGrayValue(3,0)) {
        Serial.print("3");

    }
    if (readGrayValue(4,0)) {
        Serial.print("4");

    }
    if (readGrayValue(5,0)) {
        Serial.print("5");

    }
    delay(200);

}
