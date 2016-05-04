;madlib-by-numbers.asm
		global 	main 
		extern 	madlib_by_numbers
		extern 	puts
		extern 	atoi
		extern	printf
		section .text
main:
		push 	rbx
		sub		rdi, 2
		cmp 	rdi, 0	; need to ensure that there are at least 0 words to substitute in 
		jl		error
		push 	rdi				; need to keep track of word count
		mov 	rdi, [rsi + 8]	; store template in rdi
		add		rsi, 16			
		mov 	rdx, rsi		; store pointer to word array in rdx
		pop		rsi						
		call	madlib_by_numbers
		mov		rsi, rdi
		mov		rdi, output
		mov 	rsi, rax
		xor 	rax, rax
		sub 	rsp, 8
		call	printf
		add		rsp, 8
		jmp		end
error:
		mov 	rdi, error_format
		call 	puts

end:
		pop 	rbx
		ret
error_format:
		db "Argument error.",10,0
output:
		db "%s",10,0

