# Virtual Machine

A simple JVM-like bytecode language that is compiled and run on a simple stack-based virtual machine.

An assembler was written in Python, which parses the human-readable instruction set and compiles it into a bytecode file (.bin).

The virtual machine is written in C++, and reads in the bytecode files and executes them.

## Usage

On Windows, you can compile the virtual machine using the Visual Studio Developer Command Prompt:

`cl /EHsc main.cpp VM.cpp /link /out:VM.exe`

You can compile assembly code files using the Python assembler:

`assembler.py mycodefile.asm`

And finally, run your compiled bytecode with the virtual machine:

`VM.exe mycodefile.bin`

> **Note:** You can specify multiple files to be compiled/executed in sequence.

## Features

- Variable declaration and storage
- Multiple data types (char, short, int, float)
- Numerous arithmetic and bitwise operations
- Method creation and invocation (utilizes stack frames; supports recursion)
- Modifying program control flow (instruction jumping; conditionals)

## Instruction Set

A full list of opcodes and how they are used can be found in the following file located in the repository:

[OPCODES.md](/OPCODES.md "Instruction Set")

A guide to the language syntax and writing actual code can be found here:

[SYNTAX.md](/SYNTAX.md "Syntax Guide")

## Sample Programs

Many more sample programs can be found in the repository directory [programs](../programs/ "Sample Programs").

#### Hello World

```python
bpush H     bprint
bpush e     bprint
bpush l     bprint
bpush l     bprint
bpush o     bprint
bpush 32    bprint
bpush 87    bprint
bpush 111   bprint
bpush 114   bprint
bpush 108   bprint
bpush 100   bprint
bpush 33    bprint
```

> **output**

>
    <OUTPUT> H
    <OUTPUT> e
    <OUTPUT> l
    <OUTPUT> l
    <OUTPUT> o
    <OUTPUT>
    <OUTPUT> W
    <OUTPUT> o
    <OUTPUT> r
    <OUTPUT> l
    <OUTPUT> d
    <OUTPUT> !
    Done.

#### Manipulating User Input

```python
iprompt     # prompt user for an integer
ipush 2     # push literal value '2' onto stack
imul        # multiply top two values on stack; push result
iprint      # output top result on stack to console
```

> **output**

>
    Enter integer: 5
    <OUTPUT> 10
    Done.

#### Method Invocation

```python
define .double 1 0 int  # define a method named '.double' with one parameter [int] and no local variables
    iload 0             # load parameter onto stack
    ipush 2             # push literal value '2' onto the stack
    imul                # multiply top two values on stack together; push result
ireturn

iprompt                 # prompt user for integer input
invoke .double          # invoke double() method
iprint                  # print result
```

> **output**

>
    Enter integer: 5
    <OUTPUT> 10
    Done.

#### Simple For-Loop

```python
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
```

> **output**

>
    Enter integer: 5
    <OUTPUT> 5
    <OUTPUT> 4
    <OUTPUT> 3
    <OUTPUT> 2
    <OUTPUT> 1
    <OUTPUT> 0
    Done.

## Disclaimer

> I am really, REALLY sorry for the giant mess of spaghetti code and lack of commenting. This was more of a weekend "just get it working" sort of project, and really didn't take into account best coding practices. Hopefully I will revisit this in the future and refactor the shit out of it...
