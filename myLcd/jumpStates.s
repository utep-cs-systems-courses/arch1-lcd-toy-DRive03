	.data 		; s is a static variable (in ram)
s:
	.word 1
	

	.text 		; jt is constants (in flash)
jt1:
	.word default	;  jt[0]
	.word option1	;  jt[1]
	.word option2	;  jt[2]
	.word option3	;  jt[3]




       .global f
f:
;;;  range check on selector (s)
	cmp #4, &s	; s-4 doesn't borrow if s>3
	jhs default	; jmp if s > 3

;;;  index into jt
	mov &s, r12
	add r12, r12	; r12=2*s
	mov jt(r12), r0 ; jmp jt[s]
	
;;;  switch table options
;;;  same order as in source code
option3: mov &s, r12	; g(s)
	call #g

	;;  no break

option1:
	
option2:
	add #1, &s
	jmp end	; break

default:
	mov #0, &s	; no break
end:
	pop r0          ; return
