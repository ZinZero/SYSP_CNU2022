.section .data
message:
	.string "val1=%d, val2=%d, val1+val2=%d\n"
val1:
	.int 100
val2:
	.int 200

.section .text
.global main
main:
	movq $message, %rdi

	movq val1, %rsi
	movq val2, %rdx

	addq %rsi, %rdx

	movq %rdx, %rcx
	movq val2, %rdx

	movq $0, %rax
	call printf
	ret
.end
