 1. **去掉**代码开头`//#define DEBUG_MODE`的注释，编译并上传，进入**debug模式**
 2. 检查你的两个数字屏是否**同时**按照0-9的顺序循环跳动。如果出现个别数字是乱码，请检查**译码器到数字屏的线路**。参考：[译码器连法](https://digitalclock.eee.dog/#/instro?id=译码器连法),[译码器电路示意图](https://digitalclock.eee.dog/#/attach?id=译码器电路示意图), [数字屏电路示意图](https://digitalclock.eee.dog/#/attach?id=数字屏电路示意图)
 3. 分别长按两个按钮开关，观察arduino板最左边的板载led是否亮起。如果板载led常亮，请检查你的两个[开关线路](https://digitalclock.eee.dog/#/instro?id=开关电路说明)，保证当开关按下时，输出为高电平。
 4. 如果上述测试均通过，请**重新注释**`#define DEBUG_MODE`，编译并上传
 5. **如果你的问题仍无法解决，请参考下文[Q&A](https://digitalclock.eee.dog/#/qa)**
