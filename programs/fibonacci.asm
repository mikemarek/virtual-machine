# fibonacci.asm
# Finds the Nth number in the Fibonacci sequence using recursion


iprompt
invoke .main

define .main 1 0 int
    iload 0
    invoke .fibonacci
    iprint
return

define .fibonacci 1 1 int int
    #
    # if n <= 2, return 0
    iload 0
    ipush 2
    ifgreaterequal .fib
    iload 0
    goto .return

    label .fib

    # Fib(n-2)
    iload 0
    ipush 2
    isub
    invoke .fibonacci

    # Fib(n-1)
    iload 0
    ipush 1
    isub
    invoke .fibonacci

    # Fib(n-2) + Fib(n-1)
    iadd

    label .return
ireturn
