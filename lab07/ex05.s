.section .data
printf_str:
    .string "x : %d, result : %d\n"
x:
    .int 1

.section .text
.global main
main:
    movl x, %esi

    cmpl $0, %esi
    movl $50, %edx
    je END

    cmpl $1, %esi
    movl $100, %edx
    je END

    movl $0, %edx

END:
    movq $printf_str, %rdi
    movq $0, %rax
    call printf
    ret