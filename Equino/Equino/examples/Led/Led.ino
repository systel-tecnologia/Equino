/*
	File  : Led.ino
	Version : 1.0
	Date  : 28/07/2016
	Project : Systel Babuino Led State Device Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
*/
#include <Arduino.h>
#include <Led.h>

#define BLINK_LED_PIN_1 13
#define BLINK_LED_PIN_2 0
#define BLINK_LED_PIN_3 1

Led led0;
Led led1;
Led led2;

void setup() {
	Serial.begin(115200);
	
	led0.start(BLINK_LED_PIN_1);
	led1.start(BLINK_LED_PIN_2);
	led2.start(BLINK_LED_PIN_3);
}

void loop() {
	led0.write(STATE_OFF);
	printState(led0);
	led1.write(STATE_ON);
	printState(led1);
	led2.write(STATE_ON);
	printState(led2);
	
	delay(1000);
	
	led0.write(STATE_ON);
	printState(led0);
	led1.write(STATE_OFF);
	printState(led1);
	led2.write(STATE_OFF);
	printState(led2);
	
}	

void printState(Led led){
	if(Serial){
		if(led.read() == STATE_ON){		
			Serial.print("Led ");
			Serial.print(led.getId());
			Serial.println(" State ON");		
		} else {
			Serial.print("Led ");
			Serial.print(led.getId());
			Serial.println(" State ON");
		}
	}
	delay(250);
}	