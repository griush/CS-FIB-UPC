.data
	.align 2
	mat1: 	.space 120 # 5 * 6 * 4
	mat4: 	.word 2, 3, 1
		.word 2, 4, 3
		
	col:	.word 2
	
.text
.globl main
main:
	# stack setup
	# since this is main, only need to save $ra
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	la $s0, mat4 # $s0 = &mat4
	la $s1, mat1 # $s1 = &mat1
	
	# 1st call params
	move $a0, $s0 # pass pointer to mat4 as first parameter
	
	lw $a1, 8($s0) # set $a1 to the value at mat[0][2]
	
	la $t0, col # $t0 = &col
	lw $a2, 0($t0) # $a0 = *$t0
	
	jal subr # make 1st call

	# set mat1[4][3] to return value ($v0)
	sw $v0, 108($s1) # mat1 at byte offset 108 (/ 4 == [4][3] position) = $v0 (return param)

	# 2nd call params
	move $a0, $s0 # pass pointer to mat4 as first parameter
	
	li $a1, 1 # set $a1 to 1
	li $a2, 1 # set $a2 to 1
	
	jal subr # make 2nd call
	
	# retrieve return value
	sw $v0, 0($s1) # ($s1 == &mat1)
	
	# stack restore
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra
	
subr: # returns: int
	# calculate &x[i][j]
	li $t0, 3 # NC
	mulu $t0, $a1, $t0 # i * NC
	addu $t0, $t0, $a2 # i * NC + j
	sll $t0, $t0, 2 # (i * NC + j) * (sizeof(int) == 4)
	
	# now, $t0 contains offset
	addu $t0, $a0, $t0 # $t0 = x + offset($t0)
	lw $t0, 0($t0) # $t0 = x[i][j]
	
	li $t1, 6 # NC of mat1
	mulu $t1, $a2, $t1 # j * NC
	addiu $t1, $t1, 5 # offset = j * NC + j
	sll $t1, $t1, 2 # offset *= 4 (sizeof(int))
	
	la $t2, mat1
	addu $t1, $t1, $t2 # $t1 = &mat1[j][5]
	sw $t0, 0($t1)
	
	move $v0, $a1
	jr $ra
