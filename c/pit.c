
#include "kernel.h"

#define PIT_COMMAND 0x43
#define PIT_CHANNEL0_DATA 0x40
#define PIT_CHANNEL1_DATA 0x41
#define PIT_CHANNEL2_DATA 0x42

#define PIT_COUNTER_0 0x00
#define PIT_COUNTER_1 0x40
#define PIT_COUNTER_2 0x80

#define PIT_RWMODE_LSB 0x10
#define PIT_RWMODE_MSB 0x20
#define PIT_RWMODE_LSBMSB 0x30

#define PIT_MODE_TERMINAL_COUNT  0x00
#define PIT_MODE_ONE_SHOT        0x02
#define PIT_MODE_RATE            0x04
#define PIT_MODE_SQUARE          0x06
#define PIT_MODE_SOFTWARE_STROBE 0x08
#define PIT_MODE_HARDWARE_STROBE 0x0A

#define PIT_NO_BCD 0x00
#define PIT_BCD    0x01

volatile int timer_ticks;

void timer_phase(int hz)
{
    int divisor = 1193180 / hz;
    outb(PIT_COMMAND, PIT_COUNTER_0 | PIT_RWMODE_LSBMSB | PIT_MODE_SQUARE | PIT_NO_BCD);
    outb(PIT_CHANNEL0_DATA, divisor & 0xFF);
    outb(PIT_CHANNEL0_DATA, divisor >> 8);
}

void irq0_handler()
{
    timer_ticks++;
    PIC_sendEOI(0);
}

void delay(int ms)
{
    int start = timer_ticks;
    while(timer_ticks - start < ms)
    {
        __asm__ __volatile__("hlt");
    }
}