.global reverse_in_place

reverse_in_place:
    # IN rdi <- str
    # OUT rax <- count
    jmp calc_str_len # first find str length


    calc_str_len:

        xor %rcx, %rcx #i = 0
        xor %rax, %rax # count = 0
        while_start: #while str[i] != '\0', inc count and inc i

            cmpq $0x00, (%rdi, %rcx, 1) # check if str[i] == '\0'
            je while_done # if is then loop done
            inc %rcx # i++
            inc %rax # count++
            jmp while_start

        while_done:
        # rax <- string length (our return value)
        mov %rax, %r9 # save return value for later
        dec %rax # strlen = strlen - 1
        mov %rax, %r8
        sar $1, %r8 # (strlen-1)/2

        xor %rcx, %rcx # i = 0 (loop var)
        xor %rdx, %rdx
        jmp reverse

    reverse:

        #store each char in byte-sized register
        movb (%rdi, %rcx, 1), %dl # str[i] <- rdx
        movb (%rdi, %rax, 1), %bl # str[strlen-1-i] <- rbx

        #swap
        movb %dl, (%rdi, %rax, 1) # str[strlen-1-i] = str[i]
        movb %bl, (%rdi, %rcx, 1) # str[i] = str[strlen-1-i]
        
        dec %rax # strlen-1-i
        inc %rcx # i++

        cmp %r8, %rcx # i < (strlen-1)/2
        jg done

        cmpb $0x20, %dl # if str[i] == 'space' skip that char
        je reverse
        cmpb $0x20, %bl # if str[i] == 'space' skip that char
        je reverse
        jmp reverse

    done:
        mov %r9, %rax
        ret



        

