
#include"uKitMotor.h"  


unsigned long uKitMotor::setMotorTurn(uint8_t id, uint16_t pwmDuty){
  unsigned long tRet = 0;
  unsigned char buf[12];
  uint16_t speeds;
  speeds=pwmDuty*8;
  buf[0] = 0xFB;
  buf[1] = 0x03;
  buf[2] = 0x08;
  buf[3] = 0x06;
  buf[4] = id;
  buf[5] = 0x00;
  buf[6] = 0x0E;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = (speeds & 0xFF00) >> 8;
  buf[10] = speeds & 0x00FF;
  buf[11] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(12,buf);  
  return tRet;
}
/**@brief EN:Motor run at a target speed for a target time/CN:电机以目标速度为目标时间运行.
 *
 * @param[in] id EN:Motor module id/CN:电机ID号.
 * @param[in] speed EN:Target speed(Range -120~120)/CN:电机目标速度(范围 -120~120).
 * @param[in] time EN:Target time/CN:电机运动时间.
 *
 * @returns ret EN:0 means motor module acks correct, <0 means no ack or ack error/CN:返回0表示功能正常.
 */
unsigned long uKitMotor::setMotorTurnAdj(uint8_t id, uint16_t speed, uint16_t time){
  unsigned long tRet = 0;
  unsigned char buf[16];
  
  buf[0] = 0xFB;  //填充协议头
  buf[1] = 0x03;
  buf[2] = 0x0c;
  buf[3] = 0x06;
  buf[4] = id;
  buf[5] = 0x00;
  buf[6] = 0x04;
  buf[7] = 0x00;
  buf[8] = 0x03;
  buf[9] = (speed & 0xFF00) >> 8;
  buf[10] = speed & 0x00FF;
  buf[11] = (time & 0xFF00) >> 8;
  buf[12] = time & 0x00FF;
  buf[13] = 0x00;
  buf[14] = 0x01;
  buf[15] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(16,buf);  
  return tRet;
}
/**@brief Read motor speed.
 *
 * @param[in] id EN:Motor module id/EN:电机ID号.
 *
 * @returns pSpeed EN:Motor speed/EN:电机速度..
 */
uint16_t uKitMotor::readMotorSpeed(uint8_t id){
  unsigned long tRet = 0;
  unsigned char buf[10];
  
  buf[0] = 0xFB;
  buf[1] = 0x03;
  buf[2] = 0x06;
  buf[3] = 0x05;
  buf[4] = id;
  buf[5] = 0x00;
  buf[6] = 0x07;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(10,buf);
  return tRet;
}
/**@brief EN:Motor stop/CN:电机停止.
 *
 * @param[in] id EN:Motor module id/CN:电机ID号.
 *
 * @returns tRet EN:0 means motor module acks correct, <0 means no ack or ack error/CN:返回0表示功能正常.
 */
int uKitMotor::setMotorStop(uint8_t id)
{
  unsigned long tRet = 0;
  unsigned char buf[12];
  
  buf[0] = 0xFB;
  buf[1] = 0x03;
  buf[2] = 0x08;
  buf[3] = 0x06;
  buf[4] = id;
  buf[5] = 0x00;
  buf[6] = 0x06;
  buf[7] = 0x00;
  buf[8] = 0x01;
  buf[9] = 0x00;
  buf[10] = 0x00;
  buf[11] = crc8_itu(&buf[1], buf[2]+2);
  tRet=TXD(12,buf);
  return tRet;
}
/**@brief EN:Set motor module ID/CN:设置电机ID号.
 *
 * @param[in] id_old EN:Old target motor module id/CN:旧的舵机号.
 * @param[in] id_new EN:New target motor module id/CN:新的舵机号.
 *
 * @returns tRet EN:0 means motor module acks correct, <0 means no ack or ack error/CN:返回0表示功能正常..
 */
void uKitMotor::StopServo()
{
  unsigned char aa[4]={0xFF,0,0,0};
  TXD(0xFA,0,4,0x01,aa); 
}


