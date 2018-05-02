

#ifndef SENSOR_h
#define SENSOR_h

#include <Arduino.h>
#include"Port.h"

class Sensor:Port
{
public:
  void tone(int pin, uint16_t frequency, uint32_t duration);
  void tone(uint16_t frequency, uint32_t duration = 0);
  void noTone(int pin);
  void noTone();
  
  int num1,num2,num3,num4,num5=0;
  void read_data();

  void colorRGB(int red, int green, int blue);//板载RGB灯函数
  void setcolor(int color);

  float Battery_check();
  float HcSr04Dis(char jp); //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。
  float HcSr04Dis(char EchoPin,char TrigPin); //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。
  
  
};


#endif

