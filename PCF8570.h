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
	uint8_t writeByte( uint8_t, uint8_t );
	void clearMemory( void );
	void readPacket( uint8_t, uint8_t*, uint8_t );
	void writePacket( uint8_t, uint8_t*, uint8_t );
	uint8_t read( uint8_t, void*, uint8_t );
	uint8_t write( uint8_t, void*, uint8_t );
};



#endif
