#ifndef UKITID_h
#define UKITID_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>

class uKitId : public SemiduplexSerial
{
public:
	
    unsigned char setLightId(char oldid,char newid);
    unsigned char getLightId();
    
    unsigned char setSoundId(char oldid,char newid);
    unsigned char getSoundId();
    
    unsigned char setHumitureId(char oldid,char newid);
    unsigned char getHumitureId();
    
    unsigned char setMotorId(uint8_t id_old, uint8_t id_new);
    unsigned char getMotorId();
    
    unsigned char setInfraredId(char oldid,char newid);
    unsigned char getInfraredId();
    void setSensorId();
 };
 #endif
