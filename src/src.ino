#include"uKitExplore.h"
String item;
int i=0;
void setup(){
  Initialization();
  
  item = "";
  pinMode(22, OUTPUT);
}
void loop(){

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
