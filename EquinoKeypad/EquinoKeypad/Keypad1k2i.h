/*
 File  : Keypad1k2i.h
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino 1 Key 2 Input Keypad Support Arduino Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 Keypad Device:
 ROW 0 connect to digital in 13	//	ATMEGA_8 PIN 19
 COL 0 connect to digital in 12	//	ATMEGA_8 PIN 18

 */

#ifndef _Keypad1k2i_h_
#define _Keypad1k2i_h_

#include <Arduino.h>
#include <InputDevice.h>
#include <Keypad.h>

#include "Keys.h"

#define KEYPAD_ROW_0_PIN	7
#define KEYPAD_COL_0_PIN	8

// library interface description
class Keypad1k2i: public KeyInputDevice {
	// user-accessible "public" interface
public:

	Keypad1k2i();

	void start();

	char read(void);

	// library-accessible "protected" interface
protected:

	void setup(void);

	// library-accessible "private" interface
private:

	const char keyCodes[1][1] = { { CODE_B } };

	byte keyRows[1] = { KEYPAD_ROW_0_PIN };

	byte keyCols[1] = { KEYPAD_COL_0_PIN };

	Keypad keypadBtns = Keypad(makeKeymap(keyCodes), keyRows, keyCols, 1, 1);

};

#endif
