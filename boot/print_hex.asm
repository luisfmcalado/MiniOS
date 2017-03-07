; https://github.com/sukwon0709/osdev/blob/master/print_hex.asm

print_hex:
    ; manipulate chars at HEX_OUT to reflect DX
    mov cx, dx
    and cx, 0xf000
    shr cx, 12
    call to_char
    mov [HEX_OUT + 2], cx

    mov cx, dx
    and cx, 0x0f00
    shr cx, 8
    call to_char
    mov [HEX_OUT + 3], cx

    mov cx, dx
    and cx, 0x00f0
    shr cx, 4
    call to_char
    mov [HEX_OUT + 4], cx

    mov cx, dx
    and cx, 0x000f
    call to_char
    mov [HEX_OUT + 5], cx

    mov bx, HEX_OUT
    call print_string
    mov byte [HEX_OUT + 2], '0'
    mov byte [HEX_OUT + 3], '0'
    mov byte [HEX_OUT + 4], '0'
    mov byte [HEX_OUT + 5], '0'
    ret

to_char:
    cmp cx, 0xa
    jl digits
    sub cx, 0xa
    add cx, 'a'
    ret
    
digits:
    add cx, '0'
    ret
    
HEX_OUT: db '0x0000', 0