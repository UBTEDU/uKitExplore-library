/* 
 * UKIT Advanced  
 * <Circuitry> 
 * LED Matrix 1
 */  

int pin9=7; //Connect LED pin 9 to pin D7 of the uKit Explore 
int pin13=6;// Connect LED pin 13 to pin D6 of the uKit Explore 
void setup() { 
// put your setup code here, to run once: 
    pinMode(pin9,OUTPUT); 
    pinMode(pin13,OUTPUT); 
    digitalWrite(pin9,HIGH); 
    digitalWrite(pin13,HIGH); 
} 
void loop() { 
// put your main code here, to run repeatedly: 
    digitalWrite(pin13,LOW);//Pin 13 is low level, and the LED goes on 
    delay(200); 
    digitalWrite(pin13,HIGH);//Pin 13 is high level, and the LED is high level at both ends, has no current, and goes out. 
    delay(200); 
}
