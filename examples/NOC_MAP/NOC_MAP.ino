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
void setup() { 
  delay(200);
  door(2);
  delay(100);
} 
void loop(){
  maps(); 

}
void maps()
{
  unsigned long tCmd = 0;
  unsigned int  H1,H2=0;
  tCmd = readButtonValue(1);
  delay(10);
  H1=readInfraredDistance(1);
  delay(10);
  H2=readInfraredDistance(2);
  delay(10);
        if(H1!=0 & H1<18 & jiguanbit==0)  
        {          
        hongwainum++;
        jiguan(2);
        jiguanbit=1;
        tone(43,200);
          delay(400);
          noTone(43);
        Serial.print("hongwai:");
       }
        else if(tCmd == 1)  //按一下停
        {
          
          buttomnum++;
          buttombit=1;
          tone(43,200);
          delay(400);
          noTone(43);
          Serial.print("buttom:");
        }
        else if(H2!=0& H2<19 & hongwaibit==0)
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

  
  tCmd = readButtonValue(1);
  delay(20);
        if(tCmd == 1)  //按一下停
        {
        //  door(1);
          //buttomnum++;
          Serial.print("buttom:");
          //Serial.println(buttomnum);
        }
        if(tCmd == 2)  //按两下开
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
   setServoAngle(doorLid,90,400);
   setServoAngle(doorRid,-90,400);
    delay(1000);
  }
    if(action==2)//closedoor
  {
    setServoAngle(doorLid,0,400);
    setServoAngle(doorRid,0,400);
    delay(300);
  }
}
void jiguan(char action)
{
  if(action==1)//funtion
  {
    setServoAngle(jiguanid,-40,700);
    delay(1000);
    setServoAngle(jiguanid,5,700);
    delay(1200);
  }
    if(action==2)//closefuntion
  {
    setServoAngle(jiguanid,-90,700);

    delay(300);
  }
}
