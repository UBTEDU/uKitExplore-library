/* 
 * uKit Explore 2.0 
 * <Chapter 6> 
 * <Section 5> 
 * 6.5.1 Controlling an LED with a remote control 
 *  FFA25D    １
    FF629D    ２
    FFE21D    ３
    FF22DD    ４
    FF02FD    ５
    FFC23D    ６
    FFE01F    ７
    FFA857    ８
    FF906F    ９
 */
#include"uKitExplore2En.h" 
#include "IRremote/IRremote.h" 
 
long ir_item; 
int ledPin=9; 
int recvPin=37; 
IRrecv irrecv(recvPin); 
decode_results results; 
 
long KEY_1=0xFF30CF; 
long KEY_2=0xFF18E7; 
long KEY_3=0xFF7A85; 
long KEY_4=0xFF10EF; 
long KEY_5=0xFF38C7; 
long KEY_LONGkey=0xFFFFFFFF; 
long longkey=-1; 
void setup() { 
  pinMode(ledPin,OUTPUT); 
    Initialization(); 
   irrecv.enableIRIn();  
} 
void loop() { 
  if (irrecv.decode(&results)) { 
    Serial.println(results.value, HEX);//Output the receiving code using line breaks in hexadecimal 
    Serial.println();//Add a blank row in order to make it easy to view the output 
        irrecv.resume(); // Receive the next value 
  } 
 
  //The event of pressing key 1 
  if (results.value == KEY_1 ) { 
    ledOn(ledPin); 
    longkey = KEY_1; 
  } 
  //The event of pressing and holding key 1 
  if ( results.value == KEY_LONGkey && longkey == KEY_1) { 
    ledOn(ledPin); 
  } 
 
  //The event of pressing key 2 
  if (results.value == KEY_2 ) { 
    ledOff(ledPin); 
    longkey = KEY_2; 
  } 
  //The event of pressing and holding key 2 
  if ( results.value == KEY_LONGkey && longkey == KEY_2) { 
    ledOff(ledPin); 
  } 
  //The event of pressing key 3 
  if (results.value == KEY_3 ) { 
    flash(ledPin, 100, 100); 
    longkey = KEY_3; 
  } 
  //The event of pressing and holding key 3 
  if ( results.value == KEY_LONGkey && longkey == KEY_3) { 
    flash(ledPin, 100, 100); 
  } 
  //The event of pressing key 4 
  if (results.value == KEY_4 ) { 
    fadeOn(1000, 5); 
    fadeOff(1000, 5); 
        longkey = KEY_4; 
  } 
  //The event of pressing and holding key 4 
  if ( results.value == KEY_LONGkey && longkey == KEY_4) { 
    fadeOn(1000, 5); 
    fadeOff(1000, 5); 
  } 
} 
// Turn the LED on 
void ledOn(int ledPin) { 
  digitalWrite(ledPin, HIGH); 
} 
// Turn the LED off 
void ledOff(int ledPin) { 
  digitalWrite(ledPin, LOW); 
} 
//LED flashes 
void flash(int ledPin, long highDuration, long lowDuration) { 
  digitalWrite(ledPin, HIGH); 
  delay(highDuration); 
  digitalWrite(ledPin, LOW); 
  delay(lowDuration); 
} 
//The breathing light is on 
void fadeOn(unsigned int time, int increament) { 
  for (byte value = 0 ; value < 255; value += increament) { 
    Serial.println(value); 
    analogWrite(ledPin, value); 
    delay(time / (255 / 5)); 
  } 
} 
//The breathing light is off 
void fadeOff(unsigned int time, int decreament) { 
  for (byte value = 255; value > 0; value -= decreament) { 
    Serial.println(value); 
      analogWrite(ledPin, value); 
    delay(time / (255 / 5)); 
  } 
} 
