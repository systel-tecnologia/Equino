/*
	File  : Relay.ino
	Version : 1.0
	Date  : 28/07/2016
	Project : Systel Babuino Relay State Device Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
*/
#include <Relay.h>

#define RELAY_PIN 4

Relay relay1;
Relay relay2;

void setup() {
	Serial.begin(115200);
	relay1.start(RELAY_PIN);
	relay2.start(RELAY_PIN);
}

void loop() {
	relay1.write(STATE_ON);
	printState(relay1);
	relay1.write(STATE_OFF);
	printState(relay1);	
	delay(1000);
	relay2.write(STATE_ON);
	printState(relay2);
	relay2.write(STATE_OFF);
	printState(relay2);	
}	

void printState(Relay relay){
	if(Serial){
		if(relay1.read() == STATE_ON){
			Serial.print("Relay ");
			Serial.print(relay.getId());
			Serial.println(" State ON");
		} else {
			Serial.print("Relay ");
			Serial.print(relay.getId());
			Serial.println(" State OFF");
		}		
	}
	delay(500);
}	