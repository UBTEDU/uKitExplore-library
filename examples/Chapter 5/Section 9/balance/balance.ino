/* 
 * uKit Explore 2.0 
 * <Chapter 5> 
 * <Section 9> 
 * 5.9.2 Self-balancing scooter 
 */ 
 
//Original 6050 data + double speed code disk 
 
#include"uKitExplore2.h" 
//Custom variable 
char val='z'; //Adjust and control the command word 
int Speed_need = 0, Turn_need = 0; //Motion speed, turning speed 
float speeds, speeds_filter, positions; //Speed, speed filtering, position 
float diff_speeds; //Speed difference 
int text_time = 0, spcount = 0; //Test time, times of speed measurement 
#define Gry_offset -20     // Gyroscope offset 
#define Gyr_Gain 0.00763358    //The corresponding 1G 
float omega; 
uint32_t timer; 
//PID parameter 
double Output = 0; //PID output 
float Kp=68.34 ,Kd=0,Ksp=0,Ksi=0,Kdsp=0; //Kp=jitter speed  Kd=jitter frequency 
// MPU6050 parameter 
MPU6050 accelgyro; 
int16_t ax, ay, az, gx, gy, gz; 
//Angle parameter 
float Gyro_y; //Temporarily store the data about the gyroscope at axis Y 
float Angle_ax; //The angle of inclination calculated from the acceleration 
float Angle; //The final tilt angle of the car calculated by the first order complementary filter 
float Angle0 = -6.22; //Angle of mechanical balance is -6.23 
 
 
//Motor output 
int PWM_right = 0, PWM_left = 0; 
int PWM_left_least = 0, PWM_right_least =0; //Compensation of 50 for the startup of left and right motors 
 
 
//The speed measurement code disk interrupts 
int count_right = 0; 
int count_left = 0; 
 
 
 
//Motor output 
void SetMotorVoltage(int nLeftVol, int nRightVol) { 
if(nLeftVol > 140) nLeftVol = 140; //Prevent the PWM value from exceeding 255 
else if(nLeftVol<-140)nLeftVol = -140; 
if(nRightVol > 140) nRightVol = 140; //Prevent the PWM value from exceeding 255 
else if(nRightVol<-140)nRightVol = -140; 
  setMotorTurn(1,nLeftVol); 
  setMotorTurn(2,-nRightVol); 
 
 
} 
 
//Calculate the car angle 
void Angle_Calcu(void) { 
  Angle_ax = (az - 711.9009)/238.2 ; //Eliminate the zero offset 1942, 16384*3.14/1.2*180//Radians converted to degrees,711.9009 
      
  Gyro_y = ((gy - 85.607)/16.4); //Remove the zero offset 119, 2000deg/s 16.4 LSB/(deg/s)250---131 85.607 
 
  Angle = 0.97 * (Angle + Gyro_y * 0.0005) + 0.03 * Angle_ax; 
 Serial.println(Angle); 
 
}  
 
void setup() { 
  Wire.begin(); 
  Serial.begin(115200);  
  accelgyro.initialize(); //Initialize the device 
  //Pin mode setting 
   //Interrupt settings 
 
} 
 
 
 
void loop() { 
  if (Serial.available() > 0) { 
    val = Serial.read(); 
    //Parameter adjustment 
    if(val == 'A') Kp += 0.1; 
    if(val == 'a') Kp -= 0.1; 
    if(val == 'B') Kd += 0.01; 
    if(val == 'b') Kd -= 0.01; 
    if(val == 'C') Ksp += 0.1; 
    if(val == 'c') Ksp -= 0.1; 
    if(val == 'D') Ksi += 0.01; 
    if(val == 'd') Ksi -= 0.01; 
    if(val == 'E') Angle0 += 0.1; 
    if(val == 'e') Angle0 -= 0.1;     
    if(val == 'F') PWM_left_least += 1; 
    if(val == 'f') PWM_left_least -= 1;  
    if(val == 'G') PWM_right_least += 1; 
    if(val == 'g') PWM_right_least -= 1; 
    //Parameter viewing 
    if(val == 'H') { 
      Serial.print(ax); Serial.print("\t"); //Used to measure zero offset 
      Serial.println(gy); //Used to measure zero offset 
    } 
    if(val == 'I') { 
      Serial.print(Angle0); Serial.print("\t"); 
      Serial.print(PWM_left_least); Serial.print("\t"); 
      Serial.print(PWM_right_least); Serial.print("\t"); 
      Serial.print(Kp); Serial.print("\t"); 
      Serial.print(Kd); Serial.print("\t"); 
      Serial.print(Ksp); Serial.print("\t"); 
      Serial.print(Ksi); Serial.print("\t"); 
            Serial.println(Kdsp); 
    } 
    if(val == 'J') { 
      Serial.print(Angle); Serial.print("\t"); 
      Serial.println(diff_speeds); 
    } 
    if(val == 'K') Kdsp += 1; 
    if(val == 'k') Kdsp -= 1;     
    //Car control 
    if(val == '1') { 
      Angle0 = -5.12; //Angle of mechanical balance //Forward 
      Turn_need = 0; 
    } 
    if(val == '2') { 
      Speed_need = -15; //Backwards 
      Turn_need = 0; 
    } 
    if(val == '3') { 
      Speed_need = 0; 
      Turn_need = 30; //Turn left 
    } 
    if(val == '4') { 
      Speed_need = 0; 
      Turn_need = -30; //Turn right 
    } 
    if(val == '5') { 
      Angle0 = -6.23; //Angle of mechanical balance; //Stop 
      Turn_need = 0; 
    } 
  } 
 
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); //Get the sensor raw value 
  Angle_Calcu(); //Calculate the angle 
  PWM_Calcu(); //PWM output calculation 
} 
 
void PWM_Calcu(void) { 
     
    
  if (abs(Angle)>45) { 
    SetMotorVoltage(0,0); //Angle is greater than 30 degrees, so the PWM output is stopped 
   
     
  }else { 
    //PWM output calculation 
    Output = Kp*(Angle - Angle0) + Kd*Gyro_y ; 
    if(Turn_need == 0){ 
      PWM_left = Output - Kdsp * diff_speeds; 
      PWM_right = Output + Kdsp * diff_speeds; 
    } 
    PWM_left = Output - Turn_need; 
    PWM_right = Output + Turn_need; 
    if(PWM_left >= 0) { 
      PWM_left += PWM_left_least; 
    }else { 
      PWM_left -= PWM_left_least; 
    } 
    if(PWM_right >= 0) { 
      PWM_right += PWM_right_least; 
    }else { 
      PWM_right -= PWM_right_least; 
    } 
    SetMotorVoltage(PWM_left, PWM_right); 
    //setNixieTube(2,Angle); 
     
  } 
} 

