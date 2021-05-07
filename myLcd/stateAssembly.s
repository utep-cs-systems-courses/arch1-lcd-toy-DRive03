        .arch msp430g25453 
	.p2align 1,0
	#include "lcddraw.h"
	.data	
st:	.word 0 	
	
	.text
	
jt:
	.word case0
	.word case1
	.word case2
	.word case3
	.word default
	.global state_selection

state_selection:
	cmp #4, r12	
	jc default
	add r12, r12
	mov jt(r12), r0


default:
	mov #0, r12 
	pop r0

case0:
	mov #30,r12
	mov #30,r13
	mov #40,r14
	mov #0x07e0,r15
	call #fillTriangle
	mov #1,r12
	pop r0

case1:
	mov #70,r12
	mov #60,r13
	mov #30,r14
	mov #0x07e0,r15
	call #fillRectangle2
	mov #2,r12
	pop r0
	
case2:
	mov #30,r12
	mov #30,r13
	mov #40,r14
	mov #0xff,r15
	call #fillTriangle
	mov #3,r12
	pop r0
	
case3:
	mov #70,r12
	mov #60,r13
	mov #30,r14
	mov #0xffff,r15
	call #fillRectangle2
	mov #0,r12
	pop r0
