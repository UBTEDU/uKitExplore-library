/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 2> 
 * 5.2.1 Big pinwheel 
 */ 

 
#include"uKitExplore2En.h"
int i=0;
void setup()
{
  Initialization();
}
void loop()
{
  button1.Update();//Read button update
  if(button1.clicks == 1)//Button is clicked once 
  {
    i=i+20;
    if(i>120)
    {
      i=0;
    }
    Serial.println(i);//Print output data
  }
setMotorTurnAdj(1,i,0xffff);
}
