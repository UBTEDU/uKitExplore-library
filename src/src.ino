#include "uKitExplore2.h"

String colours_json;
volatile int item;
volatile int item2;
volatile int item3;
void setup() {
      item = 0;
    item2 = 0;
    item3 = 0;
     item = millis();
    Initialization();
   
    
   
   
   
     
}

void loop() {
 
   item2 = millis();   
  Serial.println(item2-item);
  while(1);
  }

 
  

  
 

  
