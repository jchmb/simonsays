#ifndef H_BUTTON
#define H_BUTTON 1

#include <Arduino.h>
#include "Listener.h"
#include "Event.h"
#include "ButtonEvent.h"

class Button {
	private:
		boolean pressed;
		int pin;
		Listener* listener;
	public:
		Button(int);
		void update();
		boolean isBeingPressed();
		void setListener(Listener*);
		void fireEvent(int);
};

#endif