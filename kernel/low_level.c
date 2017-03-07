#include "include/low_level.h"

unsigned char port_byte_in(unsigned short port) {
	unsigned char result;
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	return result;
}

void port_byte_out(unsigned short port , unsigned char data) {
	__asm__("out %%al, %%dx" : :"a" (data) , "d" (port));
}

unsigned short port_word_in(unsigned short port) {
	unsigned short result ;
	__asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
	return result ;
}

void port_word_out(unsigned short port , unsigned short data) {
	__asm__("out %%ax, %%dx " : :"a" (data) , "d" (port));
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count){
	int i;
	for(i = 0; i < count; i++){
		*(dest + i) = val;
	}
	return dest;
}
