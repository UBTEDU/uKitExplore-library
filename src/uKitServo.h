

#ifndef UKITSERVO_h
#define UKITSERVO_h
#include"SemiduplexSerial.h" 
#include"uKitId.h"
#include <Arduino.h>
class uKitServo : public uKitId
{
public:

  void setServoTurn(char id,int dir, int speed);//舵机轮模式控制，id是舵机号，dir是方向（1顺时针，0逆时针），speed是速度（0-5）
  void setServoStiffness(char id,unsigned char stiffness);
  void setServoAngle(char id,int angle, int times);//舵机舵机模式，id是舵机号，angle是角度（-118°~118°），times是运行时间（300-5000）

  void setServoStop(char id);//单个舵机停止函数
  int  readServoAnglePD(char id);//单个舵机回读，返回舵机角度值(掉电回读）
  void readServoAnglePD_M(char read_id[],char num);//多个舵机回读，返回舵机角度值(掉电回读）
  int  readServoAngleNPD(char id);//单个舵机回读，返回舵机角度值(不掉电回读）
  void  readServoAngleNPD_M(char read_id[],char num);//多个舵机回读，返回舵机角度值(不掉电回读）
  void ServoRead();
  
  void playMotion(signed char *id,signed char **action,int *times);
  int read_num=1;
};

#endif
