#include "ucode.h"
char *sns="010220TPT18120701387";
void setup() {
    Initialization();
    if (protocolRunState == false) {
      
    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
      
      //uKitId.writeString(0,sns);
      //delay(200);
      //Serial.println(uKitId.read_String(0));
      //while(1);
   
        


    }
}
