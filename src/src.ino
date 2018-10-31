#include "uKitExplore2.h"
#include <LCD5110_Basic.h>
LCD5110 myGLCD(8,4,5,6,7);
extern uint8_t SmallFont[];
unsigned char buf[3]={0};
int x=0;
void setup() {
    //Initialization();
     myGLCD.InitLCD(); //Intializing LCD
    Serial.begin(115200);
    buf[1]=uKitId.getMotorId(2);
   x=0;
    delay(20);
}

void loop() {

   setMotorTurnAdj(2,50,0xffff);
  if(buf[0]==1){
        setRgbledColor(255,0,0);
        delay(100);
  }
   if(buf[1]==2){
    tone(110,200);
  }
  x= readMotorSpeed(2);
  buf[0]=0;
  buf[1]=0;
  setRgbledColor(0,0,0);    
  myGLCD.setFont(SmallFont);
  myGLCD.printNumI(x, CENTER, 16);
  delay(200);
  myGLCD.clrScr();


   
}
