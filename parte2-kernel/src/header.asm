section .multiboot_header
align 8
header_start:
    dd 0xe85250d6                ; Número mágico para Multiboot2
    dd 0                         ; Arquitectura 0 (Modo protegido de 32 bits)
    dd header_end - header_start ; Longitud del encabezado
    ; Checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    ; Etiquetas obligatorias de finalización
    dw 0    ; tipo
    dw 0    ; banderas
    dd 8    ; tamaño
header_end:

