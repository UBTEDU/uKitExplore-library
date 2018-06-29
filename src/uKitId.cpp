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



void uKitId::setDeciveId(){
  unsigned char buf[20]={0};
  unsigned char zeronum,num,decive=0;
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
          
          if(decive==0 & zeronum==9){
            delay(20);
            if(id!=0)
              setSoundId(buf[0],id);
            delay(100);
            buf[10]=getSoundId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【声响传感器】ID-");
            Serial.print(buf[0]);
            Serial.print("改为ID-");
            Serial.println(buf[10]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
            
          }
          else if(decive==1 & zeronum==9){
            delay(20);
            if(id!=0)
              setLightId(buf[1],id);
            delay(100);
            buf[11]=getLightId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【光感传感器】ID-");
            Serial.print(buf[1]);
            Serial.print("改为ID-");
            Serial.println(buf[11]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }
          else if(decive==2 & zeronum==9){
            delay(20);
            if(id!=0)
              setHumitureId(buf[2],id);
            delay(100);
            buf[12]=getHumitureId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【温湿度传感器】ID-");
            Serial.print(buf[2]);
            Serial.print("改为ID-");
            Serial.println(buf[12]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }
          else if(decive==3 & zeronum==9){
            delay(20);
            if(id!=0)
              setInfraredId(buf[3],id);
            delay(100);
            buf[13]=getInfraredId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【红外传感器】ID-");
            Serial.print(buf[3]);
            Serial.print("改为ID-");
            Serial.println(buf[13]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }
           else if(decive==4 & zeronum==9){
            delay(20);
            if(id!=0)
              setLedId(buf[4],id);
            delay(100);
            buf[14]=getLedId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【眼灯】ID-");
            Serial.print(buf[4]);
            Serial.print("改为ID-");
            Serial.println(buf[14]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }         
           else if(decive==5 & zeronum==9){
            delay(20);
            if(id!=0)
              setButtonId(buf[5],id);
            delay(100);
            buf[15]=getButtonId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【触碰传感器】ID-");
            Serial.print(buf[5]);
            Serial.print("改为ID-");
            Serial.println(buf[15]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          } 
          else if(decive==6 & zeronum==9){
            delay(20);
            if(id!=0)
              setUltrasonicId(buf[6],id);
            delay(100);
            buf[16]=getUltrasonicId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【超声波传感器】ID-");
            Serial.print(buf[6]);
            Serial.print("改为ID-");
            Serial.println(buf[16]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }    
          else if(decive==7 & zeronum==9){
            delay(20);
            if(id!=0)
              setColorId(buf[7],id);
            delay(100);
            buf[17]=getColorId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【颜色传感器】ID-");
            Serial.print(buf[7]);
            Serial.print("改为ID-");
            Serial.println(buf[17]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }    
          else if(decive==8 & zeronum==9){
            delay(20);
            if(id!=0)
              setMotorId(buf[8],id);
            delay(100);
            buf[18]=getMotorId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【电机】ID-");
            Serial.print(buf[8]);
            Serial.print("改为ID-");
            Serial.println(buf[18]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }                   
          else if(decive==9 & zeronum==9){
            delay(20);
            if(id!=0)
              setServoId(buf[9],id);
            delay(100);
            buf[19]=getServoId();
            delay(30);
            Serial.print("  修改成功！");
            Serial.print("已将【舵机】ID-");
            Serial.print(buf[9]);
            Serial.print("改为ID-");
            Serial.println(buf[19]); 
            Serial.println("  *如需修改其他设备ID,请接入设备，并按下开发板复位键"); 
          }        
        else if(zeronum==10){
            Serial.println("  *请打开电源,或接入传感器！");
          }    
        else{
            Serial.println("  *请不要接入多个传感器！");   
        }
  
        }
    }
   comdata = "";//  必须在此把comdata设为空字符,否则会导致前后字符串叠加
   zeronum=0;
   decive=0;
 
  
}
