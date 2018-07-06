

#ifndef PORT2_h
#define PORT2_h

#include <Arduino.h>

#include"uKitId.h"

class Port2:uKitId
{
public:
  void Initialization();
  
  const char IR_S=3;
  //Button_pin
  const char Button_pin=36;
  
  //Buzzer_pin 
	const char buzzer_pin=38;
 
 //Grayscale_Sensor_pin 
  const char GrayscaleNum1=29;
  const char GrayscaleNum2=28;
  const char GrayscaleNum3=27;
  const char GrayscaleNum4=26;
  const char GrayscaleNum5=25;
  
  //RGB_LED_pin 
  const char redPin = 44;
  const char greenPin = 45;
  const char bluePin = 46;

  //HC-SR04
  char Trig;
  char Echo;


  
};

#endif

