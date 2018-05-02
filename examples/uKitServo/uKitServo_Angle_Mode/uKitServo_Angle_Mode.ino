/*
 * CN:这个例子是实现uKit舵机角度模式（舵机模式）。
 * EN:This example is to achieve the uKit Servo Angle mode (Servo mode)
 * CN:程序:ID-1号uKit舵机以300ms的时间完成20°的转向，等待300ms,再以300ms的时间完成-20°的转向,停止300ms
 * EN:Procedure: ID-1 uKit Servo completes the steering of 20 degree at 300ms time, waits for 300ms, and then completes 300ms -20's turn with 300ms time.Stop 300ms
 * 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
} 

//CN:ServoAngle第一个是di号，第二是角度（-118°~118°），第三是运行时间（100~3000）
//EN:ServoAngle the first is Di, the second is the angle (-118 degree ~118 degree), and the third is the running time (100~3000).
void loop(){
  ServoAngle(1,20,300);
  delay(300);
  ServoAngle(1,-20,300);
  delay(300);
  ServoStop(1);
  delay(300);
  
  
  }



