#define TINKER_UNO_SHIELD
#define TINKER_LED

#include "tinkerlib.h" 

TinkerLED maLed(D3); //définition de la LED

void setup(){}
void loop(){
  for(int i=0;i<256;i++){
    maLed.on(i);    //allumer la LED avec intensité i
    delay(10);       //retarder le programme 1sec
  }
  for(int i=255;i>0;i--){
    maLed.on(i);    //allumer la LED avec intensité i
    delay(5);     
  }
}


