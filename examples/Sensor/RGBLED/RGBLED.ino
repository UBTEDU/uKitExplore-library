/*
 * CN:RGB灯代码
* 
 */

#include"uKitExplore.h"

void setup() { 
  Initialization();//CN:初始化/EN:Initialization
 
} 

//红色亮300ms,绿灯亮300ms，蓝灯亮300ms，循环
void loop(){
  colorRGB(255,0,0);
  delay(300);
  colorRGB(0,255,0);
  delay(300);
  colorRGB(0,0,255);
  delay(300);

  
  }


