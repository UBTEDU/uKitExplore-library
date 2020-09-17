/* 
 * UKIT Advanced  
 * <Circuitry> 
 * Tilt Switch
 */  
 
#include"UKIT_Advance.h" 
int switchPin = A4;//Define the pin 
int ledPin = 7;//Define the pin 
int val = 0;//Define the assignment 
 
void setup()  
{  
 
  pinMode(ledPin,OUTPUT);//Set pin 7 as output 
  Initialization(); 
 
}  
void loop()  
{  
 
  val = analogRead(switchPin);//Assign a value for the tilt switch 
  if(val<800)//Open the serial port to adjust the value 
  digitalWrite(ledPin,LOW); 
  else 
  digitalWrite(ledPin,HIGH); 
  Serial.println(val);//Read the value 
   
} 
