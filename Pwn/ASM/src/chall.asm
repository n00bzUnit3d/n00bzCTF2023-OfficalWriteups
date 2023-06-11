global _start

section .text
	vuln:

		mov rax, 1        ; write(
		mov rdi, 1        ;   STDOUT_FILENO,
		mov rsi, msg      ;   "Hello, world!!\n",
		mov rdx, msglen   ;     sizeof("Hello, world!!\n")
		syscall           ; );

		sub rsp, 0x20

		mov rax, 0        ; read(
		mov rdi, 0        ;   STDIN_FILENO,
		mov rsi, rsp      ;   buf,
		mov rdx, 0x200    ;   0x100
		syscall           ; );

		add rsp, 0x20

		ret


	_start:
		call vuln

		mov rax, 60       ; exit(
		mov rdi, 0        ;   EXIT_SUCCESS
		syscall           ; );
		ret

section .rodata
	msg: db "Hello, world!!", 10
	msglen: equ $ - msg
	binsh: db "/bin/sh", 0
