/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 2> 
 * 5.2.2 Two-wheel-drive vehicle 
 */


#include"uKitExplore2En.h"
int i=0;//定义i=0

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
  }
 
setMotorTurnAdj(1,-i,0xffff);//Motor 1 rotates clockwise 
setMotorTurnAdj(2,i,0xffff);//Motor 2 rotates counterclockwise

}

