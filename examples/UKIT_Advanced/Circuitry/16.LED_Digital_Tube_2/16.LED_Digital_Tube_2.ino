/* 
 * UKIT Advanced  
 * <Circuitry> 
 * LED Digital Tube 2
 * Number order: dp, g, f, e, d, c, b, a
 */  
 
#include"UKIT_Advance.h" 
 
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
 
 
unsigned long longPressed;//Define the long press 
unsigned long changeTime;//Define the time 
 
#define button_1 42  
#define button_2 41  
 
int SUM = 0;//Define the value of the variable 
int Flag_up = 1; 
int Flag_down = 1; 
int buttonPressd = 0; 
int light_time = 100;  
     
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
 
  pinMode(button_1,INPUT_PULLUP); 
  pinMode(button_2,INPUT_PULLUP);//Set button IO to pull-up input 
   
} 
 
void loop() 
{ 
if( ScanKeyUp() == 1) //When a key is pressed 
  { 
    SUM++; //SUM plus one 
    if(SUM>9999) SUM = 0; 
    }  
     if( ScanKeyDown() == 1) 
    { 
      SUM--; 
      if(SUM<0) 
      { 
        SUM = 9999; 
      } 
    } 
  if( ScanKeyUp() == 2 && (millis() - changeTime) > light_time )   //Increase by 1 every 100 milliseconds 
  { 
      SUM ++; 
      if(SUM>9999) SUM = 0; 
      changeTime = millis(); 
  } 
   
  if( ScanKeyDown() == 2 && (millis() - changeTime) > light_time )  //Decrease by 1 every 100 milliseconds 
 { 
   SUM --; 
   if(SUM<0) SUM = 9999; 
   changeTime = millis(); 
  } 
   
  Display(1,SUM/1000); //Display the thousandth value of SUM 
  delay(3); 
  Display(2,(SUM/100)%10); //Display the hundredth value of SUM 
  delay(3); 
  Display(3,(SUM/10)%10); //Display the tenth value of SUM 
  delay(3); 
  Display(4,SUM%10); //Display the one value of SUM 
  delay(3); 
 
} 
 
unsigned char ScanKeyUp() //Key press scanner; return the key value 
{ 
   if(Flag_up  && digitalRead(button_1) == LOW) //A key is pressed when it is in the "not pressed" state 
  { 
    Flag_up = 0; //Clear Flag_up 
    delay(20); //Eliminate jittering through delay 
    if(digitalRead(button_1) == LOW) //Key is pressed 
    { 
      longPressed = millis(); 
      return 1;         //Return the key value of 1 
    } 
  } 
   
  if(!Flag_up && digitalRead(button_1) == LOW && (millis() - longPressed) > 2000) return 2; 
  //&& means AND, indicating that both conditions must be met at the same time. 
  
  if(digitalRead(button_1) == HIGH)  Flag_up = 1; //Set Flag_up when the key is released 
  return 0; 
} 
  
unsigned char ScanKeyDown() 
{ 
 if(Flag_down  && digitalRead(button_2) == LOW) 
  { 
    Flag_down = 0; //Clear Flag_up 
    delay(20); //Eliminate jittering through delay 
    if(digitalRead(button_2) == LOW) //Key is pressed 
    { 
      longPressed = millis(); 
      return 1;         //Return the key value of 1 
    } 
  } 
   
  if(!Flag_down && digitalRead(button_2) == LOW && (millis() - longPressed) > 2000) return 2;   
  if(digitalRead(button_2) == HIGH)  Flag_down = 1; //Set Flag_up when the key is released 
  return 0;  
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
  //digitalWrite(LED_dp,LOW); 
 
 
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
//      if (SUM<=10) digitalWrite(COM4,LOW); 
//      else digitalWrite(COM4,LOW); 
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

