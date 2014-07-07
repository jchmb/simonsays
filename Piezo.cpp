#include "Piezo.h"

Piezo::Piezo(int pin) {
	this->pin = pin;
	pinMode(pin, OUTPUT);
}

void Piezo::playTone(int tone, int duration) {
	for (long i = 0; i < duration * 1000L; i += tone * 2) {
		digitalWrite(this->pin, HIGH);
		delayMicroseconds(tone);
		digitalWrite(this->pin, LOW);
		delayMicroseconds(tone);
	}
}