/*
 * 最新NOC
 */

#include"uKitExplore.h"
int lnum=0;
int rnum=0;
unsigned char route[500];
int route_node=1;
void straight(int speed);
void setup() 
{ 
  
  Initialization();//初始化
  button1.debounceTime = 20;//按键时长
  button1.multiclickTime = 250;//按键时长
  button1.longClickTime  = 1000;//按键时长
  motion_car(1);
  delay(30);

 
} 

void loop()
{
  button1.Update();//读取按键更新
  if(button1.clicks == 1)//按键按一下
  {
      while(1)
      {
        straight(2);
      }    
    }
  }


void cross(int speed) {
  switch (route[route_node]) {    
  case 1:   //任务1
    stops();
    delay(400);
    forward(2);
    delay(300);
     break;
  case 2:  //任务2
stops();

    break;
  case 3:  //任务3
      forward(speed);
      delay(1300);
      back(speed);
      delay(1000);     
      break;
  case 4://任务4
      stops();
     delay(300);
     motion_button(1);
     delay(300);
     motion_sitdown(1);
     forward(speed);
     delay(300);
      break;
  case 5://任务4
      break;

   
  }
  route_node = route_node + 1; //准备取优化路径的下一个节点
}

void straight(int speed)
{
  read_data();
  if(Battery_check()<=6.1 & Battery_check()>0.2)//检测电量函数，电池低于6.1V报警
  {
    stops();
    setcolor(1);
    tone(43,200);
    delay(200);
    noTone(43);
    setcolor(5);
    delay(200); 
  }
  else
  {
    noTone(43);
    if(lnum+rnum>=3)
    {
      forward(speed);
      delay(50);
      lnum=0;
      rnum=0;
    }
    if (num3 == 0)//中感測器在黑色區域
    {   
      if (num2 == 0 & num4 == 1) // 左黑右白, 向左轉彎
      {  
        turnL(speed);           
      } 
      else if (num2 == 1 & num4 == 0) //左白右黑, 向右轉彎
      {  
        turnR(speed); 
      }
      else if(num1==0 & num5==0 & num2==1 & num4==1)
      {
        cross(speed);
      }  
      else  // 兩側均為白色, 直進
      {    
        forward(speed);
      }      
    } 
    else // 中感測器在白色區域
    {    
      if(num1==1 & num5==0)
      {    
        turnR(speed);
        delay(80);
        rnum=rnum+1;     
      }
      else if(num1==0 & num5==1)
      {     
        turnL(speed);
        delay(80);
        lnum=lnum+1;     
      }
      else if (num2 == 0 & num4 == 1)// 左黑右白, 快速左轉 
      {  
        turnL(speed);
      
      }
      else if (num2 == 1 & num4 == 0) // 左白右黑, 快速右轉
      {  
        turnR(speed);  
      }
      else if(num1==0 & num5==0 & num2==1  & num4==1)
      {
        cross(speed);
      }  
      else // 都是白色, 停止
      {    
        forward(speed);
      }
    }
  
  
  }
}


