/*
 File  : StateDevice.h
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino State Device Driver Interface
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#ifndef _StateDevice_H_
#define _StateDevice_H_

enum State {
	STATE_OFF = 0x00, STATE_ON = 0x01
};

// library interface description
class StateDevice {
	// user-accessible "public" interface
public:

	virtual ~StateDevice();

	virtual void write(State state) = 0;

	virtual State read() = 0;

	virtual int getId() = 0;

	// library-accessible "protected" interface
protected:

	// library-accessible "private" interface
private:

};

#endif
