		global main
		extern printf
		extern puts
		extern atoi
		section .text
main:
		push 	rbx				; necessary convention
		cmp 	rdi, 2			; ensure proper number of args
		jne		arg_error
		mov 	rdi, [rsi + 8]	
		call 	atoi
		push 	rax				; will need to be able to access this value even after divide	
		mov 	rcx, 4			; will use to divide by 4
		xor		rdx, rdx
		div  	rcx
		cmp		rdx, 0			; if 4 does not evenly divide into year, return no
		jne		no_out
		;sub 	rsp, 8			; align stack (maybe)
		;mov	rax, [rsp]  ; ask question about aligning stack
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
arg_out:
		db 	"Improper argument format.", 10, 0
yes_out:
		mov 	rdi, yes_string
		pop 	rsi
		jmp 	end
no_out:
		mov 	rdi, no_string
		pop 	rsi
		jmp 	end
yes_string:
	db 	"The year %d is a leap year", 10, 0
no_string:
	db 	"The year %d is not a leap year", 10, 0
end:	
		call 	printf
		pop 	rbx
		ret
