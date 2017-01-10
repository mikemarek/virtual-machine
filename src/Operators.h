#ifndef OPERATORS_H
#define OPERATORS_H

#include "DataTypes.h"
#include "Value.h"

void VM::operator_bpush()
{
    value v;
    v.type = DATA_BYTE;
    v.b = readbyte();
    push(v);
}

void VM::operator_spush()
{
    value v;
    v.type = DATA_SHORT;
    v.s = readshort();
    push(v);
}

void VM::operator_ipush()
{
    value v;
    v.type = DATA_INT;
    v.i = readint();
    push(v);
}

void VM::operator_fpush()
{
    value v;
    v.type = DATA_FLOAT;
    v.f = readfloat();
    push(v);
}

void VM::operator_swap()
{
    value a = pop();
    value b = pop();
    push(a);
    push(b);
}

void VM::operator_swap2()
{
    value a = pop();
    value b = pop();
    value c = pop();
    value d = pop();
    push(a);
    push(b);
    push(c);
    push(d);
}

void VM::operator_duplicate()
{
    value v = pop();
    push(v);
    push(v);
}

void VM::operator_duplicate2()
{
    value b = pop();
    value a = pop();
    push(a);
    push(b);
    push(a);
    push(b);
}

void VM::operator_bstore()
{
    short reg = readshort();
    value v = pop();
    stack[fp + (int)reg] = v;
}

void VM::operator_sstore()
{
    short reg = readshort();
    value v = pop();
    stack[fp + (int)reg] = v;
}

void VM::operator_istore()
{
    short reg = readshort();
    value v = pop();
    stack[fp + (int)reg] = v;
}

void VM::operator_fstore()
{
    short reg = readshort();
    value v = pop();
    stack[fp + (int)reg] = v;
}

void VM::operator_bload()
{
    short reg = readshort();
    value v = stack[fp + (int)reg];
    push(v);
}

void VM::operator_sload()
{
    short reg  = readshort();
    value v = stack[fp + (int)reg];
    push(v);
}

void VM::operator_iload()
{
    short reg = readshort();
    value v = stack[fp + (int)reg];
    push(v);
}

void VM::operator_fload()
{
    short reg = readshort();
    value v = stack[fp + (int)reg];
    push(v);
}

void VM::operator_badd()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b + b.b;
    push(c);
}

void VM::operator_bsubtract()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b - b.b;
    push(c);
}

void VM::operator_bmultiply()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b * b.b;
    push(c);
}

void VM::operator_bdivide()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b / b.b;
    push(c);
}

void VM::operator_bmodulus()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b % b.b;
    push(c);
}

void VM::operator_bnot()
{
    value a = pop();

    value b;
    b.type = DATA_BYTE;
    b.b = ~a.b;
    push(b);
}

void VM::operator_band()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b & b.b;
    push(c);
}

void VM::operator_bor()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b | b.b;
    push(c);
}

void VM::operator_bxor()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_BYTE;
    c.b = a.b ^ b.b;
    push(c);
}

void VM::operator_sadd()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s + b.s;
    push(c);
}

void VM::operator_ssubtract()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s - b.s;
    push(c);
}

void VM::operator_smultiply()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s * b.s;
    push(c);
}

void VM::operator_sdivide()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s / b.s;
    push(c);
}

void VM::operator_smodulus()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s % b.s;
    push(c);
}

void VM::operator_snot()
{
    value a = pop();

    value b;
    b.type = DATA_SHORT;
    b.s = ~a.s;
    push(b);
}

void VM::operator_sand()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s & b.s;
    push(c);
}

void VM::operator_sor()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s | b.s;
    push(c);
}

void VM::operator_sxor()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_SHORT;
    c.s = a.s ^ b.s;
    push(c);
}

void VM::operator_iadd()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i + b.i;
    push(c);
}

void VM::operator_isubtract()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i - b.i;
    push(c);
}

void VM::operator_imultiply()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i * b.i;
    push(c);
}

void VM::operator_idivide()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i / b.i;
    push(c);
}

void VM::operator_imodulus()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i % b.i;
    push(c);
}

void VM::operator_inot()
{
    value a = pop();

    value b;
    b.type = DATA_INT;
    b.i = ~a.i;
    push(b);
}

void VM::operator_iand()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i & b.i;
    push(c);
}

void VM::operator_ior()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i | b.i;
    push(c);
}

void VM::operator_ixor()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_INT;
    c.i = a.i ^ b.i;
    push(c);
}

void VM::operator_fadd()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f + b.f;
    push(c);
}

void VM::operator_fsubtract()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f - b.f;
    push(c);
}

void VM::operator_fmultiply()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f * b.f;
    push(c);
}

void VM::operator_fdivide()
{
    value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f / b.f;
    push(c);
}

void VM::operator_fmodulus()
{
    /*value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f % b.f;
    push(c);*/
}

void VM::operator_fnot()
{
    /*value a = pop();

    value b;
    b.type = DATA_FLOAT;
    b.f = ~a.f;
    push(b);*/
}

void VM::operator_fand()
{
    /*value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f & b.f;
    push(c);*/
}

void VM::operator_for()
{
    /*value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f | b.f;
    push(c);*/
}

void VM::operator_fxor()
{
    /*value b = pop();
    value a = pop();

    value c;
    c.type = DATA_FLOAT;
    c.f = a.f ^ b.f;
    push(c);*/
}

void VM::operator_goto()
{
    ip = (int)readshort()-1;
}

void VM::operator_jump()
{
    value addr = pop();
    ip = (int)addr.s-1;
}

//------------------------------------------

void VM::operator_ifequal()
{
    value b = pop();
    value a = pop();

    int v1 = (int)(a.type == DATA_BYTE ? a.b : a.type == DATA_SHORT ? a.s : a.i);
    int v2 = (int)(b.type == DATA_BYTE ? b.b : b.type == DATA_SHORT ? b.s : b.i);

    ip = ((v1 == v2) ? (int)readshort()-1 : ip + 2);
}

void VM::operator_ifnot()
{
    value a = pop();

    bool v = (bool)(a.type == DATA_BYTE ? a.b : a.type == DATA_SHORT ? a.s : a.i);

    ip = (!v ? (int)readshort()-1 : ip + 2);
}

void VM::operator_ifnotequal()
{
    value b = pop();
    value a = pop();

    int v1 = (int)(a.type == DATA_BYTE ? a.b : a.type == DATA_SHORT ? a.s : a.i);
    int v2 = (int)(b.type == DATA_BYTE ? b.b : b.type == DATA_SHORT ? b.s : b.i);

    ip = ((v1 != v2) ? (int)readshort()-1 : ip + 2);
}

void VM::operator_iflessthan()
{
    value b = pop();
    value a = pop();

    int v1 = (int)(a.type == DATA_BYTE ? a.b : a.type == DATA_SHORT ? a.s : a.i);
    int v2 = (int)(b.type == DATA_BYTE ? b.b : b.type == DATA_SHORT ? b.s : b.i);

    ip = ((v1 < v2) ? (int)readshort()-1 : ip + 2);
}

void VM::operator_iflessequal()
{
    value b = pop();
    value a = pop();

    int v1 = (int)(a.type == DATA_BYTE ? a.b : a.type == DATA_SHORT ? a.s : a.i);
    int v2 = (int)(b.type == DATA_BYTE ? b.b : b.type == DATA_SHORT ? b.s : b.i);

    ip = ((v1 <= v2) ? (int)readshort()-1 : ip + 2);
}

void VM::operator_ifgreaterthan()
{
    value b = pop();
    value a = pop();

    int v1 = (int)(a.type == DATA_BYTE ? a.b : a.type == DATA_SHORT ? a.s : a.i);
    int v2 = (int)(b.type == DATA_BYTE ? b.b : b.type == DATA_SHORT ? b.s : b.i);

    ip = ((v1 > v2) ? (int)readshort()-1 : ip + 2);
}

void VM::operator_ifgreaterequal()
{
    value b = pop();
    value a = pop();

    int v1 = (int)(a.type == DATA_BYTE ? a.b : a.type == DATA_SHORT ? a.s : a.i);
    int v2 = (int)(b.type == DATA_BYTE ? b.b : b.type == DATA_SHORT ? b.s : b.i);

    ip = ((v1 >= v2) ? (int)readshort()-1 : ip + 2);
}

//------------------------------------------

void VM::operator_invoke()
{
    value empty;
    value lastip;
    value lastfp;
    empty.type  = DATA_INT;
    lastip.type = DATA_INT;
    lastfp.type = DATA_INT;
    empty.i  = 0x00;
    lastip.i = ip+2;
    lastfp.i = fp;

    id = readshort();
    for (int i = 0; i < methods[id][4]; i++)
        push(empty);
    push(lastip);
    ip = methods[id][0]-1;
    push(lastfp);
    fp = sp-methods[id][3]-methods[id][4]-2;
}

void VM::operator_return()
{
    value lastip;
    value lastfp;

    while (sp > fp+methods[id][3]+methods[id][4]+2) pop();
    lastfp = pop(); fp = lastfp.i;
    lastip = pop(); ip = lastip.i;
    for (int i = 0; i < methods[id][3]+methods[id][4]; i++)
        pop();
    if (id == 0) ip = *progsize;
    id = -1;
    for (int i = 0; i < methods.size(); i++)
    {
        if (ip >= methods[i][0] && ip <= methods[i][1])
        {
            id = i;
            break;
        }
    }
}

void VM::operator_sreturn()
{
    value v = pop();
    operator_return();
    push(v);
}

void VM::operator_ireturn()
{
    value v = pop();
    operator_return();
    push(v);
}

void VM::operator_freturn()
{
    value v = pop();
    operator_return();
    push(v);
}

void VM::operator_bprint()
{
    value v = pop();
    std::cout << "<OUTPUT> " << v.b << std::endl;
}

void VM::operator_sprint()
{
    value v = pop();
    std::cout << "<OUTPUT> " << v.s << std::endl;
}

void VM::operator_iprint()
{
    value v = pop();
    std::cout << "<OUTPUT> " << v.i << std::endl;
}

void VM::operator_fprint()
{
    value v = pop();
    std::cout << "<OUTPUT> " << v.f << std::endl;
}

void VM::operator_bprompt()
{
    char b;
    std::cout << "Enter byte: ";
    std::cin >> b;

    value v;
    v.type = DATA_BYTE;
    v.b = (unsigned char)b;
    push(v);
}

void VM::operator_sprompt()
{
    short s;
    std::cout << "Enter short: ";
    std::cin >> s;

    value v;
    v.type = DATA_SHORT;
    v.s = (short)s;
    push(v);
}

void VM::operator_iprompt()
{
    int i;
    std::cout << "Enter integer: ";
    std::cin >> i;

    value v;
    v.type = DATA_INT;
    v.i = (int)i;
    push(v);
}

void VM::operator_fprompt()
{
    float f;
    std::cout << "Enter float: ";
    std::cin >> f;

    value v;
    v.type = DATA_FLOAT;
    v.f = (float)f;
    push(v);
}

#endif
