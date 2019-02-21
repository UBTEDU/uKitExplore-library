#include"uKitExplore2.h"
//左右悬臂舵机的90度位置
#define SERVOFAKTORLEFT 60 
#define SERVOFAKTORRIGHT 60   //此参数650是理论中间位置，需要看实际情况调节
 
//左右悬臂舵机的 0或180度位置
#define SERVOLEFTNULL 0
#define SERVORIGHTNULL -15
 
//三只舵机的接口
#define SERVOPINLIFT  2
#define SERVOPINLEFT  4
#define SERVOPINRIGHT 5
 
//升举舵机的3个角度 
#define LIFT0 1080 // on drawing surface
#define LIFT1 925  // between numbers
#define LIFT2 725  // going towards sweeper
 
// 速度
#define LIFTSPEED 1500
 
// 悬臂的长度，根据图纸测量，无需改变
#define L1 35
#define L2 57.2
#define L3 14.2
 
 
// 左右舵机轴心的位置
#define O1X 23
#define O1Y -25
#define O2X 59
#define O2Y -25
 
 
 
#include <Time.h> // see http://playground.arduino.cc/Code/time 
#include <Servo.h>
 
int servoLift = 1500;
 
Servo servo1;  // 
Servo servo2;  // 
Servo servo3;  // 
 
volatile double lastX = 38;
volatile double lastY = 24;
 
int last_min = 0;
 
void setup() 
{ 
  // Set current time only the first to values, hh,mm are needed
//  setTime(19,38,0,0,0,0);
 Serial.begin(115200);
  drawTo(38, 24);
  lift(0);
  servo1.attach(SERVOPINLIFT);  //  lifting servo
  servo2.attach(SERVOPINLEFT);  //  left servo
  servo3.attach(SERVOPINRIGHT);  //  right servo
  delay(1000);
 
} 
 
void loop() 
{ 
 
 
 
//  // 移动左右悬臂，让两只悬臂分别停留在水平和垂直的位置上。 通过修改 SERVOFAKTORLEFT ， SERVOFAKTORRIGHT， SERVOLEFTNULL ， SERVORIGHTNULL 四个参数来微调
    button1.Update();
    if(button1.clicks == 1){
  drawTo(-3, 29.2);
  delay(500);
  drawTo(74.1, 28);
  delay(500);
    }
else if(button1.clicks == 2){
number(5, 25, 2, 1.2);
}
     if(button1.clicks == -1){
  drawTo(-3, 29.2);
  delay(500);
  drawTo(74.1, 28);
  delay(500);
    }
 
} 
 
// Writing numeral with bx by being the bottom left originpoint. Scale 1 equals a 20 mm high font.
// The structure follows this principle: move to first startpoint of the numeral, lift down, draw numeral, lift up
void number(float bx, float by, int num, float scale) {
 
  switch (num) {
 
  case 0:
    drawTo(bx + 12 * scale, by + 6 * scale);
    lift(0);
    bogenGZS(bx + 7 * scale, by + 10 * scale, 10 * scale, -0.8, 6.7, 0.5);
    lift(1);
    break;
  case 1:
 
    drawTo(bx + 3 * scale, by + 15 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    drawTo(bx + 10 * scale, by + 0 * scale);
    lift(1);
    break;
  case 2:
    drawTo(bx + 2 * scale, by + 12 * scale);
    lift(0);
    tone(600,300);
    delay(300);
    bogenUZS(bx + 8 * scale, by + 14 * scale, 6 * scale, 3, -0.8, 1);
    drawTo(bx + 1 * scale, by + 0 * scale);
    drawTo(bx + 12 * scale, by + 0 * scale);
    lift(1);
    break;
  case 3:
    drawTo(bx + 2 * scale, by + 17 * scale);
    lift(0);
    bogenUZS(bx + 5 * scale, by + 15 * scale, 5 * scale, 3, -2, 1);
    bogenUZS(bx + 5 * scale, by + 5 * scale, 5 * scale, 1.57, -3, 1);
    lift(1);
    break;
  case 4:
    drawTo(bx + 10 * scale, by + 0 * scale);
    lift(0);
    drawTo(bx + 10 * scale, by + 20 * scale);
    drawTo(bx + 2 * scale, by + 6 * scale);
    drawTo(bx + 12 * scale, by + 6 * scale);
    lift(1);
    break;
  case 5:
    drawTo(bx + 2 * scale, by + 5 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 6 * scale, 6 * scale, -2.5, 2, 1);
    drawTo(bx + 5 * scale, by + 20 * scale);
    drawTo(bx + 12 * scale, by + 20 * scale);
    lift(1);
    break;
  case 6:
    drawTo(bx + 2 * scale, by + 10 * scale);
    lift(0);
    bogenUZS(bx + 7 * scale, by + 6 * scale, 6 * scale, 2, -4.4, 1);
    drawTo(bx + 11 * scale, by + 20 * scale);
    lift(1);
    break;
  case 7:
    drawTo(bx + 2 * scale, by + 20 * scale);
    lift(0);
    drawTo(bx + 12 * scale, by + 20 * scale);
    drawTo(bx + 2 * scale, by + 0);
    lift(1);
    break;
  case 8:
    drawTo(bx + 5 * scale, by + 10 * scale);
    lift(0);
    bogenUZS(bx + 5 * scale, by + 15 * scale, 5 * scale, 4.7, -1.6, 1);
    bogenGZS(bx + 5 * scale, by + 5 * scale, 5 * scale, -4.7, 2, 1);
    lift(1);
    break;
 
  case 9:
    drawTo(bx + 9 * scale, by + 11 * scale);
    lift(0);
    bogenUZS(bx + 7 * scale, by + 15 * scale, 5 * scale, 4, -0.5, 1);
    drawTo(bx + 5 * scale, by + 0);
    lift(1);
    break;
 
  case 111:
 
    lift(0);
    drawTo(70, 46);
    drawTo(65, 43);
 
    drawTo(65, 49);
    drawTo(5, 49);
    drawTo(5, 45);
    drawTo(65, 45);
    drawTo(65, 40);
 
    drawTo(5, 40);
    drawTo(5, 35);
    drawTo(65, 35);
    drawTo(65, 30);
 
    drawTo(5, 30);
    drawTo(5, 25);
    drawTo(65, 25);
    drawTo(65, 20);
 
    drawTo(5, 20);
    drawTo(60, 44);
 
    drawTo(75.2, 47);
    lift(2);
 
    break;
 
  case 11:
    drawTo(bx + 5 * scale, by + 15 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 15 * scale, 0.1 * scale, 1, -1, 1);
    lift(1);
    drawTo(bx + 5 * scale, by + 5 * scale);
    lift(0);
    bogenGZS(bx + 5 * scale, by + 5 * scale, 0.1 * scale, 1, -1, 1);
    lift(1);
    break;
 
  }
}
 
 
 
void lift(char lift) {
  switch (lift) {
    // room to optimize  !
 
  case 0: //850
 
      if (servoLift >= LIFT0) {
      while (servoLift >= LIFT0) 
      {
        servoLift--;
        servo1.writeMicroseconds(servoLift);                                
        delayMicroseconds(LIFTSPEED);
      }
    } 
    else {
      while (servoLift <= LIFT0) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
 
      }
 
    }
 
    break;
 
  case 1: //150
 
    if (servoLift >= LIFT1) {
      while (servoLift >= LIFT1) {
        servoLift--;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
 
      }
    } 
    else {
      while (servoLift <= LIFT1) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
      }
 
    }
 
    break;
 
  case 2:
 
    if (servoLift >= LIFT2) {
      while (servoLift >= LIFT2) {
        servoLift--;
        servo1.writeMicroseconds(servoLift);
        delayMicroseconds(LIFTSPEED);
      }
    } 
    else {
      while (servoLift <= LIFT2) {
        servoLift++;
        servo1.writeMicroseconds(servoLift);                                
        delayMicroseconds(LIFTSPEED);
      }
    }
    break;
  }
}
 
 
void bogenUZS(float bx, float by, float radius, int start, int ende, float sqee) {
  float inkr = -0.05;
  float count = 0;
 
  do {
    drawTo(sqee * radius * cos(start + count) + bx,
    radius * sin(start + count) + by);
    count += inkr;
  } 
  while ((start + count) > ende);
 
}
 
void bogenGZS(float bx, float by, float radius, int start, int ende, float sqee) {
  float inkr = 0.05;
  float count = 0;
 
  do {
    drawTo(sqee * radius * cos(start + count) + bx,
    radius * sin(start + count) + by);
    count += inkr;
  } 
  while ((start + count) <= ende);
}
 
 
void drawTo(double pX, double pY) {
  double dx, dy, c;
  int i;
 
  // dx dy of new point
  dx = pX - lastX;
  dy = pY - lastY;
  //path lenght in mm, times 4 equals 4 steps per mm
  c = floor(4 * sqrt(dx * dx + dy * dy));
 
  if (c < 1) c = 1;
 
  for (i = 0; i <= c; i++) {
    // draw line point by point
    set_XY(lastX + (i * dx / c), lastY + (i * dy / c));
 
  }
 
  lastX = pX;
  lastY = pY;
}
 
double return_angle(double a, double b, double c) {
  // cosine rule for angle between c and a
  return acos((a * a + c * c - b * b) / (2 * a * c));
} 
 
void set_XY(double Tx, double Ty) 
{

  double dx, dy, c, a1, a2, Hx, Hy;
 
  // calculate triangle between pen, servoLeft and arm joint
  // cartesian dx/dy
  dx = Tx - O1X;
  dy = Ty - O1Y;
 
  // polar lemgth (c) and angle (a1)
  c = sqrt(dx * dx + dy * dy); // 
  a1 = atan2(dy, dx); //
  a2 = return_angle(L1, L2, c);
    setServoAngle(3,-floor(((a2 + a1 - M_PI) * SERVOFAKTORLEFT) + SERVOLEFTNULL),10);
    servo2.writeMicroseconds(floor(((a2 + a1 - M_PI) * SERVOFAKTORLEFT) + SERVOLEFTNULL));
   
  // calculate joinr arm point for triangle of the right servo arm
  a2 = return_angle(L2, L1, c);
  Hx = Tx + L3 * cos((a1 - a2 + 0.621) + M_PI); //36,5掳
  Hy = Ty + L3 * sin((a1 - a2 + 0.621) + M_PI);
 
  // calculate triangle between pen joint, servoRight and arm joint
  dx = Hx - O2X;
  dy = Hy - O2Y;
 
  c = sqrt(dx * dx + dy * dy);
  a1 = atan2(dy, dx);
  a2 = return_angle(L1, (L2 - L3), c);
 
   servo3.writeMicroseconds(floor(((a1 - a2) * SERVOFAKTORRIGHT) + SERVORIGHTNULL));
   Serial.println(floor(((a1 - a2) * SERVOFAKTORRIGHT) + SERVORIGHTNULL));
   setServoAngle(11,-floor(((a1 - a2) * SERVOFAKTORRIGHT) + SERVORIGHTNULL),10);

}
 
 
