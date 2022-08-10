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
