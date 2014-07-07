#ifndef H_GAME
#define H_GAME

#define NUM_LIGHTS 4
#define PATTERN_LENGTH 100
#define ERROR_TONE_LENGTH 1000
#define CORRECT_TONE_LENGTH 100
#define ERROR_TONE 2500
#define CORRECT_TONE 800

#include <Arduino.h>
#include "Light.h"
#include "Led.h"
#include "Piezo.h"
#include "Button.h"
#include "Listener.h"
#include "GameButtonListener.h"

class Game {
	private:
		Piezo* piezo;
		Light* lights[NUM_LIGHTS];
		byte pattern[100];
		int turn;
		int inputTurn;

		boolean checkInput();
		void addLight(int, int, int);
		void expandPattern();
		boolean turnEnded();
	public:
		Game();
		Piezo* getPiezo();
		void reset();
		void showPattern();
		void showLight(int);
		void start();
		void restart();
		void nextTurn();
		void processButtonPress(int);
		void updateButtons();
		void run();
};

#endif