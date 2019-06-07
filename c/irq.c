#include "kernel.h"
#include <stddef.h>
#include <stdint.h>

#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)

#define ICW1_ICW4	0x01		/* ICW4 (not) needed */
#define ICW1_INIT	0x10		/* Initialization - required! */
 
#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */

#define PIC_EOI		0x20		/* End-of-interrupt command code */

#define PIC_READ_IRR                0x0a    /* OCW3 irq ready next CMD read */
#define PIC_READ_ISR                0x0b    /* OCW3 irq service next CMD read */


void irq_init()
{
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

    outb(PIC1_DATA, 0x20);
    outb(PIC2_DATA, 0x28);

    outb(PIC1_DATA, 4); // 0000 0100 IRQ 2 comes from slave
    outb(PIC2_DATA, 2); // our cascade ID is 2

    outb(PIC1_DATA, ICW4_8086); // we are in 8086 mode
    outb(PIC2_DATA, ICW4_8086); // we are in 8086 mode

    outb(PIC1_DATA, 0x00); // unmask all interrupts
    outb(PIC2_DATA, 0x00); // unmask all interrupts
}


 
void PIC_sendEOI(unsigned char irq)
{
	if(irq >= 8)
		outb(PIC2_COMMAND,PIC_EOI);
 
	outb(PIC1_COMMAND,PIC_EOI);
}

void IRQ_set_mask(unsigned char IRQline) {
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) | (1 << IRQline);
    outb(port, value);        
}
 
void IRQ_clear_mask(unsigned char IRQline) {
    uint16_t port;
    uint8_t value;
 
    if(IRQline < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        IRQline -= 8;
    }
    value = inb(port) & ~(1 << IRQline);
    outb(port, value);        
}

 
/* Helper func */
static uint16_t __pic_get_irq_reg(int ocw3)
{
    /* OCW3 to PIC CMD to get the register values.  PIC2 is chained, and
     * represents IRQs 8-15.  PIC1 is IRQs 0-7, with 2 being the chain */
    outb(PIC1_COMMAND, ocw3);
    outb(PIC2_COMMAND, ocw3);
    return (inb(PIC2_COMMAND) << 8) | inb(PIC1_COMMAND);
}
 
/* Returns the combined value of the cascaded PICs irq request register */
uint16_t pic_get_irr(void)
{
    return __pic_get_irq_reg(PIC_READ_IRR);
}
 
/* Returns the combined value of the cascaded PICs in-service register */
uint16_t pic_get_isr(void)
{
    return __pic_get_irq_reg(PIC_READ_ISR);
}

int isSpurious(int IRQ)
{
    uint16_t isr = pic_get_isr();
    if(isr & (1 << IRQ))
        return 0;
    else
        return 1;
}

void null_irq_handler(int IRQ)
{
    if(!isSpurious(IRQ))
    {
        PIC_sendEOI(IRQ);
    } else
    {
        if(IRQ == 15)
        {
            outb(PIC1_COMMAND,PIC_EOI);
        }
    }
}


void irq1_handler()
{
    null_irq_handler(1);
}
void irq2_handler()
{
    null_irq_handler(2);
}
void irq3_handler()
{
    null_irq_handler(3);
}
void irq4_handler()
{
    null_irq_handler(4);
}
void irq5_handler()
{
    null_irq_handler(5);
}
void irq6_handler()
{
    null_irq_handler(6);
}
void irq7_handler()
{
    null_irq_handler(7);
}
void irq8_handler()
{
    null_irq_handler(8);
}
void irq9_handler()
{
    null_irq_handler(9);
}
void irq10_handler()
{
    null_irq_handler(10);
}
void irq11_handler()
{
    null_irq_handler(11);
}
void irq12_handler()
{
    null_irq_handler(12);
}
void irq13_handler()
{
    null_irq_handler(13);
}
void irq14_handler()
{
    null_irq_handler(14);
}
void irq15_handler()
{
    null_irq_handler(15);
}