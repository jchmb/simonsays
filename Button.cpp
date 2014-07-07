#include "Button.h"

Button::Button(int pin) {
	this->pin = pin;
	pinMode(pin, INPUT);
}

void Button::update() {
	if (this->pressed) {
		if (!this->isBeingPressed()) {
			this->pressed = false;
			this->fireEvent(BUTTON_RELEASED);
		}
	} else {
		if (this->isBeingPressed()) {
			this->pressed = true;
			this->fireEvent(BUTTON_PRESSED);
		}
	}
}

boolean Button::isBeingPressed() {
	if (digitalRead(pin) == LOW) {
		return true;
	} else {
		return false;
	}
}

void Button::setListener(Listener* listener) {
	this->listener = listener;
}

void Button::fireEvent(int type) {
	Event* event = (Event*) new ButtonEvent(type);
	this->listener->process(event);
}