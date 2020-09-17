/* 
 * UKIT Advanced  
 * <Circuitry> 
 * RGB LED
 */  
 
#include"UKIT_Advance.h" 
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
