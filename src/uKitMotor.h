

#ifndef UKITMOTOR_h
#define UKITMOTOR_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>
class uKitMotor : public SemiduplexSerial
{
public:
  	unsigned long MotorRotate(uint8_t id, uint16_t pwmDuty);
    unsigned long MotorRotateAdj(uint8_t id, uint16_t speed, uint16_t time);
    uint16_t MotorReadSpeed(uint8_t id);
    int MotorStop(uint8_t id);
    int MotorSetID(uint8_t id_old, uint8_t id_new);
    int MotorCheckID(uint8_t id);

  
};

#endif

