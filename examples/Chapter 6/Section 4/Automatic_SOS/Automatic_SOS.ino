/* 
 * uKit Explore 2.0 
 * <Chapter 6> 
 * <Section 4> 
 * 6.4.2 Automatic SOS 
 */  
int led=7;//Define the interface for digit 7 
int button=6;//Define the interface for digit 6 
int val;//Define the variable val 
void setup() 
{ 
pinMode(led,OUTPUT);//Set the LED as output 
pinMode(button,INPUT);//Set the button as input 
} 
void loop() 
{ 
val=digitalRead(button);//Read digital pin 7's level value and assign it to val 
if(val==LOW)//Check if the button is pressed; the light goes on when the button is pressed 
  {  
  digitalWrite(led,LOW); 
  } 
else 
  {  
  digitalWrite(led,HIGH); 
  delay(200); 
  digitalWrite(led,LOW); 
  delay(200); 
  digitalWrite(led,HIGH); 
  delay(200); 
  digitalWrite(led,LOW); 
  delay(200); 
  digitalWrite(led,HIGH); 
  delay(200); 
  digitalWrite(led,LOW); 
  delay(200); 
  digitalWrite(led,HIGH); 
  delay(800); 
  digitalWrite(led,LOW); 
  delay(500); 
  digitalWrite(led,HIGH); 
  delay(800); 
  digitalWrite(led,LOW); 
  delay(500); 
  digitalWrite(led,HIGH); 
  delay(800); 
  digitalWrite(led,LOW); 
  delay(500); 
  digitalWrite(led,HIGH); 
  delay(200); 
  digitalWrite(led,LOW); 
  delay(200); 
  digitalWrite(led,HIGH); 
  delay(200); 
  digitalWrite(led,LOW); 
  delay(200); 
  digitalWrite(led,HIGH); 
  delay(200); 
  digitalWrite(led,LOW); 
  delay(200); 
  } 
}
