
#include"uKitServo.h"  



void uKitServo::ServoRotate(char id,int dir, int speed){
  int isNewSpeed = 0;
  static char t=10;
  char a=10;
  
  if(t!=speed)
  {
    ServoStop(id);
    t=speed;
    isNewSpeed = 1;
  }
  
  if ((10 == a) ||(10 == t) || (isNewSpeed == 1))
  {
    //ServoRotates(id,dir,speed);
    unsigned char aa[4]={0xFE,0,speed,0};//fan
    unsigned char bb[4]={0xFD,0,speed,0};//zheng
    if(dir==0)  
      TXD(0xFA,id,4,0x01,aa);  
    else if(dir==1)   
      TXD(0xFA,id,4,0x01,bb);  
    t=speed;
  }
}



//id表示舵机号，angle表示角度（角度范围-118°~118°），time表示旋转所需时间（时间范围：300~5000）
void uKitServo::ServoAngle(char id,int angle,int times){
  unsigned char tData[4];
  tData[0]=angle+120;
  tData[1]=(times/20);
  tData[2]=0;
  tData[3]=0;
  TXD(0xFA,id,4,0x01,tData );
}
void uKitServo::ServoStop(char id){
  unsigned char aa[4]={0xFF,0,0,0};
  TXD(0xFA,id,4,0x01,aa); 
}

int uKitServo::ServoRead_PD(char id){//单个舵机回读(掉电回读）
  int tCmd=0;
  unsigned char aa[4]={0,0,0,0};
  tCmd=TXD(0xFA,id,4,2,aa)-120;
  delay(5);
  if(tCmd>=-118 && tCmd<=118)
    return tCmd;

}

void uKitServo::ServoRead_PD_M(char read_id[],char num)//舵机回读
{
    int ServoAngle=0;
    Serial.println("");
    Serial.print("----------");
    Serial.print(read_num++);
    Serial.println("----------");
    Serial.print("{");
    for(int i=0;i<num;i++)
    {
        ServoAngle=ServoRead_PD(read_id[i]);
        delay(20);
        if(ServoAngle>=-118 && ServoAngle<=118)
        {
          Serial.print(ServoAngle);
          if(i<num-1)
            Serial.print(",");
        }
        
        else
        {
          Serial.print("id-");
          Serial.print(ServoAngle);
          Serial.print(":Out of range,");
        }
    }
      Serial.print("}");
  
    
  
 

}
int uKitServo::ServoRead_NPD(char id){//单个舵机回读(不掉电回读）
  int tCmd=0;
  unsigned char aa[4]={0,0,0,0};
  tCmd=TXD(0xFA,id,4,3,aa)-120;
  delay(5);
  if(tCmd>=-118 && tCmd<=118)
    return tCmd;


}

void uKitServo::ServoRead_NPD_M(char read_id[],char num)//舵机回读
{
    int ServoAngle=0;
    Serial.println("");
    Serial.print("----------");
    Serial.print(read_num++);
    Serial.println("----------");
    Serial.print("{");
    for(int i=0;i<num;i++)
    {
        ServoAngle=ServoRead_NPD(read_id[i]);
        delay(20);
        if(ServoAngle>=-118 && ServoAngle<=118)
        {
          Serial.print(ServoAngle);
          if(i<num-1)
            Serial.print(",");
        }
        
        else
        {
          Serial.print("id-");
          Serial.print(ServoAngle);
          Serial.print(":Out of range,");
        }
    }
      Serial.print("}");
  
    
  
 

}

