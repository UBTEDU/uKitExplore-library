/*
 * CN:uKit按键程序。按一下ID-1的uKit按键蜂鸣器以300Hz响300ms，按两下蜂鸣器以800Hz响600ms,长按蜂鸣器以1200Hz响1000ms. 
 * EN:Click on the uKit button of ID-1, the buzzer rings 300Hz at 300ms, press two buzzer to 800Hz 600ms. Long press the buzzer to 1200Hz 1000ms.
 * 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
 
} 

//Return 256 no operation, return 258 is clicking, return 259 is double click.
//返回256无操作，返回257是单击，返回258是双击
void loop(){
  int ButtonState=0;
  ButtonState=uKit_Button(1);
  if(ButtonState==257)//return 257 is clicking
  {
    tone(300,300);
  }
  else if(ButtonState==258){//return 258 is double click.
    tone(800,600);
  }
  else if(ButtonState==259){//return 259 is long click.
    tone(1200,1000);
  }
  
  
}

