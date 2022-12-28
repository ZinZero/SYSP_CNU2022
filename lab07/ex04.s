.section .data
printf_str:
	.string "result : %d\n"
i:
	.int 0
sum:
	.int 0
n:
	.int 10

.section .text
.global main
main:
	movl n, %esi
	movl sum, %edx
	movl i, %ecx

loop:
	addl %ecx, %edx
	incl %ecx
	cmpl %esi, %ecx
	jle loop

	movl %edx, %esi

	movq $printf_str, %rdi
	movq $0, %rax
	call printf
	ret
