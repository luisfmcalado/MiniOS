print_string:
    pusha
    mov ah, 0x0e
loops:
    mov al, [bx]
    int 0x10
    add bx, 1
    cmp al, 0
    jne loops
    popa
    ret
    
print_new_line:
    mov ah , 0x0e
    mov al, 0x0d
    int 0x10
    mov al, 0x0a
    int 0x10
    ret
