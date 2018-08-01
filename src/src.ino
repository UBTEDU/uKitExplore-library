#include "uKitExploreBlockly.h"

String colours_json;

void setup() {
    Initialization();
}

void loop() {
   colours_json = "{\"data\":\
      [1, 255, 0, 0,\
      2, 255, 0, 0,\
      4, 255, 0, 0,\
      8, 255, 0, 0,\
      16, 0, 255, 255,\
      32, 255, 0, 0,\
      64, 255, 0, 0,\
      128, 255, 0, 0]}";
    setEyelightPetals(1, 8, colours_json);
   colours_json = "{\"data\":\
      [1, 255, 128, 0,\
      2, 255, 128, 0,\
      4, 255, 128, 0,\
      8, 255, 128, 0,\
      16, 255, 240, 0,\
      32, 255, 128, 0,\
      64, 255, 128, 0,\
      128, 255, 128, 0]}";
    setEyelightPetals(2, 8, colours_json);
    delay(1*1000);
    setEyelightOff(0);
    delay(1*1000);

}


