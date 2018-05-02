/*
 * 最新蔽障测试1
 * 在基础上修改
 * 最新库
 * （+，-）向后
 * （-，+）向前
 */




#include"uKitExplore.h"



 int i=1;

int buttomnum=0;
int hongwainum=0;
int jiguanbit=0;
int buttombit=0;
int hongwaibit=0;
const char jiguanid=1;
const char doorLid=2;
const char doorRid=3;
void setup() 
{ 
     delay(200);
     door(2);
     delay(100);
} 
void loop()
{
  maps(); 



}
void maps()
{
  unsigned long tCmd = 0;
  unsigned int  H1,H2=0;
  tCmd = uKit_button(1);
  delay(10);
  H1=ukit_infrared(1);
  delay(10);
  H2=ukit_infrared(2);
  delay(10);
        if(H1!=0 & H1<16 & jiguanbit==0)  
        {          
        hongwainum++;
        jiguan(2);
        jiguanbit=1;
        tone(43,200);
          delay(400);
          noTone(43);
        Serial.print("hongwai:");
       }
        else if(tCmd == 0x101)  //按一下停
        {
          
          buttomnum++;
          buttombit=1;
          tone(43,200);
          delay(400);
          noTone(43);
          Serial.print("buttom:");
        }
        else if(H2!=0& H2<17 & hongwaibit==0)
        {
           tone(43,200);
          delay(400);
          noTone(43);
          hongwainum++;
          hongwaibit=1;
          Serial.print("hongwai2:");
        }

      else if(jiguanbit==0){
        jiguan(1);
      }
      else if(buttombit==1 && hongwaibit==1)
      {
      door(1);
      }
}

void ukit_bottom()
{
    unsigned long tCmd = 0;

  
  tCmd = uKit_button(1);
  delay(20);
        if(tCmd == 0x101)  //按一下停
        {
        //  door(1);
          //buttomnum++;
          Serial.print("buttom:");
          //Serial.println(buttomnum);
        }
        if(tCmd == 0x102)  //按两下开
      {
        Serial.print("STart:");
        Serial.print("\r\n");
        Serial.print(tCmd,HEX);
      }


}
void door(char action)
{
  if(action==1)//opendoor
  {
   ServoAngle(doorLid,90,400);
   ServoAngle(doorRid,-90,400);
    delay(1000);
  }
    if(action==2)//closedoor
  {
    ServoAngle(doorLid,0,400);
    ServoAngle(doorRid,0,400);
    delay(300);
  }
}
void jiguan(char action)
{
  if(action==1)//funtion
  {
    ServoAngle(jiguanid,-40,700);
    delay(1000);
    ServoAngle(jiguanid,5,700);
    delay(1200);
  }
    if(action==2)//closefuntion
  {
    ServoAngle(jiguanid,-90,700);

    delay(300);
  }
}





