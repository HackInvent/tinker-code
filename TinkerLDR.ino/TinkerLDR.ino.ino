#define TINKER_UNO_SHIELD
#define TINKER_LDR
#define TINKER_LED

#include "tinkerlib.h"

TinkerLdr maLdr(A0);        //définition de la LDR
TinkerLed maLed(D3);        //définition de la LED

void setup(){}
void loop(){
  if(maLdr.value()<2){
     maLed.off();        //allumer la LED
  }else{
     maLed.on();       //eteindre la LED
  }
  delay(25);            //une petite temporisation
}

