#include "kernel.h"
/* Defines an IDT entry */
struct idt_entry
{
    unsigned short base_lo;
    unsigned short sel;        /* Our kernel segment goes here! */
    unsigned char always0;     /* This will ALWAYS be set to 0! */
    unsigned char flags;       /* Set using the above table! */
    unsigned short base_hi;
} __attribute__((packed));

struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

/* Declare an IDT of 256 entries. Although we will only use the
*  first 32 entries in this tutorial, the rest exists as a bit
*  of a trap. If any undefined IDT entry is hit, it normally
*  will cause an "Unhandled Interrupt" exception. Any descriptor
*  for which the 'presence' bit is cleared (0) will generate an
*  "Unhandled Interrupt" exception */
struct idt_entry idt[256];
struct idt_ptr idtp;

/* This exists in 'idt.s', and is used to load our IDT */
extern void idt_load();

/* Use this function to set an entry in the IDT. Alot simpler
*  than twiddling with the GDT ;) */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    /* We'll leave you to try and code this function: take the
    *  argument 'base' and split it up into a high and low 16-bits,
    *  storing them in idt[num].base_hi and base_lo. The rest of the
    *  fields that you must set in idt[num] are fairly self-
    *  explanatory when it comes to setup */
   idt[num].always0 = 0;
   idt[num].base_lo = (base & 0xFFFF);
   idt[num].base_hi = (base >> 16 & 0xFFFF);
   idt[num].sel = sel;
   idt[num].flags = flags;

}

extern void int0();
extern void int1();
extern void int2();
extern void int3();
extern void int4();
extern void int5();
extern void int6();
extern void int7();
extern void int8();
extern void int9();
extern void int10();
extern void int11();
extern void int12();
extern void int13();
extern void int14();
extern void int15();
extern void int16();
extern void int17();
extern void int18();
extern void reserved();


/* Installs the IDT */
void idt_install()
{
    int i = 0;
    /* Sets the special IDT pointer up, just like in 'gdt.c' */
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = &idt;

    /* Clear out the entire IDT, initializing it to zeros */
    memset(&idt, 0, sizeof(struct idt_entry) * 256);

    /* Add any new ISRs to the IDT here using idt_set_gate */
    idt_set_gate(0, int0, 0x08, 0x8E);
    idt_set_gate(1, int1, 0x08, 0x8E);
    idt_set_gate(2, int2, 0x08, 0x8E);
    idt_set_gate(3, int3, 0x08, 0x8E);
    idt_set_gate(4, int4, 0x08, 0x8E);
    idt_set_gate(5, int5, 0x08, 0x8E);
    idt_set_gate(6, int6, 0x08, 0x8E);
    idt_set_gate(7, int7, 0x08, 0x8E);
    idt_set_gate(8, int8, 0x08, 0x8E);
    idt_set_gate(9, int9, 0x08, 0x8E);
    idt_set_gate(10, int10, 0x08, 0x8E);
    idt_set_gate(11, int11, 0x08, 0x8E);
    idt_set_gate(12, int12, 0x08, 0x8E);
    idt_set_gate(13, int13, 0x08, 0x8E);
    idt_set_gate(14, int14, 0x08, 0x8E);
    idt_set_gate(15, int15, 0x08, 0x8E);
    idt_set_gate(16, int16, 0x08, 0x8E);
    idt_set_gate(17, int17, 0x08, 0x8E);
    idt_set_gate(18, int18, 0x08, 0x8E);
    idt_set_gate(19, reserved, 0x08, 0x8E);
    idt_set_gate(20, reserved, 0x08, 0x8E);
    idt_set_gate(21, reserved, 0x08, 0x8E);
    idt_set_gate(22, reserved, 0x08, 0x8E);
    idt_set_gate(23, reserved, 0x08, 0x8E);
    idt_set_gate(24, reserved, 0x08, 0x8E);
    idt_set_gate(25, reserved, 0x08, 0x8E);
    idt_set_gate(26, reserved, 0x08, 0x8E);
    idt_set_gate(27, reserved, 0x08, 0x8E);
    idt_set_gate(28, reserved, 0x08, 0x8E);
    idt_set_gate(29, reserved, 0x08, 0x8E);
    idt_set_gate(30, reserved, 0x08, 0x8E);
    idt_set_gate(31, reserved, 0x08, 0x8E);


    /* Points the processor's internal register to the new IDT */
    idt_load();
}


void int0_handler(void)
{
    bsod("Division By Zero Exception");
}


void int1_handler(void)
{
    bsod("Debug Exception");
}


void int2_handler(void)
{
    bsod("Non Maskable Interrupt Exception");
}


void int3_handler(void)
{
    bsod("Breakpoint Exception");
}


void int4_handler(void)
{
    bsod("Into Detected Overflow Exception");
}


void int5_handler(void)
{
    bsod("Out of Bounds Exception");
}


void int6_handler(void)
{
    bsod("Invalid Opcode Exception");
}


void int7_handler(void)
{
    bsod("No Coprocessor Exception");
}


void int8_handler(void)
{
    bsod("Double Fault Exception");
}


void int9_handler(void)
{
    bsod("Coprocessor Segment Overrun Exception");
}


void int10_handler(void)
{
    bsod("Bad TSS Exception");
}


void int11_handler(void)
{
    bsod("Segment Not Present Exception");
}


void int12_handler(void)
{
    bsod("Stack Fault Exception");
}


void int13_handler(void)
{
    bsod("General Protection Fault Exception");
}


void int14_handler(void)
{
    bsod("Page Fault Exception");
}


void int15_handler(void)
{
    bsod("Unknown Interrupt Exception");
}


void int16_handler(void)
{
    bsod("Coprocessor Fault Exception");
}


void int17_handler(void)
{
    bsod("Alignment Check Exception (486+)");
}


void int18_handler(void)
{
    bsod("Machine Check Exception (Pentium/586+)");
}

void reserved_handler(void)
{
    bsod("Unknown Exception!");
}