/*
 File  : Led.h
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino Led Device Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#ifndef _Led_h_
#define _Led_h_

#include <Arduino.h>
#include "StateDevice.h"

// library interface description
class Led: public StateDevice {
	// user-accessible "public" interface

public:

	Led();

	void start(uint8_t setup_PIN);

	void write(State state);

	State read();

	int getId();

	// library-accessible "protected" interface
protected:

	static uint8_t ledids;

	void setup(void);

	// library-accessible "private" interface
private:

	volatile uint8_t id = 0;

	volatile uint8_t setupPin = 0;

};

#endif
