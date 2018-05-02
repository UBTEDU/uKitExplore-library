
#include"TransforRobot.h" 

//小车前进speed表示前进速度（速度范围：0-5）
void TransforRobot::forward(int speeds){
  ServoRotate(lmotor,0,speeds);//1表示顺时针，0表示逆时针
  ServoRotate(rmotor,1,speeds);
}

//小车前进speed表示前进速度（速度范围：0-5）
void TransforRobot::forward(int Lspeed,int Rspeed){
  ServoRotate(lmotor,0,Lspeed);//1表示顺时针，0表示逆时针
  ServoRotate(rmotor,1,Rspeed);
}


//小车左转speed表示前进速度（速度范围：0-5）
void TransforRobot::turnL(int speed){
  ServoRotate(lmotor,1,speed);//1表示顺时针，0表示逆时针
  ServoRotate(rmotor,1,speed);
}

//小车右转speed表示前进速度（速度范围：0-5）
void TransforRobot::turnR(int speed){
  ServoRotate(lmotor,0,speed);//1表示顺时针，0表示逆时针
  ServoRotate(rmotor,0,speed);
}

void TransforRobot::turnL(int Lspeed,int Rspeed){
  ServoRotate(lmotor,1,Lspeed);//1表示顺时针，0表示逆时针
  ServoRotate(rmotor,1,Rspeed);
}

//小车右转speed表示前进速度（速度范围：0-5）
void TransforRobot::turnR(int Lspeed,int Rspeed){
  ServoRotate(lmotor,0,Lspeed);//1表示顺时针，0表示逆时针
  ServoRotate(rmotor,0,Rspeed);
}

//小车后退speed表示前进速度（速度范围：0-5）
void TransforRobot::back(int speed){
  ServoRotate(lmotor,1,speed);
  ServoRotate(rmotor,0,speed);
}

//小车停止
void TransforRobot::stops(){
  ServoStop(lmotor);
  ServoStop(rmotor);
  
}
void TransforRobot::turn_L(int speed){//90
     forward(speed);//前进
     delay(500);
     turnL(speed);
     delay(400);//拐弯的时间
    do
    {
      turnL(speed);
      delay(140);//若没拐到中心继续拐
      read_data();
    }while (num3 == 0||num4 == 0);
     stops();

    
}

void TransforRobot::turn_R(int speed){
    forward(speed);//前进
    delay(500);
    turnR(speed);
    delay(400);//拐弯的时间
    do
     {
         turnR(speed);
         delay(140);//若没拐到中心继续拐
         read_data();
      }while(num3 == 0 ||num2 == 0);
      stops();
} 
/**@brief EN:Turn a corner in human form/CN:车形态转弯.
 *
 * @param[in] speed EN:Turning speed(Range:0~5)/CN:转弯速度（0~5）.
 *
 */
void TransforRobot::turn_U(int speed){
  one_step(speed,300);   //确保足够的转弯半径
  do{
    turnL(speed); //掉头
    read_data();
  } while ( num3 == 1);
  stops();
}
/**@brief EN:A step forward in the shape of the car/CN:车形态前进一小步.
 *
 * @param[in] time EN:forward time/CN:前进时间.
 *
 */
void TransforRobot::one_step(int speed,int time)
{
  ServoRotate(lmotor,0,speed);//1表示顺时针，0表示逆时针
  ServoRotate(rmotor,1,speed);
  delay(time);
  stops();
  
}
void TransforRobot::motion_case(int cases,char times){
  if(cases==0)
    motion_getup(times);
  else if(cases==1)
    motion_forward(times);
  else if(cases==2)
    motion_back(times);   
  else if(cases==3)
    motion_omotion(times);  
  else if(cases==4)
    motion_car(times);
  else if(cases==5)
    motion_button(times);   
  else if(cases==6)
    motion_lift(times);      
  else if(cases==7)
    motion_lift_hand(times);
  else if(cases==8)
    motion_head(times);   
  else if(cases==9){
    for(int c=0;c<times;c++){
      forward(2);
      delay(300);
      stops();
    }
  }
  else if(cases==10){
     for(int c=0;c<times;c++){
      back(2);
      delay(300);
      stops();
    }
   }
  else if(cases==11){
     for(int c=0;c<times;c++){
      turnL(2);
      delay(300);
      stops();
    }
   } 
  else if(cases==12){
     for(int c=0;c<times;c++){
      turnR(2);
      delay(300);
      stops();
    } 
  }
    else if(cases==13){
      motion_sitdown(times); 
    } 
    else{
      motion_zero(times);
    }   
}

/**@brief EN:Robot humanoid forward action/CN:机器人人形前进动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_forward(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(m_forward)/sizeof(m_forward[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(m_forward[i][t]),300);
      }  
      delay(forward_times[i]);
    }
  }   
}

/**@brief EN:Car shape/CN:机器人车形态.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_car(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(car)/sizeof(car[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(car[i][t]),700);
      }  
      delay(omotion_times[i]);
      }
  }
}
/**@brief EN:Robot vehicle shape deformed humanoid/CN:机器人车型变人形.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_getup(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(get_up)/sizeof(get_up[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(get_up[i][t]),500);
      }  
      delay(get_up_times[i]);
    }
  }
}
/**@brief EN:Robot humanoid deformed vehicle shape/CN:机器人人形变车型.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_sitdown(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(sitdown)/sizeof(sitdown[0]);i++) {
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(sitdown[i][t]),500);
      }  
      delay(sitdown_times[i]);
    }
  }
}
/**@brief EN:Robot humanoid back action/CN:机器人人形h后退动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_back(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(m_back)/sizeof(m_back[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(m_back[i][t]),300);
      }  
      delay(back_times[i]);
    }
  }
}
/**@brief EN:Robot humanoid left shift action/CN:机器人人形左移动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_left_shift(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(left_shift)/sizeof(left_shift[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(left_shift[i][t]),280);
      }  
      delay(left_shift_times[i]);
    }
  }
}
/**@brief EN:Robot humanoid right shift action/CN:机器人人形右移动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_right_shift(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(right_shift)/sizeof(right_shift[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(right_shift[i][t]),300);
      }  
      delay(right_shift_times[i]);
    }
  }
}
/**@brief EN:Robot humanoid turn left action/CN:机器人人形左拐动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_turn_left(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(turn_left)/sizeof(turn_left[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(turn_left[i][t]),300);
      }  
      delay(turn_left_times[i]);
    }
  }
}
/**@brief EN:Robot humanoid turn right action/CN:机器人人形右拐动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_turn_right(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(turn_right)/sizeof(turn_right[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(turn_right[i][t]),300);
      }  
      delay(turn_right_times[i]);
    }
  }
}
/**@brief EN:Robot initialization action/CN:机器人初始化动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_omotion(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(omotion)/sizeof(omotion[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(omotion[i][t]),700);
      }  
      delay(omotion_times[i]);
    }
  }
}
/**@brief EN:The robot presses the button action/CN:机器人按下按键动作
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_button(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(button)/sizeof(button[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(button[i][t]),300);
      }  
      delay(button_times[i]);
    }
  }
}
/**@brief EN:The robot raised his right hand action/CN:机器人举起右手动作
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_lift(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(lift)/sizeof(lift[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(lift[i][t]),300);
      }  
      delay(lift_times[i]);
    }
  }
}
/**@brief EN:Robot lifting hands action/CN:机器人举起双手动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_lift_hand(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(lift_hand)/sizeof(lift_hand[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(lift_hand[i][t]),300);
      }  
      delay(lift_hand_times[i]);
    }
  }
}
/**@brief EN:Robot head impact action/CN:机器人头部撞击函数.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_head(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(head)/sizeof(head[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(head[i][t]),300);
      }  
      delay(head_times[i]);
    }
  }
}
/**@brief EN:All zero robot action/CN:机器人全零动作.
 *
 * @param[in] times EN:Action execution times/CN:动作执行次数.
 */
void TransforRobot::motion_zero(char times){
  for(int c=0;c<times;c++){
    for(int i=0;i<sizeof(mzero)/sizeof(mzero[0]);i++){
      for(int t=0;t<sizeof(id)/sizeof(id[0]);t++){
        ServoAngle(id[t],(mzero[i][t]),300);
      }  
      delay(mzero_times[i]);
    }
  }
}


