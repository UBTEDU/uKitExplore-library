/**************************************************
 * @file    VisionDiscrim.cpp
 * @brief   Visual Identity module 
 * @author  chenglong.xiong
 * @date    2019/12/18
 * @version 1.2.6
**************************************************/
#include "VisionDiscrim.h"
#include <ArduinoJson.h>
/**************************************************
 * @name        WifiConnectSet
 * @brief       wifi connect
 * @param[in]   iId   device id
 * @param[in]   blType true or false, true = connect,false = disconnect    
 * @return      int 0 for success
 * @author      chenglong.xiong
 * @date        2019/12/18
 * @version     1.2.6
**************************************************/
int VisionDiscrim::WifiConnectSet(int iId, bool blType)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build head, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_WIFI;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_WIFI_CONNECT);
    ucBuf[0] = blType;
    
    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID, VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return uiRet;
    }
    
    do
    {
        stVisionHead strHeadRd = {0};
        uint8_t DataCrc;
        int DataLen;
        unsigned char ucRdBuf[VISION_SERIAL_BUFSIZE] = {0};
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 1, ucBuf);
        if(uiRet < 0)
        {
            uiRet = -1;
            break;
        }

        //delay(1000);
        uiRet = UbtExploreRead(ucRdBuf, VISION_SERIAL_BUFSIZE - 1, 5000, 100);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        /*prase*/
        memcpy(&strHeadRd, ucRdBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucRdBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHeadRd.mCmd != strHead.mCmd)||(DataCrc != ucRdBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }
        if(ucRdBuf[2+ucRdBuf[1]])
        {
            uiRet = ucRdBuf[3+ucRdBuf[1]];
        }
        else
        {
            uiRet = -1;
        }
        
    } while (0);
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);
    return uiRet;
}

/**************************************************
 * @name        WifiStatusGet
 * @brief       get wifi infomation
 * @param[in]   iId   device id
 * @param[out]  strVisionWifiStatus wifi info
 * @return      int 0 for success
 * @author      chenglong.xiong
 * @date        2019/12/18
 * @version     1.2.6
**************************************************/
int VisionDiscrim::WifiStatusGet(int iId, VisionWifiStatus  * strVisionWifiStatus)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_WIFI;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_WIFI_STATUSGET);

    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return uiRet;
    }
    
    do
    {
        //VisionWifiStatus strVisionWifiStatus = {0};
        //DynamicJsonDocument jsonRoot(100);
        stVisionHead strHeadRd = {0};
        uint8_t DataCrc;
        int DataLen;
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        //delay(1000);
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 2000, 100);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        /*prase*/
        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }

        uiRet = ucBuf[3 + ucBuf[1]];
        if((ucBuf[2 + ucBuf[1]] >= (sizeof(VisionWifiStatus) + 1))&&(!(uiRet)))
        {
            //uiRet = ucBuf[3 + ucBuf[1]];
            memcpy(strVisionWifiStatus, ucBuf + 4 + ucBuf[1], sizeof(VisionWifiStatus));
            //strVisionWifiStatus->mRssi = swab32(strVisionWifiStatus->mRssi);
            #if 0
            jsonRoot["device"] = UCODE_VISION_ID;
            jsonRoot["mode"] = UCODE_MODE_WIFISTATUS;
            jsonRoot["id"] = iId;
            jsonRoot["code"] = ucBuf[3 + ucBuf[1]];
            JsonArray jsonData = jsonRoot.createNestedArray("data");
            JsonObject JsonArrayItem = jsonData.createNestedObject();
            jsonRoot["uuid"]=1;
            JsonArrayItem["state"] = strVisionWifiStatus.mStatus;
            JsonArrayItem["disreason"] = strVisionWifiStatus.mDisReason;
            JsonArrayItem["ssid"] = strVisionWifiStatus.mSsid;
            JsonArrayItem["rssi"] = swab32(strVisionWifiStatus.mRssi);
            JsonArrayItem["authmode"] = strVisionWifiStatus.mAuthmode;
            /*send to ucode*/
            uint16_t bufferLength=measureMsgPack(jsonRoot);
            byte Buffer[2]={0};
            Buffer[0]=(bufferLength>>8)&0xff;
            Buffer[1]=(bufferLength)&0xff;
            Serial.write(Buffer,2); 
            serializeMsgPack(jsonRoot,Serial);
            #endif
        }
    }while(0);
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);

    return uiRet;
}

/**************************************************
 * @name        WifiIpGet
 * @brief       get wifi infomation
 * @param[in]   iId   device id
 * @param[out]  strVisionIpInfo ip info
 * @return      int 成功返回0
 * @author      chenglong.xiong
 * @date        2019/12/18
 * @version     1.2.6
**************************************************/
int VisionDiscrim::WifiIpGet(int iId, VisionIpInfo * strVisionIpInfo)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_WIFI;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_WIFI_IPGET);

    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return uiRet;
    }

    do
    {
        //VisionIpInfo strVisionIpInfo = {0};
        //DynamicJsonDocument jsonRoot(100);
        stVisionHead strHeadRd = {0};
        uint8_t DataCrc;
        int DataLen;
        uint8_t uiBuf[20] = {0};
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        //delay(1000);
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 2000, 100);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        /*prase*/
        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHeadRd.mCmd != strHead.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }

        uiRet = ucBuf[3 + ucBuf[1]];
        if((ucBuf[2 + ucBuf[1]] >= (sizeof(VisionIpInfo) + 1))&&(!(uiRet)))
        {
            //uiRet = ucBuf[3 + ucBuf[1]];
            memcpy(strVisionIpInfo, ucBuf + 4 + ucBuf[1], sizeof(VisionIpInfo));
            strVisionIpInfo->mIp = swab32(strVisionIpInfo->mIp);
            strVisionIpInfo->mMask = swab32(strVisionIpInfo->mMask);
            strVisionIpInfo->mGw = swab32(strVisionIpInfo->mGw);
            #if 0
            jsonRoot["device"] = UCODE_VISION_ID;
            jsonRoot["mode"] = UCODE_MODE_IPINFO;
            jsonRoot["id"] = iId;
            jsonRoot["code"] = ucBuf[3 + ucBuf[1]];
            JsonArray jsonData = jsonRoot.createNestedArray("data");
            JsonObject JsonArrayItem = jsonData.createNestedObject();
            jsonRoot["uuid"]=1;
            sprintf(uiBuf, "%d.%d.%d.%d", strVisionIpInfo.mIp&0xff, (strVisionIpInfo.mIp>>8)&0xff, (strVisionIpInfo.mIp>>16)&0xff, (strVisionIpInfo.mIp>>32)&0xff);
            JsonArrayItem["ip"] = uiBuf;
            memset(uiBuf, 0, sizeof(uiBuf));
            sprintf(uiBuf, "%d.%d.%d.%d", strVisionIpInfo.mMask&0xff, (strVisionIpInfo.mMask>>8)&0xff, (strVisionIpInfo.mMask>>16)&0xff, (strVisionIpInfo.mMask>>32)&0xff);
            JsonArrayItem["mask"] = uiBuf;
            memset(uiBuf, 0, sizeof(uiBuf));
            sprintf(uiBuf, "%d.%d.%d.%d", strVisionIpInfo.mGw&0xff, (strVisionIpInfo.mGw>>8)&0xff, (strVisionIpInfo.mGw>>16)&0xff, (strVisionIpInfo.mGw>>32)&0xff);
            JsonArrayItem["gw"] = uiBuf;
            /*send to ucode*/
            uint16_t bufferLength=measureMsgPack(jsonRoot);
            byte Buffer[2]={0};
            Buffer[0]=(bufferLength>>8)&0xff;
            Buffer[1]=(bufferLength)&0xff;
            Serial.write(Buffer,2); 
            serializeMsgPack(jsonRoot,Serial);
            #endif
        }
    } while (0);
    
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);

    return uiRet;
}

/**************************************************
 * @name        WifiSsidSet
 * @brief       get wifi infomation
 * @param[in]   iId   device id
 * @param[in]   strId wifi ssid
 * @param[in]   strPin wifi password
 * @param[out]  strVisionWifiStatus wifi status
 * @return      int 成功返回0
 * @author      chenglong.xiong
 * @date        2019/12/18
 * @version     1.2.6
**************************************************/
int VisionDiscrim::WifiSsidSet(int iId, const char * strId, const char * strPin, VisionWifiStatus * strVisionWifiStatus)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_WIFI;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_WIFI_SSIDSET);
    memcpy(ucBuf, strId, strlen(strId));
    memcpy(ucBuf + 33, strPin, strlen(strPin));
    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return uiRet;
    }
    
    do
    {
        //VisionWifiStatus strVisionWifiStatus = {0};
        DynamicJsonDocument jsonRoot(100);
        unsigned char ucRdBuf[VISION_SERIAL_BUFSIZE] = {0};
        stVisionHead strHeadRd = {0};
        uint8_t DataCrc;
        int DataLen;
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 66, ucBuf);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        //delay(1000);
        /*read*/
        //memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucRdBuf, VISION_SERIAL_BUFSIZE - 1, VISION_WIFIWAIT_TIMEOUT, 100);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        /*prase*/
        memcpy(&strHeadRd, ucRdBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucRdBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHeadRd.mCmd != strHead.mCmd)||(DataCrc != ucRdBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }
        uiRet = ucRdBuf[3 + ucRdBuf[1]];
        if((ucRdBuf[2 + ucRdBuf[1]] >= (sizeof(VisionWifiStatus) + 1))&&(!uiRet))
        {
            //uiRet = ucRdBuf[3 + ucRdBuf[1]];
            memcpy(strVisionWifiStatus, ucRdBuf + 4 + ucRdBuf[1], sizeof(VisionWifiStatus));
            //strVisionWifiStatus->mRssi = swab32(strVisionWifiStatus->mRssi);
            #if 0
            jsonRoot["device"] = UCODE_VISION_ID;
            jsonRoot["mode"] = UCODE_MODE_WIFISET;
            jsonRoot["id"] = iId;
            jsonRoot["code"] = ucRdBuf[3 + ucRdBuf[1]];
            JsonArray jsonData = jsonRoot.createNestedArray("data");
            JsonObject JsonArrayItem = jsonData.createNestedObject();
            jsonRoot["uuid"]=1;
            JsonArrayItem["state"] = strVisionWifiStatus.mStatus;
            JsonArrayItem["disreason"] = strVisionWifiStatus.mDisReason;
            JsonArrayItem["ssid"] = strVisionWifiStatus.mSsid;
            JsonArrayItem["rssi"] = swab32(strVisionWifiStatus.mRssi);
            JsonArrayItem["authmode"] = strVisionWifiStatus.mAuthmode;
            /*send to ucode*/
            uint16_t bufferLength=measureMsgPack(jsonRoot);
            byte Buffer[2]={0};
            Buffer[0]=(bufferLength>>8)&0xff;
            Buffer[1]=(bufferLength)&0xff;
            Serial.write(Buffer,2); 
            serializeMsgPack(jsonRoot,Serial);
            #endif
        }
    }while(0);
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);

    return uiRet;
}

/**************************************************
 * @name        VisionIdentity
 * @brief       vision discrim
 * @param[in]   iId   device id
 * @param[in]   iType sign type
 * @param[in]   iTimeOut time out
 * @return      int 成功返回0
 * @author      chenglong.xiong
 * @date        2019/12/18
 * @version     1.2.6
**************************************************/
bool VisionDiscrim::VisionIdentity(int iId, int iType, int iTimeOut)
{
    #if 0
    /*charley test*/
    Serial.println("VisionIdentity");
    #endif
    /*be must enable and chosse type before use vision module*/
    if((!mOnOff)||(mType <= 0))
    {
        return false;
    }
    #if 0
    /*charley test*/
    Serial.println(mOnOff);
    Serial.println(mType);
    #endif
    randomSeed(analogRead(0));
    uint32_t uTime = 0;
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    uint32_t uiBegin;
    uint32_t uiEnd;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_DISCRIM;
    strHead.mSeq = swab16(uiRandNum);
    //if(mType != (iType / 100))
    {
    //    return false;
    }
    strHead.mCmd = swab16(mCmdArray[mType - 1]);
    #if 0
    /*charley test*/
    Serial.print("cmd:");
    Serial.println(mCmdArray[mType - 1]);
    #endif
    #if 0
    if(2 == (iType / 100))
    {
        strHead.mCmd = swab16(VISION_DISCRIM_ROAD);
    }
    else if(1 == (iType / 100))
    {
        strHead.mCmd = swab16(VISION_DISCRIM_TRAFFIC);
    }
    else if(3 == (iType / 100))
    {
        strHead.mCmd = swab16(VISION_DISCRIM_QRCODE);
    }
    #endif
    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return false;
    }
    uiBegin = millis();
    do
    {
        int DataLen;
        uint8_t DataCrc;
        uint8_t DataBuf[33] = {0};
        stVisionHead strHeadRd = {0};
        if(iTimeOut > 0)
        {
            uiEnd = millis();
            if((uiEnd - uiBegin)/1000 >= iTimeOut)
            {
                break;
            }
        }
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
        if(uiRet <= 0)
        {
            continue;
        }
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, VISION_READ_TIMEOUT);
        if(uiRet <= 0)
        {
            continue;
        }

        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            continue;
        }
        /*judge sign type*/
        if((ucBuf[2 + ucBuf[1]] > sizeof(VisionSign))&&(0 == ucBuf[3 + ucBuf[1]]))
        {
            VisionSign strVisionSign;
            memcpy(&strVisionSign, ucBuf + 4 + ucBuf[1], sizeof(VisionSign));
            strVisionSign.mX = swab16(strVisionSign.mX);
            strVisionSign.mY = swab16(strVisionSign.mY);
            strVisionSign.mW = swab16(strVisionSign.mW);
            strVisionSign.mH = swab16(strVisionSign.mH);
            #ifdef DEBUG_VISION_FLAG
            {
                Serial.print("Type:");
                Serial.println(swab16(strVisionSign.mType));
            }
            #endif
            if(swab16(strVisionSign.mType) == iType)
            {
                if((207 == iType)&&(strVisionSign.mY < 160))
                {
                    uTime = 0;
                }
                else
                {
                    uTime = 1;
                    break;  
                }
                //break;
            }
        }
        
        delay(100);
    }while(iTimeOut);
    
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);

    return (1 == uTime)?true:false;
}

/**************************************************
 * @name        VisionEnable
 * @brief       vision on off
 * @param[in]   val   true enable,false close
 * @return      void
 * @author      chenglong.xiong
 * @date        2019/12/18
 * @version     1.2.6
**************************************************/
void VisionDiscrim::VisionEnable(bool val, int iType)
{
    mOnOff = val;
    mType = iType;
}

/**************************************************
 * @name        VisionDiscrim
 * @brief       constructed function
 * @param       void
 * @return      void
 * @author      chenglong.xiong
 * @date        2019/12/18
 * @version     1.2.6
**************************************************/
VisionDiscrim::VisionDiscrim()
{
    #if 0
    /*charley test*/
    Serial.println("VisionDiscrim init:");
    #endif
    /*init*/
    mOnOff = false;
    mType = -1;
    mCmdArray[0] = VISION_DISCRIM_TRAFFIC;
    mCmdArray[1] = VISION_DISCRIM_ROAD;
    mCmdArray[2] = VISION_DISCRIM_QRCODE;
    
}

/**************************************************
 * @name        VisionOffset
 * @brief       get module offset
 * @param[in]   iId id of module 
 * @return      float
 * @author      chenglong.xiong
 * @date        2019/12/28
 * @version     1.2.6
**************************************************/
float VisionDiscrim::VisionOffset(int iId)
{
    /*be must enable and chosse type before use vision module*/
    if((!mOnOff)||(mType <= 0))
    {
        return -100;
    }

    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    float    fOffset = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_DISCRIM;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_DISCRIM_OFFSET);

    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return -100;
    }
    
    do
    {
        int DataLen;
        uint8_t DataCrc;
        uint8_t DataBuf[33] = {0};
        stVisionHead strHeadRd = {0};
        //delay(1000);
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
        if(uiRet <= 0)
        {
            fOffset = -100;
            break;
        }
        //delay(1000);
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 200);
        if(uiRet <= 0)
        {
            fOffset = -100;
            break;
        }
        
        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            fOffset = -100;
            break;
        }
        
        /*judge code and data len*/
        if((ucBuf[2 + ucBuf[1]] == (sizeof(float) + 1))&&(0 == ucBuf[3 + ucBuf[1]]))
        {
            //memcpy(&fOffset, ucBuf[4 + ucBuf[1]], sizeof(float));
            /*string to float*/
            unsigned char ucFloat[4] = {0};
            ucFloat[0] = ucBuf[4 + ucBuf[1] + 3];
            ucFloat[1] = ucBuf[4 + ucBuf[1] + 2];
            ucFloat[2] = ucBuf[4 + ucBuf[1] + 1];
            ucFloat[3] = ucBuf[4 + ucBuf[1]];
            memcpy(&fOffset, ucFloat, sizeof(float));
        }
    }while(0);
    
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);

    return fOffset;
}

/**************************************************
 * @name        WifiUpdate
 * @brief       update wifi
 * @param[in]   iId id of module 
 * @param[out]  strVisionWifiList return info of wifi list
 * @return      int success return 0
 * @author      chenglong.xiong
 * @date        2020/01/02
 * @version     1.2.6
**************************************************/
int VisionDiscrim::WifiUpdate(int iId, VisionWifiList * strVisionWifiList)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_WIFI;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_WIFI_UPDATE);

    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return -1;
    }

    do
    {
        int DataLen;
        uint8_t DataCrc;
        uint8_t DataBuf[33] = {0};
        stVisionHead strHeadRd = {0};
        //delay(1000);
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        //delay(1000);
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 5000);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        
        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }
        
        /*judge code and data len*/
        uiRet = ucBuf[3 + ucBuf[1]];
        if((ucBuf[2 + ucBuf[1]] > sizeof(VisionWifiList))&&(0 == uiRet))
        {
            memcpy(strVisionWifiList, ucBuf + 4 + ucBuf[1], sizeof(VisionWifiList));
        }
    } while (0);
    
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);
    return uiRet;
}

/**************************************************
 * @name        WifiItem
 * @brief       get wifi info
 * @param[in]   iId id of module 
 * @param[out]  strVisionWifiInfo return info of wifi
 * @return      int success return 0
 * @author      chenglong.xiong
 * @date        2020/01/02
 * @version     1.2.6
**************************************************/
int VisionDiscrim::WifiItem(int iId, VisionWifiInfo * strVisionWifiInfo)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_WIFI;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_WIFI_ITEM);

    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return -1;
    }

    do
    {
        int DataLen;
        uint8_t DataCrc;
        uint8_t DataBuf[33] = {0};
        stVisionHead strHeadRd = {0};
        //delay(1000);
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        //delay(1000);
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 1000);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        
        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }
        
        /*judge code and data len*/
        uiRet = ucBuf[3 + ucBuf[1]];
        if((ucBuf[2 + ucBuf[1]] > sizeof(VisionWifiInfo))&&(0 == uiRet))
        {
            memcpy(strVisionWifiInfo, ucBuf + 4 + ucBuf[1], sizeof(VisionWifiInfo));
            //strVisionWifiInfo->mRssi = swab32(strVisionWifiInfo->mRssi);
        }
    } while (0);
    
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);
    return uiRet;
}

/**************************************************
 * @name        DisplayQualitySet
 * @brief       set quality of the graphic dispaly
 * @param[in]   iId id of module 
 * @param[out]  strDisplayQuality quality
 * @return      int success return 0
 * @author      chenglong.xiong
 * @date        2020/01/03
 * @version     1.2.6
**************************************************/
int VisionDiscrim::DisplayQualitySet(int iId, DisplayQuality strDisplayQuality)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_DISCRIM;
    strHead.mSeq = swab16(uiRandNum);
    strHead.mCmd = swab16(VISION_DISPLAY_QUALITY);

    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID,VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return 0;
    }

    do
    {
        int DataLen;
        uint8_t DataCrc;
        uint8_t DataBuf[33] = {0};
        stVisionHead strHeadRd = {0};
        //delay(1000);
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, sizeof(DisplayQuality), (unsigned char *)&strDisplayQuality);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        //delay(1000);
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 1000);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        
        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }
        
        /*return code*/
        uiRet = ucBuf[3 + ucBuf[1]];
    } while (0);
    
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);
    return uiRet;
}

/**************************************************
 * @name        SoftWareVersionGet
 * @brief       get software version of vision module
 * @param[in]   iId id of module 
 * @param[out]  mVisionSWInfo software info
 * @return      int success return 0
 * @author      chenglong.xiong
 * @date        2020/01/08
 * @version     1.2.6
**************************************************/
int VisionDiscrim::SoftWareVersionGet(int iId, VisionSWInfo * mVisionSWInfo)
{
    randomSeed(analogRead(0));
    uint16_t uiRandNum = random(50000);
    int uiRet = 0;
    unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
    stVisionHead strHead;
    /*build packet, big endian*/
    strHead.mId = iId;
    strHead.mDev = VISION_DEVTYPE_SYSTEM;
    strHead.mSeq = swab16(uiRandNum);
    //strHead.mSeq = swab16(mSeq);
    strHead.mCmd = swab16(VISION_SOFTWARE_NO);

    /*serial begin*/
    uiRet = UbtSerialBegin(VISION_SERIAL_ID, VISION_SERIAL_BITRATE);
    if(uiRet < 0)
    {
        return uiRet;
    }

    do
    {
        int DataLen;
        uint8_t DataCrc;
        stVisionHead strHeadRd = {0};
        //delay(1000);
        /*send*/
        uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }
        /*read*/
        memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
        uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 60);
        if(uiRet <= 0)
        {
            uiRet = -1;
            break;
        }

        memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
        DataLen = uiRet;
        DataCrc = crc8_itu(ucBuf, DataLen-1);
        strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
        if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
        {
            uiRet = -1;
            break;
        }
        /*Get version*/
        uiRet = ucBuf[3 + ucBuf[1]];
        if((ucBuf[2 + ucBuf[1]] > sizeof(VisionSWInfo))&&(0 == uiRet))
        {
            
            memcpy(mVisionSWInfo, ucBuf + 4 + ucBuf[1], sizeof(VisionSWInfo));
        }
    } while (0);
    
    /*serial end*/
    UbtSerialEnd(VISION_SERIAL_ID);
    
    return uiRet;
}

/**************************************************
 * @name        HardWareVersionGet
 * @brief       get version of the vision module
 * @param[in]   iId id of module 
 * @param[out]  mVisionHWInfo hardware info
 * @return      int success return 0
 * @author      chenglong.xiong
 * @date        2020/01/08
 * @version     1.2.6
**************************************************/
int VisionDiscrim::HardWareVersionGet(int iId, VisionHWInfo * mVisionHWInfo)
{
  randomSeed(analogRead(0));
  uint16_t uiRandNum = random(50000);
  int uiRet = 0;
  unsigned char ucBuf[VISION_SERIAL_BUFSIZE] = {0};
  stVisionHead strHead;
  /*build packet, big endian*/
  strHead.mId = iId;
  strHead.mDev = VISION_DEVTYPE_SYSTEM;
  strHead.mSeq = swab16(uiRandNum);
  strHead.mCmd = swab16(VISION_HARDWARE_NO);

  /*serial begin*/
  uiRet = UbtSerialBegin(VISION_SERIAL_ID, VISION_SERIAL_BITRATE);
  if(uiRet < 0)
  {
      return uiRet;
  }

  do
  {
      int DataLen;
      uint8_t DataCrc;
      stVisionHead strHeadRd = {0};
      //delay(1000);
      /*send*/
      uiRet = UbtExploreSend(VISION_PACKET_FLAG, &strHead, 0, NULL);
      if(uiRet <= 0)
      {
          uiRet = -1;
          break;
      }
      /*read*/
      memset(ucBuf, 0, VISION_SERIAL_BUFSIZE);
      uiRet = UbtExploreRead(ucBuf, VISION_SERIAL_BUFSIZE - 1, 60);
      if(uiRet <= 0)
      {
          uiRet = -1;
          break;
      }

      memcpy(&strHeadRd, ucBuf + 2, sizeof(stVisionHead));
      DataLen = uiRet;
      DataCrc = crc8_itu(ucBuf, DataLen-1);
      strHeadRd.mCmd = strHeadRd.mCmd&0xFF7F;
      if((strHead.mSeq != strHeadRd.mSeq)||(strHead.mCmd != strHeadRd.mCmd)||(DataCrc != ucBuf[DataLen-1]))
      {
          uiRet = -1;
          break;
      }
      /*Get version*/
      uiRet = ucBuf[3 + ucBuf[1]];
      if((ucBuf[2 + ucBuf[1]] > sizeof(VisionHWInfo))&&(0 == uiRet))
      {
          memcpy(mVisionHWInfo, ucBuf + 4 + ucBuf[1], sizeof(VisionHWInfo));
      }
  } while (0);
  
  /*serial end*/
  UbtSerialEnd(VISION_SERIAL_ID);
  
  return uiRet;
}