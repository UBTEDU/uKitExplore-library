#include"uKitExplore.h"

void setup() {
  Serial.begin(115200);       // 初始化串口通信

}

void loop() {
 float *tepm=getMpu6050Data();
 Serial.print(tepm[0]);
 Serial.print(",");
 Serial.print(tepm[1]);
 Serial.print(",");
 Serial.println(tepm[2]);
 delay(300);
}




