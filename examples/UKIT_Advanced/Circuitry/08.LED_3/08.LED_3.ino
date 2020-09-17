/* 
 * UKIT Advanced  
 * <Circuitry> 
 * LED 3
 */  
 
#include"UKIT_Advance.h" 
int r = 8;//Red 
int y = 9;//Yellow 
int g = 10;//Green 
void setup()  
{  
  pinMode(r ,OUTPUT);//Declare pin D8 as output 
  pinMode(y ,OUTPUT);//Declare pin D9 as output 
  pinMode(g ,OUTPUT);//Declare pin D10 as output 
}  
 
void loop() 
{ 
    digitalWrite(r,HIGH);//Turn the red LED on 
    delay(2000); 
    digitalWrite(r,LOW);//Turn the red LED off 
    digitalWrite(g,HIGH);//Turn the green LED on 
    delay(2000); 
    digitalWrite(g,HIGH);//Turn the green LED on 
    delay(500); 
    digitalWrite(g ,LOW);//Turn the green LED off 
    delay(500); 
    digitalWrite(g,HIGH);//Turn the green LED on 
    delay(500); 
    digitalWrite(g ,LOW);//Turn the green LED off 
    delay(500); 
    digitalWrite(g,HIGH);//Turn the green LED on 
    delay(500); 
    digitalWrite(g ,LOW);//Turn the green LED off 
    delay(500); 
    digitalWrite(y,HIGH);//Turn the yellow LED on 
    delay(1300); 
    digitalWrite(y,LOW);//Turn the yellow LED off 
    delay(300); 
     
 }
