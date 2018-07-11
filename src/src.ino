#include "uKitExplore.h"

signed char ida[12]={1,2,3,9,10,11,4,5,6,14,15,16};
signed char forwarda[4][12]={{109,-60,50,-13,-10,35,-90,60,-50,13,8,5},{90,-60,50,-12,-18,0,-109,60,-50,-8,-15,0},{109,-60,50,-11,-5,0,-90,60,-50,13,10,-35},{90,-60,50,8,15,0,-109,60,-50,12,18,0}};
signed char timea[4]={400,400,400,400};
volatile int a;
volatile int b;
volatile int c;
void setup(){
  Initialization();
  
    a = 0;
    b = 0;
    c = 0;
 

}

void loop() {

    unsigned char Rvalue1=uKit_RGB_Read(1,'R');
    unsigned char Gvalue1=uKit_RGB_Read(1,'G');
    unsigned char Bvalue1=uKit_RGB_Read(1,'B');
    a = Rvalue1;
    b = Gvalue1;
    c = Bvalue1;
     Serial.print("R:");
    Serial.print(a);
    Serial.print(",");
      Serial.print("G:");
    Serial.println(b);
     Serial.print(",");
     Serial.print("B:");
    Serial.println(c);
    delay(500);

}

