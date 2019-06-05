.section .text

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