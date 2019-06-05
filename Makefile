CC=/root/opt/cross/bin/i686-elf-gcc
AS=/root/opt/cross/bin/i686-elf-as

build/snakeos32.iso: build/snakeos32.bin grub.cfg
	mkdir -p build/isodir/boot/grub
	yes | cp grub.cfg build/isodir/boot/grub
	yes | cp build/snakeos32.bin build/isodir/boot
	grub-mkrescue -o build/snakeos32.iso build/isodir

build/boot.o: boot.s
	$(AS) boot.s -o build/boot.o

build/kernel.o: kernel.c
	$(CC) -c kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

build/snakeos32.bin: linker.ld build/boot.o build/kernel.o
	$(CC) -T linker.ld -o build/snakeos32.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o -lgcc
	
clean:
	rm -f build/snakeos32.iso build/boot.o build/kernel.o build/snakeos32.bin

