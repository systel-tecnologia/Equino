/*
	File  : Keypad1k2i.cpp
	Version : 1.0
	Date  : 11/11/2016
	Project : Systel Babuino 1 Key 2 Input Keypad Support Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
*/

#include "Keypad1k2i.h"

Keypad1k2i::Keypad1k2i(){
	
}

void Keypad1k2i::start(){
	setup();
	#if(DEBUG_LEVEL == 3)
		DBG_PRINTLN_LEVEL("Keypad 1 Key 2 Inputs started...");
	#endif
}

char Keypad1k2i::read(void){
	char key = keypadBtns.getKey();
	#if(DEBUG_LEVEL == 3)
		if(key){
			DBG_PRINT_LEVEL("Keypad Key code ");
			DBG_PRINT_LEVEL(key);
			DBG_PRINTLN_LEVEL(" pressed");
		}
	#endif
	return key;  	  
}

void Keypad1k2i::setup(void){
	
}

