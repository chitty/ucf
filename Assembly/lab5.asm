OUTA	EQU	$FFB8
OUTCRLF	EQU	$FFC4
OUTSTRG EQU 	$FFC7

	ORG	$00EE
	JMP	IRQ_ISR

	ORG	$2000

W	FCB	$09
X	FCB	$09
Y	FCB	$09
Z	FCB	$09
CNTRL	FCB	$02
MSG	FCC	'albert... con esto son 3 chipotles...'
	FCB	$04

	ORG	$2050

START	LDX	#MSG
	JSR	OUTSTRG
	JSR	OUTCRLF

	CLI
	JSR	PRINT

WAIT	LDAA	CNTRL
	BNE	WAIT

LP	LDX	#2000
DELAY	NOP
	NOP
	DEX
	BNE	DELAY

	JSR	PRINT
	LDAA	#00
	ADDA	W
	ADDA	X
	ADDA	Y
	ADDA	Z
	CMPA	#00
	BNE	DECZ
	LDAA	#09
	STAA	W
	STAA	X
	STAA	Y
	STA	Z
	BRA	LP

DECZ	LDAA	CNTRL
	BNE	WAIT
	LDAA	Z
	DECA
	STAA	Z
	BMI	DECY
	BRA	LP

DECY	LDAA	#09
	STAA	Z
	JSR	PRINT
	LDAA	Y
	DECA
	STAA	Y
	BMI	DECX
	BRA	LP
	
DECX	LDAA	#09
	STAA	Y
	LDAA	X
	DECA
	STAA	X
	BMI	DECW
	BRA	LP

DECW	LDAA	#09
	STAA	X
	LDAA	W
	DECA
	STAA	W
	BRA	LP

PRINT	LDAA	W
	ADDA	#$30
	JSR	OUTA
	LDAA	X
	ADDA	#$30
	JSR	OUTA
	LDAA	#$2E
	JSR	OUTA
	LDAA	Y
	ADDA	#$30
	JSR	OUTA
	LDAA	Z
	ADDA	#$30
	JSR	OUTA
	JSR	OUTCRLF
	RTS

IRQ_ISR	LDAA	#0100
LP1	LDX	#2000
LP2	NOP
	NOP
	DEX
	BNE	LP2
	DECA
	BNE	LP1
	
	LDAA	CNTRL
	INCA
	STAA	CNTRL
	CMPA	#02
	BEQ	RESET
	CMPA	#01
	BEQ	STOP
	LDAA	#00
	STAA	CNTRL
	RTI

RESET	LDAA	#09
	STAA	W
	STAA	X
	STAA	Y
	STAA	Z
	JSR	PRINT
		
STOP	RTI

END	SWI