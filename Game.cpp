#include "Game.h"

Game::Game() {
	this->reset();

	this->piezo = new Piezo(A5);

	this->addLight(0, 0, 1);
	this->addLight(1, 8, 5);
	this->addLight(2, 9, 2);
	this->addLight(3, 6, 3);
}

void Game::reset() {
	this->turn = -1;
}

void Game::expandPattern() {
	byte randomIndex = (byte) random(0, 4);
	this->pattern[this->turn] = randomIndex;
}

void Game::nextTurn() {
	this->turn++;
	this->inputTurn = 0;
	this->expandPattern();
	this->showPattern();
}

void Game::addLight(int index, int ledPin, int buttonPin) {
	Light* light;
	Led* led;
	Button* button;
	Listener* listener;

	led = new Led(ledPin);
	button = new Button(buttonPin);
	listener = (Listener*) new GameButtonListener(this, index);
	button->setListener(listener);
	light = new Light(this->piezo, led, button, 1500 + index * 300);

	this->lights[index] = light;
}

void Game::showPattern() {
	for (int i = 0; i <= this->turn; i++) {
		this->showLight(this->pattern[i]);
	}
}

void Game::showLight(int index) {
	Light* light = this->lights[index];
	light->lightUp();
}

void Game::start() {
	this->nextTurn();
}

void Game::restart() {
	this->reset();
	this->start();
}

void Game::updateButtons() {
	for (int i = 0; i < NUM_LIGHTS; i++) {
		this->lights[i]->updateButton();
	}
}

void Game::processButtonPress(int index) {
	this->showLight(index);
	int indexToMatch = this->pattern[this->inputTurn++];
	if (index == indexToMatch) {
		if (this->turnEnded()) {
			/* Correct beep. */
			this->piezo->playTone(CORRECT_TONE, CORRECT_TONE_LENGTH);
			delay(500);
			this->nextTurn();
		}
	} else {
		/* Error beep. */
		this->piezo->playTone(ERROR_TONE, ERROR_TONE_LENGTH);
		delay(500);
		this->restart();
	}
}

boolean Game::turnEnded() {
	return this->inputTurn >= (this->turn + 1);
}

Piezo* Game::getPiezo() {
	return this->piezo;
}