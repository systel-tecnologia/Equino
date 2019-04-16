#include <Arduino.h>
#include "DisplayDevice7Seg.h"

DisplayDevice7Seg4094 display;

const char* fmt = "%.5d";

void setup() {
	Serial.begin(115200);
	display.start(ENABLE_PIN, CLOCK_PIN, DATA_PIN, LATCH_PIN, 5);
}

void loop() {

	display.print((char*)fmt, 6, 123);
	delay(500);
	display.clear();
	delay(500);
}
