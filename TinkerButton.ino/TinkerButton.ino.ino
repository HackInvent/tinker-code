#define TINKER_UNO_SHIELD
#define TINKER_BUTTON
#define TINKER_LED

#include "tinkerlib.h"

TinkerButton monBouton(D2); //définition du bouton
TinkerLed maLed(D3);        //définition de la LED

void setup(){}
void loop(){
  if(monBouton.status()==HIGH){
     maLed.on();        //allumer la LED
  }else{
     maLed.off();       //eteindre la LED
  }
  delay(25);            //une petite temporisation
}


