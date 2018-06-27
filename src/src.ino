#include"uKitExplore.h"
#include "FlexiTimer2.h"
String comdata = "";
int i;


void setup() {
    Initialization();
}

void loop()
{
  MotorRotate(1,30);
  MotorRotate(2,30);
  MotorRotate(3,30);
  MotorRotate(4,30);
  MotorRotate(5,30);
  delay(300);
   MotorRotate(1,120);
  MotorRotate(2,120);
  MotorRotate(3,120);
  MotorRotate(4,120);
  MotorRotate(5,120);
  delay(300);

}
