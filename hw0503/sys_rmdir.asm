;sys_rmdir.asm
		global		main
		extern		printf
		extern		puts
		section		.text
main:
		cmp			rdi, 2
		jne			error 			; output error string if program has improper # of args
		mov			rdi, [rsi + 8]	; set rdi to first arg
		mov			rax, 84			; prep for system call
		syscall
		cmp			rax, 0			; ensure no errors
		jne			error
		mov			rsi, rdi 
		mov			rdi, format_str
		call		printf
		jmp 		end
error:
		mov			rdi, error_str
		call		puts
end:
		ret
error_str:
		db "Argument error.",0
format_str:
		db "Removed directory %s",10,0