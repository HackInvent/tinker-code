#define TINKER_UNO_SHIELD
#define TINKER_LED

#include "tinkerlib.h"

TinkerLED maLed(D3); //définition de la LED

void setup(){}
void loop(){
  maLed.on();        //allumer la LED
  delay(1000);       //retarder le programme 1sec
  maLed.off();       //eteindre la LED
  delay(1000); 
}
