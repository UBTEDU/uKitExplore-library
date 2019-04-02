#include "ucode.h"
double t=0;
void setup() {
    Initialization();
    if (protocolRunState == false) {



    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
       //test
    }
}
