/* 
* uKit Explore 2.0 
 * <Chapter 6> 
 * <Section 10> 
* 6.10.2 Light follower robot 
 * EN: Photoresistor 
 * Increase the val value to increase the sensitivity of the sensor, 
 * Decrease the value to decrease the sensitivity of the sensor. 
 */ 
#include"uKitExplore2En.h" 
 
 
float val = 0;       //Define variable i 
 
void setup()  
{  
 Initialization(); 
 
}   
void loop()  
{  
    double error = 0; 
    int adc[5] = {0}; 
    static int readval=0; 
     
    adc[0] = analogRead(A1); 
    adc[1] = analogRead(A2); 
    adc[2] = analogRead(A3); 
    adc[3] = analogRead(A4); 
    adc[4] = analogRead(A5); 
    error += adc[0]; 
    error += adc[1]; 
    error -= adc[3]; 
    error -= adc[4]; 
    error *= 0.1; 
   Serial.println(error); 
   //delay(400); 
    if(readval==0) 
    {   
    for(int i=0;i<10;i++){ 
    error=0; 
    adc[0] = analogRead(A1); 
    adc[1] = analogRead(A2); 
    adc[2] = analogRead(A3); 
    adc[3] = analogRead(A4); 
    adc[4] = analogRead(A5); 
    error += adc[0]; 
    error += adc[1]; 
    error -= adc[3]; 
    error -= adc[4]; 
    error *= 0.1; 
    } 
    val=error; 
     
      readval=1; 
    }  
 
   if(error>val-2) 
   { 
    action('r'); 
   } 
  else if(error<val+2) 
   { 
    action('l'); 
   } 
} 
void action(char dir) 
{ 
  if(dir=='r') 
  { 
    setServoTurn(1,0,100);//Servo, direction, speed 
    setServoTurn(2,0,100); 
  } 
   else if(dir=='l') 
  { 
    setServoTurn(1,1,100); 
    setServoTurn(2,1,100); 
  } 
} 
