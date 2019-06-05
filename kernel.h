#ifndef _KERNEL_H
#define _KERNEL_H

void idt_install();
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_install();

#endif