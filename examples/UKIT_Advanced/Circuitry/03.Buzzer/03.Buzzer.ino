/* 
 * UKIT Advanced  
 * <Circuitry> 
 * Buzzer
 */  
 
#include"UKIT_Advance.h" 
 
void setup() {  
  Initialization();//EN: Initialization 
  
}  
 
void loop(){ 
  tone(200,300);//(Hz, duration) 
  tone(400,300); 
  tone(200,300); 
  tone(400,300); 
  noTone();//Stop tone square wave 
  delay(1000); 
  } 
