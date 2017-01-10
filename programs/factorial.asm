# factorial.asm
# Finds the factorial of a user-entered number using recursion


iprompt
invoke .main

define .main 1 0 int
    iload 0
    invoke .factorial
    iprint
return

define .factorial 1 0 int
    # return 1 if n <= 1
    iload 0
    ipush 1
    iflessequal .return1

    # Fac(n-1) * n
    iload 0
    ipush 1
    isub
    invoke .factorial
    iload 0
    imul
    ireturn

    label .return1
    ipush 1
ireturn
