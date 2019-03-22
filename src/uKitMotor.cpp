
#include"uKitMotor.h"  


unsigned char uKitMotor::setMotorTurn(uint8_t id, uint16_t pwmDuty){
  unsigned char tRet = 0;
  unsigned char buf[7];
  uint16_t speeds;
  speeds=pwmDuty*8;

  buf[0] = id;
  buf[1] = 0x00;
  buf[2] = 0x0E;
  buf[3] = 0x00;
  buf[4] = 0x01;
  buf[5] = (speeds & 0xFF00) >> 8;
  buf[6] = speeds & 0x00FF;

  tRet=ubtMotorProtocol(0x0C,0x06,buf);
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
unsigned char uKitMotor::setMotorTurnAdj(uint8_t id, uint16_t speed, uint16_t time){
  unsigned char tRet = 0;
  unsigned char buf[11];  
  buf[0] = id;
  buf[1] = 0x00;
  buf[2] = 0x04;
  buf[3] = 0x00;
  buf[4] = 0x03;
  buf[5] = (speed & 0xFF00) >> 8;
  buf[6] = speed & 0x00FF;
  buf[7] = (time & 0xFF00) >> 8;
  buf[8] = time & 0x00FF;
  buf[9] = 0x00;
  buf[10] = 0x01;
  tRet=ubtMotorProtocol(0x10,0x06,buf);
  return tRet;
}
/**@brief Read motor speed.
 *
 * @param[in] id EN:Motor module id/EN:电机ID号.
 *
 * @returns pSpeed EN:Motor speed/EN:电机速度..
 */
short uKitMotor::readMotorSpeed(uint8_t id){
  short tRet = 0;
  unsigned char buf[5];

  buf[0] = id;
  buf[1] = 0x00;
  buf[2] = 0x07;
  buf[3] = 0x00;
  buf[4] = 0x01;
 
  tRet=ubtMotorProtocol(0x0A,0x05,buf);
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
  unsigned char buf[7];
  

  buf[0] = id;
  buf[1] = 0x00;
  buf[2] = 0x06;
  buf[3] = 0x00;
  buf[4] = 0x01;
  buf[5] = 0x00;
  buf[6] = 0x00;
 
  tRet=ubtMotorProtocol(0x0C,0x06,buf);
  return tRet;
}
void uKitMotor::clearMotorInf(unsigned char id){
  unsigned char buf[7];  
  buf[0] = id;
  buf[1] = 0x00;
  buf[2] = 0x0F;
  buf[3] = 0x00;
  buf[4] = 0x01;
  buf[5] = 0xff;
  buf[6] = 0xff;
  ubtMotorProtocol(0x0C,0x06,buf);
 
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
  unsigned char buf[4]={0xFF,0,0,0};
  //TXD(0xFA,0,4,0x01,aa); 
  ubtServoProtocol(0xFA,0x00,0x01,buf);
}
