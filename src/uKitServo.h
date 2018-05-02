

#ifndef UKITSERVO_h
#define UKITSERVO_h
#include"SemiduplexSerial.h" 
#include <Arduino.h>
class uKitServo : public SemiduplexSerial
{
public:

  void ServoRotate(char id,int dir, int speed);//舵机轮模式控制，id是舵机号，dir是方向（1顺时针，0逆时针），speed是速度（0-5）
  void ServoAngle(char id,int angle, int times);//舵机舵机模式，id是舵机号，angle是角度（-118°~118°），times是运行时间（300-5000）
  void ServoStop(char id);//单个舵机停止函数
  int  ServoRead_PD(char id);//单个舵机回读，返回舵机角度值(掉电回读）
  void ServoRead_PD_M(char read_id[],char num);//多个舵机回读，返回舵机角度值(掉电回读）
  int  ServoRead_NPD(char id);//单个舵机回读，返回舵机角度值(不掉电回读）
  void  ServoRead_NPD_M(char read_id[],char num);//多个舵机回读，返回舵机角度值(不掉电回读）
  int read_num=1;
};

#endif

