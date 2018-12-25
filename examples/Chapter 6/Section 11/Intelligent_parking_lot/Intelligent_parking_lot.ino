/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 11> 
 * 5.11.1 Smart parking lot 
 * Number order: dp, g, f, e, d, c, b, a 
 */ 
#include"uKitExplore2En.h" 
 
#define  LED_A 7    //Define the pin 
#define  LED_B 8    //Define the pin 
#define  LED_C 9    //Define the pin 
#define  LED_D 10     //Define the pin 
#define  LED_E 11    //Define the pin 
#define  LED_F 12    //Define the pin 
#define  LED_G A1    //Define the pin 
#define  LED_dp A2    //Define the pin      
  
#define COM1 2    //Define the pin 
#define COM2 4    //Define the pin 
#define COM3 5    //Define the pin 
#define COM4 6    //Define the pin     
int dis=0,dis2=0; 
int SUM = 200;//Define the value of the variable 
 
 
unsigned char Number[11][8] =                 
{ 
  {0, 0,  1,  1,  1,  1,  1,  1},     //0 
  {0, 0,  0,  0,  0,  1,  1,  0},     //1 
  {0, 1,  0,  1,  1,  0,  1,  1},     //2 
  {0, 1,  0,  0,  1,  1,  1,  1},     //3 
  {0, 1,  1,  0,  0,  1,  1,  0},     //4 
  {0, 1,  1,  0,  1,  1,  0,  1},     //5 
  {0, 1,  1,  1,  1,  1,  0,  1},     //6 
  {0, 0,  0,  0,  0,  1,  1,  1},     //7 
  {0, 1,  1,  1,  1,  1,  1,  1},     //8 
  {0, 1,  1,  0,  1,  1,  1,  1},     //9 
  {1, 0,  0,  0,  0,  0,  0,  0}      //10 decimal point 
}; 
 
 
 
void setup() 
{ 
  Initialization(); 
  pinMode(LED_A,OUTPUT);    //Set as the output pin 
  pinMode(LED_B,OUTPUT); 
  pinMode(LED_C,OUTPUT); 
  pinMode(LED_D,OUTPUT); 
  pinMode(LED_E,OUTPUT); 
  pinMode(LED_F,OUTPUT); 
  pinMode(LED_G,OUTPUT); 
  pinMode(LED_dp,OUTPUT); 
 
  pinMode(COM1,OUTPUT); 
  pinMode(COM2,OUTPUT); 
  pinMode(COM3,OUTPUT); 
  pinMode(COM4,OUTPUT); 
} 
 
 
void getData(){ 
  dis=readUltrasonicDistance(1); 
  dis2=readInfraredDistance(1); 
} 
void loop() 
{ 
 
 
  getData(); 
  
  if(dis2<17) 
  { 
    setServoAngle(2,0,400);//Raise the lifting lever 
    for(int i=0;i<30;i++){ 
      Display(1,SUM/1000); //Display the thousandth value of SUM 
      delay(3); 
      Display(2,(SUM/100)%10); //Display the hundredth value of SUM 
      delay(2); 
      Display(3,(SUM/10)%10); //Display the tenth value of SUM 
      delay(2); 
      Display(4,SUM%10); //Display the one value of SUM 
      delay(3);    
         
    } 
    while(dis2<17){ 
      for(int i=0;i<30;i++){ 
        Display(1,SUM/1000); //Display the thousandth value of SUM 
        delay(3); 
        Display(2,(SUM/100)%10); //Display the hundredth value of SUM 
        delay(2); 
        Display(3,(SUM/10)%10); //Display the tenth value of SUM 
        delay(2); 
        Display(4,SUM%10); //Display the one value of SUM 
        delay(3);       
    }   
      dis2=readInfraredDistance(1); 
    } 
    SUM--; //SUM minus one 
 
    if(SUM>9999) 
    { 
      SUM=9999; 
    } 
  }    
    else if  (dis!=0 && dis<10) 
    { 
    
    setServoAngle(1,90,400);//Raise the lifting lever 
    for(int i=0;i<30;i++){ 
      Display(1,SUM/1000); //Display the thousandth value of SUM 
      delay(3); 
      Display(2,(SUM/100)%10); //Display the hundredth value of SUM 
      delay(2); 
      Display(3,(SUM/10)%10); //Display the tenth value of SUM 
      delay(2); 
      Display(4,SUM%10); //Display the one value of SUM 
      delay(3);       
    } 
     while(dis>0  && dis<10){ 
      for(int i=0;i<30;i++){ 
        Display(1,SUM/1000); //Display the thousandth value of SUM 
        delay(3); 
        Display(2,(SUM/100)%10); //Display the hundredth value of SUM 
        delay(2); 
        Display(3,(SUM/10)%10); //Display the tenth value of SUM 
        delay(2); 
        Display(4,SUM%10); //Display the one value of SUM 
        delay(3);       
    }     
      dis=readUltrasonicDistance(1); 
 
    } 
     SUM++; 
     if(SUM<0) 
     { 
      SUM=0; 
     } 
  } 
 
    
  
  setServoAngle(2,-90,400);//Lower the lifting lever 
   setServoAngle(1,0,400);//Lower the lifting lever 
  for(int i=0;i<30;i++){ 
    Display(1,SUM/1000); //Display the thousandth value of SUM 
    delay(6); 
    Display(2,(SUM/100)%10); //Display the hundredth value of SUM 
    delay(6); 
    Display(3,(SUM/10)%10); //Display the tenth value of SUM 
    delay(6); 
    Display(4,SUM%10); //Display the one value of SUM 
    delay(6);       
  } 
 
} 
 
 
 
 
void Display(unsigned char com,unsigned char num) 
{ 
  digitalWrite(LED_A,LOW);       
  digitalWrite(LED_B,LOW); 
  digitalWrite(LED_C,LOW); 
  digitalWrite(LED_D,LOW); 
  digitalWrite(LED_E,LOW); 
  digitalWrite(LED_F,LOW); 
  digitalWrite(LED_G,LOW); 
 
  switch(com)           //Position selection 
  { 
    case 1: 
      //digitalWrite(COM1,LOW);   //Select bit 1 
      digitalWrite(COM2,HIGH); 
      digitalWrite(COM3,HIGH); 
      digitalWrite(COM4,HIGH); 
      if (SUM<1000) digitalWrite(COM1,HIGH); 
      else digitalWrite(COM1,LOW);   //Mask out the high bits 
      break; 
    case 2: 
      digitalWrite(COM1,HIGH); 
      //digitalWrite(COM2,LOW);   //Select bit 2 
      digitalWrite(COM3,HIGH); 
     digitalWrite(COM4,HIGH); 
      if (SUM<100) digitalWrite(COM2,HIGH); 
      else digitalWrite(COM2,LOW); 
      break; 
    case 3: 
      digitalWrite(COM1,HIGH); 
      digitalWrite(COM2,HIGH); 
      //digitalWrite(COM3,LOW);   //Select bit 3 
      digitalWrite(COM4,HIGH); 
      if (SUM<10) digitalWrite(COM3,HIGH); 
      else digitalWrite(COM3,LOW); 
      break; 
    case 4: 
      digitalWrite(COM1,HIGH); 
      digitalWrite(COM2,HIGH); 
      digitalWrite(COM3,HIGH); 
      digitalWrite(COM4,LOW);   //Select bit 4 
      break; 
    case 5: 
      digitalWrite(COM1,LOW);   //Select the first point 
      digitalWrite(LED_dp,LOW); 
      digitalWrite(COM2,HIGH); 
      digitalWrite(COM3,HIGH); 
      digitalWrite(COM4,HIGH); 
      break; 
     case 6: 
      digitalWrite(COM1,HIGH);   //Select the second point 
      digitalWrite(COM2,LOW); 
      digitalWrite(LED_dp,LOW); 
      digitalWrite(COM3,HIGH); 
      digitalWrite(COM4,HIGH); 
      break; 
      case 7: 
      digitalWrite(COM1,HIGH);   //Select the third point 
      digitalWrite(COM2,HIGH); 
      digitalWrite(COM3,LOW); 
      digitalWrite(LED_dp,LOW); 
      digitalWrite(COM4,HIGH); 
      break; 
      case 8: 
      digitalWrite(COM1,HIGH);   //Select the fourth point 
      digitalWrite(COM2,HIGH); 
      digitalWrite(COM3,HIGH); 
      digitalWrite(COM4,LOW); 
      digitalWrite(LED_dp,LOW); 
      break; 
    default:break; 
  } 
 
  digitalWrite(LED_A,Number[num][7]);      //Query the code value table 
  digitalWrite(LED_B,Number[num][6]); 
  digitalWrite(LED_C,Number[num][5]); 
  digitalWrite(LED_D,Number[num][4]); 
  digitalWrite(LED_E,Number[num][3]); 
  digitalWrite(LED_F,Number[num][2]); 
  digitalWrite(LED_G,Number[num][1]); 
 // digitalWrite(LED_dp,Number[num][0]); 
} 
