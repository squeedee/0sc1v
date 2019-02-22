#include <Arduino.h>
#include "faders.h"
#include "stdlib.h"

// lookup is [(b)ank][(f)ader]:  n = b*3 + f
//uint *fader[3][3] = {
//  { 0,0,0,0 },
//  { 0,0,0,0 },
//  { 0,0,0,0 },
//  { 0,0,0,0 }
//}

using namespace Faders;

void setup() {
	Serial.begin(38400);
	analogReference(EXTERNAL);

	Faders::Setup();
	Faders::SetBank(0);
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

	delay(250);
}
