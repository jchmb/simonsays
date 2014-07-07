#ifndef H_GAME_BUTTON_LISTENER
#define H_GAME_BUTTON_LISTENER 1

#include "Listener.h"
#include "Event.h"
#include "ButtonEvent.h"
#include "Game.h"

class Game;

class GameButtonListener : Listener {
	private:
		Game* game;
		int index;
	public:
		GameButtonListener(Game*, int);
		void process(Event*);
};

#endif