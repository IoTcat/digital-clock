#include "ovo.h"
#include "digital-screen.h"




void setup(){
  digital_clock_ini();
}

DigitalClock dig(22);

void loop(){

  dig.core();
  dig.hide();
  dig.show();
 
}

