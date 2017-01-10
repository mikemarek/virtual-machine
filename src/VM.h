#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <vector>
#include <iostream>
#include <cassert>
#include "Value.h"

class VM
{
public:
    void run(unsigned char*, int);

private:
    static const int  MAX_STACK   = 128;
    static const int  MAX_PROGRAM = 2056;
    static const bool DEBUG       = false;
    static const bool DEBUG_SLEEP = false;

    void  push(value);
    value pop();
    char  readbyte();
    short readshort();
    int   readint();
    float readfloat();
    void SkipMethod();
    void  PrintStack();
    void  PrintMethodList();
    char* opcode(unsigned char);
    char* datatype(unsigned char);

    //stack; instruction and stack pointers
    value stack[MAX_STACK];
    unsigned char* bytecode;
    int*  progsize;
    int   ip;
    int   sp;
    int   fp;

    //current invoked method and method area
    int id;
    std::vector < std::vector<int>  >  methods; //[entry, exit, return, # params, # locals]
    std::vector < std::vector<char> >  params;  //[typeof param0, ...]
    std::vector < std::vector<char> >  locals;  //[typeof local0, ...]

    //opcode functions
    void operator_bpush             ();
    void operator_spush             ();
    void operator_ipush             ();
    void operator_fpush             ();
    void operator_swap              ();
    void operator_swap2             ();
    void operator_duplicate         ();
    void operator_duplicate2        ();
    //
    void operator_bstore            ();
    void operator_sstore            ();
    void operator_istore            ();
    void operator_fstore            ();
    void operator_bload             ();
    void operator_sload             ();
    void operator_iload             ();
    void operator_fload             ();
    //
    void operator_badd              ();
    void operator_bsubtract         ();
    void operator_bmultiply         ();
    void operator_bdivide           ();
    void operator_bmodulus          ();
    void operator_bnot              ();
    void operator_band              ();
    void operator_bor               ();
    void operator_bxor              ();
    void operator_sadd              ();
    void operator_ssubtract         ();
    void operator_smultiply         ();
    void operator_sdivide           ();
    void operator_smodulus          ();
    void operator_snot              ();
    void operator_sand              ();
    void operator_sor               ();
    void operator_sxor              ();
    void operator_iadd              ();
    void operator_isubtract         ();
    void operator_imultiply         ();
    void operator_idivide           ();
    void operator_imodulus          ();
    void operator_inot              ();
    void operator_iand              ();
    void operator_ior               ();
    void operator_ixor              ();
    void operator_fadd              ();
    void operator_fsubtract         ();
    void operator_fmultiply         ();
    void operator_fdivide           ();
    void operator_fmodulus          ();
    void operator_fnot              ();
    void operator_fand              ();
    void operator_for               ();
    void operator_fxor              ();
    //
    void operator_goto              ();
    void operator_jump              ();
    void operator_ifequal           ();
    void operator_ifnot             ();
    void operator_ifnotequal        ();
    void operator_iflessthan        ();
    void operator_iflessequal       ();
    void operator_ifgreaterthan     ();
    void operator_ifgreaterequal    ();
    //
    void operator_invoke            ();
    void operator_return            ();
    void operator_sreturn           ();
    void operator_ireturn           ();
    void operator_freturn           ();
    //
    void operator_bprint            ();
    void operator_sprint            ();
    void operator_iprint            ();
    void operator_fprint            ();
    void operator_bprompt           ();
    void operator_sprompt           ();
    void operator_iprompt           ();
    void operator_fprompt           ();
};

#endif
