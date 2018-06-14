#include"uKitExplore.h"
String item;
int r=255;
int g=255;
int b=56;

void setup(){

Initialization();
}
void loop(){
 Serial.println(uKit_Infrared(2));
 delay(500);
  
  
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
