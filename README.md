# uKit Explore Library v1.0.5
```
git clone git@10.10.1.34:uKit/explorer-library.git

```
Arduino Library for uKit Explore Modules

### How to use:

1. Download the source from the git http://10.10.1.34/uKit-explore/ubtrobot

2. Importing a .zip Library. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library. At the top of the drop down list, select the option to "Add .ZIP Library''.
![Image text](http://10.10.1.245/uKit-explore/Course/blob/master/image/lib.jpg)
3. Open the Arduino Application. (If it's already open, you will need to restart it to see changes.)

4. Click "File-> Examples". Here are some test programs in "uKit Explore->"

### Links
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Drive](http://www.wch.cn/downfile/65)
- [Instructions](http://10.10.1.245/uKit-explore/Course/blob/master/uKit_Explore_Course_CN.pdf)  

### Update
#### V1.0.5更新说明
1. 规范化函数命名方式
2. 若已安装了本程序，安装前加入卸载提示功能
2. 修复和优化了颜色传感器的读取
3. 开放舵机速度，修改底层实现真正的舵机运行时间。（不占用CPU任务）
4. 声音传感器的ADC由0~4069改为0~1023 

#### V1.0.4更新说明：
1. 加入开机获取设备ID功能，烧录新程序后，打开串口会显示当前接入的设备和ID号（重复ID暂时无法检测）。
2. 加入修改ID功能
3. 加入FlexiTimer2库，支持定时器功能。
4. 添加电机pwm调速

#### V1.0.3更新说明：
1. 修复了接入多个RGB传感器打印数据覆盖问题
2. 修复了电机逆时针读速度错误问题
3. 修复了NOC块车型不能动问题
4. 修复了板载按键长按错误问题
5. 超声波读取数据由毫米转给厘米
6. 蜂鸣器的节拍去掉，改为可输入的响亮时间
7. 新增uKitExploreBlockly库，解决Arduino IDE开发和Blockly开发版本不一致互相影响问题。

#### V1.0.2更新说明：
1. 修改了舵机正反转错误问题
2. 增加了声响传感器、光感传感器支持；传感器已全支持
3. 修复舵机回读大于118的问题
4. 舵机轮模式速度改为0~255
5. 修复眼灯模块、陀螺仪、变量不可用问题
6. 修复红外传感器读取数值跳变问题
7. 修复舵机速度不变化问题


   

### Learn more from UBTECH official website: www.ubtrobot.com
