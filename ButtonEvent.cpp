#include "ButtonEvent.h"

ButtonEvent::ButtonEvent(int type) {
	this->type = type;
}

int ButtonEvent::getType() {
	return this->type;
}