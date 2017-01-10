# Virtual Machine Instruction Set

The following is a list of all supported data types and opcodes available in the virtual machine.

## Data Types

Data Type | Keyword | Size
:--- | :--- | :---
Byte | byte | 1 byte *(unsigned)*
Short Integer | short | 2 bytes *(signed)*
Integer | int | 4 bytes *(signed)*
Floating-Point Number | float | 4 bytes *(signed)*

## Stack Manipulation

Mnemonic | Opcode (Hex) | Parameters | Stack [before] → [after] | Description
:--- | :--- | :--- | :--- | :---
BPUSH | 0x00 | *[byte]* | *→ byte* | Push a byte value onto the stack.
SPUSH | 0x01 | *[short]* | *→ short* | Push a short value int onto the stack.
IPUSH | 0x02 | *[int]* | *→ int* | Push an integer value onto the stack.
FPUSH | 0x03 | *[float]* | *→ float* | Push a float value onto the stack.
SWAP | 0x05 | | *AB → BA* | Swap the top two elements on the stack.
SWAP2 | 0x06 | | *ABCD → DCBA* | Swap the top four elements on the stack.
DUP | 0x07 | | *A → AA* | Duplicate the top value on the stack.
DUP2 | 0x08 | | *AB → ABAB* | Duplicate the top two values on the stack.

## Variable Creation, Storage, and Loading

Mnemonic | Opcode (Hex) | Parameters | Stack [before] → [after] | Description
:--- | :--- | :--- | :--- | :---
BSTORE | 0x10 | *[byte]* | *byte →* | Save a byte value from the stack into the specified local variable.
SSTORE | 0x11 | *[short]* | *short →* | Save a short int value from the stack into the specified local variable.
ISTORE | 0x12 | *[int]* | *int →* | Save an integer value from the stack into the specified local variable.
FSTORE | 0x13 | *[float]* | *float →* | Save a float value from the stack into the specified local variable.
BLOAD | 0x15 | *[byte]* | *→ byte* | Push a byte value from specified local variable onto the stack.
SLOAD | 0x16 | *[short]* | *→ short* | Push a short int value from specified local variable onto the stack.
ILOAD | 0x17 | *[int]* | *→ int* | Push an integer value from specified local variable onto the stack.
FLOAD | 0x18 | *[float]* | *→ float* | Push a float value from specified local variable onto the stack.

## Arithmetic and Bitwise Operations

Mnemonic | Opcode (Hex) | Parameters | Stack [before] → [after] | Description
:--- | :--- | :--- | :--- | :---
BADD | 0x20 | | *AB → C* | Add the top two byte values on the stack.
BSUB | 0x21 | | *AB → C* | Subtract the top two byte values on the stack.
BMUL | 0x22 | | *AB → C* | Multiply the top two byte values on the stack.
BDIV | 0x23 | | *AB → C* | Divide the top two byte values on the stack.
BMOD | 0x24 | | *AB → C* | Take the modulo of the top two byte values on the stack.
BNOT | 0x25 | | *A → B* | Perform bitwise NOT on the top byte value on the stack.
BAND | 0x26 | | *AB → C* | Perform bitwise AND on the top two byte values on the stack.
BOR | 0x27 | | *AB → C* | Perform bitwise OR on the top two byte values on the stack.
BXOR | 0x28 | | *AB → C* | Perform bitwise XOR on the top two byte values on the stack.
SADD | 0x29 | | *AB → C* | Add the top two short int values on the stack.
SSUB | 0x2A | | *AB → C* | Subtract the top two short int values on the stack.
SMUL | 0x2B | | *AB → C* | Multiply the top two short int values on the stack.
SDIV | 0x2C | | *AB → C* | Divide the top two short int values on the stack.
SMOD | 0x2D | | *AB → C* | Take the modulo of the top two short int values on the stack.
SNOT | 0x2E | | *A → B* | Perform bitwise operation NOT on the top short int value on the stack.
SAND | 0x2F | | *AB → C* | Perform bitwise AND on the top two short int values on the stack.
SOR | 0x30 | | *AB → C* | Perform bitwise OR on the top two short int values on the stack.
SXOR | 0x31 | | *AB → C* | Perform bitwise XOR on the top two short int values on the stack.
IADD | 0x32 | | *AB → C* | Add the top two integer values on the stack.
ISUB | 0x33 | | *AB → C* | Subtract the top two integer values on the stack.
IMUL | 0x34 | | *AB → C* | Multiply the top two integer values on the stack.
IDIV | 0x35 | | *AB → C* | Divide the top two integer values on the stack.
IMOD | 0x36 | | *AB → C* | Take the modulo of the top two integer values on the stack.
INOT | 0x37 | | *A → B* | Perform bitwise NOT on the top integer value on the stack.
IAND | 0x38 | | *AB → C* | Perform bitwise AND on the top two integer values on the stack.
IOR | 0x39 | | *AB → C* | Perform bitwise OR on the top two integer values on the stack.
IXOR | 0x3A | | *AB → C* | Perform bitwise XOR on the top two integer values on the stack.
FADD | 0x3B | | *AB → C* | Add the top two float values on the stack.
FSUB | 0x3C | | *AB → C* | Subtract the top two float values on the stack.
FMUL | 0x3D | | *AB → C* | Multiply the top two float values on the stack.
FDIV | 0x3E | | *AB → C* | Divide the top two float values on the stack.
FMOD | 0x3F | | *AB → C* | Take the modulo of the top two float values on the stack.
FNOT | 0x40 | | *A → B* | Perform bitwise NOT on the top float value on the stack.
FAND | 0x41 | | *AB → C* | Perform bitwise AND on the top two float values on the stack.
FOR | 0x42 | | *AB → C* | Perform bitwise OR on the top two float values on the stack.
FXOR | 0x43 | | *AB → C* | Perform bitwise XOR on the top two float values on the stack.

## Comparators

*Coming Soon!*

## Logic and Control Flow

Mnemonic | Opcode (Hex) | Parameters | Stack [before] → [after] | Description
:--- | :--- | :--- | :--- | :---
GOTO | 0x50 | *[short]* | *→* | Go to the specified instruction.
JUMP | 0x51 | | *A →* | Pop the top short int value off of the stack and go to that instruction.
IFE | 0x52 | *[short]* | *AB →* | If the top two values on the stack are equal, go to the specified instruction.
IFN | 0x53 | *[short]* | *A →* | If the top value on the stack is logically false, go to the specified instruction.
IFNE | 0x54 | *[short]* | *AB →* | If the top two values on the stack are not equal, go to the specified instruction.
IFLT | 0x55 | *[short]* | *AB →* | If value A is less than value B, go to the specified instruction.
IFLE | 0x56 | *[short]* | *AB →* | If value A is less than or equal to value B, go to the specified instruction.
IFGT | 0x57 | *[short]* | *AB →* | If value A is greater than value B, go to the specified instruction.
IFGE | 0x58 | *[short]* | *AB →* | If value A is greater than or equal to value B, go to the specified instruction.

## Method Declaration and Invokation

Mnemonic | Opcode (Hex) | Parameters | Stack [before] → [after] | Description
:--- | :--- | :--- | :--- | :---
DEFINE | 0x80 | *[short] [int] [int] <type0> ... <typeN>* | *→ <value0> ... <valueN> [int] [int]* | Define a method with specified index in the *methods table*. Number of method parameters and local variables are also specified, along with the corrisponding variables' types.
INVOKE | 0x81 | *[short]* | *→ undefined* | Invoke a method at the specified index in the *methods table* by creating a stack frame for the method. The stack may or may not be modified after the method has run, depending on its return type.
RETURN | 0x82 | | | Exit out of the method's stack frame without returning any value (equivalent of a void function).
BRETURN | 0x83 | | *→ byte* | Exit out of a method's stack frame and return the last byte value that was present on the stack.
SRETURN | 0x84 | | *→ short* | Exit out of a method's stack frame and return the last short int value that was present on the stack.
IRETURN | 0x85 | | *→ int* | Exit out of a method's stack frame and return the last integer value that was present on the stack.
FRETURN | 0x86 | | *→ float* | Exit out of a method's stack frame and return the last float value that was present on the stack.

## Type Conversion

*Coming Soon!*

## System Calls

Mnemonic | Opcode (Hex) | Parameters | Stack [before] → [after] | Description
:--- | :--- | :--- | :--- | :---
BPRINT | 0x90 | | *byte →* | Outputs the byte value of topmost stack value to the console.
SPRINT | 0x91 | | *short →* | Outputs the short int value of topmost stack value to the console.
IPRINT | 0x92 | | *int →* | Outputs the integer value of topmost stack value to the console.
FPRINT | 0x93 | | *float →* | Outputs the float value of topmost stack value to the console.
BPROMPT | 0x96 | | *→ byte* | Pushes the byte value onto the stack of a user-entered value through the console.
SPROMPT | 0x97 | | *→ short* | Pushes the short int value onto the stack of a user-entered value through the console.
IPROMPT | 0x98 | | *→ int* | Pushes the integer value onto the stack of a user-entered value through the console.
FPROMPT | 0x99 | | *→ float* | Pushes the float value onto the stack of a user-entered value through the console.

## Other

Mnemonic | Opcode (Hex) | Parameters | Stack [before] → [after] | Description
:--- | :--- | :--- | :--- | :---
PASS | 0xFF | | | Do nothing (nop).
