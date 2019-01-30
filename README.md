# uKit Explore Library v1.1.3
```
git clone git@10.10.1.34:explore/explorer-library.git

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
#### V1.1.3更新说明
1. 加入开机获取设备信息


#### V1.1.2更新说明
1. 修复了初次打开串口时，读取设备信息提示有时缺少的问题
2. 修复打印四个颜色传感器【B】值（仅连接三个颜色传感器）时，未连接的传感器ID打印值不为0的问题
3. 修复了频繁打印串口时，开始的几个数据会乱码的问题

#### V1.1.1更新说明
1. 修复初次打开串口时，读取设备信息提示有时缺少
2. 修复接入两个颜色传感器时只有一个可以使用
3. 调整了一些翻译问题

#### V1.1.0更新说明
1. 修复长时间打印颜色传感器会读取不出来的问题
2. 解决颜色传感器多次读取r值时，有时获取的数值为0的问题
3. 增加英文库，uKitExploreEn.h/uKitExplore2En.h
4. 修复ID获取声音传感器为电机的BUG
5. 优化频繁打印串口时，开始的几个数据会乱码的情况


#### V1.0.9更新说明
1. 开机获取ID按照设备类型排序
2. 优化颜色传感器读取，修复颜色传感器多次读取r值时，有时获取的数值为0的问题
3. 亮度传感器最大值设定在4000
4. 新增复位关闭所有设备
5. 加入陀螺仪姿态融合获取

#### V1.0.8更新说明
1. 优化颜色识别算法
2. 进一步优化Json解析库
3. 亮度传感器最大值设定在4000
4. 优化灰度传感器识别灵敏度

#### V1.0.7更新说明
1. 温湿度传感器读取数据改为四舍五入，减小误差
2. 加入RGB转HSB算法，优化颜色识别
3. 修改ID输入小数、中文等均能提示
4. 加入json解析库并适配
5. 优化了灯瓣的逻辑和操作，解决不同嵌入式版本时间问题
6. 修改了一些传感器名称不统一的问题

#### V1.0.6更新说明
1. 修复了获取ID字符缺漏的问题
2. 修复了颜色传感器检测颜色问题，并支持10种uKit颜色识别
3. 增加uKit Explore 2.0主控支持
4. 加入眼灯灯瓣功能
5. 修复陀螺仪读取问题

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
