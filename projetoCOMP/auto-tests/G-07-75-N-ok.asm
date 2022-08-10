; TEXT
segment	.text
; ALIGN
align	4
; LABEL funcao
funcao:
; ENTER 0
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; DATA
segment	.data
; GLOBAL f, :object
global	f:object
; ALIGN
align	4
; TEXT
segment	.text.funcao
; LABEL f
f:
; SADDR funcao
	dd	funcao
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
; INT 4
	push	dword 4
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
