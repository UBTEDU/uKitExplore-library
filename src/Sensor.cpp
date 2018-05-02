
#include"Sensor.h" 

void Sensor::tone(int pin, uint16_t frequency, uint32_t duration) 
{
  
  int period = 1000000L / frequency;
  int pulse = period / 2;
  pinMode(pin, OUTPUT);
  for (long i = 0; i < duration * 1000L; i += period) 
  {
    digitalWrite(buzzer_pin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(buzzer_pin, LOW);
    delayMicroseconds(pulse);
    
  }
}
void Sensor::tone(uint16_t frequency, uint32_t duration)
{
  int period = 1000000L / frequency;
  int pulse = period / 2;
  pinMode(buzzer_pin, OUTPUT);
  for (long i = 0; i < duration * 1000L; i += period) 
  {
    digitalWrite(buzzer_pin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(buzzer_pin, LOW);
    delayMicroseconds(pulse);
   
  }
}
void Sensor::noTone(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(buzzer_pin, LOW);
}
void Sensor::noTone()
{
  pinMode(buzzer_pin, OUTPUT);
  digitalWrite(buzzer_pin, LOW);
}
void Sensor::read_data(){
  num1 = digitalRead(GrayscaleNum1);
  num2 = digitalRead(GrayscaleNum2);
  num3 = digitalRead(GrayscaleNum3);
  num4 = digitalRead(GrayscaleNum4);
  num5 = digitalRead(GrayscaleNum5);
}
/**@brief EN:Color setting of board RGB LED/CN:板载RGB灯颜色设置.
 *
 * @param[in] red EN:Red value/CN:红色值.
 * @param[in] green EN:green value/CN:绿色值.
 * @param[in] blue EN:blue value/CN:蓝色值.
 *
 */
void Sensor::colorRGB(int red, int green, int blue){
  analogWrite(redPin,constrain((255-red),0,255));
  analogWrite(greenPin,constrain((255-green),0,255));
  analogWrite(bluePin,constrain((255-blue),0,255));
}
/**@brief EN:The presupposed color function of board RGB LED/CN:板载RGB灯预设颜色函数.
 *
 * @param[in] color EN:color selection/CN:颜色选择.
 *
 */
void Sensor::setcolor(int color){
  switch (color) {
    case 1://红
      analogWrite(redPin,0);
      analogWrite(greenPin,255);
      analogWrite(bluePin,255);
      break;
    case 2://绿
      analogWrite(redPin,255);
      analogWrite(greenPin,0);
      analogWrite(bluePin,255);
      break;
    case 3://蓝
      analogWrite(redPin,255);
      analogWrite(greenPin,255);
      analogWrite(bluePin,0);
    case 4://黄
      analogWrite(redPin,0);
      analogWrite(greenPin,0);
      analogWrite(bluePin,255);
      break;
    case 5://灭灯
      analogWrite(redPin,175);
      analogWrite(greenPin,255);
      analogWrite(bluePin,175);
      break;  
  }
}

float Sensor::Battery_check(){
  float voltage;
  voltage=(analogRead(A4)*5.0/1024.0)*151.0/51.0;
  return voltage;
 }


 float Sensor::HcSr04Dis(char jp){
  if(jp==1){
    Trig=A0;
    Echo=A1;
  }
  else{
    Trig=A2;
    Echo=A3;
  }
  digitalWrite(Trig, LOW);   // 给触发脚低电平2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  // 给触发脚高电平10μs，这里至少是10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    // 持续给触发脚低电
  float distance = pulseIn(Echo, HIGH)/58.00;  // 读取高电平时间(单位：微秒)
  delay(10);
  //为什么除以58等于厘米，  Y米=（X秒*344）/2
  // X秒=（ 2*Y米）/344 ==》X秒=0.0058*Y米 ==》厘米=微秒/58
  return distance;
 }
  float Sensor::HcSr04Dis(char EchoPin,char TrigPin){
  digitalWrite(TrigPin, LOW);   // 给触发脚低电平2μs
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);  // 给触发脚高电平10μs，这里至少是10μs
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);    // 持续给触发脚低电
  float distance = pulseIn(EchoPin, HIGH)/58.00;  // 读取高电平时间(单位：微秒)
  delay(10);
  //为什么除以58等于厘米，  Y米=（X秒*344）/2
  // X秒=（ 2*Y米）/344 ==》X秒=0.0058*Y米 ==》厘米=微秒/58
  return distance;
 }


