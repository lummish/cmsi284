		global main
		extern atoi
		extern printf
		extern puts
		section .text

main:	
		push 	rbx				; necessary convention
		cmp 	rdi, 2 			; 
		jne		incorrect_args_error
		mov		rdi, [rsi + 8]	; move user entered amount to make change of into rdi
		call	atoi			; turn contents of rdi into integer in rax 
		cmp 	rax, 0
		jl 		negative_error

add_quarters:
		xor 	rdx, rdx		; set all bits in rdx to 0 to nullify msb in dividend
		mov 	rcx, [q]		; set value of rcx to current coin value
		div 	rcx 			; unsigned divide
		push	rax				; push quotient to stack
		push	rdx 			; want to store remaining value after removing coin
		xor 	rax, rax 		; reset rax for next label

add_dimes:
		pop		rax 			; pops previous remainder from top of stack and stores in rax
		xor 	rdx, rdx
		mov 	rcx, [d]		; set value of rcx to current coin value
		div 	rcx 			; unsigned divide
		push	rax				; push quotient to stack
		push	rdx 			; want to store remaining value after removing coin
		xor 	rax, rax		; reset rax for next label

add_nickels:
		pop		rax 			; pops previous remainder from top of stack and stores in rax
		xor		rdx, rdx
		mov 	rcx, [n]		; set value of rcx to current coin value
		div 	rcx 			; unsigned divide
		push	rax				; push quotient to stack
		push	rdx 			; want to store remaining value after removing coin
		xor 	rax, rax		; reset rax for next label
		jmp		output

q:		
		dq 	25

d:
		dq 	10

n:
		dq 	5

quarter_format:
		db "Number of quarters: %d", 10, 0

dime_format:
		db "Number of dimes: %d", 10, 0

nickel_format:
		db "Number of nickels: %d", 10, 0

penny_format:
		db "Number of pennies: %d", 10, 0

debug_format:
		db "Number of quarters: %d, Remainder: %d, rcx: %d", 10, 0

debug_dividend:
		db "Dividend: %d", 10, 0

debug_divisor:
		db "Divisor: %d", 10, 0

negative_amt_format:
		db "Cannot make negative change.", 10, 0

incorrect_args_format:
		db "Incorrect number of arguments.", 10, 0

negative_error:
		mov 	rdi, negative_amt_format
		call 	puts
		jmp 	end

incorrect_args_error:
		mov 	rdi, incorrect_args_format
		call 	puts
		jmp 	end

output:
		mov 	rdi, penny_format  ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of pennies)
		xor 	rax, rax
		call 	printf

		mov 	rdi, nickel_format ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of nickels)
		xor 	rax, rax
		call 	printf

		mov 	rdi, dime_format 	 ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of nickels)
		xor 	rax, rax
		call 	printf

		mov 	rdi, quarter_format ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of nickels)
		xor 	rax, rax
		call 	printf		
end:
		pop 	rbx 					;necessary convention
		ret

