#include "ucode.h"
#include<EEPROM.h>
#include <IRremote.h>

 
void setup() {
    Initialization();
    if (protocolRunState == false) {


    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
//      //   rgbValue1 = readColorRgb(1);
//      // rgbValue1[0];       
//    setMotorTurn(1,40);
//    setMotorTurn(2,40);
//    delay(500);
//    setMotorTurnAdj(1,40,0xffff);
//    setMotorTurnAdj(2,40,0xffff);
//    delay(500);
//    setMotorStop(1);
//    setMotorStop(2);
//    delay(500);
//    setMotorTurn(1,40);
//    setMotorTurn(2,40);
//    setMotorTurnAdj(1,40,0xffff);
//    setMotorTurnAdj(2,40,0xffff);
//    delay(500);
//    setMotorStop(1);
//    setMotorStop(2);
//    delay(500);
////  delete [] rgbValue1;
//    if(uKitId.getMotorId(1)==1+0xec || uKitId.getMotorId(2)==2+0xec ){
//      tone2(800,300);
//      setMotorStop(1);
//      setMotorStop(2);
//      EEPROM.write(0,255);
//      while(1);
//      
//    }


    }
}
