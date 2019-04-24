#include "ucode.h"
double i=1;
bool t=1;
void setup() {
    Initialization();
    if (protocolRunState == false) {
    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {



    }
}
