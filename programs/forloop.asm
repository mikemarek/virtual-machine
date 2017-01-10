# forloop.asm
# Prompt user for a positive integer; decrement until 0, printing current iteration.


iprompt             # prompt user for integer
invoke .forloop     # invoke forloop() method

# method has one (1) parameter [int] and two (2) local variables [int int]
define .forloop 1 2 int int int
    #
    ipush  0    istore 1    # loop limit
    ipush -1    istore 2    # loop decrement

    # jump point for start of loop
    label .loop

    # check if loop value is greater than limit
    iload 0
    iload 1
    iflessthan .end

    # print current loop iteration
    iload 0
    iprint

    # decrement loop iteration value and resave in memory
    iload 0
    iload 2
    iadd
    istore 0
    goto .loop

    # jump point for end of loop (end of function)
    label .end
return
