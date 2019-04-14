
/**
 * ovo-arduino Main File
 *
 * @category ovo-arduino
 * @package ovo.cpp
 * @copyright Copyright (c) 2019 EEENeko (https://github.com/eeeneko)
 * @license GNU General Public License 3.0
 * @version 0.0.1
 */


#ifndef _OVO_H
#define _OVO_H


/**
 * Like set Timeout in JS
 *
 * @Author yimian
 * @param auto function (allow Lambda)
 * @param int millisecond to dealy
 * @return void
 */
void setTimeout(auto function,const int delay)
{
    static bool on = 1;
    if(on == 1){
        static unsigned long startTime = millis(); 

        if(millis() - startTime > delay){
            function();
            on == 0;
        }
    }
}

/**
 * Like set Interval in JS
 *
 * @Author yimian
 * @param auto function (allow Lambda)
 * @param int millisecond of interval
 * @return void
 */
void setInterval(auto function, const int delay)
{
    static unsigned long startTime = millis(); 

    if(millis() - startTime > delay){
        function();
        startTime = millis();
    }
}


/**
 * Switch between function1 and function2 for delay1 and delay2
 *
 * @Author yimian
 * @param auto function1 (allow Lambda)
 * @param auto function2 (allow Lambda)
 * @param int millisecond of interval
 * @param int millisecond of interval
 * @return void
 */
void setSwitch(auto function1, auto function2, const int delay1, const int delay2)
{
    static unsigned long startTime = millis(); 

    if(millis() - startTime < delay1){
        function1();
    }else if(millis() - startTime >= delay1 && millis() - startTime < delay1 + delay2){
        function2();
    }else if(millis() - startTime >= delay1 + delay2){
        startTime = millis();
    }
}


/**
 * Make direct voltage change to gradually change
 *
 * @author yimian
 * @category ovo
 * @package ovo
 */
class slowWrite
{
    public:
        inline void set(int t_pin, unsigned int t_delay){
            pin = t_pin;
            delay = t_delay;
        };
        inline void high(){
            startTime = millis();
            state = 1;
        };
        inline void low(){
            startTime = millis();
            state = 0;
        };
        inline void run(){
            if(state == 1 && millis() - startTime < delay){
                analogWrite(pin, ((millis() - startTime) * 255 / delay));Serial.println(((millis() - startTime) * 255 / delay));
            }else if(state == 0 && millis() - startTime < delay){
                analogWrite(pin, 255-((millis() - startTime) * 255 / delay));Serial.println(255-((millis() - startTime) * 255 / delay));
            }else{
                state = -1;
            }
        };

    private:
        unsigned long startTime;
        int state;
        int pin;
        unsigned int delay;    
};





#endif