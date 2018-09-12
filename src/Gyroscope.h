#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <Arduino.h>
#include "Wire.h"
#include "I2Cdev/I2Cdev.h"
#include "MPU6050.h"

class Gyroscope:MPU6050
{
public:
	float *getMpu6050Data();


  
	//MPU6050
	unsigned long now, lastTime = 0;
	float dt;                                   //微分时间

	int16_t ax, ay, az, gx, gy, gz;             //加速度计陀螺仪原始数据
	float aax=0, aay=0,aaz=0, agx=0, agy=0, agz=0;    //角度变量
	long axo = 0, ayo = 0, azo = 0;             //加速度计偏移量
	long gxo = 0, gyo = 0, gzo = 0;             //陀螺仪偏移量

	float pi = 3.1415926;
	float AcceRatio = 16384.0;                  //加速度计比例系数
	float GyroRatio = 131.0;                    //陀螺仪比例系数

	uint8_t n_sample = 8;                       //加速度计滤波算法采样个数
	float aaxs[8] = {0}, aays[8] = {0}, aazs[8] = {0};         //x,y轴采样队列
	long aax_sum, aay_sum,aaz_sum;                      //x,y轴采样和

	float a_x[10]={0}, a_y[10]={0},a_z[10]={0} ,g_x[10]={0} ,g_y[10]={0},g_z[10]={0}; //加速度计协方差计算队列
	float Px=1, Rx, Kx, Sx, Vx, Qx;             //x轴卡尔曼变量
	float Py=1, Ry, Ky, Sy, Vy, Qy;             //y轴卡尔曼变量
	float Pz=1, Rz, Kz, Sz, Vz, Qz;             //z轴卡尔曼变量

};
#endif
