#include "uKitExplore.h"

signed char ida[12]={1,2,3,9,10,11,4,5,6,14,15,16};
signed char forwarda[4][12]={{109,-60,50,-13,-10,35,-90,60,-50,13,8,5},{90,-60,50,-12,-18,0,-109,60,-50,-8,-15,0},{109,-60,50,-11,-5,0,-90,60,-50,13,10,-35},{90,-60,50,8,15,0,-109,60,-50,12,18,0}};
signed char timea[4]={400,400,400,400};
volatile int a;
volatile int b;
volatile int c;
void setup(){
  Initialization();

  

 

}

void loop() {
unsigned char petals[32]={0x01,255,0,0,0x02,0,255,0,0x04,0,0,255,0x08,255,0,0,0x10,0,255,0,0x20,255,0,255,0x40,0,0,255,0x80,0,255,255};
setLedPetals(1,8, petals);
delay(700);
    

}

