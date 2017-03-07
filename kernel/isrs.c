#include "include/drivers/screen.h"
#include "include/system.h"

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

char *exception_messages[32];

void isrs_install() {
	idt_set_gate(0, (unsigned)isr0, 0x08, 0x8E);
	idt_set_gate(1, (unsigned)isr1, 0x08, 0x8E);
	idt_set_gate(2, (unsigned)isr2, 0x08, 0x8E);
	idt_set_gate(3, (unsigned)isr3, 0x08, 0x8E);
	idt_set_gate(4, (unsigned)isr4, 0x08, 0x8E);
	idt_set_gate(5, (unsigned)isr5, 0x08, 0x8E);
	idt_set_gate(6, (unsigned)isr6, 0x08, 0x8E);
	idt_set_gate(7, (unsigned)isr7, 0x08, 0x8E);
	idt_set_gate(8, (unsigned)isr8, 0x08, 0x8E);
	idt_set_gate(9, (unsigned)isr9, 0x08, 0x8E);
	idt_set_gate(10, (unsigned)isr10, 0x08, 0x8E);
	idt_set_gate(11, (unsigned)isr11, 0x08, 0x8E);
	idt_set_gate(12, (unsigned)isr12, 0x08, 0x8E);
	idt_set_gate(13, (unsigned)isr13, 0x08, 0x8E);
	idt_set_gate(14, (unsigned)isr14, 0x08, 0x8E);
	idt_set_gate(15, (unsigned)isr15, 0x08, 0x8E);
	idt_set_gate(16, (unsigned)isr16, 0x08, 0x8E);
	idt_set_gate(17, (unsigned)isr17, 0x08, 0x8E);
	idt_set_gate(18, (unsigned)isr18, 0x08, 0x8E);
	idt_set_gate(19, (unsigned)isr19, 0x08, 0x8E);
	idt_set_gate(20, (unsigned)isr20, 0x08, 0x8E);
	idt_set_gate(21, (unsigned)isr21, 0x08, 0x8E);
	idt_set_gate(22, (unsigned)isr22, 0x08, 0x8E);
	idt_set_gate(23, (unsigned)isr23, 0x08, 0x8E);
	idt_set_gate(24, (unsigned)isr24, 0x08, 0x8E);
	idt_set_gate(25, (unsigned)isr25, 0x08, 0x8E);
	idt_set_gate(26, (unsigned)isr26, 0x08, 0x8E);
	idt_set_gate(27, (unsigned)isr27, 0x08, 0x8E);
	idt_set_gate(28, (unsigned)isr28, 0x08, 0x8E);
	idt_set_gate(29, (unsigned)isr29, 0x08, 0x8E);
	idt_set_gate(30, (unsigned)isr30, 0x08, 0x8E);
	idt_set_gate(31, (unsigned)isr31, 0x08, 0x8E);

	exception_messages[0] = "Division By Zero";
	exception_messages[1] = "Debug";
	exception_messages[2] = "Non Maskable Interrupt";
	exception_messages[3] = "Breakpoint Exception";
	exception_messages[4] = "Into Detected Overflow Exception";
	exception_messages[5] = "Out of Bounds Exception";
	exception_messages[6] = "Invalid Opcode Exception";
	exception_messages[7] = "No Coprocessor Exception";
	exception_messages[8] = "Double Fault Exception";
	exception_messages[9] = "Coprocessor Segment Overrun Exception";
	exception_messages[10] = "Bad TSS Exception";
	exception_messages[11] = "Xegment Not Present Exception";
	exception_messages[12] = "Ytack Fault Exception";
	exception_messages[13] = "General Protection Fault Exception";
	exception_messages[14] = "Page Fault Exception";
	exception_messages[15] = "Unknown Interrupt Exception";
	exception_messages[16] = "Coprocessor Fault Exception";
	exception_messages[17] = "Alignment Check Exception (486+)";
	exception_messages[18] = "Machine Check Exception (Pentium/586+)";
	exception_messages[19] = "Reserved";
       	exception_messages[20] = "Reserved";
	exception_messages[21] = "Reserved";
       	exception_messages[22] = "Reserved";
	exception_messages[23] = "Reserved";
       	exception_messages[24] = "Reserved";
	exception_messages[25] = "Reserved";
       	exception_messages[26] = "Reserved";
	exception_messages[27] = "Reserved";
       	exception_messages[28] = "Reserved";
	exception_messages[29] = "Reserved"; 
	exception_messages[30] = "Reserved";
	exception_messages[31] = "Reserved";
}

void fault_handler(struct regs *r) {
	if (r->int_no < 32) {
		print(exception_messages[r->int_no]);
		print(" - Exception. System Halted!\n");
		for (;;)
			;
	}
}
