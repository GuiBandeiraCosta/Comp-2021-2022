; DATA
segment	.data
; ALIGN
align	4
; LABEL x
x:
; SINT 10
	dd	10
; DATA
segment	.data
; ALIGN
align	4
; LABEL y
y:
; SINT 3
	dd	3
; TEXT
segment	.text
; ALIGN
align	4
; GLOBAL _main, :function
global	_main:function
; LABEL _main
_main:
; ENTER 0
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; ADDR y
	push	dword $y
; LDINT
	pop	eax
	push	dword [eax]
; ADDR x
	push	dword $x
; LDINT
	pop	eax
	push	dword [eax]
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; CALL printi
	call	printi
; TRASH 4
	add	esp, 4
; CALL println
	call	println
; INT 0
	push	dword 0
; STFVAL32
	pop	eax
; LEAVE
	leave
; RET
	ret
; EXTERN readi
extern	readi
; EXTERN printi
extern	printi
; EXTERN prints
extern	prints
; EXTERN println
extern	println
