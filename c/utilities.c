#include "kernel.h"
#include <stddef.h>

void *memset(void *ptr, int value, size_t num)
{
    char *t = ptr;

    while(num--)
        *t++ = value;

    return ptr;
}