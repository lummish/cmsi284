;rev-echo.asm
		global 		main
		extern 		reverse_range_in_place
		extern 		printf
		extern		puts
		extern 		strlen
		section 	.text
main:	
		push 	rbx
		mov		r13, rdi
		mov		r12, rsi
next:	
		mov 	rdi, [r12]
		call	strlen
		xor		rax, rax
		call	puts
		mov		rdi, rax
		

		mov		rdi, rax
		call 	printf
		mov		rcx, rax
		xor		rsi, rsi
		pop		rdi
		call	reverse_range_in_place
		mov		rsi, rdi
		mov		rdi, format
		call	printf
		add		r12, 8
		dec		r13
		jnz		next
		pop 	rbx
		ret
format:
		db "%s",10,0
num_format: 
		db "%d",10,0

			
