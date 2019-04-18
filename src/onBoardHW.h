

#ifndef ONBOARDHW_H
#define ONBOARDHW_H

#include <Arduino.h>
#include"uKitId.h"
#include"uKitSensor.h"
#include"uKitMotor.h"



class OnBoardHW :uKitId,uKitSensor,uKitMotor
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
  long readHcsr04Distance(unsigned char jp); //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。
  void printInf();
  
  void checkVersion();
  
 
  char IR_S;
  //Button_pin
  char Button_pin;
  
  //Buzzer_pin 
  char buzzer_pin;
 
 //Grayscale_Sensor_pin 
   char GrayscaleNum1;
   char GrayscaleNum2;
   char GrayscaleNum3;
   char GrayscaleNum4;
   char GrayscaleNum5;
  
  //RGB_LED_pin 
   char redPin;
   char greenPin;
   char bluePin;

 //电池电压pin
 int battery_pin;

  //HC-SR04
  unsigned char Trig;
  unsigned char Echo;
  const char* Version="";
  
  
  
};


#endif
