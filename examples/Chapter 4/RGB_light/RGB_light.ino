/* 
 * uKit Explore 2.0 
 * <Chapter 4> 
 * <Section 2> 
 * 4.2 RGB light 
 */  
 
#include"uKitExplore2En.h" 
void setup() 
{  
  Initialization();//EN: Initialization 
}  
void loop() { 
    setRgbledColor(255,0,0);//(R, G, B) 
    delay(1000);//Flash red 1000 ms 
 
    setRgbledColor(0,255,0); 
    delay(1000);//Flash green 1000 ms 
 
    setRgbledColor(0,0,255); 
    delay(1000);//Flash blue 1000 ms 
} 
