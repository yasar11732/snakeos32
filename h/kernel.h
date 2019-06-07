#ifndef _KERNEL_H
#define _KERNEL_H
#include <stdint.h>
#include <stddef.h>

void idt_install();
void idt_set_gate(unsigned char num, void *base, unsigned short sel, unsigned char flags);
void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_install();

void enable_interrupts(int flags);
unsigned char inb(uint16_t port);
void outb(uint16_t port, uint8_t data);

void bsod(char *message);

void *memset(void *ptr, int value, size_t num);
void irq_init();
void wait_forever();
void timer_phase(int hz);

extern volatile int timer_ticks;

void PIC_sendEOI(unsigned char irq);

void delay(int ms);

#endif