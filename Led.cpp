#include "Led.h"

Led::Led(int pin) {
	this->pin = pin;
	pinMode(pin, OUTPUT);
}

void Led::setLight(boolean on) {
	digitalWrite(this->pin, on ? HIGH : LOW);
}