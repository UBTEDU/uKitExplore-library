/* 
 * UKIT Advanced  
 * <Circuitry> 
 * LED 2
 */  
 
#include"UKIT_Advance.h" 
 
void setup()  
{  
pinMode(9, OUTPUT); //Declare pin D9 as output 
}  
 
void loop() 
{ 
  for (int a=0; a<=255;a++)                //Loop statement, used to control the increase of PWM brightness 
  { 
    analogWrite(9,a); 
    delay(8);                             //The duration of the current brightness level, in milliseconds             
  } 
    for (int a=255; a>=0;a--)             //Loop statement, used to control the decrease of PWM brightness 
  { 
    analogWrite(9,a); 
    delay(8);                             //The duration of the current brightness, in milliseconds   
  } 
  delay(800);  
 }
