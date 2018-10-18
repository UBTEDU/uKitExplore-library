#include "uKitExplore2.h"
#include "ArduinoJson/ArduinoJson.h"

int incomingByte = 0;          // 接收到的 data byte
String inputString = "";         // 用来储存接收到的内容
boolean newLineReceived = false; // 前一次数据结束标志
void ProtocolParser(unsigned char device,unsigned char mode,unsigned char id,int *buf);
void setup() {
    //Initialization();
    Serial.begin(115200);
      
}


void loop() {

  if (newLineReceived) {  
    StaticJsonBuffer<200> jsonBuffer;     
    JsonObject& root = jsonBuffer.parseObject(inputString);
    int buf[5]={0}; 
    unsigned char device = root["device"];
    unsigned char mode = root["mode"];
    unsigned char id = root["id"];
    buf[0]  = root["data"][0];
    buf[1]  = root["data"][1];
    buf[2]  = root["data"][2];
    buf[3]  = root["data"][3];
    buf[4]  = root["data"][4];    
    ProtocolParser(device,mode,id,buf);
    inputString = "";   // clear the string
   
    newLineReceived = false;
    
    
  }
}

void serialEvent(){
  while (Serial.available()) {  
    incomingByte = Serial.read();              //一个字节一个字节地读，下一句是读到的放入字符串数组中组成一个完成的数据包
    inputString += (char) incomingByte;     // 全双工串口可以不用在下面加延时，半双工则要加的//
    delay(2);   
    if (incomingByte == '\n') {    
      newLineReceived = true;

    }
  }
}
void ProtocolParser(unsigned char device,unsigned char mode,unsigned char id,int *buf){
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  JsonArray& data = root.createNestedArray("data"); 
  switch(device){
    case 1:    //舵机
      root["device"]=1;    
      switch(mode){
        case 127: //轮模式  
           setServoTurn(id,buf[0],buf[1]);     
           root["mode"]=127;
           root["id"]=id;
           root["code"]=0;
           break;
        case 128: //角模式      
           setServoAngle(id,buf[0],buf[1]);
           root["mode"]=128;
           root["id"]=id;
           root["code"]=0;
           break;    
        case 129://读取角度  
           
           root["mode"]=129;
           root["id"]=id;
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
           root["mode"]=130;
           root["id"]=id;
           root["code"]=0;
           break;                                      
      }
      break;
    case 2:    //电机
      root["device"]=2;    
      switch(mode){
        case 127: //恒速转动  
           setMotorTurnAdj(id,buf[0],0xffff);     
           root["mode"]=127;
           root["id"]=id;
           root["code"]=0;
           break;
        case 128: //pwm转动     
           setMotorTurn(id,buf[0]);
           root["mode"]=128;
           root["id"]=id;
           root["code"]=0;
           break;    
        case 129://读取速度 
          
           root["mode"]=129;
           root["id"]=id;
           root["code"]=0; 
           data.add(readMotorSpeed(id));        
           break;
        case 130: //停止电机   
           setMotorStop(id);
           root["mode"]=130;
           root["id"]=id;
           root["code"]=0;
           break;                                      
      }
      break;
    case 3:    //眼灯
      root["device"]=3;    
      switch(mode){
        case 127: //亮起眼灯
           setEyelightAllPetals(id,buf[0],buf[1],buf[2]);    
           root["mode"]=127;
           root["id"]=id;
           root["code"]=0;
           break;
        case 128: //眼灯表情     
           setEyelightLook(id,buf[0],buf[4],buf[1],buf[2],buf[3]);
           root["mode"]=128;
           root["id"]=id;
           root["code"]=0;
           break;    
        case 129://情景灯
           setEyelightScene(id,buf[0],buf[1]);
           root["mode"]=129;
           root["id"]=id;
           root["code"]=0;      
           break;
        case 130: //关闭眼灯  
           setEyelightOff(id);
           root["mode"]=130;
           root["id"]=id;
           root["code"]=0;
           break;                                      
      }
      break;        
    case 4:    //传感器
      root["device"]=4; 
      root["mode"]=0;
      root["id"]=id;
      root["code"]=1;            
      switch(mode){
        case 127: //超声波                      
           root["mode"]=127;
           root["id"]=id;
           root["code"]=0; 
           data.add(readUltrasonicDistance(id));  
           break;
        case 128: //红外     
           root["mode"]=128;
           root["id"]=id;
           root["code"]=0; 
           data.add( readInfraredDistance(id)); 
           break;    
        case 129://按压
           root["mode"]=129;
           root["id"]=id;
           root["code"]=0; 
           data.add(readButtonValue(id));     
           break;
        case 130: //亮度  
           root["mode"]=130;
           root["id"]=id;
           root["code"]=0; 
           data.add(readLightValue(id));   
         case 131: //声音     
           root["mode"]=131;
           root["id"]=id;
           root["code"]=0; 
           data.add(readSoundValue(id)); 
           break;    
        case 132://温湿度
           root["mode"]=132;
           root["id"]=id;
           root["code"]=0; 
           if(buf[0]==0){
            data.add(readHumitureValue(id,'C'));
           }
           else if(buf[0]==1){
            data.add(readHumitureValue(id,'F'));
           }
           else if(buf[0]==2){
            data.add(readHumitureValue(id,'H'));
           }                
           break;
        case 133: //颜色识别模式 
           root["mode"]=133;
           root["id"]=id;
           root["code"]=0; 
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
           break;  
        case 134: //颜色RGB模式 
           unsigned char *rgbValue=NULL;
           rgbValue=readColorRgb(id);
           root["mode"]=134;
           root["id"]=id;
           root["code"]=0; 
           data.add(rgbValue[0]);
           data.add(rgbValue[1]);
           data.add(rgbValue[2]);                         
           break;                                              
      }
      break;    
     case 5:    //板载蜂鸣器
      root["device"]=5; 
      root["mode"]=0;
      root["id"]=id;
      root["code"]=1;       
      switch(mode){
        case 127: //播放音调                      
           root["mode"]=127;
           root["code"]=0; 
           tone(buf[0],buf[1]);
           break;
        case 128: //播放频率   
           root["mode"]=128;         
           root["code"]=0; 
           tone(buf[0],buf[1]); 
           break;    
        case 129://结束声音
           root["mode"]=129;
           root["code"]=0; 
           noTone(43);     
           break;                                           
      }
      break; 
     case 6:    //板载RGB
      root["device"]=6; 
      root["mode"]=0;
      root["id"]=id;
      root["code"]=1;       
      switch(mode){
        case 127: //RGB                     
           root["mode"]=127;
           root["code"]=0; 
           setRgbledColor(buf[0],buf[1],buf[2]);
           break;
        case 128: //播放频率   
           root["mode"]=128;         
           root["code"]=0; 
           setRgbledColor(0,0,0);
           break;                                            
      }
      break;   
     case 7: //电池电压
      root["device"]=7; 
      root["mode"]=0;
      root["code"]=1;         
      if(mode==127){
        root["mode"]=127;
        root["code"]=0;      
        data.add(readBatteryVoltage());                   
      }                                       
      break;    
    case 8: //巡线传感器
      root["device"]=8; 
      root["mode"]=0;
      root["code"]=1;         
      if(mode==127){
        root["mode"]=127;
        root["id"]=id;
        root["code"]=0;        
        data.add(readGrayValue(id,buf[0]));                   
      }                                       
      break;  
     case 9: //陀螺仪
      root["device"]=9; 
      root["mode"]=0;
      root["code"]=1;         
      if(mode==127){
        float *value=NULL;
        value=getMpu6050Data();
        root["mode"]=127;
        root["code"]=0;       
        data.add(value[0]);   
        data.add(value[1]);   
        data.add(value[2]);                   
      }                                     
      break;
     case 10: //板载按键
      root["device"]=10; 
      root["mode"]=0;
      root["code"]=1;         
      if(mode==127){
        button1.Update();
        root["mode"]=127;
        root["code"]=0;       
        data.add(button1.clicks);                     
      }                                     
      break;
     case 11:    //ID相关
      root["device"]=11; 
      root["mode"]=0;
      root["id"]=id;
      root["code"]=1;       
      switch(mode){
        case 127: //修改ID                   
           root["mode"]=127;
           root["code"]=0; 
           uKitId.setAllDeciveId(buf[0],buf[1],buf[2]);
           break;
        case 128: //获取ID   
           uKitId.getDeciveIdJs();
           root["code"]=0;
           root["mode"]=128;
           break;                                            
      }
      break;                             
    default:
      root["id"]=id;
      root["code"]=1;
  }
  if(device!=11 & mode!=128){
      root.printTo(Serial);
      Serial.print('\n');
  }


  
}
