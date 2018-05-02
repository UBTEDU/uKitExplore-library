#include"uKitExplore.h"
unsigned char id[6]={1,2,3,4,5,6};
void setup()
{
  Initialization();
}
void loop()
{
      button1.Update();//读取按键更新
  if(button1.clicks == 1)//按键按一下
  {
    ServoRead_PD_M(id,6);
  }
}

