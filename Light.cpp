#include "Light.h"

Light::Light(Piezo* piezo, Led* led, Button* button, int frequency) {
	this->piezo = piezo;
	this->led = led;
	this->button = button;
	this->frequency = frequency;
}

void Light::beep() {
	this->piezo->playTone(this->frequency, 100);
}

void Light::setLight(boolean state) {
	this->led->setLight(state);
}

void Light::updateButton() {
	this->button->update();
}

void Light::lightUp() {
	this->setLight(true);
	this->beep();
	delay(500);
	this->setLight(false);
	delay(500);
}