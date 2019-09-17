#ifndef UKITID_h
#define UKITID_h
#include"SemiduplexSerial.h" 
#include"EEPROM.h"
#include <Arduino.h>
#define EEPROM_START_ADDRESS    0     // Start Address in EEPROM
#define EEPROM_SIZE             1024  // EEPROM size
class uKitId : public SemiduplexSerial
{
public:
	  String getCpuUUID();
    unsigned char setLightId(char oldid,char newid);
    unsigned char getLightId();
    unsigned char getLightId(char id);
    void motorclear(unsigned char id);
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


    unsigned char setServoId1M(char oldid,char newid);
    unsigned char getServoId1M();   
    unsigned char getServoId1M(char id);  
    
    void setDeciveId();
    void setAllDeciveId(unsigned char decive,unsigned char oldid,unsigned char newid);
    unsigned char getAllDeciveId(unsigned char decive,unsigned char newid);

    void setAllDeciveId1M(unsigned char decive,unsigned char oldid,unsigned char newid);
    unsigned char getAllDeciveId1M(unsigned char decive,unsigned char newid);
    void setDeciveIdEn();
    void setDeciveIdKo();
    void setDeciveIdTh();
    void setDeciveIdRu();
    void getDeciveId();
    void getDeciveIdJs(const String uuid);
    void getServoIdJs(const String uuid);
    void getMotorIdJs(const String uuid);
    void getEyeLightIdJs(const String uuid);
    void getDeciveIdJs1M(const String uuid);
   
    void getDeciveIdEn();
    void getDeciveIdKo();
    void getDeciveIdTh();
    void getDeciveIdRu();
    void writeString(char add,String data);
    String read_String(char add);



      

 };
 #endif
