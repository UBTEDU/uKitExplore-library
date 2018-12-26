/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 5> 
 * 5.5.2 Automated lifting lever 
 */ 
 
#include"uKitExplore.h"

void setup() { 
  Initialization();//EN:Initialization
  setServoAngle(1,-90,300);
  delay(300);
} 

void loop()
{
  Serial.print("Infrared_distance:");
  Serial.println(readInfraredDistance(1));//Infrared sensor ID 
  delay(300);
  
  
if(readInfraredDistance(1)<=15)//Can be adjusted according to the data printed to the serial port 
 {
  delay(300);
  setServoAngle(1,0,700);
  delay(2000);
 }
 else
 {  
  setServoAngle(1,-90,600);
  delay(300); 
  setServoAngle(1,-50,600);
  delay(300);
 }
}

