.section .data
msg:
	.string "val1=%d, val2=%d, val3=%d\n"
val1:
	.int 100
val2:
	.int 200
val3:
	.int 300

.section .text
.global main
main:
	movq $msg, %rdi
	movq val1, %rsi
	movq val2, %rdx
	movq val3, %rcx

	movq $0, %rax
	call printf
	movq $0, %rax
	ret
