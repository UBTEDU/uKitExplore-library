#ifndef UKITSENSOR_h
#define UKITSENSOR_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>
class uKitSensor : public SemiduplexSerial
{
public:
    
    float uKit_Infrared(char ID);//ukit红外传感器控制函数，返回cm,(0-20)cm
    void Set_Infrared_Id(char id);//设置红外ID
    void uKit_Led(char id,char face,int times,int red,int green,int blue);//ukit led传感器。id为led的id号，face为表情种类（0）
    unsigned char uKit_RGB_Read(char id,unsigned char RGB);
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

