#include"uKitExplore2.h"
unsigned char *rgbValue1;
void setup() {
 Initialization();
 
}

void loop() {
 //tone(131,2);
 rgbValue1=readColorRgb(2);
 Serial.print(rgbValue1[0]);
 Serial.print(",");
 Serial.print(rgbValue1[1]);
 Serial.print(",");
 Serial.println(rgbValue1[2]);
  if (readColor(1,"Red")) {
        Serial.println("红色");

    }
    if (readColor(1,"Green")) {
        Serial.println("绿色");

    }
    if (readColor(1,"Blue")) {
        Serial.println("蓝色");

    }
    if (readColor(1,"Yellow")) {
        Serial.println("黄色");

    }
    if (readColor(1,"Cyan")) {
        Serial.println("青色");

    }
    if (readColor(1,"Purple")) {
        Serial.println("紫色");

    }
    if (readColor(1,"Orange")) {
        Serial.println("橙色");

    }
    if (readColor(1,"Black")) {
        Serial.println("黑色");

    }
    if (readColor(1,"White")) {
        Serial.println("白色");

    }
    if (readColor(1,"Gray")) {
        Serial.println("灰色");

    }
    delay(20);
 delete [] rgbValue1;
 
//motion_case(1,3);

}




