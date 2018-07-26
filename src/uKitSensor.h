#ifndef UKITSENSOR_h
#define UKITSENSOR_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>

class uKitSensor : public SemiduplexSerial
{
public:
    
    unsigned char  readInfraredDistance(char ID);//ukit红外传感器控制函数，返回cm,(0-20)cm
    unsigned short int readSoundValue(char id);
    unsigned short int readLightValue(char id);
   
    //ukit led传感器。id为led的id号，face为表情种类（0眨眼，1伤心，2热泪盈眶，3泪光闪动，4哭泣，5晕，6开心，7惊讶，8呼吸，9闪烁，10风扇，11雨刮）,times是次数 ,rgb
    void setEyelightLook(char id,char face,int times,int red,int green,int blue);
    void setEyelightScene(char id,char scene,int times);//情景模式 id是id号，scene是情景灯，times是次数
    void setEyelightAllPetals(char id,int red,int green, int blue);//全亮模式， id是id号， RGB
    void setEyelightPetals(char id,unsigned char petalsnum,unsigned char petals[8][4]);
    void setEyelightOff(char id);
    unsigned char  readColorRgb(char id,unsigned char RGB);
   
    bool readColor(char id,String color);
    void setColorOff(char id);
    signed char readHumitureValue(char id, char choice);
    int readButtonValue(char id);//返回256无操作，返回257是单击，返回258是双击
    int readUltrasonicDistance(char id);
    //tpye:   0:静态显示    1：闪烁   2：递增   3：递减   4：显示时间  5：递增计时(类似秒表)  6：递减计时(类似秒表)
    //method :低四位表示数码管的控制个数，高四位表示下标点的控制方式，第8位：冒号显示位，9位：符号位
    //frequency: 100ms
    //times:闪烁次数：0：不闪烁，>0：表示实际次数。
    void setNixieTubeFull(char id,uint8_t tpye,uint8_t method,uint8_t frequency,uint8_t times,uint8_t start,uint8_t ends);
    void setNixieTube(char id,float number);
 
    
};

#endif

