/*
	File  : Keypad3k4i.ino
	Version : 1.0
	Date  : 12/07/2016
	Project : Systel Babuino 3 Key 4 Input Keypad Support Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
	Keypad Device:
    ROW 0 connect to digital in 7	//	ATMEGA_8 PIN 13
    COL 0 connect to digital in 8	//	ATMEGA_8 PIN 14
    COL 1 connect to digital in 9	//	ATMEGA_8 PIN 15
    COL 2 connect to digital in 10	//	ATMEGA_8 PIN 16
	
	
*/
#include <Arduino.h>
#include <Keypad3k4i.h>

Keypad3k4i keypad;

void setup() {
	Serial.begin(9600);
	keypad.start();
}

void loop() {
	char key = keypad.read();
	if(key){
		Serial.print("\tKey Code-> ");
		Serial.println(key);
	}
	delay(100);
}			