#include "uKitExploreBlockly.h"

String colours_json;

void setup() {
    Initialization();
}

void loop() {
  Serial.print("R:");
  delay(2);
  Serial.print(readColorRgb(1,'R'));
  delay(2);
  Serial.print(",");
  delay(2);
    Serial.print("G:");
    delay(2);
  Serial.print(readColorRgb(1,'G'));
  delay(2);
  Serial.print(",");
  delay(2);
    Serial.print("B:");
    delay(2);
  Serial.println(readColorRgb(1,'B'));
delay(400);
  
}


