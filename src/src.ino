#include "ucode.h"


void setup() {
    Initialization();
    
}

void loop() {
    protocol();
    if (protocolRunState == false) {
      setServoAngle(1,1,2);
 
    }
}
void forward(){
  ;
}
