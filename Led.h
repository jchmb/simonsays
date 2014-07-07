#ifndef H_LED
#define H_LED 1

#include <Arduino.h>

class Led {
	private:
		int pin;
	public:
		Led(int);
		void setLight(boolean);
};

#endif