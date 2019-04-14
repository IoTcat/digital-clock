
/**
 * switch Functions
 *
 * @category digital-clock
 * @package switch.h
 * @copyright Copyright (c) 2019 IoTcat (https://iotcat.me)
 * @license GNU General Public License 3.0
 * @version 0.0.2
 */


#ifndef _SWITCH_H
#define _SWITCH_H

#include "ovo.h"

#ifndef SWI_OFF
#define SWI_OFF 3
#endif

#ifndef SWI_RESET
#define SWI_RESET 4
#endif

#ifndef SWI_DELAY_TIME 1200
#define SWI_DELAY_TIME 1200
#endif

class Switch{

public:

    Switch(unsigned short pin = 3, bool type = HIGH){
        this->_pin = pin;
        this->_type = type;
        this->_isPressed = false;
        this->_status = true;
    }

    void core(){
        check_status();
    }

    bool getStatus(){
        return _status;
    }

    void changeStatus(int state){
        if(state == 15){
            this->_status = true;
            return;
        }
        this->_status = !(this->_status);
    }

    bool isPressed(){
        return _isPressed;
    }

private:
    unsigned short _pin;
    bool _type;
    bool _isPressed;

    bool _status;

    void set_isPressed(){

        if(digitalRead(this->_pin) == this->_type){

            this->_isPressed = true;
        }else{
            this->_isPressed = false;
        }
    }

    void check_status(){

        static bool s_fIsPressed = false;
        set_isPressed();

#ifdef FORCED_SWITCH
        static unsigned int t_t = millis();
        // 检测开关键按下动作
        if(this->_isPressed != s_fIsPressed){

            if(t_t < millis() - SWI_DELAY_TIME ){
                this->_status = !(this->_status);
                t_t = millis();
            }
        }
#else
        // 检测开关键松开动作
        if(this->_isPressed != s_fIsPressed /*&& this->_isPressed != _type*/){

            this->_status = !(this->_status);
            delay(600);
        }
#endif
    }

};




/**
 * switch setup
 *
 * @Author yimian
 * @param void
 * @return void
 */
void switch_ini(){

    pinMode(SWI_OFF, INPUT);
    pinMode(SWI_RESET, INPUT);

}


#endif
