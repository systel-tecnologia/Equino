/*
 File  : DisplayDevice7Seg4094.ino
 Version : 1.0
 Date : 05/03/2019
 Project : Systel Equino Shift Register 7 Segments Driver Interfaces
 Author  : Daniel Valentin - dtvalentin@gmail.com
 
 STROBE_PIN/ LATCH_PIN  connect to analog pin A2
 DATA_PIN    		   connect to analog pin A1
 CLOCK_PIN   		   connect to analog pin A0
 ENABLE_PIN  		   connect to digital pin 3
 
 */
#include <DisplayDevice7Seg.h>

DisplayDevice7Seg4094 display;
int current = 0;

void setup() {
	Serial.begin(9600);
	display.start(ENABLE_PIN, CLOCK_PIN, DATA_PIN, LATCH_PIN, 6);
}

void loop() {
	char d[6] = { 0, 0, 0, 0, 0, 0 };

	sprintf(d, "%6d", current);
	display.print(d);

	current = current + 1;
	if (current > 65535) {
		current = 0;
	}
	delay(30);
}
