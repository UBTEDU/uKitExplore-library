#include"uKitSensor.h" 

unsigned char  uKitSensor::readInfraredDistance(char ID){//uKit红外传感器
  unsigned char hData[1];
  volatile int State=0;
  unsigned int  inval;
  hData[0]=ID;
  if(State==0){
    State=TXD(0xF8,1,1,0x02,hData);
    delay(5);
  }  
  inval=TXD(0xF8,1,1,4,hData);
  if(inval<=879)
    inval=0;
  else if(inval>879 &inval<=892)
    inval=1;
  else if(inval>892 &inval<=905)
    inval=2;
   else if(inval>905 &inval<=918)
    inval=3;
   else if(inval>918 &inval<=931)
    inval=4;
   else if(inval>918 &inval<=944)
    inval=5;
  else
     inval=inval*20/2700;
     
 return inval;  

  delay(5);
}



unsigned short int uKitSensor::readSoundValue(char id){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x10;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = id;//id
  buf[5] = 0x10;//参数
  buf[6] = 0x00;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=map(TXD(10,buf),0,4069,0,1023);
  delay(10);
  if(tRet>1023)
    tRet=1023;
  return tRet;
}
unsigned short int uKitSensor::readLightValue(char id){
  unsigned short int tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x06;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = id;//id
  buf[5] = 0x10;//参数
  buf[6] = 0x00;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  delay(10);
  if(tRet>4000){
    tRet=4000;    
  }
  return tRet;
}
void uKitSensor::setEyelightLook(char id,char face,int times,int red,int green,int blue){

  signed char tData2[1] ;
  signed char tData[7];
  tData2[0]=id;
  volatile int State=0;
  if(State==0){
    State=TXD(0xF4,1,1,0x2,tData2 );
    delay(5);  
  }
  tData[0]=id;  //ID
  tData[1]=face;//表情
  tData[2]=0x00;//
  tData[3]=times;//
  tData[4]=red;
  tData[5]=green;
  tData[6]=blue;
  
  State=TXD(0xF4,1,7,0x0a,tData );
  delay(10);

 }
void uKitSensor::setEyelightScene(char id,char scene,int times){

  signed char tData2[1] ;
  signed char tData[7];
  tData2[0]=id;
  volatile int State=0;
  if(State==0){
    State=TXD(0xF4,1,1,0x2,tData2 );
    delay(5);  
  }
  tData[0]=id;  //ID
  tData[1]=scene+12;//表情
  tData[2]=0x00;//
  tData[3]=times;// 
  tData[4]=0;
  tData[5]=0;
  tData[6]=0;
  State=TXD(0xF4,1,7,0x0a,tData );
  delay(10);
 }
void uKitSensor::setEyelightAllPetals(char id,int red,int green,int blue){

  signed char tData2[1] ;
  signed char tData[8];
  tData2[0]=id;
  volatile int State=0;
  if(State==0){
    State=TXD(0xF4,1,1,0x2,tData2 );
    delay(5); 
    State=1; 
  }
  tData[0]=id;  //ID
  tData[1]=0xff;
  tData[2]=1;//
  tData[3]=0xff;//
  tData[4]=red;
  tData[5]=green;
  tData[6]=blue;
  tData[7]=8;
  State=TXD(0xF4,1,8,0x0b,tData );
  delay(10);
 }
void uKitSensor::setEyelightPetal(char id,unsigned char petalsnum,unsigned char petals[8][4],unsigned char time){
  signed char tData2[1] ;
  signed char tData[35];
  tData2[0]=id;
  volatile int State=0;
  if(State==0){
    State=TXD(0xF4,1,1,0x2,tData2 );
    delay(5);  
  }
  tData[0]=id;  //ID
  tData[1]=0xff;//持续时间
  tData[2]=petalsnum;//色块数量
  
  tData[3]=petals[0][0];//第1
  tData[4]=petals[0][1];
  tData[5]=petals[0][2];
  tData[6]=petals[0][3];
  
  tData[7]=petals[1][0];//第2
  tData[8]=petals[1][1];
  tData[9]=petals[1][2];
  tData[10]=petals[1][3];
  
  tData[11]=petals[2][0];//第3
  tData[12]=petals[2][1];
  tData[13]=petals[2][2];
  tData[14]=petals[2][3];
  
  tData[15]=petals[3][0];//第4
  tData[16]=petals[3][1];
  tData[17]=petals[3][2];
  tData[18]=petals[3][3];
  
  tData[19]=petals[4][0];//第5
  tData[20]=petals[4][1];
  tData[21]=petals[4][2];
  tData[22]=petals[4][3];
  
  tData[23]=petals[5][0];//第6
  tData[24]=petals[5][1];
  tData[25]=petals[5][2];
  tData[26]=petals[5][3];
  
  tData[27]=petals[6][0];//第7
  tData[28]=petals[6][1];
  tData[29]=petals[6][2];
  tData[30]=petals[6][3];
  
  tData[31]=petals[7][0];//第8
  tData[32]=petals[7][1];
  tData[33]=petals[7][2];
  tData[34]=petals[7][3];  

  State=TXD(0xF4,1,35,0x0b,tData );
  delay(time*1000);
  setEyelightOff(id);
  delay(5);
  
}
void uKitSensor::setEyelightPetals(char id,unsigned char petalsnum,String petals){
  DynamicJsonBuffer jsonBuffer;
  signed char tData2[1] ;
  unsigned char tData[35];
  
  JsonObject& root = jsonBuffer.parseObject(petals);
  tData2[0]=id;
  volatile int State=0;
  if(State==0){
    State=TXD(0xF4,1,1,0x2,tData2 );
    delay(5);  
  }
  tData[0]=id;  //ID
  tData[1]=0xff;//持续时间
  tData[2]=petalsnum;//色块数量
  
  tData[3]=int(root["data"][0]);//第1
  tData[4]=int(root["data"][1]);
  tData[5]=int(root["data"][2]);
  tData[6]=int(root["data"][3]);
  
  tData[7]=int(root["data"][4]);//第2
  tData[8]=int(root["data"][5]);
  tData[9]=int(root["data"][6]);
  tData[10]=int(root["data"][7]);
  
  tData[11]=int(root["data"][8]);//第3
  tData[12]=int(root["data"][9]);
  tData[13]=int(root["data"][10]);
  tData[14]=int(root["data"][11]);
  
  tData[15]=int(root["data"][12]);//第4
  tData[16]=int(root["data"][13]);
  tData[17]=int(root["data"][14]);
  tData[18]=int(root["data"][15]);
  
  tData[19]=int(root["data"][16]);//第5
  tData[20]=int(root["data"][17]);
  tData[21]=int(root["data"][18]);
  tData[22]=int(root["data"][19]);
  
  tData[23]=int(root["data"][20]);//第6
  tData[24]=int(root["data"][21]);
  tData[25]=int(root["data"][22]);
  tData[26]=int(root["data"][23]);
  
  tData[27]=int(root["data"][24]);//第7
  tData[28]=int(root["data"][25]);
  tData[29]=int(root["data"][26]);
  tData[30]=int(root["data"][27]);
  
  tData[31]=int(root["data"][28]);//第8
  tData[32]=int(root["data"][29]);
  tData[33]=int(root["data"][30]);
  tData[34]=int(root["data"][31]);  

  State=TXD(0xF4,1,35,0x0b,tData );
  delay(10);
  
  
}
void uKitSensor::setEyelightOff(char id){
  signed char tData[1];
  volatile int State=0;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF4,1,1,0x3,tData);
    delay(5);
  }
 } 
signed char uKitSensor::readHumitureValue(char id, char choice){
  signed char tRet = 0;
  unsigned char buf[10];
  buf[0] = 0xFB;//帧头
  buf[1] = 0x05;//设备类型
  buf[2] = 0x06;//长度
  buf[3] = 0x05;//命令号
  buf[4] = id;//id
  buf[5] = 0x10;//参数
  buf[6] = 0x00;
  buf[7] = 0x00;
  buf[8] = 0x02;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,choice,buf);
  delay(10);
  return tRet;
}
int  *uKitSensor::Rgb2Hsb(unsigned char rgbR,unsigned char rgbG,unsigned char rgbB){
  int *temp = new int[3];
  int Max,Min=0;
  Max=max(max(rgbR,rgbG),rgbB);
  Min=min(min(rgbR,rgbG),rgbB);
  float hsbB= Max/(float)255.00*100;
  float hsbS= Max == 0 ? 0:(Max-Min)/(float)Max*100;
  float hsbH=0;  
  if (Max == rgbR && rgbG >= rgbB) {
  hsbH = (rgbG - rgbB) * 60.0 / (Max - Min) + 0;
  } else if (Max == rgbR && rgbG < rgbB) {
  hsbH = (rgbG - rgbB) * 60.0 / (Max - Min) + 360;
  } else if (Max == rgbG) {
  hsbH = (rgbB - rgbR) * 60.0 / (Max - Min) + 120;
  } else if (Max == rgbB) {
  hsbH = (rgbR - rgbG) * 60.0 / (Max - Min) + 240;
  }
  temp[0]=hsbH;
  temp[1]=hsbS;
  temp[2]=hsbB;
  
  
  return temp;
  
  
}

unsigned char uKitSensor::readColorRgb(char id,unsigned char RGB){
  unsigned  char tData[1];
  unsigned char Value;
  tData[0]=id;
  volatile int State=0;

  if(State==0){
    TXD(0xE8,1,1,2,tData);  
    delay(10); 
    State=1;
    
  }
    Value=TXD(0xE8,1,1,4,RGB,tData);  
    delay(100);
    return Value;
          
 }
unsigned char *uKitSensor::readColorRgb(char id){
  unsigned  char tData[1];
  unsigned char *value=NULL;
  value=new unsigned char[3];  
  tData[0]=id;
  unsigned char getid=0;
  volatile int State=0;
  if(State==0){
    getid=TXD(0xE8,1,1,2,tData);  
    delay(10); 
    State=1;
    
    
  }
    if(getid==id){
    value=TXDRandom(0xE8,1,1,4,tData);  
    delay(180);   
    }
    else {
      value[0]=0;
      value[1]=0;
      value[2]=0;
       
    }
    return value;
    delete []value;
   
     
    
    
    
          
 }
 
void uKitSensor::setColorOff(char id){
  unsigned  char tData[1];
  tData[0]=id;
  TXD(0xE8,1,1,3,tData); 
    delay(5);   
 }
bool uKitSensor::readColor(char id,String color){
  unsigned char *ColorRgb=readColorRgb(id);
  delay(5);
  //ColorRgb[0]为R,ColorRgb[1]为G,ColorRgb[2]为B
  int *buf=Rgb2Hsb(ColorRgb[0],ColorRgb[1],ColorRgb[2]);
  delay(5);
// Serial.print(buf[0]);
// Serial.print(",");
//  Serial.print(buf[1]);
// Serial.print(",");
//  Serial.println(buf[2]);
 //buf[0]为H,buf[1]为S,buf[2]为B
  bool state=0;
  if(color!="Black"&& (buf[1]>15 & buf[2]>25)){    
    if(color=="Red" && ((buf[0]>=0 & buf[0]<=11)||(buf[0]>=340 & buf[0]<=360))){
      state=1;
    } 
   else if(color=="Orange" && ((buf[0]>=18 & buf[0]<=39))){
    state=1;
    }     
   else if(color=="Yellow" && ((buf[0]>=41 & buf[0]<=62))){//yellow
     state=1;
    } 
  else if(color=="Green" && ((buf[0]>=67 & buf[0]<=169))){
      state=1;
    }   
 
   else if(color=="Purple" && ((buf[0]>=256 & buf[0]<=337))){
     state=1;
   }

    else if(color=="Blue" && ((buf[0]>194 & buf[0]<=255))){
      state=1;
    }
    else if(color=="Cyan" && ((buf[0]>=170 & buf[0]<=193))){
      state=1;
    }
  
 }
  else if(color=="White" && buf[0]<20 && (buf[1]<=7) &&buf[2]>=80){
    state=1;
  }
  else if(color=="Black"  &&( buf[2]<=25)){
    state=1;
  }
 else if(color=="Gray" && buf[0]>80 & buf[1]<=15 & (buf[2]>=30)&&(buf[1]<buf[2])){
    state=1;
 } 

  else{
    state=0;
  }
   delete [] ColorRgb;
   delete [] buf;
    return state;
   
  
}
 
void uKitSensor::setAllSensorOff(){
  setEyelightOff(0);
  setColorOff(0);
}


int uKitSensor::readButtonValue(char id){
  unsigned  char tData[1];
  volatile int State=0;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF7,1,1,2,tData);  //开触碰
    delay(5);
  }   
  return TXD(0xF7,1,1,4,tData)-(id-1)*256;  
  delay(5);
}

int uKitSensor::readUltrasonicDistance(char id){
  unsigned char tData[1];
  volatile int State=0;
  int distance;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF5,1,1,0x02,tData);
    delay(5);
  }
   distance+=TXD(0xF5,1,1,4,tData);
   distance/=10;
   if(distance!=0)
    return distance; 
  delay(5);
}
void uKitSensor::setNixieTubeFull(char id,uint8_t tpye,uint8_t method,uint8_t frequency,uint8_t times,uint8_t start,uint8_t ends){
  unsigned char tData[1]; 
  volatile int State=0;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF6,1,1,0x02,tData);  
    delay(5);
  }
  unsigned char xData[17];
  xData[0]=id;
  xData[1]=tpye;
  xData[2]=(uint8_t)method>>8;
  xData[3]=(uint8_t)method;
  xData[4]=frequency;
  xData[5]=(uint8_t)times>>24;  
  xData[6]=(uint8_t)times>>16;
  xData[7]=(uint8_t)times>>8;
  xData[8]=times;  
  xData[9]=(uint8_t)start>>24;
  xData[10]=(uint8_t)start>>16;
  xData[11]=(uint8_t)start>>8;
  xData[12]=start;  
  xData[13]=(uint8_t)ends>>24;
  xData[14]=(uint8_t)ends>>16;
  xData[15]=(uint8_t)ends>>8;
  xData[16]=ends; 
  State=TXD(0xF6,1,17,0x04,xData); 
  delay(5);
}
void uKitSensor::setNixieTube(char id,float number){
  
  unsigned char tData[1];
  uint16_t method;
  uint32_t numbers;
  volatile int State=0;
  numbers=number;
  if(numbers-number==0)
  {
    if(number<10 &number>=0)
      method=0x08;
    else if(number>=10 & number<100)
      method=0x0c;
    else if(number>=100 & number<1000)
      method=0x0e;
    else if(number>=1000 & number<10000)
      method=0x0f; 
   
  }
  else{
     if(numbers<10 &numbers>=0)
     {
        method=0x4c;
        number=number*10;
     }
    else if(numbers>=10 & numbers<100)
    {
      method=0x4e;
      number=number*10;
    }
    else if(numbers>=100 & numbers<1000)
    {
      method=0x4f;
      number=number*10;
    }
    
  }
  
  tData[0]=id;
  if(State==0){
    State=TXD(0xF6,1,1,0x02,tData);  
    delay(5);
  }

  unsigned char xData[17];
  xData[0]=id;
  xData[1]=0;
  xData[2]=method>>8;
  xData[3]=method;
  xData[4]=0;
  xData[5]=0>>24;  
  xData[6]=0>>16;
  xData[7]=0>>8;
  xData[8]=0;  
  xData[9]=(uint32_t)number>>24;
  xData[10]=(uint32_t)number>>16;
  xData[11]=(uint32_t)number>>8;
  xData[12]=(uint32_t)number;  
  xData[13]=0>>24;
  xData[14]=0>>16;
  xData[15]=0>>8;
  xData[16]=0; 
  TXD(0xF6,1,17,0x04,xData); 
  delay(5);
}
