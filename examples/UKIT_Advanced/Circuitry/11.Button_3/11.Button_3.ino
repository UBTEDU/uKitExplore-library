/* 
 * UKIT Advanced  
 * <Circuitry> 
 * Button 3
 */  
 
int pinBuzzer = 6; //Pin D6 is connected to the signal pin of the buzzer module   
int button=7; 
int val; 
void setup()   
{   
  pinMode(pinBuzzer,OUTPUT);   
  pinMode(button,INPUT); 
}   
    
void loop()   
{   
  val=digitalRead(button); 
  if(val==LOW) 
  { 
    noTone(pinBuzzer); 
  } 
  else 
  { 
  for(int i=200;i<=800;i++)     //Use a loop to increase the frequency from 200 Hz to 800 Hz   
  {   
    tone(pinBuzzer,i);             //Port output frequency   
    delay(5);                     //Last for 5 milliseconds at the frequency      
  }   
    delay(4000);                    //Last for 4 seconds at the highest frequency   
    for(int i=800;i>=200;i--)   
  {   
    tone(pinBuzzer,i);   
    delay(10);   
  }   
 } 
} 


