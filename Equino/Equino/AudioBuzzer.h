/*
 File  : AudioBuzzer.h
 Version : 1.0
 Date  : 04/03/2019
 Project : Systel Equino Buzzer Audio Driver Device Support Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 Sound Control Device Config:

 For uno:
 SOUND_OUT_PIN    connect to digital pin 5

 For Mega:
 SOUND_OUT_PIN    connect to digital pin 18

 */
#ifndef _AudioBuzzer_h_
#define _AudioBuzzer_h_

#include <Arduino.h>
#include "AudioMessageDevice.h"

#if defined(__AVR_ATmega2560__)
	#define SOUND_OUT_PIN   18  // connect to digital MEGA 2560 PIN
#else
	#define SOUND_OUT_PIN   5  // connect to digital ATMEGA_8 PIN 11
#endif

// library interface description
class AudioBuzzer: public AudioMessageDevice {
	// user-accessible "public" interface
public:

	void start(uint8_t sound_PIN);

	void signal(Level level, int frequency, unsigned long duration);

	void info(Level level, uint8_t repetitions = 1);

	void warn(Level level, uint8_t repetitions = 1);

	void error(Level level, uint8_t repetitions = 1);

	void fatal(Level level, uint8_t repetitions = 1);

	void mute(void);

	// library-accessible "private" interface
protected:

	void setup(void);

	void volume(Level level);

	// library-accessible "private" interface
private:

	void compensation(uint8_t repetitions);

	volatile uint8_t soundPin = SOUND_OUT_PIN;

};

#endif
