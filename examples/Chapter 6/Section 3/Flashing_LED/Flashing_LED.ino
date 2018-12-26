/* 
 * uKit Explore 2.0 
 * <Chapter 6> 
 * <Section 3> 
 * 6.3.1 Flashing LED 
 */
#include"uKitExplore2En.h" 
 
void setup()  
{  
pinMode(8, OUTPUT); //Declare pin D8 as output 
}  
 
void loop() 
{ 
    digitalWrite(8, HIGH);     // Turn the LED on 
    delay(1000);              // Wait for 1 second 
    digitalWrite(8, LOW);     // Turn the LED off 
    delay(1000);              // Wait for 1 second. 
 }
