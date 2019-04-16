/*
 File : DisplayDevice7Seg4094.cpp
 Version : 1.0
 Date : 05/03/2019
 Project : Systel Equino 74HC4094 Shift Register 7 Segments Driver Board Display Arduino Library
 Author : Daniel Valentin - dtvalentin@gmail.com

 */
#include <avr/pgmspace.h>
#include <Arduino.h>
#include <stdio.h>
#include <DisplayDevice.h>
#include "DisplayDevice7Seg.h"
// Constructor
DisplayDevice7Seg4094::DisplayDevice7Seg4094() {

}

void DisplayDevice7Seg4094::start(uint8_t enabled_PIN, uint8_t clock_PIN,
		uint8_t data_PIN, uint8_t latch_PIN, uint8_t digits) {
#if(DEBUG_LEVEL >= 2)
		DBG_PRINTLN_LEVEL("4094 Shift Register Display Device Driver Started (PINS: " + String(enabled_PIN) + 
		", " + String(clock_PIN) +
		", " + String(data_PIN) +
		", " + String(strobe_PIN) +
		", Lenght: " + String(digits) + ")...");
	#endif

	len = digits;
	enabledPin = enabled_PIN;
	clockPin = clock_PIN;
	dataPin = data_PIN;
	latchPin = latch_PIN;
	setup();
	clear();
}

int DisplayDevice7Seg4094::getCols() {
	return len;
}

int DisplayDevice7Seg4094::getRows() {
	return 1;
}

void DisplayDevice7Seg4094::clear(void) {
	digitalWrite(enabledPin, LOW);
	for (int i = 0; i < len; i++) {
		sendChar(32, false);
	}

	if (getEnable()) {
		digitalWrite(enabledPin, HIGH);
	}
}

void DisplayDevice7Seg4094::print(char* format, int size, ...) {
	char record[size];
	va_list args;
	va_start(args, format);
	vsnprintf(record, size, format, args);
	va_end(args);
	print(record);
}

void DisplayDevice7Seg4094::print(char *data) {
	digitalWrite(enabledPin, LOW);
	int size = strlen(data);
	char buffer[size];
	int i = 0;
	while (*data != '\0') {
		buffer[i++] = (char) *data++;
	}

	boolean point = false;
	int shifts = 0;
	for (int j = (size - 1); j >= 0; j--) {
		if ((char) buffer[j] == '.') {
			point = true;
		} else {
			sendChar((char) buffer[j], point);
			point = false;
			shifts++;
		}
	}

	for (int k = 0; k <= (len - shifts) - 1; k++) {
		sendChar(32, false);
	}

	if (getEnable()) {
		digitalWrite(enabledPin, HIGH);
	}

#if(DEBUG_LEVEL >= 4)
		String log =  "";
		for(int j = 0; j < len; j++ ){
			log = log + (char)buffer[j];
		}
		DBG_PRINTLN_LEVEL("Display DATA ->" + log);
	#endif	
}

void DisplayDevice7Seg4094::sendChar(char ch, boolean pt) {
	if (ch >= 32 && ch <= 122) {
		ch = (ch - 32);
	} else {
		ch = 32;
	}
	uint8_t value = (uint8_t) pgm_read_byte(&charset[(uint8_t )ch]);
	if (pt) {
		value = value | 64;
	}
	sendBits(value);
}

void DisplayDevice7Seg4094::sendBits(uint8_t value) {
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, value);
	digitalWrite(latchPin, HIGH);
}

void DisplayDevice7Seg4094::setup(void) {
	pinMode(enabledPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	pinMode(latchPin, OUTPUT);

	digitalWrite(enabledPin, LOW);
	digitalWrite(clockPin, LOW);
	digitalWrite(dataPin, LOW);
	digitalWrite(latchPin, LOW);
}
