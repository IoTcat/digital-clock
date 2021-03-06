
/**
 * digital clock code for EEE116
 *
 * @category digital-clock
 * @package digital-clock.ino
 * @copyright Copyright (c) 2019 IoTcat (https://iotcat.me)
 * @license GNU General Public License 3.0
 * @version 0.0.2
 */


/*** 引入关键库 ****/
#include "ovo.h"

/*** 是否开启debug模式 ****/

//去掉下一行的注释以开启debug模式
//#define DEBUG_MODE

/*** 是否使用备用开关算法 ****/

//!!仅在暂停键不灵敏时考虑本选项!!
//去掉下一行的注释以使用备用开关算法
//#define FORCED_SWITCH


/*** 定义初始参数 ****/

//小组组号
#define GROUP_ID 22 //计时器增大到此值将重新从零开始
                    //例如此处我的组号是22

//时钟变换时间间隔 (毫秒)::如果组号超过30可考虑调小本值
#define INTERVAL_TIME 1000 //默认是1秒

//按下开关后冻结时间 (毫秒)::仅在备用开关模式有效
#define SWI_DELAY_TIME 1200

//pin口 - 接译码器1 (显示个位)
#define DIG_1_1 9   //A
#define DIG_1_2 10  //B
#define DIG_1_3 11  //C
#define DIG_1_4 12  //D

//pin口 - 接译码器2 (显示十位)
#define DIG_2_1 5   //A
#define DIG_2_2 6   //B
#define DIG_2_3 7   //C
#define DIG_2_4 8   //D

//pin口 - 接开关
#define SWI_OFF 3

//pin口 - 接reset键
#define SWI_RESET 4



/*** 引入自定义库 ****/

#include "digital-screen.h"
#include "switch.h"



/*** 运行初始化 ****/

void setup(){

    //时钟显示屏初始化
    digital_clock_ini();
    //开关组件初始化
    switch_ini();
    //初始化串口,方便debug
    Serial.begin(115200);
#ifdef DEBUG_MODE
    //初始化板载led,作为debug的指示灯
    pinMode(LED_BUILTIN, OUTPUT);
#endif
}


/*** 实例化组件 ****/

#ifdef DEBUG_MODE

//时钟显示屏实例化
Debug_DigitalClock clock(GROUP_ID);


#else

//时钟显示屏实例化
DigitalClock clock(GROUP_ID);

#endif

//开关组件实例化
Switch swi(SWI_OFF), reset(SWI_RESET);

/*** 主循环程序 ****/

void loop(){

    /*** 主要控制逻辑 ****/
#ifdef DEBUG_MODE

    //如果reset键或开关键被按下，板载led亮
    if(reset.isPressed() == true || swi.isPressed() == true) {
        digitalWrite(LED_BUILTIN, HIGH);
    }else{
        digitalWrite(LED_BUILTIN, LOW);
    }

#else
    //如果reset键被按下，重置时钟
    if(reset.isPressed() == true) {
      clock.reset();
      swi.changeStatus(15);
      reset.changeStatus(1);
    }

    //如果开关打开，则开始或停止计时
    if(swi.getStatus() == true) clock.show();
    else clock.hide();
#endif

    /*** 守护进程 ****/
    clock.core();
    swi.core();
    reset.core();
 
}

