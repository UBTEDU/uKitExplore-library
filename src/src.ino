#include "uKitExploreBlockly2.h"

void setup() {
    Initialization();
}

void loop() {
    unsigned char Rvalue1=readColorRgb(1,'R');
    unsigned char Gvalue1=readColorRgb(1,'G');
    unsigned char Bvalue1=readColorRgb(1,'B');
    Serial.println(Rvalue1);
    Serial.println(Gvalue1);
    Serial.println(Bvalue1);
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
    delay(1000);

}



