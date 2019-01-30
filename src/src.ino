#include "uKitExplore2.h"
#include "ArduinoJson/ArduinoJson.h"

int incomingByte = 0;          // 接收到的 data byte
String inputString = "";         // 用来储存接收到的内容
boolean newLineReceived = false; // 前一次数据结束标志
float *values=NULL;
int buttonstate=0;
bool bstate=true;
bool bstate1=true;
double bstate2=10.00;
unsigned char *rgbValue=NULL;
void ProtocolParser(unsigned char device,unsigned char mode,unsigned char id,int *buf);
void setup() {
    Initialization();
    Wire.begin();
    button1.debounceTime   = 20;   // Debounce timer in ms
    button1.multiclickTime = 250;  // Time limit for multi clicks
    button1.longClickTime  = 1000; // time until "held-down clicks" register
  
 
}


void loop() {
}
