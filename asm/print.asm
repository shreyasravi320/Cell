global print
global println

print:
    mov   r8, -3689348814741910323
    sub   rsp, 40
    lea   rcx, [rsp+31]
.L2:
    mov   rax, rdi
    mul   r8
    mov   rax, rdi
    shr   rdx, 3
    lea   rsi, [rdx+rdx*4]
    add   rsi, rsi
    sub   rax, rsi
    mov   rsi, rcx
    sub   rcx, 1
    add   eax, 48
    mov   BYTE [rcx+1], al
    mov   rax, rdi
    mov   rdi, rdx
    cmp   rax, 9
    ja    .L2
    lea   rdx, [rsp+32]
    mov   edi, 1
    xor   eax, eax
    sub   rdx, rsi
    mov   rax, 1
    syscall
    add   rsp, 40
    ret

println:
    mov   r8, -3689348814741910323
    sub   rsp, 40
    mov   BYTE [rsp+31], 10
    lea   rcx, [rsp+30]
    jmp   print.L2
    ret