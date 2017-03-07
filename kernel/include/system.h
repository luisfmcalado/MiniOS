#ifndef SYSTEM_H
#define SYSTEM_H

struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */
};


void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_install();

void isrs_install();

void irq_install();
void irq_uninstall_handler(int irq);
void irq_install_handler(int irq, void (*handler)(struct regs *r));

void timer_install();
void timer_wait(int ticks);

void keyboard_install();

#endif
