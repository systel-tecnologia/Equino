/*
	File  : Keypad3k4i.h
	Version : 1.0
	Date  : 05/03/2019
	Project : Systel Equino 3 Key 4 Input Keypad Support Arduino Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
	
	Keypad Device:
		ROW 0 connect to digital in 13	//	ATMEGA_8 PIN 19
		COL 0 connect to digital in 12	//	ATMEGA_8 PIN 18
		COL 1 connect to digital in 10	//	ATMEGA_8 PIN 16
		COL 2 connect to digital in 9	//	ATMEGA_8 PIN 15
	
*/

#ifndef _Keypad3k4i_h_
	#define _Keypad3k4i_h_
	
	#include <Arduino.h>
	#include <Keypad.h>
	#include <InputDevice.h>
	#include "Keys.h"
	
	#define KEYPAD_ROW_0_PIN	11
	#define KEYPAD_COL_0_PIN	12
	#define KEYPAD_COL_1_PIN	13
	#define KEYPAD_COL_2_PIN	9
	
	
	// library interface description
	class Keypad3k4i : public KeyInputDevice {
		// user-accessible "public" interface
		public:

		void start();
		
		char read(void);
				
		// library-accessible "protected" interface
		protected:
		
		void setup(void);
		
		// library-accessible "private" interface
		private:

		const char keyCodes[1][3] = {{CODE_A, CODE_B, CODE_C}};
		
		byte keyRows[1] = {KEYPAD_ROW_0_PIN};
		
		byte keyCols[3] = {KEYPAD_COL_0_PIN, KEYPAD_COL_1_PIN, KEYPAD_COL_2_PIN};

		Keypad keypadBtns = Keypad( makeKeymap(keyCodes), keyRows, keyCols, 1, 3 );

	};
	
	
#endif
