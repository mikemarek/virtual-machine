#include <vector>
#include <windows.h>
#include "VM.h"
#include "Operators.h"
#include "Opcodes.h"
#include "DataTypes.h"
#include "Value.h"

void VM::push(value v)
{
    assert(sp < MAX_STACK);
    stack[sp++] = v;
}

value VM::pop()
{
    assert(sp > 0);
    return stack[--sp];
}

void VM::run(unsigned char* program, int size)
{
    assert(size < MAX_PROGRAM);
    bytecode = program;
    progsize = &size;

    //load method area
    methods.clear();
    params.clear();
    locals.clear();
    for (ip = 0; ip < size; ip++)
    {
        if (bytecode[ip] == OP_DEFINE)
        {
            int i;
            int id = readshort();
            int np = readshort();
            int nl = readshort();

            if (id+1 > methods.size())
            {
                methods.resize(id+1);
                params.resize(id+1);
                locals.resize(id+1);
            }

            for (i = 0; i < np; i++)
                params[id].push_back(readbyte());
            for (i = 0; i < nl; i++)
                locals[id].push_back(readbyte());
            methods[id].push_back(ip+1);
            methods[id].push_back(ip+1);
            methods[id].push_back(DATA_VOID);
            methods[id].push_back(np);
            methods[id].push_back(nl);

            ip = ip+np+nl;
            i  = ip;

            int end = ip;

            while (ip < size)
            {
                if (bytecode[ip] == OP_RETURN)
                {
                    methods[id][1] = ip;
                    methods[id][2] = DATA_VOID;
                    //break;
                }
                else if (bytecode[ip] == OP_SRETURN)
                {
                    methods[id][1] = ip;
                    methods[id][2] = DATA_SHORT;
                    //break;
                }
                else if (bytecode[ip] == OP_IRETURN)
                {
                    methods[id][1] = ip;
                    methods[id][2] = DATA_INT;
                    //break;
                }

                //new method declaration - last return statement is end of current method
                if (bytecode[ip+1] == OP_DEFINE || ip+1 >= *progsize)
                    break;

                ip++;
            }

            ip = i;
        }
    }

    if (DEBUG)
        PrintMethodList();

    //execute bytecode
    id = -1;
    sp = 0;
    fp = 0;
    ip = 0;
    bool running = true;
    for (ip = 0; ip < size; ip++)
    {
        unsigned char instruction = bytecode[ip];

        if (DEBUG)
            std::cout << "opcode #" << ip << ": " << opcode(bytecode[ip]) << std::endl;

             if (instruction == OP_DEFINE)  SkipMethod();
        else if (instruction == OP_BPUSH)   operator_bpush();
        else if (instruction == OP_SPUSH)   operator_spush();
        else if (instruction == OP_IPUSH)   operator_ipush();
        else if (instruction == OP_FPUSH)   operator_fpush();
        else if (instruction == OP_SWAP)    operator_swap();
        else if (instruction == OP_SWAP2)   operator_swap2();
        else if (instruction == OP_DUP)     operator_duplicate();
        else if (instruction == OP_DUP2)    operator_duplicate2();
        else if (instruction == OP_BSTORE)  operator_bstore();
        else if (instruction == OP_SSTORE)  operator_sstore();
        else if (instruction == OP_ISTORE)  operator_istore();
        else if (instruction == OP_FSTORE)  operator_fstore();
        else if (instruction == OP_BLOAD)   operator_bload();
        else if (instruction == OP_SLOAD)   operator_sload();
        else if (instruction == OP_ILOAD)   operator_iload();
        else if (instruction == OP_FLOAD)   operator_fload();
        else if (instruction == OP_BADD)    operator_badd();
        else if (instruction == OP_BSUB)    operator_bsubtract();
        else if (instruction == OP_BMUL)    operator_bmultiply();
        else if (instruction == OP_BDIV)    operator_bdivide();
        else if (instruction == OP_BMOD)    operator_bmodulus();
        else if (instruction == OP_BNOT)    operator_bnot();
        else if (instruction == OP_BAND)    operator_band();
        else if (instruction == OP_BOR)     operator_bor();
        else if (instruction == OP_BXOR)    operator_bxor();
        else if (instruction == OP_SADD)    operator_sadd();
        else if (instruction == OP_SSUB)    operator_ssubtract();
        else if (instruction == OP_SMUL)    operator_smultiply();
        else if (instruction == OP_SDIV)    operator_sdivide();
        else if (instruction == OP_SMOD)    operator_smodulus();
        else if (instruction == OP_SNOT)    operator_snot();
        else if (instruction == OP_SAND)    operator_sand();
        else if (instruction == OP_SOR)     operator_sor();
        else if (instruction == OP_SXOR)    operator_sxor();
        else if (instruction == OP_IADD)    operator_iadd();
        else if (instruction == OP_ISUB)    operator_isubtract();
        else if (instruction == OP_IMUL)    operator_imultiply();
        else if (instruction == OP_IDIV)    operator_idivide();
        else if (instruction == OP_IMOD)    operator_imodulus();
        else if (instruction == OP_INOT)    operator_inot();
        else if (instruction == OP_IAND)    operator_iand();
        else if (instruction == OP_IOR)     operator_ior();
        else if (instruction == OP_FXOR)    operator_ixor();
        else if (instruction == OP_FADD)    operator_fadd();
        else if (instruction == OP_FSUB)    operator_fsubtract();
        else if (instruction == OP_FMUL)    operator_fmultiply();
        else if (instruction == OP_FDIV)    operator_fdivide();
        else if (instruction == OP_FMOD)    operator_fmodulus();
        else if (instruction == OP_FNOT)    operator_fnot();
        else if (instruction == OP_FAND)    operator_fand();
        else if (instruction == OP_FOR)     operator_for();
        else if (instruction == OP_FXOR)    operator_fxor();
        else if (instruction == OP_GOTO)    operator_goto();
        else if (instruction == OP_JUMP)    operator_jump();
        else if (instruction == OP_IFE)     operator_ifequal();
        else if (instruction == OP_IFN)     operator_ifnot();
        else if (instruction == OP_IFNE)    operator_ifnotequal();
        else if (instruction == OP_IFLT)    operator_iflessthan();
        else if (instruction == OP_IFLE)    operator_iflessequal();
        else if (instruction == OP_IFGT)    operator_ifgreaterthan();
        else if (instruction == OP_IFGE)    operator_ifgreaterequal();
        else if (instruction == OP_INVOKE)  operator_invoke();
        else if (instruction == OP_RETURN)  operator_return();
        else if (instruction == OP_SRETURN) operator_sreturn();
        else if (instruction == OP_IRETURN) operator_ireturn();
        else if (instruction == OP_FRETURN) operator_freturn();
        else if (instruction == OP_BPRINT)  operator_bprint();
        else if (instruction == OP_SPRINT)  operator_sprint();
        else if (instruction == OP_IPRINT)  operator_iprint();
        else if (instruction == OP_FPRINT)  operator_fprint();
        else if (instruction == OP_BPROMPT) operator_bprompt();
        else if (instruction == OP_SPROMPT) operator_sprompt();
        else if (instruction == OP_IPROMPT) operator_iprompt();
        else if (instruction == OP_FPROMPT) operator_fprompt();
        else if (instruction == OP_PASS)    continue;
        else
            running = false;

        if (!running)
        {
            std::cout << "<INVALID OPCODE>"
                      << " line:" << ip
                      << " opcode:" << (int)bytecode[ip]
                      << std::endl
                      << "terminating..."
                      << std::endl;
            break;
        }

        if (DEBUG) PrintStack();
    }

    std::cout << "Done." << std::endl;
}


char VM::readbyte()
{
    return (unsigned char)bytecode[++ip];
}


short VM::readshort()
{
    short s = 0;
    s = 0;
    s = s | (unsigned char)bytecode[++ip];
    s = s << 8;
    s = s | (unsigned char)bytecode[++ip];
    return s;
}


int VM::readint()
{
    int i = 0;
    i = 0;
    i = i | (unsigned char)bytecode[++ip];
    i = i << 8;
    i = i | (unsigned char)bytecode[++ip];
    i = i << 8;
    i = i | (unsigned char)bytecode[++ip];
    i = i << 8;
    i = i | (unsigned char)bytecode[++ip];
    return i;
}


float VM::readfloat()
{
    float f;
    unsigned char b[] = {
        (unsigned char)bytecode[++ip],
        (unsigned char)bytecode[++ip],
        (unsigned char)bytecode[++ip],
        (unsigned char)bytecode[++ip]
    };

    memcpy(&f, &b, sizeof(f));

    return f;
}


//skip execution of method declaration during runtime
void VM::SkipMethod()
{
    if (DEBUG)
        std::cout << "<SKIP METHOD>" << std::endl;

    int id = readshort();
    ip = methods[id][1];
}


void VM::PrintStack()
{
    std::cout << "s:[";
    if (sp == 0)
        std::cout << "<empty stack>";
    for (int i = 0; i < sp; i++)
        switch (stack[i].type)
        {
        case DATA_BYTE:
            std::cout << stack[i].b << (i < sp-1 ? " " : "");
            break;
        case DATA_SHORT:
            std::cout << stack[i].s << (i < sp-1 ? " " : "");
            break;
        case DATA_INT:
            std::cout << stack[i].i << (i < sp-1 ? " " : "");
            break;
        case DATA_FLOAT:
            std::cout << stack[i].f << (i < sp-1 ? " " : "");
            break;
        }
    std::cout << "]\n";

    if (DEBUG && DEBUG_SLEEP)
        Sleep(1000);
}

void VM::PrintMethodList()
{
    if (methods.size() == 0)
        std::cout << "<no methods>\n\n";
    for (int i = 0; i < methods.size(); i++)
    {
        std::cout << "method #"     << i << ":"
                  << "\nentry:    " << methods[i][0]
                  << "\nexit:     " << methods[i][1]
                  << "\nreturn:   " << datatype(methods[i][2])
                  << "\n# params: " << methods[i][3];
        for (int j = 0; j < params[i].size(); j++)
            std::cout << " " << datatype(params[i][j]);
        std::cout << "\n# locals: " << methods[i][4];
        for (int j = 0; j < locals[i].size(); j++)
            std::cout << " " << datatype(locals[i][j]);
        std::cout << std::endl << std::endl;
    }
}

char* VM::datatype(unsigned char d)
{
    switch (d)
    {
    case DATA_VOID:
        return (char*)"VOID";
    case DATA_BOOL:
        return (char*)"BOOL";
    case DATA_BYTE:
        return (char*)"BYTE";
    case DATA_SHORT:
        return (char*)"SHORT";
    case DATA_INT:
        return (char*)"INT";
    case DATA_FLOAT:
        return (char*)"FLOAT";
    case DATA_DOUBLE:
        return (char*)"DOUBLE";
    case DATA_ADDRESS:
        return (char*)"POINTER";
    default:
        return (char*)"<UNKNOWN>";
    }
}

char* VM::opcode(unsigned char o)
{
         if (o == OP_BPUSH)     return (char*)"BPUSH";
    else if (o == OP_SPUSH)     return (char*)"SPUSH";
    else if (o == OP_IPUSH)     return (char*)"IPUSH";
    else if (o == OP_FPUSH)     return (char*)"FPUSH";
    else if (o == OP_SWAP)      return (char*)"SWAP";
    else if (o == OP_SWAP2)     return (char*)"SWAP2";
    else if (o == OP_DUP)       return (char*)"DUP";
    else if (o == OP_DUP2)      return (char*)"DUP2";
    else if (o == OP_BSTORE)    return (char*)"BSTORE";
    else if (o == OP_SSTORE)    return (char*)"SSTORE";
    else if (o == OP_ISTORE)    return (char*)"ISTORE";
    else if (o == OP_FSTORE)    return (char*)"FSTORE";
    else if (o == OP_BLOAD)     return (char*)"BLOAD";
    else if (o == OP_SLOAD)     return (char*)"SLOAD";
    else if (o == OP_ILOAD)     return (char*)"ILOAD";
    else if (o == OP_FLOAD)     return (char*)"FLOAD";
    else if (o == OP_BADD)      return (char*)"BADD";
    else if (o == OP_BSUB)      return (char*)"BSUB";
    else if (o == OP_BMUL)      return (char*)"BMUL";
    else if (o == OP_BDIV)      return (char*)"BDIV";
    else if (o == OP_BMOD)      return (char*)"BMOD";
    else if (o == OP_BNOT)      return (char*)"BNOT";
    else if (o == OP_BAND)      return (char*)"BAND";
    else if (o == OP_BOR)       return (char*)"BOR";
    else if (o == OP_BXOR)      return (char*)"XOR";
    else if (o == OP_SADD)      return (char*)"SADD";
    else if (o == OP_SSUB)      return (char*)"SSUB";
    else if (o == OP_SMUL)      return (char*)"SMUL";
    else if (o == OP_SDIV)      return (char*)"SDIV";
    else if (o == OP_SMOD)      return (char*)"SMOD";
    else if (o == OP_SNOT)      return (char*)"SNOT";
    else if (o == OP_SAND)      return (char*)"SAND";
    else if (o == OP_SOR)       return (char*)"SOR";
    else if (o == OP_SXOR)      return (char*)"SXOR";
    else if (o == OP_IADD)      return (char*)"IADD";
    else if (o == OP_ISUB)      return (char*)"ISUB";
    else if (o == OP_IMUL)      return (char*)"IMUL";
    else if (o == OP_IDIV)      return (char*)"IDIV";
    else if (o == OP_IMOD)      return (char*)"IMOD";
    else if (o == OP_INOT)      return (char*)"INOT";
    else if (o == OP_IAND)      return (char*)"IAND";
    else if (o == OP_IOR)       return (char*)"IOR";
    else if (o == OP_IXOR)      return (char*)"IXOR";
    else if (o == OP_FADD)      return (char*)"FADD";
    else if (o == OP_FSUB)      return (char*)"FSUB";
    else if (o == OP_FMUL)      return (char*)"FMUL";
    else if (o == OP_FDIV)      return (char*)"FDIV";
    else if (o == OP_FMOD)      return (char*)"FMOD";
    else if (o == OP_FNOT)      return (char*)"FNOT";
    else if (o == OP_FAND)      return (char*)"FAND";
    else if (o == OP_FOR)       return (char*)"FOR";
    else if (o == OP_FXOR)      return (char*)"FXOR";
    else if (o == OP_GOTO)      return (char*)"GOTO";
    else if (o == OP_JUMP)      return (char*)"JUMP";
    else if (o == OP_IFE)       return (char*)"IFE";
    else if (o == OP_IFN)       return (char*)"IFN";
    else if (o == OP_IFNE)      return (char*)"IFNE";
    else if (o == OP_IFLT)      return (char*)"IFLT";
    else if (o == OP_IFLE)      return (char*)"IFLE";
    else if (o == OP_IFGT)      return (char*)"IFGT";
    else if (o == OP_IFGE)      return (char*)"IFGE";
    else if (o == OP_DEFINE)    return (char*)"DEFINE";
    else if (o == OP_INVOKE)    return (char*)"INVOKE";
    else if (o == OP_RETURN)    return (char*)"RETURN";
    else if (o == OP_SRETURN)   return (char*)"SRETURN";
    else if (o == OP_IRETURN)   return (char*)"IRETURN";
    else if (o == OP_FRETURN)   return (char*)"FRETURN";
    else if (o == OP_BPRINT)    return (char*)"BPRINT";
    else if (o == OP_SPRINT)    return (char*)"SPRINT";
    else if (o == OP_IPRINT)    return (char*)"IPRINT";
    else if (o == OP_FPRINT)    return (char*)"FPRINT";
    else if (o == OP_BPROMPT)   return (char*)"BPROMPT";
    else if (o == OP_SPROMPT)   return (char*)"SPROMPT";
    else if (o == OP_IPROMPT)   return (char*)"IPROMPT";
    else if (o == OP_FPROMPT)   return (char*)"FPROMPT";
    else if (o == OP_PASS)      "PASS";
    return (char*)"<UNKNOWN OPCODE>";
}
