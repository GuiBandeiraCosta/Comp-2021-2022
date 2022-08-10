; TEXT
segment	.text
; ALIGN
align	4
; GLOBAL _main, :function
global	_main:function
; LABEL _main
_main:
; ENTER 8
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; INT 1
	push	dword 1
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; STINT
	pop	ecx
	pop	eax
	mov	[ecx], eax
; LABEL _L1
_L1:
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; INT 3
	push	dword 3
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; JZ _L2
	pop	eax
	cmp	eax, byte 0
	je	near _L2
; INT 1
	push	dword 1
; LOCAL -8
	lea	eax, [ebp+-8]
	push	eax
; STINT
	pop	ecx
	pop	eax
	mov	[ecx], eax
; LABEL _L3
_L3:
; LOCAL -8
	lea	eax, [ebp+-8]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; INT 6
	push	dword 6
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; JZ _L4
	pop	eax
	cmp	eax, byte 0
	je	near _L4
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; INT 2
	push	dword 2
; MOD
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
; INT 1
	push	dword 1
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ _L5
	pop	eax
	cmp	eax, byte 0
	je	near _L5
; LOCAL -8
	lea	eax, [ebp+-8]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; INT 1
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; DUP32
	push	dword [esp]
; LOCAL -8
	lea	eax, [ebp+-8]
	push	eax
; STINT
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH 4
	add	esp, 4
; JMP _L3
	jmp	dword _L3
; JMP _L6
	jmp	dword _L6
; LABEL _L5
_L5:
; LOCAL -8
	lea	eax, [ebp+-8]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; CALL printi
	call	printi
; TRASH 4
	add	esp, 4
; CALL println
	call	println
; LABEL _L6
_L6:
; LOCAL -8
	lea	eax, [ebp+-8]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; INT 1
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; DUP32
	push	dword [esp]
; LOCAL -8
	lea	eax, [ebp+-8]
	push	eax
; STINT
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH 4
	add	esp, 4
; JMP _L3
	jmp	dword _L3
; LABEL _L4
_L4:
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; INT 1
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; DUP32
	push	dword [esp]
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; STINT
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH 4
	add	esp, 4
; JMP _L1
	jmp	dword _L1
; LABEL _L2
_L2:
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
