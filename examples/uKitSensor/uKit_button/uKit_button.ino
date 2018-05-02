/*
 * CN:uKit按键程序。按一下ID-1的uKit按键蜂鸣器以300Hz响300ms，按两下蜂鸣器以800Hz响600ms
 * EN:Click on the uKit button of ID-1, the buzzer rings 300Hz at 300ms, press two buzzer to 800Hz 600ms.
 * 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
 
} 

//Return 768 no operation, return 769 is clicking, return 770 is double click.
//返回768无操作，返回769是单击，返回770是双击
void loop(){
  int ButtonState=0;
  ButtonState=uKit_Button(3);
  if(ButtonState==769)//return 769 is clicking
  {
    for(int i=0;i<10;i++)
    {
    MotorRotate(1,500);
    delay(10);
    MotorRotate(1,-500);
    delay(10);
    }
  }
  if(ButtonState==770)//return 770 is double click.
    tone(800,600);
  MotorStop(1);
  }
  


