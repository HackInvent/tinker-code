#define TINKER_UNO_SHIELD
#define TINKER_LV_RELAY

#include "tinkerlib.h"

TinkerLvRelay monRelai(D0); //définition

void setup(){}
void loop(){
  monRelai.s2();     //active le relai sur S2
  delay(1000);       //retarder le programme 1sec
  monRelai.s1();     //bascule le relai sur S1
  delay(1000);
}


