/*
 File  : Led.CPP
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino Led Device Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#include "Led.h"

#include <stdint.h>

uint8_t Led::ledids = 1;

Led::Led() {
	id = Led::ledids++;
}

void Led::start(uint8_t setup_PIN) {
	setupPin = setup_PIN;
	setup();
#if(DEBUG_LEVEL >= 2)
		DBG_PRINT_LEVEL("\tLed Device Driver ");
		DBG_PRINT_LEVEL(id);
		DBG_PRINT_LEVEL(" Started (PIN: ");
		DBG_PRINT_LEVEL(setupPin);
		DBG_PRINTLN_LEVEL(" )...");
	#endif
}

int Led::getId() {
	return id;
}

void Led::write(State state) {
	digitalWrite(setupPin, state);
}

State Led::read() {
	return State(digitalRead(setupPin));
}

void Led::setup(void) {
	// Modo
	pinMode(setupPin, OUTPUT);

	// Preset
	digitalWrite(setupPin, STATE_OFF);
}

