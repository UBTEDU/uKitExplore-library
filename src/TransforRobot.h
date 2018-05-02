

#ifndef TRANSFORROBOT_h
#define TRANSFORROBOT_h

#include <Arduino.h>
#include"uKitServo.h" 
#include"Sensor.h" 
 
class TransforRobot:public uKitServo,public Sensor
{
public:
    void forward(int speeds);//小车前进函数，速度0-5
    void forward(int Lspeed,int Rspeed);
    void turnL(int speed);//小车左转，速度0-5
    void turnR(int speed);//小车右转，速度0-5
    void turnL(int Lspeed,int Rspeed);
    void turnR(int Lspeed,int Rspeed);
    void back(int speed);//小车后退函数，速度0-5
    void stops();//小车停止函数
    void turn_L(int speed);
    void turn_R(int speed);
    void turn_U(int speed);
    void one_step(int speed,int time);
    void motion_case(int cases,char times);
    void motion_forward(char times);//人形模式前进
    void motion_car(char times);//保持车形态
    void motion_getup(char times);//车变人
    void motion_sitdown(char times);//人变车
    void motion_back(char times);//人形模式后退
    void motion_left_shift(char times);//人形模式左移
    void motion_right_shift(char times);//人形模式右移
    void motion_turn_left(char times);//人形模式左拐
    void motion_turn_right(char times);//人形模式右拐
    void motion_omotion(char times);//保持人形态
    void motion_button(char times);//人形按键
    void motion_lift(char times);//让机器人举起右手. times表示执行动作的次数。一次为一步动作。
    void motion_lift_hand(char times);//让机器人举起双手. times表示执行动作的次数。一次为一步动作。
    void motion_head(char times);//拆引爆雷
    void motion_zero(char times);//零状态
    
    const signed char lmotor=13;
    const signed char rmotor=8;
    
    const signed char id[12]={1,2,3,9,10,11,4,5,6,14,15,16};
    const signed char forward2[4][12]={{109,-60,50,-13,-10,35,-90,60,-50,13,8,5},{90,-60,50,-12,-18,0,-109,60,-50,-8,-15,0},{109,-60,50,-11,-5,0,-90,60,-50,13,10,-35},{90,-60,50,8,15,0,-109,60,-50,12,18,0}};
    const signed char m_forward[4][12]={{109,-60,50,-13,-10,35,-90,60,-50,13,8,5},{90,-60,50,-12,-18,0,-109,60,-50,-8,-13,0},{109,-60,50,-11,-5,0,-90,60,-50,13,10,-35},{90,-60,50,8,15,0,-109,60,-50,12,18,0}};  
    const signed char m_back[4][12]={{90,-60,50,10,15,0,-109,60,-50,10,18,0},{109,-60,50,-9,-5,0,-90,60,-50,11,10,-35},{90,-60,50,-10,-18,0,-109,60,-50,-10,-15,0},{109,-60,50,-11,-10,35,-90,60,-50,11,8,5}}; 
    const signed char get_up[5][12]={{0,90,-80,90,2,-90,0,-90,80,-90,2,90},{0,0,0,9,100,0,0,0,0,-9,-100,0},{5,-95,0,-106,-30,0,-5,95,0,106,30,0},{60,-70,0,-105,-68,0,-60,70,0,105,68,0},{90,-75,55,-5,-5,0,-90,75,-55,5,5,0}};
    const signed char sitdown[5][12]={{90,-75,55,-5,-5,0,-90,75,-55,5,5,0},{0,-90,0,-105,-60,0,0,90,0,105,60,0},{0,-90,0,-104,-20,0,0,90,0,104,20,0},{-20,-80,0,-30,75,0,20,80,0,30,-75,0},{0,90,-80,90,2,-90,0,-90,80,-90,2,90}}; 
    const signed char left_shift[2][12]={{97,-45,33,-35,-22,-44,-74,47,-34,24,20,0},{81,-45,33,-35,-22,0,-97,47,-34,24,22,0}};//左移
    const signed char right_shift[2][12]={{62,-53,33,-35,-19,0,-105,45,-37,24,19,44},{85,-53,33,-35,-19,0,-85,45,-37,24,19,0}};//右移
    const signed char turn_left[3][12]={{84,-48,44,3,0,0,-95,45,-50,-3,0,0},{84,-48,44,-60,-60,-10,-95,45,-37,-60,-60,0},{84,-48,44,-3,0,0,-95,45,-50,3,0,0}};//左拐
    const signed char turn_right[3][12]={{84,-48,44,-3,0,0,-95,45,-50,3,0,0},{84,-48,44,71,58,0,-95,45,-37,58,71,-23},{84,-48,44,-3,0,0,-95,45,-37,3,0,0}};//右拐
    const signed char button[6][12]={{90,-75,55,-5,-5,0,-90,75,-55,5,5,0},{-22,-90,55,-5,-5,0,-90,75,-55,5,5,0},{-22,-5,45,-5,-5,0,-90,75,-55,5,5,0},{-22,-12,-30,-5,-5,0,-90,75,-55,5,5,0},{-5,-99,3,-5,-5,0,-90,75,-55,5,5,0},{93,-70,3,-5,-5,0,-90,75,-55,5,5,0}};//按键
    const signed char lift[3][12]={{90,-75,55,-5,-5,0,-90,75,-55,5,5,0},{90,-75,55,-5,-5,0,0,-2,-85,5,5,0},{90,-75,55,-5,-5,0,30,85,-25,5,5,0}};//人形抬手
    const signed char lift_hand[3][12]={{90,-75,55,-5,-5,0,-90,75,-55,5,5,0},{30,-78,90,-5,-5,0,-30,78,-90,5,5,0},{-30,-78,90,-5,-5,0,30,78,-90,5,5,0}};//人形抬手
    const signed char head[3][12]={{30,-78,90,-6,-3,0,-30,78,-90,6,3,0},{90,-75,55,-60,-25,0,-90,75,-55,60,25,0},{30,-78,90,-6,-3,0,-30,78,-90,6,3,0}};//人点头      
    const signed char car[1][12]={{0,90,-80,90,2,-90,0,-90,80,-90,2,90}};
    const signed char omotion[1][12]={{90,-75,55,-5,-5,0,-90,75,-55,5,5,0}};  
    const signed char mzero[1][12]={{0,0,0,0,0,0,0,0,0,0,0,0}};   
    const int get_up_times[5]={600,600,1000,1000,1000};
    const int sitdown_times[5]={400,400,400,400,400};
    const int forward_times[4]={300,300,300,250};
    const int back_times[4]={300,300,300,300};//时间    
    const int left_shift_times[2]={280,280};//时间
    const int right_shift_times[2]={280,280};//时间
    const int turn_left_times[3]={400,400,400};//时间
    const int turn_right_times[3]={400,400,400};//时间
    const int button_times[6]={600,600,600,600,600,600};//时间
    const int lift_times[3]={400,400,400};//时间
    const int lift_hand_times[3]={400,400,400};//时间
    const int head_times[3]={400,400,400};//时间
    const int omotion_times[1]={400};//时间    
    const int mzero_times[1]={300};



  
};

#endif

