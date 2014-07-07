#ifndef H_LIGHT
#define H_LIGHT 1

#include <Arduino.h>
#include "Button.h"
#include "Led.h"
#include "Piezo.h"

class Light {
	private:
		Piezo* piezo;
		Led* led;
		Button* button;
		int frequency;
	public:
		Light(Piezo*, Led*, Button*, int);
		void setLight(boolean);
		void beep();
		void updateButton();
		void lightUp();
};

#endif