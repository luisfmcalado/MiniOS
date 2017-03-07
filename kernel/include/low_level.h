#ifndef LOW_LEVEL_H
#define LOW_LEVEL_H

unsigned char port_byte_in( unsigned short port );
void port_byte_out( unsigned short port , unsigned char data );
unsigned short port_word_in ( unsigned short port );
void port_word_out ( unsigned short port , unsigned short data );

unsigned char *memset(unsigned char *dest, unsigned char val, int count);

#endif
