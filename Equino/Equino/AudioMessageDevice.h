/*
 File  : AudioMessageDevice.h
 Version : 1.0
 Date  : 05/03/2019
 Project : Systel Equino Audio Message Driver Interface
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */

#ifndef _AudioMessageDevice_H_
#define _AudioMessageDevice_H_

#include "Equino.h"

// Beep Times
#define BEEP_TONE_FREQ	 	2500
#define BEEP_TIME		 	20

// Audio Message TONE Frequency Code Numbers
#define FREQ_INIT_WARN  	2900
#define FREQ_FINAL_WARN 	3100
#define TONE_TIME_WARN  	20
#define FREQ_INIT_ERROR   	2800
#define FREQ_FINAL_ERROR  	3200
#define TONE_TIME_ERROR   	6
#define FREQ_INIT_FATAL   	2500
#define FREQ_FINAL_FATAL  	2800
#define TONE_TIME_FATAL   	6

// Volume for audio signal
enum Level {
	LEVEL_0 = 0x00,
	LEVEL_25 = 0x25,
	LEVEL_50 = 0x50,
	LEVEL_75 = 0x75,
	LEVEL_100 = 0x100
};

class AudioMessageDevice {
	// user-accessible "public" interface
public:

	virtual ~AudioMessageDevice() {};

	virtual void signal(Level level, int frequency, unsigned long duration) = 0;

	virtual void info(Level level, uint8_t repetitions = 1) = 0;

	virtual void warn(Level level, uint8_t repetitions = 1) = 0;

	virtual void error(Level level, uint8_t repetitions = 1) = 0;

	virtual void fatal(Level level, uint8_t repetitions = 1) = 0;

	virtual void mute(void) = 0;

	// library-accessible "protected" interface
protected:

	virtual void setup(void) = 0;

	virtual void volume(Level level) = 0;

	// library-accessible "private" interface
private:

};

#endif
