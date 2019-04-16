/*
	File  : RTCDs1307.ino
	Version : 1.0
	Date  : 07/11/2016
	Project : Systel Babuino RTC Device DS1307 Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
*/
#include <Arduino.h>
#include <RTClib.h>
#include "TimeDevice.h"

RTCDs1307 clock;

void setup() {
	Serial.begin(9600);
	DateTime dt = DateTime(F(__DATE__), F(__TIME__));
	clock.start();
	clock.setup(dt);
}

void loop() {
	if(Serial){
		DateTime now = clock.now();
		Serial.print("Time Clock: ");
		Serial.print(now.hour(), DEC);
		Serial.print(":");
		Serial.print(now.minute(), DEC);
		Serial.print(":");
		Serial.println(now.second(), DEC);
	}
	delay(500);
}	