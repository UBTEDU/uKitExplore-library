/*
 * CN:RGB灯代码
* 
 */

#include"uKitExplore2.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
 
} 

//红色亮300ms,绿灯亮300ms，蓝灯亮300ms，循环
void loop(){
  setRgbledColor(255,0,0);
  delay(300);
  setRgbledColor(0,255,0);
  delay(300);
  setRgbledColor(0,0,255);
  delay(300);

  
  }


