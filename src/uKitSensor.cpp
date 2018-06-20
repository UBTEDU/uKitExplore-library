#include"uKitSensor.h" 

unsigned char  uKitSensor::uKit_Infrared(char ID){//uKit红外传感器
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

void uKitSensor::Set_Infrared_Id(char id){
  unsigned char tData[2];
  tData[0]=1;
  tData[1]=id;
  TXD(0xF8,1,2,0x06,tData);
  delay(5);
}
unsigned char uKitSensor::uKit_Sound_Read(char id){
  unsigned long tRet = 0;
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
  tRet=TXD(10,buf);
  return tRet;
}
unsigned char uKitSensor::uKit_Light_Read(char id){
  unsigned long tRet = 0;
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
  return tRet;
}
void uKitSensor::uKit_Led_Face(char id,char face,int times,int red,int green,int blue){

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
  delay(5);

 }
void uKitSensor::uKit_Led_Scene(char id,char scene,int times){

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
  delay(5);
 }
void uKitSensor::uKit_Leds(char id,int red,int green,int blue){

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
  delay(5);
 }
void uKitSensor::uKit_Led_off(char id){
  signed char tData[1];
  volatile int State=0;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF4,1,1,0x3,tData);
    delay(5);
  }
 } 
signed char uKitSensor::uKit_Humiture(char id, char choice){
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
  return tRet;
}
void uKitSensor::uKit_RGB_Read(char id){
  unsigned  char tData[1];
  tData[0]=id;
  volatile int State=0;
  if(State==0){
    State=TXD(0xE8,1,1,2,tData);  
    delay(5); 
  }
    State=TXD(0xE8,1,1,4,tData);  
    delay(8);

 
 }
void uKitSensor::uKit_RGB_off(char id){
  unsigned  char tData[1];
  tData[0]=id;
  TXD(0xE8,1,1,3,tData); 
    delay(5);   
 }
bool uKitSensor::uKit_RGB_Readcolor(char id,char color){
  uKit_RGB_Read(id);
  unsigned char Rvalue=redvalue;
  unsigned char Gvalue=greenvalue;
  unsigned char Bvalue=bluevalue;
  if(Rvalue>80 & Rvalue<255 & Gvalue<150 &Bvalue<150 & color=='R')
    return true;
  else if(Gvalue>80 & Gvalue<255 & Rvalue<150 &Bvalue<150 & color=='G')
    return true;
  else if(Bvalue>80 & Bvalue<255 & Rvalue<150 &Gvalue<150 & color=='B')
    return true;
  else if(Bvalue>200  & Rvalue>200 &Gvalue>200 & color=='W')
    return true;   
  else if(Rvalue>50 & Rvalue<240  & Bvalue>40& Bvalue<255 &Gvalue<80 & color=='P')
    return true;      
  else if(Rvalue>60 & Rvalue<255  & Bvalue>30& Bvalue<180 &Rvalue>60 & Rvalue<255 & color=='Y')
    return true;  
  else
    return false;
   
  
}
 
  


int uKitSensor::uKit_Button(char id){
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

int uKitSensor::uKit_Ultrasonic(char id){
  unsigned char tData[1];
  volatile int State=0;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF5,1,1,0x02,tData);
    delay(5);
  }
  return TXD(0xF5,1,1,4,tData); 
  delay(5);
}
void uKitSensor::uKit_NixieTube_Full(char id,uint8_t tpye,uint8_t method,uint8_t frequency,uint8_t times,uint8_t start,uint8_t ends){
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
void uKitSensor::uKit_NixieTube(char id,float number){
  
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
