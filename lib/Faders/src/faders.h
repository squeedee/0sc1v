#include "Arduino.h"


namespace Faders {
	const int FSEL0 = 22;
	const int FSEL1 = 23;

	// For analog reads
	const int F0 = 0;
	const int F1 = 1;
	const int F2 = 2;
	const int F3 = 3;
	
	void Setup();

	void SetBank(int bank);

	void Read(int faders[16]);
}