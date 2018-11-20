#include"uKitId.h" 
#include "ArduinoJson/ArduinoJson.h"
unsigned char uKitId::setLightId(char oldid,char newid){
  unsigned short int tRet = 0;
  unsigned char buf[11];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x06;//设备类型
  buf[2] = 0x08;//长度
  buf[3] = 0x06;//命令号
  buf[4] = oldid;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = (newid & 0xFF00) >> 8;//new id
  buf[10] = newid & 0x00FF;//new id
  buf[11] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(12,buf);
  return tRet;
}

unsigned char uKitId::getLightId(){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x06;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = 0xff;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  return tRet;
}
unsigned char uKitId::getLightId(char id){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x06;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = id;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  return tRet;
}
unsigned char uKitId::setSoundId(char oldid,char newid){
  unsigned short int tRet = 0;
  unsigned char buf[11];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x10;//设备类型
  buf[2] = 0x08;//长度
  buf[3] = 0x06;//命令号
  buf[4] = oldid;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = (newid & 0xFF00) >> 8;//new id
  buf[10] = newid & 0x00FF;//new id
  buf[11] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(12,buf);
  return tRet;
}

unsigned char uKitId::getSoundId(){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x10;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = 0xff;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  return tRet;
}
unsigned char uKitId::getSoundId(char id){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x10;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = id;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  return tRet;
}

unsigned char uKitId::setHumitureId(char oldid,char newid){
  unsigned short int tRet = 0;
  unsigned char buf[11];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x05;//设备类型
  buf[2] = 0x08;//长度
  buf[3] = 0x06;//命令号
  buf[4] = oldid;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = (newid & 0xFF00) >> 8;//new id
  buf[10] = newid & 0x00FF;//new id
  buf[11] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(12,buf);
  return tRet;
}

unsigned char uKitId::getHumitureId(){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x05;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = 0xff;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  return tRet;
}
unsigned char uKitId::getHumitureId(char id){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x05;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = id;//id
  buf[5] = 0x00;//参数
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  return tRet;
}
unsigned char uKitId::setMotorId(uint8_t id_old, uint8_t id_new){
  unsigned long tRet = 0;
  unsigned char buf[12];  
  buf[0] = 0xFB;
  buf[1] = 0x03;
  buf[2] = 0x08;
  buf[3] = 0x06;
  buf[4] = id_old;
  buf[5] = 0x00;
  buf[6] = 0x03;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = 0x00;
  buf[10] = id_new;
  buf[11] = crc8_itu(&buf[1], buf[2]+2);
  tRet=IdTxd(12,buf); 
  
  return tRet;
}

unsigned char uKitId::getMotorId(){
  unsigned char tRet = 0;
  unsigned char buf[10];
  for(int testid=1;testid<=18;testid++){
    buf[0] = 0xFB;//帧头
    buf[1] = 0x03;//设备类型
    buf[2] = 0x06;//长度
    buf[3] = 0x05;//命令号
    buf[4] = testid;//ID
    buf[5] = 0x00;//参数
    buf[6] = 0x09;
    buf[7] = 0x00;
    buf[8] = 0x05;
    buf[9] = crc8_itu(&buf[1], buf[2]+2);

    tRet=IdTxd(10,buf);
    delay(5);
    if(tRet==testid){
      return tRet;
    }
    delay(5);
  
  }
   return 0;
}
unsigned char uKitId::getMotorId(char id){
  unsigned char tRet = 0;
  unsigned char buf[10];
    buf[0] = 0xFB;//帧头
    buf[1] = 0x03;//设备类型
    buf[2] = 0x06;//长度
    buf[3] = 0x05;//命令号
    buf[4] = id;//ID
    buf[5] = 0x00;//参数
    buf[6] = 0x09;
    buf[7] = 0x00;
    buf[8] = 0x05;
    buf[9] = crc8_itu(&buf[1], buf[2]+2);
    tRet=IdTxd(10,buf); 
    delay(5);  
    return tRet; 
}
unsigned char uKitId::setInfraredId(char oldid,char newid){
  unsigned char tRet = 0;
  unsigned char buf[2];
  buf[0]=oldid;
  buf[1]=newid;
  tRet=TXD(0xF8,1,2,0x06,buf);
  delay(5);
  return tRet;
 
}
unsigned char uKitId::getInfraredId(){
  unsigned char tRet = 0;
  unsigned char buf[1];
  for(int testid=1;testid<=10;testid++){
    buf[0]=testid;
    tRet=TXD(0xF8,1,1,0x07,buf);
    delay(5);
    if(tRet==testid){
      return tRet;
    }
    delay(5);
  }
  return 0;

}
unsigned char uKitId::getInfraredId(char id){
  unsigned char tRet = 0;
  unsigned char buf[1];
  buf[0]=id;
  tRet=TXD(0xF8,1,1,0x07,buf);
  delay(5);
  return tRet;

}
unsigned char uKitId::setLedId(char oldid,char newid){
  unsigned char tRet = 0;
  unsigned char buf[2];
  buf[0]=oldid;
  buf[1]=newid;
  tRet=TXD(0xF4,1,2,0x06,buf);
  delay(5);
  return tRet;
 
}
unsigned char uKitId::getLedId(){
  unsigned char tRet = 0;
  unsigned char buf[1];
  for(int testid=1;testid<=10;testid++){
    buf[0]=testid;
    tRet=TXD(0xF4,1,1,0x07,buf);
    delay(5);
    if(tRet==testid){
      return tRet;
    }
    delay(5);
  }
  return 0;

}
unsigned char uKitId::getLedId(char id){
  unsigned char tRet = 0;
  unsigned char buf[1];

    buf[0]=id;
    tRet=TXD(0xF4,1,1,0x07,buf);
    delay(5);
    return tRet;

}
unsigned char uKitId::setButtonId(char oldid,char newid){
  unsigned char tRet = 0;
  unsigned char buf[2];
  buf[0]=oldid;
  buf[1]=newid;
  tRet=TXD(0xF7,1,2,0x06,buf);
  delay(5);
  return tRet;
 
}
unsigned char uKitId::getButtonId(){
  unsigned char tRet = 0;
  unsigned char buf[1];
  for(int testid=1;testid<=10;testid++){
    buf[0]=testid;
    tRet=TXD(0xF7,1,1,0x07,buf);
    delay(5);
    if(tRet==testid){
      return tRet;
    }
    delay(5);
  }
  return 0;

}
unsigned char uKitId::getButtonId(char id){
  unsigned char tRet = 0;
  unsigned char buf[1];
  buf[0]=id;
  tRet=TXD(0xF7,1,1,0x07,buf);
  delay(5);
  return tRet;

}
unsigned char uKitId::setUltrasonicId(char oldid,char newid){
  unsigned char tRet = 0;
  unsigned char buf[2];
  buf[0]=oldid;
  buf[1]=newid;
  tRet=TXD(0xF5,1,2,0x06,buf);
  delay(5);
  return tRet;
 
}
unsigned char uKitId::getUltrasonicId(){
  unsigned char tRet = 0;
  unsigned char buf[1];
  for(int testid=1;testid<=10;testid++){
    buf[0]=testid;
    tRet=TXD(0xF5,1,1,0x07,buf);
    delay(5);
    if(tRet==testid){
      return tRet;
    }
    delay(5);
  }
  return 0;

}
unsigned char uKitId::getUltrasonicId(char id){
  unsigned char tRet = 0;
  unsigned char buf[1];
  buf[0]=id;
  tRet=TXD(0xF5,1,1,0x07,buf);
  delay(5);
  return tRet;

}
unsigned char uKitId::setColorId(char oldid,char newid){
  unsigned char tRet = 0;
  unsigned char buf[2];
  buf[0]=oldid;
  buf[1]=newid;
  tRet=TXD(0xE8,1,2,0x06,buf);
  delay(5);
  return tRet;
 
}

unsigned char uKitId::getColorId(){
  unsigned char tRet = 0;
  unsigned char buf[1];
  for(int testid=1;testid<=10;testid++){
    buf[0]=testid;
    tRet=TXD(0xE8,1,1,0x07,buf);
    delay(5);
    if(tRet==testid){
      return tRet;
    }
    delay(5);
  }
  return 0;
}
unsigned char uKitId::getColorId(char id){
  unsigned char tRet = 0;
  unsigned char buf[1];
  buf[0]=id;
  tRet=TXD(0xE8,1,1,0x07,buf);
  delay(5);
  return tRet;
}

unsigned char uKitId::setServoId(char oldid,char newid){
  unsigned char tRet = 0;
  unsigned char buf[2];
  buf[0]=0x00;
  buf[1]=newid;
  tRet=TXD(0xFA,oldid,4,0xCD,buf);
  delay(5);
  return tRet;
 
}

unsigned char uKitId::getServoId(){
  unsigned char tRet = 0;
  unsigned char buf[4];
  for(int testid=1;testid<=18;testid++){
    buf[0]=0x00;
    buf[1]=0x00;
    buf[2]=0x00;
    buf[3]=0x00;
    tRet=TXD(0xFC,testid,4,0x01,buf);
    delay(5);
    if(tRet==testid){
      return tRet;
    }
  }
 return 0;
}

unsigned char uKitId::getServoId(char id){
  unsigned char tRet = 0;
  unsigned char buf[4];
    buf[0]=0x00;
    buf[1]=0x00;
    buf[2]=0x00;
    buf[3]=0x00;
    tRet=TXD(0xFC,id,4,0x01,buf);
    delay(5);
    return tRet;
}
void uKitId::setAllDeciveId(unsigned char decive,unsigned char oldid,unsigned char newid){
  switch(decive){
    case 1://舵机
      setServoId(oldid,newid);
      break;
    case 2://电机
      setMotorId(oldid,newid);
      break;
    case 3://红外
      setInfraredId(oldid,newid);
      break;
    case 4://超声波
      setUltrasonicId(oldid,newid);
      break;
    case 5://眼灯
      setLedId(oldid,newid);
      break;
    case 6://触碰
      setButtonId(oldid,newid);
      break;
    case 7://亮度
      setLightId(oldid,newid);
      break;
    case 8://声音
      setSoundId(oldid,newid);
      break;
    case 9://温湿度
      setHumitureId(oldid,newid);
      break;
    case 10://颜色
      setColorId(oldid,newid);
      break;          
  }
    
}

void uKitId::setDeciveId(){
  unsigned char buf[20]={0};
  unsigned char zeronum=0,num=0,numlength=0,decive=0;
  String single="",ten="";
  int id_1=0,id_2=0,id=0;
  static int i=0;
  String comdata="";
   if(i==0){
    delay(10);
    Serial.println("  请输入数字修改外设ID号。"); 
    Serial.println("  *注意,请确保当前仅连接一个外设，并打开电源。");    
    delay(300); 
    i=1;
  }  
    while (Serial.available() > 0){
        comdata += char(Serial.read());
        delay(2);//为了防止数据丢失,在此设置短暂延时delay(2)         
    }
      if(comdata.length() !=0){
        ten=comdata[comdata.length()-2];
        id_1=ten.toInt()*10;
        single=comdata[comdata.length()-1];
        id_2=single.toInt();
        id=id_1+id_2;    
        numlength=comdata.length();
        delay(20);
          buf[0]=getSoundId();
          delay(10);
          buf[1]=getLightId();
          delay(10);
          buf[2]=getHumitureId();
          delay(10);
          buf[3]=getInfraredId();
          delay(10);
          buf[4]=getLedId();
          delay(10);
          buf[5]=getButtonId();
          delay(10);
          buf[6]=getUltrasonicId();
          delay(10);
          buf[7]=getColorId();
          delay(10);
          buf[8]=getMotorId();
          delay(10);
          buf[9]=getServoId();
          delay(10);
        
          for(int i=0;i<=9;i++){
            if(buf[i]==0){
              zeronum+=1;
            }
            else if(buf[i]!=0){
              num+=1;
              if(num==1){
                decive=i; 
              }

            }
          }
               
        if((id==0 | id>18 | numlength>2) & decive>=8 ){
          Serial.println("  *请输入1至18的正整数");
          comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
        }
        else if(id!=0 & id<=18 & numlength<=2){
        if(id<=10){
          if(decive==0 & zeronum==9){
            delay(20);
            if(id!=0)
              setSoundId(buf[0],id);
            delay(100);
            buf[10]=getSoundId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【声音传感器】ID-");
            Serial.print(buf[0]);
            Serial.print("改为ID-");
            Serial.println(buf[10]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
            
          }
          else if(decive==1 & zeronum==9){
            delay(20);
            if(id!=0)
              setLightId(buf[1],id);
            delay(100);
            buf[11]=getLightId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【亮度传感器】ID-");
            Serial.print(buf[1]);
            Serial.print("改为ID-");
            Serial.println(buf[11]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }
          else if(decive==2 & zeronum==9){
            delay(20);
            if(id!=0)
              setHumitureId(buf[2],id);
            delay(100);
            buf[12]=getHumitureId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【温湿度传感器】ID-");
            Serial.print(buf[2]);
            Serial.print("改为ID-");
            Serial.println(buf[12]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }
          else if(decive==3 & zeronum==9){
            delay(20);
            if(id!=0)
              setInfraredId(buf[3],id);
            delay(100);
            buf[13]=getInfraredId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【红外传感器】ID-");
            Serial.print(buf[3]);
            Serial.print("改为ID-");
            Serial.println(buf[13]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }
           else if(decive==4 & zeronum==9){
            delay(20);
            if(id!=0)
              setLedId(buf[4],id);
            delay(100);
            buf[14]=getLedId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【眼灯】ID-");
            Serial.print(buf[4]);
            Serial.print("改为ID-");
            Serial.println(buf[14]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }         
           else if(decive==5 & zeronum==9){
            delay(20);
            if(id!=0)
              setButtonId(buf[5],id);
            delay(100);
            buf[15]=getButtonId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【按压传感器】 ID-");
            Serial.print(buf[5]);
            Serial.print("改为ID-");
            Serial.println(buf[15]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          } 
          else if(decive==6 & zeronum==9){
            delay(20);
            if(id!=0)
              setUltrasonicId(buf[6],id);
            delay(100);
            buf[16]=getUltrasonicId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【超声波传感器】ID-");
            Serial.print(buf[6]);
            Serial.print("改为ID-");
            Serial.println(buf[16]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }    
          else if(decive==7 & zeronum==9){
            delay(20);
            if(id!=0)
              setColorId(buf[7],id);
            delay(100);
            buf[17]=getColorId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【颜色传感器】ID-");
            Serial.print(buf[7]);
            Serial.print("改为ID-");
            Serial.println(buf[17]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }    
          
          if(decive==8 & zeronum==9){
            delay(20);
            if(id!=0)
              setMotorId(buf[8],id);
            delay(100);
            buf[18]=getMotorId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【电机】ID-");
            Serial.print(buf[8]);
            Serial.print("改为ID-");
            Serial.println(buf[18]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }                   
          else if(decive==9 & zeronum==9){
            delay(20);
            if(id!=0)
              setServoId(buf[9],id);
            delay(100);
            buf[19]=getServoId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【舵机】ID-");
            Serial.print(buf[9]);
            Serial.print("改为ID-");
            Serial.println(buf[19]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }  
        }
        else if(id>10 & id<=18 & decive>=8){
        if(decive==8 & zeronum==9){
            delay(20);
            if(id!=0)
              setMotorId(buf[8],id);
            delay(100);
            buf[18]=getMotorId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【电机】ID-");
            Serial.print(buf[8]);
            Serial.print("改为ID-");
            Serial.println(buf[18]); 
            Serial.println("  *如需修改其他设备ID，请接入设备，并按下开发板复位键。"); 
          }                   
          else if(decive==9 & zeronum==9){
            delay(20);
            if(id!=0)
              setServoId(buf[9],id);
            delay(100);
            buf[19]=getServoId();
            delay(30);
            Serial.print("  修改成功，");
            Serial.print("已将【舵机】ID-");
            Serial.print(buf[9]);
            Serial.print("改为ID-");
            Serial.println(buf[19]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键。"); 
          }                         
        }
        else if(id==0 | numlength>2 | id>10 && decive<9 ){
          Serial.println("  *请输入1至10的正整数。");
        }
        }

                else if(zeronum==10){
            Serial.println("  *请打开电源，或接入传感器。");
          }   
          else if(id==0 | numlength>2 | id>10 && decive<9 ){
          Serial.println("  *请输入1至10的正整数。");
        } 
        else {
            Serial.println("  *请不要接入多个传感器。");   
        }
    }
   comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
   zeronum=0;
   decive=0;
  
 
  
}
void uKitId::setDeciveIdEn(){
  unsigned char buf[20]={0};
  unsigned char zeronum=0,num=0,numlength=0,decive=0;
  String single="",ten="";
  int id_1=0,id_2=0,id=0;
  static int i=0;
  String comdata="";
   if(i==0){
    delay(10);
    Serial.println("  Please enter number to modify device ID"); 
    Serial.println("  *Please make sure that only ONE device is connected, and the board is switched on.");    
    delay(300); 
    i=1;
  }  
    while (Serial.available() > 0){
        comdata += char(Serial.read());
        delay(2);//为了防止数据丢失,在此设置短暂延时delay(2)        
    }
      if(comdata.length() !=0){
        ten=comdata[comdata.length()-2];
        id_1=ten.toInt()*10;
        single=comdata[comdata.length()-1];
        id_2=single.toInt();
        id=id_1+id_2;     
        numlength=comdata.length();
        delay(20);
          buf[0]=getSoundId();
          delay(10);
          buf[1]=getLightId();
          delay(10);
          buf[2]=getHumitureId();
          delay(10);
          buf[3]=getInfraredId();
          delay(10);
          buf[4]=getLedId();
          delay(10);
          buf[5]=getButtonId();
          delay(10);
          buf[6]=getUltrasonicId();
          delay(10);
          buf[7]=getColorId();
          delay(10);
          buf[8]=getMotorId();
          delay(10);
          buf[9]=getServoId();
          delay(10);
          for(int i=0;i<=9;i++){
            if(buf[i]==0){
              zeronum+=1;
            }
            else if(buf[i]!=0){
              num+=1;
              if(num==1){
                decive=i; 
              }

            }
          }
                  
        if((id==0 | id>18 | numlength>2) & decive>=8 ){
          Serial.println("  *Please enter positive integer from 1 to 18");
          comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
        }
        else if(id!=0 & id<=18 & numlength<=2){
        if(id<=10){
          if(decive==0 & zeronum==9){
            delay(20);
            if(id!=0)
              setSoundId(buf[0],id);
            delay(100);
            buf[10]=getSoundId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Sound sensor】ID-");
            Serial.print(buf[0]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[10]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
            
          }
          else if(decive==1 & zeronum==9){
            delay(20);
            if(id!=0)
              setLightId(buf[1],id);
            delay(100);
            buf[11]=getLightId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Light sensor】ID-");
            Serial.print(buf[1]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[11]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }
          else if(decive==2 & zeronum==9){
            delay(20);
            if(id!=0)
              setHumitureId(buf[2],id);
            delay(100);
            buf[12]=getHumitureId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Temp. & Humi. sensor】ID-");
            Serial.print(buf[2]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[12]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }
          else if(decive==3 & zeronum==9){
            delay(20);
            if(id!=0)
              setInfraredId(buf[3],id);
            delay(100);
            buf[13]=getInfraredId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【IR sensor】ID-");
            Serial.print(buf[3]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[13]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }
           else if(decive==4 & zeronum==9){
            delay(20);
            if(id!=0)
              setLedId(buf[4],id);
            delay(100);
            buf[14]=getLedId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Eye lamp】ID-");
            Serial.print(buf[4]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[14]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }         
           else if(decive==5 & zeronum==9){
            delay(20);
            if(id!=0)
              setButtonId(buf[5],id);
            delay(100);
            buf[15]=getButtonId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Touch sensor】 ID-");
            Serial.print(buf[5]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[15]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          } 
          else if(decive==6 & zeronum==9){
            delay(20);
            if(id!=0)
              setUltrasonicId(buf[6],id);
            delay(100);
            buf[16]=getUltrasonicId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Ultrasonic sensor】ID-");
            Serial.print(buf[6]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[16]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }    
          else if(decive==7 & zeronum==9){
            delay(20);
            if(id!=0)
              setColorId(buf[7],id);
            delay(100);
            buf[17]=getColorId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Color sensor】ID-");
            Serial.print(buf[7]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[17]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }    
          if(decive==8 & zeronum==9){
            delay(20);
            if(id!=0)
              setMotorId(buf[8],id);
            delay(100);
            buf[18]=getMotorId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Motor】ID-");
            Serial.print(buf[8]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[18]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }                   
          else if(decive==9 & zeronum==9){
            delay(20);
            if(id!=0)
              setServoId(buf[9],id);
            delay(100);
            buf[19]=getServoId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Servo】ID-");
            Serial.print(buf[9]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[19]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }  
        }
        else if(id>10 & id<=18 & decive>=8){
        if(decive==8 & zeronum==9){
            delay(20);
            if(id!=0)
              setMotorId(buf[8],id);
            delay(100);
            buf[18]=getMotorId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Motor】ID-");
            Serial.print(buf[8]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[18]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }                   
          else if(decive==9 & zeronum==9){
            delay(20);
            if(id!=0)
              setServoId(buf[9],id);
            delay(100);
            buf[19]=getServoId();
            delay(30);
            Serial.print("  Modification succeeded!");
            Serial.print("【Servo】ID-");
            Serial.print(buf[9]);
            Serial.print(" has been changed to ID-");
            Serial.println(buf[19]); 
            Serial.println("  *If you want to modify another device ID, please replace the device and press reset button at the board."); 
          }                         
        }
        else if(id==0 | numlength>2 | id>10 && decive<9 ){
          Serial.println("  Please enter positive integer from 1 to 10");
        }
        }

                else if(zeronum==10){
            Serial.println("  *Please turn on the power or insert sensors.");
          }   
          else if(id==0 | numlength>2 | id>10 && decive<9 ){
          Serial.println("  Please enter positive integer from 1 to 10");
        } 
        else {
            Serial.println("  *Please do not connect multiple devices.");   
        }
    }
   comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
   zeronum=0;
   decive=0;
   
 
  
}
void uKitId::setDeciveIdKo(){
  unsigned char buf[20]={0};
  unsigned char zeronum=0,num=0,numlength=0,decive=0;
  String single="",ten="";
  int id_1=0,id_2=0,id=0;
  static int i=0;
  String comdata="";
   if(i==0){
    delay(10);
    Serial.println("  수정할 장치 ID번호를 입력하십시오."); 
    Serial.println("  *장치가 하나만 연결되어 있는지 또는 보드가 켜져 있는지 확인하십시오.");    
    delay(300); 
    i=1;
  }  
    while (Serial.available() > 0){
        comdata += char(Serial.read());
        delay(2);//为了防止数据丢失,在此设置短暂延时delay(2)        
    }
      if(comdata.length() !=0){
        ten=comdata[comdata.length()-2];
        id_1=ten.toInt()*10;
        single=comdata[comdata.length()-1];
        id_2=single.toInt();
        id=id_1+id_2;     
        numlength=comdata.length();
        delay(20);
          buf[0]=getSoundId();
          delay(10);
          buf[1]=getLightId();
          delay(10);
          buf[2]=getHumitureId();
          delay(10);
          buf[3]=getInfraredId();
          delay(10);
          buf[4]=getLedId();
          delay(10);
          buf[5]=getButtonId();
          delay(10);
          buf[6]=getUltrasonicId();
          delay(10);
          buf[7]=getColorId();
          delay(10);
          buf[8]=getMotorId();
          delay(10);
          buf[9]=getServoId();
          delay(10);
          for(int i=0;i<=9;i++){
            if(buf[i]==0){
              zeronum+=1;
            }
            else if(buf[i]!=0){
              num+=1;
              if(num==1){
                decive=i; 
              }

            }
          }
                  
        if((id==0 | id>18 | numlength>2) & decive>=8 ){
          Serial.println("  *1에서 18 사이의 양의 정수를 입력하십시오.");
          comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
        }
        else if(id!=0 & id<=18 & numlength<=2){
        if(id<=10){
          if(decive==0 & zeronum==9){
            delay(20);
            if(id!=0)
              setSoundId(buf[0],id);
            delay(100);
            buf[10]=getSoundId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【소리센서】ID-");
            Serial.print(buf[0]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[10]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
            
          }
          else if(decive==1 & zeronum==9){
            delay(20);
            if(id!=0)
              setLightId(buf[1],id);
            delay(100);
            buf[11]=getLightId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【빛센서】ID-");
            Serial.print(buf[1]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[11]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }
          else if(decive==2 & zeronum==9){
            delay(20);
            if(id!=0)
              setHumitureId(buf[2],id);
            delay(100);
            buf[12]=getHumitureId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【온도 & 습도 센서】ID-");
            Serial.print(buf[2]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[12]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }
          else if(decive==3 & zeronum==9){
            delay(20);
            if(id!=0)
              setInfraredId(buf[3],id);
            delay(100);
            buf[13]=getInfraredId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【적외선센서】ID-");
            Serial.print(buf[3]);
             Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[13]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }
           else if(decive==4 & zeronum==9){
            delay(20);
            if(id!=0)
              setLedId(buf[4],id);
            delay(100);
            buf[14]=getLedId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【LED 라이트 센서】ID-");
            Serial.print(buf[4]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[14]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
            
          }         
           else if(decive==5 & zeronum==9){
            delay(20);
            if(id!=0)
              setButtonId(buf[5],id);
            delay(100);
            buf[15]=getButtonId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【접촉센서】 ID-");
            Serial.print(buf[5]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[15]); 
            Serial.println(" 로 변경되었습니다.");
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          } 
          else if(decive==6 & zeronum==9){
            delay(20);
            if(id!=0)
              setUltrasonicId(buf[6],id);
            delay(100);
            buf[16]=getUltrasonicId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【초음파센서】ID-");
            Serial.print(buf[6]+"가");
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[16]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }    
          else if(decive==7 & zeronum==9){
            delay(20);
            if(id!=0)
              setColorId(buf[7],id);
            delay(100);
            buf[17]=getColorId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【컬러센서】ID-");
            Serial.print(buf[7]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[17]); 
            Serial.println(" 로 변경되었습니다.");
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }    
          if(decive==8 & zeronum==9){
            delay(20);
            if(id!=0)
              setMotorId(buf[8],id);
            delay(100);
            buf[18]=getMotorId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【모터】ID-");
            Serial.print(buf[8]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[18]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }                   
          else if(decive==9 & zeronum==9){
            delay(20);
            if(id!=0)
              setServoId(buf[9],id);
            delay(100);
            buf[19]=getServoId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【서보】ID-");
            Serial.print(buf[9]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[19]);
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }  
        }
        else if(id>10 & id<=18 & decive>=8){
        if(decive==8 & zeronum==9){
            delay(20);
            if(id!=0)
              setMotorId(buf[8],id);
            delay(100);
            buf[18]=getMotorId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【모터】ID-");
            Serial.print(buf[8]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[18]); 
            Serial.println(" 로 변경되었습니다.");
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }                   
          else if(decive==9 & zeronum==9){
            delay(20);
            if(id!=0)
              setServoId(buf[9],id);
            delay(100);
            buf[19]=getServoId();
            delay(30);
            Serial.println("");
            Serial.print("  수정 성공!");
            Serial.print("【서보】ID-");
            Serial.print(buf[9]);
            Serial.print(" 가 ");
            Serial.print("ID-");
            Serial.print(buf[19]); 
            Serial.println(" 로 변경되었습니다."); 
            Serial.println("  * 다른 기기의 ID를 수정하려면, 기기를 교체하고 보드의 리셋 버튼을 누르세요."); 
          }                         
        }
        else if(id==0 | numlength>2 | id>10 && decive<9 ){
          Serial.println("  1에서 10 사이의 양의 정수를 입력하십시오.");
        }
        }

                else if(zeronum==10){
            Serial.println("  *전원 켜주세요.");
          }   
          else if(id==0 | numlength>2 | id>10 && decive<9 ){
          Serial.println("  1에서 10 사이의 양의 정수를 입력하십시오.");
        } 
        else {
            Serial.println("  *여러 개의 설비를 삽입하지 마십시오.");   
        }
    }
   comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
   zeronum=0;
   decive=0;
   
 
  
}

void uKitId::getDeciveId(){
  
  
  unsigned char idbuf[116]={0};
  unsigned char decivenum[10]={0};
  unsigned char deciveid[116]={0};
  
 if (Serial) {
  Serial.println(">-----当前接入了以下外设-----< ");
  for(int i=1;i<=18;i++){
    if(i<=10){
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i); 
      idbuf[i+36]=getInfraredId(i);
      idbuf[i+46]=getUltrasonicId(i);
      idbuf[i+56]=getLedId(i);
      idbuf[i+66]=getButtonId(i);
      idbuf[i+76]=getLightId(i);
      idbuf[i+86]=getSoundId(i);           
      idbuf[i+96]=getHumitureId(i);              
      idbuf[i+106]=getColorId(i);                  
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      }  
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
      if(idbuf[i+36]!=0){
        ++decivenum[2];
        deciveid[decivenum[2]+36]=idbuf[i+36];
      } 
      if(idbuf[i+46]!=0){
        ++decivenum[3];
        deciveid[decivenum[3]+46]=idbuf[i+46];
      } 
      if(idbuf[i+56]!=0){
        ++decivenum[4];
        deciveid[decivenum[4]+56]=idbuf[i+56];
      } 
      if(idbuf[i+66]!=0){
        ++decivenum[5];
        deciveid[decivenum[5]+66]=idbuf[i+66];
      } 
      if(idbuf[i+76]!=0){
        ++decivenum[6];
        deciveid[decivenum[6]+76]=idbuf[i+76];
      } 
      if(idbuf[i+86]!=0){
        ++decivenum[7];
        deciveid[decivenum[7]+86]=idbuf[i+86];
      } 
      if(idbuf[i+96]!=0){
        ++decivenum[8];
        deciveid[decivenum[8]+96]=idbuf[i+96];
      } 
      if(idbuf[i+106]!=0){
        ++decivenum[9];
        deciveid[decivenum[9]+106]=idbuf[i+106];
      } 
  }
  else{
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i);
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      } 
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
 

     }
  }
  if(decivenum[0]!=0){      
    Serial.print(" 【舵机】");
    for(int i=1;i<=decivenum[0];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i]);
      if(i!=decivenum[0]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[1]!=0){      
    Serial.print(" 【电机】");
    for(int i=1;i<=decivenum[1];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+18]);
      if(i!=decivenum[1]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[2]!=0){      
    Serial.print(" 【红外传感器】");
    for(int i=1;i<=decivenum[2];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+36]);
      if(i!=decivenum[2]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[3]!=0){      
    Serial.print(" 【超声波传感器】");
    for(int i=1;i<=decivenum[3];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+46]);
      if(i!=decivenum[3]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[4]!=0){      
    Serial.print(" 【LED眼灯】");
    for(int i=1;i<=decivenum[4];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+56]);
      if(i!=decivenum[4]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[5]!=0){      
    Serial.print(" 【按压传感器】");
    for(int i=1;i<=decivenum[5];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+66]);
      if(i!=decivenum[5]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[6]!=0){      
    Serial.print(" 【亮度传感器】");
    for(int i=1;i<=decivenum[6];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+76]);
      if(i!=decivenum[6]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[7]!=0){      
    Serial.print(" 【声音传感器】");
    for(int i=1;i<=decivenum[7];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+86]);
      if(i!=decivenum[7]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[8]!=0){      
    Serial.print(" 【温湿度传感器】");
    for(int i=1;i<=decivenum[8];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+96]);
      if(i!=decivenum[8]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[9]!=0){      
    Serial.print(" 【颜色传感器】");
    for(int i=1;i<=decivenum[9];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+106]);
      if(i!=decivenum[9]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  Serial.println("------------------------ ");
 
}
}
 void uKitId::getDeciveIdJs(){
  
  
  unsigned char idbuf[116]={0};
  unsigned char decivenum[10]={0};
  unsigned char deciveid[116]={0};
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  JsonArray& drivers = root.createNestedArray("drivers");   

 if (Serial) {
  
  for(int i=1;i<=18;i++){
    if(i<=10){
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i);
      idbuf[i+36]=getInfraredId(i);
      idbuf[i+46]=getUltrasonicId(i);
      idbuf[i+56]=getLedId(i);
      idbuf[i+66]=getButtonId(i);
      idbuf[i+76]=getLightId(i);
      idbuf[i+86]=getSoundId(i);           
      idbuf[i+96]=getHumitureId(i);              
      idbuf[i+106]=getColorId(i);                  
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      }  
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
      if(idbuf[i+36]!=0){
        ++decivenum[2];
        deciveid[decivenum[2]+36]=idbuf[i+36];
      } 
      if(idbuf[i+46]!=0){
        ++decivenum[3];
        deciveid[decivenum[3]+46]=idbuf[i+46];
      } 
      if(idbuf[i+56]!=0){
        ++decivenum[4];
        deciveid[decivenum[4]+56]=idbuf[i+56];
      } 
      if(idbuf[i+66]!=0){
        ++decivenum[5];
        deciveid[decivenum[5]+66]=idbuf[i+66];
      } 
      if(idbuf[i+76]!=0){
        ++decivenum[6];
        deciveid[decivenum[6]+76]=idbuf[i+76];
      } 
      if(idbuf[i+86]!=0){
        ++decivenum[7];
        deciveid[decivenum[7]+86]=idbuf[i+86];
      } 
      if(idbuf[i+96]!=0){
        ++decivenum[8];
        deciveid[decivenum[8]+96]=idbuf[i+96];
      } 
      if(idbuf[i+106]!=0){
        ++decivenum[9];
        deciveid[decivenum[9]+106]=idbuf[i+106];
      } 
  }
  else{
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i);
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      } 
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
 

     }
  }
  if(decivenum[0]!=0){    
    JsonArray& servo = root.createNestedArray("servo");    
    drivers.add(1);//舵机
    for(int i=1;i<=decivenum[0];i++){
      servo.add(deciveid[i]);//舵机
    }
  }
  if(decivenum[1]!=0){     
    JsonArray& motor = root.createNestedArray("motor"); 
    drivers.add(2);//电机
    for(int i=1;i<=decivenum[1];i++){
      motor.add(deciveid[i+18]);
      
    }
  }
  if(decivenum[2]!=0){      
    JsonArray& ir = root.createNestedArray("ir");
    drivers.add(3);//红外
    for(int i=1;i<=decivenum[2];i++){
      ir.add(deciveid[i+36]); 
    }
  }
  if(decivenum[3]!=0){    
     JsonArray& ultrasonic = root.createNestedArray("ultrasonic");
    drivers.add(4);//超声波 
    for(int i=1;i<=decivenum[3];i++){
      ultrasonic.add(deciveid[i+46]); 

    }
  }
  if(decivenum[4]!=0){      
    JsonArray& eyelamp = root.createNestedArray("eyelamp");
    drivers.add(5);//led眼灯
    for(int i=1;i<=decivenum[4];i++){
      eyelamp.add(deciveid[i+56]);
    }
  }
  if(decivenum[5]!=0){      
    JsonArray& touch = root.createNestedArray("touch");
    drivers.add(6);//触碰传感器
    for(int i=1;i<=decivenum[5];i++){
      touch.add(deciveid[i+66]);
    }

  }
  if(decivenum[6]!=0){      
    JsonArray& light = root.createNestedArray("light");
    drivers.add(7);//亮度
    for(int i=1;i<=decivenum[6];i++){
      light.add(deciveid[i+76]);

    }
  }
  if(decivenum[7]!=0){      
    JsonArray& sound = root.createNestedArray("sound");
    drivers.add(8);//声音
    for(int i=1;i<=decivenum[7];i++){
      sound.add(deciveid[i+86]);

    }

  }
  if(decivenum[8]!=0){      
    JsonArray& tah = root.createNestedArray("tah");
    drivers.add(9);//温湿度传感器
    for(int i=1;i<=decivenum[8];i++){
      tah.add(deciveid[i+96]);
      Serial.print(deciveid[i+96]);
    }
  }
  if(decivenum[9]!=0){      
    JsonArray& colors = root.createNestedArray("colors");
    drivers.add(10);//颜色传感器
    for(int i=1;i<=decivenum[9];i++){
      colors.add(deciveid[i+106]);
  
    }
  } 
 
}
  root.printTo(Serial);
  Serial.print('\n');
} 
void uKitId::getDeciveIdEn(){
 
  
  unsigned char idbuf[116]={0};
  unsigned char decivenum[10]={0};
  unsigned char deciveid[116]={0};
  
 if (Serial) {
  Serial.println(">------Following device has been connected to the board------< ");
  for(int i=1;i<=18;i++){
    if(i<=10){
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i);
      idbuf[i+36]=getInfraredId(i);
      idbuf[i+46]=getUltrasonicId(i);
      idbuf[i+56]=getLedId(i);
      idbuf[i+66]=getButtonId(i);
      idbuf[i+76]=getLightId(i);
      idbuf[i+86]=getSoundId(i);           
      idbuf[i+96]=getHumitureId(i);              
      idbuf[i+106]=getColorId(i);                  
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      }  
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
      if(idbuf[i+36]!=0){
        ++decivenum[2];
        deciveid[decivenum[2]+36]=idbuf[i+36];
      } 
      if(idbuf[i+46]!=0){
        ++decivenum[3];
        deciveid[decivenum[3]+46]=idbuf[i+46];
      } 
      if(idbuf[i+56]!=0){
        ++decivenum[4];
        deciveid[decivenum[4]+56]=idbuf[i+56];
      } 
      if(idbuf[i+66]!=0){
        ++decivenum[5];
        deciveid[decivenum[5]+66]=idbuf[i+66];
      } 
      if(idbuf[i+76]!=0){
        ++decivenum[6];
        deciveid[decivenum[6]+76]=idbuf[i+76];
      } 
      if(idbuf[i+86]!=0){
        ++decivenum[7];
        deciveid[decivenum[7]+86]=idbuf[i+86];
      } 
      if(idbuf[i+96]!=0){
        ++decivenum[8];
        deciveid[decivenum[8]+96]=idbuf[i+96];
      } 
      if(idbuf[i+106]!=0){
        ++decivenum[9];
        deciveid[decivenum[9]+106]=idbuf[i+106];
      } 
  }
  else{
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i);
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      } 
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
 

     }
  }
  if(decivenum[0]!=0){      
    Serial.print(" 【Servo】");
    for(int i=1;i<=decivenum[0];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i]);
      if(i!=decivenum[0]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[1]!=0){      
    Serial.print(" 【Motor】");
    for(int i=1;i<=decivenum[1];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+18]);
      if(i!=decivenum[1]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[2]!=0){      
    Serial.print(" 【IR sensor】");
    for(int i=1;i<=decivenum[2];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+36]);
      if(i!=decivenum[2]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[3]!=0){      
    Serial.print(" 【Ultrasonic sensor】");
    for(int i=1;i<=decivenum[3];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+46]);
      if(i!=decivenum[3]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[4]!=0){      
    Serial.print(" 【Eye lamp】");
    for(int i=1;i<=decivenum[4];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+56]);
      if(i!=decivenum[4]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[5]!=0){      
    Serial.print(" 【Touch sensor】");
    for(int i=1;i<=decivenum[5];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+66]);
      if(i!=decivenum[5]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[6]!=0){      
    Serial.print(" 【Light sensor】");
    for(int i=1;i<=decivenum[6];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+76]);
      if(i!=decivenum[6]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[7]!=0){      
    Serial.print(" 【Sound sensor】");
    for(int i=1;i<=decivenum[7];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+86]);
      if(i!=decivenum[7]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[8]!=0){      
    Serial.print(" 【Temp. & Humi. sensor】");
    for(int i=1;i<=decivenum[8];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+96]);
      if(i!=decivenum[8]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[9]!=0){      
    Serial.print(" 【Color sensor】");
    for(int i=1;i<=decivenum[9];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+106]);
      if(i!=decivenum[9]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  Serial.println("------------------------------ ");
 
}
}
void uKitId::getDeciveIdKo(){
 
  
  unsigned char idbuf[116]={0};
  unsigned char decivenum[10]={0};
  unsigned char deciveid[116]={0};
  
 if (Serial) {
  Serial.println(">------다음 장치가 보드에 연결되었습니다------< ");
  for(int i=1;i<=18;i++){
    if(i<=10){
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i);
      idbuf[i+36]=getInfraredId(i);
      idbuf[i+46]=getUltrasonicId(i);
      idbuf[i+56]=getLedId(i);
      idbuf[i+66]=getButtonId(i);
      idbuf[i+76]=getLightId(i);
      idbuf[i+86]=getSoundId(i);           
      idbuf[i+96]=getHumitureId(i);              
      idbuf[i+106]=getColorId(i);                  
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      }  
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
      if(idbuf[i+36]!=0){
        ++decivenum[2];
        deciveid[decivenum[2]+36]=idbuf[i+36];
      } 
      if(idbuf[i+46]!=0){
        ++decivenum[3];
        deciveid[decivenum[3]+46]=idbuf[i+46];
      } 
      if(idbuf[i+56]!=0){
        ++decivenum[4];
        deciveid[decivenum[4]+56]=idbuf[i+56];
      } 
      if(idbuf[i+66]!=0){
        ++decivenum[5];
        deciveid[decivenum[5]+66]=idbuf[i+66];
      } 
      if(idbuf[i+76]!=0){
        ++decivenum[6];
        deciveid[decivenum[6]+76]=idbuf[i+76];
      } 
      if(idbuf[i+86]!=0){
        ++decivenum[7];
        deciveid[decivenum[7]+86]=idbuf[i+86];
      } 
      if(idbuf[i+96]!=0){
        ++decivenum[8];
        deciveid[decivenum[8]+96]=idbuf[i+96];
      } 
      if(idbuf[i+106]!=0){
        ++decivenum[9];
        deciveid[decivenum[9]+106]=idbuf[i+106];
      } 
  }
  else{
      idbuf[i]=getServoId(i);
      idbuf[i+18]=getMotorId(i);
      if(idbuf[i]!=0){
        ++decivenum[0];
        deciveid[decivenum[0]]=idbuf[i];
      } 
      if(idbuf[i+18]!=0){
        ++decivenum[1];
        deciveid[decivenum[1]+18]=idbuf[i+18];
      } 
 

     }
  }
  if(decivenum[0]!=0){      
    Serial.print(" 【서보】");
    for(int i=1;i<=decivenum[0];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i]);
      if(i!=decivenum[0]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[1]!=0){      
    Serial.print(" 【서보】");
    for(int i=1;i<=decivenum[1];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+18]);
      if(i!=decivenum[1]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[2]!=0){      
    Serial.print(" 【적외선센서】");
    for(int i=1;i<=decivenum[2];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+36]);
      if(i!=decivenum[2]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[3]!=0){      
    Serial.print(" 【초음파센서】");
    for(int i=1;i<=decivenum[3];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+46]);
      if(i!=decivenum[3]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[4]!=0){      
    Serial.print(" 【LED 라이트 센서】");
    for(int i=1;i<=decivenum[4];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+56]);
      if(i!=decivenum[4]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[5]!=0){      
    Serial.print(" 【접촉센서】");
    for(int i=1;i<=decivenum[5];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+66]);
      if(i!=decivenum[5]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[6]!=0){      
    Serial.print(" 【빛센서】");
    for(int i=1;i<=decivenum[6];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+76]);
      if(i!=decivenum[6]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[7]!=0){      
    Serial.print(" 【소리센서】");
    for(int i=1;i<=decivenum[7];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+86]);
      if(i!=decivenum[7]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[8]!=0){      
    Serial.print(" 【온도 & 습도 센서】");
    for(int i=1;i<=decivenum[8];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+96]);
      if(i!=decivenum[8]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  if(decivenum[9]!=0){      
    Serial.print(" 【컬러센서】");
    for(int i=1;i<=decivenum[9];i++){
      Serial.print("ID-");
      Serial.print(deciveid[i+106]);
      if(i!=decivenum[9]){
        Serial.print("、");
      }   
    }
    Serial.println("");
  }
  Serial.println("------------------------------ ");
 
}
}
