#include "uKitExplore.h"
String comdata="";
String single,ten;
int id_1,id_2,id;
void setup() {
    Initialization();
}

void loop() {
setSensorId();
Serial.println(uKitId.getInfraredId());
delay(400);


}

