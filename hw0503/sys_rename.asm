;sys_rename.asm

		global 		main
		extern		printf
		extern		puts
main:
		push 	rbx
		cmp		rdi, 3			;ensure proper number of arugments
		jne		error
		mov		rdi, [rsi + 8]	;get original name of file (should be first arg)
		mov		rsi, [rsi + 16] ;get desired name of file
		mov		rax, 82			;number of system call
		syscall
		cmp		rax, 0			;if exits with code other than 0, error.
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