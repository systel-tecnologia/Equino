/*
	File  : Keypad13k7i.h
	Version : 1.0
	Date  : 05/03/2019
	Project : Systel Equino 13 Key 7 Input Keypad Support Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
	Keypad Device:
		ROW 0 connect to digital in 7	//	ATMEGA_8 PIN 13
		ROW 1 connect to digital in 13	//	ATMEGA_8 PIN 19
		ROW 2 connect to digital in 12	//	ATMEGA_8 PIN 18
		ROW 3 connect to digital in 10	//	ATMEGA_8 PIN 16
		COL 0 connect to digital in 11	//	ATMEGA_8 PIN 17
		COL 1 connect to digital in 9	//	ATMEGA_8 PIN 15
		COL 2 connect to digital in 8	//	ATMEGA_8 PIN 14
	
*/

#ifndef _Keypad13k7i_h_
	#define _Keypad13k7i_h_
	
	#include <Arduino.h>
	#include <Keypad.h>
	#include "InputDevice.h"
	#include "Keys.h"
	
	#define KEYPAD_ROW_0_PIN	7
	#define KEYPAD_ROW_1_PIN	13
	#define KEYPAD_ROW_2_PIN	12
	#define KEYPAD_ROW_3_PIN	10
	#define KEYPAD_COL_0_PIN	11
	#define KEYPAD_COL_1_PIN	9
	#define KEYPAD_COL_2_PIN	8
	
	
	// library interface description
	class Keypad13k7i : public KeyInputDevice {
		// user-accessible "public" interface
		public:

		void start();
		
		char read(void);
		
		// library-accessible "protected" interface
		protected:
		
		void setup(void);
		
		// library-accessible "private" interface
		private:
		
		char configKeys[4][3] = {{CODE_1, CODE_2, CODE_3}, {CODE_4, CODE_5, CODE_6}, {CODE_7, CODE_8, CODE_9}, {CODE_A, CODE_0, CODE_B}};
		byte configRowPins[4] = {KEYPAD_ROW_0_PIN, KEYPAD_ROW_1_PIN, KEYPAD_ROW_2_PIN, KEYPAD_ROW_3_PIN};
		byte configColPins[3] = {KEYPAD_COL_0_PIN, KEYPAD_COL_1_PIN, KEYPAD_COL_2_PIN};
		
		char powerKeys[1][1] = {{CODE_C}};
		byte powerRowPins[1] = {KEYPAD_ROW_0_PIN};
		byte powerColPins[1] = {KEYPAD_ROW_1_PIN};
		
		Keypad numberKeypad = Keypad( makeKeymap(configKeys), configRowPins, configColPins, 4, 3 );
		Keypad controlKeypad = Keypad( makeKeymap(powerKeys), powerRowPins, powerColPins, 1, 1 );
		
	};
	
	
#endif
