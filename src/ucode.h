#ifndef UKTEXPLORE_h
#define UKTEXPLORE_h

#include <Arduino.h>

// Supported Modules drive needs to be iddded here
#include "FlexiTimer2.h"
#include "ArduinoJson.h"
#include"onBoardHW.h"
#include "NewTone.h"
#include"TransforRobot.h"
#include"uKitMotor.h"
#include"uKitSensor.h"
#include"uKitServo.h"
#include "ClickButton.h"
#include"uKitId.h"
#include"Gyroscope.h"
const char* versionNumber="v1.2.0";

unsigned char lengthBuf[]={0};

boolean butonTimer=true;
uint8_t incomingByte = 0;          // 接收到的 data byte
String inputString = "";         // 用来储存接收到的内容
const char* snCode="";
boolean newLineReceived = false; // 前一次数据结束标志

char deciveSN[20]={0};



bool protocolRunState=true;
int timeTimes=0,timeFlag=0,buttonFlag=0;
OnBoardHW Sensor;
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


#define setEyelightPetalu(id,a,b) uKitSensor.setEyelightPetalu(id,a,b)
#define setEyelightSceneUntil(id,a,b) uKitSensor.setEyelightSceneUntil(id,a,b)
#define setEyelightLookUntil(id,a,b,c,d,e) uKitSensor.setEyelightLookUntil(id,a,b,c,d,e)
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
#define getCpuUUID() uKitId.getCpuUUID()
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
#define num1 Sensor.num1
#define num2 Sensor.num2
#define num3 Sensor.num3
#define num4 Sensor.num4
#define num5 Sensor.num5
#define getGrayAllValue() Sensor.getGrayAllValue()
#define readGrayValue(num,grayval) Sensor.readGrayValue(num,grayval)
#define setRgbledColor(red,green,blue) Sensor.setRgbledColor(red,green,blue)//板载RGB灯函数
#define setcolor(color) Sensor.setcolor(color)
#define readBatteryVoltage() Sensor.readBatteryVoltage()
#define readHcsr04Distance(jp) Sensor.readHcsr04Distance(jp) //超声波函数。返回cm,JP是位置，超声波若接在JP1,那么JP为1。
#define redPin Sensor.redPin
#define greenPin Sensor.greenPin
#define bluePin Sensor.bluePin
#define Button_pin Sensor.Button_pin
#define GrayscaleNum1 Sensor.GrayscaleNum1
#define GrayscaleNum2 Sensor.GrayscaleNum2
#define GrayscaleNum3 Sensor.GrayscaleNum3
#define GrayscaleNum4 Sensor.GrayscaleNum4
#define GrayscaleNum5 Sensor.GrayscaleNum5
#define IR_S Sensor.IR_S
#define buzzer_pin Sensor.buzzer_pin

void protocol();
void serialEvent();


//ClickButton_API
ClickButton button1(Button_pin, HIGH, CLICKBTN_PULLUP);//设置按键

void stopDecives(){
  digitalWrite(redPin,HIGH);//EN:Main board RGB lamp, R interface set to HIGH/CN:主板RGB灯，R接口设置为高电平输出.
  digitalWrite(greenPin,HIGH);//EN:Main board RGB lamp, G interface set to HIGH/CN:主板RGB灯，G接口设置为高电平输出.
  digitalWrite(bluePin,HIGH);//EN:Main board RGB lamp, B interface set to HIGH/CN:主板RGB灯，B接口设置为高电平输出.
  noNewTone(buzzer_pin);     
  setAllSensorOff();
  setMotorStop(0xff);
  StopServo();
  setUltrasonicRgbledOff(0x00);
  delay(2);
}

void flexiTimer2_func() {
  if(timeFlag==0){
     timeTimes+=1;
  }
  else{
    if(butonTimer==true){
   
    button1.Update();
    if(button1.clicks == 1){
      buttonFlag=1;   
    }
    if(button1.clicks == 2){
      buttonFlag=2;   
    }
    if(button1.clicks == -1){
      buttonFlag=-1;   
    }    
    }
  }
 
  
}
 void Initialization(){
 
  Sensor.checkVersion();
  delay(5);
  button1.ClickButtons(Button_pin, HIGH, CLICKBTN_PULLUP);
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
  pinMode(buzzer_pin,OUTPUT);
  
  delay(5);  //开机延时
  Wire.begin();
  setAllSensorOff();
  setMotorStop(0xff);
  StopServo();
  setUltrasonicRgbledOff(0x00);
  Serial.begin(115200);//EN:Initialize the serial port (baud rate 115200)/CN:初始化串口（波特率115200）
  delay(2); 
  Serial.write("AT+URATE=1000000");
  Serial.write(0x0D);
  Serial.write(0x0A);
  delay(2);
  if(EEPROM.read(0)!=48){
    for(int i=0;i<21;i++){
      EEPROM.write(i,0);
    }
  }
  Serial.begin(1000000);//EN:Initialize the serial port (baud rate 115200)/CN:初始化串口（波特率115200）
  delay(2);
  const size_t capacity = JSON_ARRAY_SIZE(3) + JSON_OBJECT_SIZE(1);
  DynamicJsonDocument doc(capacity);
  JsonArray data = doc.createNestedArray("data");
  data.add(versionNumber);
  data.add(Sensor.Version);
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  FlexiTimer2::set(20,flexiTimer2_func);
  FlexiTimer2::start();
  //getDeciveId();
  for(int i=0;i<600;i++){
  serialEvent();
  protocol();
  delayMicroseconds(300);
  }
 
  
  
}

void tone2(uint16_t frequency, unsigned long duration = 0)
{
  NewTone(buzzer_pin,frequency,duration);  
}
void noTone2(int pin)
{
  noNewTone(pin);  
}



void ProtocolParser(unsigned char device,unsigned char mode,unsigned char id,int* buf,const char* uuid,unsigned char* bin64,unsigned char *ids,int* par1,int* par2,int* par3,int* par4,int* par5,int* par6,int* par7,int* par8,int eyeTime){
  const size_t capacity = JSON_ARRAY_SIZE(8) + JSON_OBJECT_SIZE(8)+100;
  unsigned char* rgbValue=NULL;
  DynamicJsonDocument root(capacity);
  root["device"]=device;
  root["mode"]=mode;
  root["id"]=id;
  root["code"]=1;
  JsonArray data = root.createNestedArray("data");
  root["uuid"]=uuid;
  switch(device){
    case 1: //舵机
      butonTimer=false;
      buttonFlag=0; 
      switch(mode){
        case 127: //轮模式  
           setServoTurn(id,buf[0],buf[1]);     
           root["code"]=0;
           break;
        case 128: //角模式      
           setServoAngle(id,buf[0],buf[1]);
           root["code"]=0;
           break;    
        case 129://读取角度           
           root["code"]=0; 
           if(buf[0]==0){
            data.add(readServoAnglePD(id));  
           }
           else{
            data.add(readServoAngleNPD(id));
           }  
           break;
        case 130: //停止舵机       
           setServoStop(id);
           root["code"]=0;
           break;     
        case 131://多舵机轮模式
          uKitServo.setServoTurns(ids,par1,par2);
          root["code"]=0;
          break;
        case 132://多舵机角度模式
          uKitServo.setServoAngles(ids,par1,par2[0]);
          root["code"]=0;
          break;                                             
      }
      break;
    case 2:    //电机 
      butonTimer=false;
      buttonFlag=0; 
      switch(mode){
        case 127: //恒速转动  
           setMotorTurnAdj(id,buf[0],0xffff);     
           root["code"]=0;
           break;
        case 128: //pwm转动     
           setMotorTurn(id,buf[0]);
           root["code"]=0;
           break;    
        case 129://读取速度                    
           data.add(readMotorSpeed(id));  
           root["code"]=0; 
           break;
        case 130: //停止电机   
           setMotorStop(id);
           root["code"]=0;
           break; 
        case 131: //多电机恒速模式   
           uKitMotor.setMotorTurnAdjs(ids,par1);
           root["code"]=0;
           break;  
        case 132: //多电机pwm模式   
           uKitMotor.setMotorTurns(ids,par1);
           root["code"]=0;
           break;                                                  
      }
      break;
    case 3:    //眼灯 
      butonTimer=false;  
      buttonFlag=0; 
      switch(mode){
        case 127: //亮起眼灯
           setEyelightAllPetals(id,buf[0],buf[1],buf[2]);    
           root["code"]=0;
           break;
        case 128: //眼灯表情     
           setEyelightLook(id,buf[0],buf[4],buf[1],buf[2],buf[3]);
           root["code"]=0;
           break;    
        case 129://情景灯
           setEyelightScene(id,buf[0],buf[1]);
           root["code"]=0;   
           break;
        case 130: //关闭眼灯  
           setEyelightOff(id);
           root["code"]=0;
           break;    
        case 131: //自定义眼灯          
           setEyelightPetalu(id,8,buf);
           root["code"]=0;
           break;   
        case 132: //眼灯表情阻塞         
           setEyelightLookUntil(id,buf[0],buf[4],buf[1],buf[2],buf[3]);
           root["code"]=0;
           break;  
        case 133: //情景灯阻塞         
           setEyelightSceneUntil(id,buf[0],buf[1]);             
           root["code"]=0;
           break;             
        case 134: //多亮起眼灯
           for(int i=0;i<sizeof(ids)/sizeof(ids[0]);i++){
            setEyelightAllPetals(ids[i],par1[i],par2[i],par3[i]);   
           } 
           root["code"]=0;   
           break; 
        case 135: //多眼灯表情 
           for(int i=0;i<sizeof(ids)/sizeof(ids[0]);i++){    
            setEyelightLook(ids[i],par1[i],par2[i],par3[i],par4[i],par5[i]);
           }
           root["code"]=0;
           break; 
        case 136://多情景灯
          for(int i=0;i<sizeof(ids)/sizeof(ids[0]);i++){ 
           setEyelightScene(ids[i],par1[i],par2[i]);
          }
           root["code"]=0;   
           break;
        case 137: //多自定义眼灯    
          for(int i=0;i<sizeof(ids)/sizeof(ids[0]);i++){       
           uKitSensor.setEyelightPetalus(ids[i],par1[i],par2[i],par3[i],par4[i],par5[i],par6[i],par7[i],par8[i],eyeTime);
          }
           root["code"]=0; 
           break;          
        case 138: //多眼灯表情阻塞
          for(int i=0;i<sizeof(ids)/sizeof(ids[0]);i++){          
           setEyelightLookUntil(ids[i],par1[i],par2[i],par3[i],par4[i],par5[i]);
          }
           root["code"]=0;
           break;  
        case 139: //多情景灯阻塞     
          for(int i=0;i<sizeof(ids)/sizeof(ids[0]);i++){     
           setEyelightSceneUntil(ids[i],par1[i],par2[i]);    
          }         
           root["code"]=0;
           break;                                                                            
      }
      break;        
    case 4:    //传感器      
      butonTimer=false;   
      buttonFlag=0; 
      switch(mode){
        case 127: //超声波                           
           data.add(readUltrasonicDistance(id)); 
           root["code"]=0; 
           break;
        case 128: //红外     
           data.add(readInfraredDistance(id)); 
           root["code"]=0; 
           break;    
        case 129://按压
           data.add(readButtonValue(id));
           root["code"]=0; 
           break;
        case 130: //亮度  
           data.add(readLightValue(id));   
           root["code"]=0; 
           break;
         case 131: //声音     
           data.add(readSoundValue(id)); 
           root["code"]=0; 
           break;    
        case 132://温湿度
           if(buf[0]==0){
            data.add(readHumitureValue(id,'C'));
           }
           else if(buf[0]==1){
            data.add(readHumitureValue(id,'F'));
           }
           else if(buf[0]==2){
            data.add(readHumitureValue(id,'H'));
           }        
           root["code"]=0;       
           break;
        case 133: //颜色识别模式 
           switch(buf[0]){
            case 0:
              data.add(readColor(id,"Red"));
              break;
            case 1:
              data.add(readColor(id,"Green")); 
              break;    
            case 2:
              data.add(readColor(id,"Blue")); 
              break;
            case 3:
              data.add(readColor(id,"Yellow")); 
              break;                            
            case 4:
              data.add(readColor(id,"Cyan")); 
              break;
            case 5:
              data.add(readColor(id,"Purple")); 
              break;     
             case 6:
              data.add(readColor(id,"Orange")); 
              break;
            case 7:
              data.add(readColor(id,"Black")); 
              break;    
            case 8:
              data.add(readColor(id,"White")); 
              break;
            case 9:
              data.add(readColor(id,"Gray"));     
              break;                                                   
           }
           root["code"]=0;            
           break;  
        case 134: //颜色RGB模式           
           rgbValue=readColorRgb(id);
           data.add(rgbValue[0]);
           data.add(rgbValue[1]);
           data.add(rgbValue[2]);  
           root["code"]=0;                     
           break;    
        case 135: //ukit超声波灯光       
           setUltrasonicRgbled(id,buf[0],buf[1],buf[2]);
           root["code"]=0;                     
           break;  
        case 136: //关闭ukit超声波灯光 
           setUltrasonicRgbledOff(id);
           root["code"]=0;                      
           break;                                                                  
      }
      break;    
     case 5:    //板载蜂鸣器  
      butonTimer=false;    
      buttonFlag=0; 
      switch(mode){
        case 127: //播放音调                      
           tone2(buf[0],buf[1]);
           root["code"]=0; 
           break;
        case 128: //播放频率   
           tone2(buf[0],buf[1]); 
           root["code"]=0; 
           break;    
        case 129://结束声音
           noNewTone(buzzer_pin);     
           root["code"]=0; 
           break;                                           
      }
      break; 
     case 6:    //板载RGB  
      butonTimer=false;  
      buttonFlag=0; 
      switch(mode){
        case 127: //RGB                     
           setRgbledColor(buf[0],buf[1],buf[2]);
           root["code"]=0; 
           break;
        case 128: //播放频率   
           setRgbledColor(0,0,0);
           root["code"]=0; 
           break;                                            
      }
      break;   
     case 7: //电池电压   
      butonTimer=false;  
      buttonFlag=0; 
      if(mode==127){     
        data.add(readBatteryVoltage());  
        root["code"]=0;                  
      }                                  
      break;    
    case 8: //巡线传感器 
      butonTimer=false;      
      buttonFlag=0;  
      if(mode==127){            
        data.add(readGrayValue(id,buf[0]));   
        root["code"]=0;                
      }                                  
      break;  
     case 9: //陀螺仪  
      butonTimer=false;     
      buttonFlag=0;   
      if(mode==127){   
        float* gyronum=getMpu6050Data();        
        data.add(gyronum[0]);   
        data.add(gyronum[1]);   
        data.add(gyronum[2]);  
        root["code"]=0;  
        
        
                
      }                            
      break;
     case 10: //板载按键    
        delay(30); 
        if(mode==127){                
          data.add(buttonFlag); 
          buttonFlag=0; 
          root["code"]=0;                            
        }                                 
        break;
     case 11:    //ID相关    
      switch(mode){
      case 130: //停止设备
           root["code"]=0; 
           stopDecives();
           break;          
        case 127: //修改ID               
           uKitId.setAllDeciveId(buf[0],buf[1],buf[2]);
           delay(220);                
           if(buf[2]==uKitId.getAllDeciveId(buf[0],buf[2])){
            root["code"]=0;
           }
           else{
            root["code"]=1;
           }
           break;
        case 128: //获取ID   
          switch(buf[0]){
            case 0:
              uKitId.getDeciveIdJs(uuid);
              break;
            case 1:
              uKitId.getServoIdJs(uuid);
              break;
            case 2:
              uKitId.getMotorIdJs(uuid);
              break;              
            case 5:
              uKitId.getEyeLightIdJs(uuid);
              break;              
          }
           root["code"]=0;         
           break;    
      case 129: //检测固件  
           root["code"]=0;  
           strcpy(deciveSN,uKitId.read_String(0).c_str());
           data.add(0);   
           data.add(versionNumber);
           data.add(Sensor.Version);       
           data.add(deciveSN);
          
          break;   
      case 131: //获取版本号
        if(uKitSensor.getSensorVersion(id,buf[0])==170){
          root["code"]=0; 
        }            
        break;           
     case 132: //进入升级
        if(uKitSensor.setSensorUpdate(id,buf[0])==170){
          root["code"]=0; 
         
        }    
        break;    
     case 133: //正在升级
        if(uKitSensor.setSensorUpdating(id,buf[1],buf[2],bin64,buf[0])==170){
           setRgbledColor(255,0,0);
           delay(10);
           setRgbledColor(0,0,0);
           root["code"]=0; 
        }  
        
       
        break;        
     case 134: //结束升级
        if(uKitSensor.setSensorUpdated(id,buf[1],buf[0])==170){
          root["code"]=0; 
        }
        break;     
     case 135: //烧录SN  
          uKitId.writeString(0, snCode);  
          delay(5);
          //strcpy(deciveSN,uKitId.read_String(0).c_str());
          if(uKitId.read_String(0).c_str()!=0x00){
            root["code"]=0;     
            setRgbledColor(255,0,0);
            tone2(800,100);
            noNewTone(buzzer_pin);
            setRgbledColor(0,0,0);
           
          }
          else{
            root["code"]=1; 
          }      
        break;    
     case 136: //读取sn    
          strcpy(deciveSN,uKitId.read_String(0).c_str());
          root["sn"]=deciveSN;
          break;      
               
      }
      break;                             
    default:
      root["id"]=id;
      root["code"]=1;
      root["uuid"]=uuid;
      break;
  }
  if(device!=11 || mode!=128){
      uint16_t bufferLength=measureMsgPack(root);
      byte Buffer[2]={0};
      Buffer[0]=(bufferLength>>8)&0xff;
      Buffer[1]=(bufferLength)&0xff;
      Serial.write(Buffer,2); 
      serializeMsgPack(root,Serial);
      
      uuid="";
  }  

  
  
}

void serialEvent(){

  static int readFlag=0;
  static unsigned char g=0;
  static uint16_t dataLength=0;
  static uint16_t times=0;
  
  if (Serial.available() && readFlag==0) { 
     
    if(readFlag==0){
      Serial.readBytes(lengthBuf,2);    
      dataLength=lengthBuf[0]<<8 |lengthBuf[1];
      readFlag=1;
      
    } 
  }
  while(Serial.available()){   
    times++;
    incomingByte=Serial.read(); 
    inputString += (char) incomingByte;     // 全双工串口可以不用在下面加延时，半双工则要加的//  
    if (dataLength==times) {    
      newLineReceived = true;
      readFlag=0;
      g=0;
      times=0;
      dataLength=0;

    }
    
  }
 
   
}
void protocol(){  
  
    if (newLineReceived) { 
    const size_t capacity =JSON_ARRAY_SIZE(3) + JSON_ARRAY_SIZE(64) + JSON_OBJECT_SIZE(6) + 230; 
    DynamicJsonDocument root(capacity);  
    deserializeMsgPack(root,inputString);     
    int eyeTime=0,buf[9]={0},par1[18]={0},par2[18]={0},par3[10]={0},par4[10]={0},par5[10]={0},par6[10]={0},par7[10]={0},par8[10]={0}; 
    unsigned char bin64[64]={0},ids[18]={0};
    unsigned char device = root["device"];
    unsigned char mode = root["mode"];
    unsigned char id = root["id"];  
    const char* dataLen = root["data"];
    for(int i=0;i<sizeof(dataLen)/sizeof(dataLen[0]);i++){
       buf[i]  = root["data"][i];  
    }
    const char* uuid = root["uuid"];
    const char* idsLen = root["ids"];
    
    switch(device){   
      case 1:  
          if(mode==131 ||mode==132){  
            for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
              par1[i]  = root["ids"][i];  
            }
            for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
              par1[i]  = root["par1"][i];  
            }
            for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
              par2[i]  = root["par2"][i];  
            }   
          }   
        break;
      case 2:
          if(mode==131 ||mode==132){
            for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
              par1[i]  = root["ids"][i];  
            }
            for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
              par1[i]  = root["par1"][i];  
            }
          }
        break;      
      case 3: 
        if(mode>=132 &&mode<=139){  
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par1[i]  = root["ids"][i];  
          }
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par1[i]  = root["par1"][i];  
          }
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par2[i]  = root["par2"][i];  
          }
          if(mode==134|| mode==135 ||mode==138 || mode==137){
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par3[i]  = root["par3"][i];  
          } 
          }
          if(mode==135 ||mode==138 || mode==137){
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par4[i]  = root["par4"][i]; 
          }
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par5[i]  = root["par5"][i]; 
          }
          }
          if( mode==137){
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par6[i]  = root["par6"][i];  
          } 
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par7[i]  = root["par7"][i]; 
          }
          for(int i=0;i<sizeof(idsLen)/sizeof(idsLen[0]);i++){
            par8[i]  = root["par8"][i]; 
          }
          eyeTime=root["time"];
          }
        }        
        break;         
      case 10:
        butonTimer=true; 
        break;
      case 11:
        if(mode==135){
          snCode = root["sn"];
        }
        if(mode==133){
          for(int i=0;i<64;i++){
            bin64[i] = root["bin64"][i];
          }
        
        }
        break;
        
        
    }

    ProtocolParser(device,mode,id,buf,uuid,bin64,ids,par1,par2,par3,par4,par5,par6,par7,par8,eyeTime);
    inputString = "";   // clear the string       
    newLineReceived = false;
    timeFlag=1; 
    timeTimes=0;
    //FlexiTimer2::stop();
    uuid="";
    snCode="";
    protocolRunState=true;   
    
  }
  if(timeTimes>=5){
    protocolRunState=false;
    //FlexiTimer2::stop();
    timeFlag=1;
    timeTimes=0;

  }

}
void consoleLog(unsigned char level,  const String msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);   
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  const char *buf=NULL;
  buf=msg.c_str();
  doc["msg"] = buf;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  
  
}
void consoleLog(unsigned char level,  const char* msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);   
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  
  
}


void consoleLog(unsigned char level, const long msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  
  
}
void consoleLog(unsigned char level, const char msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  
  
}

void consoleLog(unsigned char level, const int msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  
  
}
void consoleLog(unsigned char level, const uint16_t msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  
}
void consoleLog(unsigned char level, const uint32_t msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  
}
void consoleLog(unsigned char level,const double msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  String gy = "";
  const char *buf=NULL;
  long tmp = msg;   // 整数部分
  long yytmp = abs((msg -tmp))*100+0.5;  //  小数部分; 从小数点后第三位做四舍五入(round)到第二位
  if(yytmp >= 100) {   // 防错
   yytmp=0;  
   ++tmp;  // 0.99xyz.. +0.005 ===>  1.0pqr...
  } // it is 0.99xyz...
  if(msg<0 &&tmp==0){
  gy += "-0"; // 整数部分
  gy += ".";  // 小数点, 废话
  if(yytmp < 10) gy += "0";
  gy += yytmp;
  }
  else{
  gy += tmp; // 整数部分
  gy += ".";  // 小数点, 废话
  if(yytmp < 10) gy += "0";
  gy += yytmp;
  }
  buf=gy.c_str();
  doc["level"] = level;
  doc["msg"] =buf;
  uint16_t bufferLength=measureMsgPack(doc);
  byte Buffer[2]={0};
  Buffer[0]=(bufferLength>>8)&0xff;
  Buffer[1]=(bufferLength)&0xff;
  Serial.write(Buffer,2); 
  serializeMsgPack(doc, Serial);
  

}







#endif
