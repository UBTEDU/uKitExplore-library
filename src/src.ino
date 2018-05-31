#include"uKitExplore.h"
String item;
int i=0;
void setup(){
  Initialization();
  
  item = "";
  pinMode(22, OUTPUT);
}
void loop(){
    button1.Update();
    if(button1.clicks == 1){
      i++;
      Serial.println(i);
      uKit_Led_Scene(1,i,2);
      uKit_Led_Scene(2,i,2);
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
