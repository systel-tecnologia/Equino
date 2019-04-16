/*
 File: Equino.cpp
 Version: 1.0
 Date: 05/03/2019
 Project: Systel Equino Library
 Author: Daniel Valentin - dtvalentin@gmail.com

 */

#include "Equino.h"

#include "AudioBuzzer.h"
#include "Led.h"
#include "Relay.h"

AudioBuzzer audio;
Led led1;
Led led2;
Relay relay;

void setup() {
	audio.start(SOUND_OUT_PIN);
	audio.info(LEVEL_100, 1);
	relay.start(4);
	led1.start(0);
	led2.start(1);
}

void loop() {
	relay.write(STATE_ON);
	led1.write(STATE_ON);
	led2.write(STATE_OFF);
	delay(500);
	relay.write(STATE_OFF);
	led1.write(STATE_OFF);
	led2.write(STATE_ON);
	delay(500);
}

