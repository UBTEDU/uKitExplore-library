
#include"uKitExplore.h"
int led1 = 2;
int led2 = 3;
int led3 = 4;
void setup()
{
  Initialization();

 
}
void setColor(int a,int green,int blue)
{
  analogWrite(led1,a);
  analogWrite(led2,255-green);
  analogWrite(led3,255-blue);
}
void loop()
{
Serial.println(uKit_Light_Read(1));
delay(400);
}
