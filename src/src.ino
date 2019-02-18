#include "ucode2.h"
void setup() {
    Initialization();

}


void loop() {
  protocol();
  if(protocolRunState==false){    
  
  consoleLog(1,"Hello");
delay(800);

    
  }
  

}
