#include <Arduino.h>
#include "Keypad13k7i.h"

Keypad13k7i keypad;

void setup() {
	Serial.begin(9600);
	keypad.start();
}

void loop() {
	char key = keypad.read();
	if (key) {
		Serial.print("\tKey Code-> ");
		Serial.println(key);
	}
	delay(100);
}
