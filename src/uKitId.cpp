#include"uKitId.h" 

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
  tRet=TXD(12,buf); 
  return tRet;
}

unsigned char uKitId::getMotorId(){
  unsigned long tRet = 0;
  unsigned char buf[10];
  for(int testid=1;testid<=16;testid++){
    buf[0] = 0xFB;//帧头
    buf[1] = 0x03;//设备类型
    buf[2] = 0x06;//长度
    buf[3] = 0x05;//命令号
    buf[4] = testid;//ID
    buf[5] = 0x00;//参数
    buf[6] = 0x03;
    buf[7] = 0x00;
    buf[8] = 0x01;
    buf[9] = crc8_itu(&buf[1], buf[2]+2);
    tRet=TXD(10,buf); 
    delay(5); 
    if(tRet==testid){
      return tRet;
    }
    delay(5);
     
  }
   return 0; 
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
  for(int testid=1;testid<=16;testid++){
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

void uKitId::setSensorId(){
  unsigned char SoundId,SoundId_1,LightId,LightId_1,HumitureId,HumitureId_1,\
  InfraredId,InfraredId_1,LedId,LedId_1,ButtonId,ButtonId_1,UltrasonicId,UltrasonicId_1,\
  ColorId,ColorId_1,MotorId,MotorId_1,ServoId,ServoId_1=0;
  String single,ten;
  int id_1,id_2,id;
  static int i=0;
  String comdata="";
   if(i==0){
    delay(10);
    Serial.println("/----------------------------------------------/");
    Serial.println("  请输入数字修改设备ID号"); 
    Serial.println("  *注意，请确保当前仅连接一个设备，并打开电源。");    
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
      
        delay(20);
        if(id==0 | id>16){
          Serial.println("请不要输入id-0或大于16");
          comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
        }
        else if(id!=0 & id<=20){
          delay(20);
          SoundId=getSoundId();
          delay(10);
          LightId=getLightId();
          delay(10);
          HumitureId=getHumitureId();
          delay(10);
          InfraredId=getInfraredId();
          delay(10);
          LedId=getLedId();
          delay(10);
          ButtonId=getButtonId();
          delay(10);
          UltrasonicId=getUltrasonicId();
          delay(10);
          ColorId=getColorId();
          delay(10);
          MotorId=getMotorId();
          delay(10);
          ServoId=getServoId();
          delay(10);
          
          if(SoundId!=0){
            delay(20);
            if(id!=0)
              setSoundId(SoundId,id);
            delay(100);
            SoundId_1=getSoundId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【声响传感器】ID-");
            Serial.print(SoundId);
            Serial.print("改为ID-");
            Serial.println(SoundId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
            
          }
          else if(LightId!=0){
            delay(20);
            if(id!=0)
              setLightId(LightId,id);
            delay(100);
            LightId_1=getLightId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【光感传感器】ID-");
            Serial.print(LightId);
            Serial.print("改为ID-");
            Serial.println(LightId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }
          else if(HumitureId!=0){
            delay(20);
            if(id!=0)
              setHumitureId(HumitureId,id);
            delay(100);
            HumitureId_1=getHumitureId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【温湿度传感器】ID-");
            Serial.print(HumitureId);
            Serial.print("改为ID-");
            Serial.println(HumitureId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }
          else if(InfraredId!=0){
            delay(20);
            if(id!=0)
              setInfraredId(InfraredId,id);
            delay(100);
            InfraredId_1=getInfraredId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【红外传感器】ID-");
            Serial.print(InfraredId);
            Serial.print("改为ID-");
            Serial.println(InfraredId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }
           else if(LedId!=0){
            delay(20);
            if(id!=0)
              setLedId(LedId,id);
            delay(100);
            LedId_1=getLedId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【眼灯】ID-");
            Serial.print(LedId);
            Serial.print("改为ID-");
            Serial.println(LedId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }         
           else if(ButtonId!=0){
            delay(20);
            if(id!=0)
              setButtonId(ButtonId,id);
            delay(100);
            ButtonId_1=getButtonId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【触碰传感器】ID-");
            Serial.print(ButtonId);
            Serial.print("改为ID-");
            Serial.println(ButtonId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          } 
          else if(UltrasonicId!=0){
            delay(20);
            if(id!=0)
              setUltrasonicId(UltrasonicId,id);
            delay(100);
            UltrasonicId_1=getUltrasonicId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【超声波传感器】ID-");
            Serial.print(UltrasonicId);
            Serial.print("改为ID-");
            Serial.println(UltrasonicId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }    
          else if(ColorId!=0){
            delay(20);
            if(id!=0)
              setColorId(ColorId,id);
            delay(100);
            ColorId_1=getColorId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【颜色传感器】ID-");
            Serial.print(ColorId);
            Serial.print("改为ID-");
            Serial.println(ColorId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }    
          else if(MotorId!=0){
            delay(20);
            if(id!=0)
              setMotorId(MotorId,id);
            delay(100);
            MotorId_1=getMotorId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【电机】ID-");
            Serial.print(MotorId);
            Serial.print("改为ID-");
            Serial.println(MotorId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }                   
          else if(ServoId!=0){
            delay(20);
            if(id!=0)
              setServoId(ServoId,id);
            delay(100);
            ServoId_1=getServoId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【舵机】ID-");
            Serial.print(ServoId);
            Serial.print("改为ID-");
            Serial.println(ServoId_1); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }                
  
        }
    }
   comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
 
  
}
