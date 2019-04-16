/*
	File: Equino.h
	Version: 1.0
	Date: 05/03/2019
	Project: Systel Equino Library
	Author: Daniel Valentin - dtvalentin@gmail.com
	
*/

#ifndef _Equino_H_
	#define _Equino_H_
	
	#include <Arduino.h>
	
	// Debug directive Levels
	#define DEBUG_LEVEL 3

	// Default Empty Data Value
	#define EMPTY_DATA	0
		
	// Debug Macro Print
	#if DEBUG_LEVEL != 0
		#define DBG_PRINT_LEVEL(...)    Serial.print(__VA_ARGS__)
		#define DBG_PRINTLN_LEVEL(...)  Serial.println(__VA_ARGS__)
	#else
		#define DBG_PRINT_LEVEL(...)
		#define DBG_PRINTLN_LEVEL(...)
	#endif
	
	
#endif