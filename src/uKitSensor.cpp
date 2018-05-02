#include"uKitSensor.h" 

int uKitSensor::ukit_infrared(char ID){//uKit红外传感器
  unsigned char hData[1];
  hData[0]=ID;
  TXD(0xF8,1,1,0x02,hData);
  delay(5);
  int distance = TXD(0xF8,1,1,4,hData);
  return distance*20/2790;
}

void uKitSensor::Set_infrared_id(char id){
  unsigned char tData[2];
  tData[0]=1;
  tData[1]=id;
  TXD(0xF8,1,2,0x06,tData);
}

int uKitSensor::uKit_button(char id){
  unsigned  char tData[1];
  tData[0]=id;
  TXD(0xF7,1,1,2,tData);  //开触碰
  delay(5);
  int ButtonState = TXD(0xF7,1,1,4,tData);
  return ButtonState;
}

int uKitSensor::uKit_Ultrasonic(char id){
  unsigned char tData[1];
  tData[0]=1;
  TXD(0xF5,1,1,0x02,tData);
  delay(5);
  return TXD(0xF5,1,1,4,tData); 
}
void uKitSensor::NixieTube_full(char id,uint8_t tpye,uint8_t method,uint8_t frequency,uint8_t times,uint8_t start,uint8_t ends){
  unsigned char tData[1];
  
  tData[0]=id;
  TXD(0xF6,1,1,0x02,tData);  
  delay(5);
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
 
  TXD(0xF6,1,17,0x04,xData); 
}
void uKitSensor::uKit_NixieTube(char id,float number){
  
  unsigned char tData[1];
  uint16_t method;
  uint32_t numbers;
  numbers=number;
  if(numbers-number==0)
  {
    if(number<10 &number>0)
      method=0x08;
    else if(number>10 & number<100)
      method=0x0c;
    else if(number>100 & number<1000)
      method=0x0e;
    else if(number>1000 & number<9999)
      method=0x0f; 
   
  }
  else{
     if(numbers<10 &numbers>0)
     {
        method=0x4c;
        number=number*10;
     }
    else if(numbers>10 & numbers<100)
    {
      method=0x4e;
      number=number*10;
    }
    else if(numbers>100 & numbers<1000)
    {
      method=0x4f;
      number=number*10;
    }
    
  }
  
  tData[0]=id;
  TXD(0xF6,1,1,0x02,tData);  
  delay(5);
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
}
