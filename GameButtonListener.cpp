#include "GameButtonListener.h"

GameButtonListener::GameButtonListener(Game* game, int index) {
	this->game = game;
	this->index = index;
}

void GameButtonListener::process(Event* event) {
	ButtonEvent* buttonEvent = (ButtonEvent*) event;

	if (buttonEvent->getType() == BUTTON_PRESSED) {
		this->game->processButtonPress(this->index);
	}
}