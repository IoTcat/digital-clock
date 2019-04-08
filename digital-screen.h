
/**
 * digital-screen Functions
 *
 * @category digital-screen
 * @package digital-screen.h
 * @copyright Copyright (c) 2019 EEENeko (https://github.com/eeeneko)
 * @license GNU General Public License 2.0
 * @version 0.0.1
 */


#ifndef _DIGITAL_SCREEN_H
#define _DIGITAL_SCREEN_H

#include "ovo.h"


#ifndef DIG_1_1
#define DIG_1_1 9
#endif

#ifndef DIG_1_2
#define DIG_1_2 10
#endif

#ifndef DIG_1_3
#define DIG_1_3 11
#endif

#ifndef DIG_1_4
#define DIG_1_4 12
#endif

#ifndef DIG_2_1
#define DIG_2_1 5
#endif

#ifndef DIG_2_2
#define DIG_2_2 6
#endif

#ifndef DIG_2_3
#define DIG_2_3 7
#endif

#ifndef DIG_2_4
#define DIG_2_4 8
#endif


class DigitalClock{

public:

    DigitalClock(int group = 22){

        this->_group = group;
        _ice = 0;
        _cnt = 0;
    };



    /**
     * control digital screens
     *
     * @Author yimian
     * @param int num # 待显示数字
     * @return void
     */
    inline void digital_show(int num){

        if(num == -1 || _ice == 1){
            digital_show_1(15);
            digital_show_2(15);
            return;
        }

        digital_show_1(num % 10);
        digital_show_2((num / 10) % 10);
    }



    void core(){

        setInterval([&](){
            this->digital_show(this->_cnt % this->_group);
            this->_cnt++;
        }, 1000);
    }

    inline void hide(){
        this->_ice = 1;
    }

    inline void show(){
        this->_ice = 0;
    }

    inline void reset(){
        this->_cnt = 0;
    }

private:

    int _group;
    int _ice;
    unsigned int _cnt;

    /**
     * control digital screen 1
     *
     * @Author yimian
     * @param int num # 待显示数字
     * @return void
     */
    void digital_show_1(int num){

        digitalWrite(DIG_1_1, !!(num & (0x01<<0)));
        digitalWrite(DIG_1_2, !!(num & (0x01<<1)));
        digitalWrite(DIG_1_3, !!(num & (0x01<<2)));
        digitalWrite(DIG_1_4, !!(num & (0x01<<3)));
    }


    /**
     * control digital screen 2
     *
     * @Author yimian
     * @param int num # 待显示数字
     * @return void
     */
    void digital_show_2(int num){

        digitalWrite(DIG_2_1, !!(num & (0x01<<0)));
        digitalWrite(DIG_2_2, !!(num & (0x01<<1)));
        digitalWrite(DIG_2_3, !!(num & (0x01<<2)));
        digitalWrite(DIG_2_4, !!(num & (0x01<<3)));
    }


};




/**
 * digital-clock setup
 *
 * @Author yimian
 * @param void
 * @return void
 */
void digital_clock_ini(){

    pinMode(DIG_1_1, OUTPUT);
    pinMode(DIG_1_2, OUTPUT);
    pinMode(DIG_1_3, OUTPUT);
    pinMode(DIG_1_4, OUTPUT);
    pinMode(DIG_2_1, OUTPUT);
    pinMode(DIG_2_2, OUTPUT);
    pinMode(DIG_2_3, OUTPUT);
    pinMode(DIG_2_4, OUTPUT);

}



#endif
