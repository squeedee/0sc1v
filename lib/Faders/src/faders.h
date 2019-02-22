#include "Arduino.h"

const int FSEL0 = 22;
const int FSEL1 = 23;

namespace Faders {
	void Setup();

	void SetBank(int bank);

	void Read(int faders[16]);
}