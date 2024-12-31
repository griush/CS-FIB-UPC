.data
	.align 2
mat:	.word 0, 0, 2, 0, 0, 0
	.word 0, 0, 4, 0, 0, 0
	.word 0, 0, 6, 0, 0, 0
	.word 0, 0, 8, 0, 0, 0

resultat: .word 0
.text
.globl main
main:
	addiu $sp, $sp, -4 # to store $ra
	sw $ra, 0($sp)
	
	# call
	la $a0, mat
	jal suma_col
	
	#return value
	la $t0, resultat
	sw $v0, 0($t0)
	
	# restore stack and return
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra
	
suma_col:
	# No need to setup stack
	li $v0, 0 # v0 / suma
	
	addiu $t1, $a0, 8 # &m[0][2] => $t1 = p. 8 = 2 * stride
	
	li $t0, 0 # i
	for: bge $t0, 4, endfor
	lw $t2, 0($t1) # *p
	addu $v0, $v0, $t2 # suma += *p;
	addiu $t1, $t1, 24 # p += 6; (* sizeof(int))
	addiu $t0, $t0, 1
	b for

	# No need to restore stack also
	endfor: jr $ra
