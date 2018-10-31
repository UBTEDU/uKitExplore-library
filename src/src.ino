#include "uKitExplore2.h"

unsigned char *rgbValue1=NULL;

void setup() {
    Initialization();
}

void loop() {
    rgbValue1=readColorRgb(1);
    Serial.println(rgbValue1[0]);
    Serial.println(rgbValue1[1]);
    Serial.println(rgbValue1[2]);
    if (readColor(1,"Red")) {
        Serial.println("红色");

    }
    if (readColor(2,"Green")) {
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


    delete [] rgbValue1;
}
