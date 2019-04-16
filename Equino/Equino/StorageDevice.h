/*
 File  : StorageDevice.h
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino Storange Device Driver Interface
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#ifndef _StorageDevice_H_
#define _StorageDevice_H_

#include <stdint.h>

class StorageDevice {
	// user-accessible "public" interface
public:
	virtual ~StorageDevice() {};

	virtual void read(uint8_t* data, uint8_t size, uint8_t address);

	virtual void write(uint8_t address, uint8_t data);

	virtual void write(uint8_t address, uint8_t* data, uint8_t size);

	// library-accessible "protected" interface
protected:

	// library-accessible "private" interface
private:
};

#endif
