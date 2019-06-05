SNAKEOS32
========

This is second iteration of my snakeos project, it is called snakeos32.
I orignally aimed to write a complete snake game in real mode, that could
fit in a 512 byte boot sector.

My original snakeos project died prematurely, because;

1. It is hard to write programs for real mode, because of the lack of C compiler support for real mode applications. Therefore, I had to implement everything using assembly language.
2. It is hard to write programs for real mode, because of the lack of proper debuggers. Virtualbox integrated debugger used to work, but, stopped functioning properly for some unknown reason. GDB misinterprets instruction pointers in real mode.
3. I had to roll my own bootloader beucase grub automatically switches to protected mode.

In this project, I will do these things differently,

1. I will not depend on any bios functionality
2. I will let grub to load my program.
3. I will implement my own interrupt handlers.
4. I will keep assembly language to minimum

With these improvements, I think I can get it to work.
