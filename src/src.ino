#include "uKitExploreBlockly2.h"

void setup() {
    Initialization();
}

void loop() {
    Serial.print("Color:");
  Serial.println(readColor(1,"Purple"));
   // readColor(1,"Gray");
    delay(200);
    

}


