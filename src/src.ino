#include"uKitExplore2En.h"
unsigned char *rgbValue1;
void setup() {
 Initialization();
 
}

void loop() {

 setRgbledColor(255,0,0);
 rgbValue1=readColorRgb(2);
 Serial.print(rgbValue1[0]);
 Serial.print(",");
 Serial.print(rgbValue1[1]);
 Serial.print(",");
 Serial.println(rgbValue1[2]);

 delete [] rgbValue1;
 delay(20);
 
//motion_case(1,3);

}




