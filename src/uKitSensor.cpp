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
void uKitSensor::setEyelightPetals(char id,unsigned char petalsnum,unsigned char petals[8][4],unsigned char time){
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

unsigned char uKitSensor::readColorRgb(char id,unsigned char RGB){
  unsigned  char tData[1];
  unsigned char Value=0;
  tData[0]=id;
  volatile int State=0;
  if(State==0){
    State=TXD(0xE8,1,1,2,tData);  
    delay(5); 
    State=1;
  }
    Value=TXD(0xE8,1,1,4,RGB,tData);  
    delay(20);
    return Value;
 
 }

 
void uKitSensor::setColorOff(char id){
  unsigned  char tData[1];
  tData[0]=id;
  TXD(0xE8,1,1,3,tData); 
    delay(5);   
 }
bool uKitSensor::readColor(char id,String color){
  
  unsigned char Rvalue=readColorRgb(id,'R');
  unsigned char Gvalue=readColorRgb(id,'G');
  unsigned char Bvalue=readColorRgb(id,'B');
  bool state;
 
  if(color=="Red" & (Rvalue>90 & Rvalue<255 & Gvalue<120 &Bvalue<120)){
    state=1;
  }   
  else if(color=="Green" && (Gvalue>90 & Gvalue<255 & Rvalue<160 &Bvalue<120)&&(abs(Rvalue-Gvalue)>25)){
    state=1;
  }
  else if(color=="LBlue" && (Bvalue>90 & Bvalue<255 & Rvalue>120 & Rvalue<200 &Gvalue<220)&&(abs(Gvalue-Bvalue)<25)){
    state=1;
  }
  else if(color=="Blue" && (Bvalue>90 & Bvalue<255 & Rvalue>60 & Rvalue<120 &Gvalue<220)){
    state=1;
  }
  else if(color=="DBlue" && (Bvalue>90 & Bvalue<255 & Rvalue>20 & Rvalue<60 &Gvalue<220)){
    state=1;
  }
   
  else if(color=="White" && (Bvalue>200  & Rvalue>200 &Gvalue>200)){
    state=1;
   }
     else if(color=="Gray" && (Rvalue>70 & Rvalue<200 & Bvalue>70 & Bvalue<200 &Gvalue>70 & Gvalue<200) &&(abs(Rvalue-Bvalue)<=25 &abs(Bvalue-Gvalue)<=25)){
    state=1;
   }
 else if(color=="Black" && (Rvalue<70 & Bvalue<70 & Gvalue<70) &&(abs(Rvalue-Bvalue)<=25 &abs(Bvalue-Gvalue)<=25)){
    state=1;
   }
    
   else if(color=="Purple" && (Rvalue>90 & Rvalue<255  & Bvalue>90& Bvalue<255 &Gvalue<120)&&(abs(Rvalue-Bvalue)<=25)){
    state=1;
   }
    
   else if(color=="Yellow" &&((Rvalue>=90 & Rvalue<=255)  & (Gvalue>=90& Gvalue<=255) & Bvalue>=50 &Bvalue<=120)&&(abs(Rvalue-Gvalue)<=25)){//yellow
    state=1;
   }
   else if(color=="Orange" &&((Rvalue>=90 & Rvalue<=255)  & (Gvalue>=90& Gvalue<=255) & Bvalue>=0 &Bvalue<50)){//Orgin
    state=1;
   }

  else{
    state=0;
  }
    return state;
   
  
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
