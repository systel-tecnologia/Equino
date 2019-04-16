/*
	File  : AudioBuzzer.ino
	Version : 1.0
	Date  : 04/03/2019
	Project : Systel Equino Buzzer Audio Driver Device Support Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
	Sound Control Device Config:
	
	For uno:
		SOUND_OUT_PIN    connect to digital pin 5	

	For Mega:
		SOUND_OUT_PIN    connect to digital pin 18	
		
*/
#include <Arduino.h>
#include <AudioBuzzer.h>

Level level = LEVEL_100;

AudioBuzzer audio;

void setup() {	
	Serial.begin(115200);
	audio.start(SOUND_OUT_PIN);
}

void loop() {
	audio.info(level);
	delay(1000);
	
	audio.warn(level);
	delay(1000);
	
	audio.error(level, 2);
	delay(1000);
	
	audio.error(level, 3);
	delay(1000);
	
	audio.error(level, 5);
	delay(1000);
	
	audio.fatal(level, 2);
	delay(1000);
	
	audio.fatal(level, 3);
	delay(1000);
	
	audio.fatal(level, 5);
	delay(1000);
	
}				