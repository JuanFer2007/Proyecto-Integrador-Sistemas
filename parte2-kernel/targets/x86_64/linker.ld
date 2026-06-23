ENTRY(start)

SECTIONS
{
    . = 1M;

    .boot :
    {
        /* Asegura que el encabezado multiboot2 esté al inicio absoluto */
        KEEP(*(.multiboot_header))
    }

    .text :
    {
        *(.text)
    }

    .rodata : ALIGN(4K)
    {
        *(.rodata)
    }

    .data : ALIGN(4K)
    {
        *(.data)
    }

    .bss : ALIGN(4K)
    {
        *(.bss)
        *(COMMON)
    }
}


