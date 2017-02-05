#define TINKER_UNO_SHIELD
#define TINKER_POT
#define TINKER_LED

#include "tinkerlib.h"

TinkerPot     monRotPot(A0);        
TinkerPot     monSlidePot(A1);     
TinkerLed    maRotLed(D3);     
TinkerLed    maSlideLed(D5); 

void setup(){
  //Serial.begin(9600);
  }
void loop(){
  maRotLed.on(monRotPot.relative());
  maSlideLed.on(monSlidePot.relative());
  //Serial.print("SlidePot:");
  //Serial.println(monRotPot.relative());
  delay(20);        
}


