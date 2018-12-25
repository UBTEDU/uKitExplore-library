/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 3> 
 * 5.3.3 Dwarf 
 */


/*
 * Create action 
 * Custom name 1: Zero (name of the run in loop) 
 * Custom name 2: Zeros (number of frames running, angle name) 
 * Custom name 3: Zero_time (the length of each frame run) 
 */

 
#include"uKitExplore2En.h"
const signed char id[4]={1,2,3,4};//[Define the number of IDs]={Enter the corresponding servo number}; 

const signed char Zeros[3][4]={{1,0,-1,-1},{-27,27,26,-20},{2,-2,-3,-3}};
// Custom name 2, [action frame number] [number of servos] = {{per frame angle}}; 
// Connect to the serial port to display the angle of each frame 

const int  Zero_time[3]={1000,600,700};
// Custom name 3, [action frame number] = {motion duration between frames}; 


void setup() 
{
   Initialization();
}

void loop() 
{
     button1.Update();
    if(button1.clicks == 1)
    {
        //readServoAnglePD_M(id,4);//Mask the servo angle 
        Zero(1);//Custom name 1, execute once
        delay(300);
        while(1);
     }
}


void Zero(char times)//void Custom name 1 
  {
        for(int c=0;c<times;c++)
    {
         for(int i=0;i<sizeof(Zeros)/sizeof(Zeros[0]);i++)//Enter the custom name 2 in parentheses to determine how many frames are in Zeros
         {
            for(int t=0;t<sizeof(id)/sizeof(id[0]);t++)
            {
                setServoAngle(id[t],(Zeros[i][t]),800);//Place custom name 2 into the parentheses and execute every frame 
            }  
          delay(Zero_time[i]);//Execute custom name 3 for Zero_time 
          }
    }
}

