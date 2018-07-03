#ifndef UKITID_h
#define UKITID_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>

class uKitId : public SemiduplexSerial
{
public:
	
    unsigned char setLightId(char oldid,char newid);
    unsigned char getLightId();
    unsigned char getLightId(char id);
    
    unsigned char setSoundId(char oldid,char newid);
    unsigned char getSoundId();
    unsigned char getSoundId(char id);
    
    unsigned char setHumitureId(char oldid,char newid);
    unsigned char getHumitureId();
    unsigned char getHumitureId(char id);
    
    unsigned char setMotorId(uint8_t id_old, uint8_t id_new);
    unsigned char getMotorId();
    unsigned char getMotorId(char id);
    
    unsigned char setInfraredId(char oldid,char newid);
    unsigned char getInfraredId();
    unsigned char getInfraredId(char id);

    unsigned char setLedId(char oldid,char newid);
    unsigned char getLedId();
    unsigned char getLedId(char id);

    unsigned char setButtonId(char oldid,char newid);
    unsigned char getButtonId();
    unsigned char getButtonId(char id);

    unsigned char setUltrasonicId(char oldid,char newid);
    unsigned char getUltrasonicId();
    unsigned char getUltrasonicId(char id);

    unsigned char setColorId(char oldid,char newid);
    unsigned char getColorId();  
    unsigned char getColorId(char id);  

    unsigned char setServoId(char oldid,char newid);
    unsigned char getServoId();   
    unsigned char getServoId(char id);  
    
    void setDeciveId();
    void getDeciveId();
    void getDeciveIds();

 };
 #endif
