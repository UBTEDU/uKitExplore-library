

#ifndef PORT_h
#define PORT_h

#include <Arduino.h>
#include"SemiduplexSerial.h"
class Port:SemiduplexSerial
{
public:
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

