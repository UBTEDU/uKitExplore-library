#include "ucode2.h"
char json[]="{\"device\":3,\"mode\":128,\"id\":1,\"data\":[0,157,233,59,1],\"uuid\":\"944485\"}";
void setup() {
    Initialization();
}

void loop() {
    protocol();
    if (protocolRunState == false) {
        setEyelightAllPetals(1,136,190,54);
        delay(1000);
        setEyelightOff(1);
        delay(1000);
        Serial.println(sizeof(json) / sizeof(int));

    }
}
