/* 
* uKit Explore 2.0 
 * <Chapter 6> 
 * <Section 9> 
 * 6.10.1 Photoresistor 
 *  512=2.5V, increase the val value to increase the sensitivity of the sensor; 
 *  Decrease the value to decrease the sensitivity of the sensor. 
 */ 
#include"uKitExplore2En.h" 
int LdrPin = A5;  //Define variable Ldr as 5 for the voltage reading port. 
int ledPin = 6;   //Set the digital IO pin for the LED 
int val = 0;       //Define the variable i 
void setup()  
{  
  pinMode(ledPin,OUTPUT);  //Set the digital pin as output 
  Initialization(); 
}  
void loop()  
{  
  val = analogRead(LdrPin);    //Read the value from the sensor 
  if(val<70)//Adjust according to the serial port 
  {       
    digitalWrite(ledPin, LOW);//The LED turns off in strong light. 
  } 
  else 
    { 
    digitalWrite(ledPin, HIGH); //The LED turns on in dim light. 
    } 
  Serial.println(val); 
  delay(100); 
} 
