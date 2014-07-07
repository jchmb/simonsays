#include "DigitLed.h"

int DigitLed::convertToBits(int digit) {
	switch (digit) {
		case 0:
			return PART_F | PART_G | PART_A | PART_E | PART_C | PART_D;
		case 1:
			return PART_A | PART_C;
		case 2:
			return PART_G | PART_A | PART_B | PART_E | PART_D;
		case 3:
			return PART_G | PART_A | PART_B | PART_C | PART_D;
		case 4:
			return PART_F | PART_B | PART_A | PART_C; 
	}
	return 0x0;
}