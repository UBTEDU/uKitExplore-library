/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 10> 
 * 5.10.1 Line follower and obstacle avoiding robot 
 */ 
#include"uKitExplore2En.h" 
const int startingAngle = -45; 
const int minimumAngle = -45; 
const int maximumAngle = 45; 
const int rotationSpeed = 8; 
long distance=0; 
int lnum=0; 
int rnum=0; 
void straight(int speed); 
void setup() { 
  Initialization(); 
} 
void loop() { 
  getGrayAllValue(); 
  if(num1==1 & num2==1 & num3==1 &num4==1 &num5==1) 
 { 
  tt(50); 
 } 
 else 
 { 
  straight(20); 
} 
} 
void tt(int speed) 
{   
    //Forward 
    setMotorTurnAdj(2,-speed,0xffff); 
    setMotorTurnAdj(1,speed,0xffff); 
    static int motorAngle = startingAngle;//motorAngle is equal to its real angle; used to store the variable 
    static int setMotorTurnAdjAmount = rotationSpeed;//setMotorTurnAmount defines the stepping speed; declared as static so it can hold data between function calls, but other functions cannot change its value 
    setServoAngle(3,motorAngle,100);//Servo mode ID, angle, duration 
    delay(30); 
    distance=readUltrasonicDistance(1);//Ultrasonic ID 
    delay(30); 
    motorAngle += setMotorTurnAdjAmount; 
        if(motorAngle <= minimumAngle || motorAngle >= maximumAngle) { 
        setMotorTurnAdjAmount = -setMotorTurnAdjAmount; //Return to original if the maximum angle is exceeded        
    } 
     else if(distance<20 & distance !=0)//Detection distance 
     { 
      if(motorAngle<0) 
      { 
        //Turn right 
        setMotorTurnAdj(2,-speed,0xffff); 
        setMotorTurnAdj(1,-speed,0xffff); 
        delay(distance*20);//Can adjust the number to make the right turn smaller 
      } 
       else 
      { 
        //Turn left 
        setMotorTurnAdj(2,speed,0xffff); 
        setMotorTurnAdj(1,speed,0xffff); 
        delay(distance*20); //Can adjust the number to make the left turn smaller 
      } 
     }  
    } 
void turnLL(int speed) 
{ 
setMotorTurnAdj(2,speed,0xffff); 
setMotorTurnAdj(1,speed,0xffff); 
} 
void turnRR(int speed) 
{ 
setMotorTurnAdj(2,-speed,0xffff); 
setMotorTurnAdj(1,-speed,0xffff); 
} 
void forwardss(int speed) 
{ 
setMotorTurnAdj(2,-speed,0xffff); 
setMotorTurnAdj(1,speed,0xffff); 
} 
void straight(int speed) 
{ 
  getGrayAllValue(); 
    if(lnum+rnum>=3) 
    { 
      forwardss(speed); 
      delay(10); 
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
        delay(2); 
        rnum=rnum+1;      
      } 
      else if(num1==0 & num5==1) 
      {      
        turnLL(speed); 
        delay(2); 
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
