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
     Serial.println(uKit_RGB_Readcolor(1,'R'));
     delay(20);
  }
    //uKit_RGB_off(1);

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
