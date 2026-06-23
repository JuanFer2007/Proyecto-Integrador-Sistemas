global long_mode_start
extern main_c

section .text
bits 64
long_mode_start:
    ; Cargar registros de datos limpios para modo largo
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; CORRECCIÓN CRÍTICA: Alinear la pila a 16 bytes para evitar el Triple Fault
    mov rsp, stack_top
    and rsp, -16         ; Borra los bits bajos para forzar alineación de 16 bytes
    sub rsp, 8           ; Ajuste de espacio para la llamada de retorno

    ; Saltar al código principal en C
    call main_c
    hlt

section .bss
align 16
stack_bottom:
    resb 16384           ; Reservar 16KB de espacio de pila estable
stack_top:

