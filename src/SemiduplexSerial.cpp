
#include"SemiduplexSerial.h"  



/**@brief EN:JIMU Servo checksum/CN:JIMU舵机校验
 *
 * @param[in] len EN:Data length/CN：数据长度.
 * @param[in] len EN:Data buffer/CN:数据缓冲区.
 *
 * @returns sum EN: checksum value/CN:校验值.
 */
unsigned char SemiduplexSerial::Cheak_Sum(unsigned char len, unsigned char *buf){
  unsigned char i, sum = 0;
  
  if(len > 254) return 0;
  for(i = 0; i < len; i++)
  {
    sum += buf[i];
  }
  return  (uint8_t)(sum);
}

/**@brief EN:Communication protocol sending and receiving functions/CN:通讯协议发送和接受函数.
 *
 * @param[in] Head EN:Protocol head/CN:协议头.
 * @param[in] ServoNO EN:Servo id/CN:舵机号.
 * @param[in] len EN:data length/CN:数据长度.
 * @param[in] CMD EN:CMD code/CN:CMD码.
 * @param[in] Data EN:data buffer/CN:数据缓冲区.
 *
 * @returns tRet EN:Accept return value/CN:接受返回值.
 */
unsigned long SemiduplexSerial::TXD(unsigned char Head,unsigned char ServoNO,unsigned char len,unsigned char CMD,unsigned char * Data){
  unsigned long tRet = 0;
  unsigned char tCnt = 0;
  unsigned long temp = 2; //2ms 发完
  unsigned char buf[40];
  unsigned char length = 9; //9+1

  unsigned char Usart3_Rx_Ack_Len=0;
  
  memset((void *)Usart3_Rx_Buf,0,sizeof(Usart3_Rx_Buf));
  memset((void *)buf,0,sizeof(buf));
  Usart3_Rx_Ack_Len = 10; //应答消息长度
  
  buf[0] = Head;  //填充协议头
  buf[1] = swab8(Head);
  if(Head >= 0xFA)
  {
    buf[2] = ServoNO; //舵机好
  }
  else if(Head > 0x00)  //变长协议
  {
    length = len + 5; //长度
    buf[2] = length;
  }
  buf[3] = CMD;
  memcpy((void *)&buf[4],(void *)Data,len);
  buf[length - 1] = Cheak_Sum( (length - 3),(u8*)&buf[2]);
  buf[length ] = 0xED;
  
  
  if(Head == 0xFA)
  {
    if(CMD == 1 )
    {
      if(ServoNO == 0)
      {
        //这句有问题 memset 不支持双字节的填充
        //memset((void *)&gsSave_Angle,0xFF,sizeof(gsSave_Angle));  //保存所有角度
        //memset((void *)&gsSave_Angle,Data,sizeof(gsSave_Angle));  //保存所有角度
        memset((void *)&gsSave_Angle,Data[0],sizeof(gsSave_Angle)); //保存所有角度
      }
      else
      {
        if(Data[0] == gsSave_Angle.Angle[ServoNO - 1])  return  0;  //不发送,直接返回
        else
        {
          gsSave_Angle.Angle[ServoNO - 1] = Data[0];  //保存单个角度,以后可能双字节角度
        }
      }
      Usart3_Rx_Ack_Len = 1;  //1,4命令只应答一个字节
    }
    else if( CMD == 4)  Usart3_Rx_Ack_Len = 1;  //1,4命令只应答一个字节
  }
  
Retry_Servo:
  
  temp = (Usart3_Rx_Ack_Len + 5) ;  //接收消息长度,用于计算接收时间,1个字节 0.087ms,预留5个空闲,10%误差
  Serial3.begin(115200);  //uart3
  Serial3.setTimeout(temp*87*110/100 / 400);  //设置超时ms
  Serial2.begin(115200);  //设置波特率
  Serial2.write(buf,length + 1);  //发送消息
  Serial2.end();  //关闭串口2,否则会影响接收消息
  
  tRet = Serial3.readBytes( Usart3_Rx_Buf, Usart3_Rx_Ack_Len+10); //接收应答
  Serial3.end();  //关闭串口3,否则会影响接收消息
  if(tRet > RXD_OFFSET) //打印返回消息
  {
      //Serial.write(Usart3_Rx_Buf + RXD_OFFSET,tRet - RXD_OFFSET);
      //Serial.print("\r\n");
  }
  
  if(tRet == 0) //没有接收到消息
  {
    if( tCnt < 2)
    {
      tCnt ++;  //重试
      goto  Retry_Servo;
    }
  }
  else  //接收到消息
  {
  Usart3_Rx_Buf_count = tRet;
    tRet = 0;
    if(Head == 0xFA)
    {
      if( (CMD == 1) || (CMD == 4) )
      {
        if( (Usart3_Rx_Buf[RXD_OFFSET + 1] == 0xAA + ServoNO) )
        {
          tRet = ServoNO;
        }
      }
      else if(CMD == 2 |CMD==3)
      {
        if( (Usart3_Rx_Buf[RXD_OFFSET + 3] == 0xAA) && (Usart3_Rx_Buf[RXD_OFFSET + 2] == ServoNO) )
        {
          tRet = Usart3_Rx_Buf[10+6] << 8;
          tRet |= Usart3_Rx_Buf[10+7] << 0;
        }
      }

      
      else if(CMD == 0xCD )
      {
        if( (Usart3_Rx_Buf[RXD_OFFSET + 5] == ServoNO) )
        {
          tRet = Usart3_Rx_Buf[RXD_OFFSET + 5];
        }
      }
      else if(CMD == 0xD2 )
      {
        if( (Usart3_Rx_Buf[RXD_OFFSET + 3] == 0xAA) && (Usart3_Rx_Buf[RXD_OFFSET + 2] == ServoNO) )
        {
          tRet = 1;
        }
      }
      else if(CMD == 0xD4 )
      {
        if( (Usart3_Rx_Buf[RXD_OFFSET + 3] == 0xAA) && (Usart3_Rx_Buf[RXD_OFFSET + 2] == ServoNO) )
        {
          tRet = Usart3_Rx_Buf[RXD_OFFSET + 6] << 8;
          tRet |= Usart3_Rx_Buf[RXD_OFFSET + 7] << 0;
        }
      }
      
    }
    else if(Head == 0xFC)
    {
      if(CMD == 1 )
      {
        if((Usart3_Rx_Buf[RXD_OFFSET + 3] == 0xAA) && (Usart3_Rx_Buf[RXD_OFFSET + 2] == ServoNO) )
        {
          tRet = Usart3_Rx_Buf[RXD_OFFSET + 6] << 8;
          tRet |= Usart3_Rx_Buf[RXD_OFFSET + 7] << 0;
        }
      }
    }
    else if( (Head < 0xFA) && (Head > 0x00) && (Usart3_Rx_Buf[length + 4] == CMD) )
    {
      if(CMD == 0x02 )
      {
        tRet = Usart3_Rx_Buf[length + 5] - 0xAA;
      }
      else if(CMD == 0x04 )
      {
  if(Usart3_Rx_Buf[length + 3] == 7)
        tRet = ((Usart3_Rx_Buf[length + 5] - 0xAA) << 8) + Usart3_Rx_Buf[length + 6];
else   if(Usart3_Rx_Buf[length + 3] == 8)
  tRet = (Usart3_Rx_Buf[length + 6] << 8) + Usart3_Rx_Buf[length + 7];
      }
      else if(CMD==0x06|CMD==0x07)
      {
        tRet = Usart3_Rx_Buf[length + 5] - 0xAA;
      }
      
    }
  }
  return tRet;
}

unsigned long SemiduplexSerial::TXD(unsigned char len,unsigned char * Data){
   unsigned char Rx_Buf[23];
  unsigned long tRet = 0;
  memset((void *)Rx_Buf,0,sizeof(Rx_Buf));
  
  Serial3.begin(115200);  //uart3
  Serial3.setTimeout(len+5*87*110/100/400);  //设置超时ms
  Serial2.begin(115200);  //设置波特率
  Serial2.write(Data,len);  //发送消息
  Serial2.end();  //关闭串口2,否则会影响接收消息
  Serial3.readBytes(Rx_Buf,23); //接收应答
  Serial3.end();  //关闭串口3,否则会影响接收消息
  if((Rx_Buf[6]==4 |Rx_Buf[6]==6 | Rx_Buf[6]==3) &( Rx_Buf[8]==3 | Rx_Buf[8]==1)){//move&stop&setid
    if(Rx_Buf[len+3]==0x06 & Rx_Buf[len+5]==0){
       tRet=0;//停止成功返回0
    }
    else if(Rx_Buf[len+3]==0x05 & Rx_Buf[len+5]==0){
      return Rx_Buf[len+7]; 
    }
    else{
      tRet=1;//停止成功返回0 
    }
  }
  else if(Rx_Buf[6]==7  & Rx_Buf[8]==1){//readspeed
    if(Rx_Buf[len+3]==0x05 & Rx_Buf[len+5]==0){
       tRet=(Rx_Buf[len+6]<<8)+Rx_Buf[len+7];//停止成功返回0
    }
    else{
      tRet=1;//停止成功返回0 
      
    }
  }  
    else if(Rx_Buf[6]==0x0e  & Rx_Buf[8]==0x01){//readspeed
    if(Rx_Buf[len+3]==0x06 & Rx_Buf[len+5]==0){
        tRet=0;//停止成功返回0

    }
    else{
      tRet=1;//停止成功返回0 
      
    }
  }
  memset((void *)Data,0,sizeof(Data));
  return tRet;
}

/**@brief EN:Communication protocol sending and receiving functions/CN:检查舵机是否存在。
 *
 * @param[in] Head EN:servo id/CN:舵机号.
 *
 * @returns tRet EN:Accept return value/CN:接受返回值.
 */
unsigned char SemiduplexSerial::Get_Servo_list(unsigned char Servo_NO){
  return(Read_bit(gServo_list[Servo_NO / 8],Servo_NO % 8 ));
}

void SemiduplexSerial::Set_Servo_list(unsigned char Servo_NO){
  Set_bit(gServo_list[Servo_NO / 8],Servo_NO % 8 );
}

void SemiduplexSerial::Clr_Servo_list(unsigned char Servo_NO){
  Clr_bit(gServo_list[Servo_NO / 8],Servo_NO % 8 );
}

/**@brief EN:Check the number of the servo/CN:检查舵机个数
 */
void SemiduplexSerial::check_servo(){//花两秒时间
  unsigned char tID = 1;
  unsigned char tData[4] = {0,0,0,0};
  
  memset((void*)gServo_list,0,sizeof(gServo_list));
  gServos = 0;
  TXD(0xFC,tID,4,0x01,tData ); //预先测试一下
  for(tID = 1; tID < SERVO_NUMER_MAX + 1; tID++)
  {
    if( TXD(0xFC,tID,4,0x01,tData ) != 0 )
    {
      Set_Servo_list(tID - 1);  //设置舵机列表,后面多舵机使用
      gServos++;
    }
    else
    {
      Clr_Servo_list(tID - 1);
    }
  }
 Serial.print("\tTotal Servo:");
  Serial.print(gServos, DEC);
Serial.print("\r\n");
}

static uint8_t SemiduplexSerial::_crc8(unsigned short data){
  for(int i = 0; i < 8; i++)
  {
    if(data & 0x8000)
    {
      data = data ^ POLY;
    }
    
    data = data << 1;
  }

  return (uint8_t)(data >> 8);
}

static uint32_t SemiduplexSerial::crc8(uint32_t crc, const uint8_t *vptr, uint32_t len){
  for(int i = 0; i < len; i++)
  {
    crc = _crc8((crc ^ vptr[i]) << 8);
  }

  return crc;
}

/**@brief EN:JIMU MOTOR Calculate the CRC8 checksum/CN:JIMU电机计算CRC8校验
 *
 * @param[in] pBuf EN:Data buffer/CN:数据缓冲区
 * @param[in] len EN:Data length/CN：数据长度.
 *
 * @returns crc EN:CRC8 checksum value/CN:CRC8校验值.
 */
uint32_t SemiduplexSerial::crc8_itu(const uint8_t *pBuf, uint32_t len){
  uint32_t crc;
  crc = crc8(0 ,pBuf, len);
  crc ^= 0x55;
  
  return crc;
}

