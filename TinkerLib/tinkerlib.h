#include "Arduino.h"

#ifdef TINKER_UNO_SHIELD

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

#endif

#ifdef TINKER_BUTTON
	class TinkerButton{
   		private:
  			int _p = 0;

	    public:
	      	TinkerButton(int p){
		    	_p = p;
		    	pinMode(p, INPUT);
		    }

		    int status(void){
		    	return digitalRead(_p);
		    }
	  };
#endif

#ifdef TINKER_DIGI_TEMP
	#include <OneWire.h>
	#include <DallasTemperature.h>

	#define ONE_WIRE_BUS 0

	class TinkerDigiTemp{
   		private:
  			int _p = 0;
  	 		OneWire *dsWire=NULL;
			DallasTemperature *ds=NULL;

	    public:
	      	TinkerDigiTemp(int p){
		    	_p = p;
		     	dsWire = new OneWire(p);
				ds = new DallasTemperature(dsWire);
				ds->begin();
		    }
		    ~TinkerDigiTemp(){
		    	delete dsWire;
		    	delete ds;
		    }

		    float tempC(void){
		    	ds->requestTemperatures();
		    	return ds->getTempCByIndex(0);		    	
		    }

		    float tempC(uint8_t index){
		    	ds->requestTemperatures();
		    	return ds->getTempCByIndex(index);		    	
		    }
	  };
#endif

#ifdef TINKER_LDR
	class TinkerLdr{
   		private:
  			int _p = 0;
  			float _v = 5.0;

	    public:
	      	TinkerLdr(int p){
		    	_p = p;
		    	pinMode(p, INPUT);
		    }

		    float value(void){
		    	return analogRead(_p)*_v/1024;
		    }

		    void setRef(float ref){
		    	if(ref <= 0)
		    		return;
		    	_v = ref;
		    }
	  };
#endif

#ifdef TINKER_POT
	class TinkerPot{
   		private:
  			int _p = 0;
  			float _v = 5.0;

	    public:
	      	TinkerPot(int p){
		    	_p = p;
		    	pinMode(p, INPUT);
		    }

		    float value(void){
		    	return analogRead(_p)*_v/1024;
		    }

			uint8_t relative(void){
				return analogRead(_p)/4;
			}		    

		    void setRef(float ref){
		    	if(ref <= 0)
		    		return;
		    	_v = ref;
		    }
	  };
#endif

#ifdef TINKER_LV_RELAY
	class TinkerLvRelay{
   		private:
  			int _p = 0;

	    public:
	      	TinkerLvRelay(int p){
		    	_p = p;
		    	pinMode(p, OUTPUT);
		    }

		    void s2(void){
		    	digitalWrite(_p, HIGH);
		    }   

		    void s1(void){
		    	digitalWrite(_p, LOW);
		    }		    
	  };
#endif

#ifdef TINKER_LED
  
  class TinkerLed{
  	private:
  		int _p = 0;

    public:
      	TinkerLed(int p){
	    	_p = p;
	    	pinMode(p, OUTPUT);
	    }

	    void on(void){
	    	digitalWrite(_p, HIGH);
	    }   

	    void off(void){
	    	digitalWrite(_p, LOW);
	    }

	    void on(int val){
	    	if(val>255)
	    		val = 255;
	    	if(val<0)
	    		val = 0;
	    	analogWrite(_p,val);
	    }
  };

#endif

#ifdef TINKER_RGB_LED
  
  class TinkerRgbLed{
  	private:
  		int _rp = 0;
  		int _gp = 0;
  		int _bp = 0;

    public:
      	TinkerRgbLed(int rp, int gp, int bp){
	    	_rp = rp;
	    	_gp = gp;
	    	_bp = bp;
	    	pinMode(rp, OUTPUT);
	    	pinMode(gp, OUTPUT);
	    	pinMode(bp, OUTPUT);
	    }

	    void on(void){
	    	digitalWrite(_rp, HIGH);
	    	digitalWrite(_gp, HIGH);
	    	digitalWrite(_bp, HIGH);
	    }   

	    void off(void){
	    	digitalWrite(_rp, LOW);
	    	digitalWrite(_gp, LOW);
	    	digitalWrite(_bp, LOW);
	    }

	    void on(int rv, int gv, int bv){
	    	if(rv>255) rv = 255;
	    	if(rv<0)  rv = 0;
	    	if(gv>255) gv = 255;
	    	if(gv<0)  gv = 0;
	    	if(bv>255) bv = 255;
	    	if(bv<0)  bv = 0;

	    	analogWrite(_rp, rv);
	    	analogWrite(_gp, gv);
	    	analogWrite(_bp, bv);
	    }
  };

#endif
