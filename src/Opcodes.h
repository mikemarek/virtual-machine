#ifndef OPCODES_H
#define OPCODES_H

enum Opcodes
{
    // stack manipulation
    OP_BPUSH    = 0x00,
    OP_SPUSH    = 0x01,
    OP_IPUSH    = 0x02,
    OP_FPUSH    = 0x03,
    OP_DPUSH    = 0x04,
    OP_SWAP     = 0x05,
    OP_SWAP2    = 0x06,
    OP_DUP      = 0x07,
    OP_DUP2     = 0x08,

    // loading and storing variables
    OP_BSTORE   = 0x10,
    OP_SSTORE   = 0x11,
    OP_ISTORE   = 0x12,
    OP_FSTORE   = 0x13,
    OP_DSTORE   = 0x14,
    OP_BLOAD    = 0x15,
    OP_SLOAD    = 0x16,
    OP_ILOAD    = 0x17,
    OP_FLOAD    = 0x18,
    OP_DLOAD    = 0x19,

    // arithmetic and bitwise operations
    OP_BADD     = 0x20,
    OP_BSUB     = 0x21,
    OP_BMUL     = 0x22,
    OP_BDIV     = 0x23,
    OP_BMOD     = 0x24,
    OP_BNOT     = 0x25,
    OP_BAND     = 0x26,
    OP_BOR      = 0x27,
    OP_BXOR     = 0x28,
    OP_SADD     = 0x29,
    OP_SSUB     = 0x2A,
    OP_SMUL     = 0x2B,
    OP_SDIV     = 0x2C,
    OP_SMOD     = 0x2D,
    OP_SNOT     = 0x2E,
    OP_SAND     = 0x2F,
    OP_SOR      = 0x30,
    OP_SXOR     = 0x31,
    OP_IADD     = 0x32,
    OP_ISUB     = 0x33,
    OP_IMUL     = 0x34,
    OP_IDIV     = 0x35,
    OP_IMOD     = 0x36,
    OP_INOT     = 0x37,
    OP_IAND     = 0x38,
    OP_IOR      = 0x39,
    OP_IXOR     = 0x3A,
    OP_FADD     = 0x3B,
    OP_FSUB     = 0x3C,
    OP_FMUL     = 0x3D,
    OP_FDIV     = 0x3E,
    OP_FMOD     = 0x3F,
    OP_FNOT     = 0x40,
    OP_FAND     = 0x41,
    OP_FOR      = 0x42,
    OP_FXOR     = 0x43,
    OP_DADD     = 0x44,
    OP_DSUB     = 0x45,
    OP_DMUL     = 0x46,
    OP_DDIV     = 0x47,
    OP_DMOD     = 0x48,
    OP_DNOT     = 0x49,
    OP_DAND     = 0x4A,
    OP_DOR      = 0x4B,
    OP_DXOR     = 0x4C,

    // comparators
    //

    // logic and control flow
    OP_GOTO     = 0x50,
    OP_JUMP     = 0x51,
    OP_IFE      = 0x52,
    OP_IFN      = 0x53,
    OP_IFNE     = 0x54,
    OP_IFLT     = 0x55,
    OP_IFLE     = 0x56,
    OP_IFGT     = 0x57,
    OP_IFGE     = 0x58,

    // method invokation
    OP_DEFINE   = 0x80,
    OP_INVOKE   = 0x81,
    OP_RETURN   = 0x82,
    OP_BRETURN  = 0x83,
    OP_SRETURN  = 0x84,
    OP_IRETURN  = 0x85,
    OP_FRETURN  = 0x86,

    // type conversion
    //

    // system calls
    OP_BPRINT   = 0x90,
    OP_SPRINT   = 0x91,
    OP_IPRINT   = 0x92,
    OP_FPRINT   = 0x93,
    OP_DPRINT   = 0x94,
    OP_APRINT   = 0x95,
    OP_BPROMPT  = 0x96,
    OP_SPROMPT  = 0x97,
    OP_IPROMPT  = 0x98,
    OP_FPROMPT  = 0x99,
    OP_DPROMPT  = 0x9A,
    OP_APROMPT  = 0x9B,

    // do nothing
    OP_PASS     = 0xFF
};

#endif
