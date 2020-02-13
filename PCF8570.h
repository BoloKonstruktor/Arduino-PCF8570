#ifndef PCF8570_h
#define PCF8570_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class PCF8570 {
	
	uint8_t hwaddr;
	
public:

	PCF8570( uint8_t=0x50 );
	void begin( void );
	uint8_t readByte( uint8_t );
	void writeByte( uint8_t, uint8_t );
	uint8_t readMemory( uint8_t, void*, uint8_t );
	uint8_t writeMemory( uint8_t, void*, uint8_t );
	void clearMemory( uint8_t=0x0 );
};



#endif

