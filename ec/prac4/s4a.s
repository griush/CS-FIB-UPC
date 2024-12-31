	.data
signe:		.word 0
exponent:	.word 0
mantissa:	.word 0
cfixa:		.word 0x7FFFF000
cflotant:	.float 0.0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)

	la	$t0, cfixa
	lw	$a0, 0($t0)
	la	$a1, signe
	la	$a2, exponent
	la	$a3, mantissa
	jal	descompon

	la	$a0, signe
	lw	$a0,0($a0)
	la	$a1, exponent
	lw	$a1,0($a1)
	la	$a2, mantissa
	lw	$a2,0($a2)
	jal	compon

	la	$t0, cflotant
	swc1	$f0, 0($t0)

	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra


descompon:
	li $t0, 0 # int exp = 0;
	andi $t1, $a0, 0x80000000 # $t1 = cf & 0x80000000 => gets sign bit
	srl $t1, $t1, 31
	sw $t1, 0($a1) # *s = $t1
	
	sll $a0, $a0, 1 # cf = cf << 1;
	
	beq $a0, $zero fi
	#else
	li $t0, 18 # exp = 18;
	while: blt $a0, $zero, ewhile
	sll $a0, $a0, 1 # cf = cf << 1;
	addi $t0, $t0, -1 # exp--;
	b while
	ewhile:
	srl $a0, $a0, 8 # cf = (cf >> 8)
	andi $a0, $a0, 0x7FFFFF # cf & 0x7FFFFF
	addi $t0, $t0, 127
	
	fi:
	sw $t0, 0($a2) # *e = exp;
        sw $a0, 0($a3) # *m = cf;
	jr $ra

compon:
	sll $t0, $a0, 31
	sll $t1, $a1, 23
	move $t2, $a2
	or $t2, $t2, $t0
	or $t2, $t2, $t1
	mtc1 $t2, $f0
	jr $ra
