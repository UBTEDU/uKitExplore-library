/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 3> 
 * 5.3.2 Rear-wheel-drive car 
 */

#include"uKitExplore2En.h"
void setup() {
    Initialization();
}

void loop() {
if (readInfraredDistance(1) < 10) //If the infrared sensor value is less than 10 
{
  setEyelightScene(1,1,2);//Eye light scene mode (eye light ID, scene light, number of times) 
  setEyelightScene(2,1,2);
  setServoAngle(3,33,400);//Servo mode (servo ID, angle, duration) 
  setServoTurn(1,0,80);//Servo wheel mode (servo ID, clockwise, speed)  
  setServoTurn(2,1,80);// Servo wheel mode (servo ID, counterclockwise, speed) 
  delay(5000);


}
   else 
      {
      setEyelightLook(1,11,3,0,255,1);//Eye light look mode (eye light ID, scene mode, color *3, number of times)
      setEyelightLook(2,11,3,0,255,1);
      setServoAngle(3,0,400);
      setServoTurn(1,0,80);
      setServoTurn(2,1,80);
      
      }
}

