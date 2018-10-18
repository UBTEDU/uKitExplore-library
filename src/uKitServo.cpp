
#include"uKitServo.h"  



void uKitServo::setServoTurn(char id,int dir, int speed){
  unsigned char buf[4];
  volatile int t=0;
  int speeds=0;
  speeds=constrain((speed*3.92),0,1000);
 
  if(t!=speeds)
  {
    setServoStop(id);
    t=speeds;
   
  }
 
    
    if(dir==0){
        buf[0]=0xFD;
        buf[1]=0x00;
        buf[2]=(speeds &0xFF00) >> 8;
        buf[3] = speeds & 0x00FF;
      
        TXD(0xFA,id,4,0x01,buf); 
    }     
    else if(dir==1){
        buf[0]=0xFE;
        buf[1]=0x00;
        buf[2]=(speeds &0xFF00) >> 8;
        buf[3] = speeds & 0x00FF;
        TXD(0xFA,id,4,0x01,buf);
         
    }
        
  // t=speed;
  
}



//id表示舵机号，angle表示角度（角度范围-118°~118°），time表示旋转所需时间（时间范围：300~5000）
void uKitServo::setServoAngle(char id,int angle,int times){
  unsigned char tData[4];
  tData[0]=angle+120;
  tData[1]=(times/20);
  tData[2]=((times/20) & 0xFF00) >> 8;
  tData[3]=(times/20) & 0x00FF;

  TXD(0xFA,id,4,0x01,tData );
}
void uKitServo::setServoStop(char id){
  unsigned char aa[4]={0xFF,0,0,0};
  TXD(0xFA,id,4,0x01,aa); 
}

void uKitServo::setServoStiffness(char id,unsigned char stiffness){
  unsigned char tData[4];
  tData[0]=stiffness;
  tData[1]=0;
  tData[2]=0;
  tData[3]=0;
  
  TXD(0xFA,id,8,0x01,tData );
}

int uKitServo::readServoAnglePD(char id){//单个舵机回读(掉电回读）
  int tCmd=0;
  unsigned char aa[4]={0,0,0,0};
  tCmd=TXD(0xFA,id,4,0x02,aa)-120;
  delay(5);
  if(tCmd>=-118 & tCmd<=118 )
    return tCmd;
  else
    return 0;


}

void uKitServo::readServoAnglePD_M(char read_id[],char num)//舵机回读
{
    int setServoAngle=0;
    Serial.println("");
    Serial.print("----------");
    Serial.print(read_num++);
    Serial.println("----------");
    Serial.print("{");
    for(int i=0;i<num;i++)
    {
        setServoAngle=readServoAnglePD(read_id[i]);
        delay(20);
        if(setServoAngle>=-118 && setServoAngle<=118)
        {
          Serial.print(setServoAngle);
          if(i<num-1)
            Serial.print(",");
        }
        
        else
        {
          Serial.print("id-");
          Serial.print(setServoAngle);
          Serial.print(":Out of range,");
        }
    }
      Serial.print("}");
  
    
  
 

}
int uKitServo::readServoAngleNPD(char id){//单个舵机回读(不掉电回读）
  int tCmd=0;
  unsigned char aa[4]={0,0,0,0};


  tCmd=TXD(0xFA,id,4,0x03,aa)-120;
  delay(5);
  
  if(tCmd>=-118 & tCmd<=118)
    return tCmd;
  else
    return 0;

}

void uKitServo::readServoAngleNPD_M(char read_id[],char num)//舵机回读
{
    int setServoAngle=0;
    Serial.println("");
    Serial.print("----------");
    Serial.print(read_num++);
    Serial.println("----------");
    Serial.print("{");
    for(int i=0;i<num;i++)
    {
        setServoAngle=readServoAngleNPD(read_id[i]);
        delay(20);
        if(setServoAngle>=-118 && setServoAngle<=118)
        {
          Serial.print(setServoAngle);
          if(i<num-1)
            Serial.print(",");
        }
        
        else
        {
          Serial.print("id-");
          Serial.print(setServoAngle);
          Serial.print(":Out of range,");
        }
    }
      Serial.print("}");
  
    
  
 

}
void uKitServo::ServoRead(){
  unsigned char t=0;
  static char ServoId[18],ServoIdRead[18];
  static int start=0;
  if(start==0){
  Serial.print("当前读取的舵机ID：{");
  for(int i=1;i<=18;i++){
    ServoId[i]=getServoId(i);
    if(ServoId[i]!=0){
     
      ServoIdRead[t]=ServoId[i];
      Serial.print(ServoIdRead[t]);
        Serial.print(",");
      ++t;
      
    }
  }
  Serial.println("}");
  start=1;
  }
  readServoAnglePD_M(ServoIdRead,t);
}
void uKitServo::motion(unsigned char id[],signed char action[][sizeof(id)/sizeof(id[0])],signed char time[],int times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(action)/sizeof(action[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        setServoAngle(id[t],action[i][t],500);
      }  
      delay(time[i]);
    }
  }
}
