#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define D12 12
#define D13 13

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 4
#define A5 5


#ifdef TINKER_UNO_SHIELD
    
#endif

#ifdef TINKER_BUTTON

#endif

#ifdef TINKER_LED
  
  class TinkerLED{
    public void TinkerLED(int port);
    public void on();   
    public void off();  //set the TINKER LED on
  }
  
#endif
