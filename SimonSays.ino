#include "Game.h"

Game game;

boolean started = false;

void setup() {
	game.reset();
}

void loop() {
	if (!started) {
		started = true;
		game.start();
	}
	game.updateButtons();
}