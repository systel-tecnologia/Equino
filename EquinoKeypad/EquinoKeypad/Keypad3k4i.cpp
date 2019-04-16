/*
	File  : Keypad3k4i.cpp
	Version : 1.0
	Date  : 12/07/2016
	Project : Systel Babuino 3 Key 4 Input Keypad Support Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com

*/

#include "Keypad3k4i.h"

void Keypad3k4i::start(){
	setup();
	#if(DEBUG_LEVEL == 3)
		DBG_PRINTLN_LEVEL("Keypad 3 Keys 4 Inputs started...");
	#endif
}

char Keypad3k4i::read(void){
	return (keypadBtns.getKey());  	  
}

void Keypad3k4i::setup(void){

}

