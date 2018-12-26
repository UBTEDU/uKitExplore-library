/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 7> 
 * 5.7.2 Obstacle avoidance car 
 */ 
 
#include"uKitExplore2En.h" 
const int startingAngle = -45;//Initial angle 
const int minimumAngle = -45;//Minimum angle 
const int maximumAngle = 45;//Maximum angle 
const int rotationSpeed = 8;//Stepping speed 
long distance=0;//Initialize the distance 
 
void setup() { 
  Initialization(); 
  // put your setup code here, to run once: 
 
} 

 
void loop() { 
  // put your main code here, to run repeatedly: 
 
    while(1) 
    { 
      tt(50);//Speed 
    } 
   
} 
void tt(int speed) 
{   
    //Forward 
    setServoTurn(1,1,speed); 
    setServoTurn(2,0,speed); 
     
    static int motorAngle = startingAngle;//motorAngle is equal to its real angle; used to store the variable 
    static int setMotorTurnAmount = rotationSpeed;//setMotorTurnAmount defines the stepping speed; declared as static so it can hold data between function calls, but other functions cannot change its value 
    setServoAngle(3,motorAngle,100); 
    delay(30); 
    distance=readUltrasonicDistance(1);//Ultrasonic sensor ID 
    delay(30); 
    
    motorAngle += setMotorTurnAmount; 
     
    if(motorAngle <= minimumAngle || motorAngle >= maximumAngle)  
    { 
        setMotorTurnAmount = -setMotorTurnAmount;         
    } 
 
     else if(distance<20 & distance !=0)//Detection distance 
     { 
      if(motorAngle<0) 
      { 
        //Turn right 
        setServoTurn(1,1,speed); 
                setServoTurn(2,1,speed); 
        delay(distance*20); 
      } 
       else 
      { 
        //Turn left 
        setServoTurn(1,0,speed); 
        setServoTurn(2,0,speed); 
        delay(distance*50); 
      } 
     }  
    }
