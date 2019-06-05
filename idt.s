
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

.global idt_load
.type idt_load, @function
idt_load:
	lidt idtp
	ret
 
.global enable_interrupts
.type enable_interrupts, @function
enable_interrupts:
	sti
	ret

.global force_error
.type force_error, @function
force_error:
	mov $0, %ebx
	div %ebx
	ret
	
.global fault_handler
.type fault_handler, @function
fault_handler:
	call bsod
halting_loop:
	hlt
	jmp halting_loop