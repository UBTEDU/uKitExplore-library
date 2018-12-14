#include "uKitExplore2.h"

String colours_json;
volatile int item;
volatile int item2;
volatile int item3;
void setup() {
      item = 0;
    item2 = 0;
    item3 = 0;
    
    Initialization();
    item = millis();
     
}

void loop() {
item3=uKitId.setLedId(2,1);
if(item3==170){
    item2 = millis();
Serial.println(item2-item);
while(1);
}



    


}
