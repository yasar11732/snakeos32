.section .text

.global irq0
.type irq0,@function
.align 4
irq0:
    pushal
    cld
    call irq0_handler
    popal
    iret
.global irq1
.type irq1,@function
.align 4
irq1:
    pushal
    cld
    call irq1_handler
    popal
    iret
.global irq2
.type irq2,@function
.align 4
irq2:
    pushal
    cld
    call irq2_handler
    popal
    iret
.global irq3
.type irq3,@function
.align 4
irq3:
    pushal
    cld
    call irq3_handler
    popal
    iret
.global irq4
.type irq4,@function
.align 4
irq4:
    pushal
    cld
    call irq4_handler
    popal
    iret
.global irq5
.type irq5,@function
.align 4
irq5:
    pushal
    cld
    call irq5_handler
    popal
    iret
.global irq6
.type irq6,@function
.align 4
irq6:
    pushal
    cld
    call irq6_handler
    popal
    iret
.global irq7
.type irq7,@function
.align 4
irq7:
    pushal
    cld
    call irq7_handler
    popal
    iret
.global irq8
.type irq8,@function
.align 4
irq8:
    pushal
    cld
    call irq8_handler
    popal
    iret
.global irq9
.type irq9,@function
.align 4
irq9:
    pushal
    cld
    call irq9_handler
    popal
    iret
.global irq10
.type irq10,@function
.align 4
irq10:
    pushal
    cld
    call irq10_handler
    popal
    iret
.global irq11
.type irq11,@function
.align 4
irq11:
    pushal
    cld
    call irq11_handler
    popal
    iret
.global irq12
.type irq12,@function
.align 4
irq12:
    pushal
    cld
    call irq12_handler
    popal
    iret
.global irq13
.type irq13,@function
.align 4
irq13:
    pushal
    cld
    call irq13_handler
    popal
    iret
.global irq14
.type irq14,@function
.align 4
irq14:
    pushal
    cld
    call irq14_handler
    popal
    iret
.global irq15
.type irq15,@function
.align 4
irq15:
    pushal
    cld
    call irq15_handler
    popal
    iret
