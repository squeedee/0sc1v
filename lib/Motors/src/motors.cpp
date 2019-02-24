#include "Arduino.h"
#include "motors.h"

namespace Motors {
	void Setup() {
		pinMode(BANK0, OUTPUT);
		pinMode(BANK1, OUTPUT);
		pinMode(BANK2, OUTPUT);
		pinMode(BANK3, OUTPUT);

		pinMode(M0_A, OUTPUT);
		pinMode(M0_B, OUTPUT);
		pinMode(M1_A, OUTPUT);
		pinMode(M1_B, OUTPUT);
		pinMode(M2_A, OUTPUT);
		pinMode(M2_B, OUTPUT);
		pinMode(M3_A, OUTPUT);
		pinMode(M3_B, OUTPUT);

        pinMode(RESET, OUTPUT);

        // set clock low
        digitalWrite(BANK0, false);
        digitalWrite(BANK1, false);
        digitalWrite(BANK2, false);
        digitalWrite(BANK3, false);

        // Reset - I have no idea what the timing is for clear but I bet the lag the 
        // digitalWrite introduces will be enough.
        digitalWrite(RESET, true);
        digitalWrite(RESET, false);
        digitalWrite(RESET, true);
	}

    void Set(int bank, int m0, int m1, int m2, int m3) {
        digitalWrite(M0_A, m0 & B01);
        digitalWrite(M0_B, m0 & B10);
        digitalWrite(M1_A, m1 & B01);
        digitalWrite(M1_B, m1 & B10);
        digitalWrite(M2_A, m2 & B01);
        digitalWrite(M2_B, m2 & B10);
        digitalWrite(M3_A, m3 & B01);
        digitalWrite(M3_B, m3 & B10);

        digitalWrite(bank, false);
        digitalWrite(bank, true);
        digitalWrite(bank, false);
    }
}