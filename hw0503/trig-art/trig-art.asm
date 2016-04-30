		global main
		extern sin
		extern cos
		extern printf
		
		section .text
output: db "%10f %10f %10f", 10, 0 
;output: db "                                                                                ", 10, 0
pi: dq 3.141592653589793
delta: dq 18.0 ; One line moves pi/delta radians.
two: dq 2.0 ; For two pi.
center: dq 39.5 ; define central value of number line
main: 
	push rbp
L0: 
	movsd 	 xmm0, [radian]
 	call 	 sin 			; Result in xmm0.
	movsd 	 [sine], xmm0 	; Save to memory.
	mulsd 	 xmm0, [center]	; multiply sine value by center to determine offset from center
	addsd	 xmm0, [center]	; offset central value
	;cvtsd2si rax, xmm0		; will bring these back once correctness is checkd
	;mov 	 [index], rax	; store rax as index value
	movsd 	 [index], xmm0
	
	; Display the results.
	mov rdi, output
	movsd xmm0, [radian]
	movsd xmm1, [sine]
	movsd xmm2, [index]
	mov rax, 3 ; 3 vector registers!
	call printf
	movsd xmm0, [radian]
	movsd xmm1, [pi]
	divsd xmm1, [delta]
	addsd xmm0, xmm1 ; radian += pi/delta
	movsd [radian], xmm0
	movsd xmm2, [pi]
	mulsd xmm2, [two]
	addsd xmm1, xmm2 ; 2*pi + pi/delta
	comisd xmm0, xmm1
	jc L0 ; CF is set if less than.
	pop rbp
	ret
 
 section .data
radian: dq 0.0
sine: 	dq 0.0
index: 	dq 0.0 