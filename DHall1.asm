.data
int1: .asciiz "Enter the first integer please: "
int2: .asciiz "Enter the second integer please: "
int3: .asciiz "Enter the third integer please: "

thesum: .asciiz "\n The sum of "
thediff: .asciiz "\n The difference of "
theprod: .asciiz "\n The product of "
thequot: .asciiz "\n The quotent of "

comma: .asciiz " ,  "
commaAnd: .asciiz " , and,  "
is: .asciiz " is "
period: .asciiz "."
remainder: .asciiz " with remainder "

.text

main:

    #t0-to hold 1st int
    #t1-to hold 2nd int
    #t2- to hold 3rd int
    #s0- used to hold the sum of t$1 and t$2
 

        #first number

    li $v0, 4 #call for 1st number
        la $a0, int1  #print
        syscall

        li $v0, 5 #input 1st number
        syscall
        move $t0, $v0  

   li $v0, 4 #call for 2nd number
        la $a0, int1  #print
        syscall

        li $v0, 5 #input second number
        syscall
        move $t1, $v0  
    
    li $v0, 4 #call for 3rd number
        la $a0, int3  #print
        syscall

        li $v0, 5 #input 3rd number
        syscall
        move $t2, $v0  

        add $s0, $t1, $t0 #add num1 + num2 to s0
        add $s0, $s0, $t2 #add t2 + s0 to s0
        
        
        ##############################################
        li $t4, -1	#t4 stores -1 to be used for multiplication
        
        mult $t1, $t4
        mflo $s1
        mult $t2, $t4
        mflo $s2
        
        add $t3, $s1, $s2
        add $s3, $t0, $t3 #s3 holds the diff of num1 - num2 - num3
        
        ##############################################
        
        mult $t0, $t1
        mflo $t5
        mult $t5, $t2
        mflo $s4 #s4 holds (num1)(num2)(num3)
        
        ############################################
        
        div $t0, $t1
        mflo $s5 #holds (num1/num2)
        mfhi $s6 #holds num1 % num2    
        
  

    #print out sum
    li $v0, 4
    la $a0, thesum   
    syscall
    li $v0, 1
    move $a0, $t0
    syscall
    li $v0, 4
    la $a0, comma   
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    li $v0, 4
    la $a0, commaAnd   
    syscall
    li $v0, 1
    move $a0, $t2
    syscall
    li $v0, 4
    la $a0, is   
    syscall
    li $v0, 1
    move $a0, $s0
    syscall
    li $v0, 4
    la $a0, period   
    syscall
    
    #print out difference 
    li $v0, 4
    la $a0, thediff  
    syscall
    li $v0, 1
    move $a0, $t0
    syscall
    li $v0, 4
    la $a0, comma   
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    li $v0, 4
    la $a0, commaAnd   
    syscall
    li $v0, 1
    move $a0, $t2
    syscall
    li $v0, 4
    la $a0, is   
    syscall
    li $v0, 1
    move $a0, $s3
    syscall
    li $v0, 4
    la $a0, period   
    syscall
    
    #print out product 
    li $v0, 4
    la $a0, theprod 
    syscall
    li $v0, 1
    move $a0, $t0
    syscall
    li $v0, 4
    la $a0, comma   
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    li $v0, 4
    la $a0, commaAnd   
    syscall
    li $v0, 1
    move $a0, $t2
    syscall
    li $v0, 4
    la $a0, is   
    syscall
    li $v0, 1
    move $a0, $s4
    syscall
    li $v0, 4
    la $a0, period   
    syscall
    
    #print out quotient 
    li $v0, 4
    la $a0, thequot   
    syscall
    li $v0, 1
    move $a0, $t0
    syscall
    li $v0, 4
    la $a0, comma   
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    li $v0, 4
    la $a0, commaAnd   
    syscall
    li $v0, 1
    move $a0, $t2
    syscall
    li $v0, 4
    la $a0, is   
    syscall
    li $v0, 1
    move $a0, $s5
    syscall
    li $v0, 4
    la $a0, remainder
    syscall
    li $v0, 1
    move $a0, $s6
    syscall
    li $v0, 4
    la $a0, period
    syscall
    
    


Done:

    li $v0, 10    #syscall to exit
        syscall