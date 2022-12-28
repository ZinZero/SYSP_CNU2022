.section .data
printf_str:
	.string "%d is greater \n"
val1:
	.int 150
val2:
	.int 300

.section .text
.global main
main:
	movl val1, %esi
	movl val2, %edx

	cmpl %edx, %esi
	jg greater
	movl %edx, %esi

greater:
	movq $printf_str, %rdi
	movq $0, %rax
	call printf
	ret
