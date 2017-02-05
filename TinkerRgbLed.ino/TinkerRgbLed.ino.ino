#define TINKER_UNO_SHIELD
#define TINKER_RGB_LED

#include "tinkerlib.h"

TinkerRgbLed maRgbLed(D6,D5,D3); //définition

void setup(){}
void loop(){
  for(int i=0;i<256;i++){
     maRgbLed.on(i, (128-i)%256, (128+i)%256);    
     delay(20);
  }  
}


