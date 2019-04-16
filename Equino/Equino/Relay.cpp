/*
 File  : Relay.cpp
 Version : 1.0
 Date  : 28/07/2016
 Project : Systel Babuino Relay State Device Arduino Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#include "Relay.h"

#include <stdint.h>

uint8_t Relay::relayids = 1;

Relay::Relay() {
	id = Relay::relayids++;
}

void Relay::start(uint8_t setup_PIN) {
	setupPin = setup_PIN;
	setup();
#if(DEBUG_LEVEL >= 2)
		DBG_PRINT_LEVEL("\tRelay Device Driver ");
		DBG_PRINT_LEVEL(id);
		DBG_PRINT_LEVEL(" Started (PIN: ");
		DBG_PRINT_LEVEL(setupPin);
		DBG_PRINTLN_LEVEL(" )...");
	#endif
}

int Relay::getId() {
	return id;
}

void Relay::write(State state) {
	digitalWrite(setupPin, state);
}

State Relay::read() {
	return State(digitalRead(setupPin));
}

void Relay::setup(void) {
	// Modo
	pinMode(setupPin, OUTPUT);

	// Preset
	digitalWrite(setupPin, STATE_OFF);
}

