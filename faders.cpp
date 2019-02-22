#include "Arduino.h"
#include "faders.h"

namespace Faders {

	void Setup() {
		pinMode(FSEL0, OUTPUT);
		pinMode(FSEL1, OUTPUT);
	}

	void SetBank(int bank) {
		digitalWrite(FSEL0, bank & B01);
		digitalWrite(FSEL1, bank & B10);
	}

	void Read(int faders[16]) {
		int b, f;

		for (b = 0; b < 4; b++) {
			SetBank(b); // TODO this might need a sleep
			for (f = 0; f < 4; f++) {
				faders[(f * 4) + b] = analogRead(f);
			}
		}
	}
}