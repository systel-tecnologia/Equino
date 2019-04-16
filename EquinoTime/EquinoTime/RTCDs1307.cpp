/*
 File  : RTCDs1307.cpp
 Version : 1.0
 Date  : 13/03/2019
 Project : Systel Babuino Timer Devices Arduino Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#include <Equino.h>
#include <RTClib.h>

#include "TimeDevice.h"

/***************************************
 RTC 37,2 KHz IC-DS1307
 ****************************************/
RTCDs1307::RTCDs1307() {
}

void RTCDs1307::start(void) {
	// Init RTC
	rtc.begin();
	Ds1307SqwPinMode mode = rtc.readSqwPinMode();
	if (mode != SquareWave1HZ) {
		rtc.writeSqwPinMode(SquareWave1HZ);
		rtc.adjust(DateTime(2001, 1, 1, 12, 0, 0));
	}
#if(DEBUG_LEVEL >= 2)	
//	DBG_PRINTLN_LEVEL("Ds1307 I2C RTC Device Driver Started (SQR Mode: 1HZ)...");
#endif
}

void RTCDs1307::start(Ds1307SqwPinMode mode) {
	// Init RTC
	rtc.begin();
	Ds1307SqwPinMode md = rtc.readSqwPinMode();
	if (mode != md) {
		rtc.writeSqwPinMode(mode);
	}
#if(DEBUG_LEVEL >= 2)
	DBG_PRINTLN_LEVEL("Ds1307 I2C RTC Device Driver Started (SQR Mode: ?)...");
#endif
}

void RTCDs1307::setup(const DateTime& dt) {
	rtc.adjust(dt);
}

DateTime RTCDs1307::now() {
	return rtc.now();
}

void RTCDs1307::read(uint8_t* buf, uint8_t size, uint8_t address) {
	rtc.readnvram(buf, size, address);
}

void RTCDs1307::write(uint8_t address, uint8_t data) {
	rtc.writenvram(address, data);
}

void RTCDs1307::write(uint8_t address, uint8_t* buf, uint8_t size) {
	rtc.writenvram(address, buf, size);
}
