#include"uKitExplore.h"

String bufs;

void setup()
{
Serial.begin(115200);
}

void loop() {



 Serial.println(readHumitureValue(1,'C'));
 delay(300);
     

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

