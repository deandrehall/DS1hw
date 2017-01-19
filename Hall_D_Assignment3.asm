
##############
#Deandre Hall#
#PSID 1241692#
##############

.data
start:	.asciiz "**Program start**\n"
input:	.asciiz "Please input a number: "
endl:	.asciiz "\n"

	.align 2
array:	.space 40 #4bits per number * 10 numbers = 40

.text
.globl main

main:
	li $v0, 4
	la $a0, start #prints "Program start"
	syscall

	la $s0, array #puts array into $s0
	li $t0, 0 #t0 = 0
	jal loadLoop

	la $s0, array
	jal sort #calls bubblesort function	

	la $s0, array 
	jal printArray #prints array, then extis
	
exit:
	li $v0, 10
	syscall

#loadLoop&loadArray are used to populate the array	
loadLoop:
	blt $t0, 10, loadArray #while $t0 < 10, continue to the load function
	jr $ra #returns to the origional fillArray call
loadArray:
	li $v0, 4
	la $a0, input
	syscall #prints "Please input a number: "
	
	li $v0, 5
	syscall #accepts an int input
	sw $v0, ($s0)
	
	addi $s0, $s0, 4 # next array element
	addi $t0, $t0, 1 # $t0++
	
	beq $0,$0,loadLoop
	
printArray:
#t0 is the counter being loaded witht he vlaue 
	li $t0, 0
check:
	blt $t0, 10, display #while $t0 < 10, continue to print
	jr $ra
display:
	li $v0, 1
	lw $a0, ($s0)
	syscall
	
	li $v0, 4
	la $a0, endl
	syscall
	
	addi $s0, $s0, 4 #move to next array element
	addi $t0, $t0, 1 #$t0++
	
	beq $0, $0, check #jumps back up to check if at the end of the array
	
#Bubble Sort 
sort:
#compare two elements in an array
#if element1>element2, swap them
#move to the next element and check/swap again
#do this for the length of the array

	li $t0, 0 #$t0 = 0
	li $t1, 1 #$t1 = 1
	li $t2, 0 #dummy used for swaps

	la $s0, array

outerLoop:
	blt $t0, 9, innerLoop #if $t0<9, jump down to loop
	#else
      	beq $t1, 0, sort  #if $t1==0, continue sorting
      	#else 
	jr $ra #return to initial sort call in main

innerLoop:
	lw $t3, 0($s0) # $t3 = array[i]
	lw $t4, 4($s0) # $t4 = array[i++]
	
	bgt $t3, $t4, swap #if $t3>$t4, jump to swap

	#else $t0++, move to next element of the array
	addi $s0, $s0, 4
	addi $t0, $t0, 1
	
	beq $0,$0, outerLoop #jump back up to the outer loop to check if there needs to be more sorting
swap:
	move $t2, $t3 #move $t3 into $t2
	sw $t4, 0($s0)#$t4 is saved as array[i]
	sw $t2, 4($s0)#$t2 is saved as array[i++]
	
	addi $s0, $s0, 4 #move to the next element of the array
	addi $t0, $t0, 1 #$t0++
	
	li $t1, 0 #set $t1 to 0

	beq $0,$0, outerLoop #jump back up to the outer loop to check if there needs to be more sorting