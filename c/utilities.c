#include "kernel.h"
#include <stddef.h> // size_t
#include <stdint.h> // uint16_t uint8_t

void *memset(void *ptr, int value, size_t num)
{
    char *t = ptr;

    while(num--)
        *t++ = value;

    return ptr;
}

void enable_interrupts(int flags)
{
    if(flags) {
        __asm__ __volatile__ ("sti");
    } else {
        __asm__ __volatile__ ("cli");
    }
}

unsigned char inb(uint16_t port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (port));
    return rv;
}

void outb(uint16_t port, uint8_t data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (data));
}

void wait_forever()
{
    for (;;)
        __asm__ __volatile__("hlt");
}