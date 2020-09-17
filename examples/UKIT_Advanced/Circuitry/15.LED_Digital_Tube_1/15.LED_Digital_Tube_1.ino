/* 
 * UKIT Advanced  
 * <Circuitry> 
 * LED Digital Tube 1
 * Number order: dp, g, f, e, d, c, b, a
 */  
 
#include"UKIT_Advance.h" 

#define  LED_A 7    
#define  LED_B 8    
#define  LED_C 9    
#define  LED_D 10     
#define  LED_E 11    
#define  LED_F 12    
#define  LED_G A1    
#define  LED_dp A2   
    
#define COM1 2    
#define COM2 4    
#define COM3 5    
#define COM4 6    
    
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
 
void loop() 
{ 
  Display(1,1);     //Bit 1 displays 1 
  delay(500); 
  Display(2,2);     //Bit 2 displays 2 
  delay(500); 
  Display(3,3);     //Bit 3 displays 3 
  delay(500); 
  Display(4,4);     //Bit 4 displays 4 
  delay(500); 
  Display(5,10);     //Display the 1st point 
  delay(500); 
  Display(6,10);     //Display the 2nd point 
  delay(500); 
  Display(7,10);     //Display the 3rd point 
  delay(500); 
  Display(8,10);     //Display the 4th point 
  delay(500); 
 
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
  digitalWrite(LED_dp,LOW); 
 
  switch(com)           //Position selection 
  { 
    case 1: 
      digitalWrite(COM1,LOW);   //Select bit 1 
      digitalWrite(COM2,HIGH); 
      digitalWrite(COM3,HIGH); 
      digitalWrite(COM4,HIGH); 
      break; 
    case 2: 
      digitalWrite(COM1,HIGH); 
      digitalWrite(COM2,LOW);   //Select bit 2 
      digitalWrite(COM3,HIGH); 
      digitalWrite(COM4,HIGH); 
      break; 
    case 3: 
      digitalWrite(COM1,HIGH); 
      digitalWrite(COM2,HIGH); 
      digitalWrite(COM3,LOW);   //Select bit 3 
      digitalWrite(COM4,HIGH); 
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
  digitalWrite(LED_dp,Number[num][0]); 
} 
