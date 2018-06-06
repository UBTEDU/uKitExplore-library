#include"uKitExplore.h"
String item;
int r=255;
int g=255;
int b=56;

void setup(){

  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  digitalWrite(22, HIGH);
}
void loop(){
  for(int t=0;t<20;t++)
  {
  digitalWrite(24, LOW);  
  delayMicroseconds(r);  
  digitalWrite(24, HIGH);  
  delayMicroseconds(255 - r); 
    digitalWrite(26, LOW);  
  delayMicroseconds(g);  
  digitalWrite(26, HIGH);  
  delayMicroseconds(255 - g); 
      digitalWrite(22, LOW);  
  delayMicroseconds(b);  
  digitalWrite(22, HIGH);  
  delayMicroseconds(255 - b); 
  }
 
  
  
  
}
void loops(){
  if (Serial.available() > 0) {
    item = Serial.readStringUntil('.');
    if (String(item).equals(String("OPEN"))) {
      digitalWrite(22,LOW);

    } else if (String(item).equals(String("CLOSE"))) {
      digitalWrite(22,HIGH);
    }

  }

}
