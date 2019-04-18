#include "ucode.h"

void setup() {
    Initialization();
    if (protocolRunState == false) {
    }
}

void loop() {
    protocol();
    if (protocolRunState == false) {
        button1.Update();
        if (button1.clicks == 1) {
          tone2(100,300);
            delay(1000);
             

        }


    }
}
