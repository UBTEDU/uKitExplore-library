#ifndef UKTEXPLORE_h
#define UKTEXPLORE_h

#include <Arduino.h>

// Supported Modules drive needs to be iddded here

#include"Sensor2.h"
#include"TransforRobot.h"
#include"uKitMotor.h"
#include"uKitSensor.h"
#include"uKitServo.h"
#include "ClickButton.h"
#include"uKitId.h"
#include"Gyroscope.h"

Sensor2 Sensor2;
TransforRobot TransforRobot;
uKitMotor uKitMotor;
uKitServo uKitServo;
uKitSensor uKitSensor;
uKitId uKitId;
Gyroscope gyro;


//Gyroscope_API
#define getMpu6050Data() gyro.getMpu6050Data()



//uKitServo_API

#define setServoTurn(id,dir,speed) uKitServo.setServoTurn(id,dir,speed)//舵机轮模式控制，id是舵机号，dir是方向（1顺时针，0逆时针），speed是速度（0-5）
#define setServoAngle(id,angle,times) uKitServo.setServoAngle(id,angle,times)//舵机舵机模式，id是舵机号，angle是角度（-118°~118°），times是运行时间（300-5000）
#define setServoStop(id) uKitServo.setServoStop(id)//单个舵机停止函数
#define readServoAnglePD(id) uKitServo.readServoAnglePD(id)//单个舵机回读，返回舵机角度值(掉电回读）
#define readServoAnglePD_M(read_id,num) uKitServo.readServoAnglePD_M(read_id,num)//单个舵机回读，返回舵机角度值(掉电回读）
#define readServoAngleNPD(id) uKitServo.readServoAngleNPD(id)//单个舵机回读，返回舵机角度值(不掉电回读）
#define readServoAngleNPD_M(read_id,num) uKitServo.readServoAngleNPD_M(read_id,num)//单个舵机回读，返回舵机角度值(掉电回读）
#define playMotion(id,action,times) uKitServo.playMotion(id,action,times)//播放动作
//uKitSensor_API
#define setUltrasonicRgbled(id,r,g,b) uKitSensor.setUltrasonicRgbled(id,r,g,b)
#define setUltrasonicRgbledOff(id) uKitSensor.setUltrasonicRgbledOff(id)
#define setAllSensorOff() uKitSensor.setAllSensorOff()
#define readLightValue(id) uKitSensor.readLightValue(id)
#define readSoundValue(id) uKitSensor.readSoundValue(id)
#define readInfraredDistance(id) uKitSensor.readInfraredDistance(id)//ukit红外传感器控制函数，返回cm,(0-20)cm
#define Set_Infrared_Id(id) uKitSensor.Set_Infrared_Id(id)//设置红外ID
#define readColorRgb(id) uKitSensor.readColorRgb(id)
#define readColor(id,color) uKitSensor.readColor(id,color)
#define setColorOff(id) uKitSensor.setColorOff(id)
#define setEyelightLook(id,face,times,red,green,blue) uKitSensor.setEyelightLook(id,face,times,red,green,blue)//ukit led传感器。id为led的id号，face为表情种类（0）
#define setEyelightScene(id,scene,times) uKitSensor.setEyelightScene(id,scene,times)
#define setEyelightOff(id) uKitSensor.setEyelightOff(id)
#define setEyelightAllPetals(id,red,green,blue) uKitSensor.setEyelightAllPetals(id,red,green,blue)//ukit led传感器。id为led的id号，face为表情种类（0）
#define setEyelightPetals(id,petalnum,petals) uKitSensor.setEyelightPetals(id,petalnum,petals)
#define readHumitureValue(id,choice) uKitSensor.readHumitureValue(id,choice)
#define readButtonValue(id) uKitSensor.readButtonValue(id)//返回256无操作，返回257是单击，返回258是双击
#define readUltrasonicDistance(id) uKitSensor.readUltrasonicDistance(id)
#define setNixieTubeFull(id,tpye,method,frequency,times,start,ends) uKitSensor.setNixieTubeFull(id,tpye,method,frequency,times,start,ends)
#define setNixieTube(id,number) uKitSensor.setNixieTube(id,number)
#define redvalue uKitSensor.redvalue
#define greenvalue uKitSensor.greenvalue
#define bluevalue uKitSensor.bluevalue

//uKitMotor_API
#define setMotorTurn(id,pwmDuty) uKitMotor.setMotorTurn(id,pwmDuty)
#define setMotorTurnAdj(id,speed,time) uKitMotor.setMotorTurnAdj(id,speed,time)
#define readMotorSpeed(id) uKitMotor.readMotorSpeed(id)
#define setMotorStop(id) uKitMotor.setMotorStop(id)
#define MotorSetID(id_old,id_new) uKitMotor.MotorSetID(id_old,id_new)
#define MotorCheckID(id) uKitMotor.MotorCheckID(id)
#define StopServo() uKitMotor.StopServo()
//uKitId
#define setDeciveId() uKitId.setDeciveId()
#define getDeciveId() uKitId.getDeciveId()

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
    
//Sensor2_API
#define num1 Sensor2.num1
#define num2 Sensor2.num2
#define num3 Sensor2.num3
#define num4 Sensor2.num4
#define num5 Sensor2.num5
#define getGrayAllValue() Sensor2.getGrayAllValue()
#define readGrayValue(num,grayval) Sensor2.readGrayValue(num,grayval)
#define setRgbledColor(red,green,blue) Sensor2.setRgbledColor(red,green,blue)//板载RGB灯函数
#define setcolor(color) Sensor2.setcolor(color)
#define readBatteryVoltage() Sensor2.readBatteryVoltage()
#define readHcsr04Distance(jp) Sensor2.readHcsr04Distance(jp) //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。
#define redPin Sensor2.redPin
#define greenPin Sensor2.greenPin
#define bluePin Sensor2.bluePin
#define Button_pin Sensor2.Button_pin
#define GrayscaleNum1 Sensor2.GrayscaleNum1
#define GrayscaleNum2 Sensor2.GrayscaleNum2
#define GrayscaleNum3 Sensor2.GrayscaleNum3
#define GrayscaleNum4 Sensor2.GrayscaleNum4
#define GrayscaleNum5 Sensor2.GrayscaleNum5
#define IR_S Sensor2.IR_S
#define buzzer_pin Sensor2.buzzer_pin





//ClickButton_API
ClickButton button1(Button_pin, HIGH, CLICKBTN_PULLUP);//设置按键

 void Initialization(){
  
  pinMode(redPin, OUTPUT); //EN:Main board RGB lamp, R interface set to output/CN:主板RGB灯，R接口设置为输出.
  pinMode(greenPin, OUTPUT);//EN:Main board RGB lamp, G interface set to output/CN:主板RGB灯，G接口设置为输出.
  pinMode(bluePin, OUTPUT);//EN:Main board RGB lamp, B interface set to output/CN:主板RGB灯，B接口设置为输出.
  digitalWrite(redPin,HIGH);//EN:Main board RGB lamp, R interface set to HIGH/CN:主板RGB灯，R接口设置为高电平输出.
  digitalWrite(greenPin,HIGH);//EN:Main board RGB lamp, G interface set to HIGH/CN:主板RGB灯，G接口设置为高电平输出.
  digitalWrite(bluePin,HIGH);//EN:Main board RGB lamp, B interface set to HIGH/CN:主板RGB灯，B接口设置为高电平输出.
  pinMode(Button_pin,INPUT);
  pinMode(GrayscaleNum1, INPUT);  //左1的循迹传感器
  pinMode(GrayscaleNum2, INPUT);  //左2的循迹传感器
  pinMode(GrayscaleNum3, INPUT);  //中间的循迹传感器
  pinMode(GrayscaleNum4, INPUT);  //右2的循迹传感器
  pinMode(GrayscaleNum5, INPUT);  //右1的循迹传感器
  pinMode(IR_S,OUTPUT);
  pinMode(43, INPUT);    // 定义超声波输入脚
  pinMode(42, OUTPUT);   // 定义超声波输出脚 
  pinMode(41, INPUT);    // 定义超声波输入脚
  pinMode(40, OUTPUT);   // 定义超声波输出脚 
  pinMode(buzzer_pin,OUTPUT);
  delay(5);  //开机延时
  //check_servo();  //获取舵机个数,列表
  
  setAllSensorOff();
  setMotorStop(0xff);
  StopServo();
  setUltrasonicRgbledOff(0x00);
  Serial.begin(115200);//EN:Initialize the serial port (baud rate 115200)/CN:初始化串口（波特率115200）
  
  
  //getDeciveId();
 
  
  
}


#endif
