/*
 File  : DisplayDevice7Seg.h
 Version : 1.0
 Date : 05/03/2019
 Project : Systel Equino Shift Register 7 Segments Driver Interfaces
 Author  : Daniel Valentin - dtvalentin@gmail.com

 LATCH_PIN  			connect to analog 	pin A2
 DATA_PIN    		   	connect to analog 	pin A1
 CLOCK_PIN   		   	connect to analog 	pin A0
 ENABLE_PIN  		   	connect to digital 	pin 3

 */

#ifndef _DisplayDevice7Seg_H_
#define _DisplayDevice7Seg_H_

#include <avr/pgmspace.h>
#include <Arduino.h>
#include <DisplayDevice.h>
#include <pins_arduino.h>
#include <stdint.h>

#define ENABLE_PIN	3
#define CLOCK_PIN	A0
#define DATA_PIN	A1
#define LATCH_PIN	A2
#define DISPLAY_LEN	6 // Drivers with 6 Displays 7 Segments

// Displ7Seg Display Encoder
static const uint8_t charset[92] PROGMEM = {
//DEC			HEX	ASCII	BIN			SIMBOL
		0,//	00	 		00000000
		0,		//	00	!		00000000	
		33,		//	21	"		00100001	"
		0,		//	00	#		00000000	
		0,		//	00	$		00000000	
		0,		//	00	%		00000000	
		0,		//	00	&		00000000	
		1,		//	01	'		00000001	'
		29,		//	1D	(		00011101	(
		184,	//	B8	)		10111000	)
		0,		//	00	*		00000000	
		0,		//	00	+		00000000	
		64,		//	40	,		01000000	.
		2,		//	02	-		00000010	-
		64,		//	40	.		01000000	.
		0,		//	00	/		00000000	
		189,	//	BD	0		10111101	0
		160,	//	A0	1		10100000	1
		62,		//	3E	2		00111110	2
		186,	//	BA	3		10111010	3
		163,	//	A3	4		10100011	4
		155,	//	9B	5		10011011	5
		159,	//	9F	6		10011111	6
		176,	//	B0	7		10110000	7
		191,	//	BF	8		10111111	8
		187,	//	BB	9		10111011	9
		0,		//	00	:		00000000	
		0,		//	00	;		00000000	
		0,		//	00	<		00000000	
		10,		//	0A	=		00001010	=
		0,		//	00	>		00000000	
		0,		//	00	?		00000000	
		0,		//	00	@		00000000	
		183,	//	B7	A		10110111	A
		143,	//	8F	B		10001111	b
		29,		//	1D	C		00011101	C
		174,	//	AE	D		10101110	d
		31,		//	1F	E		00011111	E
		23,		//	17	F		00010111	F
		187,	//	BB	G		10111011	g
		167,	//	A7	H		10100111	H
		5,		//	05	I		00000101	I
		172,	//	AC	J		10101100	J
		0,		//	00	K		00000000	
		13,		//	0D	L		00001101	L
		0,		//	00	M		00000000	
		134,	//	86	N		10000110	n
		189,	//	BD	O		10111101	O
		55,		//	37	P		00110111	P
		179,	//	B3	Q		10110011	q
		6,		//	06	R		00000110	r
		155,	//	9B	S		10011011	S
		15,		//	0F	T		00001111	t
		173,	//	AD	U		10101101	U
		0,		//	00	V		00000000	
		0,		//	00	W		00000000	
		0,		//	00	X		00000000	
		171,	//	AB	Y		10101011	y
		62,		//	3E	Z		00111110	Z
		29,		//	1D	[		00011101	[
		0,		//	00	\		00000000	
		184,	//	B8	]		10111000	]
		0,		//	00	^		00000000	
		8,		//	08	_		00001000	_
		1,		//	01	`		00000001	'
		183,	//	B7	a		10110111	A
		143,	//	8F	b		10001111	b
		14,		//	0E	c		00001110	c
		174,	//	AE	d		10101110	d
		31,		//	1F	e		00011111	E
		23,		//	17	f		00010111	F
		187,	//	BB	g		10111011	g
		135,	//	87	h		10000111	h
		12,		//	0C	i		00001100	i
		172,	//	AC	j		10101100	J
		0,		//	00	k		00000000	
		13,		//	0D	l		00001101	L
		0,		//	00	m		00000000	
		134,	//	86	n		10000110	n
		142,	//	8E	o		10001110	o
		55,		//	37	p		00110111	P
		179,	//	B3	q		10110011	q
		6,		//	06	r		00000110	r
		155,	//	9B	s		10011011	S
		15,		//	0F	t		00001111	t
		140,	//	8C	u		10001100	u
		0,		//	00	v		00000000	
		0,		//	00	w		00000000	
		26,		//	1A	x		00011010	3 linhas
		171,	//	AB	y		10101011	y
		62		//	3E	z		00111110	z
		};

// library interface description
class DisplayDevice7Seg4094: public DisplayDevice {
	// user-accessible "public" interface
public:

	DisplayDevice7Seg4094();

	void start(uint8_t enabled_PIN, uint8_t clock_PIN, uint8_t data_PIN,
			uint8_t latch_PIN, uint8_t digits);

	void clear(void);

	void print(char *data);

	void print(char* format, int size, ...);

	int getCols();

	int getRows();

	// library-accessible "protected" interface
protected:

	void sendChar(char ch, boolean pt);

	void setup(void);

	void sendBits(uint8_t value);

	// library-accessible "private" interface
private:

	uint8_t len = DISPLAY_LEN;

	uint8_t enabledPin = ENABLE_PIN;

	uint8_t clockPin = CLOCK_PIN;

	uint8_t dataPin = DATA_PIN;

	uint8_t latchPin = LATCH_PIN;

};

class DisplayDevice7Seg595D: public DisplayDevice {
	// user-accessible "public" interface
public:

	DisplayDevice7Seg595D();

	void start(uint8_t enabled_PIN, uint8_t clock_PIN, uint8_t data_PIN,
			uint8_t latch_PIN, uint8_t digits);

	void clear(void);

	void print(char *data);

	void print(char* format, int size, ...);

	int getCols();

	int getRows();

	// library-accessible "protected" interface
protected:

	void sendChar(char ch, boolean pt);

	void setup(void);

	void sendBits(uint8_t value);

	// library-accessible "private" interface
private:

	uint8_t len = DISPLAY_LEN;

	uint8_t enabledPin = ENABLE_PIN;

	uint8_t clockPin = CLOCK_PIN;

	uint8_t dataPin = DATA_PIN;

	uint8_t latchPin = LATCH_PIN;

};

#endif 
