
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
void Sensor::IR_Send38KHZ(char pin,int x,int y){
  for(int i=0;i<x;i++){ //15=386US
    if(y==1){
      digitalWrite(pin,1);
      delayMicroseconds(9);
      digitalWrite(pin,0);
      delayMicroseconds(9);
      }
    else{
      digitalWrite(pin,0);
      delayMicroseconds(20);
      }            
    } 
}
void Sensor::IR_Sendcode(char pin,uint8_t x){
  for(int i=0;i<8;i++){
    if((x&0x01)==0x01){
      IR_Send38KHZ(pin,23,1);
      IR_Send38KHZ(pin,64,0);             
    }
    else{
      IR_Send38KHZ(pin,23,1);
      IR_Send38KHZ(pin,21,0);  
    }
      x=x>>1;
  }  
}
void Sensor::IR_Sendcode16(char pin,uint16_t x){
  for(int i=0;i<16;i++)
  {
    if((x&0x000001)==0x000001)
    {
      IR_Send38KHZ(pin,23,1);
      IR_Send38KHZ(pin,64,0);             
    }
    else
    {
      IR_Send38KHZ(pin,23,1);
      IR_Send38KHZ(pin,21,0);  
    }
    x=x>>1;
  }    
}
void Sensor::IR_Send(char pin,uint8_t code){
  IR_Send38KHZ(pin,280,1);//发送9ms的起始码
  IR_Send38KHZ(pin,140,0);//发送4.5ms的结果码
  
  IR_Sendcode(pin,code);//用户ID
 // IR_Sendcode16(like);//用户匹配项目    
 // IR_Sendcode(0xFF);//用户ID
  
  IR_Send38KHZ(pin,21,1);//发送结束码
  delay(200);
}


void Sensor::getGrayAllValue(){
  num1 = digitalRead(GrayscaleNum1);
  num2 = digitalRead(GrayscaleNum2);
  num3 = digitalRead(GrayscaleNum3);
  num4 = digitalRead(GrayscaleNum4);
  num5 = digitalRead(GrayscaleNum5);
}
int Sensor::readGrayValue(char num,char grayval){//0深，1浅
  int GrayscaleVal=0;
  if(num==1)
    GrayscaleVal=digitalRead(GrayscaleNum1);
  else if(num==2)
    GrayscaleVal=digitalRead(GrayscaleNum2);
  else if(num==3)
    GrayscaleVal=digitalRead(GrayscaleNum3);
  else if(num==4)
    GrayscaleVal=digitalRead(GrayscaleNum4);
  else if(num==5)
    GrayscaleVal=digitalRead(GrayscaleNum5);//黑0，白1
 if(grayval==0 & GrayscaleVal==0)
    return 1;
 else if(grayval==1 & GrayscaleVal==1)
    return 1;
 else
    return 0;

}
/**@brief EN:Color setting of board RGB LED/CN:板载RGB灯颜色设置.
 *
 * @param[in] red EN:Red value/CN:红色值.
 * @param[in] green EN:green value/CN:绿色值.
 * @param[in] blue EN:blue value/CN:蓝色值.
 *
 */
void Sensor::setRgbledColor(int red, int green, int blue){
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
      break;
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

float Sensor::readBatteryVoltage(){
  float voltage;
  voltage=(analogRead(A4)*5.0/1024.0)*151.0/51.0;
  return voltage;
 }


 float Sensor::readHcsr04Distance(char jp){
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
  float Sensor::readHcsr04Distance(char EchoPin,char TrigPin){
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
 void Sensor::Initialization(){
  delay(100);
  Serial.begin(115200);//EN:Initialize the serial port (baud rate 115200)/CN:初始化串口（波特率115200）
  pinMode(redPin, OUTPUT); //EN:Main board RGB lamp, R interface set to output/CN:主板RGB灯，R接口设置为输出.
  pinMode(greenPin, OUTPUT);//EN:Main board RGB lamp, G interface set to output/CN:主板RGB灯，G接口设置为输出.
  pinMode(bluePin, OUTPUT);//EN:Main board RGB lamp, B interface set to output/CN:主板RGB灯，B接口设置为输出.
  digitalWrite(redPin,HIGH);//EN:Main board RGB lamp, R interface set to HIGH/CN:主板RGB灯，R接口设置为高电平输出.
  digitalWrite(greenPin,HIGH);//EN:Main board RGB lamp, G interface set to HIGH/CN:主板RGB灯，G接口设置为高电平输出.
  digitalWrite(bluePin,HIGH);//EN:Main board RGB lamp, B interface set to HIGH/CN:主板RGB灯，B接口设置为高电平输出.
  pinMode(Button_pin,INPUT);
  pinMode(GrayscaleNum1, INPUT);  //左1的循迹传感器
  pinMode(GrayscaleNum2, INPUT);  //左2的循迹传感器
  pinMode(GrayscaleNum3, INPUT);  //中间的循迹传感器
  pinMode(GrayscaleNum4, INPUT);  //右2的循迹传感器
  pinMode(GrayscaleNum5, INPUT);  //右1的循迹传感器
  pinMode(IR_S,OUTPUT);
//  pinMode(A3, INPUT);    // 定义超声波输入脚
//  pinMode(A2, OUTPUT);   // 定义超声波输出脚 
//  pinMode(A1, INPUT);    // 定义超声波输入脚
//  pinMode(A0, OUTPUT);   // 定义超声波输出脚 
  pinMode(buzzer_pin,OUTPUT);
  delay(10);  //开机延时
  //check_servo();  //获取舵机个数,列表
  setAllSensorOff();
  setMotorStop(0xff);
  StopServo();
  getDeciveId2();
  
  
}


