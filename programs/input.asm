# input.asm
# Prompts user for an integer; simply double the value.


iprompt # prompt user for an integer
ipush 2 # push literal value '2' onto stack
imul    # multiply top two values on stack; push result
iprint  # output top result on stack to console
