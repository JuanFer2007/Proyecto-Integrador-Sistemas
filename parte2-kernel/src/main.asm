global start
extern long_mode_start

section .text
bits 32
start:
    mov esp, stack_top

    ; Configurar tablas de páginas (Mapear 1 GB)
    mov eax, page_table_p3
    or eax, 0b11 ; present + writable
    mov [page_table_p4], eax

    mov eax, page_table_p2
    or eax, 0b11 ; present + writable
    mov [page_table_p3], eax

    mov eax, 0b10000011 ; present + writable + huge (2MB)
    mov [page_table_p2], eax

    ; Pasar tablas al procesador
    mov eax, page_table_p4
    mov cr3, eax

    ; Activar PAE
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ; Activar Long Mode
    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr

    ; Activar Paginación
    mov eax, cr0
    or eax, 1 << 31
    mov cr0, eax

    ; Cargar la GDT de 64 bits
    lgdt [gdt64.pointer]
    jmp gdt64.code:long_mode_start

    hlt

section .bss
align 4096
page_table_p4:
    resb 4096
page_table_p3:
    resb 4096
page_table_p2:
    resb 4096
stack_bottom:
    resb 64
stack_top:

section .rodata
gdt64:
    dq 0
.code: equ $ - gdt64
    dq (1<<43) | (1<<44) | (1<<47) | (1<<53)
.pointer:
    dw $ - gdt64 - 1
    dq gdt64

