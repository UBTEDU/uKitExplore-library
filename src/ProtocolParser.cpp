#include "ProtocolParser.h"
//构造函数初始化，header为协议首部
ProtocolParser::ProtocolParser(char *header)
{
  m_bInCmd = false;
  //strcpy(m_pHeader, header);
  m_pHeader = header;
  m_nCmdLength = 0;
  m_nCheckSum = 0;
  m_nRecvDataIndex = 0;
  m_pCtrlCmd = NULL;

  buffer[0] = '\0';
}

ProtocolParser::~ProtocolParser()
{
}

char ProtocolParser::GetHeader(size_t index)
{
  int headerLength = strlen(m_pHeader);
  return m_pHeader[index];
}
//获取“控制指令”字段的长度，通过接收到的数据的第2、3位的值获取
size_t ProtocolParser::GetCmdLength()
{
  int len = strlen(buffer);
  if (len >= 2)
  {
    m_nCmdLength=(buffer[0] - '0') * 16 + (buffer[1] - '0') * 1;
  }
  return m_nCmdLength;
}
//获取实际接收到的校验和
size_t ProtocolParser::GetCheckSum()
{
  //int len = strlen(buffer);
  m_nCheckSum = (buffer[GetCmdLength() * 2 + 2] - '0') * 16 + (buffer[GetCmdLength() * 2 + 3] - '0') * 1;
  return m_nCheckSum;
}
//从buffer中解析出设备类型
size_t ProtocolParser::GetDeviceType()
{
  //int len = strlen(buffer);
  return (buffer[2] - '0') * 16 + (buffer[3] - '0') * 1;
}
//从buffer中解析出设备号
size_t ProtocolParser::GetDeviceNumber()
{
  //int len = strlen(buffer);
  return (buffer[4] - '0') * 16 + (buffer[5] - '0') * 1;
}
//从buffer中解析出端口号
size_t ProtocolParser::GetPort()
{
  //int len = strlen(buffer);
  return (buffer[6] - '0') * 16 + (buffer[7] - '0') * 1;
}

//将从串口接收的字符串存入buffer中
void ProtocolParser::AppendChar(char ch)
{
  size_t bufferLength = strlen(buffer);
  switch (m_nRecvDataIndex)
  {
  case 0:
  case 1://接收到的数据的索引值为0或者1，表示接收到的是首部
    m_bInCmd = true;
    buffer[0] = 0;
    m_nRecvDataIndex++;
    return;
    break;
  case 2:
  case 3://接收到的数据的索引值为2或者3，表示接收到的是"指令长度"部分
    buffer[m_nRecvDataIndex - 2] = ch;
    buffer[m_nRecvDataIndex - 1] = '\0';
    m_nRecvDataIndex++;
    return;
    break;
  default:
    break;
  }
  if (m_nRecvDataIndex==(GetCmdLength()*2+5))//达到了索引值
  {
    buffer[bufferLength] = ch;
    buffer[bufferLength + 1] = '\0';
    size_t chksum = 0;
    //计算根据接收的数据得到的校验和
    for (size_t i = 0; i < GetCmdLength()*2;++i)
    {
      chksum ^= buffer[i + 2];
    }

    if (chksum==GetCheckSum())//判断实际接收到的校验和跟计算出来的校验和是否相等
    {
      Serial.println("DeviceType:");
      Serial.println(GetDeviceType(),DEC);
      Serial.println("DeviceNumber:");
      Serial.println(GetDeviceNumber(),DEC);
      Serial.println("Port:");
      Serial.println(GetPort(),DEC);

    }
    else//不相等说明出错了
    {
      Serial.println("Error");
      //cout << "Error" << endl;
    }
    buffer[0] = '\0';
    m_bInCmd = false;
    m_nRecvDataIndex = 0;
    m_nCheckSum = 0;
  }
  else if (m_bInCmd)//指令未接收完毕
  {
    buffer[bufferLength] = ch;
    buffer[bufferLength + 1] = '\0';
    m_nRecvDataIndex++;
  }
}
void ProtocolParser::Append(char *data)
{
  for (size_t i = 0; i < strlen(data);++i)
  {
    AppendChar(data[i]);
  }
}
