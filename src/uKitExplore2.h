#ifndef UKTEXPLORE_h
#define UKTEXPLORE_h

#include <Arduino.h>

// Supported Modules drive needs to be iddded here
#include"Port2.h"
#include"Sensor.h"
#include"TransforRobot.h"
#include"uKitMotor.h"
#include"uKitSensor.h"
#include"uKitServo.h"
#include "ClickButton.h"
#include"uKitId.h"


Port2 Port2;
Sensor Sensor;
TransforRobot TransforRobot;
uKitMotor uKitMotor;
uKitServo uKitServo;
uKitSensor uKitSensor;
uKitId uKitId;



//Port_API
#define Button_pin Port2.Button_pin
#define Initialization() Port2.Initialization()
//uKitServo_API

#define ServoRotate(id,dir,speed) uKitServo.ServoRotate(id,dir,speed)//舵机轮模式控制，id是舵机号，dir是方向（1顺时针，0逆时针），speed是速度（0-5）
#define ServoAngle(id,angle,times) uKitServo.ServoAngle(id,angle,times)//舵机舵机模式，id是舵机号，angle是角度（-118°~118°），times是运行时间（300-5000）
#define ServoStop(id) uKitServo.ServoStop(id)//单个舵机停止函数
#define ServoRead_PD(id) uKitServo.ServoRead_PD(id)//单个舵机回读，返回舵机角度值(掉电回读）
#define ServoRead_PD_M(read_id,num) uKitServo.ServoRead_PD_M(read_id,num)//单个舵机回读，返回舵机角度值(掉电回读）
#define ServoRead_NPD(id) uKitServo.ServoRead_NPD(id)//单个舵机回读，返回舵机角度值(不掉电回读）
#define ServoRead_NPD_M(read_id,num) uKitServo.ServoRead_NPD_M(read_id,num)//单个舵机回读，返回舵机角度值(掉电回读）

//uKitSensor_API


#define uKit_Light_Read(id) uKitSensor.uKit_Light_Read(id)
#define uKit_Sound_Read(id) uKitSensor.uKit_Sound_Read(id)
#define uKit_Infrared(id) uKitSensor.uKit_Infrared(id)//ukit红外传感器控制函数，返回cm,(0-20)cm
#define Set_Infrared_Id(id) uKitSensor.Set_Infrared_Id(id)//设置红外ID
#define uKit_RGB_Read(id,rgb) uKitSensor.uKit_RGB_Read(id,rgb)
#define uKit_RGB_Readcolor(id,color) uKitSensor.uKit_RGB_Readcolor(id,color)
#define uKit_RGB_off(id) uKitSensor.uKit_RGB_off(id)
#define uKit_Led_Face(id,face,times,red,green,blue) uKitSensor.uKit_Led_Face(id,face,times,red,green,blue)//ukit led传感器。id为led的id号，face为表情种类（0）
#define uKit_Led_Scene(id,scene,times) uKitSensor.uKit_Led_Scene(id,scene,times)
#define uKit_Led_off(id) uKitSensor.uKit_Led_off(id)
#define uKit_Leds(id,red,green,blue) uKitSensor.uKit_Leds(id,red,green,blue)//ukit led传感器。id为led的id号，face为表情种类（0）
#define uKit_Humiture(id,choice) uKitSensor.uKit_Humiture(id,choice)
#define uKit_Button(id) uKitSensor.uKit_Button(id)//返回256无操作，返回257是单击，返回258是双击
#define uKit_Ultrasonic(id) uKitSensor.uKit_Ultrasonic(id)
#define uKit_NixieTube_Full(id,tpye,method,frequency,times,start,ends) uKitSensor.uKit_NixieTube_Full(id,tpye,method,frequency,times,start,ends)
#define uKit_NixieTube(id,number) uKitSensor.uKit_NixieTube(id,number)
#define redvalue uKitSensor.redvalue
#define greenvalue uKitSensor.greenvalue
#define bluevalue uKitSensor.bluevalue
//uKitMotor_API
#define MotorRotate(id,pwmDuty) uKitMotor.MotorRotate(id,pwmDuty)
#define MotorRotateAdj(id,speed,time) uKitMotor.MotorRotateAdj(id,speed,time)
#define MotorReadSpeed(id) uKitMotor.MotorReadSpeed(id)
#define MotorStop(id) uKitMotor.MotorStop(id)
#define MotorSetID(id_old,id_new) uKitMotor.MotorSetID(id_old,id_new)
#define MotorCheckID(id) uKitMotor.MotorCheckID(id)

//uKitId
#define setDeciveId() uKitId.setDeciveId()
//TransforRobot_API
#define forward(a) TransforRobot.forward(a)//小车前进函数，速度0-5
#define turnL(speed) TransforRobot.turnL(speed)//小车左转，速度0-5
#define turnR(speed) TransforRobot.turnR(speed)//小车右转，速度0-5
#define back(speed) TransforRobot.back(speed)//小车后退函数，速度0-5
#define stops() TransforRobot.stops()//小车停止函数
#define turn_L(speed) TransforRobot.turn_L(speed)
#define turn_R(speed) TransforRobot.turn_R(speed)
#define turn_U(speed) TransforRobot.turn_U(speed)
#define one_step(speed,time) TransforRobot.one_step(speed,time)
#define motion_case(cases,times) TransforRobot.motion_case(cases,times)
#define motion_forward(times) TransforRobot.motion_forward(times)//人形模式前进
#define motion_car(times) TransforRobot.motion_car(times)//保持车形态
#define motion_getup(times) TransforRobot.motion_getup(times)//车变人
#define motion_sitdown(times) TransforRobot.motion_sitdown(times)//人变车
#define motion_back(times) TransforRobot.motion_back(times)//人形模式后退
#define motion_left_shift(times) TransforRobot.motion_left_shift(times)//人形模式左移
#define motion_right_shift(times) TransforRobot.motion_right_shift(times)//人形模式右移
#define motion_turn_left(times) TransforRobot.motion_turn_left(times)//人形模式左拐
#define motion_turn_right(times) TransforRobot.motion_turn_right(times)//人形模式右拐
#define motion_omotion(times) TransforRobot.motion_omotion(times)//保持人形态
#define motion_button(times) TransforRobot.motion_button(times)//人形按键
#define motion_lift(times) TransforRobot.motion_lift(times)//让机器人举起右手. times表示执行动作的次数。一次为一步动作。
#define motion_lift_hand(times) TransforRobot.motion_lift_hand(times)//让机器人举起双手. times表示执行动作的次数。一次为一步动作。
#define motion_head(times) TransforRobot.motion_head(times)//拆引爆雷
#define motion_zero(times) TransforRobot.motion_zero(times)//零状态
    
//Sensor_API
#define num1 Sensor.num1
#define num2 Sensor.num2
#define num3 Sensor.num3
#define num4 Sensor.num4
#define num5 Sensor.num5
#define tone(frequency,duration) Sensor.tone(frequency,duration)
#define noTone(pin) Sensor.noTone(pin)
#define read_data() Sensor.read_data()
#define read_gray(num,grayval) Sensor.read_gray(num,grayval)
#define colorRGB(red,green,blue) Sensor.colorRGB(red,green,blue)//板载RGB灯函数
#define setcolor(color) Sensor.setcolor(color)
#define Battery_check() Sensor.Battery_check()
#define HcSr04Dis(jp) Sensor.HcSr04Dis(jp) //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。


//ClickButton_API
ClickButton button1(Button_pin, HIGH, CLICKBTN_PULLUP);//设置按键



#endif
