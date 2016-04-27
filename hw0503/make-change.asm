		global main
		extern atoi
		extern printf
		section .text
main:	
		mov		rdi, [rsi + 8]	; move user entered amount to make change of into rdi
		call	atoi			; turn contents of rdi into integer in rax 
		;mov 	rdi, rax; 		; move rax back into rdi, rdi stores total remaining value
add_quarters:
		mov 	rdx, 0 			; to track remainder
		mov 	rcx, [q]		; set value of rcx to current coin value
		div 	rcx 			; unsigned divide
		push	rax				; push quotient to stack
		push	rdx 			; want to store remaining value after removing coin
		xor 	rax, rax 		; reset rax for next label
add_dimes:
		pop		rax 			; pops previous remainder from top of stack and stores in rax
		mov 	rdx, 0 			; to track remainder
		mov 	rcx, [d]		; set value of rcx to current coin value
		div 	rcx 			; unsigned divide
		push	rax				; push quotient to stack
		push	rdx 			; want to store remaining value after removing coin
		xor 	rax, rax		; reset rax for next label
add_nickels:
		pop		rax 			; pops previous remainder from top of stack and stores in rax
		mov 	rdx, 0 			; to track remainder
		mov 	rcx, [n]		; set value of rcx to current coin value
		div 	rcx 			; unsigned divide
		push	rax				; push quotient to stack
		push	rdx 			; want to store remaining value after removing coin
		xor 	rax, rax		; reset rax for next label
		jmp		output

;add_pennies:
;		pop		rax 			; pops previous remainder from top of stack and stores in rax
;		mov 	rdx, 0 			; to track remainder
;		mov 	rcx, [q]		; set value of rcx to current coin value
;		div 	rcx 			; unsigned divide
;		push	rax				; push quotient to stack
;		push	rdx 			; want to store remaining value after removing coin
;		xor 	rax, rax		; reset rax for next label
;
;		mov 	rdi, [pennies_format]
;		mov 	rsi, rax
;		call 	printf

q:		
		dq 	25

d:
		dq 10

n:
		dq 5

quarter_format:
		db "Number of quarters: %d", 10, 0

dime_format:
		db "Number of dimes: %d", 10, 0

nickel_format:
		db "Number of nickels: %d", 10, 0

penny_format:
		db "Number of pennies: %d", 10, 0

output:
		mov 	rdi, [penny_format]  ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of pennies)
		call 	printf
		mov 	rdi, [nickel_format] ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of nickels)
		call 	printf
		mov 	rdi, [dime_format] 	 ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of nickels)
		call 	printf
		mov 	rdi, [quarter_format] ; to print pennies first
		pop 	rsi					 ; pop remaining value (i.e. amount of nickels)
		call 	printf
		ret