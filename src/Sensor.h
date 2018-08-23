

#ifndef SENSOR_h
#define SENSOR_h

#include <Arduino.h>
#include"uKitId.h"
#include"uKitSensor.h"
#include"uKitMotor.h"



class Sensor:uKitId,uKitSensor,uKitMotor
{
public:
  void tone(int pin, uint16_t frequency, uint32_t duration);
  void tone(uint16_t frequency, uint32_t duration = 0);
  void noTone(int pin);
  void noTone();
  //IR红外发射
  void IR_Send38KHZ(char pin,int x,int y);
  void IR_Sendcode(char pin,uint8_t x);
  void IR_Sendcode16(char pin,uint16_t x);
  void IR_Send(char pin,uint8_t code);
 
  int num1,num2,num3,num4,num5=0;
  void getGrayAllValue();
  int readGrayValue(char num,char grayval);
  void setRgbledColor(int red, int green, int blue);//板载RGB灯函数
  void setcolor(int color);
  float *getMpu6050Data();
  float readBatteryVoltage();
  float readHcsr04Distance(char jp); //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。
  float readHcsr04Distance(char EchoPin,char TrigPin); //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。
  
  void Initialization();
  const char IR_S=37;
  //Button_pin
  const char Button_pin=41;
  
  //Buzzer_pin 
  const char buzzer_pin=43;
 
 //Grayscale_Sensor_pin 
  const char GrayscaleNum1=31;
  const char GrayscaleNum2=29;
  const char GrayscaleNum3=27;
  const char GrayscaleNum4=25;
  const char GrayscaleNum5=23;
  
  //RGB_LED_pin 
  const char redPin = 24;
  const char greenPin = 26;
  const char bluePin = 22;

  //HC-SR04
  char Trig;
  char Echo;

  
  
  
};


#endif

