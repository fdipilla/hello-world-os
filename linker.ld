ENTRY (start)
SECTIONS{
        . =0x00100000;
        .text : {
              *(.text)
        }
        .rodata ALIGN (0x1000) : {
              *(.data)
        }
        .bss : {
              sbss = .;
              *(COMMON)
              *(.bss)
              ebss = .;
        }
}