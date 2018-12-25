/* 
 * uKit Explore 2.0 
 * <Chapter 4> 
 * <Section 1> 
 * 4.1 Applications of Serial Ports 
 */  
 
void setup() { 
Serial.begin(115200);//Set baud rate 
} 
void loop() 
{ 
static unsigned long i = 0; //Create the variable i=0 
Serial.println(i++); //Add 1 to the Print function each time 
delay(1000);//Delay 1000 ms 
} 
 
