/*
 File  : Keypad13k7i.cpp
 Version : 1.0
 Date  : 12/07/2016
 Project : Systel Babuino 13 Key 7 Input Keypad Support Arduino Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#include "Keypad13k7i.h"

void Keypad13k7i::start() {
	setup();
#if(DEBUG_LEVEL == 3)
		DBG_PRINTLN_LEVEL("Keypad 13 Keys 7 Inputs started...");
	#endif
}

char Keypad13k7i::read(void) {
	// Verifica Teclas comuns
	char key = numberKeypad.getKey();
	if (!key) {
		key = controlKeypad.getKey();
	}
	return (key);
}

void Keypad13k7i::setup(void) {

}

