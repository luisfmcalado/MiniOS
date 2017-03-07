#include "include/drivers/screen.h"
#include "include/low_level.h"
#include "include/system.h"

unsigned char kbdus[128];

/* Handles the keyboard interrupt */
void keyboard_handler(struct regs *r) {
	unsigned char scancode;

	/* Read from the keyboard's data buffer */
	scancode = port_byte_in(0x60);

	if (scancode & 0x80) {
		/* You can use this one to see if the user released the
		*  shift, alt, or control keys... */
	} else {
		print_char(kbdus[scancode], -1, -1, 0);
	}
}

void keyboard_install() {
	kbdus[0] = 0;
	kbdus[1] = 27;
	kbdus[2] = '1';
	kbdus[3] = '2';
	kbdus[4] = '3';
	kbdus[5] = '4';
	kbdus[6] = '5';
	kbdus[7] = '6';
	kbdus[8] = '7';
	kbdus[9] = '8'; /* 9 */
	kbdus[10] = '9';
	kbdus[11] = '0';
	kbdus[12] = '-';
	kbdus[13] = '=';
	kbdus[14] = '\b'; /* Backspace */
	kbdus[15] = '\t'; /* Tab */
	kbdus[16] = 'q';
	kbdus[17] = 'w';
	kbdus[18] = 'e';
	kbdus[19] = 'r'; /* 19 */
	kbdus[20] = 't';
	kbdus[21] = 'y';
	kbdus[22] = 'u';
	kbdus[23] = 'i';
	kbdus[24] = 'o';
	kbdus[25] = 'p';
	kbdus[26] = '[';
	kbdus[27] = ']';
	kbdus[28] = '\n'; /* Enter key */
	kbdus[29] = 0;    /* 29   - Control */
	kbdus[30] = 'a';
	kbdus[31] = 's';
	kbdus[32] = 'd';
	kbdus[33] = 'f';
	kbdus[34] = 'g';
	kbdus[35] = 'h';
	kbdus[36] = 'j';
	kbdus[37] = 'k';
	kbdus[38] = 'l';
	kbdus[39] = ';'; /* 39 */
	kbdus[40] = '\'';
	kbdus[41] = '`';
	kbdus[42] = 0; /* Left shift */
	kbdus[43] = '\\';
	kbdus[44] = 'z';
	kbdus[45] = 'x';
	kbdus[46] = 'c';
	kbdus[47] = 'v';
	kbdus[48] = 'b';
	kbdus[49] = 'n'; /* 49 */
	kbdus[50] = 'm';
	kbdus[51] = ',';
	kbdus[52] = '.';
	kbdus[53] = '/';
	kbdus[54] = 0; /* Right shift */
	kbdus[55] = '*';
	kbdus[56] = 0;   /* Alt */
	kbdus[57] = ' '; /* Space bar */
	kbdus[58] = 0;   /* Caps lock */
	kbdus[59] = 0;   /* 59 - F1 key ... > */
	kbdus[60] = 0;
	kbdus[61] = 0;
	kbdus[62] = 0;
	kbdus[63] = 0;
	kbdus[64] = 0;
	kbdus[65] = 0;
	kbdus[66] = 0;
	kbdus[67] = 0;
	kbdus[68] = 0; /* < ... F10 */
	kbdus[69] = 0; /* 69 - Num lock*/
	kbdus[70] = 0; /* Scroll Lock */
	kbdus[71] = 0; /* Home key */
	kbdus[72] = 0; /* Up Arrow */
	kbdus[73] = 0; /* Page Up */
	kbdus[74] = '-';
	kbdus[75] = 0; /* Left Arrow */
	kbdus[76] = 0;
	kbdus[77] = 0; /* Right Arrow */
	kbdus[78] = '+';
	kbdus[79] = 0; /* 79 - End key*/
	kbdus[80] = 0; /* Down Arrow */
	kbdus[81] = 0; /* Page Down */
	kbdus[82] = 0; /* Insert Key */
	kbdus[83] = 0; /* Delete Key */
	kbdus[84] = 0;
	kbdus[85] = 0;
	kbdus[86] = 0;
	kbdus[87] = 0; /* F11 Key */
	kbdus[88] = 0; /* F12 Key */
	kbdus[89] = 0; /* All other keys are undefined */

	irq_install_handler(1, keyboard_handler);
}
