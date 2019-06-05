
.section .text
.global gdt_flush
.type gdt_flush, @function
gdt_flush:
    lgdt gp       
    mov $0x10,%ax    
    mov %ax,%ds
    mov %ax,%es
    mov %ax,%fs
    mov %ax,%gs
    mov %ax,%ss
    jmp $0x08, $flush2   
flush2:
    ret
