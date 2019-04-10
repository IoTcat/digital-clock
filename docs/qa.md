### 代码编译出现错误找不到`ovo.h`等
答：请保证压缩包中**所有文件**均在一个名为`digital-clock`的文件夹中！！之后通过arduino打开此文件夹中的digital-clock.ino即可。

### 编译错误中出现关键词`auto`
答：请确保你的arduino为**1.8.5**版本！！(下载地址：[win](https://cloud.yimian.xyz/install/arduino/1.8.5/arduino-1.8.5-windows.zip) / [mac](https://cloud.yimian.xyz/install/arduino/1.8.5/arduino-1.8.5-macosx.zip))

### 上传错误`avrdude: ser_open(): can't open device`
答：请在上方栏**工具**中选择指定**端口**。

### 上传错误`avrdude: stk500_recv(): programmer is not responding`
答：此错误由先前对端口的非正常操作引起。请尝试**重启系统**或**更换电脑**解决。

### 数字时钟显示乱码
答：请先检查**译码器与arduino的线路**连接是否正确！！(大部分同学问题都出在这里)<br/>
请务必保证译码器的 A,B,C,D脚(参考：[译码器连法](/#/instro?id=译码器连法),[译码器电路示意图](https://digitalclock.eee.dog/#/attach?id=译码器电路示意图), [数字屏电路示意图](https://digitalclock.eee.dog/#/attach?id=数字屏电路示意图))正确地连接到代码中你自定义的pin脚(默认为9,10,11,12和5,6,7,8)<br/>
使用[debug模式](https://digitalclock.eee.dog/#/debug)排查线路连接问题！

### 暂停键没有反应
答：请使用debug模式，观察按下开关时arduino板载led是否亮。详情见上文[错误排查](https://digitalclock.eee.dog/#/debug)部分。

### 显示屏个位与十位错位
答：两个译码器接反了。换过来即可。
