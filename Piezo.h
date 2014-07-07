#ifndef H_PIEZO
#define H_PIEZO 1

#include <Arduino.h>

class Piezo {
	private:
		int pin;
	public:
		Piezo(int);
		void playTone(int, int);
};

#endif