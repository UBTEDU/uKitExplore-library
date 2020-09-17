/**************************************************
 * @file    VisionDiscrim.h
 * @brief   Visual Identity module 
 * @author  chenglong.xiong
 * @date    2019/12/18
 * @version 1.2.6
**************************************************/
#ifndef __VISIONDISCRIMH__
#define __VISIONDISCRIMH__
#include "SemiduplexSerial.h"

//#define DEBUG_VISION_FLAG


#define VISION_WIFI_SSIDSET       2509
#define VISION_WIFI_CONNECT       2511
#define VISION_WIFI_STATUSGET     2512
#define VISION_WIFI_IPGET         2524
#define VISION_DISCRIM_TRAFFIC    1000
#define VISION_DISCRIM_ROAD       1001
#define VISION_DISCRIM_QRCODE     1002
#define VISION_DISCRIM_OFFSET     1003
#define VISION_DISPLAY_QUALITY    1004
#define VISION_WIFI_ITEM          2525
#define VISION_WIFI_UPDATE        2526
#define VISION_SYSTEM_GETID       200
#define VISION_SOFTWARE_NO        4
#define VISION_HARDWARE_NO        3
#define VISION_PACKET_FLAG        0xDC
#define VISION_DEVTYPE_WIFI       0x02
#define VISION_DEVTYPE_DISCRIM    0x20
#define VISION_DEVTYPE_SYSTEM     0x01
#define VISION_SERIAL_BITRATE     9600
#define VISION_SERIAL_ID          6463
#define UCODE_VISION_ID           12
#define UCODE_MODE_WIFISET        127
#define UCODE_MODE_WIFISTATUS     128
#define UCODE_MODE_IPINFO         129

#define VISION_TYPE_TRAFFICFLAG   1
#define VISION_TYPE_ROAD          2       

#define VISION_READ_TIMEOUT       200 //200 ms
#define VISION_WIFIWAIT_TIMEOUT   20000 //20s 

#pragma pack(1)

typedef struct _VisionSWInfo_
{
  uint8_t mVer[20];
}VisionSWInfo;

typedef struct _VisionHWInfo_
{
  uint8_t mVer[20];
}VisionHWInfo;

typedef struct _VisionWifiStatus_
{
  uint8_t mStatus;
  uint8_t mDisReason;
  uint8_t mSsid[33];
  int8_t  mRssi;
  uint8_t mAuthmode;
}VisionWifiStatus;

typedef struct _VisionIpInfo_
{
  uint32_t mIp;
  uint32_t mMask;
  uint32_t mGw;
}VisionIpInfo;

typedef struct _VisionSign_
{
  uint16_t  mType;
  uint8_t   mSign[33];
  int16_t   mX;
  int16_t   mY;
  int16_t   mW;
  int16_t   mH;
}VisionSign;

typedef struct _VisionWifiList_
{
  uint8_t  mNums;             /*wifi list size*/
}VisionWifiList;

typedef struct _VisionWifiInfo_
{
  uint8_t  mNums;             /*wifi list size*/
  uint8_t  mIndex;            /*index of wifi list*/
  uint8_t  mWifiSsid[33];     /*wifi name*/
  int8_t   mRssi;             /*wifi strength*/
  uint8_t  mEncryMod;         /*encryption model*/
}VisionWifiInfo;

typedef struct _DisplayQuality_
{
  uint8_t mQuality;           /*quality devel*/
}DisplayQuality;
#pragma pack()
class VisionDiscrim:public SemiduplexSerial
{
    public:
        VisionDiscrim();
        int WifiConnectSet(int iId, bool blType);
        int WifiStatusGet(int iId, VisionWifiStatus  * strVisionWifiStatus);
        int WifiIpGet(int iId, VisionIpInfo * strVisionIpInfo);
        int WifiSsidSet(int iId, const char * strId, const char * strPin, VisionWifiStatus * strVisionWifiStatus);
        bool VisionIdentity(int iId, int iType, int iTimeOut);
        //bool VisionIdentity(int iId, int iType, int iTimeOut, VisionSign * strVisionSign);
        void VisionEnable(bool val, int iType);
        float VisionOffset(int iId);
        int WifiItem(int iId, VisionWifiInfo * strVisionWifiInfo);
        int WifiUpdate(int iId, VisionWifiList * strVisionWifiList);
        int DisplayQualitySet(int iId, DisplayQuality strDisplayQuality);
        int HardWareVersionGet(int iId, VisionHWInfo * mVisionHWInfo);
        int SoftWareVersionGet(int iId, VisionSWInfo * mVisionSWInfo);
    private:
        bool mOnOff;
        int mType;
        uint16_t mCmdArray[10];
};

#endif