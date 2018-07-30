#include"uKitExplore.h"

String bufs;

void setup()
{
Serial.begin(115200);
}

void loop() {
 
  bufs= "{\"data\":\
 [0x01,255,0,0,\
 0x02,255,0,0,\         
 0x04,255,0,0,\    
 0x08,255,0,0,\    
 0x10,255,0,0,\    
 0x20,255,0,0,\   
 0x40,255,0,0,\    
 0x80,255,0,0]}";  
 
setEyelightPetals(1,8,bufs,2);


     

}
double getAverage(int arr[], int size)
{
  int    i, sum = 0;       
  double avg;          

  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
   }

  avg = double(sum) / size;

  return avg;
}
