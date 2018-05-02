/*
 * CN:读取超声波ID-1的距离并打印到串口
 * EN:Read the distance from the uKit Ultrasonic ID-1 and print it to the serial port
 * 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
 
} 

//ukit超声波传感器控制函数
//uKit Ultrasonic sensor control function
void loop(){
  Serial.print("Ultasonic_distance:");
  Serial.println(uKit_Ultrasonic(1));
  delay(300);
  
  
  }



