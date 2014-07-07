#ifndef H_DIGIT_LED
#define H_DIGIT_LED 1

#define PART_A 1
#define PART_B 2
#define PART_C 4
#define PART_D 8
#define PART_E 16
#define PART_F 32
#define PART_G 64
#define PART_H 128

#include <Arduino.h>

class DigitLed {
	private:
		int dataPin;
		int clockPin;
		int latchPin;
		byte digit;
		int bits[8];
	public:
		DigitLed(int, int, int);
		void setDigit(byte);
		void setLight(boolean);
		int convertToBits(int);
};

#endif