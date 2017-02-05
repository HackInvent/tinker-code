#define TINKER_UNO_SHIELD
#define TINKER_LV_RELAY
#define TINKER_DIGI_TEMP

#include "tinkerlib.h"

TinkerDigiTemp monCaptTemp(D2); //définition
TinkerLvRelay monRelai(D3);     //définition du relai

void setup(){ 
  delay(1000);
  Serial.begin(9600);
  Serial.print("Température:");
  Serial.println(monCaptTemp.tempC());
  }
void loop(){
  delay(1000);
  if(monCaptTemp.tempC(0)>30.0){
     monRelai.s2();   //active le relai sur S2
  }else{
     monRelai.s1();   //bascule le relai sur S1
  }  
  Serial.print("Température:");
  Serial.println(monCaptTemp.tempC());
}

