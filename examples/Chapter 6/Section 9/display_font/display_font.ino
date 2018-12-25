/* 
 * uKit Explore 2.0 
 * <Chapter 6> 
 * <Section 9> 
 * 6.9.3 The 8*8 dot matrix displays letters and patterns 
 */ 
 
int R[]={2,8,A0,6,11,A1,12,A3};//Row 
int C[]={7,A5,A4,4,A2,5,9,10};//Column  
 
int heart[8][8] = {//Solid heart shape; LED is lit up at 1 
  {0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 1, 1, 0, 0, 1, 1, 0}, 
  {1, 1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 1, 1, 1, 1}, 
  {1, 1, 1, 1, 1, 1, 1, 1}, 
  {0, 1, 1, 1, 1, 1, 1, 0}, 
  {0, 0, 1, 1, 1, 1, 0, 0}, 
  {0, 0, 0, 1, 1, 0, 0, 0} 
}; 
 
int led_I[8][8] = {//Letter I; LED is lit up at 1 
  {0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 1, 1, 0, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0} 
}; 
 
int led_U[8][8] = {//Letter U; LED is lit up at 1 
  {0, 0, 0, 0, 0, 0, 0, 0}, 
  {0, 1, 1, 0, 0, 1, 1, 0}, 
  {0, 1, 1, 0, 0, 1, 1, 0}, 
  {0, 1, 1, 0, 0, 1, 1, 0}, 
  {0, 1, 1, 0, 0, 1, 1, 0}, 
  {0, 1, 1, 1, 1, 1, 1, 0}, 
  {0, 0, 1, 1, 1, 1, 0, 0}, 
  {0, 0, 0, 0, 0, 0, 0, 0} 
}; 
 
void setup() { 
    for(int i = 0;i< 8;i++) 
    { 
        pinMode(R[i],OUTPUT); 
        pinMode(C[i],OUTPUT); 
      }  
  // Serial.begin(9600); 
} 
 
void loop() { 
//    myDisplay(heart); 
     for(int i = 0 ; i < 100 ; i++)        //Display for 100 times in cycle   
      {   
        myDisplay(led_I);                   //Display the letter "I"   
      }   
      for(int i = 0 ; i < 100 ; i++)         //Display for 100 times in cycle   
      {      
        myDisplay(heart);                 //Display a heart shape 
      }  
      for(int i = 0 ; i < 100 ; i++)         //Display for 100 times in cycle   
      {      
        myDisplay(led_U);                 //Display the letter "U" 
      }   
} 
 
//Custom function 
//Display the function   
void myDisplay(int Led[8][8])    
{   
  for(int c = 0; c<8;c++)   
  {   
    digitalWrite(C[c],LOW);//Gate column c   
    //Loop   
    for(int r = 0;r<8;r++)   
    {   
      digitalWrite(R[r],Led[r][c]);   
    }   
    delay(1);   
    Clear();  //Clear the display 
  }   
}   
 
//Clear the display   
void Clear()                           
{   
  for(int i = 0;i<8;i++)   
  {   
    digitalWrite(R[i],LOW);   
    digitalWrite(C[i],HIGH);   
  }   
}   
