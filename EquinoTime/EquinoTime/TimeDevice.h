/*
 File  : TimeDevice.h
 Version : 1.0
 Date  : 16/04/2019
 Project : Systel Babuino Timer Devices Arduino Library

 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#ifndef _TimeDevice_h_
#define _TimeDevice_h_

#include <RTClib.h>
#include <StorageDevice.h>

class TimeDevice {
	// user-accessible "public" interface
public:

	virtual ~TimeDevice() {};

	virtual void start(void) = 0;

	virtual void setup(const DateTime& dt) = 0;

	virtual DateTime now() = 0;

	// library-accessible "protected" interface
protected:

	// library-accessible "private" interface
private:

};

class RTCDs1307: public TimeDevice, StorageDevice {
	// user-accessible "public" interface
public:

	RTCDs1307();

	virtual void start(void);

	virtual void start(Ds1307SqwPinMode mode);

	virtual void setup(const DateTime& dt);

	DateTime now();

	void read(uint8_t* buf, uint8_t size, uint8_t address);

	void write(uint8_t address, uint8_t data);

	void write(uint8_t address, uint8_t* buf, uint8_t size);

	// library-accessible "protected" interface
protected:

	RTC_DS1307 rtc;

	// library-accessible "private" interface
private:
};

class TC16Mhz: public TimeDevice {
	// user-accessible "public" interface
public:

	TC16Mhz();

	void start(void);

	void setup(const DateTime& dt);

	DateTime now();

	// library-accessible "protected" interface
protected:

	RTC_Millis itc;

	// library-accessible "private" interface
private:
};

#endif
