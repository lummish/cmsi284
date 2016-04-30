;calc-ops.asm
		global 	gcd
		global 	add
		global 	power
		extern 	printf
		extern  atoi
		extern 	puts
		section .text
add:	
		xor		rax, rax	;clear rax
		add 	rax, rsi
		add		rax, rdi
		jmp 	end
gcd:	
		mov		rax, rdi ; need x to be divided
gcd_loop:
		cmp		rsi, 0
		je 		end
		xor		rdx, rdx ; need to clear rdx to make sure proper number is divided
		div 	rsi		 ; divide rax by rsi and store remainder in rdx
		mov		rax, rsi
		mov		rsi, rdx
		jmp		gcd_loop
power:	
		mov		rax, rdi ; store base in rax
		cmp		rsi, 0 	 ; if rsi == 0, return 1	
		jne		pow_loop
		mov   	rax, 1
		jmp		end
pow_loop:
		dec		rsi		 ; only loop as many times as needed
		cmp		rsi, 0
		je		end
		mul		rdi
		jmp		pow_loop

end:
		ret
num_format:
		db "%d %d",10,0
