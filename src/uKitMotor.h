

#ifndef UKITMOTOR_h
#define UKITMOTOR_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>
class uKitMotor : public SemiduplexSerial
{
public:
  	unsigned long setMotorTurn(uint8_t id, uint16_t pwmDuty);
    unsigned long setMotorTurnAdj(uint8_t id, uint16_t speed, uint16_t time);
    uint16_t readMotorSpeed(uint8_t id);
    int setMotorStop(uint8_t id);
    void StopServo();


  
};

#endif

