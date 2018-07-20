#include "uKitExploreBlockly.h"

void setup() {
    Initialization();
}

void loop() {
    unsigned char Rvalue1=readColorRgb(1,'R');
    unsigned char Gvalue1=readColorRgb(1,'G');
    Serial.print(Rvalue1);
    Serial.print(",");
    Serial.println(Gvalue1);
    delay(300);

}

