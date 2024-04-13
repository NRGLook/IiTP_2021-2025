	ldx #$8200
 	ldy #$82ff
swap:  
 	ldaa 0,x
 	psha
 	ldaa 0,y
 	staa 0,x
 	pula
 	staa 0,y
 	inx
 	dey
 	cpx #$8280 
 	bne swap
 	nop