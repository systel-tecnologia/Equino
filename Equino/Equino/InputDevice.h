/*
 File  : InputDevice.h
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino Input Device Driver Interface
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#ifndef _InputDevice_H_
#define _InputDevice_H_

// library interface description
class InputDevice {
	// user-accessible "public" interface
public:

	// library-accessible "protected" interface
protected:

	// library-accessible "private" interface
private:

};

// library interface description
class KeyInputDevice: public InputDevice {
	// user-accessible "public" interface
public:
	virtual ~KeyInputDevice();

	virtual char read(void) = 0;

	// library-accessible "protected" interface
protected:

	// library-accessible "private" interface
private:

};

#endif
