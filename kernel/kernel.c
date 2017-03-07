#include "include/system.h"
#include "include/drivers/screen.h"
#include "include/system.h"

void printi(){
	print("OSxxxx\n");
	print("kernel 0.1v\n");
}

void main(){
	screen_init(); // init vga driver
	clear_screen(); // clear the entire screen

	printi(); //print OS and kernel information

	//init IDT
	idt_install();

	//init ISRs
	isrs_install();

	//init IRQ
	irq_install();
	__asm__ __volatile__ ("sti");

	timer_install();	
	keyboard_install();

	print("wait started.\n");
	timer_wait(18*2); // 2 seconds wait
	print("wait ended.\n");

	while(1);
}

