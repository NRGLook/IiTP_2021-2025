	org $8000
	ldaa #0
	ldab #255
	ldx #$8200
loop:
	staa ,x
	inca
	decb
	inx
	decb
	bne loop 
	ldaa #128
	ldy #$8200
	ldx #$82ff
loop1:
	stx $100
	sty $102
	ldx $100
	ldy $102
	sty ,x
	stx ,y
	iny
	dex
	deca
	bne loop1