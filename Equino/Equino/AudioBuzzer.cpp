/*
 File  : AudioBuzzer.cpp
 Version : 1.0
 Date  : 04/03/2019
 Project : Systel Equino Buzzer Audio Driver Device Support Library
 Author  : Daniel Valentin - dtvalentin@gmail.com

 */
#include <Arduino.h>
#include "AudioBuzzer.h"

void AudioBuzzer::start(uint8_t sound_PIN) {
	soundPin = sound_PIN;
	setup();
#if(DEBUG_LEVEL >= 2)
	DBG_PRINT_LEVEL("Buzzer Audio Message Device Write ON Pin: (");
	DBG_PRINT_LEVEL(soundPin);
	DBG_PRINTLN_LEVEL(") Started...");
#endif	
}

void AudioBuzzer::info(Level level, uint8_t repetitions) {
#if(DEBUG_LEVEL >= 4)
	DBG_PRINT_LEVEL("\t\tINFO Sound Message ");
	DBG_PRINT_LEVEL(repetitions);
	DBG_PRINTLN_LEVEL(" Repetitions ");
#endif		
	volume(level);
	for (int r = 0; r < repetitions; r++) {
		tone(soundPin, BEEP_TONE_FREQ, BEEP_TIME);
		delay(BEEP_TIME * 10);
	}
	volume(LEVEL_0);
}

void AudioBuzzer::warn(Level level, uint8_t repetitions) {
#if(DEBUG_LEVEL >= 4)
	DBG_PRINT_LEVEL("\t\tWARN Sound Message ");
	DBG_PRINT_LEVEL(repetitions);
	DBG_PRINTLN_LEVEL(" Repetitions ");
#endif		
	volume(level);
	for (int r = 0; r < repetitions; r++) {
		for (int i = (FREQ_INIT_WARN); i < (FREQ_FINAL_WARN); i++) {
			tone(soundPin, i, TONE_TIME_WARN);
		}
		delay(TONE_TIME_WARN * 5);
	}
	volume(LEVEL_0);
}

void AudioBuzzer::error(Level level, uint8_t repetitions) {
#if(DEBUG_LEVEL >= 4)
	DBG_PRINT_LEVEL("\t\tERROR Sound Message ");
	DBG_PRINT_LEVEL(repetitions);
	DBG_PRINTLN_LEVEL(" Repetitions ");
#endif		
	volume(level);
	for (int r = 0; r < repetitions; r++) {
		for (int j = 0; j < TONE_TIME_ERROR; j++) {
			for (int i =
			FREQ_INIT_ERROR; i < FREQ_FINAL_ERROR; i++) {
				// Som Continuo
				tone(soundPin, FREQ_FINAL_ERROR, TONE_TIME_ERROR);
			}
		}
		compensation(repetitions);
	}
	volume(LEVEL_0);
}

void AudioBuzzer::fatal(Level level, uint8_t repetitions) {
#if(DEBUG_LEVEL >= 4)
	DBG_PRINT_LEVEL("\t\tFATAL Sound Message ");
	DBG_PRINT_LEVEL(repetitions);
	DBG_PRINTLN_LEVEL(" Repetitions ");
#endif		
	volume(level);
	for (int r = 0; r < repetitions; r++) {
		for (int j = 0; j < TONE_TIME_FATAL; j++) {
			for (int i =
			FREQ_INIT_FATAL; i < FREQ_FINAL_FATAL; i++) {
				// Som oscilante
				tone(soundPin, i, TONE_TIME_FATAL);
			}
		}
		compensation(repetitions);
	}
	volume(LEVEL_0);
}

void AudioBuzzer::signal(Level level, int frequency, unsigned long duration) {
#if(DEBUG_LEVEL >= 4)
	DBG_PRINT_LEVEL("\t\t\tSound Output Tone Frequency: ");
	DBG_PRINT_LEVEL(frequency);
	DBG_PRINT_LEVEL(" Duration:  ");
	DBG_PRINTLN_LEVEL(duration);
#endif		
	volume(level);
	tone(soundPin, frequency, duration);
}

void AudioBuzzer::mute(void) {
	volume(LEVEL_0);
}

void AudioBuzzer::compensation(uint8_t repetitions) {
	if (repetitions == 2) {
		delay(50);
	} else if (repetitions >= 3) {
		delay(40);
	}
}

void AudioBuzzer::setup(void) {

	// digital Pins
	pinMode(soundPin, OUTPUT);

	// Preset
	digitalWrite(soundPin, 0);
}

void AudioBuzzer::volume(Level level) {
#if(DEBUG_LEVEL == 4)
	DBG_PRINT_LEVEL("\t\t\t(Adj. Level to : ");
	DBG_PRINT_LEVEL((level % 255) * 100);
	DBG_PRINTLN_LEVEL("%) ");
#endif
	if (level == LEVEL_0) {
#if(DEBUG_LEVEL == 4)
	DBG_PRINT_LEVEL("\n");
	noTone(soundPin);
#endif
	}
}
