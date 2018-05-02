/*
 * CN:这个例子是实现uKit舵机回读角度模式。(掉电回读）
 * EN:This example is to implement the uKit Servo back reading angle mode.(power off back reading)
 * 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
  ServoAngle(1,20,300);
  delay(200);
} 

//CN:回读ID-1的角度并打印到串口
//EN:Read the ID-1 angle and print it to the serial port
void loop(){
  Serial.print("Id-1Angle:");
  Serial.println(ServoRead_PD(1));
  delay(300);
  
  
  }



