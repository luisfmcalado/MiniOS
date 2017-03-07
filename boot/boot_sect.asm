; A boot sector that enters 32- bit protected mode.
[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl

mov bp, 0x9000 ; Set the stack.
mov sp, bp

call print_new_line
mov bx, MSG_REAL_MODE
call print_string

;call print_new_line
;mov bx, KERNEL_VERSION
;call print_string

call load_kernel

call switch_to_pm ; Note that we never return from here.

jmp $

;KERNEL_VERSION :
;    db 'kernel v0.0.1', 0x0d, 0x0a, 0

%include "print_string.asm"
%include "gdt.asm"
%include "print_string_pm.asm"
%include "switch_to_pm.asm"
%include "disk_load.asm"

[bits 16]

load_kernel:
	mov bx, MSG_LOAD_KERNEL
	call print_string

	mov bx, KERNEL_OFFSET
	mov dh, 15
	mov dl, [BOOT_DRIVE]
	call disk_load

	ret

[bits 32]

; This is where we arrive after switching to and initialising protected mode.
BEGIN_PM:
	mov ebx , MSG_PROT_MODE
	call print_string_pm ; Use our 32- bit print routine.

	call KERNEL_OFFSET
	
	jmp $ ; Hang.

; Global variables
MSG_REAL_MODE db "Started in 16-bit Real Mode", 0
MSG_PROT_MODE db "Successfully landed in 32-bit Protected Mode", 0
BOOT_DRIVE db 0
MSG_LOAD_KERNEL db "Loading kernel into memory", 0


; Bootsector padding
times 510 -($-$$) db 0
dw 0xaa55
