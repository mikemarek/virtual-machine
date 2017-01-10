# double.asm
# Create and invoke a method that simply doubles a user-entered integer.


# define a method named '.double' with one parameter [int] and no local variables
define .double 1 0 int
    iload 0 # load parameter onto stack
    ipush 2 # push literal value '2' onto the stack
    imul    # multiply top two values on stack together; push result
ireturn

iprompt         # prompt user for integer input
invoke .double  # invoke double() method
iprint          # print result
