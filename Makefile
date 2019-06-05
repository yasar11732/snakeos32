CC=/root/opt/cross/bin/i686-elf-gcc
AS=/root/opt/cross/bin/i686-elf-as
COMPILER_ARGS=-g -ffreestanding -O2 -nostdlib -Wall -Wextra
LINKER_ARGS=-lgcc
OBJ=build/boot.o build/kernel.o build/gdt-s.o build/gdt-c.o

build/snakeos32.iso: build/snakeos32.bin grub.cfg
	mkdir -p build/isodir/boot/grub
	yes | cp grub.cfg build/isodir/boot/grub
	yes | cp build/snakeos32.bin build/isodir/boot
	grub-mkrescue -o build/snakeos32.iso build/isodir

build/boot.o: boot.s
	$(AS) boot.s -o build/boot.o

build/gdt-s.o: gdt.s
	$(AS) gdt.s -o build/gdt-s.o

build/gdt-c.o: gdt.c
	$(CC) -c $^ -o $@ $(COMPILER_ARGS)

build/kernel.o: kernel.c
	$(CC) -c $^ -o $@ $(COMPILER_ARGS)

build/snakeos32.bin: linker.ld $(OBJ)
	$(CC) -T linker.ld -o $@ $(COMPILER_ARGS) $(OBJ) $(LINKER_ARGS) 
	
clean:
	rm -f $(OBJ)

