


#include"Port.h"

void Port::Initialization(){
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
  pinMode(A3, INPUT);    // 定义超声波输入脚
  pinMode(A2, OUTPUT);   // 定义超声波输出脚 
  pinMode(A1, INPUT);    // 定义超声波输入脚
  pinMode(A0, OUTPUT);   // 定义超声波输出脚 
  pinMode(buzzer_pin,OUTPUT);
  delay(10);  //开机延时
  check_servo();  //获取舵机个数,列表
  delay(20);
  unsigned char aa[4]={0xFF,0,0,0};
  TXD(0xFA,8,4,0x01,aa);
  delay(5); 
  TXD(0xFA,13,4,0x01,aa); 
  delay(5); 
  
}

