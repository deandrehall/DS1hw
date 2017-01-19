#Deandre Hall
#Brian Najera
#Alamin Ahmed

#Group 8

.data
ask: .asciiz "\n Would you like to play the game?"
ask2: .asciiz "\n 1 -> Play, 0 - > Exit \n"
thenumber: .asciiz "\n The number is: "
nextnum: .asciiz "\n Will the next number be"
higher: .asciiz "\n 1 -> Higher"
lower: .asciiz "\n 0 -> Lower \n"
right: .asciiz "\n You're Right !!"
wrong: .asciiz "\n You're Wrong! :( Sorry"
exit: .asciiz "\n Hope you had fun! Your points are: "

.text
.globl main

main:

li $s3, 0

start:

#generates 2 random numbers
li $v0, 42 #Specifies random number generation command
li $a1, 100 #Specifies the upper bound of the number generation
syscall
move $s0, $a0
syscall
move $s1, $a0

#this is the ask user if they would like to play prompt
li $v0, 4
la $a0, ask 
syscall
la, $a0, ask2
syscall
#user inputs if they would like to play 0-exit, 1-play
li $v0, 5
syscall
move $t0, $v0

#if they enter 0, print score and exit
li $t1, 0
beq $t1, $t0, Done

#prints random number
li $v0, 4
la $a0, thenumber
syscall
li $v0, 1
move $a0, $s0
syscall

#asks if the next number will be higher or lower
li $v0, 4
la $a0, nextnum
syscall
la $a0, higher
syscall
la $a0, lower
syscall
#user answers if higher or lower
li $v0, 5
syscall
move $t0, $v0
#prints the second random number
li $v0, 4
la $a0, thenumber
syscall
li $v0, 1
move $a0, $s1
syscall

beq $t0, 1, highernum #if user enters 1, check if randomnum2>randomnum1
beq $t0, 0, lowernum #if user enters 0, check if randomnum2<randomnum1

highernum:
bgt $s1, $s0, win #if user was correct, print correct 
j lose

lowernum:
blt $s1, $s0, win #if user was correct, print correct
j lose

win: #prints message if user was correct, +1 to score
li $v0, 4
la $a0,right
syscall
addi $s3, $s3, 1
j start

lose: #prints message if user was wrong, -1 from score
li $v0, 4
la $a0, wrong
syscall
addi $s3, $s3, -1
j start


Done: #prints users score, then exits
li $v0, 4
la $a0, exit
syscall
li $v0, 1
move $a0, $s3
syscall

li $v0, 10
syscall