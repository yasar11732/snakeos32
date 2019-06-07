CC=/root/opt/cross/bin/i686-elf-gcc
COMPILER_ARGS=-I./h -g -ffreestanding -O2 -nostdlib -Wall -Wextra -Werror
LINKER_ARGS=-lgcc
SRCC=$(wildcard c/*.c)
SRCS=$(wildcard s/*.s)
COBJ=$(patsubst c/%.c,build/c/%.o,$(SRCC))
SOBJ=$(patsubst s/%.s,build/s/%.o,$(SRCS))

OBJ=$(COBJ)
OBJ+=$(SOBJ)
	
build/snakeos32.iso: build/snakeos32.bin grub.cfg
	mkdir -p build/isodir/boot/grub
	yes | cp grub.cfg build/isodir/boot/grub
	yes | cp build/snakeos32.bin build/isodir/boot
	grub-mkrescue -o build/snakeos32.iso build/isodir

build/c/%.o: c/%.c h/kernel.h
	mkdir -p build/c
	$(CC) -c $< -o $@ $(COMPILER_ARGS)

build/s/%.o: s/%.s h/kernel.h
	mkdir -p build/s
	$(CC) -c $< -o $@ $(COMPILER_ARGS)

build/snakeos32.bin: linker.ld $(OBJ)
	$(CC) -T linker.ld -o $@ $(COMPILER_ARGS) $(OBJ) $(LINKER_ARGS) 
	
clean:
	rm -vr build

