#ifndef H_LISTENER
#define H_LISTENER 1

#include "Event.h"

class Listener {
	public:
		virtual void process(Event*);
};

#endif