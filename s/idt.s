.section .text

.global idt_load
.type idt_load, @function
idt_load:
	lidt idtp
	ret

.global int0
.type int0,@function
.align 4
int0:
    pushal
    cld
    call int0_handler
    popal
    iret
.global int1
.type int1,@function
.align 4
int1:
    pushal
    cld
    call int1_handler
    popal
    iret
.global int2
.type int2,@function
.align 4
int2:
    pushal
    cld
    call int2_handler
    popal
    iret
.global int3
.type int3,@function
.align 4
int3:
    pushal
    cld
    call int3_handler
    popal
    iret
.global int4
.type int4,@function
.align 4
int4:
    pushal
    cld
    call int4_handler
    popal
    iret
.global int5
.type int5,@function
.align 4
int5:
    pushal
    cld
    call int5_handler
    popal
    iret
.global int6
.type int6,@function
.align 4
int6:
    pushal
    cld
    call int6_handler
    popal
    iret
.global int7
.type int7,@function
.align 4
int7:
    pushal
    cld
    call int7_handler
    popal
    iret
.global int8
.type int8,@function
.align 4
int8:
    pushal
    cld
    call int8_handler
    popal
    iret
.global int9
.type int9,@function
.align 4
int9:
    pushal
    cld
    call int9_handler
    popal
    iret
.global int10
.type int10,@function
.align 4
int10:
    pushal
    cld
    call int10_handler
    popal
    iret
.global int11
.type int11,@function
.align 4
int11:
    pushal
    cld
    call int11_handler
    popal
    iret
.global int12
.type int12,@function
.align 4
int12:
    pushal
    cld
    call int12_handler
    popal
    iret
.global int13
.type int13,@function
.align 4
int13:
    pushal
    cld
    call int13_handler
    popal
    iret
.global int14
.type int14,@function
.align 4
int14:
    pushal
    cld
    call int14_handler
    popal
    iret
.global int15
.type int15,@function
.align 4
int15:
    pushal
    cld
    call int15_handler
    popal
    iret
.global int16
.type int16,@function
.align 4
int16:
    pushal
    cld
    call int16_handler
    popal
    iret
.global int17
.type int17,@function
.align 4
int17:
    pushal
    cld
    call int17_handler
    popal
    iret
.global int18
.type int18,@function
.align 4
int18:
    pushal
    cld
    call int18_handler
    popal
    iret

.global reserved
.type reserved,@function
.align 4
reserved:
    pushal
    cld
    call reserved_handler
    popal
    iret