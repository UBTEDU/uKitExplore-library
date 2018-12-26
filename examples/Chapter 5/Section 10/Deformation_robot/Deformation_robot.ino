/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 10> 
 * 5.10.2 Transforming robot warrior 
 */ 
 
 
#include"uKitExplore2En.h" 
int lnum=0; 
int rnum=0; 
unsigned char route[500]; 
int route_node=1; 
void straight(int speed); 
void setup()  
{  
   
  Initialization();//Initialization 
  motion_car(1); 
  delay(30); 
   route[1]=1; 
   route[2]=2; 
   route[3]=4; 
   route[4]=3; 
}  
 
void loop() 
{ 
  button1.Update();//Read button update 
  if(button1.clicks == 1)//Button is clicked once 
  { 
      while(1) 
      { 
        straight(100);//Speed is adjustable 
              }     
    } 
  } 
 
void cross(int speed) { 
  switch (route[route_node]) {     
  case 1:   //Task 1 
      stops(); 
      delay(400); 
      forward(speed); 
      delay(300); 
   break; 
   case 2:  //Task 2 
      forward(speed); 
      delay(300); 
      stops(); 
      delay(300); 
      motion_getup(1); 
      delay(300); 
      motion_forward(2); 
      delay(200); 
      motion_omotion(1); 
      delay(200); 
      motion_sitdown(1); 
      delay(400); 
      forward(speed); 
      delay(100); 
 
   break; 
      case 3:  //Task 3 stops 
      forward(speed); 
      delay(200); 
      stops(); 
      delay(300); 
      while(1); 
   break; 
   case 4://Task 4 
         forward(speed); 
      delay(200); 
      stops(); 
      delay(300); 
      motion_getup(1); 
      delay(300); 
      motion_lift_hand(1); 
      delay(300); 
      motion_sitdown(1); 
      delay(400); 
      forward(speed); 
      delay(100); 
   break; 
   case 5://Task 5 
    
   break; 
 
    
  } 
  route_node = route_node + 1; //Prepare to take the next node of the optimal route 
} 
 
void straight(int speed) 
{ 
  getGrayAllValue(); 
 { 
    noTone(43); 
    if(lnum+rnum>=3) 
    { 
      forward(speed); 
      delay(50); 
      lnum=0; 
      rnum=0; 
    } 
    if (num3 == 0)//If sensor is in the black zone 
    {    
      if (num2 == 0 & num4 == 1) // If black on the left and white on the right, turn left 
           {   
        turnL(speed);            
      }  
      else if (num2 == 1 & num4 == 0) //If white on the left and black on the right, turn right 
      {   
        turnR(speed);  
      } 
      else if(num1==0 & num5==0 & num2==1 & num4==1) 
      { 
        cross(speed); 
      }   
      else  // If white on both sides, go straight 
      {     
        forward(speed); 
      }       
    }  
    else // If sensor is in the white zone 
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
      else if (num2 == 0 & num4 == 1)// If black on the left and white on the right, turn left quickly  
      {   
        turnL(speed); 
       
      } 
      else if (num2 == 1 & num4 == 0) // If white on the left and black on the right, turn right quickly 
      {   
                turnR(speed);   
      } 
      else if(num1==0 & num5==0 & num2==1  & num4==1) 
      { 
        cross(speed); 
      }   
      else // If all white, stop 
      {     
        forward(speed); 
      } 
    } 
  } 
} 


