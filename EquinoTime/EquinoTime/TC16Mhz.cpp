/*
 File  : TC16Mhz.cpp
 Version : 1.0
 Date  : 29/07/2016
 Project : Systel Babuino Timer Devices Arduino Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#include <Equino.h>
#include <RTClib.h>

#include "TimeDevice.h"

/***************************************
 TC 16MHZ Atmega 328 Millis
 ****************************************/
TC16Mhz::TC16Mhz() {

}

void TC16Mhz::start() {
#if(DEBUG_LEVEL == 2)
		DBG_PRINTLN_LEVEL("Internal TC Device Driver Started (Millis 16MHZ)...");
	#endif		
	DateTime dt = DateTime(F(__DATE__), F(__TIME__));
	itc.begin(dt);
}

void TC16Mhz::setup(const DateTime& dt) {
	itc.adjust(dt);
}

DateTime TC16Mhz::now() {
	return itc.now();
}
