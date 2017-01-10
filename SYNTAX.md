# Bytecode Language Syntax

The following is a syntax guide for writing code to be compiled into bytecode via the assembler for execution by the virtual machine.

## Basic Syntax

You can use either uppercase or lowercase for calling opcodes and commands. The following two lines are equivalent:

    iprompt
    IPROMPT

## Numerals

Some opcodes require one or more parameters, all of which are some sort of numeral value. Depending on the type value of the parameter, we can specify them in different ways.

Data Type | Bytes | Signed? | Range | Valid Examples
:--- | :--- | :--- | :--- | :---
Byte | 1 | no | 0 to 255 | `32 54 H I`
Short | 2 | signed | -32,768 to 32,767 | `7116  -16025  2760`
Int | 4 | signed | –2,147,483,648 to 2,147,483,647 | `-77437590  125829395  -31555607`
Float | 4 | signed | 3.4E +/- 38 (7 digits) | `-5687.0  -22.30  72033.6221123`

## Labels

Labels can be used to mark positions in your code for goto statements and conditionals to branch off to. Setting a label is easy - just use the *label* keyword and specify a name for the label, which can support any naming format (characters, numerals, and symbols all supported):

```python
label .mylabel
goto .mylabel

ipush 1
ifn .mylabel
```

## Method Declaration

Several things are needed to define a method. We need to specify a name for the method, the number of parameters the method takes, the number of local variables within the method, as well as the data types for the parameters/variables.

```python
define .main 2 2 byte short int float
```

The above code specifies the following:
- Define a method called *.main*
- The method takes two parameters
- The method has two local variables
- The first parameter is of type *byte*; the second is of type *short*
- The first local variable is of type *int*; the second is of type *float*

#### Accessing Parameters and Local Variables

Since the virtual machine is stack-based, the parameters and local variables of a method are stored in sequential memory within the stack frame. This comes into play when utilizing the `*STORE` and `*LOAD` opcodes, as they reference the parameter/variable indices sequentially as well.

The following is a diagram of how the stack looks for the above example method *.main*, and the various indices of the parameters and local variables to be used by the `*STORE` and `*LOAD` opcodes:

> Stack:
> |  param1  |  param2  |  local1  |  local2  |

Property | Index | Loading | Storing
:--- | :--- | :--- | :---
Parameter 1 | 0 | BLOAD 0 | |
Parameter 2 | 1 | SLOAD 1 | |
Local Var 1 | 2 | ILOAD 2 | ISTORE 2 |
Local Var 2 | 3 | FLOAD 3 | FSTORE 3 |
