#include "uKitExploreBlockly2.h"
#include"avr/wdt.h "

void setup() {
    Initialization();
   // wdt_enable(WDTO_4S);
    //wdt_disable();
    //CarCase('R');
}
void loop(){
  //Serial.println(readColor(1,"Black"));
 rgb();
  //delay(400);
  
  //CarCase('R');
    //Motion();

 
  // motion2();
   // wdt_reset();
  
  
  }
void rgb() {
   button1.Update();
    if(button1.clicks == 1){
      uKitServo.ServoRead();
    }
}

void Motion(){
  for(int i=1;i<=16;i++){
    setServoAngle(i,60,1500);
    setMotorTurnAdj(i,60,0xffff);
    delay(5);
  }
  
  delay(1500);
  for(int i=1;i<=16;i++){
    setServoAngle(i,-60,1500);
    setMotorTurn(i,-60);
    delay(5);
  }
  delay(1500);
  
}
signed char id[]={1,2,3,6,8,10,13,4,5,12,14,16};
signed char action[][12]={{-118,-118,0,-44,0,-32,31,-118,-118,70,70,70},{118,118,-86,40,87,26,-42,118,118,-70,-70,-70}};
void motion2(){
    for(int i=0;i<sizeof(action)/sizeof(action[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        setRgbledColor(0,0,0);
        setServoAngle(id[t],action[i][t],2700);
        setMotorTurnAdj(1,35,0xffff);
        setMotorTurnAdj(2,35,0xffff);
      } 
      setRgbledColor(255,0,0);
   
      
 
      delay(2700);
    }
}

   
  

