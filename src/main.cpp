#include <Arduino.h>
#include "faders.h"
#include "motors.h"
#include "stdlib.h"

using namespace Faders;
using namespace Motors;

void setup() {
	Serial.begin(38400);
	analogReference(EXTERNAL);

	Faders::Setup();
  Motors::Setup();
}

int braking[16] = { 
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0
};

const int BRAKE_TIME = 5;

void loop() {
	int f;
	int faders[16];
	char buffer[50];

	Faders::Read(faders);

	for (f = 0; f < 16; f++) {
		sprintf(buffer, "%u: %u", f, faders[f]);
		Serial.println(buffer);
	}

	int target = faders[14];

  if (faders[0] > target + 27) {
		Motors::Set(BANK0,DOWN,STOP,STOP,STOP);
		braking[0] = BRAKE_TIME;
  } else if (faders[0] < target - 27) {
		Motors::Set(BANK0,UP,STOP,STOP,STOP);
		braking[0] = BRAKE_TIME;
  } else {
		if (braking[0]-- > 0) {
			Motors::Set(BANK0,BRAKE,STOP,STOP,STOP);	
		} else {
			Motors::Set(BANK0,STOP,STOP,STOP,STOP);
		}
	}

	// delay(250);
}
