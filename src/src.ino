#include "ucode.h"

void setup() {
    Initialization();
    if (protocolRunState == false) {
    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
        
        
        if (readUltrasonicDistance(1)< 20) {
            setRgbledColor(217,20,218);

        } else {
            setRgbledColor(0, 0, 0);

        }
        


    }
}
