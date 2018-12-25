/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 6> 
 * 5.6.2 Line follower robot 
 */ 
#include "uKitExplore2En.h" 
int lnum=0;//Define the variable 
int rnum=0; 
void straight(int speed);//Declaration function 
void setup()  
{  
  Initialization();//Initialization 
}  
void loop() 
{ 
straight(100);//Execute straight, speed 
} 
void forwardss(int speed) 
{ 
setMotorTurn(1,-speed); 
setMotorTurn(2,speed); 
} 
void turnLL(int speed)//Turn left 
{ 
setMotorTurn(1,speed); 
setMotorTurn(2,speed); 
} 
void turnRR(int speed)//Turn right 
{ 
setMotorTurn(1,-speed); 
setMotorTurn(2,-speed); 
} 
 
void straight(int speed)//Go straight 
{ 
  getGrayAllValue(); 
    if(lnum+rnum>=3) 
    { 
      forwardss(speed); 
      delay(50); 
      lnum=0; 
      rnum=0; 
    } 
    if (num3 == 0)//If sensor is in the black zone 
    {    
      if (num2 == 0 & num4 == 1) // If black on the left and white on the right, turn left 
      {   
        turnLL(speed);            
      }  
      else if (num2 == 1 & num4 == 0) //If white on the left and black on the right, turn right 
      {   
        turnRR(speed);  
      } 
      else  // If white on both sides, go straight 
      {     
          forwardss(speed); 
      }       
    }  
    else // If sensor is in the white zone 
    {     
      if(num1==1 & num5==0) 
      {     
        turnRR(speed); 
        delay(30); 
        rnum=rnum+1;      
      } 
      else if(num1==0 & num5==1) 
      {      
        turnLL(speed); 
        delay(30); 
        lnum=lnum+1;      
      } 
      else if (num2 == 0 & num4 == 1)// If black on the left and white on the right, turn left quickly  
      {   
        turnLL(speed); 
      } 
      else if (num2 == 1 & num4 == 0) // If white on the left and black on the right, turn right quickly 
      {   
        turnRR(speed);   
      } 
      else // If all white, stop 
      {     
        forwardss(speed); 
      } 
    } 
} 

