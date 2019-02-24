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

void loop() {
	int f;
	int faders[16];
	char buffer[50];

	Faders::Read(faders);

	for (f = 0; f < 16; f++) {
		sprintf(buffer, "%u: %u", f, faders[f]);
		Serial.println(buffer);
	}

  if (faders[14] > 512) {
		Motors::Set(BANK0,UP,STOP,STOP,STOP);
    Serial.println("up");
  } else {
		Motors::Set(BANK0,DOWN,STOP,STOP,STOP);
    Serial.println("down");
  }

	delay(250);
}
