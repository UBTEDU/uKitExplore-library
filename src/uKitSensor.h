#ifndef UKITSENSOR_h
#define UKITSENSOR_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>

class uKitSensor : public SemiduplexSerial
{
public:
    
    unsigned char  uKit_Infrared(char ID);//ukit红外传感器控制函数，返回cm,(0-20)cm
    unsigned short int uKit_Sound_Read(char id);
    unsigned short int uKit_Light_Read(char id);
   
    //ukit led传感器。id为led的id号，face为表情种类（0眨眼，1伤心，2热泪盈眶，3泪光闪动，4哭泣，5晕，6开心，7惊讶，8呼吸，9闪烁，10风扇，11雨刮）,times是次数 ,rgb
    void uKit_Led_Face(char id,char face,int times,int red,int green,int blue);
    void uKit_Led_Scene(char id,char scene,int times);//情景模式 id是id号，scene是情景灯，times是次数
    void uKit_Leds(char id,int red,int green, int blue);//全亮模式， id是id号， RGB
    void uKit_Led_off(char id);
    unsigned char  uKit_RGB_Read(char id,unsigned char RGB);
   
    bool uKit_RGB_Readcolor(char id,char color);
    void uKit_RGB_off(char id);
    signed char uKit_Humiture(char id, char choice);
    int uKit_Button(char id);//返回256无操作，返回257是单击，返回258是双击
    int uKit_Ultrasonic(char id);
    //tpye:   0:静态显示    1：闪烁   2：递增   3：递减   4：显示时间  5：递增计时(类似秒表)  6：递减计时(类似秒表)
    //method :低四位表示数码管的控制个数，高四位表示下标点的控制方式，第8位：冒号显示位，9位：符号位
    //frequency: 100ms
    //times:闪烁次数：0：不闪烁，>0：表示实际次数。
    void uKit_NixieTube_Full(char id,uint8_t tpye,uint8_t method,uint8_t frequency,uint8_t times,uint8_t start,uint8_t ends);
    void uKit_NixieTube(char id,float number);
 
    
};

#endif

