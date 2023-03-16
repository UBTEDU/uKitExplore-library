

#ifndef UKITSERVO_h
#define UKITSERVO_h
#include"SemiduplexSerial.h" 
#include"uKitId.h"
#include <Arduino.h>
class uKitServo : public uKitId
{
public:

  void setServoTurn(unsigned char id,int dir, int speed);//舵机轮模式控制，id是舵机号，dir是方向（0顺时针，1逆时针），speed是速度（0-255）
  void setServoTurns(unsigned char *id,int *dir, int *speed, unsigned char length);//舵机轮模式控制，id是舵机号，dir是方向（0顺时针，1逆时针），speed是速度（0-255）
  void setServoStiffness(unsigned char id, unsigned char stiffness);
  void setServoAngle(unsigned char id,int angle, int times);//舵机舵机模式，id是舵机号，angle是角度（-118°~118°），times是运行时间（300-5000）
  void setServoAngles(unsigned char *id, int *angle, int *times, unsigned char length, bool wait = true);
  void setServoAnglesWait(unsigned char *id, int *angle, int *times, unsigned char length, bool wait);

  void setServoStop(unsigned char id);//单个舵机停止函数
  void setServosStop(unsigned char *ids, unsigned char length);//多个舵机停止函数
  int  readServoAnglePD(unsigned char id);//单个舵机回读，返回舵机角度值(掉电回读）
  int  readServoOriginalAnglePD(unsigned char id);//单个舵机回读，返回舵机角度值(掉电回读）
  void readServoAnglePD_M(unsigned char *read_id,char num);//多个舵机回读，返回舵机角度值(掉电回读）
  int  readServoAngleNPD(unsigned char id);//单个舵机回读，返回舵机角度值(不掉电回读）
  int  readServoOriginalAngleNPD(unsigned char id);//单个舵机回读，返回舵机角度值(不掉电回读）
  void readServoAngleNPD_M(unsigned char *read_id,char num);//多个舵机回读，返回舵机角度值(不掉电回读）
  void ServoRead();
  
  void playMotion(unsigned char *id,signed char **action,int *times);


  void setServoTurn1M(unsigned char id,int dir, int speed);//舵机轮模式控制，id是舵机号，dir是方向（1顺时针，0逆时针），speed是速度（0-5）
  void setServoStiffness1M(unsigned char id,unsigned char stiffness);
  void setServoAngle1M(unsigned char id,int angle, int times);//舵机舵机模式，id是舵机号，angle是角度（-118°~118°），times是运行时间（300-5000）

  void setServoStop1M(unsigned char id);//单个舵机停止函数
  int  readServoAnglePD1M(unsigned char id);//单个舵机回读，返回舵机角度值(掉电回读）
  int  readServoAngleNPD1M(unsigned char id);//单个舵机回读，返回舵机角度值(不掉电回读） 
  void playMotion1M(unsigned char *id,signed char **action,int *times);
  int read_num=1;
};

#endif
