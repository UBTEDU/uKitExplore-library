/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 7> 
 * 5.7.1 Applications of ultrasonic sensors 
 * EN:Read the distance from the uKit Ultrasonic ID-1 and print it to the serial port 
 */ 
 
#include"uKitExplore2En.h" 
void setup() {  
  Initialization();//EN: Initialization 
}  
void loop()
{ 
  Serial.print("Ultasonic_distance:"); 
  Serial.println(readUltrasonicDistance(1)); 
  delay(300); 
  }
