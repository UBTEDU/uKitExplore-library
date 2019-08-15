

#ifndef UKITMOTOR_h
#define UKITMOTOR_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>
class uKitMotor : public SemiduplexSerial
{
public:
  	unsigned char setMotorTurn(uint8_t id, uint16_t pwmDuty);
    unsigned char setMotorTurnAdj(uint8_t id, uint16_t speed, uint16_t time=0xffff);
    unsigned char setMotorTurns(unsigned char* id, int* pwmDuty);
    unsigned char setMotorTurnAdjs(unsigned char* id, int* speed, uint16_t time=0xffff);
    short readMotorSpeed(uint8_t id);
    int setMotorStop(uint8_t id);
    void clearMotorInf(unsigned char id);
    void StopServo();
    


  
};

#endif
