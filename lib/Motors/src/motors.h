#include "Arduino.h"

namespace Motors {

    // Exclusive Bank selects - these are for reference, the code is optimized so don't change them
    const int BANK0 = 18;
    const int BANK1 = 19;
    const int BANK2 = 20;
    const int BANK3 = 21;

    // motor direction selects - these are for reference, the code is optimized so don't change them
    const int M0_A = 0;
    const int M0_B = 1;

    const int M1_A = 2;
    const int M1_B = 3;

    const int M2_A = 4;
    const int M2_B = 5;

    const int M3_A = 6;
    const int M3_B = 7;

    const int RESET = 8;

    const int STOP = B00;
    const int UP = B01;
    const int DOWN = B10;
    const int BRAKE = B11;

	void Setup();
    void Set(int bank, int m0, int m1, int m2, int m3);
}