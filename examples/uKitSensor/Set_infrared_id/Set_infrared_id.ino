/*
 * CN:读取红外ID-1的距离并打印到串口
 * EN:Read the distance from the infrared ID-1 and print it to the serial port
 * 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
 
} 

//ukit红外传感器控制函数，返回cm,(0-20)cm
//ukit infrared sensor control function, return cm, (0-20) cm
void loop(){
  button1.Update();//读取按键更新
  if(button1.clicks == 1)//按键按一下
  {
    Set_Infrared_Id(2);
    tone(43,300);
    delay(300);
    noTone(43);
    }
  
  
  }



