/*
 * CN:这个例子是实现uKit舵机转动模式（电机模式），达到360°转动的效果
 * EN:This example is to achieve the uKit Servo rotation mode (motor mode), to achieve the effect of 360 degree rotation.
 * CN:程序:ID-1号uKit舵机以5的速度正转300ms,反转300ms,之后同时正转300ms,同时反转300ms.停止300ms
 * EN:Program: ID-1 uKit Servo turns 300ms at 5 speed, reverses 300ms, then turns 300ms at the same time, reverses 300ms at the same time,Stop 300ms.
 * 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
} 

//CN:ServoRotate第一个是di号，第二是正反转（0是正转，1是反转），第三是速度（0~5）
//EN:The first is the ID number, the second is the positive inversion (0 is the positive rotation, the 1 is the inversion), and the third is the speed (0~5).
void loop(){
  ServoRotate(1,0,5);
  delay(300);
  ServoRotate(1,1,5);
  delay(300);
  ServoRotate(1,0,5);
  ServoRotate(1,0,5);
  delay(300);
  ServoRotate(1,1,5);
  ServoRotate(1,1,5);
  delay(300);
  ServoStop(1);
  delay(300);
  
  }



