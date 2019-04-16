/*
	File  : Relay.h
	Version : 1.0
	Date  : 05/03/2019
	Project : Systel Equino Relay Device Library
	Author  : Daniel Valentin - dtvalentin@gmail.com
		
*/

#ifndef _Relay_h_
	#define _Relay_h_
	
	#include <Arduino.h>
	#include "StateDevice.h"
	
	// library interface description
	class Relay : public StateDevice {
		// user-accessible "public" interface
		public:
		
		Relay();
		
		void start(uint8_t setup_PIN);
		
		void write(State state);
		
		State read();
		
		int getId();
										
		// library-accessible "protected" interface
		protected:
		
		static uint8_t relayids;
		
		void setup(void);
				
		// library-accessible "private" interface
		private:			
		
		uint8_t id = 0;
		
		uint8_t setupPin = 0;
		
	};
	
	
#endif