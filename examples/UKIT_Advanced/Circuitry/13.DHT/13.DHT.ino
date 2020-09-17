/* 
 * UKIT Advanced  
 * <Circuitry> 
 * DHT
 */  
 
#include"UKIT_Advance.h" 
#include "dht.h"

dht DHT;
  
  
void setup() 
{   
  Initialization(); 
   
  delay(1000); 
} 
  
void loop() 
{ 
  DHT.read11(2);// data pin 2 
  float temperature = DHT.temperature; 
  float humidity =DHT.humidity;//Assign the variable value 
  
  Serial.print("temperature is ");//Printout 
  Serial.print(temperature, 1);//Printout 
  Serial.println(" C"); 
  Serial.print("humidity is "); 
  Serial.print(humidity, 1); 
  Serial.println("%"); 
  delay(3000); 
}
