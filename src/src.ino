#include "uKitExplore2.h"


void setup() {
    Initialization();
    
}

void loop() {
   Serial.println(readUltrasonicDistance(2));
   delay(300);
   
   

}
