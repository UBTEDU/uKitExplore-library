/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 5> 
 * 5.5.1 Automated piggy bank 
 */


#include"uKitExplore2En.h"

void setup() { 
  Initialization();//EN: Initialization 
  setServoAngle(1,0,300);
  delay(300);
} 

void loop()
{
  Serial.print("Infrared_distance:");
  Serial.println(readInfraredDistance(1));
  delay(300);
  
  
if(readInfraredDistance(1)<8)//Can adjust the size according to the data printed to the serial port 
 {
  delay(300);
  setServoAngle(1,-70,200);
  delay(100);
  setEyelightLook(1,1,2,0,200,100);
  setEyelightLook(2,1,2,0,200,100);
  delay(300);
  setServoAngle(1,0,200);
  delay(300);
 }
}

