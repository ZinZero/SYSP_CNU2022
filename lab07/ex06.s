.section .data
message:
    .string "%d + %d = %d\n"
val1:
    .int 100
val2:
    .int 200

.section .text
.global main
main:
    movq val1, %rsi
    movq val2, %rdx
    call add_func

    movq %rax, %rcx
    movq val1, %rsi
    movq val2, %rdx
    movq $message, %rdi
    movq $0, %rax
    call printf
    ret

.type add_func, @function
add_func:
    movq %rsi, %rax
    addq %rdx, %rax
    ret