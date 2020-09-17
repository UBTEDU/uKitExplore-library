/* 
 * UKIT Advanced  
 * <Circuitry> 
 * LED 1
 */  
 
#include"UKIT_Advance.h" 
 
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
