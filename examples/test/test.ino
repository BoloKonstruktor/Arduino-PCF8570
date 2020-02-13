#include <PCF8570.h>

typedef struct {
uint8_t pin, mode, id;
uint16_t on, off;
char str[32]; 
}TCTRL;

//uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255 };
TCTRL data;
PCF8570 ram;

void setup(){ 
ram.begin();
Serial.begin( 115200 );

  if( ram.readByte( 0 ) ) return;

Serial.println( F("Zapis danych do pamieci RAM...") );
data.pin = 6;
data.mode = 1;
data.id = 0;
data.on = 800;
data.off = 1600;
strcpy( data.str, "Hello World!" );
ram.writeMemory( 0x0, &data, sizeof( data ) );
  
delay( 1000 );
}

void loop()
{
TCTRL data2;
ram.readMemory( 0x0, &data2, sizeof( data2 ) );

Serial.print( F("data2.pin=") );
Serial.print( data2.pin );
Serial.print( F(" data2.mode=") );
Serial.print( data2.mode );
Serial.print( F(" data2.id=") );
Serial.print( data2.id );
Serial.print( F(" data2.on=") );
Serial.print( data2.on );
Serial.print( F(" data2.off=") );
Serial.print( data2.off );
Serial.print( F(" data2.str=") );
Serial.println( data2.str );
Serial.println();

data2.id++;
ram.writeByte( 2, data2.id );
delay(500);
}
