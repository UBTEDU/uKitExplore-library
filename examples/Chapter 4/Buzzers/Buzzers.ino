/* 
 * uKit Explore 2.0 
 * <Chapter 4> 
 * <Section 3> 
 * 4.3 Applications of Buzzers 
 */  
 
#include"uKitExplore2En.h" 
 
void setup() {  
  Initialization();//EN: Initialization 
  
}  
 
void loop(){ 
  tone(200,300);//(Hz, duration) 
  tone(400,300); 
  tone(200,300); 
  tone(400,300); 
  noTone();//Stop tone square wave 
  delay(1000); 
  } 
