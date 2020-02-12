#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#include "PCF8570.h"


PCF8570::PCF8570( uint8_t addr ){
this->hwaddr = addr;	
}

void PCF8570::begin( void ){
Wire.begin();	
}

uint8_t PCF8570::readByte( uint8_t offset ){
uint8_t buff[1];
readPacket( offset, buff, 1 );
return (uint8_t)buff[0];
}

void PCF8570::writeByte( uint8_t offset, uint8_t data ){
uint8_t buff[1];
buff[0] = data;
writePacket( offset, buff, 1 );
}

uint8_t PCF8570::readMemory( uint8_t offset, void* data, uint8_t size ){
uint8_t* buff = (uint8_t*)data;
uint8_t off = offset;

    for( uint8_t i = 0; i < size; i++ ) {
    buff[i] = readByte( offset );
    off++;
    }
  
return off;
}

uint8_t PCF8570::writeMemory( uint8_t offset, void* data, uint8_t size ){
const uint8_t* buff = (uint8_t*)data;
uint8_t off = offset;
  
  for ( uint8_t i = 0; i < size; i++) {
  writeByte( offset, buff[i] );
  off++;
  }
  
return off;
}

void PCF8570::clearMemory(void){
  
  for( uint8_t offset = 0; offset < 256; offset++ ){
  writeByte( offset, 0 );
  }
}

void PCF8570::readPacket( uint8_t offset, uint8_t * buff, uint8_t size ){
Wire.beginTransmission( this->hwaddr );
#if ARDUINO >= 100
  Wire.write(offset);
#else
  Wire.send(offset);
#endif
Wire.endTransmission();
Wire.requestFrom( this->hwaddr, (int)size );

  while ( !Wire.available() );

  for ( uint8_t i = 0; i < size; i++ ){
#if ARDUINO >= 100
  buff[i] = Wire.read();
#else
  buff[i] = Wire.receive();
#endif
  }

Wire.endTransmission();
}

void PCF8570::writePacket( uint8_t offset, uint8_t * buff, uint8_t size ){
Wire.beginTransmission( this->hwaddr );

#if ARDUINO >= 100
  Wire.write( offset );
  Wire.write( buff, size );
#else
  Wire.send( offset );
  Wire.send( buff, size );
#endif

Wire.endTransmission();
}
