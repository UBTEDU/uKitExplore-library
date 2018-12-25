/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 3> 
 * 5.3.1 Golf club 
 */ 


#include"uKitExplore2En.h"
void setup() { 
  Initialization();//EN:Initialization
} 
//EN: setServoAngle: first is the id number,if the servo is 2,you need to change the id number to 2; the second is the angle (-118°to 118); the third is the running time (100 to 3000) 
void loop(){
  
  setServoAngle(1,50,800);
  delay(100);

 button1.Update();//Read button update 
  if(button1.clicks == 1)//Button is clicked once
    {

    setServoAngle(1,-20,100);
    delay(200);
    setServoStop(1);
    while(1);
    }
  }

