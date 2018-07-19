/*
 * 
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
  ButtonState=readButtonValue(1);
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

