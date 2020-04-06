#ifndef USER_PARAMETERS_H
#define USER_PARAMETERS_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(WIRING)
#include "Wiring.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

#include "breathing.h"

const uint8_t thresholdPressureSelectPin = 4;
const uint8_t bpmSelectPin = 5;
const uint8_t ieRatioSelectPin = 6;
const uint8_t tidalVolumeSelectPin = 7;

const float thresholdPressureIncrement = 0.1;
const float bpmIncrement = 1;
const float ieRatioIncrement = 0.5;
const float tidalVolumeIncrement = 5;

class UserParameter {
	public:
		float value;
		float tmpValue;
    uint8_t selectPin;
   
		UserParameter(const float minValue, const float maxValue, const float increment, const uint8_t pin);
		void updateValue();
		void updateTmpValue(int32_t numEncoderSteps);
		void writeToNV();
		void readFromNV();
		
	private:
	
	float minValue;
	float maxValue;
	float increment;
};

//UserParameter THRESHOLD_PRESSURE(MIN_THRESHOLD_PRESSURE,MAX_THRESHOLD_PRESSURE,thresholdPressureIncrement, thresholdPressureSelectPin);
//UserParameter BPM(MIN_BPM, MAX_BPM, bpmIncrement, bpmSelectPin);
//UserParameter IE_RATIO(MIN_IE_RATIO, MAX_IE_RATIO, ieRatioIncrement, ieRatioSelectPin);
//UserParameter TIDAL_VOLUME(MIN_TIDAL_VOLUME, MAX_TIDAL_VOLUME, tidalVolumeIncrement, tidalVolumeSelectPin);
#endif
