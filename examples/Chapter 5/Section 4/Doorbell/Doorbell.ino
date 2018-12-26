/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 4> 
 * 5.4.1 Doorbell 
 */

#include"uKitExplore2En.h"

void setup() { 
  Initialization();
 
} 

//Return 256 with no operation, return 1 with a click, and return 2 with a double click 

void loop(){
  int ButtonState=0;
  ButtonState=readButtonValue(1);
  if(ButtonState==1)//return 1 is clicking
  {
    tone(556,300);
    tone(495,400);
    tone(556,300);
    tone(495,400);
  }
  if(ButtonState==2)//return 2 is double click.
    tone(800,800);
    
  }

