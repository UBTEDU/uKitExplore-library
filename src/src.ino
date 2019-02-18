#include "ucode2.h"
void setup() {
    Initialization();

}


void loop() {
  protocol();
  if(protocolRunState==false){    
  
  consoleLog(1,String("检测到电池电压：")+String(readBatteryVoltage()));
  delay(800);

    
  }
  

}
