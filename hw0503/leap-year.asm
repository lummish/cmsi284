		global main
		extern printf
		extern puts
		extern atoi
		section .text
main:							; ask Dondi about handling string arguments
		push 	rbx				; necessary convention
		cmp 	rdi, 2			; ensure proper number of args
		jne		arg_error
		mov 	rdi, [rsi + 8]	
		call 	atoi
		cmp		rax, 0			; if year is negative, improper input
		jl		arg_error
		push 	rax				; will need to be able to access this value even after divide	
		mov 	rcx, 4			; will use to divide by 4
		xor		rdx, rdx
		div  	rcx
		cmp		rdx, 0			; if 4 does not evenly divide into year, return no
		jne		no_out
		pop 	rax				; instead of just peaking at stack for now
		push	rax				; store rax back in the stack
		mov		rcx, 100		; to check divisible by 100
		xor 	rdx, rdx
		div 	rcx
		cmp		rdx, 0
		jne 	yes_out			;year divisible by 4 but not 100 		
		mov 	rcx, 4							
		xor 	rdx, rdx
		div 	rcx
		cmp		rdx, 0
		jne		no_out
		jmp		yes_out
arg_error:
		mov 	rdi, arg_out
		jmp 	end
yes_out:
		mov 	rdi, yes_string
		pop 	rsi
		jmp 	end
no_out:
		mov 	rdi, no_string
		pop 	rsi
end:	
		call 	printf
		pop 	rbx
		ret
arg_out:
		db 	"Improper argument format.", 10, 0
yes_string:
	db 	"The year %d is a leap year", 10, 0
no_string:
	db 	"The year %d is not a leap year", 10, 0

