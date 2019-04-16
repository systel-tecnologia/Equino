/*
	File  : Keypad3k4i.ino
	Version : 1.0
	Date  : 12/07/2016
	Project : Systel Babuino 13 Key 7 Input Keypad Support Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
	Keypad Device:
    ROW 0 connect to digital in 7	//	ATMEGA_8 PIN 13
    ROW 1 connect to digital in 13	//	ATMEGA_8 PIN 19
    ROW 2 connect to digital in 12	//	ATMEGA_8 PIN 18
    ROW 3 connect to digital in 10	//	ATMEGA_8 PIN 16
    COL 0 connect to digital in 11	//	ATMEGA_8 PIN 17
    COL 1 connect to digital in 9	//	ATMEGA_8 PIN 15
    COL 2 connect to digital in 8	//	ATMEGA_8 PIN 14
		
*/
#include <Arduino.h>
#include <Keypad13k7i.h>

Keypad13k7i keypad;

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