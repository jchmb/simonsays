#ifndef H_BUTTON_EVENT
#define H_BUTTON_EVENT 1

#define BUTTON_PRESSED 1
#define BUTTON_RELEASED 2

#include "Event.h"

class ButtonEvent:Event {
	private:
		int type;
	public:
		ButtonEvent(int);
		int getType();
};

#endif