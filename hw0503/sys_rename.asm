;sys_rename.asm

		global 		main
		extern		printf
		extern		puts
main:
		push 	rbx
		cmp		rdi, 3
		jne		error
		mov		rdi, [rsi + 8]
		mov		rsi, [rsi + 16]
		mov		rax, 82
		syscall
		cmp		rax, 0
		jne		error
		mov		rdx, rsi
		mov		rsi, rdi
		mov		rdi, format_str
		call	printf
		jmp		end
error:
		mov		rdi, error_str
		call 	puts
end:	
		pop 	rbx
		ret
error_str:
		db "Argument error",0
format_str:
		db "%s renamed to %s.",10,0