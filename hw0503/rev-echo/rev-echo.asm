;rev-echo.asm
		global 		main
		extern 		reverse_range_in_place
		extern 		printf
		extern		puts
		extern 		strlen
		section 	.text
main:	
		push 	rbx
		mov		r13, rdi	; r13 stores number of arguments (count of strings to reverse)
		mov		r12, rsi 	; r12 stores pointer to rsi
next:	
		mov 	rdi, [r12] 	; move string to current arg to rdi
		;push	r12			; store r12 for later use
		call	strlen		; get length of arg and store in rax
		mov		rdx, rax	; move contents of rax to rdx (last argument of rev range)
		
		;mov 	rsi, rdx
		;mov 	rdi, num_format
		;call 	printf
		;call	puts
		
		;call 	printf
		;mov		rdx, rax	
		xor		rsi, rsi		; second arg (start of string) should be 0
		push 	rdi				; to make sure rdi address remains constant
		call	reverse_range_in_place
		pop 	rsi
		mov 	rdi, format
		call 	printf
		xor		rax, rax
		add		r12, 8
		dec		r13
		jnz		next
		pop 	rbx
		ret
format:
		db "%s",10,0
num_format: 
		db "%d",10,0

			
