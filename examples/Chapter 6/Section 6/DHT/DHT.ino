/* 
 * uKit Explore 2.0 
 * <Chapter 6> 
 * <Section 6> 
 * 6.6.2 Temperature & humidity sensor 
 */ 
#include "uKitExplore.h" 
#include "DHT.h" 
  
DHT dht; 
  
void setup() 
{   Initialization(); 
  dht.setup(2); // data pin 2 
  delay(1000); 
} 
  
void loop() 
{ 
  float temperature = dht.getTemperature(); 
  float humidity = dht.getHumidity();//Assign the variable value 
  
  Serial.print("temperature is ");//Printout 
  Serial.print(temperature, 1);//Printout 
  Serial.println(" C"); 
  Serial.print("humidity is "); 
  Serial.print(humidity, 1); 
  Serial.println("%"); 
  delay(3000); 
}
