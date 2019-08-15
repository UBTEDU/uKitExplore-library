#include"uKitSensor.h" 
#include<math.h>
unsigned short  uKitSensor::readInfraredDistance(char ID){//uKit红外传感器
  unsigned char buf[1];
  unsigned short  tRet=0;
  static unsigned char InfraredState=1;
  buf[0]=ID;
  if(InfraredState==1){
    ubtInfraredProtocol(0xf8,0x06,0x02,buf);
    InfraredState=0;   
  }  
  
  tRet=ubtInfraredProtocols(0xf8,0x06,0x04,buf);
  if(tRet==ID+0xec){
    ubtInfraredProtocol(0xf8,0x06,0x02,buf);
    tRet=ubtInfraredProtocols(0xf8,0x06,0x04,buf);
  }
 
        float realValue = tRet - 850;
        int level;
        
        if (realValue < 0 || tRet==0 ) {
            level = 0;
        } else if (realValue < 70) {
            level = (int)((realValue - 15) / 13.5);
        } else if (realValue < 1210) {
            level = (int)((realValue + 1134)/ 288.0);
        } else if (realValue < 1565) {
            level = (int)((realValue + 206)/ 177);
        } else if (realValue < 1821) {
            level = (int)((realValue - 1033)/ 53.75);
        } else if (realValue < 2200) {
            level = (int)((realValue - 1462)/ 22.75);
        } else {
            level = 20;
        }
        if(level > 20){
            level = 20;
        }
        
        delay(2);
        return constrain(level,0,20);


     


}



unsigned short uKitSensor::readSoundValue(char id){
  unsigned short tRet = 0,tRet2=0,tRet3=0;
  unsigned char buf[5];


  buf[0] = id;//id
  buf[1] = 0x10;//参数
  buf[2] = 0x00;
  buf[3] = 0x00;
  buf[4] = 0x01;
  tRet3=ubtSoundProtocol(0x0A,0x05,buf);
  tRet=tRet3-2048;
  tRet2=tRet/2; 

  if(tRet==0 || tRet3<=0){
    tRet2=0;
  }

  else if(tRet2>=1023){
    tRet2=1023;
  }
  delay(10);
  return tRet2;
}
unsigned short int uKitSensor::readLightValue(char id){
  unsigned short int tRet = 0;
  unsigned char buf[5];

  buf[0] = id;//id
  buf[1] = 0x10;//参数
  buf[2] = 0x00;
  buf[3] = 0x00;
  buf[4] = 0x01;
  tRet=ubtLightProtocol(0x0A,0x05,buf);
  delay(5);
  if(tRet>4000){
    tRet=4000;    
  }
  return tRet;
}
void uKitSensor::setEyelightLook(char id,char face,int times,int red,int green,int blue){

  unsigned char tData2[1] ;
  unsigned char tData[7];
  unsigned char tRet=0;
  static unsigned char eyelightState=1;
  tData2[0]=id;
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;
    
  }  
  tData[0]=id;  //ID
  tData[1]=face;//表情
  tData[2]=0x00;//
  tData[3]=times;//
  tData[4]=red;
  tData[5]=green;
  tData[6]=blue;
  
  tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
} 

  

 }


void uKitSensor::_delay(float seconds) {
long endTime = millis() + seconds * 1000;
while(millis() < endTime){
  if (Serial.available()){
    break;
  }
}

}

 void uKitSensor::setEyelightLookUntil(char id,char face,int times,int red,int green,int blue){

  unsigned char tData2[1] ;
  unsigned char tData[7];
  unsigned char tRet=0;
  static unsigned char eyelightState=1;
  tData2[0]=id;
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;
    
  }  
  tData[0]=id;  //ID
  tData[1]=face;//表情
  tData[2]=0x00;//
  tData[3]=times;//
  tData[4]=red;
  tData[5]=green;
  tData[6]=blue;
  
  tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
} 

switch(face){
  case 0://眨眼
    _delay(times*2.55); 
    break;
  case 1://害羞
    _delay(times*4.4);  
    break;  
  case 2://热泪盈眶
   _delay(times*2.8); 
    break;  
  case 3://泪光闪动
    _delay(times*1.72); 
    break;
  case 4://哭泣
    _delay(times*2.95);  
    break;  
  case 5://晕
   _delay(times*0.8); 
    break;  
  case 6://开心
    _delay(times*2.05); 
    break;
  case 7://惊讶
    _delay(times*3.4);  
    break;  
  case 8://呼吸
   _delay(times*3); 
    break;          
  case 9://闪烁
    _delay(times*0.4); 
    break;
  case 10://风扇
    _delay(times*0.3);  
    break;  
  case 11://雨刮
   _delay(times*1); 
    break;      
}

  

 }

void uKitSensor::setEyelightSceneUntil(char id,char scene,int times){

  unsigned char tData2[1] ;
  unsigned char tData[7];
  unsigned char tRet=0;
  static unsigned char eyelightState=1;
   tData2[0]=id;
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;   
  }  
  tData[0]=id;  //ID
  tData[1]=scene+12;//表情
  tData[2]=0x00;//
  tData[3]=times;// 
  tData[4]=0;
  tData[5]=0;
  tData[6]=0;
  tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
} 
switch(scene){
  case 0://七彩跑马灯
    _delay(times*2.4); 
    break;
  case 1://Disco
    _delay(times*2.04);  
    break;  
  case 2://三原色
   _delay(times*1.5); 
    break;  
  case 3://颜色堆叠
    _delay(times*8.4); 
    break;
}
  

 } 
void uKitSensor::setEyelightScene(char id,char scene,int times){

  unsigned char tData2[1] ;
  unsigned char tData[7];
  unsigned char tRet=0;
  static unsigned char eyelightState=1;
   tData2[0]=id;
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;   
  }  
  tData[0]=id;  //ID
  tData[1]=scene+12;//表情
  tData[2]=0x00;//
  tData[3]=times;// 
  tData[4]=0;
  tData[5]=0;
  tData[6]=0;
  tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    tRet=ubtEyelightProtocol(0xf4,0x0c,0x0a,tData);
} 
  

 }
void uKitSensor::setEyelightAllPetals(char id,int red,int green,int blue){

  signed char tData2[1] ;
  signed char tData[8];
  unsigned char tRet=0;
  static unsigned char eyelightState=1;
   tData2[0]=id;
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;   
  }  
  tData[0]=id;  //ID
  tData[1]=0xff;
  tData[2]=1;//
  tData[3]=0xff;//
  tData[4]=red;
  tData[5]=green;
  tData[6]=blue;
  tData[7]=8;
    tRet=ubtEyelightProtocol(0xf4,0x0c,0x0b,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    tRet=ubtEyelightProtocol(0xf4,0x0c,0x0b,tData);
  
 }
}
void uKitSensor::setEyelightPetal(char id,unsigned char petalsnum,unsigned char petals[8][4],unsigned char time){
  signed char tData2[1] ;
  signed char tData[35];
  unsigned char tRet=0;
  static unsigned char eyelightState=1;
   tData2[0]=id;
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;   
  }  
  tData[0]=id;  //ID
  tData[1]=0xff;//持续时间
  tData[2]=petalsnum;//色块数量
  
  tData[3]=petals[0][0];//第1
  tData[4]=petals[0][1];
  tData[5]=petals[0][2];
  tData[6]=petals[0][3];
  
  tData[7]=petals[1][0];//第2
  tData[8]=petals[1][1];
  tData[9]=petals[1][2];
  tData[10]=petals[1][3];
  
  tData[11]=petals[2][0];//第3
  tData[12]=petals[2][1];
  tData[13]=petals[2][2];
  tData[14]=petals[2][3];
  
  tData[15]=petals[3][0];//第4
  tData[16]=petals[3][1];
  tData[17]=petals[3][2];
  tData[18]=petals[3][3];
  
  tData[19]=petals[4][0];//第5
  tData[20]=petals[4][1];
  tData[21]=petals[4][2];
  tData[22]=petals[4][3];
  
  tData[23]=petals[5][0];//第6
  tData[24]=petals[5][1];
  tData[25]=petals[5][2];
  tData[26]=petals[5][3];
  
  tData[27]=petals[6][0];//第7
  tData[28]=petals[6][1];
  tData[29]=petals[6][2];
  tData[30]=petals[6][3];
  
  tData[31]=petals[7][0];//第8
  tData[32]=petals[7][1];
  tData[33]=petals[7][2];
  tData[34]=petals[7][3];  
  tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
  
 }
  //State=TXD(0xF4,1,35,0x0b,tData );
  delay(time*1000);
  setEyelightOff(id);
  delay(5);
  
}
void uKitSensor::setEyelightPetals(char id,unsigned char petalsnum,String petals){
  const size_t capacity = JSON_ARRAY_SIZE(32) + JSON_OBJECT_SIZE(1) + 10;
  DynamicJsonDocument root(capacity);
  signed char tData2[1] ;
  unsigned char tData[35];
  
  deserializeJson(root,petals);
  unsigned char tRet=0;
   tData2[0]=id;
  static unsigned char eyelightState=1;
  
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;   
  } 
  JsonArray data = root["data"]; 
  tData[0]=id;  //ID
  tData[1]=0xff;//持续时间
  tData[2]=petalsnum;//色块数量
  
  tData[3]=int(root["data"][0]);//第1
  tData[4]=int(root["data"][1]);
  tData[5]=int(root["data"][2]);
  tData[6]=int(root["data"][3]);
  
  tData[7]=int(root["data"][4]);//第2
  tData[8]=int(root["data"][5]);
  tData[9]=int(root["data"][6]);
  tData[10]=int(root["data"][7]);
  
  tData[11]=int(root["data"][8]);//第3
  tData[12]=int(root["data"][9]);
  tData[13]=int(root["data"][10]);
  tData[14]=int(root["data"][11]);
  
  tData[15]=int(root["data"][12]);//第4
  tData[16]=int(root["data"][13]);
  tData[17]=int(root["data"][14]);
  tData[18]=int(root["data"][15]);
  
  tData[19]=int(root["data"][16]);//第5
  tData[20]=int(root["data"][17]);
  tData[21]=int(root["data"][18]);
  tData[22]=int(root["data"][19]);
  
  tData[23]=int(root["data"][20]);//第6
  tData[24]=int(root["data"][21]);
  tData[25]=int(root["data"][22]);
  tData[26]=int(root["data"][23]);
  
  tData[27]=int(root["data"][24]);//第7
  tData[28]=int(root["data"][25]);
  tData[29]=int(root["data"][26]);
  tData[30]=int(root["data"][27]);
  
  tData[31]=int(root["data"][28]);//第8
  tData[32]=int(root["data"][29]);
  tData[33]=int(root["data"][30]);
  tData[34]=int(root["data"][31]);  

    tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2); 
    tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
 }
  
  
  
}
void uKitSensor::setEyelightPetalu(char id,unsigned char petalsnum,int* petals){

  signed char tData2[1];
  unsigned char tData[35],g=0;
  
  unsigned char tRet=0;
  tData2[0]=id;
  static unsigned char eyelightState=1;
  
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;   
  } 
  
  tData[g++]=id;  //ID
  tData[g++]=petals[8]/100;//持续时间
  tData[g++]=petalsnum;//色块数量

  for(int i=0;i<8;i++){
    if(i<=1){
      tData[g++]=int(pow(2,i)); 
    }
    else{
      tData[g++]=int(pow(2,i)+1); 
    
    }
    
    if (petals[i]==1){
      
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
    }
    else if (petals[i]==2){
     
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
    }
    else if (petals[i]==3){
     
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
    }
    else if (petals[i]==4){
     
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
    }
    else if (petals[i]==5){
    
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
    }
    else if (petals[i]==6){
     
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
    }
    else if (petals[i]==7){
      
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
    }
    else if (petals[i]==8){
  
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
    }
    else if (petals[i]==9){
  
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
    }        
  }
  

    tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2); 
    tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
 }

 
  
  
  
}
void uKitSensor::setEyelightPetalus(char id,int petal1,int petal2,int petal3,int petal4,int petal5,int petal6,int petal7,int petal8,int times){

  signed char tData2[1];
  unsigned char tData[35],g=0;
  
  unsigned char tRet=0;
  tData2[0]=id;
  static unsigned char eyelightState=1;
  
  if(eyelightState==1){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2);
    eyelightState=0;   
  } 
  
  tData[g++]=id;  //ID
  tData[g++]=times/100;//持续时间
  tData[g++]=8;//色块数量
  switch(petal1){
    tData[g++]=1;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }
  switch(petal2){
    tData[g++]=2;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }  
  switch(petal3){
    tData[g++]=4;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }
  switch(petal4){
    tData[g++]=8;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }
  switch(petal5){
    tData[g++]=16;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }
  switch(petal6){
    tData[g++]=32;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }
  switch(petal7){
    tData[g++]=64;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }
  switch(petal8){
    tData[g++]=128;
    case 1:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=0;
      break;
    case 2:
      tData[g++]=255;
      tData[g++]=128;
      tData[g++]=0;
      break;
    case 3:
      tData[g++]=255;
      tData[g++]=240;
      tData[g++]=0;
      break;
    case 4:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=0;
      break;
    case 5:
      tData[g++]=0;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 6:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=255;
      break;   
    case 7:
      tData[g++]=255;
      tData[g++]=0;
      tData[g++]=255;
      break;  
    case 8:
      tData[g++]=255;
      tData[g++]=255;
      tData[g++]=255;
      break;
    case 9:
      tData[g++]=0;
      tData[g++]=0;
      tData[g++]=0;
      break;                                           
  }          
    tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
  if(tRet==id+0xec){
    ubtEyelightProtocol(0xf4,0x06,0x02,tData2); 
    tRet=ubtEyelightProtocol(0xf4,0x28,0x0b,tData);
 }

 
  
  
  
}
void uKitSensor::setEyelightOff(char id){
  signed char tData[1];
  volatile int State=0;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF4,1,1,0x3,tData);
    delay(5);
  }
 } 
signed char uKitSensor::readHumitureValue(char id, char choice){
  signed char tRet = 0;
  unsigned char buf[6];

  buf[0] = id;//id
  buf[1] = 0x10;//参数
  buf[2] = 0x00;
  buf[3] = 0x00;
  buf[4] = 0x02;
  buf[5] = crc8_itu(&buf[1], buf[2]+2);
  tRet=ubtHumitureProtocol(0x0A,0x05,choice,buf);
  delay(15);
  return tRet;
}
int  *uKitSensor::Rgb2Hsb(unsigned char rgbR,unsigned char rgbG,unsigned char rgbB){
  static int temp[3] ={0,0,0}; 
  int Max,Min=0;
  Max=max(max(rgbR,rgbG),rgbB);
  Min=min(min(rgbR,rgbG),rgbB);
  float hsbB= Max/(float)255.00*100;
  float hsbS= Max == 0 ? 0:(Max-Min)/(float)Max*100;
  float hsbH=0;  
  if (Max == rgbR && rgbG >= rgbB) {
  hsbH = (rgbG - rgbB) * 60.0 / (Max - Min) + 0;
  } else if (Max == rgbR && rgbG < rgbB) {
  hsbH = (rgbG - rgbB) * 60.0 / (Max - Min) + 360;
  } else if (Max == rgbG) {
  hsbH = (rgbB - rgbR) * 60.0 / (Max - Min) + 120;
  } else if (Max == rgbB) {
  hsbH = (rgbR - rgbG) * 60.0 / (Max - Min) + 240;
  }
  temp[0]=hsbH;
  temp[1]=hsbS;
  temp[2]=hsbB;
  
  return temp;
  
  
  
}

unsigned char uKitSensor::readColorRgb(char id,unsigned char RGB){
  unsigned  char tData[1];
  unsigned char Value;
  tData[0]=id;
  volatile int State=0;

  if(State==0){
    TXD(0xE8,1,1,2,tData);  
    delay(10); 
    State=1;
    
  }
    Value=TXD(0xE8,1,1,4,RGB,tData);  
    delay(100);
    return Value;
          
 }
 
unsigned char* uKitSensor::readColorRgb(char id){
  unsigned  char tData[1];
  unsigned char *value1=NULL;  
  static unsigned char ColorState=1;
  tData[0]=id;
  if(ColorState==1){
    ubtColorProtocol(0xe8,0x06,0x02,tData); 
    ColorState=0;  
  }  
  value1=ubtColorProtocol(0xe8,0x06,0x04,tData);   
  delay(80);
  if(value1[0]==id+0xec){ //获取失败，开启颜色传感器
       ubtColorProtocol(0xe8,0x06,0x02,tData); 
       value1=ubtColorProtocol(0xe8,0x06,0x04,tData); 
       
  }
  return value1;
 
        
          
 }
 
void uKitSensor::setColorOff(char id){
  unsigned  char tData[1];
  tData[0]=id;
  ubtColorProtocol(0xe8,0x06,0x03,tData); 
  delay(5);   
 }
bool uKitSensor::readColor(char id,String color){
  unsigned  char tData[1];  
  tData[0]=id;
  unsigned char *ColorRgb=NULL;
  unsigned int *buf=NULL;
  bool state=false;
  unsigned char getid=0;
  ColorRgb=readColorRgb(id);//ColorRgb[0]为R,ColorRgb[1]为G,ColorRgb[2]为B
  delay(5);
  buf=Rgb2Hsb(ColorRgb[0],ColorRgb[1],ColorRgb[2]);
  delay(5);
 
  getid=TXD(0xE8,1,1,2,tData);  
  delay(5);
if(getid==id){  
  if(color!="Black"&& (buf[1]>15 & buf[2]>25)){    
    if(color=="Red" && ((buf[0]>0 & buf[0]<=11)||(buf[0]>=340 & buf[0]<=360))){
      state=true;
      
    } 
   else if(color=="Orange" && ((buf[0]>=18 & buf[0]<=39))){
    state=true;
    }     
   else if(color=="Yellow" && ((buf[0]>=41 & buf[0]<=62))){//yellow
     state=true;
    } 
  else if(color=="Green" && ((buf[0]>=67 & buf[0]<=174))){
      state=true;
    }  
  else if(color=="Cyan" && ((buf[0]>=175 & buf[0]<=193))){
    state=true;
  } 
  else if(color=="Blue" && ((buf[0]>194 & buf[0]<=255))){
    state=true;
  }  
   else if(color=="Purple" && ((buf[0]>=256 & buf[0]<=337))){
     state=true;
   }

 }
  else if(color=="White" && buf[0]<20 && (buf[1]<=7) &&buf[2]>=80){
    state=true;
  }
  else if(color=="Black"  &&( buf[2]<=25)){
    state=1;
  }
  else if(color=="Gray" && buf[0]>80 & buf[1]<=15 & (buf[2]>=30)&&(buf[1]<buf[2])){
    state=true;
  } 
    else{
    state=false;
  }
}

  else{
    state=false;
  }
   
    delay(100);
    return state;
   
  
}
 
void uKitSensor::setAllSensorOff(){
  //setEyelightOff(0);
  setEyelightAllPetals(0,0,0,0);
  setColorOff(0);
}


unsigned char uKitSensor::readButtonValue(char id){
  unsigned char buf[1] ;
  unsigned short tRet=0;
  static unsigned char ButtonState=1;
  buf[0]=id;
  if(ButtonState==1){
    ubtButtonProtocol(0xf7,0x06,0x02,buf);
    ButtonState=0;
    
  }  
  
  tRet=ubtButtonProtocol(0xf7,0x06,0x04,buf);
  if(tRet==id+0xec){
    ubtButtonProtocol(0xf7,0x06,0x02,buf);
    tRet=ubtButtonProtocol(0xf7,0x06,0x04,buf);
} 
    delay(2);

    return tRet;   
}

unsigned long uKitSensor::getButtonVersion(char id){
  unsigned long tRet = 0;
  unsigned char buf[1];
  buf[0]=id;
  tRet=ubtButtonVersionProtocol(0xf7,0x06,0x07,buf);
  delay(5);     
  return tRet;

}

unsigned long uKitSensor::getSensorVersion(char id,unsigned char sensor){
  unsigned long versions=0;
  switch(sensor){
    case 1://舵机
      versions=0;
      break;
    case 2://电机
      versions=0;
      break;
    case 3://红外
      versions=0;
      break;
    case 4://超声波
      versions=0;
      break;
    case 5://眼灯
     versions=0;
      break;
    case 6://触碰
      versions=getButtonVersion(id);
      break;
    case 7://亮度
      versions=0;
      break;
    case 8://声音
      versions=0;
      break;
    case 9://温湿度
      versions=0;   
      break;
    case 10://颜色
      versions=0;
      break;          
  }
  return versions;
    
}
unsigned char uKitSensor::setButtonUpdate(char id){
  unsigned char tRet = 0;
  unsigned char buf[1];
  buf[0]=id;
  tRet=ubtButtonProtocol(0xf7,0x06,0x10,buf);
  delay(5);     
  return tRet;

}

unsigned char uKitSensor::setSensorUpdate(char id,unsigned char sensor){
  unsigned char tRet=0;
  switch(sensor){
    case 1://舵机
      tRet=0;
      break;
    case 2://电机
      tRet=0;
      break;
    case 3://红外
      tRet=0;
      break;
    case 4://超声波
      tRet=0;
      break;
    case 5://眼灯
     tRet=0;
      break;
    case 6://触碰
      tRet=setButtonUpdate(id);
      break;
    case 7://亮度
      tRet=0;
      break;
    case 8://声音
      tRet=0;
      break;
    case 9://温湿度
      tRet=0;   
      break;
    case 10://颜色
      tRet=0;
      break;          
  }
  return tRet;
    
}
unsigned char uKitSensor::setButtonUpdating(char id,unsigned int frame,unsigned int frameTotal,unsigned char *data){
  unsigned char tRet = 0,g=0;
  unsigned char buf[90]={0};
  
  cm_t ubt_cm;
  volatile p_cm_t spi_crc32;
  spi_crc32 = &ubt_cm;
  memset(spi_crc32, 0, sizeof(cm_t));
  crc32_pack_init(spi_crc32);
  
  buf[g++]=id;
  buf[g++]=(uint8_t)(frame);
  buf[g++]=(uint8_t)(frame>>8);
  for(int i=0;i<64;i++){
    buf[g++]=data[i];  
  }
  crc32_pack(spi_crc32,data,64);
  
  if(frame==frameTotal){
    crc32 = crc32_pack_end(spi_crc32, 0, 0);
  }
  tRet=ubtButtonUpdateProtocol(0xf7,g+5,0x11,buf); 
  delay(5);   
  return tRet; 
  

}

unsigned char uKitSensor::setSensorUpdating(char id,unsigned int frame,unsigned int frameTotal,unsigned char *data,unsigned char sensor){
  unsigned char tRet=0;
  switch(sensor){
    case 1://舵机
      tRet=0;
      break;
    case 2://电机
      tRet=0;
      break;
    case 3://红外
      tRet=0;
      break;
    case 4://超声波
      tRet=0;
      break;
    case 5://眼灯
     tRet=0;
      break;
    case 6://触碰
      tRet=setButtonUpdating(id,frame,frameTotal,data);
      break;
    case 7://亮度
      tRet=0;
      break;
    case 8://声音
      tRet=0;
      break;
    case 9://温湿度
      tRet=0;   
      break;
    case 10://颜色
      tRet=0;
      break;          
  }
  return tRet;
    
}
unsigned char uKitSensor::setButtonUpdated(char id,unsigned int frame){
  unsigned char tRet = 0,g=0;
  unsigned char buf[90];
 
  buf[g++]=id;  
  buf[g++]=(uint8_t)(frame);
  buf[g++]=(uint8_t)(frame>>8); 
  buf[g++]=(uint8_t)crc32;
  buf[g++]=(uint8_t)(crc32>>8);
  buf[g++]=(uint8_t)(crc32>>16);
  buf[g++]=(uint8_t)(crc32>>24);    
  for(uint8_t i=4;i<64;i++){
    buf[g++]=0;
  } 
  tRet=ubtButtonProtocol(0xf7,g+5,0x12,buf);
  delay(5);     
  return tRet;

}

unsigned char uKitSensor::setSensorUpdated(char id,unsigned int frame,unsigned char sensor){
  unsigned char tRet=0;
  switch(sensor){
    case 1://舵机
      tRet=0;
      break;
    case 2://电机
      tRet=0;
      break;
    case 3://红外
      tRet=0;
      break;
    case 4://超声波
      tRet=0;
      break;
    case 5://眼灯
     tRet=0;
      break;
    case 6://触碰
      tRet=setButtonUpdated(id,frame);
      break;
    case 7://亮度
      tRet=0;
      break;
    case 8://声音
      tRet=0;
      break;
    case 9://温湿度
      tRet=0;   
      break;
    case 10://颜色
      tRet=0;
      break;          
  }
  return tRet;
    
}

unsigned short uKitSensor::readUltrasonicDistance(char id){//超声波传感器
  unsigned char buf[1] ;
  unsigned short tRet=0;
  static unsigned char UltrasonicState=1;
  buf[0]=id;
  if(UltrasonicState==1){
    ubtUltrasonicProtocol(0xF5,0x06,0x02,buf);
    UltrasonicState=0;
    
  }  
  
  tRet=ubtUltrasonicProtocol(0xF5,0x06,0x04,buf);
  if(tRet==id+0xec){
    ubtUltrasonicProtocol(0xF5,0x06,0x02,buf);
    tRet=ubtUltrasonicProtocol(0xF5,0x06,0x04,buf);
} 
   
    tRet/=10;
    delay(30);

    return tRet; 
    

    
 
}
unsigned char uKitSensor::setUltrasonicRgbled(char id,unsigned char red,unsigned char green,unsigned char blue ){
  unsigned char buf[8] ;
  unsigned short tRet=0;

  buf[0]=id;
  buf[1]=red;
  buf[2]=green;
  buf[3]=blue;
  buf[4]=0x01;
  buf[5]=0x00;
  buf[6] = (0xffff & 0xFF00) >> 8;
  buf[7] = 0xffff & 0x00FF;

  tRet=ubtUltrasonicProtocol(0xF5,0x0D,0x08,buf);
 
  return tRet; 
    
    
}
unsigned char uKitSensor::setUltrasonicRgbledOff(char id){
  unsigned char buf[8] ;
  unsigned short tRet=0;

  buf[0]=id;
  buf[1]=0x00;
  buf[2]=0x00;
  buf[3]=0x00;
  buf[4]=0x00;
  buf[5]=0x00;
  buf[6] = (0x0000 & 0xFF00) >> 8;
  buf[7] = 0x0000 & 0x00FF;

  tRet=ubtUltrasonicProtocol(0xF5,0x0D,0x08,buf);
 
  return tRet; 
    
    
}
void uKitSensor::setNixieTubeFull(char id,uint8_t tpye,uint8_t method,uint8_t frequency,uint8_t times,uint8_t start,uint8_t ends){
  unsigned char tData[1]; 
  volatile int State=0;
  tData[0]=id;
  if(State==0){
    State=TXD(0xF6,1,1,0x02,tData);  
    delay(5);
  }
  unsigned char xData[17];
  xData[0]=id;
  xData[1]=tpye;
  xData[2]=(uint8_t)method>>8;
  xData[3]=(uint8_t)method;
  xData[4]=frequency;
  xData[5]=(uint8_t)times>>24;  
  xData[6]=(uint8_t)times>>16;
  xData[7]=(uint8_t)times>>8;
  xData[8]=times;  
  xData[9]=(uint8_t)start>>24;
  xData[10]=(uint8_t)start>>16;
  xData[11]=(uint8_t)start>>8;
  xData[12]=start;  
  xData[13]=(uint8_t)ends>>24;
  xData[14]=(uint8_t)ends>>16;
  xData[15]=(uint8_t)ends>>8;
  xData[16]=ends; 
  State=TXD(0xF6,1,17,0x04,xData); 
  delay(5);
}
void uKitSensor::setNixieTube(char id,float number){
  
  unsigned char tData[1];
  uint16_t method;
  uint32_t numbers;
  volatile int State=0;
  numbers=number;
  if(numbers-number==0)
  {
    if(number<10 &number>=0)
      method=0x08;
    else if(number>=10 & number<100)
      method=0x0c;
    else if(number>=100 & number<1000)
      method=0x0e;
    else if(number>=1000 & number<10000)
      method=0x0f; 
   
  }
  else{
     if(numbers<10 &numbers>=0)
     {
        method=0x4c;
        number=number*10;
     }
    else if(numbers>=10 & numbers<100)
    {
      method=0x4e;
      number=number*10;
    }
    else if(numbers>=100 & numbers<1000)
    {
      method=0x4f;
      number=number*10;
    }
    
  }
  
  tData[0]=id;
  if(State==0){
    State=TXD(0xF6,1,1,0x02,tData);  
    delay(5);
  }

  unsigned char xData[17];
  xData[0]=id;
  xData[1]=0;
  xData[2]=method>>8;
  xData[3]=method;
  xData[4]=0;
  xData[5]=0>>24;  
  xData[6]=0>>16;
  xData[7]=0>>8;
  xData[8]=0;  
  xData[9]=(uint32_t)number>>24;
  xData[10]=(uint32_t)number>>16;
  xData[11]=(uint32_t)number>>8;
  xData[12]=(uint32_t)number;  
  xData[13]=0>>24;
  xData[14]=0>>16;
  xData[15]=0>>8;
  xData[16]=0; 
  TXD(0xF6,1,17,0x04,xData); 
  delay(5);
}
