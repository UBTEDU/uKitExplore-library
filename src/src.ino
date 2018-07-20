#include "uKitExplore2.h"




void setup() {
    Initialization();

}

void loop() {
  
unsigned char buf[8][4]={{0x01,255,0,0},{0x04,0,255,0},{0x02,0,0,255}};
setEyelightPetals(1,4,buf);
while(1);

}

