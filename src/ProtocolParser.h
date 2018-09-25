#ifndef PROTOCOLPARSER_H
#define PROTOCOLPARSER_H
#include <Arduino.h>
/*
自定义的库函数

协议解析器 V1.0
解析的数据格式：
	协议首部-指令长度-控制指令-校验和
"控制指令"格式：
	设备类型-设备号-端口号

*/
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 128//假定接收数据的最大长度为128
class ProtocolParser
{
public:
  ProtocolParser(char *header);
  ~ProtocolParser();
  void Append(char *data);
  void AppendChar(char ch);//将从串口接收到的字符存到buffer

  size_t GetDeviceType();//获取设备类型
  size_t GetDeviceNumber();//获取设备号
  size_t GetPort();//获取设备所连接的端口号
 
private:
  bool m_bInCmd;//标志位，标识一条控制指令是否接收完毕
  char *m_pHeader;//协议首部
  size_t m_nCmdLength;//指令长度
  char *m_pCtrlCmd;//控制指令
  size_t m_nCheckSum;//校验和
  char buffer[BUFFER_SIZE];//接收的数据暂时存在buffer中
  size_t m_nRecvDataIndex;//记录接收数据的索引

  char GetHeader(size_t index);//获取协议首部指定索引的字符
  size_t GetCmdLength();//获取控制指令长度
  size_t GetRecvDataLength();//获取接收到的一条控制指令的长度
  size_t GetCheckSum();//获取实际接收到的校验和
};
#endif
