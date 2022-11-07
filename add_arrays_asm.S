.global add_arrays

add_arrays:

/*  IN 

arr1 <- RDI
arr2 <- RSI
num <- RDX
result <- RCX

    OUT

    sum of elements in result <- RAX
*/

xor %r8, %r8 # loop var i = 0

    loop_start:
        mov (%rdi, %r8, 8), %r9 # store arr1[i]  
        mov (%rsi, %r8, 8), %r10 # store arr2[i]
        add %r9, %r10 # arr2[i] = arr1[i] + arr2[i]
        mov %r10, (%rcx, %r8, 8) # result[i] = arr1[i] + arr2[i]

        cmp $0, %r8 # i >= 0
        jl next
        cmp %rdx, %r8 # i < num
        jge next
        inc %r8
        jmp loop_start
    
    next:

        xor %r8, %r8 # i = 0
        xor %r12, %r12 # sum = 0

        sum:

            mov (%rcx, %r8, 8), %r11 # storing result[i]
            add %r11, %r12 # sum = sum + result[i]
            inc %r8 #i++
            cmp %rdx, %r8 # i < num
            jge done
            jmp sum

        done:
            mov %r12, %rax
            ret    



