#ifndef UKTEXPLORE_h
#define UKTEXPLORE_h

#include <Arduino.h>

// Supported Modules drive needs to be iddded here
#include "FlexiTimer2.h"
#include "ArduinoJson.h"
#include"onBoardHW.h"
#include"TransforRobot.h"
#include"uKitMotor.h"
#include"uKitSensor.h"
#include"uKitServo.h"
#include "ClickButton.h"
#include"uKitId.h"
#include"Gyroscope.h"
const char* versionNumber="v1.1.4";

uint64_t incomingByte = 0;          // 接收到的 data byte
String inputString = "";         // 用来储存接收到的内容
const char* snCode="";
boolean newLineReceived = false; // 前一次数据结束标志
float *values=NULL;


unsigned char *rgbValue=NULL;

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
  noTone(buzzer_pin);     
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
  const size_t capacity = JSON_ARRAY_SIZE(3) + JSON_OBJECT_SIZE(1);
  DynamicJsonDocument doc(capacity);
  JsonArray data = doc.createNestedArray("data");
  data.add(versionNumber);
  data.add(Sensor.Version);
  data.add(getCpuUUID());
  
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
  FlexiTimer2::set(20,flexiTimer2_func);
  FlexiTimer2::start();
  //getDeciveId();
  
  serialEvent();
  delay(150);
  protocol();
 
  
  
}



void ProtocolParser(unsigned char device,unsigned char mode,unsigned char id,int *buf,const char* uuid){
  const size_t capacity = JSON_ARRAY_SIZE(6) + JSON_OBJECT_SIZE(5)+40;
  DynamicJsonDocument root(capacity);
  root["device"]=device;
  root["mode"]=mode;
  root["id"]=id;
  root["code"]=1;
  JsonArray data = root.createNestedArray("data");
  root["uuid"]=uuid;

  switch(device){
    case 1: //舵机
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
      }
      break;
    case 2:    //电机 
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
      }
      break;
    case 3:    //眼灯   
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
      }
      break;        
    case 4:    //传感器         
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
           delete [] rgbValue;   
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
      switch(mode){
        case 127: //播放音调                      
           tone(buzzer_pin,buf[0],0);
           root["code"]=0; 
           break;
        case 128: //播放频率   
           tone(buzzer_pin,buf[0],0); 
           root["code"]=0; 
           break;    
        case 129://结束声音
           noTone(buzzer_pin);     
           root["code"]=0; 
           break;                                           
      }
      break; 
     case 6:    //板载RGB    
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
      if(mode==127){     
        data.add(readBatteryVoltage());  
        root["code"]=0;                  
      }                                  
      break;    
    case 8: //巡线传感器        
      if(mode==127){            
        data.add(readGrayValue(id,buf[0]));   
        root["code"]=0;                
      }                                  
      break;  
     case 9: //陀螺仪         
      if(mode==127){     
        values=getMpu6050Data();        
        data.add(values[0]);   
        data.add(values[1]);   
        data.add(values[2]);  
        root["code"]=0;  
        delete [] values;             
      }                            
      break;
     case 10: //板载按键      
        if(mode==127){                
          data.add(buttonFlag); 
          delay(2); 
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
           delay(120);                
           if(buf[2]==uKitId.getAllDeciveId(buf[0],buf[2])){
            root["code"]=0;
           }
           else{
            root["code"]=1;
           }
           break;
        case 128: //获取ID   
           uKitId.getDeciveIdJs(uuid);
           root["code"]=0;         
           break;    
      case 129: //检测固件  
           root["code"]=0; 
           data.add(0);   
           data.add(versionNumber);
           data.add(Sensor.Version);
           data.add(getCpuUUID());
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
        if(uKitSensor.setSensorUpdating(id,buf[1],buf[2],buf[3],buf[0])==170){
           root["code"]=0; 
        }      
        break;        
     case 134: //结束升级
        if(uKitSensor.setSensorUpdated(id,buf[1],buf[0])==170){
          root["code"]=0; 
        }
        break;     
     case 135: //烧录SN
          const char *getSnCode="";
          uKitId.EEPROM_clear_all(10);
          delay(5);
          uKitId.EEPROM_write_block((unsigned char*)&snCode,0, 6);  
          delay(5);
          uKitId.EEPROM_read_block((unsigned char*)&getSnCode, 0, 6);
          if(snCode==getSnCode){
            root["code"]=0; 
            tone(buzzer_pin,800,0);
            setRgbledColor(255,0,0);
            delay(10);
            noTone(buzzer_pin);
            setRgbledColor(0,0,0);
             
          }
          else{
            root["code"]=1; 
          }      
        break;    
     case 136: //读取sn
          const char *getSnCodes="";
          uKitId.EEPROM_read_block((unsigned char*)&getSnCodes, 0, 6);   
          root["sn"]=getSnCodes;  
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
      serializeMsgPack(root,Serial);
      Serial.print(' ');
      uuid="";
  }  

  
  
}
void serialEvent(){
  if (Serial.available()) {  
    incomingByte = Serial.read();              //一个字节一个字节地读，下一句是读到的放入字符串数组中组成一个完成的数据包
    inputString += (char) incomingByte;     // 全双工串口可以不用在下面加延时，半双工则要加的//   
    if (incomingByte == ' ') {    
      newLineReceived = true;

    }
  }
   
}
void protocol(){  
  
    if (newLineReceived) { 
    const size_t capacity = JSON_ARRAY_SIZE(6) + JSON_OBJECT_SIZE(5) + 40;  
    DynamicJsonDocument root(capacity);  
    deserializeMsgPack(root,inputString);     
    int buf[5]={0}; 
    unsigned char device = root["device"];
    unsigned char mode = root["mode"];
    unsigned char id = root["id"];   
    buf[0]  = root["data"][0];
    buf[1]  = root["data"][1];
    buf[2]  = root["data"][2];
    buf[3]  = root["data"][3];
    buf[4]  = root["data"][4];    
    const char* uuid = root["uuid"];
    if(device==11 && mode==135){
      snCode = root["sn"];
    }
    ProtocolParser(device,mode,id,buf,uuid);
    inputString = "";   // clear the string       
    newLineReceived = false;
    timeFlag=1; 
    timeTimes=0;
    //FlexiTimer2::stop();
    uuid="";
    protocolRunState=true;   
    
  }
  if(timeTimes>=10){
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
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
  
}
void consoleLog(unsigned char level,  const char* msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);   
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
  
}


void consoleLog(unsigned char level, const long msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
  
}
void consoleLog(unsigned char level, const char msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
  
}

void consoleLog(unsigned char level, const int msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
  
}
void consoleLog(unsigned char level, const uint16_t msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
}
void consoleLog(unsigned char level, const uint32_t msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
}
void consoleLog(unsigned char level,const double msg){
  const size_t capacity = JSON_OBJECT_SIZE(2);
  DynamicJsonDocument doc(capacity);
  doc["level"] = level;
  doc["msg"] = msg;
  serializeMsgPack(doc, Serial);
  Serial.print(' ');
}


void tone2(uint16_t frequency, long duration)
{
  int period = 1000000L / frequency;
  int pulse = period / 2;
  pinMode(buzzer_pin, OUTPUT);
  if(duration==0)
    tone(buzzer_pin,frequency,0);
    else{
  for (long i = 0; i < duration * 1000L; i += period) 
  {
    digitalWrite(buzzer_pin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(buzzer_pin, LOW);
    delayMicroseconds(pulse);
   
  }
    }
}

#endif
