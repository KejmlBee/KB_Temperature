#ifndef KB_Temperature_h
#define KB_Temperature_h

#include "Arduino.h"

class TemperatureNTC10K
{
	public:
	
		TemperatureNTC10K(uint8_t analog_pin, uint16_t NTC_RES, uint16_t EXT_RES, uint16_t BETA_COEF, float NOM_TEMP, uint16_t ADC_MAX, float IN_VOLTAGE);
		
		void begin();
		float NTC10K(float ntc10kTemperature);
		
	private:
  
		uint8_t		_analog_pin;
		uint16_t	_NTC_RES;
		uint16_t	_EXT_RES;
		uint16_t	_BETA_COEF;
		float		_NOM_TEMP;
		uint16_t	_ADC_MAX;
		float		_IN_VOLTAGE;
		
		float 		_ntc10kTemperature;	
};

class TemperaturePT1000
{
	public:
	
		TemperaturePT1000(uint8_t analog_pin, float VT_FACTOR, float PT1000_OFFSET, uint16_t ADC_MAX, float IN_VOLTAGE);
		
		void begin();
		float PT1000(float pt1000Temperature);
		
	private:
  
		uint8_t		_analog_pin;
		float 		_VT_FACTOR;
		float 		_PT1000_OFFSET;
		uint16_t	_ADC_MAX;
		float		_IN_VOLTAGE;
			
		float 		_pt1000Temperature;	
};

#endif