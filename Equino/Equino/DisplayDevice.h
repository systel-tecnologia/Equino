/*
 File  : DisplayDevice.h
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino Display Device Driver Interface
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#ifndef _DisplayDevice_H_
#define _DisplayDevice_H_

#include <Arduino.h>

// library interface description
class DisplayDevice { // @suppress("Class has a virtual method and non-virtual destructor")
	// user-accessible "public" interface
public:

	virtual void clear(void) = 0;

	virtual void print(char *data) = 0;

	virtual int getCols() = 0;

	virtual int getRows() = 0;

	virtual boolean getEnable() {
		return enable;
	}

	virtual void setEnable(boolean state) {
		enable = state;
	}

	// library-accessible "protected" interface
protected:

	// library-accessible "private" interface
private:

	boolean enable = true;

};

#endif
